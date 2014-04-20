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



#include "levy_mul_recurtex.cpp"
using namespace std;

class di_int
{
	public:
	int x; int y;

	di_int()
	{
		x= 0; y = 0;
	}

	di_int(int ix, int iy)
	{
		x = ix; y = iy;
	}

};

class tri_int
{
	public:
	int x; int y; int z;

	tri_int()
	{
		x= 0; y = 0; z = 0;
	}

	tri_int(int ix, int iy, int iz)
	{
		x = ix; y = iy; z = iz;
	}

};




class di_float
{
	public:
	float x; float y;

	di_float()
	{
		x= 0.0; y = 0.0;
	}

	di_float(float ix, float iy)
	{
		x = ix; y = iy;
	}

};

class tri_float
{
	public:
	float x; float y; float z;

	tri_float()
	{
		x= 0.0; y = 0.0; z = 0.0;
	}

	tri_float(float ix, float iy, float iz)
	{
		x = ix; y = iy; z = iz;
	}

};
/*
class quad_int
{
	public:
	int i; int j; int x; int y;

	quad_int()
	{
		i= 0; j = 0; x= 0; y = 0;
	}

	quad_int(int ii, int ij, int ix, int iy)
	{
		i = ii; j = ij; x = ix; y = iy;
	}

};
*/

/*
class quad_int_collection
{
	public:
	int size;
	quad_int* qi;

	quad_int_collection()
	{
		size = 0;
	}

	quad_int_collection(int s)
	{
		if (s < 1)
		{
			cout << "bad quad_int_collection init" << endl;
			size = 0;
		}
		else
		{
			qi = new quad_int[s];
			size = s;
		}

	}


};
*/

// This is for transporting a chunk of data and its size in bytes
class int_ucharp
{
	public:
	int i; unsigned char* c;

	int_ucharp()
	{
		i= 0;
	}

	int_ucharp(int ii, unsigned char* ic)
	{
		i = ii; c = ic;
	}
};


/*
class int_s16p
{
	public:
	int i; int16_t* c;

	int_s16p()
	{
		i= 0;
	}

	int_s16p(int ii, int16_t* ic)
	{
		i = ii; c = ic;
	}
};

*/

class int_floatp
{
	public:
	int i; float* f;

	int_floatp()
	{
		i= 0;
	}

	int_floatp(int in_i, float* in_f)
	{
		i = in_i; f = in_f;
	}
};



class int_string
{
	public:
	int i; string s;


	int_string()
	{
		i = 0;
	}

	int_string(int ii, string is)
	{
		i = ii; s = is;
	}
};



// This is for transporting a chunk of data and 4 ints of info about it
// Usually:
// i = size in bytes
// j = the original x, before making the dimensions power-of-two
// x and y are dimensions
// c is an RGBA texture

class quad_int_ucharp
{
	public:
	int i; int j; int x;int y; unsigned char* c;

	quad_int_ucharp()
	{
		i= 0; j = 0; x= 0; y = 0;
	}

	quad_int_ucharp(int ii, int ij, int ix, int iy, unsigned char* ic)
	{
		i = ii; j = ij; x = ix; y = iy; c = ic;
	}

};



class di_ubyte
{
	public:

	unsigned char lower;
	unsigned char upper;

	di_ubyte()
	{
		lower = 0x00;
		upper = 0x00;
	}

	di_ubyte(unsigned char low, unsigned char up)
	{
		lower = low; upper = up;
	}
};

class threadsave_string
{
	private:
	char s[THREADSAVE_STRING_SIZE];
	int16_t used;

	public:
	threadsave_string()
	{
		used = 0;
	}

	void set(string in)
	{
		used = 0;
		int16_t in_size = in.size();
		for (int16_t i = 0 ; (i < THREADSAVE_STRING_SIZE) && (i < in_size); i++)
		{
			s[i] = in.at(i);
			used = i+1;
		}
	}

	string get()
	{
		string out = "";
		for (int16_t i = 0 ; (i < THREADSAVE_STRING_SIZE) && (i < used); i++)
		{
			out.push_back(s[i]);
		}
		return out;
	}

};

class long_threadsave_string
{
	private:
	char s[LONG_THREADSAVE_STRING_SIZE];
	int16_t used;

	public:
	long_threadsave_string()
	{
		used = 0;
	}

	void set(string in)
	{
		used = 0;
		int16_t in_size = in.size();
		for (int16_t i = 0 ; (i < LONG_THREADSAVE_STRING_SIZE) && (i < in_size); i++)
		{
			s[i] = in.at(i);
			used = i+1;
		}
	}

	string get()
	{
		string out = "";
		for (int16_t i = 0 ; (i < LONG_THREADSAVE_STRING_SIZE) && (i < used); i++)
		{
			out.push_back(s[i]);
		}
		return out;
	}

};






