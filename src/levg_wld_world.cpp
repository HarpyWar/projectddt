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




#include "levg_fsy_loadsave.cpp"

#define WORLDSTATE_NOLOAD 0

#define WORLDSTATE_NEWCHAR_WAIT_FOR_CLASS 1
#define WORLDSTATE_NEWCHAR_WAIT_FOR_SAVEGAME 2
#define WORLDSTATE_NEWCHAR_WAIT_FOR_DUN 3

#define WORLDSTATE_NEWGAME_WAIT_FOR_CLASS 5
#define WORLDSTATE_NEWGAME_WAIT_FOR_SAVEGAME 6
#define WORLDSTATE_NEWGAME_WAIT_FOR_DUN 7

#define WORLDSTATE_OLDGAME_WAIT_FOR_CLASS 9
#define WORLDSTATE_OLDGAME_WAIT_FOR_SAVEGAME 10
#define WORLDSTATE_OLDGAME_WAIT_FOR_DUN 11

#define WORLDSTATE_EXISTING_DUN_WAIT_FOR_DUN 13
#define WORLDSTATE_NEW_DUN_WAIT_FOR_DUN 15
#define WORLDSTATE_WRITE_SAVEGAME_WAIT_FOR_DONE 16



using namespace std;




class world_manager
{
	public:

	globals* global;
	world_local* local;
	level_loader level_load;
	class_loader class_load;
	savegame_master save_master;
	level_updater level_up;
	tile_object_interactor t_o_interact;
	utils util;
	mail* post;

	int world_state;
	int new_level_destination_mechanic;
	bool first_load_extra;

	world_manager()
	{

		world_state = WORLDSTATE_NOLOAD;
		new_level_destination_mechanic = -1;
		first_load_extra = false;
	}



	void in_thread_init(globals* glob)
	{
		global = glob;
		local = new world_local;

		level_load.init(global, local);
		class_load.init(local);
		level_up.init(global, local);
		save_master.init(global, local);
		t_o_interact.init(global, local);

	}

	void start_chain_newchar()
	{
		display_load_stage(1);

		if (world_state != WORLDSTATE_NOLOAD) {return;}

		(*global).active_screen = SCREEN_LOAD_WAIT;
		(*global).game_pause = true;
		post = new mail(FILEIO_LOAD_RULES, (*global).dungeons.get_loadbg(LEVEL_TOWN));
		(*global).threadpush_filesystem(post);
		post = new mail( FILEIO_LOAD_RULES, (*global).player.char_class_path.get());
		(*global).threadpush_filesystem(post);
		world_state = WORLDSTATE_NEWCHAR_WAIT_FOR_CLASS;
		first_load_extra = true;

		ddttime::delay(500);
		(*global).lock_all_tiles();
	}

	void start_chain_newgame()
	{
		display_load_stage(1);

		if (world_state != WORLDSTATE_NOLOAD) {return;}

		(*global).active_screen = SCREEN_LOAD_WAIT;
		(*global).game_pause = true;
		post = new mail(FILEIO_LOAD_RULES, (*global).dungeons.get_loadbg(LEVEL_TOWN));
		(*global).threadpush_filesystem(post);
		post = new mail( FILEIO_LOAD_RULES, (*global).player.char_class_path.get());
		(*global).threadpush_filesystem(post);
		world_state = WORLDSTATE_NEWGAME_WAIT_FOR_CLASS;
		first_load_extra = true;

		ddttime::delay(500);
		(*global).lock_all_tiles();
	}

	void start_chain_oldgame()
	{
		display_load_stage(1);

		if (world_state != WORLDSTATE_NOLOAD) {return;}

		(*global).active_screen = SCREEN_LOAD_WAIT;
		(*global).game_pause = true;
		int lv = (*global).ondisk_savegame_dunno;
		post = new mail(FILEIO_LOAD_RULES, (*global).dungeons.get_loadbg(lv));
		(*global).threadpush_filesystem(post);
		post = new mail( FILEIO_LOAD_RULES, (*global).player.char_class_path.get());
		(*global).threadpush_filesystem(post);
		world_state = WORLDSTATE_OLDGAME_WAIT_FOR_CLASS;
		first_load_extra = false;

		ddttime::delay(500);
		(*global).lock_all_tiles();
	}

