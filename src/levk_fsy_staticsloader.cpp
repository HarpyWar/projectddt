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




#include "levk_aud_keeper_wav.cpp"
using namespace std;



class staticsloader
{
	globals* global;
	utils util;


	public:

	void init(globals* glob)
	{
		global = glob;
	}


	void load_monster(int monref, unsigned char* block, int block_size)
	{
		if ( block_size < 10)
		{
			cout << "DDT> load_monster block_size too small" << endl;
			return;
		}

		if (!(*global).monsters.exists(monref))
		{
			cout << "DDT> load_monster illegal monref" << endl;
			return;
		}



		int block_point = -1;

		while (block_point < block_size - 10)
		{
			block_point++;

			if ( !(  block[block_point] == '(') )
			{
				// nothing
			}

			else if (
					block[block_point + 1] == 'n' &&
					block[block_point + 2] == 'a' &&
					block[block_point + 3] == 'm' &&
					block[block_point + 4] == 'e' &&
					block[block_point + 5] == ')' )
			{
				string mon_name = util.get_argument_at(block_point+7, block, block_size );
				(*global).monsters.mon[monref].name.set(mon_name);
			}

			else if (
					block[block_point + 1] == 'b' &&
					block[block_point + 2] == 'l' &&
					block[block_point + 3] == 'o' &&
					block[block_point + 4] == 'b' &&
					block[block_point + 5] == '_' &&
					block[block_point + 6] == 'n' &&
					block[block_point + 7] == 'a' &&
					block[block_point + 8] == 'm' &&
					block[block_point + 9] == 'e' &&
					block[block_point +10] == ')' )
			{
				int name_no = util.get_int_at(block_point+12, block,  block_size);
				string out = util.get_argument_at(block_point+18, block, block_size ); //read the font options
				out.append((*global).binblob.get_monster_name(name_no));
				(*global).monsters.mon[monref].name.set(out);
			}

			else if (
					block[block_point + 1] == 'p' &&
					block[block_point + 2] == 'a' &&
					block[block_point + 3] == 'k' &&
					block[block_point + 4] == 'r' &&
					block[block_point + 5] == 'e' &&
					block[block_point + 6] == 'f' &&
					block[block_point + 7] == ')' )
			{
				(*global).monsters.mon[monref].pakref_vid = util.get_int_at(block_point+9, block,  block_size);
				(*global).monsters.mon[monref].pakref_aud = util.get_int_at(block_point+15, block,  block_size);
			}

			else if (
					block[block_point + 1] == 'c' &&
					block[block_point + 2] == 'l' &&
					block[block_point + 3] == 'e' &&
					block[block_point + 4] == 'a' &&
					block[block_point + 5] == 'n' &&
					block[block_point + 6] == '_' &&
					block[block_point + 7] == 'o' &&
					block[block_point + 8] == 'w' &&
					block[block_point + 9] == 'n' &&
					block[block_point +10] == '_' &&
					block[block_point +11] == 'p' &&
					block[block_point +12] == 'a' &&
					block[block_point +13] == 'k' &&
					block[block_point +14] == 's' &&
					block[block_point +15] == ')' )
			{
				(*global).monsters.mon[monref].clean_own_vid_pak = (util.get_int_at(block_point+17, block,  block_size) > 0);
				(*global).monsters.mon[monref].clean_own_aud_pak = (util.get_int_at(block_point+23, block,  block_size) > 0);
			}

			else if (
					block[block_point + 1] == 'a' &&
					block[block_point + 2] == 'n' &&
					block[block_point + 3] == 'i' &&
					block[block_point + 4] == 'm' &&
					block[block_point + 5] == 'a' &&
					block[block_point + 6] == 't' &&
					block[block_point + 7] == 'i' &&
					block[block_point + 8] == 'o' &&
					block[block_point + 9] == 'n' &&
					block[block_point +10] == ')' )
			{
				(*global).monsters.mon[monref].ani_stand  = util.get_int_at(block_point + 12, block, block_size);
				(*global).monsters.mon[monref].ani_walk   = util.get_int_at(block_point + 18, block, block_size);
				(*global).monsters.mon[monref].ani_attack = util.get_int_at(block_point + 24, block, block_size);
				(*global).monsters.mon[monref].ani_firec  = util.get_int_at(block_point + 30, block, block_size);
				(*global).monsters.mon[monref].ani_lightc = util.get_int_at(block_point + 36, block, block_size);
				(*global).monsters.mon[monref].ani_bonec  = util.get_int_at(block_point + 42, block, block_size);
				(*global).monsters.mon[monref].ani_hitrec = util.get_int_at(block_point + 48, block, block_size);
				(*global).monsters.mon[monref].ani_death  = util.get_int_at(block_point + 54, block, block_size);
			}

			else if (
					block[block_point + 1] == 'a' &&
					block[block_point + 2] == 'n' &&
					block[block_point + 3] == 'i' &&
					block[block_point + 4] == '_' &&
					block[block_point + 5] == 'd' &&
					block[block_point + 6] == 'i' &&
					block[block_point + 7] == 'r' &&
					block[block_point + 8] == 'e' &&
					block[block_point + 9] == 'c' &&
					block[block_point +10] == 't' &&
					block[block_point +11] == 'i' &&
					block[block_point +12] == 'o' &&
					block[block_point +13] == 'n' &&
					block[block_point +14] == ')' )
			{
				string direct = util.get_argument_at(block_point+16, block, block_size );
				bool dir = ( !(direct == "false"));
				(*global).monsters.mon[monref].ani_direction = dir;
			}

			else if (
					block[block_point + 1] == 'h' &&
					block[block_point + 2] == 'e' &&
					block[block_point + 3] == 'i' &&
					block[block_point + 4] == 'g' &&
					block[block_point + 5] == 'h' &&
					block[block_point + 6] == 't' &&
					block[block_point + 7] == ')' )
			{

				(*global).monsters.mon[monref].selection_height  = util.get_int_at(block_point + 9, block, block_size);
			}
			else if (
					block[block_point + 1] == 's' &&
					block[block_point + 2] == 't' &&
					block[block_point + 3] == 'e' &&
					block[block_point + 4] == 'p' &&
					block[block_point + 5] == 's' &&
					block[block_point + 6] == 'o' &&
					block[block_point + 7] == 'u' &&
					block[block_point + 8] == 'n' &&
					block[block_point + 9] == 'd' &&
					block[block_point +10] == 's' &&
					block[block_point +11] == ')' )
			{
				(*global).monsters.mon[monref].stepsound_min  = util.get_int_at(block_point + 13, block, block_size);
				(*global).monsters.mon[monref].stepsound_max  = util.get_int_at(block_point + 19, block, block_size);
			}
			else if (
					block[block_point + 1] == 'i' &&
					block[block_point + 2] == 'n' &&
					block[block_point + 3] == 't' &&
					block[block_point + 4] == 'e' &&
					block[block_point + 5] == 'r' &&
					block[block_point + 6] == 'a' &&
					block[block_point + 7] == 'c' &&
					block[block_point + 8] == 't' &&
					block[block_point + 9] == 'i' &&
					block[block_point +10] == 'o' &&
					block[block_point +11] == 'n' &&
					block[block_point +12] == '_' &&
					block[block_point +13] == 'r' &&
					block[block_point +14] == 'e' &&
					block[block_point +15] == 'f' &&
					block[block_point +16] == ')' )
			{
				(*global).monsters.mon[monref].interaction_ref  = util.get_int_at(block_point + 18, block, block_size);
			}

			else if (
					block[block_point + 1] == 's' &&
					block[block_point + 2] == 'a' &&
					block[block_point + 3] == 'v' &&
					block[block_point + 4] == 'a' &&
					block[block_point + 5] == 'b' &&
					block[block_point + 6] == 'l' &&
					block[block_point + 7] == 'e' &&
					block[block_point + 8] == ')' )
			{
				(*global).monsters.mon[monref].is_savable = (util.get_int_at(block_point + 10, block, block_size) > 0);
			}

			else if (
					block[block_point + 1] == 'l' &&
					block[block_point + 2] == 'o' &&
					block[block_point + 3] == 'a' &&
					block[block_point + 4] == 'd' &&
					block[block_point + 5] == 'm' &&
					block[block_point + 6] == 'e' &&
					block[block_point + 7] == ')' )
			{


				int buff_in_pointer = block_point + 8;
				savebuff buff;

				while ((buff_in_pointer < block_size -1) && !(block[buff_in_pointer] == '('))
				{
					buff.add(block[buff_in_pointer]);
					buff_in_pointer++;
				}

				int loadme_sz = buff.get_size();
				unsigned char* loadme_c = buff.give();

				ddtutils::del_array((*global).monsters.mon[monref].loadme, (*global).monsters.mon[monref].loadme_size);

				(*global).monsters.mon[monref].loadme_size = loadme_sz;
				(*global).monsters.mon[monref].loadme = loadme_c;

				block_point = buff_in_pointer;


			}
			else if (
					block[block_point + 1] == 'b' &&
					block[block_point + 2] == 'r' &&
					block[block_point + 3] == 'a' &&
					block[block_point + 4] == 'i' &&
					block[block_point + 5] == 'n' &&
					block[block_point + 6] == 's' &&
					block[block_point + 7] == ')' )
			{
				(*global).monsters.mon[monref].brains = util.get_int_at(block_point + 9, block, block_size);
			}
		}



		delete[] block;
	}

