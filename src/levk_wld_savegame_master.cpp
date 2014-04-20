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




#include "levk_wld_on_tileclick_interaction.cpp"
using namespace std;


class savegame_master
{
	private:

	globals* global;
	world_local* local;
	utils util;
	mail* post;

	public:

	void init(globals* glob, world_local* loc)
	{
		global = glob;
		local = loc;
	}

	void generate_new_char_save()
	{

		int game_mode = (*global).game_mode;
		int save_size = ddtsavegame::static_size();
		unsigned char* save = new unsigned char[save_size];
		for (int i  = 0; i < save_size; i++) { save[i] = 0;}


		//file defines
		//------------

		ddtsavegame::set_file_header(save, save_size);


		//game independant char characteristics
		//-------------------------------------

		ddtsavegame::set_expantion_mode(game_mode, save, save_size);
		ddtsavegame::set_char_class((*local).pclass.class_number, save, save_size);
		ddtsavegame::set_stars(0, save, save_size); //diablo never defeated yet
		ddtsavegame::set_level(1, save, save_size); //starting at level 1
		ddtsavegame::set_xp(0, save, save_size); //no xp yet

		ddtsavegame::set_spell_level(0, 1, save, save_size); //class skill is 1

		ddtsavegame::set_map_active(false, save, save_size);
		ddtsavegame::set_map_move(0, 0, save, save_size); //center the map

		ddtsavegame::set_str((*local).pclass.str_start, save, save_size); //starting stats
		ddtsavegame::set_mag((*local).pclass.mag_start, save, save_size); //starting stats
		ddtsavegame::set_dex((*local).pclass.dex_start, save, save_size); //starting stats
		ddtsavegame::set_vit((*local).pclass.vit_start, save, save_size); //starting stats

		//cout << "game independant char characteristics done " << endl;

		//items on char
		//-------------

		ddtsavegame::set_item_hands_left(false, (*local).pclass.start_item[0], save, save_size);
		ddtsavegame::set_item_hands_right(false, (*local).pclass.start_item[1], save, save_size);
		ddtsavegame::set_item_inventory(0, 3, (*local).pclass.start_item[2], save, save_size); //should be gold
		ddtsavegame::set_item_belt(0, (*local).pclass.start_item[3], save, save_size); //first potion
		ddtsavegame::set_item_belt(1, (*local).pclass.start_item[4], save, save_size); //2nd potion
		//cout << "items on char done " << endl;


		//game specific characteristics
		//-----------------------------

		ddtsavegame::set_active_dungeon(LEVEL_TOWN , save, save_size);
		ddtsavegame::set_char_tile_location(99, 47, save, save_size); //town coords

		ddtsavegame::set_hp(10, save, save_size);  //temp values
		ddtsavegame::set_mana(10, save, save_size);
		//cout << "game specific characteristics done " << endl;


		//sectorfixes
		//-----------------------------




		reset_random_block(save, save_size);

		(*global).threadpush_filesystem(new mail(FILEIO_WRITE_SAVE, save, save_size));

	}

	void place_savegame(unsigned char* save, int save_size)
	{

		if (save_size < ddtsavegame::static_size())
		{
			cout << "DDT> savegame loaded recieved a to short save. aborting" << endl;
			(*global).quit_game = true;
			return;
		}


		(*local).psave.load_whole_savegame_distructive(save, save_size);

	}

	void scrub_dungeon_info()
	{
		for (int i = 0; i < LEVEL_COUNT; i++)
		{
			(*local).psave.delete_dungeon(i);
		}

		int stat_size = ddtsavegame::static_size();
		unsigned char* stat = (*local).psave.show_static_part();

		ddtsavegame::set_active_dungeon(LEVEL_TOWN , stat, stat_size);
		ddtsavegame::set_char_tile_location(99, 47, stat, stat_size);
		ddtsavegame::set_diff((*global).game_diff, stat, stat_size);


		for (int i = 0; i < SECTORFIX_COUNT; i++)
		{
			ddtsavegame::set_sector_fix(false, i, stat, stat_size);
		}


		reset_random_block(stat, stat_size);
	}




	void export_savegame()
	{

		savebuff buff;

		buff.add_nondestuctive((*local).psave.show_static_part(), ddtsavegame::static_size());

		for (int i = 0; i < LEVEL_COUNT; i++)
		{
			buff.add_nondestuctive((*local).psave.show_dungeon(i), (*local).psave.get_dungeon_size(i));
		}

		int out_size = buff.get_size();
		unsigned char* out = buff.give();

		int var_off_start = ddtsavegame::static_size();
		int var_off_end = var_off_start + (*local).psave.get_dungeon_size(0);

		for (int i = 0; i < LEVEL_COUNT; i++)
		{
			ddtsavegame::set_level_info_offset(var_off_start, i, out, out_size);

			var_off_start = var_off_end;
			var_off_end = var_off_start + (*local).psave.get_dungeon_size(i+1);
		}
		ddtsavegame::set_level_info_offset(out_size, LEVEL_COUNT, out, out_size);

		(*global).ondisk_savegame_dunno = (*global).level_number;
		(*global).ondisk_savegame_mode = (*global).game_mode;

		(*global).threadpush_filesystem(new mail(FILEIO_WRITE_SAVE, out, out_size));


	}




