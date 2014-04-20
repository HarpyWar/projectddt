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



#include "levk_fsy_staticsloader.cpp"
using namespace std;



class button_commando
{
	public:

	globals* global;
	mousekeyb_local* local;
	utils util;
	mail* post;
	screens_manager screen_man;

	float display_scale;
	float display_scale_inverse;
	float screen_size_x;
	float screen_size_y;


	long def_tile_off_x;
	long def_tile_off_y;

	double corrected_x;
	double corrected_y;
	double mapped_y;
	double mapped_x;
	int mapped_x_int;
	int mapped_y_int;
	double tile_relative_pointer_x;
	double tile_relative_pointer_y;



	button_commando()
	{}

	void button_commando_set(globals* glob, mousekeyb_local* loc)
	{
		global = glob;
		local = loc;

		screen_man.go_init_screens(global);

		display_scale = (ddtgrfx::find_display_scale((*global).display_w, (*global).display_h, (*global).display_zoom));
		display_scale_inverse =  1.0 / display_scale;

		screen_size_x = (*global).display_w / display_scale;
		screen_size_y = (*global).display_h / display_scale;

		def_tile_off_x = 0.5* ((*global).display_w * display_scale_inverse ) - 0.5*TILE_SCREEN_X_SIZE;
		def_tile_off_y = 0.5* ((*global).display_h * display_scale_inverse );
	}



	void command( int cmd)
	{
		if ((*global).active_screen == SCREEN_LOAD_WAIT)
		{
			return;
		}

		switch (cmd)
		{
			case BUTTON_VOID_COMMAND : break;

			//TITLE SCREEN BUTTS

			case BUTTON_GOTO_MAINMENU_COMMAND : goto_main_menu_screen(false); break;
			case BUTTON_GOTO_SETTINGS_COMMAND : goto_settings_screen(false); break;
			case BUTTON_QUIT_GAME_COMMAND : (*global).quit_game = true; break;


			case BUTTON_GAMEOPT_SELECTA_COMMAND: game_opt_butt(0); break;
			case BUTTON_GAMEOPT_SELECTB_COMMAND: game_opt_butt(1); break;
			case BUTTON_GAMEOPT_SELECTC_COMMAND: game_opt_butt(2); break;
			case BUTTON_GAMEOPT_SELECTD_COMMAND: game_opt_butt(3); break;
			case BUTTON_GAMEOPT_SELECTE_COMMAND: game_opt_butt(4); break;
			case BUTTON_GAMEOPT_SELECTF_COMMAND: game_opt_butt(5); break;
			case BUTTON_GAMEOPT_SELECTG_COMMAND: game_opt_butt(6); break;
			case BUTTON_GAMEOPT_SELECTH_COMMAND: game_opt_butt(7); break;
			case BUTTON_GAMEOPT_SCROLLUP_COMMAND: opt_scroll(true); break;
			case BUTTON_GAMEOPT_SCROLLDOWN_COMMAND: opt_scroll(false); break;

			case BUTTON_GAMEOPT_MIN_MIN_COMMAND: opt_plusmin_press(-2); break;
			case BUTTON_GAMEOPT_MIN_COMMAND: opt_plusmin_press(-1); break;
			case BUTTON_GAMEOPT_PLUS_COMMAND: opt_plusmin_press(1); break;
			case BUTTON_GAMEOPT_PLUS_PLUS_COMMAND: opt_plusmin_press(2); break;

			case BUTTON_SETTINGS_ACCEPT_COMMAND : goto_main_menu_screen_from_settings(true); break;
			case BUTTON_SETTINGS_DEF_COMMAND : goto_settings_screen(true); break;
			case BUTTON_SETTINGS_CANCEL_COMMAND : goto_main_menu_screen_from_settings(false); break;


			case BUTTON_GOTO_CREDITS_COMMAND : goto_credits_screen(); break;
			case BUTTON_GOTO_GAME_CREDITS_COMMAND : goto_version_credits_screen(0); break;
			case BUTTON_GOTO_EXPANTION_CREDITS_COMMAND :  goto_version_credits_screen(1); break;
			case BUTTON_GOTO_ENGINE_CREDITS_COMMAND : goto_version_credits_screen(2); break;

			case BUTTON_CREDITS_SCROLLUP_COMMAND : screen_man.credits_scroll_up(60.0); break;
			case BUTTON_CREDITS_SCROLLDOWN_COMMAND : screen_man.credits_scroll_down(60.0); break;
			case BUTTON_GOTO_SINGLE_PLAYER_COMMAND : goto_single_player_screen(); break;
			case BUTTON_SINGLE_PLAYER_SCROLLUP_COMMAND : single_player_scroll(true); break;
			case BUTTON_SINGLE_PLAYER_SCROLLDOWN_COMMAND : single_player_scroll(false); break;
			case BUTTON_SINGLE_PLAYER_SELECTA_COMMAND : single_player_butt(0); break;
			case BUTTON_SINGLE_PLAYER_SELECTB_COMMAND : single_player_butt(1); break;
			case BUTTON_SINGLE_PLAYER_SELECTC_COMMAND : single_player_butt(2); break;
			case BUTTON_SINGLE_PLAYER_SELECTD_COMMAND : single_player_butt(3); break;
			case BUTTON_SINGLE_PLAYER_SELECTE_COMMAND : single_player_butt(4); break;
			case BUTTON_SINGLE_PLAYER_OK_COMMAND : single_player_ok_press(); break;
			case BUTTON_SINGLE_PLAYER_DELETE_COMMAND :
				(*global).threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::def_bg()));
				(*global).active_screen = SCREEN_DELETE_CHAR;
				break;

