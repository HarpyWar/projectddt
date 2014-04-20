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




#include "levz_mul_ingame_element_names.h"


using namespace std;


//This is a recursive class that holds a part of a texture XOR links to others texture parts
class texchunk
{

	public:

	ddtgrfx_texob chunk; //our texture, is always a square ^2
	float chunk_xy; // pixel size
	float chunk_off_x; //x,y offsets
	float chunk_off_y;
	bool havechunk; //is texture present
	bool smooth; //should we use GL linear interpolation


	texchunk* childa; //links to our recursive children
	bool cha_occupied;
	texchunk* childb;
	bool chb_occupied;

	public:


	texchunk()
	{
		chunk_xy = 0;
		cha_occupied = false;
		chb_occupied = false;
		havechunk = false;
		smooth = true;
	}

	//This is for external use. A texture is fed to us. ctex_x,y is the size
	//and must be powers of 2.
	//chxy is the size of the square blocks the texture needs to be cut up into.
	void set(unsigned char* ctex, int16_t ctex_x, int16_t ctex_y, int16_t chxy, bool smo)
	{
		set(ctex, ctex_x, ctex_y, 0, 0, ctex_x, ctex_y, chxy, smo);
		optimise();
	}

	//This is for internal use. our_start_x,y and our_end_x,y determine the part of the texture that need to be processed by this
	// recursive branch
	int set(unsigned char* ctex, int16_t ctex_x, int16_t ctex_y, int16_t our_start_x, int16_t our_start_y, int16_t our_end_x, int16_t our_end_y, int16_t chxy, bool smo)
	{
		chunk_xy = chxy;
		cha_occupied = false;
		chb_occupied = false;
		havechunk = false;
		smooth = smo;

		// splitting up
		if (our_end_x - our_start_x > chxy)
		{

			childa = new texchunk;
			childb = new texchunk;

			int ainit = (*childa).set(ctex, ctex_x, ctex_y, our_start_x, our_start_y, our_end_x - 0.5*(our_end_x - our_start_x), our_end_y, chxy, smo);
			int binit = (*childb).set(ctex, ctex_x, ctex_y, our_start_x + 0.5*(our_end_x - our_start_x), our_start_y, our_end_x, our_end_y, chxy, smo);

			if (ainit + binit == 2) // both nogo
			{
				delete childa;
				delete childb;
				return 1;
			}

			if (ainit == 0)
			{
				cha_occupied = true;
			}
			else
			{
				delete childa;
			}

			if (binit == 0)
			{
				chb_occupied = true;
			}
			else
			{
				delete childb;
			}

			return 0;
		}

		// splitting up	other way
		else if (our_end_y - our_start_y > chxy)
		{

			childa = new texchunk;
			childb = new texchunk;

			int ainit = (*childa).set(ctex, ctex_x, ctex_y, our_start_x, our_start_y, our_end_x, our_end_y - 0.5*(our_end_y - our_start_y), chxy, smo);
			int binit = (*childb).set(ctex, ctex_x, ctex_y, our_start_x, our_start_y + 0.5*(our_end_y - our_start_y), our_end_x, our_end_y, chxy, smo);


			if (ainit + binit == 2) // both nogo
			{
				delete childa;
				delete childb;
				return 1;
			}

			if (ainit == 0)
			{
				cha_occupied = true;
			}
			else
			{
				delete childa;
			}

			if (binit == 0)
			{
				chb_occupied = true;
			}
			else
			{
				delete childb;
			}

			return 0;
		}

		else // we are not splitting but rerastering the chunk, see if we have at least one pixel
		{
			// init of our private texture
			unsigned char* tartex = new unsigned char[chxy*chxy*4];


			// mapping the source tex to our own texture
			bool at_least_one_pixel = false;

			int tartex_pointer = 0;

			for (int16_t yy = 0; yy < chxy; yy++)
			{
				for (int16_t xx = 0; xx < chxy; xx++)
				{
					//get source pixel
					int source_pixel_x =  our_start_x + xx;
					int source_pixel_y =  our_start_y + yy;

					unsigned char source_pixel_r = ctex[ 4*(ctex_x*source_pixel_y)  + 4*source_pixel_x   ];
					unsigned char source_pixel_g = ctex[ 4*(ctex_x*source_pixel_y)  + 4*source_pixel_x +1];
					unsigned char source_pixel_b = ctex[ 4*(ctex_x*source_pixel_y)  + 4*source_pixel_x +2];
					unsigned char source_pixel_a = ctex[ 4*(ctex_x*source_pixel_y)  + 4*source_pixel_x +3];

					// set the pixel at our private chunk
					tartex[4*tartex_pointer   ] = source_pixel_r;
					tartex[4*tartex_pointer+ 1] = source_pixel_g;
					tartex[4*tartex_pointer+ 2] = source_pixel_b;
					tartex[4*tartex_pointer+ 3] = source_pixel_a;

					if (source_pixel_a !=  0x00)
					{
						at_least_one_pixel = true;
					}
					///test only!!!
					else
					{
						//tartex[4*tartex_pointer+ 3] = 0x22;
					}

					tartex_pointer++;
				}
			}

			if (!(at_least_one_pixel))
			{
				delete[] tartex;
				return 1;
			}
			else
			{
				havechunk = true;
				chunk_off_x = our_start_x;
				chunk_off_y = our_start_y;
				//chunk.load(tartex, chunk_xy);
				ddtgrfx::load_texob(&chunk, tartex, chunk_xy);
				return 0;
			}
			return 0;
		}
		return 1;
	}