	void start_chain_change_dun(int source_mech)
	{
		display_load_stage(1);

		if (world_state != WORLDSTATE_NOLOAD) {return;}
		if (!(*global).mechanics.exists(source_mech))  {return;}

		int dest_mech = (*global).mechanics.mech[source_mech].other_mech_ref;
		int new_lev = (*global).mechanics.mech[source_mech].dungeon_ref;

		if (!(*local).psave.dungeon_exists(new_lev)) {return;}
		if (!(*global).mechanics.exists(dest_mech)) {return;}

		(*global).active_screen = SCREEN_LOAD_WAIT;
		(*global).game_pause = true;
		new_level_destination_mechanic = dest_mech;

		ddttime::delay(500);
		(*global).lock_all_tiles();

		save_master.world_to_saveg_static();
		save_master.world_to_saveg_dungeon();
		if((*global).autosave) { save_master.export_savegame();}

		(*global).level_number = new_lev;
		level_load.order_dun_sector_load_from_statics((*global).level_number);

		if ((*local).psave.dungeon_has_size(new_lev))
		{
			world_state = WORLDSTATE_EXISTING_DUN_WAIT_FOR_DUN;
			first_load_extra = false;
		}
		else
		{
			world_state = WORLDSTATE_NEW_DUN_WAIT_FOR_DUN;
			first_load_extra = true;
		}

	}


	void load_class(unsigned char* classtxt, int classtxt_size)
	{
		display_load_stage(2);

		if ( world_state ==  WORLDSTATE_NEWCHAR_WAIT_FOR_CLASS)
		{
			class_load.read_class_rules(classtxt,classtxt_size);
			save_master.generate_new_char_save();
			(*global).threadpush_filesystem(new mail(FILEIO_LOAD_SAVE));
			world_state = WORLDSTATE_NEWCHAR_WAIT_FOR_SAVEGAME;
		}
		else if ( world_state ==  WORLDSTATE_NEWGAME_WAIT_FOR_CLASS)
		{
			class_load.read_class_rules(classtxt,classtxt_size);
			(*global).threadpush_filesystem(new mail(FILEIO_LOAD_SAVE));
			world_state = WORLDSTATE_NEWGAME_WAIT_FOR_SAVEGAME;
		}
		else if ( world_state ==  WORLDSTATE_OLDGAME_WAIT_FOR_CLASS)
		{
			class_load.read_class_rules(classtxt,classtxt_size);
			(*global).threadpush_filesystem(new mail(FILEIO_LOAD_SAVE));
			world_state = WORLDSTATE_OLDGAME_WAIT_FOR_SAVEGAME;
		}
		else
		{
			cout << "DDT> world load class illegal state" << endl;
		}

		display_load_stage(3);
	}

	void load_save(unsigned char* save, int save_size)
	{
		display_load_stage(4);

		if ( world_state ==  WORLDSTATE_NEWCHAR_WAIT_FOR_SAVEGAME)
		{
			save_master.place_savegame(save, save_size);
			save_master.saveg_to_world_static();

			level_load.order_dun_sector_load_from_statics((*global).level_number);

			int_ucharp playtex = (*local).pclass.give_texref_rules(CLASSTX_LIGHT_UNARMED, false);
			post = new mail(FILEIO_LOAD_PROVIDED_RULES, playtex.c, playtex.i);
			(*global).threadpush_filesystem(post);
			world_state =  WORLDSTATE_NEWCHAR_WAIT_FOR_DUN;
		}
		else if ( world_state ==  WORLDSTATE_NEWGAME_WAIT_FOR_SAVEGAME)
		{
			save_master.place_savegame(save, save_size);
			save_master.scrub_dungeon_info();
			save_master.saveg_to_world_static();

			level_load.order_dun_sector_load_from_statics((*global).level_number);

			int_ucharp playtex = (*local).pclass.give_texref_rules(CLASSTX_LIGHT_UNARMED, false);
			post = new mail(FILEIO_LOAD_PROVIDED_RULES, playtex.c, playtex.i);
			(*global).threadpush_filesystem(post);
			world_state =  WORLDSTATE_NEWGAME_WAIT_FOR_DUN;
		}
		else if ( world_state ==  WORLDSTATE_OLDGAME_WAIT_FOR_SAVEGAME)
		{
			save_master.place_savegame(save, save_size);
			save_master.saveg_to_world_static();

			level_load.order_dun_sector_load_from_statics((*global).level_number);

			int_ucharp playtex = (*local).pclass.give_texref_rules(CLASSTX_LIGHT_UNARMED, false);
			post = new mail(FILEIO_LOAD_PROVIDED_RULES, playtex.c, playtex.i);
			(*global).threadpush_filesystem(post);
			world_state =  WORLDSTATE_OLDGAME_WAIT_FOR_DUN;
		}

		else
		{
			cout << "DDT> world load save illegal state" << endl;
		}

		display_load_stage(5);


	}


