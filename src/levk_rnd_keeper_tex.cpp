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




#include "levk_wld_class_loader.cpp"
using namespace std;


class tex_pak_keeper
{
	private:

	float display_scale;
	int display_w;
	int display_h;

	int pak_size[PAK_COUNT];
	int* pak_member_size[PAK_COUNT];

	texchunk** tex[PAK_COUNT]; // Our double array of textures

	public:

	tex_pak_keeper()
	{
		display_scale = 1.0;
		display_w = ORIGINAL_WIDTH;
		display_h = ORIGINAL_HEIGHT;

		for (int i = 0; i < PAK_COUNT; i++)
		{
			pak_size[i] = 0;
		}
	}

	void set_display_var(float scale, int dis_w, int dis_h)
	{
		if (dis_w > 0 && dis_h > 0 && scale > 0)
		{
			display_scale = scale;
			display_w = dis_w;
			display_h = dis_h;
		}
	}

	void init_pak(int pakno, int member_size)
	{
		if (pakno < 0 || pakno > PAK_COUNT -1 )
		{
			cout << "DDT> texkeeper illegal pak init" << endl;
			return;
		}

		kill_pak(pakno);

		if (member_size < 1) {return;}


		pak_size[pakno] = member_size;

		pak_member_size[pakno] = new int[member_size];
		tex[pakno] = new texchunk*[member_size];

		for (int i = 0; i < member_size; i++)
		{
			pak_member_size[pakno][i] = 0;
		}

		//cout << " display pak init " << pakno << " " << member_size << endl;

	}

	void set_pak_member(int memberno, texchunk* in, int chunk_count)
	{
		set_pak_member(PAK_DEFAULT, memberno, in, chunk_count);
	}

	void set_pak_member(int pakno, int memberno, texchunk* in, int chunk_count)
	{
		if (pakno < 0 || pakno > PAK_COUNT -1)
		{
			cout << "DDT> texkeeper illegal set pakno" << endl;
			return;
		}
		if (memberno < 0 || memberno > pak_size[pakno] -1)
		{
			cout << "DDT> texkeeper illegal set meberno " << pakno << " " << memberno << endl;
			return;
		}

		if (chunk_count < 0)
		{
			cout << "DDT> texkeeper illegal set chunkno" << endl;
			return;
		}

		kill_pak_member(pakno, memberno);

		if (chunk_count == 0)
		{
			return;
		}



		pak_member_size[pakno][memberno] = chunk_count;
		tex[pakno][memberno] = in;

		for (int i = 0 ; i < chunk_count; i++)
		{
			(tex[pakno][memberno][i]).make_renderable();
		}


	}

	void kill_pak_member(int memberno)
	{
		kill_pak_member(PAK_DEFAULT, memberno);
	}

	void kill_pak_member(int pakno, int memberno)
	{
		if (pakno < 0 || pakno > PAK_COUNT -1)
		{
			cout << "DDT> texkeeper illegal kill_pak_member pakno" << endl;
			return;
		}
		if (memberno < 0 || memberno > pak_size[pakno] -1)
		{
			cout << "DDT> texkeeper illegal kill_pak_member memberno" << endl;
			return;
		}

		if ( pak_member_size[pakno][memberno] < 1)
		{
			return;
		}

		for (int i = 0; i < pak_member_size[pakno][memberno]; i++)
		{
			(tex[pakno][memberno][i]).kill();
		}
		delete[] tex[pakno][memberno];

		pak_member_size[pakno][memberno] = 0;

	}

	void kill_pak(int pakno)
	{
		if (pakno < 0 || pakno > PAK_COUNT -1 )
		{
			cout << "DDT> texkeeper illegal pak init" << endl;
			return;
		}

		if (pak_size[pakno] < 1)
		{
			return;
		}

		for (int i = 0; i < pak_size[pakno]; i++)
		{
			kill_pak_member(pakno, i);
		}

		delete[] tex[pakno];
		delete[] pak_member_size[pakno];
		pak_size[pakno] = 0;
	}



	int texcount_at(int member)
	{
		return texcount_at(PAK_DEFAULT, member);
	}

	int texcount_at(int pak, int member)
	{
		if (pak < 0 || pak > PAK_COUNT -1)
		{
			return 0;
		}
		if (member < 0 || member > pak_size[pak] -1)
		{
			return 0;
		}

		return pak_member_size[pak][member];


	}

	bool exists(int pak, int member, int frame)
	{
		if (pak < 0 || pak > PAK_COUNT -1) {return false;}
		if (member < 0 || member > pak_size[pak] -1){return false;}
		if (frame < 0 || frame > pak_member_size[pak][member] -1){return false;}

		return true;
	}

	void render(int memberno, int submember, float x_off, float y_off, float r, float g, float b, float a)
	{
		render(PAK_DEFAULT, memberno, submember, x_off, y_off, r, g, b, a);
	}


	void render(int pakno, int memberno, int submember, float x_off, float y_off, float r, float g, float b, float a)
	{

		if (!exists(pakno, memberno, submember)) {return;}

		tex[pakno][memberno][submember].render(
				display_scale,  x_off, y_off, r, g, b, a, display_w, display_h);

	}

	void render_highlight(int hi_code, int pakno, int memberno, int submember, float x_off, float y_off)
	{

		if (!exists(pakno, memberno, submember)) {return;}

		tex[pakno][memberno][submember].render_highlight(
				hi_code, display_scale,  x_off, y_off, display_w, display_h);

	}



};