	void world_to_saveg_static()
	{
		unsigned char* stat = (*local).psave.show_static_part();
		int stat_size = ddtsavegame::static_size();

		ddtsavegame::set_expantion_mode((*global).game_mode, stat, stat_size);
		ddtsavegame::set_char_tile_location((*global).player.player_at_x_int, (*global).player.player_at_y_int, stat, stat_size );
		ddtsavegame::set_active_dungeon((*global).level_number, stat, stat_size);

		ddtsavegame::set_map_active((*global).player.show_map, stat, stat_size);
		ddtsavegame::set_map_move((*global).player.map_move_x_percent, (*global).player.map_move_y_percent, stat, stat_size);

		for (int i = 0; i < SECTORFIX_COUNT; i++)
		{
			bool value = (*global).player.get_sector_fix(i);
			ddtsavegame::set_sector_fix(value, i, stat, stat_size);
		}

	}


	void saveg_to_world_static()
	{
		unsigned char* stat = (*local).psave.show_static_part();
		int stat_size = ddtsavegame::static_size();

		(*global).player.player_at_x_int = ddtsavegame::get_char_tile_location_x(stat, stat_size);
		(*global).player.player_at_x_doub = (*global).player.player_at_x_int;
		(*global).player.player_at_y_int = ddtsavegame::get_char_tile_location_y(stat, stat_size);
		(*global).player.player_at_y_doub = (*global).player.player_at_y_int;
		(*global).level_number = ddtsavegame::get_active_dungeon(stat, stat_size);
		//(*global).savegame_active_dun = (*global).level_number;
		(*global).game_diff = ddtsavegame::get_diff(stat, stat_size);

		(*global).player.show_map = ddtsavegame::get_map_active(stat, stat_size);
		(*global).player.map_move_x_percent = ddtsavegame::get_map_move_x(stat, stat_size);
		(*global).player.map_move_y_percent = ddtsavegame::get_map_move_y(stat, stat_size);

		for (int i = 0; i < SECTORFIX_COUNT; i++)
		{
			bool value = ddtsavegame::get_sector_fix(i, stat, stat_size);
			(*global).player.set_sector_fix(value,i);

		}

	}

	void world_to_saveg_dungeon()
	{
		savebuff buff;

		//(*global).lock_world_token(); //not locking all tiles should be locked allready

		int lev_x_size = (*global).tile_count_x;
		int lev_y_size = (*global).tile_count_y;
		int dunno = (*global).level_number;



		int map_size = ddtsavegame::mapexplore_get_size_for_tiles(lev_x_size, lev_y_size);
		unsigned char* map = new unsigned char[map_size];

		ddtsavegame::set_mapexplore_id(0, map, map_size);
		ddtsavegame::set_mapexplore_size(map_size, 0, map, map_size);

		int tile_counter = 0;
		for(int x = 0; x < lev_x_size; x++)
		{
			for(int y = 0; y < lev_y_size; y++)
			{
				if ((*global).tile_exists(x,y))
				{
					bool discovered = (*global).tile[x][y].discovered;
					ddtsavegame::add_mapexplore_tile(discovered, tile_counter, 0, map, map_size);
					tile_counter++;
				}
			}
		}

		//(*global).unlock_world_token();

		buff.add_destuctive(map, map_size);





		for(int x = 0; x < lev_x_size; x++)
		{
			for(int y = 0; y < lev_y_size; y++)
			{
				//(*global).lock_tile(x,y); //not locking because all tiles should be locked allready
				if ((*global).tile_exists(x,y))
				{

					(*global).tile[x][y].monsters.reset_itt();
					while((*global).tile[x][y].monsters.can_request_next())
					{
						tile_monster* mon = (*global).tile[x][y].monsters.request_next();

						if ( (*global).monsters.savable((*mon).type))
						{
							int cmon_size = ddtsavegame::monster_size();
							unsigned char* cmon = ddtutils::empty_array(cmon_size);

							ddtsavegame::set_savegame_monster_id(0, cmon, cmon_size);
							ddtsavegame::set_savegame_monster_tile_location(x, y, 0, cmon, cmon_size);
							ddtsavegame::set_savegame_monster_type((*mon).type, 0, cmon, cmon_size);
							ddtsavegame::set_savegame_monster_facing((*mon).facing, 0, cmon, cmon_size);

							buff.add_destuctive(cmon, cmon_size);
						}
					}


					if ((*global).tile[x][y].has_mechanic)
					{
						tile_mechanic* mech = (*global).tile[x][y].mech;
						if ((*global).mechanics.savable((*mech).type))
						{
							int cmech_size = ddtsavegame::mech_size();
							unsigned char* cmech = ddtutils::empty_array(cmech_size);

							ddtsavegame::set_savegame_mech_id(0, cmech, cmech_size);
							ddtsavegame::set_savegame_mech_tile_location(x, y, 0, cmech, cmech_size);
							ddtsavegame::set_savegame_mech_type((*mech).type, 0, cmech, cmech_size);
							ddtsavegame::set_savegame_mech_on((*mech).is_open, 0, cmech, cmech_size);

							buff.add_destuctive(cmech, cmech_size);
						}
					}


				}
				//(*global).unlock_tile(x,y);
			}
		}

		int lev_c_size = buff.get_size();
		unsigned char* lev_c = buff.give();
		(*local).psave.set_dungeon_from_world_distructive(lev_c, lev_c_size, dunno);


		//unsigned char* dun = (*local).psave.show_dungeon(dunno);
		//int dun_size = (*local).psave.get_dungeon_size(dunno);

		//cout << "parsing dungeon " << dunno << "with size " << dec << dun_size << endl;
		//for (int i = 0; i< dun_size; i++ )
		//{
			//cout << hex << (int)dun[i] << endl;
		//}

	}

