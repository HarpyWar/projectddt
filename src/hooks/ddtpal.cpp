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



#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <stdint.h>

using namespace std;



class ddtpal
{

	public:



	static unsigned char add_gamma(unsigned char bi, int gam)
	{
		if (bi == 255){return bi;}

		unsigned short o = (unsigned short)bi + 10*(unsigned short)gam;

		if (o > 255){return 255;}
		return (unsigned char)o;
	}

	static void add_gamma(unsigned char* pal, int pal_size, int gam)
	{
		if (gam < 1) {return;}

		for (int i = 0; i < pal_size; i++)
		{
			pal[i] = add_gamma(pal[i], gam);
		}

	}


	static void get_value(unsigned char* pal, int pal_size, int pal_pos, unsigned char* r, unsigned char* g, unsigned char* b)
	{
		int memoff = 3*pal_pos;

		if ((memoff+2 > pal_size -1) || memoff < 0)
		{
			(*r) = 0; (*g) = 0; (*b) = 0;
			return;
		}

		(*r) = pal[memoff+0];
		(*g) = pal[memoff+1];
		(*b) = pal[memoff+2];
	}

	static void set_value(unsigned char* pal, int pal_size, int pal_pos, unsigned char r, unsigned char g, unsigned char b)
	{
		int memoff = 3*pal_pos;

		if ((memoff+2 > pal_size -1) || memoff < 0)
		{
			return;
		}

		pal[memoff+0] = r;
		pal[memoff+1] = g;
		pal[memoff+2] = b;
	}

	static void move_ooze(unsigned char* pal, int pal_size, int move)
	{
		if (move < 1 || move > 30) {return;}

		unsigned char ooze_r[32];
		unsigned char ooze_g[32];
		unsigned char ooze_b[32];

		unsigned char o_r = 0;
		unsigned char o_g = 0;
		unsigned char o_b = 0;

		for (int i = 0; i < 32; i++)
		{

			get_value(pal, pal_size, i, &o_r, &o_g, &o_b);
			ooze_r[i] = o_r;
			ooze_g[i] = o_g;
			ooze_b[i] = o_b;
		}

		int result_pointer = move + 1;

		for (int i = 1; i < 32; i++)
		{
			if (result_pointer > 31) {result_pointer = 1;}

			o_r = ooze_r[i];
			o_g = ooze_g[i];
			o_b = ooze_b[i];
			set_value(pal, pal_size, result_pointer, o_r, o_g, o_b);

			result_pointer++;
		}


	}

};
