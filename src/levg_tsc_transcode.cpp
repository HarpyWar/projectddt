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




#include "levg_wld_world.cpp"

using namespace std;

class transcoder
{
private:

	utils util;
	celmaker celmake;
	pcxmaker pcxmake;
	mapmaker mapmake;
	wavemaker wavmake;

	globals* global;
	mail* post;



	public:

	transcoder()
	{

	}


	void in_thread_init(globals* glob )
	{
		global = glob;
		celmake.init(glob);
		pcxmake.init(glob);

	}


	void transcode_grfx(mail* in )
	{
		int_texchunkp out;

		if ( ((*in).allog == TOWN_CEL) || ((*in).allog == INDEXED_CEL) || ((*in).allog == INDEXED_CLT) || ((*in).allog == OBJCURS) )
		{
			if (! (*global).palkeep.exists((*in).palno))
			{
				cout << "DDT> illegal pal number detected by transcoder" << endl;
				return;
			}
			out = celmake.indexed_bulk((*in).x_size, (*in).y_size, (*in).filea, (*in).size_filea, (*global).palkeep.pal[(*in).palno], (*in).allog, (*in).chunkyness, (*in).x_move, (*in).y_move, (*in).valuemap_ref);
		}
		else if ( ((*in).allog == DOUBLE_INDEXED_CEL) || ((*in).allog == DOUBLE_INDEXED_CLT) )
		{
			if (! (*global).palkeep.exists((*in).palno))
			{
				cout << "DDT> illegal pal number detected by transcoder" << endl;
				return;
			}
			out = celmake.double_indexed_bulk((*in).x_size, (*in).y_size, (*in).filea, (*in).size_filea, (*global).palkeep.pal[(*in).palno], (*in).allog, (*in).chunkyness, (*in).x_move, (*in).y_move, (*in).valuemap_ref);
		}
		else if ( ((*in).allog == UIFUSE_ORBS) || ((*in).allog == UIFUSE_STASH) )
		{
			if (! (*global).palkeep.exists((*in).palno))
			{
				cout << "DDT> illegal pal number detected by transcoder" << endl;
				return;
			}
			out = celmake.uifuse((*in).allog, (*in).filea, (*in).size_filea, (*in).fileb, (*in).size_fileb, (*global).palkeep.pal[(*in).palno] );
		}

		else if ( ((*in).allog == PCX) )
		{
			out = pcxmake.pcx_bulk((*in).frames, (*in).filea, (*in).size_filea, (*in).alpha, (*in).chunkyness, (*in).x_move, (*in).y_move, (*global).display_gamma, (*in).valuemap_ref);
		}

		else if ( ((*in).allog == MAP) )
		{
			out = mapmake.map( (*in).filea,   (*in).x_size, (*in).y_size, (*in).x_move, (*in).y_move);
		}

		else
		{
			cout << "DDT> transcode_grfx(transcode_request in ) recieved bad alog" << (*in).allog << endl;
			return;
		}


		post = new mail(DISPLAY_LOAD_CHUNKS, (*in).pakno, (*in).keepno, out.chunk, out.size );   // mail(int com, int ke, texchunk* tchu, int tchu_size)


		(*global).threadpush_display(post);


	}

	void transcode_audio(mail* in )
	{
		int pak = (*in).x_size;
		int keepno = (*in).y_size;
		unsigned char* file = (*in).filea;
		int file_size = (*in).size_filea;

		int_floatp out = wavmake.transcode(file_size, file);

		if (out.i > 0)
		{
			post = new mail(AUDIO_LOAD, pak, keepno, out.f, out.i);
			(*global).threadpush_audio(post);
		}
		else
		{
			cout << "DDT> transcode_audio has a void result" << endl;
		}




	}

};