	void saveg_to_world_dungeon()
	{
		int dunno = (*global).level_number;
		if (!(*local).psave.dungeon_has_size(dunno)) {return;}

		unsigned char* dun = (*local).psave.show_dungeon(dunno);
		int dun_size = (*local).psave.get_dungeon_size(dunno);

		//ddtutils::cout_array_hex(dun, dun_size);

		int dunpointer = 0;
		while (dunpointer < dun_size -5)
		{



			if ( ddtsavegame::has_savegame_monster_id(dunpointer, dun, dun_size))
			{
				//cout << "savegame monster detected " << endl;

				saveg_to_world_monster(dun, dun_size, dunpointer);
				dunpointer = dunpointer + ddtsavegame::monster_size();
			}
			else if ( ddtsavegame::has_mapexplore_id(dunpointer, dun, dun_size))
			{
				saveg_to_world_map(dun, dun_size, dunpointer);
				dunpointer = dunpointer + ddtsavegame::get_mapexplore_size(dunpointer, dun, dun_size);
			}
			else if (ddtsavegame::has_savegame_mech_id(dunpointer, dun, dun_size))
			{
				saveg_to_world_mech(dun, dun_size, dunpointer);
				dunpointer = dunpointer + ddtsavegame::mech_size();
			}
			else
			{
				cout << "DDT> unknown savegame level member id "
				<< hex
				<< (int)ddtsavegame::get_savegame_variable_length_member_id(dunpointer, dun, dun_size)
				<< endl;
				return;
			}

		}


	}

	void saveg_to_world_monster(unsigned char* dun, int dun_size, int offset)
	{
		int x = ddtsavegame::get_savegame_monster_tile_location_x(offset, dun, dun_size);
		int y = ddtsavegame::get_savegame_monster_tile_location_y(offset, dun, dun_size);

		//(*global).lock_tile(x,y);  //not locking because all tiles should be locked allready
		if ((*global).tile_exists(x,y))
		{
			tile_monster* mon = new tile_monster;

			(*mon).type = ddtsavegame::get_savegame_monster_type(offset, dun, dun_size);
			(*mon).facing = ddtsavegame::get_savegame_monster_facing(offset, dun, dun_size);
			(*mon).pos_x_doub = x;
			(*mon).pos_y_doub = y;

			(*global).tile[x][y].monsters.add(mon);
		}
		//(*global).unlock_tile(x,y);

	}

	void saveg_to_world_mech(unsigned char* dun, int dun_size, int offset)
	{

		int x = ddtsavegame::get_savegame_mech_tile_location_x(offset, dun, dun_size);
		int y = ddtsavegame::get_savegame_mech_tile_location_y(offset, dun, dun_size);

		//(*global).lock_tile(x,y);  //not locking because all tiles should be locked allready
		if ((*global).tile_exists(x,y))
		{
			tile_mechanic* mech = new tile_mechanic;

			(*mech).type = ddtsavegame::get_savegame_mech_type(offset, dun, dun_size);
			(*mech).is_open = ddtsavegame::get_savegame_mech_on(offset, dun, dun_size);

			(*global).tile[x][y].place_mechanic(mech);


		}
	}


	void saveg_to_world_map(unsigned char* dun, int dun_size, int offset)
	{
		//(*global).lock_world_token();
		int lev_x_size = (*global).tile_count_x;
		int lev_y_size = (*global).tile_count_y;


		int tile_counter = 0;
		for(int x = 0; x < lev_x_size; x++)
		{
			for(int y = 0; y < lev_y_size; y++)
			{
				if ((*global).tile_exists(x,y))
				{
					bool discovered = ddtsavegame::get_mapexplore_tile(tile_counter, offset, dun, dun_size);

					(*global).tile[x][y].discovered = discovered;
					tile_counter++;
				}
			}
		}
		//(*global).unlock_world_token();
	}





	void reset_random_block(unsigned char* save, int save_size)
	{
		int rnd_size = ddtsavegame::random_block_size();

		for (int i = 0; i < rnd_size; i++)
		{
			ddtsavegame::set_random_block(
					(uint8_t)ddtmath::random_int(0xff),
					i,
					save,
					save_size);
		}
	}


};