	// This is to remove unnecessary texchunks form our recursive tree
	void optimise()
	{
		if (!havechunk) // we dont have a chunk ourselves
		{

			if (cha_occupied) // but childa exists
			{

				bool optimising_a_done = false;

				while (   (!(*childa).havechunk) &&  (!optimising_a_done)      ) // and childa doesnt have a chunk either
				{
					if (  (*childa).cha_occupied  &&  !(*childa).chb_occupied  ) // but childa does have a childa itself but not a child b
					{
						texchunk* temp_pointer =  (*childa).childa;  //so we take childa's childa.
						delete childa; // and delte its parent
						childa = temp_pointer; // and make it our own child
						//cout << "recurtex optimised aa" << endl;
					}
					else if (  !(*childa).cha_occupied  &&  (*childa).chb_occupied  ) // or if childa does have a childb itself but not a child a
					{
						texchunk* temp_pointer =  (*childa).childb;  //so we take childa's childb.
						delete childa; // and delte its parent
						childa = temp_pointer; // and make it our own child
						//cout << "recurtex optimised ab" << endl;
					}
					else
					{
						optimising_a_done = true;
					}
				}
				(*childa).optimise(); // let childa optimise itself
			}

			if (chb_occupied) // now on to childb, does it exist?
			{
				bool optimising_b_done = false;

				while (   (!(*childb).havechunk) &&   !optimising_b_done  ) // and childb doesnt have a chunk either
				{
					if (  (*childb).cha_occupied  &&  !(*childb).chb_occupied  ) // but childb does have a childa itself but not a child b
					{
						texchunk* temp_pointer =  (*childb).childa;  //so we take childb's childa.
						delete childb; // and delte its parent
						childb = temp_pointer; // and make it our own child
						//cout << "recurtex optimised ba" << endl;
					}
					else if (  !(*childb).cha_occupied  &&  (*childb).chb_occupied  ) // or if childb does have a childb itself but not a child a
					{
						texchunk* temp_pointer =  (*childb).childb;  //so we take childb's childb.
						delete childb; // and delte its parent
						childb = temp_pointer; // and make it our own child
						//cout << "recurtex optimised bb" << endl;
					}
					else
					{
						optimising_b_done = true;
					}
				}
				(*childb).optimise(); // let childb optimise itself
			}
		}
	}


	void make_renderable()
	{

		if (havechunk)
		{
			//chunk.make_renderable(chunk_xy, smooth);
			ddtgrfx::texob_make_renderable(&chunk, chunk_xy, smooth);

		}
		else
		{
			if (cha_occupied)
			{
				(*childa).make_renderable();
			}
			if (chb_occupied)
			{
				(*childb).make_renderable();
			}
		}
	}


	void move_offset(int16_t xplus, int16_t yplus)
	{

		if (havechunk)
		{
			chunk_off_x = chunk_off_x + xplus;
			chunk_off_y = chunk_off_y + yplus;
		}
		else
		{
			if (cha_occupied)
			{
				(*childa).move_offset(xplus, yplus);
			}
			if (chb_occupied)
			{
				(*childb).move_offset(xplus, yplus);
			}
		}
	}

	void render(float scale, float x_off, float y_off, float rmod, float gmod, float bmod, float amod, int16_t display_w, int16_t display_h)
	{

		if (havechunk)
		{

			ddtgrfx::render_texob(
					&chunk,
					scale*(x_off+chunk_off_x),
					scale*(y_off+chunk_off_y),
					scale*chunk_xy,
					rmod,
					gmod,
					bmod,
					amod,
					display_w,
					display_h);

		}
		else
		{
			if (cha_occupied)
			{
				(*childa).render(scale, x_off, y_off, rmod, gmod, bmod, amod, display_w, display_h);
			}
			if (chb_occupied)
			{
				(*childb).render(scale, x_off, y_off, rmod, gmod, bmod, amod, display_w, display_h);
			}
		}
	}

	void render_highlight(int hi_code, float scale, float x_off, float y_off, int16_t display_w, int16_t display_h)
	{

		if (havechunk)
		{

			ddtgrfx::render_texob_highlight(
					hi_code,
					&chunk,
					scale*(x_off+chunk_off_x),
					scale*(y_off+chunk_off_y),
					scale*chunk_xy,
					display_w,
					display_h);

		}
		else
		{
			if (cha_occupied)
			{
				(*childa).render_highlight(hi_code, scale, x_off, y_off, display_w, display_h);
			}
			if (chb_occupied)
			{
				(*childb).render_highlight(hi_code, scale, x_off, y_off, display_w, display_h);
			}
		}
	}

	void kill()
	{
		if (havechunk)
		{
			ddtgrfx::kill_texob(&chunk);
		}
		else
		{
			if (cha_occupied)
			{
				(*childa).kill();
				delete childa;
			}
			if (chb_occupied)
			{
				(*childb).kill();
				delete childb;
			}
		}
	}
};


class int_texchunkp
{
	public:

	int size;
	texchunk* chunk;

	int_texchunkp()
	{
		size = 0;
	}

	int_texchunkp(int sz)
	{
		if (sz < 1)
		{
			size = 0;
			cout << "DDT> int_texchunkp bad init!" << endl;
		}
		else
		{
			size = sz;
			chunk = new texchunk[sz];
		}
	}
};






