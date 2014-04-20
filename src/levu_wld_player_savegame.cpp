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



#include "levu_mul_ui_elements.cpp"
using namespace std;



class player_savegame
{

	private:

	unsigned char* static_part;
	unsigned char* dungeon[LEVEL_COUNT];
	int dungeon_size[LEVEL_COUNT];

	public:


	player_savegame()
	{

		static_part = new unsigned char[ddtsavegame::static_size()];
		for (int i = 0; i <  ddtsavegame::static_size(); i++)
		{
			static_part[i] = 0;
		}

		for (int i = 0; i < LEVEL_COUNT; i++)
		{
			dungeon_size[i] = 0;
		}
	}

	void load_whole_savegame_distructive(unsigned char* in, int in_size)
	{
		set_static_part_nondistructive(in, in_size);

		for (int i = 0; i < LEVEL_COUNT; i++)
		{
			set_dungeon_from_file_nondistructive(in, in_size, i);
		}

		ddtutils::del_array(in, in_size);


	}


	void set_static_part_nondistructive(unsigned char* in, int in_size)
	{
		if (in_size < ddtsavegame::static_size())
		{
			cout << "DDT> player_savegame set_static_part error" << endl;
			return;
		}

		for (int i = 0; i <  ddtsavegame::static_size(); i++)
		{
			static_part[i] = in[i];
		}
	}

	void set_dungeon_from_file_nondistructive(unsigned char* in, int in_size, int dunno)
	{
		if (!dungeon_exists(dunno))
		{
			cout << "DDT> player_savegame set_dungeon_from_file error" << endl;
			return;
		}
		delete_dungeon(dunno);

		int offset = ddtsavegame::get_level_info_offset(dunno, in, in_size);
		int offset_end = ddtsavegame::get_level_info_offset_end(dunno, in, in_size);
		int dunsize = ddtsavegame::get_level_info_size(dunno, in, in_size);

		if (dunsize < 1) {return;}
		if (offset < ddtsavegame::static_size()) {return;}
		if (offset_end < offset)  {return;}


		dungeon[dunno] = new unsigned char[dunsize];

		for (int i = 0; i < dunsize; i++)
		{
			dungeon[dunno][i] = in[offset + i];
		}

		dungeon_size[dunno] = dunsize;
	}

	void set_dungeon_from_world_distructive(unsigned char* in, int in_size, int dunno)
	{
		if ( !dungeon_exists(dunno) || (in_size < 1) )
		{
			cout << "DDT> player_savegame set_dungeon_from_world error" << endl;
			return;
		}

		delete_dungeon(dunno);

		dungeon[dunno] = in;
		dungeon_size[dunno] = in_size;
	}

	void delete_dungeon(int no)
	{

		if (dungeon_has_size(no))
		{
			delete[] dungeon[no];
			dungeon_size[no] = 0;
		}

	}

	bool dungeon_exists(int no)
	{
		if ( (no < 0) || (no > LEVEL_COUNT -1)) {return false;}
		return true;
	}

	bool dungeon_has_size(int no)
	{
		if (!dungeon_exists(no)) {return false;}
		if (dungeon_size[no] < 1){return false;}
		return true;
	}

	int get_dungeon_size(int no)
	{
		if (!dungeon_exists(no)) {return 0;}
		return dungeon_size[no];
	}

	unsigned char* show_static_part()
	{
		return static_part;
	}
	unsigned char* show_dungeon(int no)
	{
		if (!dungeon_has_size(no)) {return NULL;}
		return dungeon[no];
	}










};
