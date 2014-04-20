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



#include "levy_mul_primitives.cpp"
using namespace std;


class utils
{
	public:



	int random_direction()
	{
		int raw = ddtmath::random_int(0,7);

		switch(raw)
		{
		case 0 : return DIRECTION_N;
		case 1 : return DIRECTION_NE;
		case 2 : return DIRECTION_E;
		case 3 : return DIRECTION_SE;
		case 4 : return DIRECTION_S;
		case 5 : return DIRECTION_SW;
		case 6 : return DIRECTION_W;
		}
		return DIRECTION_NW;

	}

	bool tiles_are_one_appart(int first_x, int first_y, int sec_x, int sec_y)
	{
		if ( ( (first_x - sec_x)*(first_x - sec_x) < 2 ) && ( (first_y - sec_y)*(first_y - sec_y) < 2 )  )
		{

			return true;
		}
		return false;
	}

	bool is_same_tile(int xa, int ya, int xb, int yb)
	{
		if ((xa == xb) && (ya == yb)) {return true;}
		return false;
	}



	string strip_windows_file_path(string in)
	{
		int in_size = in.size();
		string out = "";
		bool done = false;

		for (int i = in_size -1 ; i > -1 && !done; i--)
		{
			if ( in.at(i) == '\\') { done = true;}
			else
			{
				out.insert(0, 1, in.at(i));
			}
		}

		return out;
	}

	string get_argument_at(int mem_off, int_ucharp rulesfile )
	{
		return get_argument_at(mem_off, rulesfile.c, rulesfile.i);
	}

	string get_argument_at(int mem_off, unsigned char* rules, int rules_size )
	{
		int argumentpoint = mem_off;
		string argument = "";
		bool argumentdone = false;

		while ( argumentpoint < rules_size && argumentpoint < mem_off + 100 && !argumentdone)
		{
			if ( (rules[argumentpoint] == ']') )
			{
				argumentdone = true;
			}
			else
			{
				argument.append( 1, rules[argumentpoint]);
			}

			argumentpoint++;
		}


		return argument;
	}

	int get_int_at(int mem_off, string in)
	{
		int out = 0;
		int in_size = in.size();
		if (mem_off+3 < in_size)
		{
			out = out + 1000 * char_to_int(in.at(mem_off+0));
			out = out +  100 * char_to_int(in.at(mem_off+1));
			out = out +   10 * char_to_int(in.at(mem_off+2));
			out = out +    1 * char_to_int(in.at(mem_off+3));
			if (out < 0){out= (out + 1000) * -1;}
		}

		return out;

	}


	int get_int_at(int mem_off, unsigned char* rules, int rules_size)
	{
		int out = 0;

		if (mem_off+3 < rules_size)
		{
			out = out + 1000 * char_to_int(rules[mem_off+0]);
			out = out +  100 * char_to_int(rules[mem_off+1]);
			out = out +   10 * char_to_int(rules[mem_off+2]);
			out = out +    1 * char_to_int(rules[mem_off+3]);
			if (out < 0){out= (out + 1000) * -1;}
		}

		return out;

	}


	int get_int_at(int mem_off, int_ucharp rulesfile )
	{
		return get_int_at(mem_off, rulesfile.c, rulesfile.i);
	}




	int char_to_int(char c)
	{
		if(c == '0'){ return 0; }
		else if(c == '1'){ return 1; }
		else if(c == '2'){ return 2; }
		else if(c == '3'){ return 3; }
		else if(c == '4'){ return 4; }
		else if(c == '5'){ return 5; }
		else if(c == '6'){ return 6; }
		else if(c == '7'){ return 7; }
		else if(c == '8'){ return 8; }
		else if(c == '9'){ return 9; }
		else if(c == '-'){ return -1;}
		else { return 0; }
	}


	uint8_t get_byte_at_hex(int mem_off, unsigned char* rules, int rules_size)
	{
		uint8_t out = 0;

		if (mem_off+1 < rules_size)
		{
			out = out +   0x10 * (uint8_t)char_to_int_hex(rules[mem_off+0]);
			out = out +    0x1 * (uint8_t)char_to_int_hex(rules[mem_off+1]);
		}

		return out;

	}

	int get_int_at_hex(int mem_off, unsigned char* rules, int rules_size )
	{
		int out = 0;

		if (mem_off+3 < rules_size)
		{
			out = out + 0x1000 * char_to_int_hex(rules[mem_off+0]);
			out = out +  0x100 * char_to_int_hex(rules[mem_off+1]);
			out = out +   0x10 * char_to_int_hex(rules[mem_off+2]);
			out = out +    0x1 * char_to_int_hex(rules[mem_off+3]);
			if (out < 0){out= (out + 0x1000) * -1;}
		}

		return out;

	}



	int char_to_int_hex(char c)
	{
		if(c == '0'){ return 0; }
		else if(c == '1'){ return 1; }
		else if(c == '2'){ return 2; }
		else if(c == '3'){ return 3; }
		else if(c == '4'){ return 4; }
		else if(c == '5'){ return 5; }
		else if(c == '6'){ return 6; }
		else if(c == '7'){ return 7; }
		else if(c == '8'){ return 8; }
		else if(c == '9'){ return 9; }
		else if(c == 'a'){ return 10;}
		else if(c == 'b'){ return 11;}
		else if(c == 'c'){ return 12;}
		else if(c == 'd'){ return 13;}
		else if(c == 'e'){ return 14;}
		else if(c == 'f'){ return 15;}
		else if(c == '-'){ return -1;}
		else { return 0; }
	}

	string remove_save_extention(string in)
	{
		int in_size = (int)(in.size());

		if (in_size < 6){ return in;}

		if (	(	(in.at(in_size-1))  ==  'c' &&
					(in.at(in_size-2))  ==  't' &&
					(in.at(in_size-3))  ==  'd' &&
					(in.at(in_size-4))  ==  'd' &&
					(in.at(in_size-5))  ==  '.' )
                                               ||
				(	(in.at(in_size-1))  ==  'h' &&
					(in.at(in_size-2))  ==  't' &&
					(in.at(in_size-3))  ==  'd' &&
					(in.at(in_size-4))  ==  'd' &&
					(in.at(in_size-5))  ==  '.' ))
		{
			string out = "";
			for (int i = 0; (i < in_size -5) ; i++)
			{
				out.push_back(in.at(i));
			}
			return out;
		}
		return in;
	}

	string add_save_extention(string in, int mode)
	{
		if (mode == GAME_MODE_EXP)
		{
			return in.append(".ddth");
		}

		return in.append(".ddtc");
	}

	bool has_save_extention(string in, int mode)
	{
		int in_size = (int)(in.size());

		if (in_size < 6){ return false;}

		if (	(	(in.at(in_size-1))  ==  'c' &&
					(in.at(in_size-2))  ==  't' &&
					(in.at(in_size-3))  ==  'd' &&
					(in.at(in_size-4))  ==  'd' &&
					(in.at(in_size-5))  ==  '.' )
                                               ||
				(	(in.at(in_size-1))  ==  'h' &&
					(in.at(in_size-2))  ==  't' &&
					(in.at(in_size-3))  ==  'd' &&
					(in.at(in_size-4))  ==  'd' &&
					(in.at(in_size-5))  ==  '.' &&
					mode == GAME_MODE_EXP ))
		{

			return true;
		}
		return false;
	}

	bool has_specific_save_extention(string in, int mode)
	{
		int in_size = (int)(in.size());

		if (in_size < 6){ return false;}

		if (	(	(in.at(in_size-1))  ==  'c' &&
					(in.at(in_size-2))  ==  't' &&
					(in.at(in_size-3))  ==  'd' &&
					(in.at(in_size-4))  ==  'd' &&
					(in.at(in_size-5))  ==  '.' &&
					mode == GAME_MODE_CLASSIC )
                                               ||
				(	(in.at(in_size-1))  ==  'h' &&
					(in.at(in_size-2))  ==  't' &&
					(in.at(in_size-3))  ==  'd' &&
					(in.at(in_size-4))  ==  'd' &&
					(in.at(in_size-5))  ==  '.' &&
					mode == GAME_MODE_EXP ))
		{

			return true;
		}
		return false;
	}


	bool is_a_sane_savefile_name(string in_raw, int mode)
	{

		if  (! has_save_extention(in_raw, mode)) { return false;}

		string in = remove_save_extention(in_raw);
		int s_size = in.size();

		if ( s_size < 2) { return false;}
		if ( s_size > MAX_CHAR_NAME_LENGTH) { return false;}

		for (int i = 0; i < s_size; i++)
		{
			if( 	in.at(i) != '0'  &&
					in.at(i) != '1'  &&
					in.at(i) != '2'  &&
					in.at(i) != '3'  &&
					in.at(i) != '4'  &&
					in.at(i) != '5'  &&
					in.at(i) != '6'  &&
					in.at(i) != '7'  &&
					in.at(i) != '8'  &&
					in.at(i) != '9'  &&
					in.at(i) != '_'  &&
					in.at(i) != 'a'  &&
					in.at(i) != 'b'  &&
					in.at(i) != 'c'  &&
					in.at(i) != 'd'  &&
					in.at(i) != 'e'  &&
					in.at(i) != 'f'  &&
					in.at(i) != 'g'  &&
					in.at(i) != 'h'  &&
					in.at(i) != 'i'  &&
					in.at(i) != 'j'  &&
					in.at(i) != 'k'  &&
					in.at(i) != 'l'  &&
					in.at(i) != 'm'  &&
					in.at(i) != 'n'  &&
					in.at(i) != 'o'  &&
					in.at(i) != 'p'  &&
					in.at(i) != 'q'  &&
					in.at(i) != 'r'  &&
					in.at(i) != 's'  &&
					in.at(i) != 't'  &&
					in.at(i) != 'u'  &&
					in.at(i) != 'v'  &&
					in.at(i) != 'w'  &&
					in.at(i) != 'x'  &&
					in.at(i) != 'y'  &&
					in.at(i) != 'z'  )
			{
				return false;
			}
		}

		return true;


	}



	string int_to_string_no_leading_zero(int i)
	{
		string out = "";
		int in = i;
		if (i < 0)  {out.append("-"); in = in * -1;}

		int thousants = in / 1000;
		int hundreds = (in - thousants*1000) /100;
		int tens = (in - thousants*1000 - hundreds*100) /10;
		int units = in - thousants*1000 - hundreds*100 - tens*10;

		if (thousants > 0) {out.append(didget_to_string(thousants));}
		if (hundreds > 0 || thousants > 0) {out.append(didget_to_string(hundreds));}
		if (tens > 0 || hundreds > 0 || thousants > 0) {out.append(didget_to_string(tens));}
		out.append(didget_to_string(units));

		return out;

	}