	void load_level(unsigned char* levtxt, int levtxt_size)
	{
		display_load_stage(6);

		if (world_state == WORLDSTATE_NEWCHAR_WAIT_FOR_DUN)
		{
			level_load.read_level_rules(levtxt, levtxt_size);
			level_load.rasterise_level((*global).level_number, true);
			level_load.check_sectorfixes((*global).level_number);

			level_load.add_player_at((*global).player.player_at_x_int, (*global).player.player_at_y_int);
			level_load.load_tile_dwellers();

			save_master.world_to_saveg_static();
			save_master.world_to_saveg_dungeon();
			save_master.export_savegame();
		}
		else if (world_state == WORLDSTATE_NEWGAME_WAIT_FOR_DUN)
		{
			level_load.read_level_rules(levtxt, levtxt_size);
			level_load.rasterise_level((*global).level_number, true);
			level_load.check_sectorfixes((*global).level_number);

			level_load.add_player_at((*global).player.player_at_x_int, (*global).player.player_at_y_int);
			level_load.load_tile_dwellers();

			if ((*global).ondisk_savegame_mode != (*global).game_mode)
			{

				save_master.world_to_saveg_static();
				save_master.world_to_saveg_dungeon();
				save_master.export_savegame();
			}

		}
		else if (world_state == WORLDSTATE_OLDGAME_WAIT_FOR_DUN)
		{
			level_load.read_level_rules(levtxt, levtxt_size);
			level_load.rasterise_level((*global).level_number, false);

			save_master.saveg_to_world_dungeon();
			level_load.check_sectorfixes((*global).level_number);

			level_load.add_player_at((*global).player.player_at_x_int, (*global).player.player_at_y_int);
			level_load.load_tile_dwellers();
		}
		else if (world_state == WORLDSTATE_EXISTING_DUN_WAIT_FOR_DUN)
		{
			level_load.read_level_rules(levtxt, levtxt_size);
			level_load.rasterise_level((*global).level_number, false);

			save_master.saveg_to_world_dungeon();
			level_load.check_sectorfixes((*global).level_number);

			di_int playpos =  level_load.find_mechanic_on_tiles(new_level_destination_mechanic);
			(*global).player.player_at_x_int = playpos.x;
			(*global).player.player_at_x_doub = playpos.x;
			(*global).player.player_at_y_int = playpos.y;
			(*global).player.player_at_y_doub = playpos.y;

			level_load.add_player_at((*global).player.player_at_x_int, (*global).player.player_at_y_int);
			level_load.load_tile_dwellers();
		}
		else if (world_state == WORLDSTATE_NEW_DUN_WAIT_FOR_DUN)
		{

			level_load.read_level_rules(levtxt, levtxt_size);
			level_load.rasterise_level((*global).level_number, true);
			level_load.check_sectorfixes((*global).level_number);

			di_int playpos =  level_load.find_mechanic_on_tiles(new_level_destination_mechanic);
			(*global).player.player_at_x_int = playpos.x;
			(*global).player.player_at_x_doub = playpos.x;
			(*global).player.player_at_y_int = playpos.y;
			(*global).player.player_at_y_doub = playpos.y;

			level_load.add_player_at((*global).player.player_at_x_int, (*global).player.player_at_y_int);
			level_load.load_tile_dwellers();
		}
		else
		{
			cout << "DDT> world load_level illegal state" << endl;
			return;
		}




		post = new mail(MOUSEKEYB_CLEAN_WORLD_UI);
		(*global).threadpush_mousekeyb(post);

		(*global).unlock_all_tiles();

		display_load_stage(7);

		wait_for_loading();
		(*global).game_pause = false;
		(*global).active_screen = SCREEN_WORLD;
		world_state = WORLDSTATE_NOLOAD;

		post = new mail(FILEIO_LOAD_RULES, ddtrules::clear_bg());
		(*global).threadpush_filesystem(post);

		display_load_stage(0);

		if ((*global).dungeons.has_first_load_extra((*global).level_number) && (first_load_extra || (*global).level_number == LEVEL_TOWN ||DEVELOPER_LEVEL_EXTRA))
		{
			string extra = (*global).dungeons.get_first_load_extra((*global).level_number);
			post = new mail(FILEIO_LOAD_RULES, extra);
			(*global).threadpush_filesystem(post);
		}


	}

	void make_manual_savegame()
	{
		if (world_state != WORLDSTATE_NOLOAD) {return;}
		//(*global).active_screen = SCREEN_LOAD_WAIT;
		(*global).game_pause = true;

		(*global).lock_all_tiles();

		save_master.world_to_saveg_static();
		save_master.world_to_saveg_dungeon();
		save_master.export_savegame();

		world_state = WORLDSTATE_WRITE_SAVEGAME_WAIT_FOR_DONE;

	}

