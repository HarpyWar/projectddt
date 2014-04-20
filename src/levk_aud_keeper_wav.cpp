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




#include "levk_tsc_texmaker_pcx.cpp"
using namespace std;


class audio_pak_keeper
{
	public:

	int_floatp music;
	int_floatp story;

	int_floatp* sfx[PAK_COUNT];
	int pak_size[PAK_COUNT];




	audio_pak_keeper()
	{
		for (int i = 0; i < PAK_COUNT; i++)
		{
			pak_size[i] = 0;
		}
	}


	void init_pak(int pak, int slotcount)
	{
		if ( !(exists(pak))) { return; }
		kill_pak(pak);
		if (slotcount < 1) {return;}

		sfx[pak] = new int_floatp[slotcount];
		pak_size[pak] = slotcount;
	}


	void pak_load(int pak, int slot, float* file, int fsize)
	{
		if (fsize < 60)
		{
			cout << "DDT> audiomanager load file too short" << endl;
			return;
		}

		if (!exists(pak, slot))
		{
			cout << "DDT> audio load bad call" << endl;
			return;
		}

		kill_slot(pak, slot);
		sfx[pak][slot].f = file;
		sfx[pak][slot].i = fsize;
	}


	void music_load(float* file, int fsize)
	{
		kill_music();
		music.f = file;
		music.i = fsize;
	}

	void story_load(float* file, int fsize)
	{
		kill_story();
		story.f = file;
		story.i = fsize;
	}



	void kill_pak(int pak)
	{
		if ( !(exists(pak))) { return; }
		if ( pak_size[pak] < 1) { return; }


		for ( int i = 0; i < pak_size[pak]; i++)
		{
			kill_slot(pak, i);
		}
		delete[] sfx[pak];
		pak_size[pak] = 0;
	}

	void kill_slot(int pak, int slot)
	{
		if (slot_size(pak, slot) > 0)
		{
			delete[] sfx[pak][slot].f;
			sfx[pak][slot].i = 0;
		}
	}

	void kill_story()
	{
		if (story.i > 0)
		{
			delete[] story.f;
			story.i = 0;
		}
	}

	void kill_music()
	{
		if (music.i > 0)
		{
			delete[] music.f;
			music.i = 0;
		}
	}

	bool exists(int pak)
	{
		if ( pak < 0 || pak > PAK_COUNT -1) { return false; }
		return true;
	}

	bool exists(int pak, int slot)
	{
		if ( !(exists(pak))) { return false;}
		if (slot < 0) { return false;}
		if (slot > pak_size[pak] -1){ return false;}
		return true;
	}

	int slot_size(int pak, int slot)
	{
		if (!exists(pak, slot)) {return 0;}
		return sfx[pak][slot].i;

	}






};