	string int_to_string_bignum(uint32_t in)
	{

		if (in < 1000) {return int_to_string_no_leading_zero((int)in);}


		uint32_t u_bill =           in/1000000000;
		uint32_t c_mill = (in - u_bill*1000000000)       / 100000000;
		uint32_t d_mill = (in - u_bill*1000000000 - c_mill*100000000)       / 10000000;
		uint32_t u_mill = (in - u_bill*1000000000 - c_mill*100000000 - d_mill*10000000)       / 1000000;
		uint32_t c_kilo = (in - u_bill*1000000000 - c_mill*100000000 - d_mill*10000000 - u_mill*1000000)       / 100000;
		uint32_t d_kilo = (in - u_bill*1000000000 - c_mill*100000000 - d_mill*10000000 - u_mill*1000000 - c_kilo*100000)        /10000;
		uint32_t u_kilo = (in - u_bill*1000000000 - c_mill*100000000 - d_mill*10000000 - u_mill*1000000 - c_kilo*100000 - d_kilo*10000)        /1000;
		uint32_t c_unit = (in - u_bill*1000000000 - c_mill*100000000 - d_mill*10000000 - u_mill*1000000 - c_kilo*100000 - d_kilo*10000 - u_kilo*1000) /100;
		uint32_t d_unit = (in - u_bill*1000000000 - c_mill*100000000 - d_mill*10000000 - u_mill*1000000 - c_kilo*100000 - d_kilo*10000 - u_kilo*1000 - c_unit*100) /10;
		uint32_t u_unit = (in - u_bill*1000000000 - c_mill*100000000 - d_mill*10000000 - u_mill*1000000 - c_kilo*100000 - d_kilo*10000 - u_kilo*1000 - c_unit*100 - d_unit* 10);

		string out = "";

		if (u_bill > 0)
		{
			out.append(didget_to_string((int)u_bill));
			out.append(",");
			out.append(didget_to_string((int)c_mill));
			out.append(didget_to_string((int)d_mill));
			out.append(didget_to_string((int)u_mill));
			out.append(" M");
		}
		else if (c_mill > 0)
		{
			out.append(didget_to_string((int)c_mill));
			out.append(didget_to_string((int)d_mill));
			out.append(didget_to_string((int)u_mill));
			out.append(",");
			out.append(didget_to_string((int)c_kilo));
			out.append(didget_to_string((int)d_kilo));
			out.append(didget_to_string((int)u_kilo));
			out.append(" K");
		}

		else if (d_mill > 0)
		{
			out.append(didget_to_string((int)d_mill));
			out.append(didget_to_string((int)u_mill));
			out.append(",");
			out.append(didget_to_string((int)c_kilo));
			out.append(didget_to_string((int)d_kilo));
			out.append(didget_to_string((int)u_kilo));
			out.append(" K");
		}

		else if (u_mill > 0)
		{
			out.append(didget_to_string((int)u_mill));
			out.append(",");
			out.append(didget_to_string((int)c_kilo));
			out.append(didget_to_string((int)d_kilo));
			out.append(didget_to_string((int)u_kilo));
			out.append(" K");
		}

		else if (c_kilo > 0)
		{

			out.append(didget_to_string((int)c_kilo));
			out.append(didget_to_string((int)d_kilo));
			out.append(didget_to_string((int)u_kilo));
			out.append(",");
			out.append(didget_to_string((int)c_unit));
			out.append(didget_to_string((int)d_unit));
			out.append(didget_to_string((int)u_unit));
		}

		else if (d_kilo > 0)
		{

			out.append(didget_to_string((int)d_kilo));
			out.append(didget_to_string((int)u_kilo));
			out.append(",");
			out.append(didget_to_string((int)c_unit));
			out.append(didget_to_string((int)d_unit));
			out.append(didget_to_string((int)u_unit));
		}

		else if (u_kilo > 0)
		{
			out.append(didget_to_string((int)u_kilo));
			out.append(",");
			out.append(didget_to_string((int)c_unit));
			out.append(didget_to_string((int)d_unit));
			out.append(didget_to_string((int)u_unit));
		}

		else if (c_unit > 0)
		{
			out.append(didget_to_string((int)c_unit));
			out.append(didget_to_string((int)d_unit));
			out.append(didget_to_string((int)u_unit));
		}

		else if (d_unit > 0)
		{
			out.append(didget_to_string((int)d_unit));
			out.append(didget_to_string((int)u_unit));
		}

		else
		{
			out.append(didget_to_string((int)u_unit));
		}

		return out;


	}

	string int_to_string_leading_zero(int in)
	{
		string out = "";

		int thousants = in / 1000;
		int hundreds = (in - thousants*1000) /100;
		int tens = (in - thousants*1000 - hundreds*100) /10;
		int units = in - thousants*1000 - hundreds*100 - tens*10;

		out.append(didget_to_string(thousants));
		out.append(didget_to_string(hundreds));
		out.append(didget_to_string(tens));
		out.append(didget_to_string(units));

		return out;

	}

	string didget_to_string(int in)
	{
		if (in == 0) {return "0";}
		if (in == 1) {return "1";}
		if (in == 2) {return "2";}
		if (in == 3) {return "3";}
		if (in == 4) {return "4";}
		if (in == 5) {return "5";}
		if (in == 6) {return "6";}
		if (in == 7) {return "7";}
		if (in == 8) {return "8";}
		if (in == 9) {return "9";}
		return "0";
	}


	// this returns a x*y empty texture
	unsigned char* empty_texture(int x_size, int y_size)
	{
		unsigned char* tex; // the array that is going to be the output
		int tex_byte_size = x_size*y_size*4; // 4 being the bytes per pixel for 32 bit color;
		tex = new unsigned char [tex_byte_size];
		for (int s = 0; s < tex_byte_size ; s++){tex[s] = 0x00;}

		return tex;

	}

	unsigned char* empty_ucharp(int size)
	{
		if (size < 1) {return NULL;}

		unsigned char* out = new unsigned char[size];

		for (int i = 0; i < size; i++)
		{
			out[i] = 0;
		}

		return out;
	}

	void insert_texture (int dest_x_size, int dest_y_size, unsigned char* dest, int sor_x_size, int sor_y_size, unsigned char* sor, int x_startat, int y_startat, int sor_x_orig, int sor_y_orig)
	{

		int cur_sor_pix = 0;
		for (int y_insert = 0; y_insert < sor_y_size; y_insert++)
		{
			for (int x_insert = 0; x_insert < sor_x_size; x_insert++)
			{
				if ( (x_insert < sor_x_orig) && y_insert < sor_y_orig)
				{
					// get our insert color
					unsigned char ins_r = sor[ 4*cur_sor_pix   ];
					unsigned char ins_g = sor[(4*cur_sor_pix)+1];
					unsigned char ins_b = sor[(4*cur_sor_pix)+2];
					unsigned char ins_a = sor[(4*cur_sor_pix)+3];

				raster_pix(dest, dest_x_size, dest_y_size ,x_startat + x_insert, y_startat + y_insert, ins_r, ins_g, ins_b, ins_a);
				//void raster_pix(unsigned char* tex, int tex_x, int tex_y ,int x, int y, unsigned char byte, unsigned char* pal)
				}

				cur_sor_pix ++;

			}
		}


	}

	// This returns the smallest power of 2 that is bigger or equal to  x
	// Well not really, but this is not for math but for texture creation
	int power_of_two(int x)
	{

		if (x <   9) {return    8;}
		if (x <  17) {return   16;}
		if (x <  33) {return   32;}
		if (x <  65) {return   64;}
		if (x < 129) {return  128;}
		if (x < 257) {return  256;}
		if (x < 513) {return  512;}
		if (x <1025) {return 1024;}
		return 2048;

	}


	int maxi_chunkyness(int x, int y)
	{
		int smalldim = x;
		if (y < x){smalldim = y;}
		return power_of_two(smalldim);


	}

	int auto_chunkyness(int x, int y)
	{
		// here we guess the right chunkyness value for any given x and y
		int smalldim = x;
		if (y < x){smalldim = y;}
		smalldim = power_of_two(smalldim);

		if (smalldim < 64) { return smalldim; }
		if (smalldim < 256) { return 32; }
		if (smalldim < 512) { return 64; }
		return 128;

	}

	int validate_chunkyness(int x, int y, int chunkyness)
	{
		//  y and y must be powers of 2. else chunkyness is pointless ayway
		// chunkyness must also be a power of 2, but we are going to check that.

		int smalldim = x;
		if (y < x){smalldim = y;}

		int out = chunkyness;

		if (chunkyness != 8 && chunkyness != 16 && chunkyness != 32 && chunkyness != 64 && chunkyness != 128 && chunkyness != 256 )
		{
			out = auto_chunkyness(x, y);
		}
		else if ( chunkyness > smalldim)
		{
			out = auto_chunkyness(x, y);
		}

		return out;

	}



	void texture_set_error(unsigned char* tex)
	{

		tex[0] = 0xFF; tex[1] = 0x00; tex[2] = 0x00; tex[3] = 0x00;
		texture_set_warning(tex);


	}
	bool texture_get_error(unsigned char* tex)
	{
		bool out = false;


		if(  (tex[0] == 0xFF) && (tex[1] == 0x00) && (tex[2] == 0x00) && (tex[3] == 0x00)    )
		{
			out = true;
		}


		return out;
	}

	void texture_set_warning(unsigned char* tex)
	{

		tex[8] = 0xFF; tex[9] = 0x00; tex[10] = 0x00; tex[11] = 0x00;


	}
	bool texture_get_warning(unsigned char* tex)
	{
		bool out = false;


		if(  (tex[8] == 0xFF) && (tex[9] == 0x00) && (tex[10] == 0x00) && (tex[11] == 0x00)    )
		{
			out = true;
		}

		return out;
	}



	// this returns a x*y test texture
	unsigned char* test_texture(int x_size, int y_size)
	{
		unsigned char* tex; // the array that is going to be the output
		int tex_byte_size = x_size*y_size*4; // 4 being the bytes per pixel for 32 bit color;
		tex = new unsigned char [tex_byte_size];
		for (int s = 0; s < tex_byte_size ; s++){tex[s] = 0xff;}


		for ( int i = 0; (i < x_size)  && (y_size > 4); i++)
		{
			raster_pix(tex, x_size, y_size , i, 0,        0xff, 0x00, 0x00, 0xff);
			raster_pix(tex, x_size, y_size , i, 1,        0x00, 0x00, 0x00, 0x00);
			raster_pix(tex, x_size, y_size , i, 2,        0x00, 0xff, 0x00, 0xff);
			raster_pix(tex, x_size, y_size , i, 3,        0x00, 0x00, 0xff, 0xff);

			raster_pix(tex, x_size, y_size , i, y_size-4, 0x00, 0x00, 0xff, 0xff);
			raster_pix(tex, x_size, y_size , i, y_size-3, 0x00, 0xff, 0x00, 0xff);
			raster_pix(tex, x_size, y_size , i, y_size-2, 0x00, 0x00, 0x00, 0x00);
			raster_pix(tex, x_size, y_size , i, y_size-1, 0xff, 0x00, 0x00, 0xff);

		}

		return tex;

	}






	// This stamps a number in hexadecimal in texture tex
	void stamp_tex(unsigned char* tex, int x_size, int y_size, int stampno)
	{
		if (stampno < 0x1000 && stampno > -1)
		{

			int upper = stampno / 0x100;
			int middle = (stampno - upper*0x100)/ 0x10;
			int lower = (stampno - upper*0x100 - middle*0x10);

			stamp_letter(tex, x_size, y_size, 11, 13, upper);
			stamp_letter(tex, x_size, y_size, 15, 13, middle);
			stamp_letter(tex, x_size, y_size, 19, 13, lower);

			raster_pix(tex, x_size, y_size, 0, 0); //this stamps the 0,0 pixel aswell
		}

	}