	void load_mechanic(int ref, unsigned char* block, int block_size)
	{
		if ( block_size < 10)
		{
			cout << "DDT> load_mechanic block_size too small" << endl;
			return;
		}

		if ( !(*global).mechanics.exists(ref) )
		{
			cout << "DDT> load_mechanic illegal ref" << endl;
			return;
		}



		int block_point = -1;

		while (block_point < block_size - 10)
		{
			block_point++;

			if ( !(  block[block_point] == '(') )
			{
				// nothing
			}

			else if (
					block[block_point + 1] == 'n' &&
					block[block_point + 2] == 'a' &&
					block[block_point + 3] == 'm' &&
					block[block_point + 4] == 'e' &&
					block[block_point + 5] == ')' )
			{
				string mech_name = util.get_argument_at(block_point+7, block, block_size );
				(*global).mechanics.mech[ref].name.set(mech_name);
			}

			else if (
					block[block_point + 1] == 'b' &&
					block[block_point + 2] == 'l' &&
					block[block_point + 3] == 'o' &&
					block[block_point + 4] == 'b' &&
					block[block_point + 5] == '_' &&
					block[block_point + 6] == 'n' &&
					block[block_point + 7] == 'a' &&
					block[block_point + 8] == 'm' &&
					block[block_point + 9] == 'e' &&
					block[block_point +10] == '_' &&
					block[block_point +11] == 'a' &&
					block[block_point +12] == 'p' &&
					block[block_point +13] == ')' )
			{
				int name_no = util.get_int_at(block_point+15, block,  block_size);
				string appender = (*global).binblob.get_mech_name(name_no);
				string name = (*global).mechanics.mech[ref].name.get();
				name.append(appender);
				(*global).mechanics.mech[ref].name.set(name);
			}

			else if (
					block[block_point + 1] == 'n' &&
					block[block_point + 2] == 'a' &&
					block[block_point + 3] == 'm' &&
					block[block_point + 4] == 'e' &&
					block[block_point + 5] == '_' &&
					block[block_point + 6] == 'a' &&
					block[block_point + 7] == 'p' &&
					block[block_point + 8] == ')' )
			{
				string appender = util.get_argument_at(block_point+10, block, block_size );
				string name = (*global).mechanics.mech[ref].name.get();
				name.append(appender);
				(*global).mechanics.mech[ref].name.set(name);
			}


			else if (
					block[block_point + 1] == 'l' &&
					block[block_point + 2] == 'o' &&
					block[block_point + 3] == 'a' &&
					block[block_point + 4] == 'd' &&
					block[block_point + 5] == 'r' &&
					block[block_point + 6] == 'e' &&
					block[block_point + 7] == 'f' &&
					block[block_point + 8] == ')' )
			{
				string lref = util.get_argument_at(block_point+10, block, block_size );
				(*global).mechanics.mech[ref].loadref.set(lref);
			}

			else if (
					block[block_point + 1] == 'p' &&
					block[block_point + 2] == 'a' &&
					block[block_point + 3] == 'k' &&
					block[block_point + 4] == 'r' &&
					block[block_point + 5] == 'e' &&
					block[block_point + 6] == 'f' &&
					block[block_point + 7] == ')' )
			{
				(*global).mechanics.mech[ref].pakref_vid = util.get_int_at(block_point+9, block,  block_size);
				(*global).mechanics.mech[ref].pakref_aud = util.get_int_at(block_point+15, block,  block_size);
			}

			else if (
					block[block_point + 1] == 'c' &&
					block[block_point + 2] == 'l' &&
					block[block_point + 3] == 'e' &&
					block[block_point + 4] == 'a' &&
					block[block_point + 5] == 'n' &&
					block[block_point + 6] == '_' &&
					block[block_point + 7] == 'o' &&
					block[block_point + 8] == 'w' &&
					block[block_point + 9] == 'n' &&
					block[block_point +10] == '_' &&
					block[block_point +11] == 'p' &&
					block[block_point +12] == 'a' &&
					block[block_point +13] == 'k' &&
					block[block_point +14] == 's' &&
					block[block_point +15] == ')' )
			{
				(*global).mechanics.mech[ref].clean_own_vid_pak = (util.get_int_at(block_point+17, block,  block_size) > 0);
				(*global).mechanics.mech[ref].clean_own_aud_pak = (util.get_int_at(block_point+23, block,  block_size) > 0);
			}

			else if (
					block[block_point + 1] == 'o' &&
					block[block_point + 2] == 'p' &&
					block[block_point + 3] == 'e' &&
					block[block_point + 4] == 'n' &&
					block[block_point + 5] == '_' &&
					block[block_point + 6] == 'c' &&
					block[block_point + 7] == 'l' &&
					block[block_point + 8] == 'o' &&
					block[block_point + 9] == 's' &&
					block[block_point +10] == 'e' &&
					block[block_point +11] == 'd' &&
					block[block_point +12] == '_' &&
					block[block_point +13] == 'g' &&
					block[block_point +14] == 'r' &&
					block[block_point +15] == 'f' &&
					block[block_point +16] == 'x' &&
					block[block_point +17] == ')' )
			{
				(*global).mechanics.mech[ref].open_grfx_gr = util.get_int_at(block_point+19, block,  block_size);
				(*global).mechanics.mech[ref].open_grfx_sub = util.get_int_at(block_point+25, block,  block_size);
				(*global).mechanics.mech[ref].closed_grfx_gr = util.get_int_at(block_point+31, block,  block_size);
				(*global).mechanics.mech[ref].closed_grfx_sub = util.get_int_at(block_point+37, block,  block_size);
			}

			else if (
					block[block_point + 1] == 'h' &&
					block[block_point + 2] == 'e' &&
					block[block_point + 3] == 'i' &&
					block[block_point + 4] == 'g' &&
					block[block_point + 5] == 'h' &&
					block[block_point + 6] == 't' &&
					block[block_point + 7] == ')' )
			{
				(*global).mechanics.mech[ref].selection_height = util.get_int_at(block_point+9, block,  block_size);
			}
			else if (
					block[block_point + 1] == 'r' &&
					block[block_point + 2] == 'e' &&
					block[block_point + 3] == 'f' &&
					block[block_point + 4] == '_' &&
					block[block_point + 5] == 'o' &&
					block[block_point + 6] == 't' &&
					block[block_point + 7] == 'h' &&
					block[block_point + 8] == 'e' &&
					block[block_point + 9] == 'r' &&
					block[block_point +10] == ')' )
			{
				(*global).mechanics.mech[ref].other_mech_ref = util.get_int_at(block_point+12, block,  block_size);
			}
			else if (
					block[block_point + 1] == 'd' &&
					block[block_point + 2] == 'u' &&
					block[block_point + 3] == 'n' &&
					block[block_point + 4] == 'g' &&
					block[block_point + 5] == 'e' &&
					block[block_point + 6] == 'o' &&
					block[block_point + 7] == 'n' &&
					block[block_point + 8] == '_' &&
					block[block_point + 9] == 'r' &&
					block[block_point +10] == 'e' &&
					block[block_point +11] == 'f' &&
					block[block_point +12] == ')' )
			{
				(*global).mechanics.mech[ref].dungeon_ref = util.get_int_at(block_point+14, block,  block_size);
			}

			else if (
					block[block_point + 1] == 'i' &&
					block[block_point + 2] == 'n' &&
					block[block_point + 3] == 't' &&
					block[block_point + 4] == 'e' &&
					block[block_point + 5] == 'r' &&
					block[block_point + 6] == 'a' &&
					block[block_point + 7] == 'c' &&
					block[block_point + 8] == 't' &&
					block[block_point + 9] == 'i' &&
					block[block_point +10] == 'o' &&
					block[block_point +11] == 'n' &&
					block[block_point +12] == '_' &&
					block[block_point +13] == 'r' &&
					block[block_point +14] == 'e' &&
					block[block_point +15] == 'f' &&
					block[block_point +16] == ')' )
			{
				(*global).mechanics.mech[ref].interaction_ref  = util.get_int_at(block_point + 18, block, block_size);
			}

			else if (
					block[block_point + 1] == 's' &&
					block[block_point + 2] == 'a' &&
					block[block_point + 3] == 'v' &&
					block[block_point + 4] == 'a' &&
					block[block_point + 5] == 'b' &&
					block[block_point + 6] == 'l' &&
					block[block_point + 7] == 'e' &&
					block[block_point + 8] == ')' )
			{
				(*global).mechanics.mech[ref].is_savable = (util.get_int_at(block_point + 10, block, block_size) > 0);
			}

			else if (
					block[block_point + 1] == 'l' &&
					block[block_point + 2] == 'o' &&
					block[block_point + 3] == 'a' &&
					block[block_point + 4] == 'd' &&
					block[block_point + 5] == 'm' &&
					block[block_point + 6] == 'e' &&
					block[block_point + 7] == ')' )
			{
				int buff_in_pointer = block_point + 8;
				savebuff buff;

				while ((buff_in_pointer < block_size -1) && !(block[buff_in_pointer] == '('))
				{
					buff.add(block[buff_in_pointer]);
					buff_in_pointer++;
				}

				int loadme_sz = buff.get_size();
				unsigned char* loadme_c = buff.give();

				ddtutils::del_array((*global).mechanics.mech[ref].loadme,(*global).mechanics.mech[ref].loadme_size );

				(*global).mechanics.mech[ref].loadme_size = loadme_sz;
				(*global).mechanics.mech[ref].loadme = loadme_c;

				block_point = buff_in_pointer;
			}


		}



		delete[] block;
	}

