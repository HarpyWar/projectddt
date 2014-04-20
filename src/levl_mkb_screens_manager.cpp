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



#include "levm_mul_tile_operations.cpp"
using namespace std;


class screens_manager
{
	globals* global;
	utils util;

	public:

	void go_init_screens(globals* glob)
	{

		global = glob;

		int game_mode = (*global).game_mode;
		float display_scale = ddtgrfx::find_display_scale((*global).display_w, (*global).display_h, (*global).display_zoom);
		float screen_size_x = (float)(*global).display_w / display_scale;
		float screen_size_y = (float)(*global).display_h / display_scale;
		float hud_alpha = util.find_hud_transparency((*global).hud_transp);

		di_float backdrop = util.find_backdrop_anchor(screen_size_x, screen_size_y);
		di_float charstat = util.find_charstat_anchor(screen_size_x, screen_size_y);
		di_float inventory = util.find_inventory_anchor(screen_size_x, screen_size_y);


		int logo_medium = LOGO_MEDIUM;
		int logo_big = LOGO_BIG;
		int intro_backdrop_no = 0;
		string intro_string = (*global).binblob.get_notice();
		string diab_cred = "$s01$<cen>{30g}";
		string hf_cred = "$s01$<cen>{30s}";
		bool hf_active = false;
		string exit_string = "$s01$<cen>{30g}Exit ";


		if (game_mode == GAME_MODE_EXP)
		{
			logo_medium = LOGO_SMALL;
			logo_big = VOID_TEXTURE;
			intro_backdrop_no = IDLE_ANIMATED;
			intro_string = " ";
			hf_cred = "$s01$<cen>{30g}";
			hf_active = true;
		}

		diab_cred.append((*global).binblob.get_game_name(GAME_MODE_CLASSIC));
		diab_cred.append(" Credits");
		hf_cred.append((*global).binblob.get_game_name(GAME_MODE_EXP));
		hf_cred.append(" Credits");
		exit_string.append((*global).binblob.get_game_name(game_mode));


		(*global).active_screen = SCREEN_TITLE; // = 0

		// some measures to shorten upcomming code lines
		ui_screen* scrp; // pointer to the current working screen
		ui_subscreen* subscrp; // pointer to the current working subscreen


		//the red intro screen with the biggest flaming letters SCREEN_TITLE must be 0
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_TITLE]);
		(*scrp).init(1);
		subscrp = &((*global).screen[SCREEN_TITLE].subscreen[0]);

		(*scrp).backdrop.set(backdrop.x, backdrop.y, BACKDROP, intro_backdrop_no);
		(*subscrp).init(1,0,1,0,0); //(int txtlines, int fields, int bttns, int doods, int borders)

		(*subscrp).anchor_x = backdrop.x;
		(*subscrp).anchor_y = backdrop.y;
		(*subscrp).streching_x = 640;
		(*subscrp).streching_y = 480;

		(*subscrp).button[0].set(0, 0, 640, 480, BUTTON_GOTO_MAINMENU_COMMAND, false, VOID_SOUND, SOUND_SELECT );
		(*subscrp).button[0].idle_grfx.set(320, 75, logo_big, IDLE_ANIMATED);

		(*subscrp).textline[0].set(44, 0.5*ORIGINAL_WIDTH, 50, "$s01$<cen>{24s}Intro txt goes here");
		(*subscrp).textline[0].reset(intro_string);






		//the main menu SCREEN_MAIN_MENU must be 1
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_MAIN_MENU]);
		(*scrp).init(1);
		subscrp = &((*global).screen[SCREEN_MAIN_MENU].subscreen[0]);

		(*scrp).backdrop.set(backdrop.x, backdrop.y, BACKDROP, 0);

		(*subscrp).init(6,0,5,1,0); //(int txtlines, int fields, int bttns, int doods, int borders)
		(*subscrp).anchor_x = backdrop.x;
		(*subscrp).anchor_y = backdrop.y;
		(*subscrp).streching_x = 640;
		(*subscrp).streching_y = 480;

		string vers = "$s01${sma}(sil) ";
		vers.append(ddtrules::program_name_and_version());

		(*subscrp).textline[0].set(50, 20, 20, vers);
		(*subscrp).textline[1].set(13, 320, 250, "$s01$<cen>{30g}Single Player");
		(*subscrp).textline[2].set(13, 320, 215, "$s01$<cen>{30g}Game Settings");
		(*subscrp).textline[3].set( 6, 320, 180, "$s01$<cen>{30s}Video");
		(*subscrp).textline[4].set(12, 320, 145, "$s01$<cen>{30g}Show Credits");
		(*subscrp).textline[5].set(13, 320, 110, exit_string);

		(*subscrp).doodad[0].set(320, 310, logo_medium, IDLE_ANIMATED);

		// single player button
		(*subscrp).button[0].set(0, 250, 640, 25, BUTTON_GOTO_SINGLE_PLAYER_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[0].mouseover_grfx_a.set(320 - 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[0].mouseover_grfx_b.set(320 + 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[0].is_selected = true;
		// game settings button
		(*subscrp).button[1].set(0, 215, 640, 25, BUTTON_GOTO_SETTINGS_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[1].mouseover_grfx_a.set(320 - 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[1].mouseover_grfx_b.set(320 + 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		// videos button
		(*subscrp).button[2].set(0, 180, 640, 25, BUTTON_VOID_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[2].mouseover_grfx_a.set(320 - 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[2].mouseover_grfx_b.set(320 + 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[2].is_visisble = false; //disable for now
		// credits button
		(*subscrp).button[3].set(0, 145, 640, 25, BUTTON_GOTO_CREDITS_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[3].mouseover_grfx_a.set(320 - 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[3].mouseover_grfx_b.set(320 + 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		// exit button
		(*subscrp).button[4].set(0, 110, 640, 25, BUTTON_QUIT_GAME_COMMAND, true, SOUND_MOVE, VOID_SOUND );
		(*subscrp).button[4].mouseover_grfx_a.set(320 - 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[4].mouseover_grfx_b.set(320 + 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);



		//the SCREEN_SETTINGS_MENU must be 2
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_SETTINGS_MENU]);
		(*scrp).init(1);
		subscrp = &((*global).screen[SCREEN_SETTINGS_MENU].subscreen[0x00]);

		(*scrp).backdrop.set(backdrop.x, backdrop.y, BACKDROP, 0);

		(*subscrp).init(17,1,17,1,4); //(int txtlines, int fields, int bttns, int doods, int borders)
		(*subscrp).anchor_x = backdrop.x;
		(*subscrp).anchor_y = backdrop.y;
		(*subscrp).streching_x = 640;
		(*subscrp).streching_y = 480;

		(*subscrp).border[0].set( 20, 50, 26, 25);
		(*subscrp).border[1].set(330, 50, 26, 25);
		(*subscrp).border[2].set_center(163, 220, 24, 0);
		(*subscrp).border[3].set_center(163, 253, 24, 0);

		(*subscrp).doodad[0].set(320, 370, LOGO_SMALL, IDLE_ANIMATED);

		(*subscrp).textfield[0].init(163, 65, 1, 150, 10, 44);
		(*subscrp).textfield[0].format(5, 10, "$s01${sma}(sil)<cen>bla"); //$s01$<cen>{30s}


		(*subscrp).textline[0].set(20, 467, 285, "$s01$<cen>{24g} "); //the scroller lines
		(*subscrp).textline[1].set(20, 467, 255, "$s01$<cen>{24g} ");
		(*subscrp).textline[2].set(20, 467, 225, "$s01$<cen>{24g} ");
		(*subscrp).textline[3].set(20, 467, 195, "$s01$<cen>{24g} ");
		(*subscrp).textline[4].set(20, 467, 165, "$s01$<cen>{24g} ");
		(*subscrp).textline[5].set(20, 467, 135, "$s01$<cen>{24g} ");
		(*subscrp).textline[6].set(20, 467, 105, "$s01$<cen>{24g} ");
		(*subscrp).textline[7].set(20, 467,  75, "$s01$<cen>{24g} ");


		(*subscrp).textline[8].set(15, 320, 340, "$s01$<cen>{30s}Game Settings");
		(*subscrp).textline[9].set(8, 320 -160, 20, "$s00$<cen>{30g}Accept");
		(*subscrp).textline[10].set(8, 320   +0, 20, "$s00$<cen>{30g}Defaults");
		(*subscrp).textline[11].set(8, 320 +160, 20, "$s00$<cen>{30g}Cancel");

		(*subscrp).textline[12].set(4, 163, 275, "$s01$<cen>{30s}1000");

		(*subscrp).textline[13].set(2,  72, 222, "$s01$<cen>{42g}--");
		(*subscrp).textline[14].set(2, 133, 222, "$s01$<cen>{42g}-");
		(*subscrp).textline[15].set(2, 193, 222, "$s01$<cen>{42g}+");
		(*subscrp).textline[16].set(2, 253, 222, "$s01$<cen>{42g}++");

		// choice A butt
		(*subscrp).button[0].set(365, 280, 205, 30, BUTTON_GAMEOPT_SELECTA_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[0].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[0].mouseover_grfx_b.set( 220, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice B butt
		(*subscrp).button[1].set(365, 250, 205, 30, BUTTON_GAMEOPT_SELECTB_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[1].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[1].mouseover_grfx_b.set( 220, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice C butt
		(*subscrp).button[2].set(365, 220, 205, 30, BUTTON_GAMEOPT_SELECTC_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[2].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[2].mouseover_grfx_b.set( 220, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice D butt
		(*subscrp).button[3].set(365, 190, 205, 30, BUTTON_GAMEOPT_SELECTD_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[3].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[3].mouseover_grfx_b.set( 220, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice E butt
		(*subscrp).button[4].set(365, 160, 205, 30, BUTTON_GAMEOPT_SELECTE_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[4].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[4].mouseover_grfx_b.set( 220, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice F butt
		(*subscrp).button[5].set(365, 130, 205, 30, BUTTON_GAMEOPT_SELECTF_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[5].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[5].mouseover_grfx_b.set( 220, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice G butt
		(*subscrp).button[6].set(365, 100, 205, 30, BUTTON_GAMEOPT_SELECTG_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[6].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[6].mouseover_grfx_b.set( 220, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice H butt
		(*subscrp).button[7].set(365,  70, 205, 30, BUTTON_GAMEOPT_SELECTH_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[7].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[7].mouseover_grfx_b.set( 220, 5, PENTA_SMALL, IDLE_ANIMATED);
		// accept
		(*subscrp).button[8].set(110, 20, 100, 25, BUTTON_SETTINGS_ACCEPT_COMMAND, true, SOUND_MOVE, SOUND_SELECT);
		(*subscrp).button[8].mouseover_grfx_a.set(-10, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[8].mouseover_grfx_b.set(110, 0, PENTA_SMALL, IDLE_ANIMATED);
		// defs
		(*subscrp).button[9].set(255, 20, 130, 25, BUTTON_SETTINGS_DEF_COMMAND, true, SOUND_MOVE, SOUND_SELECT);
		(*subscrp).button[9].mouseover_grfx_a.set(-10, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[9].mouseover_grfx_b.set(140, 0, PENTA_SMALL, IDLE_ANIMATED);
		// cancel
		(*subscrp).button[10].set(430, 20, 100, 25, BUTTON_SETTINGS_CANCEL_COMMAND, true, SOUND_MOVE, SOUND_SELECT);
		(*subscrp).button[10].mouseover_grfx_a.set(-10, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[10].mouseover_grfx_b.set(110, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[10].is_selected = true;
		// scroll down button
		(*subscrp).button[11].set(596, 47, 24, 24, BUTTON_GAMEOPT_SCROLLDOWN_COMMAND, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[11].idle_grfx.set(6, 6, SCROLL_BAR, 8); //assuming the big scroll grfx is at 10
		(*subscrp).button[11].mouseover_grfx_a.set(6, 6, SCROLL_BAR, 10);
		// scroll up button
		(*subscrp).button[12].set(596, 305, 24, 24, BUTTON_GAMEOPT_SCROLLUP_COMMAND, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[12].idle_grfx.set(6, 6, SCROLL_BAR, 9); //assuming the big scroll grfx is at 10
		(*subscrp).button[12].mouseover_grfx_a.set(6, 6, SCROLL_BAR, 11);
		// -- butt
		(*subscrp).button[13].set(45, 225, 55, 25, BUTTON_GAMEOPT_MIN_MIN_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[13].mouseover_grfx_a.set( 0, 5, PENTA_SMALLEST, IDLE_ANIMATED);
		(*subscrp).button[13].mouseover_grfx_b.set( 55, 5, PENTA_SMALLEST, IDLE_ANIMATED);
		//(*subscrp).button[13].set_color(1,1,1,0.2);
		// - butt
		(*subscrp).button[14].set(105, 225, 55, 25, BUTTON_GAMEOPT_MIN_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[14].mouseover_grfx_a.set( 0, 5, PENTA_SMALLEST, IDLE_ANIMATED);
		(*subscrp).button[14].mouseover_grfx_b.set( 55, 5, PENTA_SMALLEST, IDLE_ANIMATED);
		//(*subscrp).button[14].set_color(1,1,1,0.2);
		// + butt
		(*subscrp).button[15].set(165, 225, 55, 25, BUTTON_GAMEOPT_PLUS_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[15].mouseover_grfx_a.set( 0, 5, PENTA_SMALLEST, IDLE_ANIMATED);
		(*subscrp).button[15].mouseover_grfx_b.set( 55, 5, PENTA_SMALLEST, IDLE_ANIMATED);
		//(*subscrp).button[15].set_color(1,1,1,0.2);
		// ++ butt
		(*subscrp).button[16].set(225, 225, 55, 25, BUTTON_GAMEOPT_PLUS_PLUS_COMMAND, true, SOUND_MOVE, SOUND_MOVE);
		(*subscrp).button[16].mouseover_grfx_a.set( 0, 5, PENTA_SMALLEST, IDLE_ANIMATED);
		(*subscrp).button[16].mouseover_grfx_b.set( 55, 5, PENTA_SMALLEST, IDLE_ANIMATED);
		//(*subscrp).button[16].set_color(1,1,1,0.2);



		//--------------







		//the SCREEN_CREDITS_SELECT_MENU must be 3
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_CREDITS_SELECT_MENU]);
		(*scrp).init(1);
		subscrp = &((*global).screen[SCREEN_CREDITS_SELECT_MENU].subscreen[0x00]);

		(*scrp).backdrop.set(backdrop.x, backdrop.y, BACKDROP, 0);

		(*subscrp).init(4,0,4,1,0); //4 texted buttons, , 4 textlines, and one doodad burning logo
		(*subscrp).anchor_x = backdrop.x; // the susbscreen is the 640*480 rectangle
		(*subscrp).anchor_y = backdrop.y;
		(*subscrp).streching_x = ORIGINAL_WIDTH; // the susbscreen is the 640*480 rectangle
		(*subscrp).streching_y = ORIGINAL_HEIGHT;


		(*subscrp).textline[0].set(14, 0.5*ORIGINAL_WIDTH, 215, diab_cred);
		(*subscrp).textline[1].set(16, 0.5*ORIGINAL_WIDTH, 180, hf_cred);
		(*subscrp).textline[2].set(11, 0.5*ORIGINAL_WIDTH, 145, "$s01$<cen>{30g}DDT Credits");
		(*subscrp).textline[3].set( 9, 0.5*ORIGINAL_WIDTH, 110, "$s01$<cen>{30g}Main Menu");
		// logo
		(*subscrp).doodad[0].set(0.5*ORIGINAL_WIDTH, 310, logo_medium, IDLE_ANIMATED);

		// classic credits button
		(*subscrp).button[0].set(0,215,ORIGINAL_WIDTH, 25, BUTTON_GOTO_GAME_CREDITS_COMMAND, true, SOUND_MOVE, SOUND_SELECT);
		(*subscrp).button[0].mouseover_grfx_a.set(0.5*ORIGINAL_WIDTH - 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[0].mouseover_grfx_b.set(0.5*ORIGINAL_WIDTH + 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		// exp credits button
		(*subscrp).button[1].set(0,180,ORIGINAL_WIDTH, 25, BUTTON_GOTO_EXPANTION_CREDITS_COMMAND, true, SOUND_MOVE, SOUND_SELECT);
		(*subscrp).button[1].mouseover_grfx_a.set(0.5*ORIGINAL_WIDTH - 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[1].mouseover_grfx_b.set(0.5*ORIGINAL_WIDTH + 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[1].is_visisble = hf_active;
		// credits ddt button
		(*subscrp).button[2].set(0,145,ORIGINAL_WIDTH, 25, BUTTON_GOTO_ENGINE_CREDITS_COMMAND, true, SOUND_MOVE, SOUND_SELECT);
		(*subscrp).button[2].mouseover_grfx_a.set(0.5*ORIGINAL_WIDTH - 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[2].mouseover_grfx_b.set(0.5*ORIGINAL_WIDTH + 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		// back button
		(*subscrp).button[3].set(0,110,ORIGINAL_WIDTH, 25, BUTTON_GOTO_MAINMENU_COMMAND, true, SOUND_MOVE, SOUND_SELECT);
		(*subscrp).button[3].mouseover_grfx_a.set(0.5*ORIGINAL_WIDTH - 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[3].mouseover_grfx_b.set(0.5*ORIGINAL_WIDTH + 150, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[3].is_selected = true;


		//the SCREEN_GAME_CREDITS must be 4
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_GAME_CREDITS]);
		(*scrp).init(1);
		subscrp = &((*global).screen[SCREEN_GAME_CREDITS].subscreen[0x00]);

		(*scrp).backdrop.set(backdrop.x, backdrop.y, BACKDROP, 0);

		(*subscrp).init(1,1,3,1,1);  //int txtlines, int fields, int bttns, int doods)
		(*subscrp).anchor_x = backdrop.x; // the susbscreen is the 640*480 rectangle
		(*subscrp).anchor_y = backdrop.y;
		(*subscrp).streching_x = ORIGINAL_WIDTH; // the susbscreen is the 640*480 rectangle
		(*subscrp).streching_y = ORIGINAL_HEIGHT;


		(*subscrp).textfield[0].init(70, 70, 450, 280, 270, 100);
		(*subscrp).textfield[0].autoscroll = 0.3;
		(*subscrp).textfield[0].fader = true;
		(*subscrp).textfield[0].format(16, 9, "$s00$<lef>{sys} ");


		(*subscrp).textline[0].set(4,0.5*ORIGINAL_WIDTH, 25, "$s01$<cen>{sma}(gol)Back");
		(*subscrp).doodad[0].set(0.5*ORIGINAL_WIDTH, 370, LOGO_STATIC, 0);

		// back button
		(*subscrp).button[0].set(250, 18, 140, 24, BUTTON_GOTO_CREDITS_COMMAND, false, VOID_SOUND, SOUND_SELECT );
		(*subscrp).button[0].mouseover_grfx_a.set(20, 5,  PENTA_SMALLEST, IDLE_ANIMATED); //spinng pentagram at 14
		(*subscrp).button[0].mouseover_grfx_b.set(120, 5,  PENTA_SMALLEST, IDLE_ANIMATED); //spinng pentagram at 14

		// scroll down button
		(*subscrp).button[1].set(405, 18, 24, 24, BUTTON_CREDITS_SCROLLDOWN_COMMAND, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[1].idle_grfx.set(6, 6, SCROLL_BAR, 8); //assuming the big scroll grfx is at 10
		(*subscrp).button[1].mouseover_grfx_a.set(6, 6, SCROLL_BAR, 10);

		// scroll up button
		(*subscrp).button[2].set(215, 18, 24, 24, BUTTON_CREDITS_SCROLLUP_COMMAND, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[2].idle_grfx.set(6, 6, SCROLL_BAR, 9); //assuming the big scroll grfx is at 10
		(*subscrp).button[2].mouseover_grfx_a.set(6, 6, SCROLL_BAR, 11);


		(*subscrp).border[0].set_center(0.5*ORIGINAL_WIDTH,30, 20,2);



		//the SCREEN_SINGLE_PLAYER must be 5
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_SINGE_PLAYER]);
		(*scrp).init(1);
		subscrp = &((*global).screen[SCREEN_SINGE_PLAYER].subscreen[0x00]);

		(*scrp).backdrop.set(backdrop.x, backdrop.y, BACKDROP, 0);

		(*subscrp).init(14,0,10,2,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods)
		(*subscrp).anchor_x = backdrop.x; // the susbscreen is the 640*480 rectangle
		(*subscrp).anchor_y = backdrop.y;
		(*subscrp).streching_x = ORIGINAL_WIDTH; // the susbscreen is the 640*480 rectangle
		(*subscrp).streching_y = ORIGINAL_HEIGHT;

		(*subscrp).doodad[0].set(0.5*ORIGINAL_WIDTH, 310, logo_medium, IDLE_ANIMATED); //burning logo
		(*subscrp).doodad[1].set(30, 193, 25, 3); //char portraits 25


		(*subscrp).textline[0].set(15, 420,  200, "$s01$<cen>{24g}  "); //char choice a
		(*subscrp).textline[1].set(15, 420,  170, "$s01$<cen>{24g}  "); //char choice b
		(*subscrp).textline[2].set(15, 420,  140, "$s01$<cen>{24g}  "); //char choice c
		(*subscrp).textline[3].set(15, 420,  110, "$s01$<cen>{24g}  "); //char choice d
		(*subscrp).textline[4].set(15, 420,   80, "$s01$<cen>{24g}  "); //char choice e

		(*subscrp).textline[5].set(24, 120,  120, "$s01$<cen>{sma}(sil)--"); //class line
		(*subscrp).textline[6].set(24, 120,  100, "$s01$<cen>{sma}(sil)--"); //level line
		(*subscrp).textline[7].set(24, 120,   80, "$s01$<cen>{sma}(sil)--"); //current game diff line

		(*subscrp).textline[8].set(24, 120,   55, "$s01$<cen>{30s}--"); // stars line

		(*subscrp).textline[9] .set(15, 430,  242, "$s01$<cen>{30s}Select Hero");

		(*subscrp).textline[10].set(25, 0.5*ORIGINAL_WIDTH, 280, "$s01$<cen>{30s}Single Player Characters");
		(*subscrp).textline[11].set( 2, 290,   30, "$s01$<cen>{30g}OK");
		(*subscrp).textline[12].set( 6, 400,   30, "$s01$<cen>{30g}Delete");
		(*subscrp).textline[13].set( 6, 530,   30, "$s01$<cen>{30g}Cancel");

		// choice A butt
		(*subscrp).button[0].set(280, 195, 280, 30, BUTTON_SINGLE_PLAYER_SELECTA_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[0].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[0].mouseover_grfx_b.set( 295, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice B butt
		(*subscrp).button[1].set(280, 165, 280, 30, BUTTON_SINGLE_PLAYER_SELECTB_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[1].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[1].mouseover_grfx_b.set( 295, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice C butt
		(*subscrp).button[2].set(280, 135, 280, 30, BUTTON_SINGLE_PLAYER_SELECTC_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[2].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[2].mouseover_grfx_b.set( 295, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice D butt
		(*subscrp).button[3].set(280, 105, 280, 30, BUTTON_SINGLE_PLAYER_SELECTD_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[3].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[3].mouseover_grfx_b.set( 295, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice E butt
		(*subscrp).button[4].set(280,  75, 280, 30, BUTTON_SINGLE_PLAYER_SELECTE_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[4].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[4].mouseover_grfx_b.set( 295, 5, PENTA_SMALL, IDLE_ANIMATED);

		// scroll down button
		(*subscrp).button[5].set(588, 55, 24, 24, BUTTON_SINGLE_PLAYER_SCROLLDOWN_COMMAND, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[5].idle_grfx.set(6, 6, SCROLL_BAR, 8);
		(*subscrp).button[5].mouseover_grfx_a.set(6, 6, SCROLL_BAR, 10);
		// scroll up button
		(*subscrp).button[6].set(588, 215, 24, 24, BUTTON_SINGLE_PLAYER_SCROLLUP_COMMAND, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[6].idle_grfx.set(6, 6, SCROLL_BAR, 9);
		(*subscrp).button[6].mouseover_grfx_a.set(6, 6, SCROLL_BAR, 11);
		// ok butt
		(*subscrp).button[7].set(240, 30, 100, 30, BUTTON_SINGLE_PLAYER_OK_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[7].mouseover_grfx_a.set(+5, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[7].mouseover_grfx_b.set(+95, 0, PENTA_SMALL, IDLE_ANIMATED);
		// del butt
		(*subscrp).button[8].set(350, 30, 100, 30, BUTTON_SINGLE_PLAYER_DELETE_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[8].mouseover_grfx_a.set(-15, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[8].mouseover_grfx_b.set(+115, 0, PENTA_SMALL, IDLE_ANIMATED);


		// cancel butt
		(*subscrp).button[9].set(480, 30, 100, 30, BUTTON_GOTO_MAINMENU_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[9].mouseover_grfx_a.set(-15, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[9].mouseover_grfx_b.set(+115, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[9].is_selected = true;

		//the SCREEN_CHOOSE_CLASS must be 6
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_CHOOSE_CLASS]);
		(*scrp).init(1);
		subscrp = &((*global).screen[SCREEN_CHOOSE_CLASS].subscreen[0x00]);

		(*scrp).backdrop.set(backdrop.x, backdrop.y, BACKDROP, 0);

		(*subscrp).init(11,0,9,2,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods)
		(*subscrp).anchor_x = backdrop.x; // the susbscreen is the 640*480 rectangle
		(*subscrp).anchor_y = backdrop.y;
		(*subscrp).streching_x = ORIGINAL_WIDTH; // the susbscreen is the 640*480 rectangle
		(*subscrp).streching_y = ORIGINAL_HEIGHT;

		(*subscrp).doodad[0].set(0.5*ORIGINAL_WIDTH, 310, logo_medium, IDLE_ANIMATED); //burning logo


		(*subscrp).doodad[1].set(30, 193, CHAR_PORTRAIT, 0); //char portraits 25


		(*subscrp).textline[0].set(15, 420,  200, "$s01$<cen>{24g}  "); //char choice a
		(*subscrp).textline[1].set(15, 420,  170, "$s01$<cen>{24g}  "); //char choice b
		(*subscrp).textline[2].set(15, 420,  140, "$s01$<cen>{24g}  "); //char choice c
		(*subscrp).textline[3].set(15, 420,  110, "$s01$<cen>{24g}  "); //char choice d
		(*subscrp).textline[4].set(15, 420,   80, "$s01$<cen>{24g}  "); //char choice e

		(*subscrp).textline[5].set(24, 120,  110, "$s01$<cen>{sma}(sil)Class Speciality:");
		(*subscrp).textline[6].set(24, 120,  90, "$s01$<cen>{sma}(sil)--"); // class speciality line

		//todo fix texline discrepancy here

		(*subscrp).textline[7] .set(13, 430,  242, "$s01$<cen>{30s}Choose Class");

		//todo fix texline discrepancy here

		(*subscrp).textline[8].set(25, 0.5*ORIGINAL_WIDTH, 280, "$s01$<cen>{30s}New Single Player Hero");
		(*subscrp).textline[9].set( 2, 330,   30, "$s01$<cen>{30g}OK");
		(*subscrp).textline[10].set( 6, 490,   30, "$s01$<cen>{30g}Cancel");

		// choice A butt
		(*subscrp).button[0].set(280, 195, 280, 30, BUTTON_CHOOSE_CLASS_SELECTA_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[0].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[0].mouseover_grfx_b.set( 295, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice B butt
		(*subscrp).button[1].set(280, 165, 280, 30, BUTTON_CHOOSE_CLASS_SELECTB_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[1].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[1].mouseover_grfx_b.set( 295, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice C butt
		(*subscrp).button[2].set(280, 135, 280, 30, BUTTON_CHOOSE_CLASS_SELECTC_COMMAND, true,SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[2].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[2].mouseover_grfx_b.set( 295, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice D butt
		(*subscrp).button[3].set(280, 105, 280, 30, BUTTON_CHOOSE_CLASS_SELECTD_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[3].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[3].mouseover_grfx_b.set( 295, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice E butt
		(*subscrp).button[4].set(280,  75, 280, 30, BUTTON_CHOOSE_CLASS_SELECTE_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[4].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[4].mouseover_grfx_b.set( 295, 5, PENTA_SMALL, IDLE_ANIMATED);

		// scroll down button
		(*subscrp).button[5].set(588, 55, 24, 24, BUTTON_CHOOSE_CLASS_SCROLLDOWN_COMMAND, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[5].idle_grfx.set(6, 6, SCROLL_BAR, 8);
		(*subscrp).button[5].mouseover_grfx_a.set(6, 6, SCROLL_BAR, 10);
		// scroll up button
		(*subscrp).button[6].set(588, 215, 24, 24, BUTTON_CHOOSE_CLASS_SCROLLUP_COMMAND, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[6].idle_grfx.set(6, 6, SCROLL_BAR, 9);
		(*subscrp).button[6].mouseover_grfx_a.set(6, 6, SCROLL_BAR, 11);
		// ok butt
		(*subscrp).button[7].set(280, 30, 100, 30, BUTTON_CHOOSE_CLASS_OK_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[7].mouseover_grfx_a.set(+5, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[7].mouseover_grfx_b.set(+95, 0, PENTA_SMALL, IDLE_ANIMATED);
		// cancel butt
		(*subscrp).button[8].set(440, 30, 100, 30, BUTTON_GOTO_SINGLE_PLAYER_COMMAND , true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[8].mouseover_grfx_a.set(-15, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[8].mouseover_grfx_b.set(+115, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[8].is_selected = true;

		//the SCREEN_ENTER_NAME must be 7
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_ENTER_NAME]);
		(*scrp).init(1);
		subscrp = &((*global).screen[SCREEN_ENTER_NAME].subscreen[0x00]);

		(*scrp).backdrop.set(backdrop.x, backdrop.y, BACKDROP, 0);

		(*subscrp).init(15,0,41,2,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods)
		(*subscrp).anchor_x = backdrop.x; // the susbscreen is the 640*480 rectangle
		(*subscrp).anchor_y = backdrop.y;
		(*subscrp).streching_x = ORIGINAL_WIDTH; // the susbscreen is the 640*480 rectangle
		(*subscrp).streching_y = ORIGINAL_HEIGHT;

		(*subscrp).doodad[0].set(0.5*ORIGINAL_WIDTH, 310, logo_medium, IDLE_ANIMATED); //burning logo



		(*subscrp).doodad[1].set(30, 193, CHAR_PORTRAIT, 0); //char portraits 25

		(*subscrp).textline[0].set(24, 120,  110, "$s01$<cen>{sma}(sil)Class Speciality:");
		(*subscrp).textline[1].set(24, 120,  90, "$s01$<cen>{sma}(sil)--"); // speciality line

		//todo fix texline discrepancy here

		(*subscrp).textline[5] .set(13, 430,  242, "$s01$<cen>{30s}Enter Name");

		//todo fix texline discrepancy here

		(*subscrp).textline[11].set(50, 0.5*ORIGINAL_WIDTH, 280, "$s01$<cen>{30s}New Single Player Hero");
		(*subscrp).textline[12].set( 2, 330,   30, "$s01$<cen>{30g}OK");
		(*subscrp).textline[13].set( 6, 490,   30, "$s01$<cen>{30g}Cancel");

		(*subscrp).textline[14].set(15, 430,  200, "$s01$<cen>{30g}enter name here"); //char choice c

		// name butt
		(*subscrp).button[0].set(280, 195, 295, 30, BUTTON_VOID_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[0].mouseover_grfx_a.set( -20, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[0].mouseover_grfx_b.set( 310, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[0].set_color(1, 0, 0, 0.05);
		// ok butt
		(*subscrp).button[1].set(280, 30, 100, 30, BUTTON_ENTER_NAME_OK_COMMAND, true, SOUND_MOVE, SOUND_SELECT);
		(*subscrp).button[1].mouseover_grfx_a.set(+5, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[1].mouseover_grfx_b.set(+95, 0, PENTA_SMALL, IDLE_ANIMATED);
		// cancel butt
		(*subscrp).button[2].set(440, 30, 100, 30, BUTTON_ENTER_NAME_CANCEL_COMMAND , true, SOUND_MOVE, SOUND_SELECT);
		(*subscrp).button[2].mouseover_grfx_a.set(-15, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[2].mouseover_grfx_b.set(+115, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[2].is_selected = true;

		//A
		(*subscrp).button[3].set(280, 165, 25, 25, BUTTON_ENTER_NAME_A_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[3].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x61);
		//B
		(*subscrp).button[4].set(310, 165, 25, 25, BUTTON_ENTER_NAME_B_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[4].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x62);
		//C
		(*subscrp).button[5].set(340, 165, 25, 25, BUTTON_ENTER_NAME_C_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[5].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x63);
		//D
		(*subscrp).button[6].set(370, 165, 25, 25, BUTTON_ENTER_NAME_D_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[6].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x64);
		//E
		(*subscrp).button[7].set(400, 165, 25, 25, BUTTON_ENTER_NAME_E_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[7].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x65);
		//F
		(*subscrp).button[8].set(430, 165, 25, 25, BUTTON_ENTER_NAME_F_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[8].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x66);

		//Underscore
		(*subscrp).button[9].set(520, 165, 25, 25, BUTTON_ENTER_NAME_USCORE_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[9].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x5f);
		//Backspace
		(*subscrp).button[10].set(550, 165, 25, 25, BUTTON_ENTER_NAME_BACK_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[10].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0xab);

		//G
		(*subscrp).button[11].set(280, 135, 25, 25, BUTTON_ENTER_NAME_G_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[11].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x67);
		//H
		(*subscrp).button[12].set(310, 135, 25, 25, BUTTON_ENTER_NAME_H_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[12].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x68);
		//I
		(*subscrp).button[13].set(340, 135, 25, 25, BUTTON_ENTER_NAME_I_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[13].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x69);
		//J
		(*subscrp).button[14].set(370, 135, 25, 25, BUTTON_ENTER_NAME_J_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[14].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x6a);
		//K
		(*subscrp).button[15].set(400, 135, 25, 25, BUTTON_ENTER_NAME_K_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[15].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x6b);
		//L
		(*subscrp).button[16].set(430, 135, 25, 25, BUTTON_ENTER_NAME_L_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[16].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x6c);
		//M
		(*subscrp).button[17].set(460, 135, 25, 25, BUTTON_ENTER_NAME_M_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[17].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x6d);
		//N
		(*subscrp).button[18].set(490, 135, 25, 25, BUTTON_ENTER_NAME_N_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[18].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x6e);
		//O
		(*subscrp).button[19].set(520, 135, 25, 25, BUTTON_ENTER_NAME_O_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[19].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x6f);
		//P
		(*subscrp).button[20].set(550, 135, 25, 25, BUTTON_ENTER_NAME_P_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[20].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x70);

		//Q
		(*subscrp).button[21].set(280, 105, 25, 25, BUTTON_ENTER_NAME_Q_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[21].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x71);
		//R
		(*subscrp).button[22].set(310, 105, 25, 25, BUTTON_ENTER_NAME_R_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[22].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x72);
		//S
		(*subscrp).button[23].set(340, 105, 25, 25, BUTTON_ENTER_NAME_S_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[23].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x73);
		//T
		(*subscrp).button[24].set(370, 105, 25, 25, BUTTON_ENTER_NAME_T_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[24].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x74);
		//U
		(*subscrp).button[25].set(400, 105, 25, 25, BUTTON_ENTER_NAME_U_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[25].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x75);
		//V
		(*subscrp).button[26].set(430, 105, 25, 25, BUTTON_ENTER_NAME_V_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[26].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x76);
		//W
		(*subscrp).button[27].set(460, 105, 25, 25, BUTTON_ENTER_NAME_W_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[27].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x77);
		//X
		(*subscrp).button[28].set(490, 105, 25, 25, BUTTON_ENTER_NAME_X_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[28].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x78);
		//Y
		(*subscrp).button[29].set(520, 105, 25, 25, BUTTON_ENTER_NAME_Y_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[29].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x79);
		//Z
		(*subscrp).button[30].set(550, 105, 25, 25, BUTTON_ENTER_NAME_Z_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[30].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x7a);

		//0
		(*subscrp).button[31].set(280,  75, 25, 25, BUTTON_ENTER_NAME_0_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[31].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x30);
		//1
		(*subscrp).button[32].set(310, 75, 25, 25, BUTTON_ENTER_NAME_1_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[32].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x31);
		//2
		(*subscrp).button[33].set(340, 75, 25, 25, BUTTON_ENTER_NAME_2_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[33].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x32);
		//3
		(*subscrp).button[34].set(370, 75, 25, 25, BUTTON_ENTER_NAME_3_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[34].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x33);
		//4
		(*subscrp).button[35].set(400, 75, 25, 25, BUTTON_ENTER_NAME_4_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[35].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x34);
		//5
		(*subscrp).button[36].set(430, 75, 25, 25, BUTTON_ENTER_NAME_5_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[36].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x35);
		//6
		(*subscrp).button[37].set(460, 75, 25, 25, BUTTON_ENTER_NAME_6_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[37].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x36);
		//7
		(*subscrp).button[38].set(490, 75, 25, 25, BUTTON_ENTER_NAME_7_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[38].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x37);
		//8
		(*subscrp).button[39].set(520, 75, 25, 25, BUTTON_ENTER_NAME_8_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[39].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x38);
		//9
		(*subscrp).button[40].set(550, 75, 25, 25, BUTTON_ENTER_NAME_9_COMMAND, true, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[40].idle_grfx.set(5, 5, FONT_TWENTYFOUR_G, 0x39);


		for (int i = 3; i < 41; i++)
		{
			(*subscrp).button[i].mouseover_grfx_a.set(12, 2, PENTA_SMALL, IDLE_ANIMATED, 1,1,1,0.5); //spinng pentagram at 14
			(*subscrp).button[i].set_color(1, 0, 0, 0.05);
		}



		//the //SCREEN_SELECT_GAMETYPE must be 8
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_SELECT_GAMETYPE]);
		(*scrp).init(1);
		subscrp = &((*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0]);

		(*scrp).backdrop.set(backdrop.x, backdrop.y, BACKDROP, 0);

		(*subscrp).init(10,1,6,1,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods)
		(*subscrp).anchor_x = backdrop.x; // the susbscreen is the 640*480 rectangle
		(*subscrp).anchor_y = backdrop.y;
		(*subscrp).streching_x = ORIGINAL_WIDTH; // the susbscreen is the 640*480 rectangle
		(*subscrp).streching_y = ORIGINAL_HEIGHT;

		(*subscrp).doodad[0].set(0.5*ORIGINAL_WIDTH, 310, logo_medium, IDLE_ANIMATED); //burning logo




		(*subscrp).textline[0].set(20, 450,  190, "$s01$<cen>{24g}Load Previous Game"); //Load
		(*subscrp).textline[2].set(20, 450,  150, "$s01$<cen>{24g}New Normal Game"); //normal
		(*subscrp).textline[3].set(20, 450,  120, "$s01$<cen>{24g}New Nightmare Game"); //char choice d
		(*subscrp).textline[4].set(20, 450,   90, "$s01$<cen>{24g}New Hell Game"); //char choice e


		(*subscrp).textline[5] .set(13, 450,  242, "$s01$<cen>{30s}Load Options");
		(*subscrp).textline[6] .set(13, 140,  242, "$s01$<cen>{30s}Load Previous");


		(*subscrp).textline[7].set(50, 0.5*ORIGINAL_WIDTH, 280, "$s01$<cen>{30s}class save");
		(*subscrp).textline[8].set( 2, 370,   30, "$s01$<cen>{30g}OK");
		(*subscrp).textline[9].set( 6, 520,   30, "$s01$<cen>{30g}Cancel");

		// choice loads
		(*subscrp).button[0].set(320, 185, 260, 30, BUTTON_GAMETYPE_LOAD_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[0].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[0].mouseover_grfx_b.set( 275, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[0].set_color(1, 0, 0, 0.15);

		// choice normal 135
		(*subscrp).button[1].set(320, 145, 260, 30, BUTTON_GAMETYPE_NORMAL_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[1].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[1].mouseover_grfx_b.set( 275, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice nightmare 105
		(*subscrp).button[2].set(320, 115, 260, 30, BUTTON_GAMETYPE_NIGHTMARE_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[2].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[2].mouseover_grfx_b.set( 275, 5, PENTA_SMALL, IDLE_ANIMATED);
		// choice hell 75
		(*subscrp).button[3].set(320,  85, 260, 30, BUTTON_GAMETYPE_HELL_COMMAND, true, SOUND_MOVE, SOUND_MOVE );
		(*subscrp).button[3].mouseover_grfx_a.set( -15, 5, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[3].mouseover_grfx_b.set( 275, 5, PENTA_SMALL, IDLE_ANIMATED);


		// ok butt
		(*subscrp).button[4].set(320, 30, 100, 30, BUTTON_GAMETYPE_OK_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[4].mouseover_grfx_a.set(+5, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[4].mouseover_grfx_b.set(+95, 0, PENTA_SMALL, IDLE_ANIMATED);
		// cancel butt
		(*subscrp).button[5].set(470, 30, 100, 30, BUTTON_GOTO_SINGLE_PLAYER_COMMAND , true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[5].mouseover_grfx_a.set(-15, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[5].mouseover_grfx_b.set(+115, 0, PENTA_SMALL, IDLE_ANIMATED);
		(*subscrp).button[5].is_selected = true;

		(*subscrp).textfield[0].init(140, 23, 1, 210, 10, 44);
		(*subscrp).textfield[0].format(5, 10, "$s02${sma}(sil)<cen>Game Mode description here");



		//SCREEN_WORLD

		//the //SCREEN_WORLD must be 9
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_WORLD]);
		(*scrp).init(WORLD_SUBSCREEN_COUNT);



		subscrp = &((*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_MENU]);
		(*subscrp).init(5,0,5,1,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods, int borders)
		(*subscrp).solid = true;
		(*subscrp).visible = false;
		(*subscrp).bga = 0.5;


		(*subscrp).anchor_x = 0;
		(*subscrp).anchor_y = 0;
		(*subscrp).streching_x = screen_size_x;
		(*subscrp).streching_y = screen_size_y;

		(*subscrp).doodad[0].set(0.5*screen_size_x,  0.5*screen_size_y + 130, LOGO_SMALL, IDLE_ANIMATED);

		(*subscrp).textline[0].set(10, 0.5*screen_size_x, 0.5*screen_size_y + 80 , "$s01$<cen>{42g}Save Game");
		(*subscrp).textline[1].set( 8, 0.5*screen_size_x, 0.5*screen_size_y + 40 , "$s01$<cen>{42g}Options");
		(*subscrp).textline[2].set(11, 0.5*screen_size_x, 0.5*screen_size_y +  0 , "$s01$<cen>{42g}Leave Game");
		(*subscrp).textline[3].set(11, 0.5*screen_size_x, 0.5*screen_size_y - 40 , "$s01$<cen>{42g}Load Game");
		(*subscrp).textline[4].set(14, 0.5*screen_size_x, 0.5*screen_size_y - 80 , "$s01$<cen>{42g}Continue Game");

		// save game butt
		(*subscrp).button[0].set(0, 0.5*screen_size_y + 75, screen_size_x, 40, BUTTON_WORLD_MAKE_SAVEGAME, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[0].mouseover_grfx_a.set(0.5*screen_size_x - 200 , -5, PENTA_BIG, IDLE_ANIMATED);
		(*subscrp).button[0].mouseover_grfx_b.set(0.5*screen_size_x + 200 , -5, PENTA_BIG, IDLE_ANIMATED);
		(*subscrp).button[0].is_selected = true;

		// options butt
		(*subscrp).button[1].set(0, 0.5*screen_size_y + 35, screen_size_x, 40, BUTTON_VOID_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[1].mouseover_grfx_a.set(0.5*screen_size_x - 200 , -5, PENTA_BIG, IDLE_ANIMATED);
		(*subscrp).button[1].mouseover_grfx_b.set(0.5*screen_size_x + 200 , -5, PENTA_BIG, IDLE_ANIMATED);

		// leave game butt
		(*subscrp).button[2].set(0, 0.5*screen_size_y -  5, screen_size_x, 40, BUTTON_WORLD_LEAVE_GAME, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[2].mouseover_grfx_a.set(0.5*screen_size_x - 200 , -5, PENTA_BIG, IDLE_ANIMATED);
		(*subscrp).button[2].mouseover_grfx_b.set(0.5*screen_size_x + 200 , -5, PENTA_BIG, IDLE_ANIMATED);

		// load game
		(*subscrp).button[3].set(0, 0.5*screen_size_y - 45, screen_size_x, 40, BUTTON_WORLD_LOAD_SAVEGAME, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[3].mouseover_grfx_a.set(0.5*screen_size_x - 200 , -5, PENTA_BIG, IDLE_ANIMATED);
		(*subscrp).button[3].mouseover_grfx_b.set(0.5*screen_size_x + 200 , -5, PENTA_BIG, IDLE_ANIMATED);

		// continue game butt
		(*subscrp).button[4].set(0, 0.5*screen_size_y - 85, screen_size_x, 40, BUTTON_WORLD_TOGGLE_MENU_OFF, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[4].mouseover_grfx_a.set(0.5*screen_size_x - 200 , -5, PENTA_BIG, IDLE_ANIMATED);
		(*subscrp).button[4].mouseover_grfx_b.set(0.5*screen_size_x + 200 , -5, PENTA_BIG, IDLE_ANIMATED);




		subscrp = &((*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_SPELLS]);
		(*subscrp).init(0,0,0,0,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods, borders)


		subscrp = &((*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_MSG]);
		(*subscrp).init(1,0,0,0,1); //ui_subscreen(int txtlines, int fields, int bttns, int doods, borders)
		(*subscrp).solid = false;
		(*subscrp).visible = false;

		(*subscrp).anchor_x = 0.5*screen_size_x;
		(*subscrp).anchor_y = 0.5*screen_size_y;
		(*subscrp).streching_x = 0;
		(*subscrp).streching_y = 0;

		(*subscrp).border[0].set_center(0, 40, 40, 5);
		(*subscrp).border[0].set_color(0.0, 0.0, 0.0, 0.6);

		(*subscrp).textline[0].set(50, 0, 35 , "$s00${sma}(gol)<cen>opop msg goes here");








		subscrp = &((*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_ORBS]);
		(*subscrp).init(0,1,6,1,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods, borders)

		(*subscrp).anchor_x = backdrop.x; // the susbscreen is the 640*480 rectangle
		(*subscrp).anchor_y = 0;
		(*subscrp).streching_x = ORIGINAL_WIDTH; // the susbscreen is the 640*480 rectangle
		(*subscrp).streching_y = 128;

		(*subscrp).doodad[0].set(0, 0, ORB_BAR, 0, 1.0, 1.0, 1.0, hud_alpha); //orbs hud

		//char button
		(*subscrp).button[0].set(9, 100,  71, 19, BUTTON_WORLD_TOGGLE_CHARSTATS, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[0].mouseover_grfx_a.set(0, 0, ORB_BAR_BUTTS, 0);

		//quests button
		(*subscrp).button[1].set(9,  74,  71, 19, BUTTON_VOID_COMMAND, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[1].mouseover_grfx_a.set(0, 0, ORB_BAR_BUTTS, 1);

		//map button
		(*subscrp).button[2].set(9,  34,  71, 19, BUTTON_WORLD_TOGGLE_MAP, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[2].mouseover_grfx_a.set(0, 0, ORB_BAR_BUTTS, 2);

		//menu button
		(*subscrp).button[3].set(9,  8,  71, 19, BUTTON_WORLD_TOGGLE_MENU_ON, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[3].mouseover_grfx_a.set(0, 0, ORB_BAR_BUTTS, 3);


		//inventory button
		(*subscrp).button[4].set(560, 100,  71, 19, BUTTON_WORLD_TOGGLE_INVENTORY, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[4].mouseover_grfx_a.set(0, 0, ORB_BAR_BUTTS, 4);

		//spells button
		(*subscrp).button[5].set(560,  74,  71, 19, BUTTON_VOID_COMMAND, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[5].mouseover_grfx_a.set(0, 0, ORB_BAR_BUTTS, 5);

		//void init(int anch_x, int anch_y, int wi, int hi, int l_count, int c_count)
		(*subscrp).textfield[0].init(325, 19, 1, 68, 5, 50);
		(*subscrp).textfield[0].format(7, 10, "$s01${sma}<cen>Bla");




		subscrp = &((*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_CHAR]);
		(*subscrp).init(2,0,0,1,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods, borders)
		(*subscrp).solid = true;
		(*subscrp).visible = false;


		(*subscrp).anchor_x = charstat.x;
		(*subscrp).anchor_y = charstat.y;  //128 being the orbs bar size
		(*subscrp).streching_x = 320;
		(*subscrp).streching_y = 352;

		(*subscrp).doodad[0].set(0, 0, CHAR_BACKDROP, 0, 1.0, 1.0, 1.0, hud_alpha);

		(*subscrp).textline[0].set(MAX_CHAR_NAME_LENGTH, 89, 320 , "$s01${sma}<cen>Char Name");
		(*subscrp).textline[1].set(MAX_CHAR_NAME_LENGTH, 235, 320 , "$s01${sma}<cen>Class Name");







		subscrp = &((*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_INV]);
		(*subscrp).init(0,0,0,1,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods, borders)
		(*subscrp).solid = true;
		(*subscrp).visible = false;


		(*subscrp).anchor_x = inventory.x;
		(*subscrp).anchor_y = inventory.y;
		(*subscrp).streching_x = 320;
		(*subscrp).streching_y = 352;

		(*subscrp).doodad[0].set(0, 0, INV_BACKDROP, 0, 1.0, 1.0, 1.0, hud_alpha);





		subscrp = &((*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_STASH]);
		(*subscrp).init(4,0,0,1,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods, borders)
		(*subscrp).solid = true;
		(*subscrp).visible = false;


		(*subscrp).anchor_x = charstat.x;
		(*subscrp).anchor_y = charstat.y;  //128 being the orbs bar size
		(*subscrp).streching_x = 320;
		(*subscrp).streching_y = 352;

		(*subscrp).doodad[0].set(0, 0, STASH_WINDOW, 0, 1.0, 1.0, 1.0, hud_alpha);

		(*subscrp).textline[0].set(13, 160, 300 , "$s01${sma}<cen>Stash Page XX");
		(*subscrp).textline[1].set( 5, 160, 280 , "$s01${sma}(gol)<cen>Close");
		(*subscrp).textline[2].set( 7,  80, 280 , "$s01${sma}(gol)<cen>[arowo]Browse");
		(*subscrp).textline[3].set( 7, 240, 280 , "$s01${sma}(gol)<cen>Browse[arowc]");



		subscrp = &((*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_MAP]);
		(*subscrp).init(2,0,4,0,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods, int borders)
		(*subscrp).solid = false;
		(*subscrp).visible = false;

		(*subscrp).anchor_x = 0;
		(*subscrp).anchor_y = 0;
		(*subscrp).streching_x = screen_size_x;
		(*subscrp).streching_y = screen_size_y;

		(*subscrp).textline[0].set(30, 10, screen_size_y - 20 , "$s01$(gol){sma}Level name here");
		(*subscrp).textline[1].set(30, 10, screen_size_y - 40 , "$s01$(gol){sma}Tile coords here");

		//V
		(*subscrp).button[0].set(screen_size_x - 30, screen_size_y - 40,  10, 10, BUTTON_WORLD_MAP_DOWN, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[0].idle_grfx.set(0, 0, SCROLL_BAR, 12);
		//(*subscrp).button[0].set_color(1, 0, 0, 0.5);
		//^
		(*subscrp).button[1].set(screen_size_x - 30, screen_size_y - 20,  10, 10, BUTTON_WORLD_MAP_UP, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[1].idle_grfx.set(0, 0, SCROLL_BAR, 12);
		//(*subscrp).button[1].set_color(1, 0, 0, 0.5);
		//>
		(*subscrp).button[2].set(screen_size_x - 20, screen_size_y - 30,  10, 10, BUTTON_WORLD_MAP_RIGHT, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[2].idle_grfx.set(0, 0, SCROLL_BAR, 12);
		//(*subscrp).button[2].set_color(1, 0, 0, 0.5);
		//<
		(*subscrp).button[3].set(screen_size_x - 40, screen_size_y - 30,  10, 10, BUTTON_WORLD_MAP_LEFT, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[3].idle_grfx.set(0, 0, SCROLL_BAR, 12);
		//(*subscrp).button[3].set_color(1, 0, 0, 0.5);



		subscrp = &((*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_STORY]);
		(*subscrp).init(1,1,3,0,1);  //int txtlines, int fields, int bttns, int doods, borders)
		(*subscrp).anchor_x = 0;
		(*subscrp).anchor_y = 0;
		(*subscrp).streching_x = screen_size_x; // the susbscreen is the 640*480 rectangle
		(*subscrp).streching_y = screen_size_y;
		(*subscrp).bga = 0.5;
		(*subscrp).solid = true;
		(*subscrp).visible = false;

		(*subscrp).border[0].set(backdrop.x + 20 , backdrop.y + 140 , 55, 30);
		(*subscrp).textline[0].set(4, backdrop.x + 0.5*ORIGINAL_WIDTH, backdrop.y + 150, "$s01$<cen>{sma}(gol)Back");


		// back button
		(*subscrp).button[0].set(backdrop.x + 0.5*ORIGINAL_WIDTH - 70, backdrop.y + 145, 140, 24, BUTTON_WORLD_STORY_EXIT, false, VOID_SOUND, SOUND_SELECT );
		(*subscrp).button[0].mouseover_grfx_a.set(20, 5,  PENTA_SMALLEST, IDLE_ANIMATED); //spinng pentagram at 14
		(*subscrp).button[0].mouseover_grfx_b.set(120, 5,  PENTA_SMALLEST, IDLE_ANIMATED); //spinng pentagram at 14
		//(*subscrp).button[0].set_color(1, 1, 1, 0.5);

		// scroll down button
		(*subscrp).button[1].set(backdrop.x + 603, backdrop.y + 138, 24, 24, BUTTON_WORLD_STORY_SCROLL_DOWN, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[1].idle_grfx.set(6, 6, SCROLL_BAR, 8); //assuming the big scroll grfx is at 10
		(*subscrp).button[1].mouseover_grfx_a.set(6, 6, SCROLL_BAR, 10);

		// scroll up button
		(*subscrp).button[2].set(backdrop.x + 603, backdrop.y + 448, 24, 24, BUTTON_WORLD_STORY_SCROLL_UP, false, VOID_SOUND, VOID_SOUND );
		(*subscrp).button[2].idle_grfx.set(6, 6, SCROLL_BAR, 9); //assuming the big scroll grfx is at 10
		(*subscrp).button[2].mouseover_grfx_a.set(6, 6, SCROLL_BAR, 11);



		(*subscrp).textfield[0].init(backdrop.x + 40, backdrop.y + 170, 450, 280, 270, 100);
		(*subscrp).textfield[0].autoscroll = 0.4;
		(*subscrp).textfield[0].fader = true;
		(*subscrp).textfield[0].format(16, 9, "$s01$<lef>{30g} ");

















		//the //SCREEN_DELETE_CHAR must be 10
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_DELETE_CHAR]);
		(*scrp).init(1);

		(*scrp).backdrop.set(backdrop.x, backdrop.y, BACKDROP, 0);

		subscrp = &((*global).screen[SCREEN_DELETE_CHAR].subscreen[0]);
		(*subscrp).init(4,0,2,1,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods, borders)


		(*subscrp).anchor_x = backdrop.x; // the susbscreen is the 640*480 rectangle
		(*subscrp).anchor_y = backdrop.y;
		(*subscrp).streching_x = ORIGINAL_WIDTH; // the susbscreen is the 640*480 rectangle
		(*subscrp).streching_y = ORIGINAL_HEIGHT;

		(*subscrp).doodad[0].set(0.5*ORIGINAL_WIDTH, 310, logo_medium, IDLE_ANIMATED); //burning logo

		(*subscrp).textline[0].set(40, 0.5*ORIGINAL_WIDTH,  210, "$s01$<cen>{30s}are you sure you want to delete");
		(*subscrp).textline[1].set(60, 0.5*ORIGINAL_WIDTH,  180, "$s01$<cen>{30s}Class Save?");

		(*subscrp).textline[2].set(3, 0.33*ORIGINAL_WIDTH,  100, "$s01$<cen>{30g}Yes");
		(*subscrp).textline[3].set(3, 0.66*ORIGINAL_WIDTH,  100, "$s01$<cen>{30g}No");



		// no butt
		(*subscrp).button[0].set(0.66*ORIGINAL_WIDTH - 50, 100,  100    , 25, BUTTON_GOTO_SINGLE_PLAYER_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[0].mouseover_grfx_a.set(0, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[0].mouseover_grfx_b.set(100, -5, PENTA_MEDIUM, IDLE_ANIMATED);


		//yes butt
		(*subscrp).button[1].set(0.33*ORIGINAL_WIDTH - 50, 100,  100, 25, BUTTON_DELETE_SCREEN_OK_COMMAND, true, SOUND_MOVE, SOUND_SELECT );
		(*subscrp).button[1].mouseover_grfx_a.set(0, -5, PENTA_MEDIUM, IDLE_ANIMATED);
		(*subscrp).button[1].mouseover_grfx_b.set(100, -5, PENTA_MEDIUM, IDLE_ANIMATED);


		//the //SCREENLOAD_WAIT must be 11
		//------------------------------------------------------------------------------------
		scrp = &((*global).screen[SCREEN_LOAD_WAIT]);
		(*scrp).init(1);
		(*scrp).backdrop.set(backdrop.x, backdrop.y, BACKDROP, 0);

		subscrp = &((*global).screen[SCREEN_LOAD_WAIT].subscreen[0]);
		(*subscrp).init(1,0,0,0,0); //ui_subscreen(int txtlines, int fields, int bttns, int doods, borders)

		(*subscrp).anchor_x = backdrop.x; // the susbscreen is the 640*480 rectangle
		(*subscrp).anchor_y = backdrop.y;
		(*subscrp).streching_x = ORIGINAL_WIDTH; // the susbscreen is the 640*480 rectangle
		(*subscrp).streching_y = ORIGINAL_HEIGHT;


		(*subscrp).textline[0].set(80, 0.5*ORIGINAL_WIDTH,  210, "$s01$<cen>{30g}  "); //:::loading:::

	}

	void credits_reset_scroller()
	{
		(*global).screen[SCREEN_GAME_CREDITS].subscreen[0].textfield[0].scroller = 0;
	}

	void credits_scroll_up(float value)
	{
		(*global).screen[SCREEN_GAME_CREDITS].subscreen[0].textfield[0].scroll_up(value);
	}

	void credits_scroll_down(float value)
	{
		(*global).screen[SCREEN_GAME_CREDITS].subscreen[0].textfield[0].scroll_down(value);
	}

	void credits_update(int line_count, string* field)
	{
		(*global).screen[SCREEN_GAME_CREDITS].subscreen[0].textfield[0].reset(line_count,field);
	}


	void settings_set_button_active_color(int butt)
	{
		for (int i = 0; i <  UI_OPT_BUTTON_COUNT; i++)
		{
			(*global).screen[SCREEN_SETTINGS_MENU].subscreen[0].button[i].set_color(0,0,0,0);
		}

		if ( butt > -1 && butt < UI_OPT_BUTTON_COUNT)
		{
			(*global).screen[SCREEN_SETTINGS_MENU].subscreen[0].button[butt].set_color(1, 0, 0, 0.15);
		}
	}

	void settings_set_option_value(string value)
	{
		(*global).screen[SCREEN_SETTINGS_MENU].subscreen[0].textline[12].reset(value);
	}


	void settings_set_option_discription(int opt)
	{
		int line_count = 0;
		string* field = new string();

		if (opt == OPT_WIDTH)
		{
			line_count = 6;
			field = new string[line_count];
			field[0] = "Window Width:";
			field[1] = "";
			field[2] = "Increase to get";
			field[3] = "a wider window.";
			field[4] = "";
			field[5] = "[softo]takes effect after restart[softc]";
		}
		else if (opt == OPT_HEIGHT)
		{
			line_count = 6;
			field = new string[line_count];
			field[0] = "Window Height:";
			field[1] = "";
			field[2] = "Increase to get";
			field[3] = "a higher window.";
			field[4] = "";
			field[5] = "[softo]takes effect after restart[softc]";
		}
		else if (opt == OPT_ZOOM)
		{
			line_count = 9;
			field = new string[line_count];
			field[0] = "Zoom:";
			field[1] = "";
			field[2] = "Increase to scale up";
			field[3] = "the game.";
			field[4] = "";
			field[5] = "[softo]Higher values give";
			field[6] = "better performance.[softc]";
			field[7] = "";
			field[8] = "[softo]takes effect after restart[softc]";
		}
		else if (opt == OPT_BLEND)
		{
			line_count = 8;
			field = new string[line_count];
			field[0] = "Blending Effects:";
			field[1] = "";
			field[2] = "Turn this off to";
			field[3] = "disable some visual.";
			field[4] = "effects and increase";
			field[5] = "performance.";
			field[6] = "";
			field[7] = "[softo]takes effect after restart[softc]";
		}
		else if (opt == OPT_GAMMA)
		{
			line_count = 6;
			field = new string[line_count];
			field[0] = "Extra Brightness:";
			field[1] = "";
			field[2] = "Increase to make the screen";
			field[3] = "brighter.";
			field[4] = "";
			field[5] = "[softo]takes effect after restart[softc]";
		}
		else if (opt == OPT_ALPHA)
		{
			line_count = 8;
			field = new string[line_count];
			field[0] = "Transparent UI:";
			field[1] = "";
			field[2] = "Increase to add more ";
			field[3] = "transparency effect";
			field[4] = "to some elements.";
			field[6] = "";
			field[7] = "[softo]takes effect after restart[softc]";
		}
		else if (opt == OPT_SOUND)
		{
			line_count = 4;
			field = new string[line_count];
			field[0] = "Sound Volume:";
			field[1] = "";
			field[2] = "Increase to make sound";
			field[3] = "effects louder.";
		}
		else if (opt == OPT_MUSIC)
		{
			line_count = 4;
			field = new string[line_count];
			field[0] = "Music Volume:";
			field[1] = "";
			field[2] = "Increase to make the";
			field[3] = "music louder.";
		}
		else if (opt == OPT_AUTOSAVE)
		{
			line_count = 5;
			field = new string[line_count];
			field[0] = "Auto Save:";
			field[1] = "";
			field[2] = "Turn this on to save";
			field[3] = "automatically before";
			field[4] = "leaving a dungeon.";
		}

		(*global).screen[SCREEN_SETTINGS_MENU].subscreen[0].textfield[0].reset(line_count, field);
		(*global).screen[SCREEN_SETTINGS_MENU].subscreen[0].textfield[0].space_vertical();
	}


	void settings_set_option_line(int line_no, string value)
	{
		if ( line_no > -1 && line_no < UI_OPT_BUTTON_COUNT)
		{
			(*global).screen[SCREEN_SETTINGS_MENU].subscreen[0].textline[line_no].reset(value);
		}
	}

	void sp_set_name_line(int line_no, string value)
	{
		if ( line_no > -1 && line_no < UI_SAVE_BUTTON_COUNT)
		{
			(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].textline[line_no].reset(value);
		}

	}

	void sp_set_delete_active(bool active)
	{
		if (active)
		{
			(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].textline[12].reset( "{30g}Delete");
			(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].button[8].is_visisble = true;
		}
		else
		{
			(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].textline[12].reset( "{30s}Delete");
			(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].button[8].is_visisble = false;
		}
	}


	void sp_set_button_active_color(int butt)
	{
		for (int i = 0; i <  UI_SAVE_BUTTON_COUNT; i++)
		{
			(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].button[i].set_color(0,0,0,0);
		}

		if ( butt > -1 && butt < UI_SAVE_BUTTON_COUNT)
		{
			(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].button[butt].set_color(1, 0, 0, 0.15);
		}
	}

	void sp_set_new_hero_discription()
	{

		string expantion_plus_hero = "";

		if ((*global).game_mode == GAME_MODE_EXP)
		{
			expantion_plus_hero.append((*global).binblob.get_game_name(GAME_MODE_EXP));
		}
		expantion_plus_hero.append(" hero");


		(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].textline[5].reset("");
		(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].textline[6].reset("Create a new");
		(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].textline[7].reset(expantion_plus_hero);
		(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].textline[8].reset("");
	}

	void class_set_name_line(int line_no, string value)
	{
		if ( line_no > -1 && line_no < UI_CLASS_BUTTON_COUNT)
		{
			(*global).screen[SCREEN_CHOOSE_CLASS].subscreen[0].textline[line_no].reset(value);
		}

	}


	void class_set_button_active_color(int butt)
	{
		for (int i = 0; i <  UI_CLASS_BUTTON_COUNT; i++)
		{
			(*global).screen[SCREEN_CHOOSE_CLASS].subscreen[0].button[i].set_color(0,0,0,0);
		}

		if ( butt > -1 && butt < UI_CLASS_BUTTON_COUNT)
		{
			(*global).screen[SCREEN_CHOOSE_CLASS].subscreen[0].button[butt].set_color(1, 0, 0, 0.15);
		}
	}

	void name_set_input_field(string value)
	{
		(*global).screen[SCREEN_ENTER_NAME].subscreen[0].textline[14].reset(value);
	}

	void gametype_set_allowed(int stars, int savegame_mode)
	{
		(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].button[0].is_visisble = false; //load game
		(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].button[2].is_visisble = false; //nm button
		(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].button[3].is_visisble = false; //hell button
		(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textline[0].reset("{24s}Load Previous Game");
		(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textline[3].reset("{24s}New Nightmare Game");
		(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textline[4].reset("{24s}New Hell Game");


		if (savegame_mode == (*global).game_mode)
		{
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].button[0].is_visisble = true; //hell button
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textline[0].reset("{24g}Load Previous Game");
		}
		if (stars > 0)
		{
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].button[2].is_visisble = true; //nm button
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textline[3].reset("{24g}New Nightmare Game");
		}

		if (stars > 1)
		{
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].button[3].is_visisble = true; //hell button
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textline[4].reset("{24g}New Hell Game");
		}

	}

	void gametype_set_button_active(int butt)
	{
		for (int i = 0; i <  4; i++)
		{
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].button[i].set_color(0,0,0,0);
		}

		if ( butt > -1 && butt < 4)
		{
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].button[butt].set_color(1, 0, 0, 0.15);
		}

		if (butt == 0)
		{
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textline[6].reset("Load");

			string* fieldinit = new string[6];
			fieldinit[0] = "Load Game:";
			fieldinit[1] = "";
			fieldinit[2] = "Continue your quest";
			fieldinit[3] = "to defeat ";
			fieldinit[3].append((*global).binblob.get_game_name(GAME_MODE_CLASSIC));
			fieldinit[3].append(" in");
			fieldinit[4] = "the game you have";
			fieldinit[5] = "saved.";
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textfield[0].reset(6, fieldinit);
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textfield[0].space_vertical();


		}
		else if (butt == 1)
		{
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textline[6].reset("Normal");

			string* fieldinit = new string[7];
			fieldinit[0] = "Normal Difficulty:";
			fieldinit[1] = "";
			fieldinit[2] = "This is where a";
			fieldinit[3] = "starting character";
			fieldinit[4] = "should begin the";
			fieldinit[5] = "quest to defeat";
			fieldinit[6] = (*global).binblob.get_game_name(GAME_MODE_CLASSIC);
			fieldinit[6].append(".");
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textfield[0].reset(7, fieldinit);
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textfield[0].space_vertical();

		}
		else if (butt == 2)
		{
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textline[6].reset("Nightmare");

			string* fieldinit = new string[10];
			fieldinit[0] = "Nightmare Difficulty:";
			fieldinit[1] = "";
			fieldinit[2] = "The denizens of the";
			fieldinit[3] = "labyrinth have been";
			fieldinit[4] = "bolstered and will";
			fieldinit[5] = "prove to be a greater";
			fieldinit[6] = "challenge. This is";
			fieldinit[7] = "recommended for";
			fieldinit[8] = "experienced characters";
			fieldinit[9] = "only.";
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textfield[0].reset(10, fieldinit);
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textfield[0].space_vertical();


		}
		else if (butt == 3)
		{
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textline[6].reset("Hell");

			string* fieldinit = new string[9];
			fieldinit[0] = "Hell Difficulty:";
			fieldinit[1] = "";
			fieldinit[2] = "The most powerful of";
			fieldinit[3] = "the underworld[squoc]s";
			fieldinit[4] = "creatures lurk at the";
			fieldinit[5] = "gateway into Hell. Only";
			fieldinit[6] = "the most experienced";
			fieldinit[7] = "characters should";
			fieldinit[8] = "venture into this realm.";
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textfield[0].reset(9, fieldinit);
			(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textfield[0].space_vertical();
		}

	}




	void multi_set_char_portrait_y(int value)
	{
		(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].doodad[1].tex_sub_group = value;
		(*global).screen[SCREEN_CHOOSE_CLASS].subscreen[0].doodad[1].tex_sub_group = value;
		(*global).screen[SCREEN_ENTER_NAME].subscreen[0].doodad[1].tex_sub_group = value;
	}

	void multi_set_class_tagline(string pclass, string tag)
	{
		(*global).screen[SCREEN_CHOOSE_CLASS].subscreen[0].textline[6].reset(tag);
		(*global).screen[SCREEN_ENTER_NAME].subscreen[0].textline[1].reset(tag);

		string newsp = "new single player ";
		newsp.append( pclass );
		(*global).screen[SCREEN_ENTER_NAME].subscreen[0].textline[11].reset(newsp);

	}

	void multi_set_save_discription(int expantion, string class_name, string char_name, int level, int game_diff, int stars)
	{

		string exp_and_class = "";

		if ( expantion == GAME_MODE_EXP)
		{
			exp_and_class = (*global).binblob.get_game_name(GAME_MODE_EXP);
			exp_and_class.append(" ");

		}
		exp_and_class.append(class_name);

		string fluff_level = "level: ";
		fluff_level.append(  util.int_to_string_no_leading_zero(level));

		string fluff_diff = "game: ";
		if (game_diff == GAME_DIFF_NORMAL) {fluff_diff.append("Normal");}
		else if (game_diff == GAME_DIFF_NIGHTMARE) {fluff_diff.append("Nightmare");}
		else if (game_diff == GAME_DIFF_HELL) {fluff_diff.append("Hell");}

		string fluff_stars = "";
		for (int i = 0; i < stars; i++)
		{
			fluff_stars.append("[bslsh]");
		}

		string class_char = class_name;
		class_char.append(  " " );
		class_char.append(char_name);


		(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].textline[5].reset(exp_and_class);
		(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].textline[6].reset(fluff_level);
		(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].textline[7].reset(fluff_diff);
		(*global).screen[SCREEN_SINGE_PLAYER].subscreen[0].textline[8].reset(fluff_stars);

		(*global).screen[SCREEN_SELECT_GAMETYPE].subscreen[0].textline[7].reset(class_char);
		class_char.append(  "?" );
		(*global).screen[SCREEN_DELETE_CHAR].subscreen[0].textline[1].reset(class_char);
	}


	void world_charstats_visible(int tri)
	{
		if (tri == DDT_FLIP)
		{
			(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_CHAR].visible =
			! (*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_CHAR].visible;
		}
		else if (tri == DDT_ON)
		{
			(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_CHAR].visible = true;
		}

		else if (tri == DDT_OFF)
		{
			(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_CHAR].visible = false;
		}



		if ((*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_CHAR].visible)
		{
			(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_CHAR].textline[0].reset(
					(*global).player.char_name.get());
			(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_CHAR].textline[1].reset(
					(*global).player.char_class.get());
		}
	}


	void world_inventory_visible(int tri)
	{
		if (tri == DDT_FLIP)
		{
			(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_INV].visible =
			! (*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_INV].visible;
		}
		else if (tri == DDT_ON)
		{
			(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_INV].visible = true;
		}

		else if (tri == DDT_OFF)
		{
			(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_INV].visible = false;
		}

	}


	void word_map_update_level_name()
	{
		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_MAP].textline[0].reset(
				(*global).level_name.get()
		);
	}

	void world_map_update_tile_select(int x, int y)
	{
		string out;
		out = util.int_to_string_no_leading_zero(x);
		out.append(", ");
		out.append(util.int_to_string_no_leading_zero(y));

		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_MAP].textline[1].reset(out);


	}

	void word_map_visible(int tri)
	{
		if (tri == DDT_FLIP)
		{
			(*global).player.show_map= !(*global).player.show_map;
		}
		else if (tri == DDT_ON)
		{
			(*global).player.show_map = true;
		}

		else if (tri == DDT_OFF)
		{
			(*global).player.show_map = false;
		}

		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_MAP].visible = (*global).player.show_map;

	}



	void world_menu_visible(int tri)
	{
		bool outcome;

		if (tri == DDT_FLIP)
		{
			outcome = !(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_MENU].visible;
		}
		else if (tri == DDT_ON) {outcome = true;}
		else if (tri == DDT_OFF) {outcome = false;}
		else {outcome = (*global).game_pause;}

		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_MENU].visible = outcome;
		(*global).game_pause = outcome;

	}

	void world_msg(string in)
	{
		if( in.size() == 0)
		{
			(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_MSG].visible = false;
		}
		else
		{
			(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_MSG].textline[0].reset(in);
			(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_MSG].visible = true;

		}
	}


	void world_story_visible(int tri)
	{
		bool outcome;

		if (tri == DDT_FLIP)
		{
			outcome = !(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_STORY].visible;
		}
		else if (tri == DDT_ON) {outcome = true;}
		else if (tri == DDT_OFF) {outcome = false;}
		else {outcome = (*global).game_pause;}

		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_STORY].visible = outcome;
		(*global).game_pause = outcome;
	}

	void world_story_update(int line_count, string* field)
	{
		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_STORY].textfield[0].reset(line_count,field);
		world_story_visible(DDT_ON);
		(*global).threadpush_audio(new mail(AUDIO_START_STORY));
	}

	void world_story_blob_update( string in)
	{
		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_STORY].textfield[0].reset_and_line_out(in, 40);
		world_story_visible(DDT_ON);
		(*global).threadpush_audio(new mail(AUDIO_START_STORY));
	}

	void world_story_reset_scroller()
	{
		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_STORY].textfield[0].scroller = 0;
	}

	void world_story_scroll_up(float value)
	{
		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_STORY].textfield[0].scroll_up(value);
	}

	void world_story_scroll_down(float value)
	{
		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_STORY].textfield[0].scroll_down(value);
	}

	void world_story_exit()
	{
		world_story_visible(DDT_OFF);
		(*global).threadpush_audio(new mail(AUDIO_STOP_STORY));

	}



	void world_hud_tooltip(string a, string b, string c, string d, string e)
	{
		int attempted_lines = 5;

		if ( e == "")
		{
			attempted_lines --;
			if ( d == "")
			{
				attempted_lines --;
				if ( c == "")
				{
					attempted_lines --;
					if ( b == "")
					{
						attempted_lines --;
						if ( a == "")
						{
							world_hud_tooltip_clear();
							return;
						}
					}
				}
			}
		}

		string* a_lines = new string[attempted_lines];
		if (attempted_lines > 0) {a_lines[0] = a;}
		if (attempted_lines > 1) {a_lines[1] = b;}
		if (attempted_lines > 2) {a_lines[2] = c;}
		if (attempted_lines > 3) {a_lines[3] = d;}
		if (attempted_lines > 4) {a_lines[4] = e;}

		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_ORBS].textfield[0].reset(attempted_lines, a_lines);
		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_ORBS].textfield[0].space_vertical();
	}

	void world_hud_tooltip_clear()
	{
		(*global).screen[SCREEN_WORLD].subscreen[SUBSCREEN_ORBS].textfield[0].clear();
	}

	void clean_world_ui()
	{
		word_map_update_level_name();

		word_map_visible(DDT_SYNC);
		world_menu_visible(DDT_OFF);
		world_inventory_visible(DDT_OFF);
		world_charstats_visible(DDT_OFF);
	}

	void wait_move_loadmsg_y(int spot)
	{
		(*global).screen[SCREEN_LOAD_WAIT].subscreen[0].textline[0].anchor_y = spot;
	}

	void wait_set_loadmsg(string in)
	{
		(*global).screen[SCREEN_LOAD_WAIT].subscreen[0].textline[0].reset(in);
	}

};