	// This stams a hexadecimal letter into a texture at coords x,y.
	void stamp_letter(unsigned char* tex, int tex_x, int tex_y, int x, int y, int letter)
	{
		if (letter == 0)
		{
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+2			);
		}
		else if (letter == 1)
		{
			raster_pix(tex, tex_x, tex_y,		x			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+3			);
		}
		else if (letter == 2)
		{
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+4			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+4			);
		}
		else if (letter == 3)
		{
			raster_pix(tex, tex_x, tex_y,		x			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+4			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+4			);
		}
		else if (letter == 4)
		{
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+3			);
		}
		else if (letter == 5)
		{
			raster_pix(tex, tex_x, tex_y,		x			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+4			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+4			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+4			);
		}
		if (letter == 6)
		{
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+4			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+4			);
		}
		if (letter == 7)
		{
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+3			);
		}
		if (letter == 8)
		{
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+4			);
		}
		else if (letter == 9)
		{
			raster_pix(tex, tex_x, tex_y,		x			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+4			);
		}
		else if (letter == 0xa)
		{
			raster_pix(tex, tex_x, tex_y,		x			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+3			);
		}
		if (letter == 0xb)
		{
			raster_pix(tex, tex_x, tex_y,		x			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+4			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+4			);
		}
		if (letter == 0xc)
		{
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+3			);
		}
		if (letter == 0xd)
		{
			raster_pix(tex, tex_x, tex_y,		x			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+3			);
		}
		if (letter == 0xe)
		{
			raster_pix(tex, tex_x, tex_y,		x			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+4			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+4			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+4			);
		}
		if (letter == 0xf)
		{
			raster_pix(tex, tex_x, tex_y,		x			, 		y			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+1			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+2			);
			raster_pix(tex, tex_x, tex_y,		x			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+1			, 		y+3			);
			raster_pix(tex, tex_x, tex_y,		x+2			, 		y+3			);
		}




	}


	// this takes a a texture 'tex' with size 'tex_x', 'tex_y' and draws the pixel 'byte' on coords 'x' and 'y'
	// according to the palet 'pal'
	void raster_pix(unsigned char* tex, int tex_x, int tex_y ,int x, int y, unsigned char byte, unsigned char* pal)
	{

		raster_pix(tex, tex_x, tex_y, x, y, pal[ 3 * byte], pal[(3 * byte) +1], pal[(3 * byte) +2], 0xFF);
		//cout << " pixel " << tex_x << " " << tex_y << " " << x << " " << y << endl;
	}

	// This stamps a purple pixel (xy) of a serial number into a texture of size tex_x, tex_y
	void raster_pix(unsigned char* tex, int tex_x, int tex_y, int x, int y)
	{
		raster_pix(tex, tex_x, tex_y, x, y, 0xff, 0x00, 0xff, 0xFF);
	}


	// this takes a a texture 'tex' with size 'tex_x', 'tex_y' and draws the pixel rgb on xy
	void raster_pix(unsigned char* tex, int tex_x, int tex_y ,int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{

		if (   (4*(tex_x*y +x) +3 < 4*tex_x*tex_y) && (tex_x*y +x > -1)) //see if we are within bounds
		{
			tex[4*(tex_x*y +x)   ] = r;
			tex[4*(tex_x*y +x) +1] = g;
			tex[4*(tex_x*y +x) +2] = b;
			tex[4*(tex_x*y +x) +3] = a;
		}

	}

	// this returns the proper xy values for a frame from objcurs.cel
	di_int objcurs_xy(int no)
	{

		if      (no <   0) {return di_int(32,32);} // safety
		else if (no <   1) {return di_int(33,29);} // standart mousepointer
		else if (no <  10) {return di_int(32,32);} // other mousepointers
		else if (no <  11) {return di_int(23,35);} // sand clock
		else if (no <  61) {return di_int(28,28);} // one slot items
		else if (no <  67) {return di_int(28,56);} // two slot items
		else if (no <  86) {return di_int(28,84);} // tree slot items
		else if (no < 111) {return di_int(56,56);} // four slot items
		else if (no < 179) {return di_int(56,84);} // six slot items
		else               {return di_int(32,32);} // safety

	}





	float find_hud_transparency(int transp)
	{
		return 0.05*(float)(10-transp) + 0.5;
	}


	di_float find_backdrop_anchor(float screen_size_x, float screen_size_y)
	{
		float backdrop_anchor_x = (screen_size_x - (float)ORIGINAL_WIDTH) /2.0;
		float backdrop_anchor_y = (screen_size_y - (float)ORIGINAL_HEIGHT) /2.0;


		return di_float(backdrop_anchor_x, backdrop_anchor_y);
	}

	di_float find_charstat_anchor(float screen_size_x, float screen_size_y)
	{
		if ( (screen_size_x < ORIGINAL_WIDTH -1) || (screen_size_y < ORIGINAL_HEIGHT -1))
		{
			return di_float(0,128);
		}

		di_float out = find_backdrop_anchor(screen_size_x, screen_size_y);
		out.y = out.y + 128.0  - 0.25*(screen_size_y - ORIGINAL_HEIGHT);
		if (out.y > 160.0)  {out.y = 160.0;}


		if (out.x > 200.0) {out.x = out.x - 200.0;}
		else {out.x = 0.0;}

		return out;
	}

	di_float find_inventory_anchor(float screen_size_x, float screen_size_y)
	{
		di_float out = find_charstat_anchor(screen_size_x, screen_size_y);
		out.x = screen_size_x - out.x  - 320;
		return out;
	}



	// this replaces all the question marks (?) in path with what is in newsep
	string fix_dir_separator(string path, string newsep)
	{
		int pathsize = path.size();

		for (int i = 0; i < pathsize ; i++)
		{

			if ( path.at(i) == '?'  )
			{
				path.replace(i,1,newsep);
			}
		}
		return path;
	}

	void proc_time_waster()
	{
		for (int i = 1; i < 1000000; i ++)
		{
			int xx = 23*i + 129856 / i;
			xx++;

		}

	}


	//this returns a font code for a particular string command, used by the textline class
	int textline_get_fontcode(string st)
	{
		if 		(st == "{sys}") { return FONT_SYS; }
		else if (st == "{sma}") { return FONT_SMALL; }
		else if (st == "{24g}") { return FONT_TWENTYFOUR_G; }
		else if (st == "{24s}") { return FONT_TWENTYFOUR_S ;}
		else if (st == "{30g}") { return FONT_THIRTY_G; }
		else if (st == "{30s}") { return FONT_THIRTY_S; }
		else if (st == "{42g}") { return FONT_FOURTYTWO_G; }
		else if (st == "{42s}") { return FONT_FOURTYTWO_S; }


		else if (st == "{16g}") { return FONT_SIXTEEN_G; }
		else if (st == "{16s}") { return FONT_SIXTEEN_S; }


		else                    { return FONT_SMALL; }
	}



	//this returns a rgb color code for a particular string command, used by the textline class
	tri_float textline_get_colorcode(string st)
	{
		     if (st == "(whi)") { return tri_float(1.0, 1.0, 1.0); }
		else if (st == "(yel)") { return tri_float(1.0, 1.0, 0.4); }
		else if (st == "(gol)") { return tri_float(0.0039*(float)0xd9, 0.0039*(float)0xd5, 0.0039*(float)0x9a); }
		else if (st == "(blu)") { return tri_float(0.4, 0.4, 1.0); }
		else if (st == "(grn)") { return tri_float(0.4, 1.0, 1.0); }
		else if (st == "(red)") { return tri_float(1.0, 0.4, 0.4); }
		else if (st == "(sil)") { return tri_float(0.5, 0.5, 0.5); }
		else                    { return tri_float(1.0, 1.0, 1.0); }
	}


	//this returns a font code for a particular text justify command, used by the textline class
	int textline_get_justifycode(string st)
	{
		     if (st == "<lef>") { return TEXT_JUSTIFY_LEFT; }
		else if (st == "<cen>") { return TEXT_JUSTIFY_CENTER; }
		else if (st == "<rig>") { return TEXT_JUSTIFY_RIGHT; }
		else                    { return TEXT_JUSTIFY_LEFT; }
	}

	//this returns a font code for a particular text spacing command, used by the textline class
	int textline_get_spacingcode(string st)
	{
		     if (st == "$s00$") { return 0; }
		else if (st == "$s01$") { return 1; }
		else if (st == "$s02$") { return 2; }
		else if (st == "$s03$") { return 3; }
		else if (st == "$s04$") { return 4; }
		else                    { return 0; }
	}



	// this returns the texture number for the letter in string st while using font fnt and the spacing the char requires
	// out.x is the spacing, out.y is the texure number. used by the textline class
	di_int textline_get_width_and_number(string st, int fnt)
	{

		if (st == " ") // space
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  5, VOID_TEXTURE);
				case FONT_SMALL : 			return di_int(  5, VOID_TEXTURE);
				case FONT_SIXTEEN_G : 		return di_int(  5, VOID_TEXTURE);
				case FONT_SIXTEEN_S : 		return di_int(  5, VOID_TEXTURE);
				case FONT_TWENTYFOUR_G : 	return di_int(  6, VOID_TEXTURE);
				case FONT_TWENTYFOUR_S : 	return di_int(  6, VOID_TEXTURE);
				case FONT_THIRTY_G : 		return di_int(  8, VOID_TEXTURE);
				case FONT_THIRTY_S : 		return di_int(  8, VOID_TEXTURE);
				case FONT_FOURTYTWO_G : 	return di_int( 10, VOID_TEXTURE);
				case FONT_FOURTYTWO_S : 	return di_int( 10, VOID_TEXTURE);
			}
		}


		else if ((st == "A"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x1a);
				case FONT_SMALL : 			return di_int( 10,  0x0);
				case FONT_SIXTEEN_G : 		return di_int( 11, 0x41);
				case FONT_SIXTEEN_S : 		return di_int( 11, 0x41);
				case FONT_TWENTYFOUR_G : 	return di_int( 17, 0x41);
				case FONT_TWENTYFOUR_S : 	return di_int( 17, 0x41);
				case FONT_THIRTY_G : 		return di_int( 21, 0x41);
				case FONT_THIRTY_S : 		return di_int( 21, 0x41);
				case FONT_FOURTYTWO_G : 	return di_int( 29, 0x41);
				case FONT_FOURTYTWO_S : 	return di_int( 29, 0x41);
			}
		}
		else if ( (st == "B"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x1b);
				case FONT_SMALL : 			return di_int(  6,  0x1);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x42);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x42);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x42);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x42);
				case FONT_THIRTY_G : 		return di_int( 14, 0x42);
				case FONT_THIRTY_S : 		return di_int( 14, 0x42);
				case FONT_FOURTYTWO_G : 	return di_int( 19, 0x42);
				case FONT_FOURTYTWO_S : 	return di_int( 19, 0x42);
			}
		}
		else if ( (st == "C"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x1c);
				case FONT_SMALL : 			return di_int(  9,  0x2);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x43);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x43);
				case FONT_TWENTYFOUR_G : 	return di_int( 14, 0x43);
				case FONT_TWENTYFOUR_S : 	return di_int( 14, 0x43);
				case FONT_THIRTY_G : 		return di_int( 16, 0x43);
				case FONT_THIRTY_S : 		return di_int( 16, 0x43);
				case FONT_FOURTYTWO_G : 	return di_int( 22, 0x43);
				case FONT_FOURTYTWO_S : 	return di_int( 22, 0x43);
			}
		}
		else if ( (st == "D"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x1d);
				case FONT_SMALL : 			return di_int(  8,  0x3);
				case FONT_SIXTEEN_G : 		return di_int( 10, 0x44);
				case FONT_SIXTEEN_S : 		return di_int( 10, 0x44);
				case FONT_TWENTYFOUR_G : 	return di_int( 14, 0x44);
				case FONT_TWENTYFOUR_S : 	return di_int( 14, 0x44);
				case FONT_THIRTY_G : 		return di_int( 17, 0x44);
				case FONT_THIRTY_S : 		return di_int( 17, 0x44);
				case FONT_FOURTYTWO_G : 	return di_int( 23, 0x44);
				case FONT_FOURTYTWO_S : 	return di_int( 23, 0x44);
			}
		}
		else if ( (st == "E"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 10, 0x1e);
				case FONT_SMALL : 			return di_int(  7,  0x4);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x45);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x45);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x45);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x45);
				case FONT_THIRTY_G : 		return di_int( 15, 0x45);
				case FONT_THIRTY_S : 		return di_int( 15, 0x45);
				case FONT_FOURTYTWO_G : 	return di_int( 20, 0x45);
				case FONT_FOURTYTWO_S : 	return di_int( 20, 0x45);
			}
		}
		else if ( (st == "F"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 10, 0x1f);
				case FONT_SMALL : 			return di_int(  6,  0x5);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x46);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x46);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x46);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x46);
				case FONT_THIRTY_G : 		return di_int( 14, 0x46);
				case FONT_THIRTY_S : 		return di_int( 14, 0x46);
				case FONT_FOURTYTWO_G : 	return di_int( 18, 0x46);
				case FONT_FOURTYTWO_S : 	return di_int( 18, 0x46);
			}
		}
		else if ( (st == "G"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x20);
				case FONT_SMALL : 			return di_int(  8,  0x6);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0x47);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0x47);
				case FONT_TWENTYFOUR_G : 	return di_int( 13, 0x47);
				case FONT_TWENTYFOUR_S : 	return di_int( 13, 0x47);
				case FONT_THIRTY_G : 		return di_int( 16, 0x47);
				case FONT_THIRTY_S : 		return di_int( 16, 0x47);
				case FONT_FOURTYTWO_G : 	return di_int( 22, 0x47);
				case FONT_FOURTYTWO_S : 	return di_int( 22, 0x47);
			}
		}
		else if ( (st == "H"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x21);
				case FONT_SMALL : 			return di_int(  8,  0x7);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x48);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x48);
				case FONT_TWENTYFOUR_G : 	return di_int( 13, 0x48);
				case FONT_TWENTYFOUR_S : 	return di_int( 13, 0x48);
				case FONT_THIRTY_G : 		return di_int( 15, 0x48);
				case FONT_THIRTY_S : 		return di_int( 15, 0x48);
				case FONT_FOURTYTWO_G : 	return di_int( 21, 0x48);
				case FONT_FOURTYTWO_S : 	return di_int( 21, 0x48);
			}
		}
		else if ( (st == "I"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  6, 0x22);
				case FONT_SMALL : 			return di_int(  3,  0x8);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x49);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x49);
				case FONT_TWENTYFOUR_G : 	return di_int(  6, 0x49);
				case FONT_TWENTYFOUR_S : 	return di_int(  6, 0x49);
				case FONT_THIRTY_G : 		return di_int(  7, 0x49);
				case FONT_THIRTY_S : 		return di_int(  7, 0x49);
				case FONT_FOURTYTWO_G : 	return di_int( 10, 0x49);
				case FONT_FOURTYTWO_S : 	return di_int( 10, 0x49);
			}
		}
		else if ( (st == "J"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  7, 0x23);
				case FONT_SMALL : 			return di_int(  3,  0x9);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x4a);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x4a);
				case FONT_TWENTYFOUR_G : 	return di_int(  6, 0x4a);
				case FONT_TWENTYFOUR_S : 	return di_int(  6, 0x4a);
				case FONT_THIRTY_G : 		return di_int(  7, 0x4a);
				case FONT_THIRTY_S : 		return di_int(  7, 0x4a);
				case FONT_FOURTYTWO_G : 	return di_int( 10, 0x4a);
				case FONT_FOURTYTWO_S : 	return di_int( 10, 0x4a);
			}
		}
		else if ( (st == "K"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x24);
				case FONT_SMALL : 			return di_int(  7,  0xa);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x4b);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x4b);
				case FONT_TWENTYFOUR_G : 	return di_int( 14, 0x4b);
				case FONT_TWENTYFOUR_S : 	return di_int( 14, 0x4b);
				case FONT_THIRTY_G : 		return di_int( 16, 0x4b);
				case FONT_THIRTY_S : 		return di_int( 16, 0x4b);
				case FONT_FOURTYTWO_G : 	return di_int( 23, 0x4b);
				case FONT_FOURTYTWO_S : 	return di_int( 23, 0x4b);
			}
		}
		else if ((st == "L"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 10, 0x25);
				case FONT_SMALL : 			return di_int(  6, 0x0b);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x4c);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x4c);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x4c);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x4c);
				case FONT_THIRTY_G : 		return di_int( 13, 0x4c);
				case FONT_THIRTY_S : 		return di_int( 13, 0x4c);
				case FONT_FOURTYTWO_G : 	return di_int( 18, 0x4c);
				case FONT_FOURTYTWO_S : 	return di_int( 18, 0x4c);
			}
		}
		else if ((st == "M"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 14, 0x26);
				case FONT_SMALL : 			return di_int( 11, 0xc);
				case FONT_SIXTEEN_G : 		return di_int( 11, 0x4d);
				case FONT_SIXTEEN_S : 		return di_int( 11, 0x4d);
				case FONT_TWENTYFOUR_G : 	return di_int( 16, 0x4d);
				case FONT_TWENTYFOUR_S : 	return di_int( 16, 0x4d);
				case FONT_THIRTY_G : 		return di_int( 21, 0x4d);
				case FONT_THIRTY_S : 		return di_int( 21, 0x4d);
				case FONT_FOURTYTWO_G : 	return di_int( 29, 0x4d);
				case FONT_FOURTYTWO_S : 	return di_int( 29, 0x4d);
			}
		}
		else if ((st == "N"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x27);
				case FONT_SMALL : 			return di_int(  9, 0xd);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0x4e);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0x4e);
				case FONT_TWENTYFOUR_G : 	return di_int( 14, 0x4e);
				case FONT_TWENTYFOUR_S : 	return di_int( 14, 0x4e);
				case FONT_THIRTY_G : 		return di_int( 18, 0x4e);
				case FONT_THIRTY_S : 		return di_int( 18, 0x4e);
				case FONT_FOURTYTWO_G : 	return di_int( 25, 0x4e);
				case FONT_FOURTYTWO_S : 	return di_int( 25, 0x4e);
			}
		}
		else if ( (st == "O"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x28);
				case FONT_SMALL : 			return di_int( 10, 0x0e);
				case FONT_SIXTEEN_G : 		return di_int( 10, 0x4f);
				case FONT_SIXTEEN_S : 		return di_int( 10, 0x4f);
				case FONT_TWENTYFOUR_G : 	return di_int( 16, 0x4f);
				case FONT_TWENTYFOUR_S : 	return di_int( 16, 0x4f);
				case FONT_THIRTY_G : 		return di_int( 20, 0x4f);
				case FONT_THIRTY_S : 		return di_int( 20, 0x4f);
				case FONT_FOURTYTWO_G : 	return di_int( 27, 0x4f);
				case FONT_FOURTYTWO_S : 	return di_int( 27, 0x4f);
			}
		}
		else if ( (st == "P"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x29);
				case FONT_SMALL : 			return di_int(  6,  0xf);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x50);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x50);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x50);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x50);
				case FONT_THIRTY_G : 		return di_int( 13, 0x50);
				case FONT_THIRTY_S : 		return di_int( 13, 0x50);
				case FONT_FOURTYTWO_G : 	return di_int( 20, 0x50);
				case FONT_FOURTYTWO_S : 	return di_int( 20, 0x50);
			}
		}
		else if ( (st == "Q"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x2a);
				case FONT_SMALL : 			return di_int(  9, 0x10);
				case FONT_SIXTEEN_G : 		return di_int( 11, 0x51);
				case FONT_SIXTEEN_S : 		return di_int( 11, 0x51);
				case FONT_TWENTYFOUR_G : 	return di_int( 16, 0x51);
				case FONT_TWENTYFOUR_S : 	return di_int( 16, 0x51);
				case FONT_THIRTY_G : 		return di_int( 20, 0x51);
				case FONT_THIRTY_S : 		return di_int( 20, 0x51);
				case FONT_FOURTYTWO_G : 	return di_int( 27, 0x51);
				case FONT_FOURTYTWO_S : 	return di_int( 27, 0x51);
			}
		}
		else if ( (st == "R"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x2b);
				case FONT_SMALL : 			return di_int(  9, 0x11);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0x52);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0x52);
				case FONT_TWENTYFOUR_G : 	return di_int( 14, 0x52);
				case FONT_TWENTYFOUR_S : 	return di_int( 14, 0x52);
				case FONT_THIRTY_G : 		return di_int( 17, 0x52);
				case FONT_THIRTY_S : 		return di_int( 17, 0x52);
				case FONT_FOURTYTWO_G : 	return di_int( 25, 0x52);
				case FONT_FOURTYTWO_S : 	return di_int( 25, 0x52);
			}
		}
		else if ( (st == "S"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x2c);
				case FONT_SMALL : 			return di_int(  5, 0x12);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x53);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x53);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x53);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x53);
				case FONT_THIRTY_G : 		return di_int( 13, 0x53);
				case FONT_THIRTY_S : 		return di_int( 13, 0x53);
				case FONT_FOURTYTWO_G : 	return di_int( 18, 0x53);
				case FONT_FOURTYTWO_S : 	return di_int( 18, 0x53);
			}
		}
		else if ( (st == "T"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 10, 0x2d);
				case FONT_SMALL : 			return di_int(  9, 0x13);
				case FONT_SIXTEEN_G : 		return di_int( 10, 0x54);
				case FONT_SIXTEEN_S : 		return di_int( 10, 0x54);
				case FONT_TWENTYFOUR_G : 	return di_int( 15, 0x54);
				case FONT_TWENTYFOUR_S : 	return di_int( 15, 0x54);
				case FONT_THIRTY_G : 		return di_int( 19, 0x54);
				case FONT_THIRTY_S : 		return di_int( 19, 0x54);
				case FONT_FOURTYTWO_G : 	return di_int( 27, 0x54);
				case FONT_FOURTYTWO_S : 	return di_int( 27, 0x54);
			}
		}
		else if ( (st == "U"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x2e);
				case FONT_SMALL : 			return di_int( 10, 0x14);
				case FONT_SIXTEEN_G : 		return di_int( 11, 0x55);
				case FONT_SIXTEEN_S : 		return di_int( 11, 0x55);
				case FONT_TWENTYFOUR_G : 	return di_int( 17, 0x55);
				case FONT_TWENTYFOUR_S : 	return di_int( 17, 0x55);
				case FONT_THIRTY_G : 		return di_int( 22, 0x55);
				case FONT_THIRTY_S : 		return di_int( 22, 0x55);
				case FONT_FOURTYTWO_G : 	return di_int( 30, 0x55);
				case FONT_FOURTYTWO_S : 	return di_int( 30, 0x55);
			}
		}
		else if ( (st == "V"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x2f);
				case FONT_SMALL : 			return di_int( 10, 0x15);
				case FONT_SIXTEEN_G : 		return di_int( 12, 0x56);
				case FONT_SIXTEEN_S : 		return di_int( 12, 0x56);
				case FONT_TWENTYFOUR_G : 	return di_int( 17, 0x56);
				case FONT_TWENTYFOUR_S : 	return di_int( 17, 0x56);
				case FONT_THIRTY_G : 		return di_int( 22, 0x56);
				case FONT_THIRTY_S : 		return di_int( 22, 0x56);
				case FONT_FOURTYTWO_G : 	return di_int( 30, 0x56);
				case FONT_FOURTYTWO_S : 	return di_int( 30, 0x56);
			}
		}
		else if ( (st == "W"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 15, 0x30);
				case FONT_SMALL : 			return di_int( 13, 0x16);
				case FONT_SIXTEEN_G : 		return di_int( 14, 0x57);
				case FONT_SIXTEEN_S : 		return di_int( 14, 0x57);
				case FONT_TWENTYFOUR_G : 	return di_int( 23, 0x57);
				case FONT_TWENTYFOUR_S : 	return di_int( 23, 0x57);
				case FONT_THIRTY_G : 		return di_int( 29, 0x57);
				case FONT_THIRTY_S : 		return di_int( 29, 0x57);
				case FONT_FOURTYTWO_G : 	return di_int( 40, 0x57);
				case FONT_FOURTYTWO_S : 	return di_int( 40, 0x57);
			}
		}
		else if ((st == "X"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 14, 0x31);
				case FONT_SMALL : 			return di_int( 10, 0x17);
				case FONT_SIXTEEN_G : 		return di_int( 11, 0x58);
				case FONT_SIXTEEN_S : 		return di_int( 11, 0x58);
				case FONT_TWENTYFOUR_G : 	return di_int( 17, 0x58);
				case FONT_TWENTYFOUR_S : 	return di_int( 17, 0x58);
				case FONT_THIRTY_G : 		return di_int( 21, 0x58);
				case FONT_THIRTY_S : 		return di_int( 21, 0x58);
				case FONT_FOURTYTWO_G : 	return di_int( 28, 0x58);
				case FONT_FOURTYTWO_S : 	return di_int( 28, 0x58);
			}
		}
		else if ( (st == "Y"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 12, 0x32);
				case FONT_SMALL : 			return di_int( 11, 0x18);
				case FONT_SIXTEEN_G : 		return di_int( 11, 0x59);
				case FONT_SIXTEEN_S : 		return di_int( 11, 0x59);
				case FONT_TWENTYFOUR_G : 	return di_int( 16, 0x59);
				case FONT_TWENTYFOUR_S : 	return di_int( 16, 0x59);
				case FONT_THIRTY_G : 		return di_int( 21, 0x59);
				case FONT_THIRTY_S : 		return di_int( 21, 0x59);
				case FONT_FOURTYTWO_G : 	return di_int( 28, 0x59);
				case FONT_FOURTYTWO_S : 	return di_int( 28, 0x59);
			}
		}
		else if ( (st == "Z"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 12, 0x33);
				case FONT_SMALL : 			return di_int(  7, 0x19);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0x5a);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0x5a);
				case FONT_TWENTYFOUR_G : 	return di_int( 12, 0x5a);
				case FONT_TWENTYFOUR_S : 	return di_int( 12, 0x5a);
				case FONT_THIRTY_G : 		return di_int( 15, 0x5a);
				case FONT_THIRTY_S : 		return di_int( 15, 0x5a);
				case FONT_FOURTYTWO_G : 	return di_int( 21, 0x5a);
				case FONT_FOURTYTWO_S : 	return di_int( 21, 0x5a);
			}
		}
		else if ((st == "a"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11,  0x0);
				case FONT_SMALL : 			return di_int( 10,  0x0);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0x61);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0x61);
				case FONT_TWENTYFOUR_G : 	return di_int( 13, 0x61);
				case FONT_TWENTYFOUR_S : 	return di_int( 13, 0x61);
				case FONT_THIRTY_G : 		return di_int( 18, 0x61);
				case FONT_THIRTY_S : 		return di_int( 18, 0x61);
				case FONT_FOURTYTWO_G : 	return di_int( 25, 0x61);
				case FONT_FOURTYTWO_S : 	return di_int( 25, 0x61);
			}
		}
		else if ( (st == "b"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11,  0x1);
				case FONT_SMALL : 			return di_int(  6,  0x1);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x62);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x62);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x62);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x62);
				case FONT_THIRTY_G : 		return di_int( 11, 0x62);
				case FONT_THIRTY_S : 		return di_int( 11, 0x62);
				case FONT_FOURTYTWO_G : 	return di_int( 16, 0x62);
				case FONT_FOURTYTWO_S : 	return di_int( 16, 0x62);
			}
		}
		else if ( (st == "c"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11,  0x2);
				case FONT_SMALL : 			return di_int(  9,  0x2);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x63);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x63);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x63);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x63);
				case FONT_THIRTY_G : 		return di_int( 14, 0x63);
				case FONT_THIRTY_S : 		return di_int( 14, 0x63);
				case FONT_FOURTYTWO_G : 	return di_int( 19, 0x63);
				case FONT_FOURTYTWO_S : 	return di_int( 19, 0x63);
			}
		}
		else if ( (st == "d"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11,  0x3);
				case FONT_SMALL : 			return di_int(  8,  0x3);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x64);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x64);
				case FONT_TWENTYFOUR_G : 	return di_int( 12, 0x64);
				case FONT_TWENTYFOUR_S : 	return di_int( 12, 0x64);
				case FONT_THIRTY_G : 		return di_int( 15, 0x64);
				case FONT_THIRTY_S : 		return di_int( 15, 0x64);
				case FONT_FOURTYTWO_G : 	return di_int( 20, 0x64);
				case FONT_FOURTYTWO_S : 	return di_int( 20, 0x64);
			}
		}
		else if ( (st == "e"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11,  0x4);
				case FONT_SMALL : 			return di_int(  7,  0x4);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x65);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x65);
				case FONT_TWENTYFOUR_G : 	return di_int(  8, 0x65);
				case FONT_TWENTYFOUR_S : 	return di_int(  8, 0x65);
				case FONT_THIRTY_G : 		return di_int( 12, 0x65);
				case FONT_THIRTY_S : 		return di_int( 12, 0x65);
				case FONT_FOURTYTWO_G : 	return di_int( 16, 0x65);
				case FONT_FOURTYTWO_S : 	return di_int( 16, 0x65);
			}
		}
		else if ( (st == "f"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  9,  0x5);
				case FONT_SMALL : 			return di_int(  6,  0x5);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x66);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x66);
				case FONT_TWENTYFOUR_G : 	return di_int(  9, 0x66);
				case FONT_TWENTYFOUR_S : 	return di_int(  9, 0x66);
				case FONT_THIRTY_G : 		return di_int( 11, 0x66);
				case FONT_THIRTY_S : 		return di_int( 11, 0x66);
				case FONT_FOURTYTWO_G : 	return di_int( 16, 0x66);
				case FONT_FOURTYTWO_S : 	return di_int( 16, 0x66);
			}
		}
		else if ( (st == "g"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11,  0x6);
				case FONT_SMALL : 			return di_int(  8,  0x6);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x67);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x67);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x67);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x67);
				case FONT_THIRTY_G : 		return di_int( 14, 0x67);
				case FONT_THIRTY_S : 		return di_int( 14, 0x67);
				case FONT_FOURTYTWO_G : 	return di_int( 19, 0x67);
				case FONT_FOURTYTWO_S : 	return di_int( 19, 0x67);
			}
		}
		else if ( (st == "h"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11,  0x7);
				case FONT_SMALL : 			return di_int(  8,  0x7);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x68);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x68);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x68);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x68);
				case FONT_THIRTY_G : 		return di_int( 13, 0x68);
				case FONT_THIRTY_S : 		return di_int( 13, 0x68);
				case FONT_FOURTYTWO_G : 	return di_int( 18, 0x68);
				case FONT_FOURTYTWO_S : 	return di_int( 18, 0x68);
			}
		}
		else if ( (st == "i"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  4,  0x8);
				case FONT_SMALL : 			return di_int(  3,  0x8);
				case FONT_SIXTEEN_G : 		return di_int(  3, 0x69);
				case FONT_SIXTEEN_S : 		return di_int(  3, 0x69);
				case FONT_TWENTYFOUR_G : 	return di_int(  5, 0x69);
				case FONT_TWENTYFOUR_S : 	return di_int(  5, 0x69);
				case FONT_THIRTY_G : 		return di_int(  6, 0x69);
				case FONT_THIRTY_S : 		return di_int(  6, 0x69);
				case FONT_FOURTYTWO_G : 	return di_int(  9, 0x69);
				case FONT_FOURTYTWO_S : 	return di_int(  9, 0x69);
			}
		}
		else if ( (st == "j"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  6,  0x9);
				case FONT_SMALL : 			return di_int(  3,  0x9);
				case FONT_SIXTEEN_G : 		return di_int(  3, 0x6a);
				case FONT_SIXTEEN_S : 		return di_int(  3, 0x6a);
				case FONT_TWENTYFOUR_G : 	return di_int(  5, 0x6a);
				case FONT_TWENTYFOUR_S : 	return di_int(  5, 0x6a);
				case FONT_THIRTY_G : 		return di_int(  7, 0x6a);
				case FONT_THIRTY_S : 		return di_int(  7, 0x6a);
				case FONT_FOURTYTWO_G : 	return di_int(  9, 0x6a);
				case FONT_FOURTYTWO_S : 	return di_int(  9, 0x6a);
			}
		}
		else if ( (st == "k"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  9,  0xa);
				case FONT_SMALL : 			return di_int(  7,  0xa);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x6b);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x6b);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x6b);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x6b);
				case FONT_THIRTY_G : 		return di_int( 13, 0x6b);
				case FONT_THIRTY_S : 		return di_int( 13, 0x6b);
				case FONT_FOURTYTWO_G : 	return di_int( 18, 0x6b);
				case FONT_FOURTYTWO_S : 	return di_int( 18, 0x6b);
			}
		}
		else if ((st == "l"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  4,  0xb);
				case FONT_SMALL : 			return di_int(  6, 0x0b);
				case FONT_SIXTEEN_G : 		return di_int(  5, 0x6c);
				case FONT_SIXTEEN_S : 		return di_int(  5, 0x6c);
				case FONT_TWENTYFOUR_G : 	return di_int(  9, 0x6c);
				case FONT_TWENTYFOUR_S : 	return di_int(  9, 0x6c);
				case FONT_THIRTY_G : 		return di_int( 11, 0x6c);
				case FONT_THIRTY_S : 		return di_int( 11, 0x6c);
				case FONT_FOURTYTWO_G : 	return di_int( 16, 0x6c);
				case FONT_FOURTYTWO_S : 	return di_int( 16, 0x6c);
			}
		}
		else if ((st == "m"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 14,  0xc);
				case FONT_SMALL : 			return di_int( 11, 0x0c);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0x6d);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0x6d);
				case FONT_TWENTYFOUR_G : 	return di_int( 14, 0x6d);
				case FONT_TWENTYFOUR_S : 	return di_int( 14, 0x6d);
				case FONT_THIRTY_G : 		return di_int( 18, 0x6d);
				case FONT_THIRTY_S : 		return di_int( 18, 0x6d);
				case FONT_FOURTYTWO_G : 	return di_int( 23, 0x6d);
				case FONT_FOURTYTWO_S : 	return di_int( 23, 0x6d);
			}
		}
		else if ((st == "n"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11,  0xd);
				case FONT_SMALL : 			return di_int(  9, 0x0d);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x6e);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x6e);
				case FONT_TWENTYFOUR_G : 	return di_int( 12, 0x6e);
				case FONT_TWENTYFOUR_S : 	return di_int( 12, 0x6e);
				case FONT_THIRTY_G : 		return di_int( 15, 0x6e);
				case FONT_THIRTY_S : 		return di_int( 15, 0x6e);
				case FONT_FOURTYTWO_G : 	return di_int( 20, 0x6e);
				case FONT_FOURTYTWO_S : 	return di_int( 20, 0x6e);
			}
		}
		else if ( (st == "o"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11,  0xe);
				case FONT_SMALL : 			return di_int( 10, 0x0e);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0x6f);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0x6f);
				case FONT_TWENTYFOUR_G : 	return di_int( 12, 0x6f);
				case FONT_TWENTYFOUR_S : 	return di_int( 12, 0x6f);
				case FONT_THIRTY_G : 		return di_int( 16, 0x6f);
				case FONT_THIRTY_S : 		return di_int( 16, 0x6f);
				case FONT_FOURTYTWO_G : 	return di_int( 22, 0x6f);
				case FONT_FOURTYTWO_S : 	return di_int( 22, 0x6f);
			}
		}
		else if ( (st == "p"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11,  0xf);
				case FONT_SMALL : 			return di_int(  6,  0xf);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x70);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x70);
				case FONT_TWENTYFOUR_G : 	return di_int(  9, 0x70);
				case FONT_TWENTYFOUR_S : 	return di_int(  9, 0x70);
				case FONT_THIRTY_G : 		return di_int( 12, 0x70);
				case FONT_THIRTY_S : 		return di_int( 12, 0x70);
				case FONT_FOURTYTWO_G : 	return di_int( 16, 0x70);
				case FONT_FOURTYTWO_S : 	return di_int( 16, 0x70);
			}
		}
		else if ( (st == "q"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x10);
				case FONT_SMALL : 			return di_int(  9, 0x10);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0x71);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0x71);
				case FONT_TWENTYFOUR_G : 	return di_int( 13, 0x71);
				case FONT_TWENTYFOUR_S : 	return di_int( 13, 0x71);
				case FONT_THIRTY_G : 		return di_int( 17, 0x71);
				case FONT_THIRTY_S : 		return di_int( 17, 0x71);
				case FONT_FOURTYTWO_G : 	return di_int( 23, 0x71);
				case FONT_FOURTYTWO_S : 	return di_int( 23, 0x71);
			}
		}
		else if ( (st == "r"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 10, 0x11);
				case FONT_SMALL : 			return di_int(  9, 0x11);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x72);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x72);
				case FONT_TWENTYFOUR_G : 	return di_int( 12, 0x72);
				case FONT_TWENTYFOUR_S : 	return di_int( 12, 0x72);
				case FONT_THIRTY_G : 		return di_int( 15, 0x72);
				case FONT_THIRTY_S : 		return di_int( 15, 0x72);
				case FONT_FOURTYTWO_G : 	return di_int( 20, 0x72);
				case FONT_FOURTYTWO_S : 	return di_int( 20, 0x72);
			}
		}
		else if ( (st == "s"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x12);
				case FONT_SMALL : 			return di_int(  5, 0x12);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x73);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x73);
				case FONT_TWENTYFOUR_G : 	return di_int(  8, 0x73);
				case FONT_TWENTYFOUR_S : 	return di_int(  8, 0x73);
				case FONT_THIRTY_G : 		return di_int( 12, 0x73);
				case FONT_THIRTY_S : 		return di_int( 12, 0x73);
				case FONT_FOURTYTWO_G : 	return di_int( 15, 0x73);
				case FONT_FOURTYTWO_S : 	return di_int( 15, 0x73);
			}
		}
		else if ( (st == "t"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  9, 0x13);
				case FONT_SMALL : 			return di_int(  9, 0x13);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x74);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x74);
				case FONT_TWENTYFOUR_G : 	return di_int( 14, 0x74);
				case FONT_TWENTYFOUR_S : 	return di_int( 14, 0x74);
				case FONT_THIRTY_G : 		return di_int( 16, 0x74);
				case FONT_THIRTY_S : 		return di_int( 16, 0x74);
				case FONT_FOURTYTWO_G : 	return di_int( 22, 0x74);
				case FONT_FOURTYTWO_S : 	return di_int( 22, 0x74);
			}
		}
		else if ( (st == "u"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x14);
				case FONT_SMALL : 			return di_int( 10, 0x14);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0x75);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0x75);
				case FONT_TWENTYFOUR_G : 	return di_int( 14, 0x75);
				case FONT_TWENTYFOUR_S : 	return di_int( 14, 0x75);
				case FONT_THIRTY_G : 		return di_int( 19, 0x75);
				case FONT_THIRTY_S : 		return di_int( 19, 0x75);
				case FONT_FOURTYTWO_G : 	return di_int( 24, 0x75);
				case FONT_FOURTYTWO_S : 	return di_int( 24, 0x75);
			}
		}
		else if ( (st == "v"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x15);
				case FONT_SMALL : 			return di_int( 10, 0x15);
				case FONT_SIXTEEN_G : 		return di_int( 10, 0x76);
				case FONT_SIXTEEN_S : 		return di_int( 10, 0x76);
				case FONT_TWENTYFOUR_G : 	return di_int( 14, 0x76);
				case FONT_TWENTYFOUR_S : 	return di_int( 14, 0x76);
				case FONT_THIRTY_G : 		return di_int( 18, 0x76);
				case FONT_THIRTY_S : 		return di_int( 18, 0x76);
				case FONT_FOURTYTWO_G : 	return di_int( 25, 0x76);
				case FONT_FOURTYTWO_S : 	return di_int( 25, 0x76);
			}
		}
		else if ( (st == "w"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 15, 0x16);
				case FONT_SMALL : 			return di_int( 13, 0x16);
				case FONT_SIXTEEN_G : 		return di_int( 12, 0x77);
				case FONT_SIXTEEN_S : 		return di_int( 12, 0x77);
				case FONT_TWENTYFOUR_G : 	return di_int( 19, 0x77);
				case FONT_TWENTYFOUR_S : 	return di_int( 19, 0x77);
				case FONT_THIRTY_G : 		return di_int( 23, 0x77);
				case FONT_THIRTY_S : 		return di_int( 23, 0x77);
				case FONT_FOURTYTWO_G : 	return di_int( 32, 0x77);
				case FONT_FOURTYTWO_S : 	return di_int( 32, 0x77);
			}
		}
		else if ((st == "x"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 12, 0x17);
				case FONT_SMALL : 			return di_int( 10, 0x17);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0x78);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0x78);
				case FONT_TWENTYFOUR_G : 	return di_int( 13, 0x78);
				case FONT_TWENTYFOUR_S : 	return di_int( 13, 0x78);
				case FONT_THIRTY_G : 		return di_int( 17, 0x78);
				case FONT_THIRTY_S : 		return di_int( 17, 0x78);
				case FONT_FOURTYTWO_G : 	return di_int( 23, 0x78);
				case FONT_FOURTYTWO_S : 	return di_int( 23, 0x78);
			}
		}
		else if ( (st == "y"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x18);
				case FONT_SMALL : 			return di_int( 11, 0x18);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0x79);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0x79);
				case FONT_TWENTYFOUR_G : 	return di_int( 13, 0x79);
				case FONT_TWENTYFOUR_S : 	return di_int( 13, 0x79);
				case FONT_THIRTY_G : 		return di_int( 18, 0x79);
				case FONT_THIRTY_S : 		return di_int( 18, 0x79);
				case FONT_FOURTYTWO_G : 	return di_int( 23, 0x79);
				case FONT_FOURTYTWO_S : 	return di_int( 23, 0x79);
			}
		}
		else if ( (st == "z"))
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 10, 0x19);
				case FONT_SMALL : 			return di_int(  7, 0x19);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x7a);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x7a);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x7a);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x7a);
				case FONT_THIRTY_G : 		return di_int( 13, 0x7a);
				case FONT_THIRTY_S : 		return di_int( 13, 0x7a);
				case FONT_FOURTYTWO_G : 	return di_int( 18, 0x7a);
				case FONT_FOURTYTWO_S : 	return di_int( 18, 0x7a);
			}
		}
		else if (st == "1")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  6, 0x34);
				case FONT_SMALL : 			return di_int(  3, 0x1a);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x31);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x31);
				case FONT_TWENTYFOUR_G : 	return di_int(  7, 0x31);
				case FONT_TWENTYFOUR_S : 	return di_int(  7, 0x31);
				case FONT_THIRTY_G : 		return di_int(  8, 0x31);
				case FONT_THIRTY_S : 		return di_int(  8, 0x31);
				case FONT_FOURTYTWO_G : 	return di_int( 12, 0x31);
				case FONT_FOURTYTWO_S : 	return di_int( 12, 0x31);
			}
		}
		else if (st == "2")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x35);
				case FONT_SMALL : 			return di_int(  6, 0x1b);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x32);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x32);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x32);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x32);
				case FONT_THIRTY_G : 		return di_int( 14, 0x32);
				case FONT_THIRTY_S : 		return di_int( 14, 0x32);
				case FONT_FOURTYTWO_G : 	return di_int( 21, 0x32);
				case FONT_FOURTYTWO_S : 	return di_int( 21, 0x32);
			}
		}
		else if (st == "3")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x36);
				case FONT_SMALL : 			return di_int(  6, 0x1c);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x33);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x33);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x33);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x33);
				case FONT_THIRTY_G : 		return di_int( 14, 0x33);
				case FONT_THIRTY_S : 		return di_int( 14, 0x33);
				case FONT_FOURTYTWO_G : 	return di_int( 19, 0x33);
				case FONT_FOURTYTWO_S : 	return di_int( 19, 0x33);
			}
		}
		else if (st == "4")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x37);
				case FONT_SMALL : 			return di_int(  7, 0x1d);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x34);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x34);
				case FONT_TWENTYFOUR_G : 	return di_int( 12, 0x34);
				case FONT_TWENTYFOUR_S : 	return di_int( 12, 0x34);
				case FONT_THIRTY_G : 		return di_int( 15, 0x34);
				case FONT_THIRTY_S : 		return di_int( 15, 0x34);
				case FONT_FOURTYTWO_G : 	return di_int( 21, 0x34);
				case FONT_FOURTYTWO_S : 	return di_int( 21, 0x34);
			}
		}
		else if (st == "5")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x38);
				case FONT_SMALL : 			return di_int(  6, 0x1e);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x35);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x35);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x35);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x35);
				case FONT_THIRTY_G : 		return di_int( 14, 0x35);
				case FONT_THIRTY_S : 		return di_int( 14, 0x35);
				case FONT_FOURTYTWO_G : 	return di_int( 19, 0x35);
				case FONT_FOURTYTWO_S : 	return di_int( 19, 0x35);
			}
		}
		else if (st == "6")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x39);
				case FONT_SMALL : 			return di_int(  6, 0x1f);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x36);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x36);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x36);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x36);
				case FONT_THIRTY_G : 		return di_int( 14, 0x36);
				case FONT_THIRTY_S : 		return di_int( 14, 0x36);
				case FONT_FOURTYTWO_G : 	return di_int( 18, 0x36);
				case FONT_FOURTYTWO_S : 	return di_int( 18, 0x36);
			}
		}
		else if (st == "7")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x3a);
				case FONT_SMALL : 			return di_int(  6, 0x20);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x37);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x37);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x37);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x37);
				case FONT_THIRTY_G : 		return di_int( 14, 0x37);
				case FONT_THIRTY_S : 		return di_int( 14, 0x37);
				case FONT_FOURTYTWO_G : 	return di_int( 19, 0x37);
				case FONT_FOURTYTWO_S : 	return di_int( 19, 0x37);
			}
		}
		else if (st == "8")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x3b);
				case FONT_SMALL : 			return di_int(  5, 0x21);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x38);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x38);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x38);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x38);
				case FONT_THIRTY_G : 		return di_int( 14, 0x38);
				case FONT_THIRTY_S : 		return di_int( 14, 0x38);
				case FONT_FOURTYTWO_G : 	return di_int( 18, 0x38);
				case FONT_FOURTYTWO_S : 	return di_int( 18, 0x38);
			}
		}
		else if (st == "9")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x3c);
				case FONT_SMALL : 			return di_int(  6, 0x22);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x39);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x39);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x39);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x39);
				case FONT_THIRTY_G : 		return di_int( 13, 0x39);
				case FONT_THIRTY_S : 		return di_int( 13, 0x39);
				case FONT_FOURTYTWO_G : 	return di_int( 19, 0x39);
				case FONT_FOURTYTWO_S : 	return di_int( 19, 0x39);
			}
		}
		else if (st == "0")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x3d);
				case FONT_SMALL : 			return di_int(  9, 0x23);
				case FONT_SIXTEEN_G : 		return di_int( 11, 0x30);
				case FONT_SIXTEEN_S : 		return di_int( 11, 0x30);
				case FONT_TWENTYFOUR_G : 	return di_int( 16, 0x30);
				case FONT_TWENTYFOUR_S : 	return di_int( 16, 0x30);
				case FONT_THIRTY_G : 		return di_int( 21, 0x30);
				case FONT_THIRTY_S : 		return di_int( 21, 0x30);
				case FONT_FOURTYTWO_G : 	return di_int( 29, 0x30);
				case FONT_FOURTYTWO_S : 	return di_int( 28, 0x30);
			}
		}
		else if (st == "-")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  8, 0x3e);
				case FONT_SMALL : 			return di_int(  4, 0x24);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x2d);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x2d);
				case FONT_TWENTYFOUR_G : 	return di_int(  7, 0x2d);
				case FONT_TWENTYFOUR_S : 	return di_int(  7, 0x2d);
				case FONT_THIRTY_G : 		return di_int(  9, 0x2d);
				case FONT_THIRTY_S : 		return di_int(  9, 0x2d);
				case FONT_FOURTYTWO_G : 	return di_int( 12, 0x2d);
				case FONT_FOURTYTWO_S : 	return di_int( 12, 0x2d);
			}
		}
		else if (st == "=")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  8, 0x3f);
				case FONT_SMALL : 			return di_int( 05, 0x25);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x3d);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x3d);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x3d);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x3d);
				case FONT_THIRTY_G : 		return di_int(  9, 0x3d);
				case FONT_THIRTY_S : 		return di_int(  9, 0x3d);
				case FONT_FOURTYTWO_G : 	return di_int( 15, 0x3d);
				case FONT_FOURTYTWO_S : 	return di_int( 15, 0x3d);
			}
		}
		else if (st == "+")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  8, 0x40);
				case FONT_SMALL : 			return di_int(  6, 0x26);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x2b);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x2b);
				case FONT_TWENTYFOUR_G : 	return di_int(  9, 0x2b);
				case FONT_TWENTYFOUR_S : 	return di_int(  9, 0x2b);
				case FONT_THIRTY_G : 		return di_int( 11, 0x2b);
				case FONT_THIRTY_S : 		return di_int( 11, 0x2b);
				case FONT_FOURTYTWO_G : 	return di_int( 15, 0x2b);
				case FONT_FOURTYTWO_S : 	return di_int( 15, 0x2b);
			}
		}
		else if (st == "[softo]") // (
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  8, 0x41);
				case FONT_SMALL : 			return di_int(  3, 0x27);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x28);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x28);
				case FONT_TWENTYFOUR_G : 	return di_int(  7, 0x28);
				case FONT_TWENTYFOUR_S : 	return di_int(  7, 0x28);
				case FONT_THIRTY_G : 		return di_int(  9, 0x28);
				case FONT_THIRTY_S : 		return di_int(  9, 0x28);
				case FONT_FOURTYTWO_G : 	return di_int( 11, 0x28);
				case FONT_FOURTYTWO_S : 	return di_int( 11, 0x28);
			}
		}
		else if (st == "[softc]") // )
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  8, 0x42);
				case FONT_SMALL : 			return di_int(  3, 0x28);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x29);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x29);
				case FONT_TWENTYFOUR_G : 	return di_int(  6, 0x29);
				case FONT_TWENTYFOUR_S : 	return di_int(  6, 0x29);
				case FONT_THIRTY_G : 		return di_int(  9, 0x29);
				case FONT_THIRTY_S : 		return di_int(  9, 0x29);
				case FONT_FOURTYTWO_G : 	return di_int( 11, 0x29);
				case FONT_FOURTYTWO_S : 	return di_int( 11, 0x29);
			}
		}
		else if (st == "[hardo]") // [
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  7, 0x43);
				case FONT_SMALL : 			return di_int(  4, 0x29);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x5b);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x5b);
				case FONT_TWENTYFOUR_G : 	return di_int(  6, 0x5b);
				case FONT_TWENTYFOUR_S : 	return di_int(  6, 0x5b);
				case FONT_THIRTY_G : 		return di_int(  8, 0x5b);
				case FONT_THIRTY_S : 		return di_int(  8, 0x5b);
				case FONT_FOURTYTWO_G : 	return di_int( 10, 0x5b);
				case FONT_FOURTYTWO_S : 	return di_int( 10, 0x5b);
			}
		}
		else if (st == "[hardc]") // ]
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  7, 0x44);
				case FONT_SMALL : 			return di_int(  3, 0x2a);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x5d);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x5d);
				case FONT_TWENTYFOUR_G : 	return di_int(  6, 0x5d);
				case FONT_TWENTYFOUR_S : 	return di_int(  6, 0x5d);
				case FONT_THIRTY_G : 		return di_int(  7, 0x5d);
				case FONT_THIRTY_S : 		return di_int(  7, 0x5d);
				case FONT_FOURTYTWO_G : 	return di_int( 10, 0x5d);
				case FONT_FOURTYTWO_S : 	return di_int( 10, 0x5d);
			}
		}
		else if (st == "[dquoo]") // double-quote open
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  9, 0x45);
				case FONT_SMALL : 			return di_int(  5, 0x2b);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x22);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x22);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x22);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x22);
				case FONT_THIRTY_G : 		return di_int( 13, 0x22);
				case FONT_THIRTY_S : 		return di_int( 13, 0x22);
				case FONT_FOURTYTWO_G : 	return di_int( 17, 0x22);
				case FONT_FOURTYTWO_S : 	return di_int( 17, 0x22);
			}
		}
		else if (st == "[dquoc]") // double quote close
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  9, 0x46);
				case FONT_SMALL : 			return di_int(  6, 0x2c);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0x22);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0x22);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x22);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x22);
				case FONT_THIRTY_G : 		return di_int( 13, 0x22);
				case FONT_THIRTY_S : 		return di_int( 13, 0x22);
				case FONT_FOURTYTWO_G : 	return di_int( 17, 0x22);
				case FONT_FOURTYTWO_S : 	return di_int( 17, 0x22);
			}
		}
		else if ((st == "[squoo]") || (st == "'") ) // single quote open
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  5, 0x47);
				case FONT_SMALL : 			return di_int(  3, 0x2d);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x91);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x91);
				case FONT_TWENTYFOUR_G : 	return di_int(  6, 0x91);
				case FONT_TWENTYFOUR_S : 	return di_int(  6, 0x91);
				case FONT_THIRTY_G : 		return di_int(  7, 0x91);
				case FONT_THIRTY_S : 		return di_int(  7, 0x91);
				case FONT_FOURTYTWO_G : 	return di_int( 10, 0x91);
				case FONT_FOURTYTWO_S : 	return di_int( 10, 0x91);
			}
		}


		else if (st == "[squoc]") // single quote close
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  5, 0x48);
				case FONT_SMALL : 			return di_int(  3, 0x2e);
				case FONT_SIXTEEN_G : 		return di_int(  5, 0x92);
				case FONT_SIXTEEN_S : 		return di_int(  5, 0x92);
				case FONT_TWENTYFOUR_G : 	return di_int(  6, 0x92);
				case FONT_TWENTYFOUR_S : 	return di_int(  6, 0x92);
				case FONT_THIRTY_G : 		return di_int(  7, 0x92);
				case FONT_THIRTY_S : 		return di_int(  7, 0x92);
				case FONT_FOURTYTWO_G : 	return di_int( 10, 0x92);
				case FONT_FOURTYTWO_S : 	return di_int( 10, 0x92);
			}
		}
		else if (st == ":") // double point
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  5, 0x49);
				case FONT_SMALL : 			return di_int(  3, 0x2f);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x3a);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x3a);
				case FONT_TWENTYFOUR_G : 	return di_int(  5, 0x3a);
				case FONT_TWENTYFOUR_S : 	return di_int(  5, 0x3a);
				case FONT_THIRTY_G : 		return di_int(  7, 0x3a);
				case FONT_THIRTY_S : 		return di_int(  7, 0x3a);
				case FONT_FOURTYTWO_G : 	return di_int(  9, 0x3a);
				case FONT_FOURTYTWO_S : 	return di_int(  9, 0x3a);
			}
		}
		else if (st == ";") // point-comma
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  5, 0x4a);
				case FONT_SMALL : 			return di_int(  3, 0x30);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x3b);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x3b);
				case FONT_TWENTYFOUR_G : 	return di_int(  6, 0x3b);
				case FONT_TWENTYFOUR_S : 	return di_int(  6, 0x3b);
				case FONT_THIRTY_G : 		return di_int(  7, 0x3b);
				case FONT_THIRTY_S : 		return di_int(  7, 0x3b);
				case FONT_FOURTYTWO_G : 	return di_int( 10, 0x3b);
				case FONT_FOURTYTWO_S : 	return di_int( 10, 0x3b);
			}
		}
		else if (st == ",") // comma
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  5, 0x4b);
				case FONT_SMALL : 			return di_int(  3, 0x31);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x2c);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x2c);
				case FONT_TWENTYFOUR_G : 	return di_int(  5, 0x2c);
				case FONT_TWENTYFOUR_S : 	return di_int(  5, 0x2c);
				case FONT_THIRTY_G : 		return di_int(  8, 0x2c);
				case FONT_THIRTY_S : 		return di_int(  8, 0x2c);
				case FONT_FOURTYTWO_G : 	return di_int( 10, 0x2c);
				case FONT_FOURTYTWO_S : 	return di_int( 10, 0x2c);
			}
		}
		else if (st == ".") // point
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  5, 0x4c);
				case FONT_SMALL : 			return di_int(  2, 0x32);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x2e);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x2e);
				case FONT_TWENTYFOUR_G : 	return di_int(  5, 0x2e);
				case FONT_TWENTYFOUR_S : 	return di_int(  5, 0x2e);
				case FONT_THIRTY_G : 		return di_int(  7, 0x2e);
				case FONT_THIRTY_S : 		return di_int(  7, 0x2e);
				case FONT_FOURTYTWO_G : 	return di_int(  9, 0x2e);
				case FONT_FOURTYTWO_S : 	return di_int(  9, 0x2e);
			}
		}
		else if (st == "[slash]") // /
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 10, 0x4d);
				case FONT_SMALL : 			return di_int(  7, 0x33);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x2f);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x2f);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0x2f);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0x2f);
				case FONT_THIRTY_G : 		return di_int( 15, 0x2f);
				case FONT_THIRTY_S : 		return di_int( 15, 0x2f);
				case FONT_FOURTYTWO_G : 	return di_int( 20, 0x2f);
				case FONT_FOURTYTWO_S : 	return di_int( 20, 0x2f);
			}
		}
		else if (st == "?")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x4e);
				case FONT_SMALL : 			return di_int(  6, 0x34);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0xb8);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0xb8);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0xb8);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0xb8);
				case FONT_THIRTY_G : 		return di_int( 14, 0xb8);
				case FONT_THIRTY_S : 		return di_int( 14, 0xb8);
				case FONT_FOURTYTWO_G : 	return di_int( 18, 0xb8);
				case FONT_FOURTYTWO_S : 	return di_int( 18, 0xb8);
			}
		}
		else if (st == "!")
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  4, 0x4f);
				case FONT_SMALL : 			return di_int(  3, 0x35);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0x21);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0x21);
				case FONT_TWENTYFOUR_G : 	return di_int(  6, 0x21);
				case FONT_TWENTYFOUR_S : 	return di_int(  6, 0x21);
				case FONT_THIRTY_G : 		return di_int(  7, 0x21);
				case FONT_THIRTY_S : 		return di_int(  7, 0x21);
				case FONT_FOURTYTWO_G : 	return di_int(  9, 0x21);
				case FONT_FOURTYTWO_S : 	return di_int(  9, 0x21);
			}
		}
		else if (st == "[andie]") // &
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 13, 0x50);
				case FONT_SMALL : 			return di_int( 10, 0x36);
				case FONT_SIXTEEN_G : 		return di_int( 11, 0x26);
				case FONT_SIXTEEN_S : 		return di_int( 11, 0x26);
				case FONT_TWENTYFOUR_G : 	return di_int( 16, 0x26);
				case FONT_TWENTYFOUR_S : 	return di_int( 16, 0x26);
				case FONT_THIRTY_G : 		return di_int( 20, 0x26);
				case FONT_THIRTY_S : 		return di_int( 20, 0x26);
				case FONT_FOURTYTWO_G : 	return di_int( 27, 0x26);
				case FONT_FOURTYTWO_S : 	return di_int( 27, 0x26);
			}
		}
		else if (st == "[pcent]") // %
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 14, 0x51);
				case FONT_SMALL : 			return di_int( 10, 0x37);
				case FONT_SIXTEEN_G : 		return di_int( 12, 0x25);
				case FONT_SIXTEEN_S : 		return di_int( 12, 0x25);
				case FONT_TWENTYFOUR_G : 	return di_int( 17, 0x25);
				case FONT_TWENTYFOUR_S : 	return di_int( 17, 0x25);
				case FONT_THIRTY_G : 		return di_int( 22, 0x25);
				case FONT_THIRTY_S : 		return di_int( 22, 0x25);
				case FONT_FOURTYTWO_G : 	return di_int( 30, 0x25);
				case FONT_FOURTYTWO_S : 	return di_int( 30, 0x25);
			}
		}

		else if (st == "[sharp]") // #
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 13, 0x52);
				case FONT_SMALL : 			return di_int(  6, 0x38);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x23);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x23);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x23);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x23);
				case FONT_THIRTY_G : 		return di_int( 14, 0x23);
				case FONT_THIRTY_S : 		return di_int( 14, 0x23);
				case FONT_FOURTYTWO_G : 	return di_int( 18, 0x23);
				case FONT_FOURTYTWO_S : 	return di_int( 18, 0x23);
			}
		}
		else if (st == "[money]") // $
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 12, 0x53);
				case FONT_SMALL : 			return di_int(  6, 0x39);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0x24);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0x24);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0x24);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0x24);
				case FONT_THIRTY_G : 		return di_int( 14, 0x24);
				case FONT_THIRTY_S : 		return di_int( 14, 0x24);
				case FONT_FOURTYTWO_G : 	return di_int( 18, 0x24);
				case FONT_FOURTYTWO_S : 	return di_int( 18, 0x24);
			}
		}
		else if (st == "[stari]") // *
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 14, 0x54);
				case FONT_SMALL : 			return di_int(  7, 0x3a);
				case FONT_SIXTEEN_G : 		return di_int(  9, 0xd7);
				case FONT_SIXTEEN_S : 		return di_int(  9, 0xd7);
				case FONT_TWENTYFOUR_G : 	return di_int( 11, 0xd7);
				case FONT_TWENTYFOUR_S : 	return di_int( 11, 0xd7);
				case FONT_THIRTY_G : 		return di_int( 14, 0xd7);
				case FONT_THIRTY_S : 		return di_int( 14, 0xd7);
				case FONT_FOURTYTWO_G : 	return di_int( 19, 0xd7);
				case FONT_FOURTYTWO_S : 	return di_int( 19, 0xd7);
			}
		}
		else if (st == "[arowo]") // <
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x55);
				case FONT_SMALL : 			return di_int(  4, 0x3b);
				case FONT_SIXTEEN_G : 		return di_int(  5, 0x3c);
				case FONT_SIXTEEN_S : 		return di_int(  5, 0x3c);
				case FONT_TWENTYFOUR_G : 	return di_int(  8, 0x3c);
				case FONT_TWENTYFOUR_S : 	return di_int(  8, 0x3c);
				case FONT_THIRTY_G : 		return di_int(  9, 0x3c);
				case FONT_THIRTY_S : 		return di_int(  9, 0x3c);
				case FONT_FOURTYTWO_G : 	return di_int( 12, 0x3c);
				case FONT_FOURTYTWO_S : 	return di_int( 12, 0x3c);
			}
		}
		else if (st == "[arowc]") // >
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x56);
				case FONT_SMALL : 			return di_int(  4, 0x3c);
				case FONT_SIXTEEN_G : 		return di_int(  5, 0x3e);
				case FONT_SIXTEEN_S : 		return di_int(  5, 0x3e);
				case FONT_TWENTYFOUR_G : 	return di_int(  8, 0x3e);
				case FONT_TWENTYFOUR_S : 	return di_int(  8, 0x3e);
				case FONT_THIRTY_G : 		return di_int(  9, 0x3e);
				case FONT_THIRTY_S : 		return di_int(  9, 0x3e);
				case FONT_FOURTYTWO_G : 	return di_int( 12, 0x3e);
				case FONT_FOURTYTWO_S : 	return di_int( 12, 0x3e);
			}
		}
		else if (st == "[maili]") // @
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x57);
				case FONT_SMALL : 			return di_int(  9, 0x3d);
				case FONT_SIXTEEN_G : 		return di_int( 10, 0x40);
				case FONT_SIXTEEN_S : 		return di_int( 10, 0x40);
				case FONT_TWENTYFOUR_G : 	return di_int( 16, 0x40);
				case FONT_TWENTYFOUR_S : 	return di_int( 17, 0x40);
				case FONT_THIRTY_G : 		return di_int( 20, 0x40);
				case FONT_THIRTY_S : 		return di_int( 20, 0x40);
				case FONT_FOURTYTWO_G : 	return di_int( 27, 0x40);
				case FONT_FOURTYTWO_S : 	return di_int( 27, 0x40);
			}
		}
		else if (st == "[bslsh]") // backslash or bullit
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 10, 0x58);
				case FONT_SMALL : 			return di_int(  6, 0x3e);
				case FONT_SIXTEEN_G : 		return di_int(  5, 0x2a);
				case FONT_SIXTEEN_S : 		return di_int(  5, 0x2a);
				case FONT_TWENTYFOUR_G : 	return di_int( 17, 0x2a);
				case FONT_TWENTYFOUR_S : 	return di_int( 17, 0x2a);
				case FONT_THIRTY_G : 		return di_int( 10, 0x2a);
				case FONT_THIRTY_S : 		return di_int( 10, 0x2a);
				case FONT_FOURTYTWO_G : 	return di_int( 13, 0x2a);
				case FONT_FOURTYTWO_S : 	return di_int( 13, 0x2a);
			}
		}
		else if (st == "[roofi]") // ^
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x59);
				case FONT_SMALL : 			return di_int(  6, 0x3f);
				case FONT_SIXTEEN_G : 		return di_int(  4, 0xa8);
				case FONT_SIXTEEN_S : 		return di_int(  4, 0xa8);
				case FONT_TWENTYFOUR_G : 	return di_int(  7, 0x5e);
				case FONT_TWENTYFOUR_S : 	return di_int(  7, 0x5e);
				case FONT_THIRTY_G : 		return di_int(  9, 0x5e);
				case FONT_THIRTY_S : 		return di_int(  9, 0x5e);
				case FONT_FOURTYTWO_G : 	return di_int( 11, 0x5e);
				case FONT_FOURTYTWO_S : 	return di_int( 11, 0x5e);
			}
		}
		else if (st == "[uscor]") // underscore
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x5a);
				case FONT_SMALL : 			return di_int( 11, 0x40);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x5f);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x5f);
				case FONT_TWENTYFOUR_G : 	return di_int(  9, 0x5f);
				case FONT_TWENTYFOUR_S : 	return di_int(  9, 0x5f);
				case FONT_THIRTY_G : 		return di_int( 14, 0x5f);
				case FONT_THIRTY_S : 		return di_int( 14, 0x5f);
				case FONT_FOURTYTWO_G : 	return di_int( 20, 0x5f);
				case FONT_FOURTYTWO_S : 	return di_int( 20, 0x5f);
			}
		}
		else if (st == "_") // underscore
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 11, 0x5a);
				case FONT_SMALL : 			return di_int( 11, 0x40);
				case FONT_SIXTEEN_G : 		return di_int(  8, 0x5f);
				case FONT_SIXTEEN_S : 		return di_int(  8, 0x5f);
				case FONT_TWENTYFOUR_G : 	return di_int(  9, 0x5f);
				case FONT_TWENTYFOUR_S : 	return di_int(  9, 0x5f);
				case FONT_THIRTY_G : 		return di_int( 14, 0x5f);
				case FONT_THIRTY_S : 		return di_int( 14, 0x5f);
				case FONT_FOURTYTWO_G : 	return di_int( 20, 0x5f);
				case FONT_FOURTYTWO_S : 	return di_int( 20, 0x5f);
			}
		}
		else if (st == "[verti]") // |
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int(  4, 0x5b);
				case FONT_SMALL : 			return di_int(  3, 0x41);
				case FONT_SIXTEEN_G : 		return di_int(  3, 0x7c);
				case FONT_SIXTEEN_S : 		return di_int(  3, 0x7c);
				case FONT_TWENTYFOUR_G : 	return di_int(  3, 0x7c);
				case FONT_TWENTYFOUR_S : 	return di_int(  3, 0x7c);
				case FONT_THIRTY_G : 		return di_int(  6, 0x7c);
				case FONT_THIRTY_S : 		return di_int(  6, 0x7c);
				case FONT_FOURTYTWO_G : 	return di_int(  5, 0x7c);
				case FONT_FOURTYTWO_S : 	return di_int(  5, 0x7c);
			}
		}
		else if (st == "[tilde]") // ~
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 12, 0x5c);
				case FONT_SMALL : 			return di_int(  7, 0x42);
				case FONT_SIXTEEN_G : 		return di_int(  5, 0x7e);
				case FONT_SIXTEEN_S : 		return di_int(  5, 0x7e);
				case FONT_TWENTYFOUR_G : 	return di_int(  8, 0x7e);
				case FONT_TWENTYFOUR_S : 	return di_int(  8, 0x7e);
				case FONT_THIRTY_G : 		return di_int( 10, 0x7e);
				case FONT_THIRTY_S : 		return di_int( 10, 0x7e);
				case FONT_FOURTYTWO_G : 	return di_int( 12, 0x7e);
				case FONT_FOURTYTWO_S : 	return di_int( 12, 0x7e);
			}
		}
		else if (st == "[copyr]") // (c)
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 14, 0x5d);
				case FONT_SMALL : 			return di_int(  9, 0x2);
				case FONT_SIXTEEN_G : 		return di_int( 10, 0xa9);
				case FONT_SIXTEEN_S : 		return di_int( 10, 0xa9);
				case FONT_TWENTYFOUR_G : 	return di_int( 15, 0xa9);
				case FONT_TWENTYFOUR_S : 	return di_int( 15, 0xa9);
				case FONT_THIRTY_G : 		return di_int( 20, 0xa9);
				case FONT_THIRTY_S : 		return di_int( 20, 0xa9);
				case FONT_FOURTYTWO_G : 	return di_int( 27, 0xa9);
				case FONT_FOURTYTWO_S : 	return di_int( 27, 0xa9);
			}
		}
		else if (st == "[regis]") // (r)
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 14, 0x5e);
				case FONT_SMALL : 			return di_int(  9, 0x11);
				case FONT_SIXTEEN_G : 		return di_int( 10, 0xae);
				case FONT_SIXTEEN_S : 		return di_int( 10, 0xae);
				case FONT_TWENTYFOUR_G : 	return di_int( 16, 0xae);
				case FONT_TWENTYFOUR_S : 	return di_int( 16, 0xae);
				case FONT_THIRTY_G : 		return di_int( 20, 0xae);
				case FONT_THIRTY_S : 		return di_int( 20, 0xae);
				case FONT_FOURTYTWO_G : 	return di_int( 27, 0xae);
				case FONT_FOURTYTWO_S : 	return di_int( 27, 0xae);
			}
		}
		else if (st == "[darwo]") // <<
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 15, 0x5f);
				case FONT_SMALL : 			return di_int(  4, 0x3b);
				case FONT_SIXTEEN_G : 		return di_int(  6, 0xab);
				case FONT_SIXTEEN_S : 		return di_int(  6, 0xab);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0xab);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0xab);
				case FONT_THIRTY_G : 		return di_int( 13, 0xab);
				case FONT_THIRTY_S : 		return di_int( 13, 0xab);
				case FONT_FOURTYTWO_G : 	return di_int( 16, 0xab);
				case FONT_FOURTYTWO_S : 	return di_int( 16, 0xab);
			}
		}
		else if (st == "[darwc]") // >>
		{
			switch(fnt)
			{
				case FONT_SYS :				return di_int( 15, 0x60);
				case FONT_SMALL : 			return di_int(  4, 0x3c);
				case FONT_SIXTEEN_G : 		return di_int(  7, 0xbb);
				case FONT_SIXTEEN_S : 		return di_int(  7, 0xbb);
				case FONT_TWENTYFOUR_G : 	return di_int( 10, 0xbb);
				case FONT_TWENTYFOUR_S : 	return di_int( 10, 0xbb);
				case FONT_THIRTY_G : 		return di_int( 12, 0xbb);
				case FONT_THIRTY_S : 		return di_int( 12, 0xbb);
				case FONT_FOURTYTWO_G : 	return di_int( 17, 0xbb);
				case FONT_FOURTYTWO_S : 	return di_int( 17, 0xbb);
			}
		}


		return di_int(0,VOID_TEXTURE); // the 'error, no case found' output

	}

};