	void load_dunlook(int ref, unsigned char* block, int block_size)
	{
		if ( block_size < 10)
		{
			cout << "DDT> load_mechanic block_size too small" << endl;
			return;
		}

		if ( !(*global).dunlooks.exists(ref) )
		{
			cout << "DDT> load_dunlook illegal ref" << endl;
			return;
		}



		int block_point = -1;

		while (block_point < block_size - 10)
		{
			block_point++;

			if ( !(  block[block_point] == '(') )
			{
				// nothing
			}
			else if (
					block[block_point + 1] == 'p' &&
					block[block_point + 2] == 'a' &&
					block[block_point + 3] == 'k' &&
					block[block_point + 4] == 'r' &&
					block[block_point + 5] == 'e' &&
					block[block_point + 6] == 'f' &&
					block[block_point + 7] == ')' )
			{
				(*global).dunlooks.dun[ref].pakref_vid = util.get_int_at(block_point+9, block,  block_size);
				(*global).dunlooks.dun[ref].pakref_aud = util.get_int_at(block_point+15, block,  block_size);
			}
			else if (
					block[block_point + 1] == 'l' &&
					block[block_point + 2] == 'o' &&
					block[block_point + 3] == 'a' &&
					block[block_point + 4] == 'd' &&
					block[block_point + 5] == 'm' &&
					block[block_point + 6] == 'e' &&
					block[block_point + 7] == ')' )
			{


				int buff_in_pointer = block_point + 8;
				savebuff buff;

				while ((buff_in_pointer < block_size -1) && !(block[buff_in_pointer] == '('))
				{
					buff.add(block[buff_in_pointer]);
					buff_in_pointer++;
				}

				int loadme_sz = buff.get_size();
				unsigned char* loadme_c = buff.give();
				ddtutils::del_array((*global).dunlooks.dun[ref].loadme,(*global).dunlooks.dun[ref].loadme_size);

				(*global).dunlooks.dun[ref].loadme_size = loadme_sz;
				(*global).dunlooks.dun[ref].loadme = loadme_c;

				block_point = buff_in_pointer;

			}


		}



		delete[] block;
	}