			case BUTTON_DELETE_SCREEN_OK_COMMAND : handle_delete_char(); break;
			case BUTTON_CHOOSE_CLASS_SCROLLUP_COMMAND : class_scroll(true); break;
			case BUTTON_CHOOSE_CLASS_SCROLLDOWN_COMMAND : class_scroll(false); break;
			case BUTTON_CHOOSE_CLASS_SELECTA_COMMAND : player_class_butt(0); break;
			case BUTTON_CHOOSE_CLASS_SELECTB_COMMAND : player_class_butt(1); break;
			case BUTTON_CHOOSE_CLASS_SELECTC_COMMAND : player_class_butt(2); break;
			case BUTTON_CHOOSE_CLASS_SELECTD_COMMAND : player_class_butt(3); break;
			case BUTTON_CHOOSE_CLASS_SELECTE_COMMAND : player_class_butt(4); break;
			case BUTTON_CHOOSE_CLASS_OK_COMMAND :
				(*global).active_screen = SCREEN_ENTER_NAME;
				update_enter_name_field('@');
				break;
			case BUTTON_ENTER_NAME_CANCEL_COMMAND :
				(*global).active_screen = SCREEN_CHOOSE_CLASS;
				break;
			case BUTTON_ENTER_NAME_OK_COMMAND : handle_new_char_creation(); break;

			case BUTTON_ENTER_NAME_A_COMMAND : update_enter_name_field('a'); break;
			case BUTTON_ENTER_NAME_B_COMMAND : update_enter_name_field('b'); break;
			case BUTTON_ENTER_NAME_C_COMMAND : update_enter_name_field('c'); break;
			case BUTTON_ENTER_NAME_D_COMMAND : update_enter_name_field('d'); break;
			case BUTTON_ENTER_NAME_E_COMMAND : update_enter_name_field('e'); break;
			case BUTTON_ENTER_NAME_F_COMMAND : update_enter_name_field('f'); break;
			case BUTTON_ENTER_NAME_G_COMMAND : update_enter_name_field('g'); break;
			case BUTTON_ENTER_NAME_H_COMMAND : update_enter_name_field('h'); break;
			case BUTTON_ENTER_NAME_I_COMMAND : update_enter_name_field('i'); break;
			case BUTTON_ENTER_NAME_J_COMMAND : update_enter_name_field('j'); break;
			case BUTTON_ENTER_NAME_K_COMMAND : update_enter_name_field('k'); break;
			case BUTTON_ENTER_NAME_L_COMMAND : update_enter_name_field('l'); break;
			case BUTTON_ENTER_NAME_M_COMMAND : update_enter_name_field('m'); break;
			case BUTTON_ENTER_NAME_N_COMMAND : update_enter_name_field('n'); break;
			case BUTTON_ENTER_NAME_O_COMMAND : update_enter_name_field('o'); break;
			case BUTTON_ENTER_NAME_P_COMMAND : update_enter_name_field('p'); break;
			case BUTTON_ENTER_NAME_Q_COMMAND : update_enter_name_field('q'); break;
			case BUTTON_ENTER_NAME_R_COMMAND : update_enter_name_field('r'); break;
			case BUTTON_ENTER_NAME_S_COMMAND : update_enter_name_field('s'); break;
			case BUTTON_ENTER_NAME_T_COMMAND : update_enter_name_field('t'); break;
			case BUTTON_ENTER_NAME_U_COMMAND : update_enter_name_field('u'); break;
			case BUTTON_ENTER_NAME_V_COMMAND : update_enter_name_field('v'); break;
			case BUTTON_ENTER_NAME_W_COMMAND : update_enter_name_field('w'); break;
			case BUTTON_ENTER_NAME_X_COMMAND : update_enter_name_field('x'); break;
			case BUTTON_ENTER_NAME_Y_COMMAND : update_enter_name_field('y'); break;
			case BUTTON_ENTER_NAME_Z_COMMAND : update_enter_name_field('z'); break;
			case BUTTON_ENTER_NAME_0_COMMAND : update_enter_name_field('0'); break;
			case BUTTON_ENTER_NAME_1_COMMAND : update_enter_name_field('1'); break;
			case BUTTON_ENTER_NAME_2_COMMAND : update_enter_name_field('2'); break;
			case BUTTON_ENTER_NAME_3_COMMAND : update_enter_name_field('3'); break;
			case BUTTON_ENTER_NAME_4_COMMAND : update_enter_name_field('4'); break;
			case BUTTON_ENTER_NAME_5_COMMAND : update_enter_name_field('5'); break;
			case BUTTON_ENTER_NAME_6_COMMAND : update_enter_name_field('6'); break;
			case BUTTON_ENTER_NAME_7_COMMAND : update_enter_name_field('7'); break;
			case BUTTON_ENTER_NAME_8_COMMAND : update_enter_name_field('8'); break;
			case BUTTON_ENTER_NAME_9_COMMAND : update_enter_name_field('9'); break;
			case BUTTON_ENTER_NAME_BACK_COMMAND : update_enter_name_field('<'); break;
			case BUTTON_ENTER_NAME_USCORE_COMMAND : update_enter_name_field('_'); break;