/*
 *

 0 33 29 // defualt pointer

1 32 32 // questionamark pointer
2 32 32 // hammer
3 32 32 // magic wand
4 32 32 // keyhole pointer
5 32 32 // pippet pointer
6 32 32 // teleport pointer
7 32 32 // cross pointer
8 32 32 // crosshair aim pointer
9 32 32 // medicine pointer

10 23 35 // sandclock

11 28 28 // big mana
12 28 28 // red scroll
13 28 28 // redder scroll
14 28 28 // blue scroll
15 28 28 // 3 coins
16 28 28 // 6 coins
17 28 28 // may coins
18 28 28 // thick plain ring
19 28 28 // red stone ring
20 28 28 // thorns ring
21 28 28 // blue stone ring
22 28 28 // tree skull ring
23 28 28 // plain thin ring
24 28 28 // square 4 stone ring
25 28 28 // red stone ring
26 28 28 // red lab vial
27 28 28 // fat rainbow flask
28 28 28 // gold branded flask
29 28 28 // clear stone ring
30 28 28 // dark ear
31 28 28 // light ear
32 28 28 // alt ear
33 28 28 // hellraiser coin
34 28 28 // hellraiser cube
35 28 28 // hellraider pyramid
36 28 28 // red gem diamond cut
37 28 28 // red gem round
38 28 28 // blue cube
39 28 28 // orange pyramid
40 28 28 // black thin lab vial
41 28 28 // black lab flask
42 28 28 // white branded vial
43 28 28 // red branded vial minor hp
44 28 28 // yellow round vial full rejuv
45 28 28 // fat orange flask
46 28 28 // fat red flask major hp
47 28 28 // square black flask
48 28 28 // square yellow flask major rejuv
49 28 28 // round clear vial
50 28 28 // blue minor mana
51 28 28 // brains!
52 28 28 // claw
53 28 28 // birdbeak
54 28 28 // bread
55 28 28 // white loopy neck
56 28 28 // standard steel neck
57 28 28 // black stone rad band neck
58 28 28 // white scarab blue stone
59 28 28 // loopy cross
60 28 28 // backpack

61 28 56 // wiggeling dagger
62 28 56 // staight dagger red shaft
63 28 56 // bottle o booze
64 28 56 // thick dagger
65 28 56 // striaght dagger blue shaft
66 28 56 // knuckle duster

67 28 84 // thin sword
68 28 84 // winged sword
69 28 84 // winged skimitar
70 28 84 // mace
71 28 84 // horseshoe sword
72 28 84 // thick sword
73 28 84 // extra curved skimitar
74 28 84 // spiky mace
75 28 84 // 3 slot dagger
76 28 84 // straight handle thin sword
77 28 84 // plank and nail
78 28 84 // spanish sword
79 28 84 // roman sword
80 28 84 // combat bone
81 28 84 // unique spiky mace
82 28 84 // short plank and nail
83 28 84 // curved spanish sword
84 28 84 // simple winged sword
85 28 84 // scary black sword

86 56 56 // slit helmet
87 56 56 // moon rock
88 56 56 // red gem spiky crown
89 56 56 // skull crown
90 56 56 // titan crown
91 56 56 // jokers cap
92 56 56 // red gem enchanter crown
93 56 56 // gas mask
94 56 56 // small round shield
95 56 56 // big horned helm
96 56 56 // black multihorn helm
97 56 56 // black book
98 56 56 // brown book
99 56 56 // blue book
100 56 56 // shroom
101 56 56 // steel skullcap
102 56 56 // leather cap
103 56 56 // torn flesh armor
104 56 56 // red steel skullcap
105 56 56 // red rags armor
106 56 56 // standard crown
107 56 56 // quest scroll
108 56 56 // quest book
109 56 56 // roman helm
110 56 56 // asian helm

111 56 84 // blue shield
112 56 84 // double edge axe
113 56 84 // bow
114 56 84 // light heavy armor
115 56 84 // blue axe
116 56 84 // wooden shield
117 56 84 // butchers cleaver
118 56 84 // black lether jacket
119 56 84 // spiky white bow
120 56 84 // simple staff
121 56 84 // red markings word
122 56 84 // chain armor
123 56 84 // red shaft axe
124 56 84 // blue and yellow shield
125 56 84 // lether and chain aromor
126 56 84 // titan shield
127 56 84 // black skull shield
128 56 84 // red boar shield
129 56 84 // alt simple bow
130 56 84 // siver bow
131 56 84 // blue bow
132 56 84 // red shaft hammer
133 56 84 // titan hammer
134 56 84 // arnies staff
135 56 84 // simple syth
136 56 84 // blue gem lsd staff
137 56 84 // tavern sign
138 56 84 // red roman armor
139 56 84 // leather rags
140 56 84 // red mail
141 56 84 // 3-head flail
142 56 84 // flial
143 56 84 // black tower shield
144 56 84 // enforced bow
145 56 84 // red band katana
146 56 84 // lether armor
147 56 84 // samurai outfit
148 56 84 // white robe
149 56 84 // black with red gem armor
150 56 84 // yellow spikkeled lether armor
151 56 84 // quest forge
152 56 84 // black long axe
153 56 84 // double edge blue axe
154 56 84 // skull axe
155 56 84 // simple long axe
156 56 84 // preadator bow
157 56 84 // red lion shield
158 56 84 // blue bird shield
159 56 84 // black lion shield
160 56 84 // white cape with hood
161 56 84 // red roman cape
162 56 84 // uberheavy armor
163 56 84 // black cross armor
164 56 84 // sleaveless plate
165 56 84 // back and brown robe
166 56 84 // skulls and red gem staff
167 56 84 // scarry red gem axe
168 56 84 // red bane aromor
169 56 84 // crossbow
170 56 84 // scarry red armor
171 56 84 // uberthick sword
172 56 84 // thin 2h sword
173 56 84 // black spiked baseball
174 56 84 // winged scarb axe
175 56 84 // egiptian bow
176 56 84 // blue small bow
177 56 84 // doublesided sythe
178 56 84 // wrikely bow
 */

