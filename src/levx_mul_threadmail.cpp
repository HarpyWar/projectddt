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



#include "levx_mul_global_statics.cpp"
using namespace std;

#define SAVEBUFF_CHUNK_SIZE 512

class savebuf_part
{
	public:
	unsigned char part[SAVEBUFF_CHUNK_SIZE];
	savebuf_part* newer;
};


class savebuff
{
	private:
	int parts_stored;
	savebuf_part* first_added;
	savebuf_part* last_added;

	int current_write_used;
	savebuf_part* current_write;


	public:

	savebuff()
	{
		parts_stored = 0;
		current_write_used = 0;
		current_write = new savebuf_part;
	}

	void add(unsigned char in)
	{
		push_if_needed();
		(*current_write).part[current_write_used] = in;
		current_write_used ++;
	}

	void add_nondestuctive(unsigned char* in, int in_size)
	{
		for(int i = 0; i < in_size; i++)
		{
			add(in[i]);
		}
	}

	void add_destuctive(unsigned char* in, int in_size)
	{
		add_nondestuctive(in, in_size);

		ddtutils::del_array(in, in_size);
	}


	int get_size()
	{
		return parts_stored*SAVEBUFF_CHUNK_SIZE + current_write_used;

	}

	unsigned char* give()
	{
		int size = get_size();

		if (size < 1) {return NULL;}


		unsigned char* out = new unsigned char[size];

		int out_pointer = 0;

		while (parts_stored > 0)
		{
			savebuf_part* prt = pop();

			for (int i = 0; i < SAVEBUFF_CHUNK_SIZE; i++)
			{
				out[out_pointer] = (*prt).part[i];
				out_pointer++;
			}
			delete[] prt;
		}
		for (int i = 0; i < current_write_used; i++)
		{
			out[out_pointer] = (*current_write).part[i];
			out_pointer++;
		}

		delete[] current_write;

		return out;



	}

	private:

	void push_if_needed()
	{
		if (current_write_used < SAVEBUFF_CHUNK_SIZE ) {return;}

		if (parts_stored == 0)
		{
			first_added = current_write;
			last_added = current_write;
		}
		else
		{
			(*last_added).newer = current_write;
			last_added = current_write;
		}

		parts_stored++;
		current_write = new savebuf_part;
		current_write_used = 0;
	}

	savebuf_part* pop()
	{
		if (parts_stored == 0)
		{
			cout << "DDT> savebuff overpop" << endl;
			return new savebuf_part;
		}
		else if (parts_stored == 1)
		{
			parts_stored = 0;
			return first_added;
		}
		else
		{
			savebuf_part* out = first_added;
			first_added = (*out).newer;
			parts_stored--;
			return out;
		}
	}

};







class mail
{
	public:

	mail* newer;

	int command;
	int pakno;
	int keepno;
	int allog;
	int x_size;
	int y_size;
	int palno;
	int frames;
	int alpha;
	int chunkyness;
	int x_move;
	int y_move;
	int valuemap_ref;

	string argument;

	int size_filea;
	unsigned char* filea;

	int size_fileb;
	unsigned char* fileb;

	int size_tchunk;
	texchunk* tchunk;

	int size_floatarr;
	float* floatarr;

	mail()
	{
		command = THREAD_VOID_COMMAND;
	}

	mail(int comm)
	{
		command = comm;
	}

	mail(int comm, string argu)
	{
		command = comm;
		argument = argu;
	}

	// for save game listing
	mail(int comm, int fra, string argu)
	{
		command = comm;
		frames = fra;
		argument = argu;
	}

	// for requesting a graphcis transcode
	mail(int com, int pak, int ke, int alg, int x, int y, int pal, int fr, int al, int ch, int xm, int ym, int siza, unsigned char* fla, int sizb, unsigned char* flb)
	{
		command = com;
		pakno = pak;
		keepno = ke;
		allog = alg;
		x_size = x;
		y_size = y;
		palno = pal;
		frames = fr;
		alpha = al;
		chunkyness = ch;
		x_move = xm;
		y_move = ym;
		size_filea = siza;
		filea = fla;
		size_fileb = sizb;
		fileb = flb;
		valuemap_ref = -1;
	}

	// for requesting a graphcis transcode
	mail(int com, int pak, int ke, int alg, int x, int y, int pal, int fr, int al, int ch, int xm, int ym, int siza, unsigned char* fla, int sizb, unsigned char* flb, int map)
	{
		command = com;
		pakno = pak;
		keepno = ke;
		allog = alg;
		x_size = x;
		y_size = y;
		palno = pal;
		frames = fr;
		alpha = al;
		chunkyness = ch;
		x_move = xm;
		y_move = ym;
		size_filea = siza;
		filea = fla;
		size_fileb = sizb;
		fileb = flb;
		valuemap_ref = map;
	}

	// for loading transcoded graphcis into their slot
	mail(int com, int pak, int ke, texchunk* tchu, int tchu_size)
	{
		pakno = pak;
		command = com;
		keepno = ke;
		tchunk = tchu;
		size_tchunk = tchu_size;
	}

	// for loading audio
	mail(int com, int ke, unsigned char* file, int fsize)
	{
		command = com;
		keepno = ke;
		size_filea = fsize;
		filea = file;
	}

	// for loading world stuff
	mail(int com, unsigned char* file, int fsize)
	{
		command = com;
		size_filea = fsize;
		filea = file;
	}

	// for loading levels
	mail(int com, int x, int y, unsigned char* file, int fsize)
	{
		command = com;
		x_size = x;
		y_size = y;
		filea = file;
		size_filea = fsize;
	}

	mail(int com, int pak, int keep, float* fa, int fa_size)
	{
		command = com;
		pakno = pak;
		keepno = keep;

		size_floatarr = fa_size;
		floatarr = fa;
	}




	mail(int com, int ke)
	{
		command = com;
		keepno = ke;
	}


	mail(int com, int ke, int alg)
	{
		command = com;
		keepno = ke;
		allog = alg;

	}
};



class mailbox
{
	private:
	mail* first_added;
	mail* last_added;
	int count;

	public:
	volatile bool have_mail;

	mailbox()
	{
		 count = 0;
		 have_mail = false;
	}

	 // add a member to our double-linked list
	 void push(mail* in)
	 {
		if (count == 0) // we dont have a member yet
		{
			first_added = in; last_added = in; // hook up the handeles

		}
		else // we already have a member
		{
			//doing the circular list insertion dance
			(*last_added).newer = in;
			last_added = in;
		}

		count++;
		have_mail = true;
	 }

	 mail* pop()
	 {

		 if (count == 0)
		 {
			 return new mail();
		 }
		 else if (count == 1)
		 {
			 have_mail = false;
			 count = 0;
			 return  first_added;
		 }
		 else
		 {
			 mail* out =  first_added;
			 first_added = (*first_added).newer;

			 count --;
			 return out;
		 }
	 }


};