			case BUTTON_GAMETYPE_LOAD_COMMAND : handle_gametype_selection(0); break;
			case BUTTON_GAMETYPE_NORMAL_COMMAND : handle_gametype_selection(1); break;
			case BUTTON_GAMETYPE_NIGHTMARE_COMMAND : handle_gametype_selection(2); break;
			case BUTTON_GAMETYPE_HELL_COMMAND : handle_gametype_selection(3); break;
			case BUTTON_GAMETYPE_OK_COMMAND : handle_existing_char_load(); break;


			case BUTTON_WORLD_TOGGLE_MENU_ON : screen_man.world_menu_visible(DDT_ON); break;
			case BUTTON_WORLD_TOGGLE_MENU_OFF : screen_man.world_menu_visible(DDT_OFF); break;
			case BUTTON_WORLD_TOGGLE_CHARSTATS : screen_man.world_charstats_visible(DDT_FLIP); break;
			case BUTTON_WORLD_TOGGLE_INVENTORY : screen_man.world_inventory_visible(DDT_FLIP); break;
			case BUTTON_WORLD_TOGGLE_MAP : screen_man.word_map_visible(DDT_FLIP); break;
			case BUTTON_WORLD_MAP_RIGHT : move_map(DIRECTION_E); break;
			case BUTTON_WORLD_MAP_LEFT : move_map(DIRECTION_W); break;
			case BUTTON_WORLD_MAP_UP : move_map(DIRECTION_N); break;
			case BUTTON_WORLD_MAP_DOWN : move_map(DIRECTION_S); break;
			case BUTTON_WORLD_LEAVE_GAME : goto_main_menu_screen(true); break;
			case BUTTON_WORLD_MAKE_SAVEGAME : world_make_savegame(); break;
			case BUTTON_WORLD_LOAD_SAVEGAME : handle_from_world_char_load(); break;