	void load_valuemap(int ref, unsigned char* block, int block_size)
	{
		if ( block_size < 10)
		{
			cout << "DDT> load_valuemap block_size too small" << endl;
			return;
		}

		if ( !(*global).valuemap.exists(ref) )
		{
			cout << "DDT> load_valuemap illegal ref" << endl;
			return;
		}



		int block_point = -1;

		while (block_point < block_size - 10)
		{
			block_point++;

			if ( !(  block[block_point] == '(') )
			{
				// nothing
			}
			else if (
					block[block_point + 1] == 's' &&
					block[block_point + 2] == 'i' &&
					block[block_point + 3] == 'z' &&
					block[block_point + 4] == 'e' &&
					block[block_point + 5] == ')' )
			{
				(*global).valuemap.set_size(ref, util.get_int_at(block_point+7, block,  block_size));
			}
			else if (
					block[block_point + 1] == 's' &&
					block[block_point + 2] == 'i' &&
					block[block_point + 3] == 'z' &&
					block[block_point + 4] == 'e' &&
					block[block_point + 5] == '0' &&
					block[block_point + 6] == 'x' &&
					block[block_point + 7] == ')' )
			{
				(*global).valuemap.set_size(ref, util.get_int_at_hex(block_point+9, block,  block_size));
			}

			else if (
					block[block_point + 1] == 's' &&
					block[block_point + 2] == 'e' &&
					block[block_point + 3] == 't' &&
					block[block_point + 4] == '_' &&
					block[block_point + 5] == 'a' &&
					block[block_point + 6] == 'l' &&
					block[block_point + 7] == 'l' &&
					block[block_point + 8] == ')' )
			{
				int16_t allval = util.get_int_at(block_point+10, block,  block_size);
				int mapsize = (*global).valuemap.size(ref);

				for (int i = 0; i < mapsize; i++)
				{
					(*global).valuemap.set_value(ref, i, allval);
				}

			}

			else if (
					block[block_point + 1] == 's' &&
					block[block_point + 2] == 'e' &&
					block[block_point + 3] == 't' &&
					block[block_point + 4] == '0' &&
					block[block_point + 5] == 'x' &&
					block[block_point + 6] == ')' )
			{
				int valno  = util.get_int_at_hex(block_point+8, block,  block_size);
				int16_t val = util.get_int_at_hex(block_point+14, block,  block_size);
				(*global).valuemap.set_value(ref, valno, val);
			}

			else if (
					block[block_point + 1] == 's' &&
					block[block_point + 2] == 'e' &&
					block[block_point + 3] == 't' &&
					block[block_point + 4] == '_' &&
					block[block_point + 5] == 'r' &&
					block[block_point + 6] == 'a' &&
					block[block_point + 7] == 'n' &&
					block[block_point + 8] == 'g' &&
					block[block_point + 9] == 'e' &&
					block[block_point +10] == '0' &&
					block[block_point +11] == 'x' &&
					block[block_point +12] == ')' )
			{
				int valno_from  = util.get_int_at_hex(block_point+14, block,  block_size);
				int valno_to    = util.get_int_at_hex(block_point+20, block,  block_size);
				int16_t val    = util.get_int_at_hex(block_point+26, block,  block_size);

				for( int i = valno_from; i < valno_to +1; i++)
				{
					(*global).valuemap.set_value(ref, i, val);
				}
			}
		}
		delete[] block;

	}

