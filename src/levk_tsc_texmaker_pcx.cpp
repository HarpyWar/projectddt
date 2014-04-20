/*
 *  Copyright (c) 2008-2011 Sanat Bosma <sabosma@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#include "stdafx.h"



#include "levk_tsc_texmaker_cel.cpp"
using namespace std;



class pcxmaker
{
	private:

	utils util;
	globals* global;

	public:

	void init (globals* glob)
	{
		global = glob;
	}




	int_texchunkp pcx_bulk(int texcount, unsigned char* pcx, int pcxsize, int transp, int chunkfactor, int x_move, int y_move, int gamma, int mask)
	{

		if (pcxsize < 780 || texcount < 1)
		{
			cout << " DDT> Bad pcx bulk call" << endl;
			return int_texchunkp();
		}

		// Lets get the pal first at the end of the file
		unsigned char* pal = new unsigned char[768];

		int pcxpointer = pcxsize -1;
		for (int i = 767; i > -1 ; i--)
		{
			pal[i] = (int)pcx[pcxpointer];
			pcxpointer--;

		}

		ddtpal::add_gamma(pal, 768, gamma);

		// now the x and y size
		int x_min = (int)pcx[ 4] + 0x100 * (int)pcx[ 5];
		int y_min = (int)pcx[ 6] + 0x100 * (int)pcx[ 7];
		int x_max = (int)pcx[ 8] + 0x100 * (int)pcx[ 9];
		int y_max = (int)pcx[10] + 0x100 * (int)pcx[11];



		int x_size = x_max - x_min + 1;
		int y_size = (y_max - y_min + 1) / texcount;



		if ( x_size < 1 || y_size < 1)
		{
			cout << " DDT> Not sane pcx file values" << endl;
			return int_texchunkp();
		}


		// init the output
		int_texchunkp out(texcount);



		int mem_off = 0x80; // apparantly allways

		for (int i = 0; i < texcount; i ++)
		{
			quad_int_ucharp indiv = pcx_indiv(x_size, y_size, pcx , pcxsize , pal, mem_off, transp);
			mem_off = indiv.i;

			if ((mask > -1) && ((*global).valuemap.get_value(mask, i) < 1))
			{
				//unneeded texture
				delete[] indiv.c;
				indiv.c = util.empty_texture(indiv.x, indiv.y);
			}
			else if (DEVELOPER_STAMP) // stamp the texture to keep track of it, for development
			{
				util.stamp_tex(indiv.c, indiv.x, indiv.y, i);
			}

			int chunki;
			if (chunkfactor ==  CHUNKY_MAXI) {chunki = util.maxi_chunkyness(indiv.x, indiv.y);}
			else {chunki = util.auto_chunkyness(indiv.x, indiv.y);}

			texchunk tx;
			tx.set(indiv.c, indiv.x, indiv.y, chunki, (chunkfactor == CHUNKY_SMOOTH));
			tx.move_offset(x_move, y_move);
			out.chunk[i] = tx;
			delete[] indiv.c;



		}

		delete[] pcx;
		delete[] pal;

		return out;



	}


	quad_int_ucharp pcx_indiv(int x_size, int y_size, unsigned char* pcx , int pcxsize , unsigned char* pal, int mem_off, int transp)
	{
		int mempoint = mem_off;

		//cout << hex << mem_off << endl;


		int final_x_size = util.power_of_two(x_size);
		int final_y_size = util.power_of_two(y_size);

		unsigned char* tex = util.empty_texture(final_x_size, final_y_size);

		int pixpoint_x = 0; //on the screen
		int pixpoint_y = 0; //on the screen

		int pixpoint_scalar_max = x_size*y_size; //total ammount of pixels to be drawn
		int pixpoint_scalar = 0; //current pixels vs the total ammount



		//cout << "slack " << celsize - (mempoint+40)  << endl;



		while ((mempoint+40 < pcxsize) && (pixpoint_scalar < pixpoint_scalar_max))
		{

			//repeat rules
			// c0 = 0x write,  c2 = 2x write, cf = 15x write.
			// any hidden messages with the c0 command anywhere?

			if (  (int)pcx[mempoint] > 0xbf ) //t && (int)cel[mempoint] < 0xd0)
			{

				int repeat_count = (int)pcx[mempoint] - 0xc0;
				mempoint ++;

				for (int i  = 0 ; i < repeat_count ; i++)
				{

					if (  (int)pcx[mempoint]  != transp )
					{
						util.raster_pix(tex, final_x_size, final_y_size, pixpoint_x, y_size - pixpoint_y - 1, pcx[mempoint], pal);
					}
					pixpoint_x++;
					pixpoint_scalar++;

					if (pixpoint_x > x_size -1)
					{
						pixpoint_x = pixpoint_x - x_size; pixpoint_y++;
					}

				}

				mempoint ++;

			}
			else //single pixel rules
			{
				if (  (int)pcx[mempoint]  != transp )
				{
					util.raster_pix(tex, final_x_size, final_y_size, pixpoint_x, y_size - pixpoint_y - 1, pcx[mempoint], pal);
				}
				mempoint++;
				pixpoint_scalar++;
				pixpoint_x++;
				if (pixpoint_x > x_size -1) { pixpoint_x = 0; pixpoint_y++;}

			}

		}

		//cout << hex << mempoint << endl;
		return quad_int_ucharp(mempoint, x_size, final_x_size, final_y_size, tex);
	}




};


class mapmaker
{
	private:

	utils util;

	public:


	int_texchunkp map(unsigned char* map, int x_size, int y_size, int x_move, int y_move)
	{
		if ( x_size != util.power_of_two(x_size) || y_size != util.power_of_two(y_size))
		{
			cout << " DDT> Not sane raw map file values" << endl;
			return int_texchunkp();
		}

		// init the output
		int_texchunkp out(1);

		texchunk tx;
		tx.set(map, x_size, y_size, util.auto_chunkyness(x_size, y_size), false);
		tx.move_offset(x_move, y_move);
		out.chunk[0] = tx;
		delete[] map;

		return out;

	}
};
