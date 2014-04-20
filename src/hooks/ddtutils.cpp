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


class ddtutils
{
	public:

	static void del_array(unsigned char* a, int a_size)
	{
		if (a_size > 0)
		{
			delete[] a;
		}
	}

	static unsigned char* copy_array(unsigned char* a, int a_size)
	{
		if (a_size < 1) {return NULL;}

		unsigned char* out = new unsigned char[a_size];

		for (int i = 0; i < a_size; i++)
		{
			out[i] = a[i];
		}
		return out;
	}

	static unsigned char* empty_array(int size)
	{
		if (size < 1) {return NULL;}

		unsigned char* out = new unsigned char[size];

		for (int i = 0; i < size; i++)
		{
			out[i] = 0;
		}
		return out;
	}

	static void cout_array_hex(unsigned char* a, int a_size)
	{
		int linepos = 0;
		int spacepos = 0;

		for (int i = 0; i < a_size; i++)
		{
			if ( a[i] < 0x10)
			{
				cout << "0";
			}
			cout << hex <<(int)a[i];
			linepos++;
			spacepos++;

			if(spacepos > 3)
			{
				cout << " ";
				spacepos = 0;
			}
			else
			{
				cout << ".";
			}

			if(linepos > 31)
			{
				cout << endl;
				linepos = 0;
			}
		}
		cout << dec << endl;
	}

	static float int_to_float_volume(int in)
	{
		if (in > 9) {return 1.0;}
		if (in < 1) {return 0.0;}

		return 0.1*((float)in);
	}

	static bool strings_share_beginning(string a, string b)
	{
		int chars_to_compare = a.size();

		if (b.size() < a.size()){chars_to_compare = b.size();}
		if (chars_to_compare < 1){return true;}

		for (int i = 0; i < chars_to_compare; i++)
		{
			if( a.at(i) != b.at(i))
			{
				return false;
			}
		}
		return true;
	}

};
