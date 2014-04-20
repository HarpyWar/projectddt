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




#include "levk_mkb_button_commando.cpp"
using namespace std;

// this class is for transcoding sound files. it currently doesnt do anything because we dont need it



class wavemaker
{
	public:

	int_floatp transcode(int file_size, unsigned char* file)
	{
		int file_chans;
		int file_bit_per_sample;
		int file_datablock_length;
		int file_datablock_offset = 44;



		if (file_size < 500)
		{
			cout << "DDT> wav_transcode unsupported input, file too short"  << file_size << endl;
			return int_floatp();
		}

		if (  (file[0] != 'R') || (file[1] != 'I') || (file[2] != 'F') || (file[3] != 'F')) //RIFF
		{
			cout << "DDT> wav_transcode unsupported input, no RIFF " << hex << (int)file[0] << " "<< (int)file[1] << " "<< (int)file[2] << " "<<(int)file[3] << dec << endl;
			return int_floatp();
		}


		if (  (file[8] != 'W') || (file[9] != 'A') || (file[10] != 'V') || (file[11] != 'E')) //WAVE
		{
			cout << "DDT> wav_transcode unsupported input, no WAVE" << endl;
			return int_floatp();
		}


		// Ok, file header is solid, now to check the fmt header

		if (  (file[12] != 'f') || (file[13] != 'm') || (file[14] != 't') || (file[15] != ' ')) //fmt
		{
			cout << "DDT> wav_transcode unsupported input, no fmt" << endl;
			return int_floatp();
		}

		if (  (file[16] != 0x10) || (file[17] != 0x00) || (file[18] != 0x00) || (file[19] != 0x00)) //0x00000010
		{
			cout << "DDT> wav_transcode unsupported input, wrong fmt length" << endl;
			return int_floatp();
		}

		if (  (file[20] != 0x01) || (file[21] != 0x00) )
		{
			cout << "DDT> wav_transcode unsupported input, flag not PCM" << endl;
			return int_floatp();
		}

		if ( (file[22] == 0x01) && (file[23] == 0x00))
		{
			//file is mono
			file_chans = 1;
		}
		else if ( (file[22] == 0x02) && (file[23] == 0x00))
		{
			//file is stereo
			file_chans = 2;
		}
		else
		{
			cout << "DDT> wav_transcode unsupported input, not mono not stereo" << endl;
			return int_floatp();
		}

		if (  (file[24] != 0x22) || (file[25] != 0x56) || (file[26] != 0x00) || (file[27] != 0x00))
		{
			cout << "DDT> wav_transcode unsupported input, sample rate not 22050 = 0x5622" << endl;
			return int_floatp();
		}

		if ( (file[34] == 0x08) && (file[35] == 0x00))
		{
			//file is 8 bits/sample
			file_bit_per_sample = 8;
		}
		else if ( (file[34] == 0x10) && (file[35] == 0x00))
		{
			//file is 16 bits/sample
			file_bit_per_sample = 16;
		}
		else
		{
			cout << "DDT> wav_transcode unsupported input, not 8 and not 16 bits/sample" << endl;
			return int_floatp();
		}

		if (  (file[36] != 'd') || (file[37] != 'a') || (file[38] != 't') || (file[39] != 'a')) //data
		{
			cout << "DDT> wav_transcode unsupported input, cant find data tag" << endl;
			return int_floatp();
		}

		int given_datablock_length = ddtsavegame::get_32bit_value_at(40, file,file_size);
		int expected_datablock_length = file_size - file_datablock_offset;
		file_datablock_length = ddtmath::smallest_int_of(given_datablock_length, expected_datablock_length);


		int_floatp out;

		if (file_chans == 1 && file_bit_per_sample == 16)
		{
			out = transcode_from_16bit_mono(file_size, file, file_datablock_offset, file_datablock_length);
			//cout << "16 mono" << endl;

			//show_16_bit_wave(out.c, out.i, 0);

		}
		else if (file_chans == 2 && file_bit_per_sample == 16)
		{
			out = transcode_from_16bit_stereo(file_size, file, file_datablock_offset, file_datablock_length);
			//cout << "16 stereo" << endl;

			//show_16_bit_wave(out.c, out.i, 5000);

		}

		else if (file_chans == 1 && file_bit_per_sample == 8)
		{
			out = transcode_from_8bit_mono(file_size, file, file_datablock_offset, file_datablock_length);
			//cout << "8 mono" << endl;


		}

		else if (file_chans == 2 && file_bit_per_sample == 8)
		{
			cout << "DDT> 8bit stereo sound detected, case not supported." << endl;
		}
		else
		{
			cout << "DDT> wav_transcode unsupported input, strange chan&bits combo" << endl;
		}



		delete[] file;

		return out;

	}