			case BUTTON_WORLD_STORY_SCROLL_UP : screen_man.world_story_scroll_up(25); break;
			case BUTTON_WORLD_STORY_SCROLL_DOWN : screen_man.world_story_scroll_down(25); break;
			case BUTTON_WORLD_STORY_EXIT : screen_man.world_story_exit(); break;






		}
	}


	void world_mouse_hoover_at(int screen_x, int screen_y)
	{
		if ((*global).active_screen != SCREEN_WORLD){return;}
		if ((*global).game_pause) {return;}

		di_int tile_coord = get_tile_for_mouse_at(screen_x,screen_y);

		int monref = MON_VOID;
		int mechref = TILE_MECH_VOID;
		int itemref = ITEM_TYPE_VOID;
		uint32_t itemstack = 1;

		(*global).lock_tile(tile_coord.x,tile_coord.y);
		if ( (*global).tile_exists(tile_coord.x,tile_coord.y))
		{
			(*global).tile[tile_coord.x][tile_coord.y].hoover((*global).ddt_time);
			screen_man.world_map_update_tile_select(tile_coord.x, tile_coord.y);


			(*global).tile[tile_coord.x][tile_coord.y].monsters.reset_itt();
			if((*global).tile[tile_coord.x][tile_coord.y].monsters.can_request_next())
			{
				tile_monster* tm = (*global).tile[tile_coord.x][tile_coord.y].monsters.request_next();
				monref = (*tm).type;
			}

			if ( (*global).tile[tile_coord.x][tile_coord.y].has_item)
			{

				game_item* it = (*global).tile[tile_coord.x][tile_coord.y].item;
				itemref = (*it).type;
				itemstack = (*it).stack_size;
			}

			if ( (*global).tile[tile_coord.x][tile_coord.y].has_mechanic)
			{

				tile_mechanic* tm = (*global).tile[tile_coord.x][tile_coord.y].mech;
				mechref = (*tm).type;

			}

		}
		(*global).unlock_tile(tile_coord.x,tile_coord.y);



		if ((*global).monsters.selectable(monref))
		{

			screen_man.world_hud_tooltip( (*global).monsters.mon[monref].name.get(), "", "", "", "");

		}
		else if ((*global).itemtype.exists(itemref) )
		{
			string show = "";
			if ((*global).itemtype.type[itemref].stackable)
			{
				string sstack = util.int_to_string_bignum(itemstack);
				show.append("(whi)");
				show.append(sstack);
				show.append(" ");
			}

			show.append((*global).itemtype.type[itemref].name);

			screen_man.world_hud_tooltip( show, "", "", "", "");

		}
		else if ((*global).mechanics.selectable(mechref) )
		{

			screen_man.world_hud_tooltip( (*global).mechanics.mech[mechref].name.get(), "", "", "", "");

		}
		else
		{
			screen_man.world_hud_tooltip_clear();
		}
	}

	void world_left_click(int screen_x, int screen_y)
	{
		if ((*global).active_screen != SCREEN_WORLD){return;}
		if ((*global).game_pause) {return;}

		di_int tile_coord = get_tile_for_mouse_at(screen_x,screen_y);


		post = new mail(WORLD_LEFT_CLICK, tile_coord.x, tile_coord.y);
		(*global).threadpush_world(post);
	}

	void world_right_click(int screen_x, int screen_y)
	{
		if ((*global).active_screen != SCREEN_WORLD){return;}
		if ((*global).game_pause) {return;}

		di_int tile_coord = get_tile_for_mouse_at(screen_x,screen_y);


		post = new mail(WORLD_RIGHT_CLICK, tile_coord.x, tile_coord.y);
		(*global).threadpush_world(post);
	}


	di_int get_tile_for_mouse_at(int mouse_x, int mouse_y)
	{

		corrected_x = (mouse_x - def_tile_off_x);
		corrected_y = (mouse_y - def_tile_off_y - 16);

		mapped_y = corrected_y + 0.5*corrected_x;
		mapped_x = corrected_x - mapped_y;

		mapped_x = mapped_x * 0.03125;  // 1 / 32 = 0.03125
		mapped_y = mapped_y * 0.03125;

		mapped_x = mapped_x + (*global).player.player_at_x_doub;
		mapped_y = mapped_y + (*global).player.player_at_y_doub;

		mapped_x_int = mapped_x;
		mapped_y_int = mapped_y;

		//mapped_x,y is the tile the mouse is pointing at
		//now lets find out if its pointing at the left/right and lower/upper part of the tile

		tile_relative_pointer_x = mapped_x - (double)mapped_x_int;
		tile_relative_pointer_y = mapped_y - (double)mapped_y_int;

		if ( tile_relative_pointer_x + tile_relative_pointer_y < 0.5)
		{
			//cout << "<" << endl;
			return probe_tile_for_selection(mapped_x, mapped_y-1);
		}

		if ( tile_relative_pointer_x + tile_relative_pointer_y > 1.5)
		{
			//cout << ">" << endl;
			return probe_tile_for_selection(mapped_x +1, mapped_y);
		}

		if ( tile_relative_pointer_y < tile_relative_pointer_x - 0.5)
		{
			//cout << "v" << endl;
			return probe_tile_for_selection(mapped_x + 1, mapped_y -1);
		}

		return probe_tile_for_selection(mapped_x, mapped_y);



	}

	di_int probe_tile_for_selection(int x, int y)
	{

		tri_int cur = monster_mech_item_height_for_tile(x,y);
		if ( cur.x > 0) {return di_int(x,y);} //monster is here

		tri_int lower = monster_mech_item_height_for_tile(x+1,y-1);
		if ( lower.x > 1) {return di_int(x+1,y-1); } //monster is one tile lower

		tri_int lowest = monster_mech_item_height_for_tile(x+2,y-2);
		if ( lowest.x > 2) {return di_int(x+2,y-2);} //monster is 2 tiles lower

		if ( cur.z > 0) {return di_int(x,y);} //item is here

		if ( cur.y > 0) {return di_int(x,y);} //mechanic is here
		if ( lower.y > 1) {return di_int(x+1,y-1);} //mechanic is one tile_lower
		if ( lowest.y > 2) {return di_int(x+2,y-2);} //mehcanic is 2 tiles lower

		return di_int(x,y); //no adjustments needed

	}

	tri_int monster_mech_item_height_for_tile(int x, int y)
	{
		int mon_hi = 0;
		int mech_hi = 0;
		int item_hi = 0;

		(*global).lock_tile(x,y);
		if ( (*global).tile_exists(x,y))
		{

			(*global).tile[x][y].monsters.reset_itt();
			if ( (*global).tile[x][y].monsters.can_request_next())
			{
				tile_monster* tmon = (*global).tile[x][y].monsters.request_next();
				int monref = (*tmon).type;

				if ((*global).monsters.exists(monref))
				{
					mon_hi = (*global).monsters.mon[monref].selection_height;
				}

			}
			if ( (*global).tile[x][y].has_mechanic)
			{

				tile_mechanic* tmech = (*global).tile[x][y].mech;
				int mechref = (*tmech).type;

				if ((*global).mechanics.exists(mechref))
				{
					mech_hi = (*global).mechanics.mech[mechref].selection_height;
				}
			}

			if ( (*global).tile[x][y].has_item)
			{
				item_hi = 1;
			}
		}
		(*global).unlock_tile(x,y);

		return tri_int(mon_hi, mech_hi, item_hi);
	}


	void goto_main_menu_screen(bool reboot_music)
	{
		(*global).threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::def_bg()));
		(*global).active_screen = SCREEN_MAIN_MENU;

		if (reboot_music)
		{
			(*global).threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::intro_music()));
		}
	}

	void goto_main_menu_screen_from_settings(bool settings_accepted)
	{
		if (settings_accepted)
		{
			post = new mail(FILEIO_WRITE_CONFIG);
			(*global).threadpush_filesystem(post);
			(*global).music_volume_rollback =  (*global).music_volume;
			(*global).sfx_volume_rollback =  (*global).sfx_volume;
			(*global).autosave_rollback =  (*global).autosave;
		}
		else
		{
			(*global).display_w_nexttime = (*global).display_w;
			(*global).display_h_nexttime = (*global).display_h;
			(*global).display_zoom_nexttime = (*global).display_zoom;
			(*global).display_gamma_nexttime = (*global).display_gamma;
			(*global).hud_transp_nexttime = (*global).hud_transp;
			(*global).sfx_volume = (*global).sfx_volume_rollback;
			(*global).music_volume = (*global).music_volume_rollback;
			(*global).autosave = (*global).autosave_rollback;
			(*global).blending_nexttime = (*global).blending;

		}

		goto_main_menu_screen(false);
	}

	void goto_settings_screen(bool reset_defaults)
	{
		if (reset_defaults)
		{
			(*global).display_w_nexttime = 640;
			(*global).display_h_nexttime = 480;
			(*global).display_zoom_nexttime = 10;
			(*global).display_gamma_nexttime = 0;
			(*global).hud_transp_nexttime = 7;
			(*global).sfx_volume = 10;
			(*global).music_volume = 7;
			(*global).autosave = true;
			(*global).blending_nexttime = true;
		}

		(*local).opt_scroller = 0;
		game_opt_butt(0);
		update_opt_lines();
		(*global).active_screen = SCREEN_SETTINGS_MENU;
	}

	void goto_credits_screen()
	{
		(*global).threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::def_bg()));
		screen_man.credits_reset_scroller();
		(*global).active_screen = SCREEN_CREDITS_SELECT_MENU;
	}

	void goto_version_credits_screen(int choise)
	{
		if (choise == 0){(*global).threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::cred_diab()));}
		else if (choise == 1){(*global).threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::cred_hf()));}
		else if (choise == 2){(*global).threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::cred_ddt()));}
		(*global).active_screen = SCREEN_GAME_CREDITS;
	}

	void game_opt_butt(int butt)
	{
		int oursel = (*local).opt_scroller + butt;
		if (oursel > -1 && oursel <  OPT_COUNT)
		{
			(*local).opt_selected =  (*local).opt_scroller + butt;
			update_opt_selected();
		}
	}

	void update_opt_selected()
	{
		screen_man.settings_set_button_active_color((*local).opt_selected  - (*local).opt_scroller);
		screen_man.settings_set_option_discription((*local).opt_selected);

		opt_plusmin_press(0); // 0 being the neutral option where nothing changes

	}

	void opt_plusmin_press(int key)
	{
		if ((*local).opt_selected ==  OPT_WIDTH)
		{
			if      (key == -2) { (*global).display_w_nexttime = (*global).display_w_nexttime - 30;}
			else if (key == -1) { (*global).display_w_nexttime = (*global).display_w_nexttime -  1;}
			else if (key ==  1) { (*global).display_w_nexttime = (*global).display_w_nexttime +  1;}
			else if (key ==  2) { (*global).display_w_nexttime = (*global).display_w_nexttime + 30;}

			if ((*global).display_w_nexttime > MAX_WIDTH) { (*global).display_w_nexttime = MAX_WIDTH;}
			if ((*global).display_w_nexttime < ORIGINAL_WIDTH) { (*global).display_w_nexttime = ORIGINAL_WIDTH;}

			string optn = util.int_to_string_no_leading_zero((*global).display_w_nexttime);
			screen_man.settings_set_option_value(optn);
		}
		else if ((*local).opt_selected ==  OPT_HEIGHT)
		{
			if      (key == -2) { (*global).display_h_nexttime = (*global).display_h_nexttime - 30;}
			else if (key == -1) { (*global).display_h_nexttime = (*global).display_h_nexttime -  1;}
			else if (key ==  1) { (*global).display_h_nexttime = (*global).display_h_nexttime +  1;}
			else if (key ==  2) { (*global).display_h_nexttime = (*global).display_h_nexttime + 30;}

			if ((*global).display_h_nexttime > MAX_HEIGHT) { (*global).display_h_nexttime = MAX_HEIGHT;}
			if ((*global).display_h_nexttime < ORIGINAL_HEIGHT) { (*global).display_h_nexttime = ORIGINAL_HEIGHT;}

			string optn = util.int_to_string_no_leading_zero((*global).display_h_nexttime);
			screen_man.settings_set_option_value(optn);
		}
		else if ((*local).opt_selected ==  OPT_ZOOM)
		{
			if      (key == -2) { (*global).display_zoom_nexttime = (*global).display_zoom_nexttime - 10;}
			else if (key == -1) { (*global).display_zoom_nexttime = (*global).display_zoom_nexttime -  1;}
			else if (key ==  1) { (*global).display_zoom_nexttime = (*global).display_zoom_nexttime +  1;}
			else if (key ==  2) { (*global).display_zoom_nexttime = (*global).display_zoom_nexttime + 10;}

			if ((*global).display_zoom_nexttime > 10) { (*global).display_zoom_nexttime = 10;}
			if ((*global).display_zoom_nexttime < 0) { (*global).display_zoom_nexttime = 0;}

			string optn = util.int_to_string_no_leading_zero((*global).display_zoom_nexttime);
			screen_man.settings_set_option_value(optn);
		}

		else if ((*local).opt_selected ==  OPT_BLEND)
		{
			if      ((key == -2) || (key == -1)) { (*global).blending_nexttime = false;}
			else if ((key ==  1) || (key ==  2)) { (*global).blending_nexttime = true;}


			if ((*global).blending_nexttime)
			{
				screen_man.settings_set_option_value("on");
			}
			else
			{
				screen_man.settings_set_option_value("off");
			}
		}

		else if ((*local).opt_selected ==  OPT_GAMMA)
		{
			if      (key == -2) { (*global).display_gamma_nexttime = (*global).display_gamma_nexttime - 10;}
			else if (key == -1) { (*global).display_gamma_nexttime = (*global).display_gamma_nexttime -  1;}
			else if (key ==  1) { (*global).display_gamma_nexttime = (*global).display_gamma_nexttime +  1;}
			else if (key ==  2) { (*global).display_gamma_nexttime = (*global).display_gamma_nexttime + 10;}

			if ((*global).display_gamma_nexttime > 10) { (*global).display_gamma_nexttime = 10;}
			if ((*global).display_gamma_nexttime < 0) { (*global).display_gamma_nexttime = 0;}

			string optn = util.int_to_string_no_leading_zero((*global).display_gamma_nexttime);
			screen_man.settings_set_option_value(optn);
		}
		else if ((*local).opt_selected ==  OPT_ALPHA)
		{
			if      (key == -2) { (*global).hud_transp_nexttime = (*global).hud_transp_nexttime - 10;}
			else if (key == -1) { (*global).hud_transp_nexttime = (*global).hud_transp_nexttime -  1;}
			else if (key ==  1) { (*global).hud_transp_nexttime = (*global).hud_transp_nexttime +  1;}
			else if (key ==  2) { (*global).hud_transp_nexttime = (*global).hud_transp_nexttime + 10;}

			if ((*global).hud_transp_nexttime > 10) { (*global).hud_transp_nexttime = 10;}
			if ((*global).hud_transp_nexttime < 0) { (*global).hud_transp_nexttime = 0;}

			string optn = util.int_to_string_no_leading_zero((*global).hud_transp_nexttime);
			screen_man.settings_set_option_value(optn);
		}
		else if ((*local).opt_selected ==  OPT_SOUND)
		{
			int val = 0;
			if      (key == -2) { val = (*global).sfx_volume - 10;}
			else if (key == -1) { val = (*global).sfx_volume -  1;}
			else if (key ==  1) { val = (*global).sfx_volume +  1;}
			else if (key ==  2) { val = (*global).sfx_volume + 10;}
			else { val = (*global).sfx_volume;}

			if      (val > 10) { (*global).sfx_volume = 10; }
			else if (val <  0) { (*global).sfx_volume = 0;  }
			else               { (*global).sfx_volume = val;}
			string optn = util.int_to_string_no_leading_zero((*global).sfx_volume);
			screen_man.settings_set_option_value(optn);
		}
		else if ((*local).opt_selected ==  OPT_MUSIC)
		{
			int val = 0;
			if      (key == -2) { val = (*global).music_volume - 10;}
			else if (key == -1) { val = (*global).music_volume -  1;}
			else if (key ==  1) { val = (*global).music_volume +  1;}
			else if (key ==  2) { val = (*global).music_volume + 10;}
			else { val = (*global).music_volume;}

			if      (val > 10) { (*global).music_volume = 10; }
			else if (val <  0) { (*global).music_volume = 0;  }
			else               { (*global).music_volume = val;}

			string optn = util.int_to_string_no_leading_zero((*global).music_volume);
			screen_man.settings_set_option_value(optn);
		}

		else if ((*local).opt_selected ==  OPT_AUTOSAVE)
		{
			if      (key == -2) { (*global).autosave = false; }
			else if (key == -1) { (*global).autosave = false; }
			else if (key ==  1) { (*global).autosave = true; }
			else if (key ==  2) { (*global).autosave = true; }

			if ((*global).autosave) {screen_man.settings_set_option_value("on");}
			else {screen_man.settings_set_option_value("off");}

		}

	}

	void opt_scroll(bool up)
	{
		if (up)
		{
			if ((*local).opt_scroller > 0){ (*local).opt_scroller --;}
			if ((*local).opt_selected > 0){ (*local).opt_selected--; }
		}
		else // (down)
		{
			if ( (*local).opt_scroller <  OPT_COUNT - UI_OPT_BUTTON_COUNT){ (*local).opt_scroller++;}
			if ((*local).opt_selected <  OPT_COUNT - 1){(*local).opt_selected++;}
		}
		update_opt_selected();
		update_opt_lines();
	}

	void update_opt_lines()
	{
		for (int i = 0; i < UI_OPT_BUTTON_COUNT ; i++)
		{
			screen_man.settings_set_option_line(i, "");

			int our_optline_no = i + (*local).opt_scroller;
			if ( (our_optline_no > -1) && (our_optline_no < OPT_COUNT))
			{
				string our_optline = (*local).opt_name[our_optline_no];
				screen_man.settings_set_option_line(i, our_optline);
			}
		}
	}


	void single_player_butt(int butt)
	{
		int oursel = (*local).savegame_scroller + butt;
		if (oursel > -1 && oursel <  (*local).savegame_count)
		{
			(*local).selected_savegame = (*local).savegame_scroller + butt;
			update_savegame_selected();
		}
	}

	void player_class_butt(int butt)
	{
		int oursel = (*local).class_scroller + butt;
		if (oursel > -1 && oursel <  (*local).player_class_count)
		{
			(*local).selected_class = (*local).class_scroller + butt;
			update_class_selected();
		}
	}

	void single_player_scroll(bool up)
	{
		if (up)
		{
			if ( (*local).savegame_scroller > 0){(*local).savegame_scroller --;}
			if ((*local).selected_savegame > 0){(*local).selected_savegame--;}
		}
		else // (down)
		{
			if ( (*local).savegame_scroller < (*local).savegame_count - UI_SAVE_BUTTON_COUNT){(*local).savegame_scroller++;}
			if ((*local).selected_savegame  < (*local).savegame_count - 1){(*local).selected_savegame++; }
		}
		update_savelist_lines();
		update_savegame_selected();
	}

	void goto_single_player_screen()
	{
		(*global).threadpush_filesystem(new mail(FILEIO_GET_SAFELIST));
		(*global).threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::gameselect_bg()));
		(*local).savegame_scroller = 0;
		(*local).selected_savegame = 0;
		update_savegame_selected();
		update_savelist_lines();
		(*global).active_screen = SCREEN_SINGE_PLAYER;
	}

	void goto_class_choice_screen()
	{
		// we selected New Hero
		(*local).class_scroller = 0;
		(*local).selected_class = 0;
		update_class_selected();
		update_classlist_lines();
		(*global).active_screen = SCREEN_CHOOSE_CLASS;
	}

	void single_player_ok_press()
	{
		if ( (*local).selected_savegame == (*local).savegame_count -1)
		{
			goto_class_choice_screen();
		}
		else
		{
			handle_gametype_selection(-1);
		}
	}

	void class_scroll(bool up)
	{
		if (up)
		{
			if ((*local).class_scroller > 0){ (*local).class_scroller --;}
			if ((*local).selected_class > 0){ (*local).selected_class--; }
		}
		else // (down)
		{
			if ( (*local).class_scroller < (*local).player_class_count - UI_CLASS_BUTTON_COUNT){ (*local).class_scroller++;}
			if ((*local).selected_class <  (*local).player_class_count - 1){(*local).selected_class++;}
		}
		 update_classlist_lines();
		 update_class_selected();
	}

	void update_savelist_lines()
	{
		for (int i = 0; i < UI_SAVE_BUTTON_COUNT ; i++)
		{
			screen_man.sp_set_name_line(i, "");

			int our_saveline_no = i + (*local).savegame_scroller;
			if ( (our_saveline_no > -1) && (our_saveline_no < (*local).savegame_count))
			{
				string our_saveline =  (*local).savegame[our_saveline_no];
				screen_man.sp_set_name_line(i,our_saveline);
			}
		}
	}

	void update_classlist_lines()
	{
		for (int i = 0; i < UI_CLASS_BUTTON_COUNT ; i++)
		{
			screen_man.class_set_name_line(i, "");

			int our_classline_no = i + (*local).class_scroller;
			if ( (our_classline_no > -1) && (our_classline_no < (*local).player_class_count))
			{
				string our_classline = (*local).player_class_name[our_classline_no];
				screen_man.class_set_name_line(i, our_classline);
			}
		}
	}


	void update_savegame_selected()
	{


		int new_char_portrait_y = 3;
		string new_char_tagline = "hero";

		if ((*global).game_mode == GAME_MODE_EXP)
		{
			new_char_portrait_y = 5;
			new_char_tagline = "Hellfire hero";
		}

		for (int i = 0; i <  UI_SAVE_BUTTON_COUNT; i++)
		{

			if ( i == (*local).selected_savegame  - (*local).savegame_scroller)
			{
				screen_man.sp_set_button_active_color(i);

				if ((*local).savegame_count > (*local).selected_savegame)
				{
					if ( (*local).selected_savegame == (*local).savegame_count -1) // new hero
					{

						screen_man.multi_set_char_portrait_y( new_char_portrait_y); //new hero portrait
						screen_man.sp_set_new_hero_discription();
						screen_man.sp_set_delete_active(false);
					}

					else // a real save
					{
						if (  (*local).savegame_class[(*local).selected_savegame] > -1 && (*local).savegame_class[(*local).selected_savegame] < (*local).player_class_count)
						{

							int portrait_tag = (*local).player_class_portrait_y[(*local).savegame_class[(*local).selected_savegame]];
							screen_man.multi_set_char_portrait_y( portrait_tag);

							int sav_exp =   (*local).savegame_expantion_status[(*local).selected_savegame] ;
							string sav_char_name = (*local).savegame[(*local).selected_savegame] ;
							string sav_class_name = (*local).player_class_name[(*local).savegame_class[(*local).selected_savegame]];
							int sav_lev = (*local).savegame_level[(*local).selected_savegame]; //level
							int sav_diff = (*local).savegame_diff[(*local).selected_savegame];
							int sav_stars = (*local).savegame_stars[(*local).selected_savegame];

							screen_man.multi_set_save_discription(sav_exp, sav_class_name, sav_char_name, sav_lev, sav_diff, sav_stars);
							screen_man.sp_set_delete_active(true);

						}
					}
				}
			}
		}
	}


	void update_class_selected()
	{

		for (int i = 0; i <  UI_CLASS_BUTTON_COUNT; i++)
		{

			if ( i == (*local).selected_class  - (*local).class_scroller)
			{
				screen_man.class_set_button_active_color(i);

				if ((*local).player_class_count > (*local).selected_class)
				{
					screen_man.multi_set_char_portrait_y((*local).player_class_portrait_y[(*local).selected_class]);
					screen_man.multi_set_class_tagline(
							(*local).player_class_name[(*local).selected_class],
							(*local).player_class_tagline[(*local).selected_class]);

				}
			}
		}
	}



	void update_enter_name_field(unsigned char c)
	{
		(*local).entered_char_name.add(c);
		screen_man.name_set_input_field( (*local).entered_char_name.give_with_cursor() );
	}

	void handle_gametype_selection(int option)
	{

		if (option < 0 || option > 3)
		{
			(*global).threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::gametype_bg()));
			(*global).active_screen = SCREEN_SELECT_GAMETYPE;
			handle_gametype_selection(0);
			return;
		}

		if ((*local).selected_savegame < 0 || (*local).selected_savegame > (*local).savegame_count -1) {return;}

		int stars = (*local).savegame_stars[(*local).selected_savegame];
		int save_exp_stat = (*local).savegame_expantion_status[(*local).selected_savegame];
		int opt = option;

		if ((option == 0) && (save_exp_stat != (*global).game_mode)) { opt = 1;}
		else if ((option == 2) && (stars < 1)) { opt = 1;}
		else if ((option == 3) && (stars < 2)) { opt = 1;}

		(*local).selected_game_type = opt;
		screen_man.gametype_set_allowed( stars, save_exp_stat );
		screen_man.gametype_set_button_active(opt);

	}

	void handle_new_char_creation()
	{
		if ((*local).entered_char_name.size < 2)
		{
			screen_man.name_set_input_field("name too short");
			return;
		}
		bool err;
		err = (*local).entered_char_name.exists_in_this_list((*local).savegame_count ,(*local).savegame);
		if (err)
		{
			screen_man.name_set_input_field("name conflict");
			return;
		}




		(*global).player.char_name.set((*local).entered_char_name.give());
		(*global).player.class_number = (*local).selected_class;
		(*global).player.char_class.set((*local).player_class_name[(*local).selected_class]);
		(*global).player.char_class_path.set((*local).player_class_path[(*local).selected_class]);
		(*global).game_diff = GAME_DIFF_NORMAL;
		(*global).ondisk_savegame_mode = (*global).game_mode;
		(*global).ondisk_savegame_dunno = LEVEL_TOWN;



		(*global).active_screen = SCREEN_LOAD_WAIT;
		post = new mail( WORLD_START_CHAIN_NEWCHAR);
		(*global).threadpush_world(post);
	}

	void handle_existing_char_load()
	{
		if ( (*local).selected_savegame < 0) {return;}
		if ( (*local).selected_savegame > (*local).savegame_count -1) {return;}

		if ( (*local).savegame_class[(*local).selected_savegame]  < 0 ) {return;}
		if ( (*local).savegame_class[(*local).selected_savegame]  >  (*local).player_class_count -1 ) {return;}

		(*global).active_screen = SCREEN_LOAD_WAIT;

		(*global).player.char_name.set( (*local).savegame[(*local).selected_savegame]);
		(*global).player.class_number = (*local).savegame_class[(*local).selected_savegame];
		(*global).player.char_class.set((*local).player_class_name[(*local).savegame_class[(*local).selected_savegame]]);
		(*global).player.char_class_path.set((*local).player_class_path[(*local).savegame_class[(*local).selected_savegame]]);
		(*global).ondisk_savegame_mode = (*local).savegame_expantion_status[(*local).selected_savegame];


		if ( (*local).selected_game_type == 0)
		{
			(*global).game_diff =  (*local).savegame_diff[(*local).selected_savegame];
			(*global).ondisk_savegame_dunno = (*local).savegame_active_dungeon[(*local).selected_savegame];
			(*global).threadpush_world(new mail( WORLD_START_CHAIN_OLDGAME));
		}
		else if  ( (*local).selected_game_type == 3)
		{
			(*global).game_diff =  GAME_DIFF_HELL;
			(*global).threadpush_world(new mail( WORLD_START_CHAIN_NEWGAME));
		}
		else if ( (*local).selected_game_type == 2)
		{
			(*global).game_diff =  GAME_DIFF_NIGHTMARE;
			(*global).threadpush_world(new mail( WORLD_START_CHAIN_NEWGAME));
		}
		else // if  ( (*local).selected_game_type == 1)
		{
			(*global).game_diff =  GAME_DIFF_NORMAL;
			(*global).threadpush_world(new mail( WORLD_START_CHAIN_NEWGAME));
		}

	}

	void handle_from_world_char_load()
	{
		if ((*global).active_screen != SCREEN_WORLD) {return;}

		(*global).active_screen = SCREEN_LOAD_WAIT;
		screen_man.world_menu_visible(false);
		(*global).threadpush_world(new mail( WORLD_START_CHAIN_OLDGAME));
	}

	void world_make_savegame()
	{
		if ((*global).active_screen != SCREEN_WORLD) {return;}
		//(*global).active_screen = SCREEN_LOAD_WAIT;
		(*global).game_pause = true;


		(*global).threadpush_world(new mail(WORLD_MAKE_SAVEGAME));
		screen_man.world_menu_visible(false);
	}




	void handle_delete_char()
	{
		if ((*local).selected_savegame > -1 && (*local).selected_savegame < (*local).savegame_count -1 ) // -1 is for the new hero
		{
			string nom = (*local).savegame[(*local).selected_savegame];
			int gmode = (*local).savegame_expantion_status[(*local).selected_savegame];
			(*global).threadpush_filesystem(new mail(FILEIO_DELETE_SAVE, gmode, nom));
			goto_main_menu_screen(false);
		}
	}


	void move_map(int direction)
	{
		int x_perc = (*global).player.map_move_x_percent;
		int y_perc = (*global).player.map_move_y_percent;
		float x_pix = 0.0;
		float y_pix = 0.0;

		switch(direction)
		{
			case DIRECTION_E: x_perc = x_perc + 15; break;
			case DIRECTION_W: x_perc = x_perc - 15; break;
			case DIRECTION_N: y_perc = y_perc + 15; break;
			case DIRECTION_S: y_perc = y_perc - 15; break;
		}

		if (x_perc < -90){x_perc = -90;}
		if (x_perc >  90){x_perc =  90;}
		if (y_perc < -90){y_perc = -90;}
		if (y_perc >  90){y_perc =  90;}

		x_pix = x_pix + (0.01 * (float)x_perc * 0.5 * screen_size_x);
		y_pix = y_pix + (0.01 * (float)y_perc * 0.5 * screen_size_y);

		(*global).player.map_move_x_percent = x_perc;
		(*global).player.map_move_y_percent = y_perc;
		(*global).player.map_move_x_pix = x_pix;
		(*global).player.map_move_y_pix = y_pix;

	}











};