	void load_dungeon(int ref, unsigned char* block, int block_size)
	{
		if ( block_size < 10)
		{
			cout << "DDT> load_dungeon block_size too small" << endl;
			return;
		}

		if ( !(*global).dungeons.exists(ref) )
		{
			cout << "DDT> load_dungeon illegal ref" << endl;
			return;
		}



		int block_point = -1;

		while (block_point < block_size - 10)
		{
			block_point++;

			if ( !(  block[block_point] == '(') )
			{
				// nothing
			}

			else if (
					block[block_point + 1] == 'd' &&
					block[block_point + 2] == 'u' &&
					block[block_point + 3] == 'n' &&
					block[block_point + 4] == 'l' &&
					block[block_point + 5] == 'o' &&
					block[block_point + 6] == 'o' &&
					block[block_point + 7] == 'k' &&
					block[block_point + 8] == ')' )
			{
				int from = util.get_int_at(block_point + 10, block,  block_size);
				int to = util.get_int_at(block_point + 16, block,  block_size);
				(*global).dungeons.set_look(ref, from, to);
			}

			else if (
					block[block_point + 1] == 'n' &&
					block[block_point + 2] == 'a' &&
					block[block_point + 3] == 'm' &&
					block[block_point + 4] == 'e' &&
					block[block_point + 5] == ')' )
			{
				string argu = util.get_argument_at(block_point + 7,  block,  block_size);
				(*global).dungeons.set_name(ref, argu);
			}

			else if (
					block[block_point + 1] == 'b' &&
					block[block_point + 2] == 'l' &&
					block[block_point + 3] == 'o' &&
					block[block_point + 4] == 'b' &&
					block[block_point + 5] == '_' &&
					block[block_point + 6] == 'n' &&
					block[block_point + 7] == 'a' &&
					block[block_point + 8] == 'm' &&
					block[block_point + 9] == 'e' &&
					block[block_point +10] == ')' )
			{
				int name_no = util.get_int_at(block_point+12, block,  block_size);
				string out = (*global).binblob.get_dungeon_name(name_no);
				(*global).dungeons.set_name(ref, out);
			}

			else if (
					block[block_point + 1] == 's' &&
					block[block_point + 2] == 'e' &&
					block[block_point + 3] == 'c' &&
					block[block_point + 4] == 't' &&
					block[block_point + 5] == 'o' &&
					block[block_point + 6] == 'r' &&
					block[block_point + 7] == '_' &&
					block[block_point + 8] == 's' &&
					block[block_point + 9] == 'o' &&
					block[block_point +10] == 'u' &&
					block[block_point +11] == 'r' &&
					block[block_point +12] == 'c' &&
					block[block_point +13] == 'e' &&
					block[block_point +14] == ')' )
			{
				string argu = util.get_argument_at(block_point + 16,  block,  block_size);
				(*global).dungeons.set_sector_source(ref, argu);
			}

			else if (
					block[block_point + 1] == 'l' &&
					block[block_point + 2] == 'o' &&
					block[block_point + 3] == 'a' &&
					block[block_point + 4] == 'd' &&
					block[block_point + 5] == 'b' &&
					block[block_point + 6] == 'g' &&
					block[block_point + 7] == ')' )
			{
				string argu = util.get_argument_at(block_point + 9,  block,  block_size);
				(*global).dungeons.set_loadbg(ref, argu);
			}

			else if (
					block[block_point + 1] == 'f' &&
					block[block_point + 2] == 'i' &&
					block[block_point + 3] == 'r' &&
					block[block_point + 4] == 's' &&
					block[block_point + 5] == 't' &&
					block[block_point + 6] == '_' &&
					block[block_point + 7] == 'l' &&
					block[block_point + 8] == 'o' &&
					block[block_point + 9] == 'a' &&
					block[block_point +10] == 'd' &&
					block[block_point +11] == ')' )
			{
				string argu = util.get_argument_at(block_point + 13,  block,  block_size);
				(*global).dungeons.set_first_load_extra(ref, argu);
			}

			else if (
					block[block_point + 1] == 't' &&
					block[block_point + 2] == 'i' &&
					block[block_point + 3] == 'l' &&
					block[block_point + 4] == 'e' &&
					block[block_point + 5] == '_' &&
					block[block_point + 6] == 'd' &&
					block[block_point + 7] == 'i' &&
					block[block_point + 8] == 'm' &&
					block[block_point + 9] == 's' &&
					block[block_point +10] == ')' )
			{
				int x = util.get_int_at(block_point + 12, block,  block_size);
				int y = util.get_int_at(block_point + 18, block,  block_size);
				(*global).dungeons.set_dungeon_xy(ref, x, y);

				//cout << (*global).dungeons.dun[ref].tile_dim_x << " " << (*global).dungeons.dun[ref].tile_dim_y << endl;
			}
			else if (
					block[block_point + 1] == 's' &&
					block[block_point + 2] == 'e' &&
					block[block_point + 3] == 'c' &&
					block[block_point + 4] == 't' &&
					block[block_point + 5] == 'o' &&
					block[block_point + 6] == 'r' &&
					block[block_point + 7] == '_' &&
					block[block_point + 8] == 'p' &&
					block[block_point + 9] == 'r' &&
					block[block_point +10] == 'i' &&
					block[block_point +11] == 'm' &&
					block[block_point +12] == 'e' &&
					block[block_point +13] == ')' )
			{
				(*global).dungeons.set_prime_sec(ref, util.get_int_at(block_point + 15, block,  block_size));

			}
		}

		delete[] block;
	}