	int_floatp transcode_from_16bit_mono(int file_size, unsigned char* file, int datablock_offset, int datablock_length)
	{
		if ((file_size < 500) || (file_size < datablock_offset+datablock_length ))
		{
			cout << "transcode_from_16bit_mono bad call" << endl;
			return int_floatp();
		}

		//our mixer takes 16bit mono so we just need to strip the header
		int out_size = datablock_length/2; //because size in floats is half of size in u8
		float* out = new float[out_size];

		for ( int i = 0; i < out_size; i++)
		{

			out[i] = ddtsavegame::get_signed_16bit_value_at(datablock_offset + 2*i, file, file_size);
		}

		return int_floatp(out_size, out);

	}

	int_floatp transcode_from_16bit_stereo(int file_size, unsigned char* file, int datablock_offset, int datablock_length)
	{
		if ((file_size < 500) || (file_size < datablock_offset+datablock_length))
		{
			cout << "transcode_from_16bit_stereo bad call" << endl;
			return int_floatp();
		}

		if (! ddtmath::is_even_positive_int(datablock_length))
		{
			cout << "transcode_from_16bit_stereo bad datablock_length" << endl;
			return int_floatp();
		}

		//our mixer takes 16bit mono so we need to cram both chans into one
		int out_size = datablock_length/4;
		float* out = new float[out_size];


		for ( int i = 0; i < out_size; i++)
		{
			float a = ddtsavegame::get_signed_16bit_value_at(datablock_offset + 4*i, file, file_size);
			float b = ddtsavegame::get_signed_16bit_value_at(datablock_offset + 4*i +2, file, file_size);

			out[i] = 0.5*(a + b);

		}

		return int_floatp(out_size, out);
	}

	int_floatp transcode_from_8bit_mono(int file_size, unsigned char* file, int datablock_offset, int datablock_length)
	{
		if ((file_size < 500) || (file_size < datablock_offset+datablock_length))
		{
			cout << "transcode_from_16bit_stereo bad call" << endl;
			return int_floatp();
		}


		//our mixer takes 16bit mono so we need to upsample to signed 16 bit
		int out_size = datablock_length;
		float* out = new float[out_size];

		for ( int i = 0; i < out_size; i++)
		{
			uint8_t source = ddtsavegame::get_8bit_value_at(datablock_offset + i, file, file_size);
			out[i] = ddtmath::floor_byte_to_sound_float(source);
		}

		return int_floatp(out_size, out);

	}

	void show_16_bit_wave(float* file, int file_size, int mem_off)
	{

		cout << endl;

		for(int i = 0; ((i < 1000) && (i + mem_off < file_size)); i++)
		{
			int value = file[i+mem_off];


			if (value < 0)
			{
				int v = sqrt(-value) /4;

				for (int i = 0; i < 64 - v; i++)
				{
					cout << " " ;
				}
				for (int i = 0; i < v +1; i++)
				{
					cout << "|" ;
				}
				for (int i = 0; i < 64; i++)
				{
					cout << " " ;
				}
			}
			else
			{
				int v = sqrt(value) /4;

				for (int i = 0; i < 64; i++)
				{
					cout << " " ;
				}

				for (int i = 0; i < v +1; i++)
				{
					cout << "|" ;
				}

				for (int i = 0; i < 64 - v; i++)
				{
					cout << " " ;
				}
			}

			cout << hex << value  <<endl;

		}
	}

};