	void accept_manual_savegame_sucess()
	{
		if (world_state == WORLDSTATE_WRITE_SAVEGAME_WAIT_FOR_DONE)
		{
			world_state = WORLDSTATE_NOLOAD;
			(*global).active_screen = SCREEN_WORLD;
			(*global).game_pause = false;
			(*global).threadpush_mousekeyb(new mail(MOUSEKEYB_SET_MSG, "game has been saved"));

			(*global).unlock_all_tiles();

		}
	}

	void sector_hotfix(int fixno)
	{
		if (world_state != WORLDSTATE_NOLOAD) {return;}
		(*global).lock_all_tiles();
		level_load.apply_sectorfix(fixno, true);
		(*global).unlock_all_tiles();
	}

	void update_tiles()
	{
		if (world_state != WORLDSTATE_NOLOAD) {return;}
		if ((*global).active_screen != SCREEN_WORLD){return;}
		if ((*global).game_pause) {return;}

		level_up.update_tiles();


	}

	void player_left_clicked(int x, int y)
	{
		if (world_state != WORLDSTATE_NOLOAD) {return;}
		if ((*global).active_screen != SCREEN_WORLD){return;}
		if ((*global).game_pause) {return;}

		int player_x = (*global).player.player_at_x_int;
		int player_y = (*global).player.player_at_y_int;

		bool close_tile = util.tiles_are_one_appart(x, y, player_x, player_y);
		bool same_tile = util.is_same_tile(x,y, player_x, player_y);
		bool going_for_monster_interaction = false;
		int16_t interaction_monster_type = MON_VOID;
		bool going_for_mech_activation = false;
		int16_t interaction_mech_type = TILE_MECH_VOID;
		bool going_for_a_walk = false;

		if (close_tile)
		{
			(*global).lock_tile(x, y);
			if ( (*global).tile_exists(x, y))
			{

				(*global).tile[x][y].monsters.reset_itt();
				if((*global).tile[x][y].monsters.can_request_next())
				{
					tile_monster* tmon = (*global).tile[x][y].monsters.request_next();
					if ((*global).monsters.selectable((*tmon).type))
					{
						going_for_monster_interaction = true;
						interaction_monster_type = (*tmon).type;
					}
				}

				if ( (*global).tile[x][y].has_mechanic  && !going_for_monster_interaction)
				{
					tile_mechanic* tm = (*global).tile[x][y].mech;
					if ( (*global).mechanics.selectable((*tm).type) )
					{
						going_for_mech_activation = true;
						interaction_mech_type = (*tm).type;
					}
				}
			}
			(*global).unlock_tile(x, y);
		}

		if (!going_for_monster_interaction && !going_for_mech_activation && !same_tile)
		{
			going_for_a_walk = true;
		}



		if ( going_for_monster_interaction)
		{
			t_o_interact.player_to_monster_interaction(interaction_monster_type, x, y);
		}
		else if ( going_for_mech_activation)
		{
			t_o_interact.player_to_mechanic_interaction(interaction_mech_type, x, y);
		}
		else if (going_for_a_walk)
		{
			t_o_interact.player_going_for_a_walk(x,y);
		}



	}

	void player_right_clicked(int x, int y)
	{
		if (world_state != WORLDSTATE_NOLOAD) {return;}
		if ((*global).active_screen != SCREEN_WORLD){return;}
		if ((*global).game_pause) {return;}

		if ( util.is_same_tile(x,y, (*global).player.player_at_x_int, (*global).player.player_at_y_int))
		{
			return;
		}

		t_o_interact.player_to_teleport_to(x,y);
	}

	private:

	void wait_for_loading()
	{
		ddttime::delay(100);
		while ((*global).something_is_loading()) {ddttime::delay(10);}
		ddttime::delay(100);
		while ((*global).something_is_loading()) {ddttime::delay(10);}
		ddttime::delay(100);
		while ((*global).something_is_loading()) {ddttime::delay(10);}
		ddttime::delay(100);
		while ((*global).something_is_loading()) {ddttime::delay(10);}
	}


	void display_load_stage(int stage)
	{

		string dots = "";
		string out = "";

		if (stage < 1)
		{
			out = " ";
		}
		else
		{
			for (int i = 0; i < stage; i++)
			{
				dots.append("[bslsh][bslsh]");
			}
			out.append(dots);
			out.append("    loading    ");
			out.append(dots);
		}

		(*global).threadpush_mousekeyb(new mail(MOUSEKEYB_SET_LOADMSG, out));

	}




};