	void load_itemtype(int ref, unsigned char* block, int block_size)
	{
		if ( block_size < 10)
		{
			cout << "DDT> load_itemtype block_size too small" << endl;
			return;
		}

		if ( !(*global).itemtype.exists(ref) )
		{
			cout << "DDT> load_itemtype illegal ref" << endl;
			return;
		}



		int block_point = -1;

		while (block_point < block_size - 10)
		{
			block_point++;

			if ( !(  block[block_point] == '(') )
			{
				// nothing
			}
			else if (
					block[block_point + 1] == 'n' &&
					block[block_point + 2] == 'a' &&
					block[block_point + 3] == 'm' &&
					block[block_point + 4] == 'e' &&
					block[block_point + 5] == ')' )
			{
				string argu = util.get_argument_at(block_point + 7,  block,  block_size);
				(*global).itemtype.type[ref].name = argu;
			}

			else if (
					block[block_point + 1] == 'g' &&
					block[block_point + 2] == 'r' &&
					block[block_point + 3] == 'o' &&
					block[block_point + 4] == 'u' &&
					block[block_point + 5] == 'n' &&
					block[block_point + 6] == 'd' &&
					block[block_point + 7] == '_' &&
					block[block_point + 8] == 'g' &&
					block[block_point + 9] == 'r' &&
					block[block_point +10] == 'f' &&
					block[block_point +11] == 'x' &&
					block[block_point +12] == ')' )
			{
				(*global).itemtype.type[ref].on_ground_tex = util.get_int_at(block_point+14, block,  block_size);
			}

			else if (
					block[block_point + 1] == 'f' &&
					block[block_point + 2] == 'l' &&
					block[block_point + 3] == 'i' &&
					block[block_point + 4] == 'p' &&
					block[block_point + 5] == '_' &&
					block[block_point + 6] == 's' &&
					block[block_point + 7] == 'f' &&
					block[block_point + 8] == 'x' &&
					block[block_point + 9] == ')' )
			{
				(*global).itemtype.type[ref].flip_sfx = util.get_int_at(block_point+11, block,  block_size);
			}

			else if (
					block[block_point + 1] == 's' &&
					block[block_point + 2] == 't' &&
					block[block_point + 3] == 'a' &&
					block[block_point + 4] == 'c' &&
					block[block_point + 5] == 'k' &&
					block[block_point + 6] == '_' &&
					block[block_point + 7] == 'l' &&
					block[block_point + 8] == 'i' &&
					block[block_point + 9] == 'm' &&
					block[block_point +10] == 'i' &&
					block[block_point +11] == 't' &&
					block[block_point +12] == ')' )
			{
				int val = 10000 *  util.get_int_at(block_point+14, block,  block_size);
				val = val + util.get_int_at(block_point+20, block,  block_size);

				if (val < 2)
				{
					(*global).itemtype.type[ref].stackable = false;
					(*global).itemtype.type[ref].stack_limit = 1;
				}
				else
				{
					(*global).itemtype.type[ref].stackable = true;
					(*global).itemtype.type[ref].stack_limit = val;
				}


			}



		}



		delete[] block;
	}
};
