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




#include "levk_rnd_keeper_tex.cpp"
using namespace std;

class ui_handler
{
public:

	globals* global;
	mousekeyb_local* local;
	button_commando butt_command;
	utils util;
	mail* post;


	ddtinput_event event;
	int event_type;
	uint16_t event_x;
	uint16_t event_y;

	float display_w;
	float display_h;
	float display_scale_inverse;

	unsigned int l_mouse_time;
	unsigned int r_mouse_time;


	unsigned int slow_regular_update_time;
	unsigned int button_hoover_time;
	unsigned int screen_msg_time;


	unsigned int ddt_time;
	int act_screen;

	int mouse_at_x;
	int mouse_at_y;








	public:


	ui_handler()
	{
		local = new mousekeyb_local;
		button_hoover_time = 0;
		ddt_time = 0;
		slow_regular_update_time = 0;

		l_mouse_time = 0;;
		r_mouse_time = 0;;

	}

	void in_thread_init(globals* glob)
	{
		global = glob;
		butt_command.button_commando_set(global, local);

		display_w = (*global).display_w;
		display_h = (*global).display_h;
		display_scale_inverse =  1.0 / (ddtgrfx::find_display_scale(display_w, display_h, (*global).display_zoom));

	}


	void run()
	{
		ddt_time = (*global).ddt_time;
		act_screen = (*global).active_screen;

		//ddtinput::mouse_move_update(&event_x, &event_y);
		//handle_mouse_move(event_x, event_y);

		while(ddtinput::get_event(&event, &event_type, &event_x, &event_y))
		{
			switch(event_type)
			{
			 case DDTINPUT_UNKNOWN : break;
			 case DDTINPUT_QUIT : (*global).quit_game = true; break;
			 case DDTINPUT_MOUSE_MOVE : handle_mouse_move(event_x, event_y); break;
			 case DDTINPUT_MOUSE_LEFT_UP : l_mouse_time = 0; break;
			 case DDTINPUT_MOUSE_RIGHT_UP : r_mouse_time = 0; break;
			 case DDTINPUT_MOUSE_LEFT_DOWN :
				 handle_mouse_move(event_x, event_y);
				 handle_event_mouse_left(); break;
			 case DDTINPUT_MOUSE_RIGHT_DOWN :
				 handle_mouse_move(event_x, event_y);
				 handle_event_mouse_right(); break;
			}
		}

		regular_update();
		slow_ui_update();

	}

	void slow_ui_update()
	{
		if (slow_regular_update_time < ddt_time - UI_SLOW_UPDATE && ((*global).active_screen == SCREEN_WORLD))
		 {
			 slow_regular_update_time = ddt_time;


			//butt_command.screen_man.word_map_update_level_name();
			//if ((*global).player.show_map) { butt_command.screen_man.word_map_visible(true);}
			//else { butt_command.screen_man.word_map_visible(false);}


		 }
	}



	void regular_update()
	{


		if(button_hoover_time < ddt_time - MOUSEOVER_TIMEOUT)
		{

			button_hoover_time = ddt_time;
			di_int ss_and_b = (*global).screen[act_screen].susbscreen_and_button_for_mouse_at(mouse_at_x, mouse_at_y);

			if (ss_and_b.y > -1) //we have a new selection target
			{
				if ((*global).screen[act_screen].subscreen[ss_and_b.x].button[ss_and_b.y].is_selected == false)
				{
					// button was not selected before so play sound
					if (  ( (*global).screen[act_screen].subscreen[ss_and_b.x].button[ss_and_b.y].mouseover_sound) != (VOID_SOUND)  )
					{
						post = new mail(AUDIO_PLAY_SFX,(*global).screen[act_screen].subscreen[ss_and_b.x].button[ss_and_b.y].mouseover_sound);
						(*global).threadpush_audio(post);

					}
				}


				(*global).screen[act_screen].unselect_all_buttons(true);  //this might flicker on screen
				(*global).screen[act_screen].subscreen[ss_and_b.x].button[ss_and_b.y].is_selected = true;

			}
			else // just unselecting the non-stickies
			{
				(*global).screen[act_screen].unselect_all_buttons(false);
			}

			if ((ss_and_b.x < 0) && ((*global).active_screen == SCREEN_WORLD) && (!(*global).game_pause))
			{
				butt_command.world_mouse_hoover_at(mouse_at_x, mouse_at_y);
			}


			if (screen_msg_time + WORLD_MSG_SCREEN_TIMEOUT < ddt_time && screen_msg_time != 0)
			{
				butt_command.screen_man.world_msg("");
				screen_msg_time = 0;

			}
		}
	}




	void handle_mouse_move(int16_t x, int16_t y)
	{
		(*global).mouse_at_x = ddtgrfx::mouse_x(x, display_w) * display_scale_inverse;
		(*global).mouse_at_y = ddtgrfx::mouse_y(y, display_h) * display_scale_inverse;
		mouse_at_x = (*global).mouse_at_x;
		mouse_at_y = (*global).mouse_at_y;
	}

	void handle_event_mouse_left()
	{

		if(!(l_mouse_time < ddt_time - BUTTON_TIMEOUT)){return;}
		l_mouse_time = ddt_time;

		di_int ss_and_b = (*global).screen[act_screen].susbscreen_and_button_for_mouse_at(mouse_at_x, mouse_at_y);

		if (ss_and_b.y > -1) //we have a button
		{
			if (  ( (*global).screen[act_screen].subscreen[ss_and_b.x].button[ss_and_b.y].klick_it_sound) != (VOID_SOUND)  )
			{
				post = new mail(AUDIO_PLAY_SFX,(*global).screen[act_screen].subscreen[ss_and_b.x].button[ss_and_b.y].klick_it_sound);
				(*global).threadpush_audio(post);
			}


			butt_command.command((*global).screen[act_screen].subscreen[ss_and_b.x].button[ss_and_b.y].button_command);
		}
		else if ( (ss_and_b.x < 0) && ((*global).active_screen == SCREEN_WORLD))
		{
			//we have a click in the game world
			butt_command.world_left_click(mouse_at_x, mouse_at_y);

		}

	}

	void handle_event_mouse_right()
	{
		if(!(r_mouse_time < ddt_time - BUTTON_TIMEOUT)){return;}
		r_mouse_time = ddt_time;

		di_int ss_and_b = (*global).screen[act_screen].susbscreen_and_button_for_mouse_at(mouse_at_x, mouse_at_y);
		if (ss_and_b.y > -1) //we have a button
		{
			if (  ( (*global).screen[act_screen].subscreen[ss_and_b.x].button[ss_and_b.y].klick_it_sound) != (VOID_SOUND)  )
			{
				post = new mail(AUDIO_PLAY_SFX,(*global).screen[act_screen].subscreen[ss_and_b.x].button[ss_and_b.y].klick_it_sound);
				(*global).threadpush_audio(post);
			}


			butt_command.command((*global).screen[act_screen].subscreen[ss_and_b.x].button[ss_and_b.y].button_command);
		}
		else if ( (ss_and_b.x < 0) && ((*global).active_screen == SCREEN_WORLD))
		{
			//we have a click in the game world
			butt_command.world_right_click(mouse_at_x, mouse_at_y);

		}

	}

	void handle_event_mouse_middle()
	{


	}

	void set_msg(string in)
	{
		butt_command.screen_man.world_msg(in);
		screen_msg_time = ddt_time;
	}







	void update_savelist(int savecount, string saves)
	{
		if (savecount < 0) {cout << "DDT> update_savelist recieved bad info" << endl; return;}

		if ((*local).savegame_count > 0)
		{
			delete[] (*local).savegame;
			delete[] (*local).savegame_class;
			delete[] (*local).savegame_stars;
			delete[] (*local).savegame_level;
			delete[] (*local).savegame_diff;
			delete[] (*local).savegame_expantion_status;
			delete[] (*local).savegame_active_dungeon;


			(*local).savegame_count = 0;
		}

		(*local).savegame_count = savecount + 1; // making room for "new hero"


		(*local).savegame = new string[(*local).savegame_count];
		(*local).savegame_class = new int[(*local).savegame_count];
		(*local).savegame_stars = new int[(*local).savegame_count];
		(*local).savegame_level = new int[(*local).savegame_count];
		(*local).savegame_diff = new int[(*local).savegame_count];
		(*local).savegame_expantion_status = new int[(*local).savegame_count];
		(*local).savegame_active_dungeon = new int[(*local).savegame_count];



		for (int i = 0 ; i < (*local).savegame_count; i++) //just init everything as new hero for convenience
		{
			(*local).savegame[i] = "new hero";
			(*local).savegame_class[i] = 99; // just some number, wont be red anyway.
			(*local).savegame_stars[i] = 0;
			(*local).savegame_level[i] = 1;
			(*local).savegame_diff[i] = 0;
			(*local).savegame_expantion_status[i] = GAME_MODE_CLASSIC;
			(*local).savegame_active_dungeon[i] = LEVEL_TOWN;
		}

		int input_size = saves.size();
		int input_point = 0;
		int save_slot_point = 0;

		while ((input_point < input_size) && (save_slot_point < savecount))
		{

			(*local).savegame_class[save_slot_point] = util.get_int_at(input_point, saves);
			input_point = input_point+5;
			(*local).savegame_stars[save_slot_point] = util.get_int_at(input_point, saves);
			input_point = input_point+5;
			(*local).savegame_level[save_slot_point] = util.get_int_at(input_point, saves);
			input_point = input_point+5;
			(*local).savegame_diff[save_slot_point] = util.get_int_at(input_point, saves);
			input_point = input_point+5;
			(*local).savegame_expantion_status[save_slot_point] = util.get_int_at(input_point, saves);
			input_point = input_point+5;
			(*local).savegame_active_dungeon[save_slot_point] = util.get_int_at(input_point, saves);
			input_point = input_point+5;

			(*local).savegame[save_slot_point] = "";

			while ( saves.at(input_point) != '@')
			{
				(*local).savegame[save_slot_point].push_back(saves.at(input_point));
				input_point++;
			}


			input_point++;
			save_slot_point ++;

		}

		(*local).selected_savegame = 0;
		(*local).savegame_scroller = 0;

		butt_command.update_savelist_lines();
		butt_command.update_savegame_selected();
	}

	void update_classlist(int class_count, unsigned char* block, int block_size)
	{

		if (class_count < 1 || block_size < 1) { cout << "DDT> update_classlist bad info" << endl; return;}

		if ((*local).player_class_count > 0)
		{
			delete[] (*local).player_class_portrait_y;
			delete[] (*local).player_class_name;
			delete[] (*local).player_class_path;
			delete[] (*local).player_class_tagline;

		}
		(*local).selected_class = 0;
		(*local).class_scroller = 0;
		(*local).player_class_count = class_count;
		(*local).player_class_portrait_y = new int[class_count];
		(*local).player_class_name = new string[class_count];
		(*local).player_class_path = new string[class_count];
		(*local).player_class_tagline = new string[class_count];



		int block_point = 0;

		while ( block_point + 20 < block_size)
		{
			if (
					(block[block_point + 0] == '(') &&
					(block[block_point + 1] == 'c') &&
					(block[block_point + 2] == 'l') &&
					(block[block_point + 3] == 'a') &&
					(block[block_point + 4] == 's') &&
					(block[block_point + 5] == 's') &&
					(block[block_point + 6] == ')') )
			{
				int classno = util.get_int_at(block_point + 8, block, block_size);
				string class_name = (*global).binblob.get_class_name(classno);
				int port = util.get_int_at(block_point + 14, block, block_size);
				string tagl = util.get_argument_at(block_point + 20, block, block_size);
				string cpath = util.get_argument_at(block_point + 35, block, block_size);

				if (classno < 0 || classno > class_count -1)
				{
					cout << "DDT> Bad classlist entry" << endl;
				}
				else
				{
					(*local).player_class_portrait_y[classno] = port;
					(*local).player_class_name[classno] = class_name;
					(*local).player_class_tagline[classno] = tagl;
					(*local).player_class_path[classno] = cpath;
				}
			}
			block_point++;
		}
		butt_command.update_classlist_lines();
		delete[] block;
	}


	void update_credits(int lines, unsigned char* block, int block_size)
	{
		if (lines > 0 && block_size > 0)
		{
			string* txtblock = new string[lines];
			int txtblock_linepoint = 0;
			int rawpoint = 0;
			unsigned char curchar;

			while (txtblock_linepoint < lines && rawpoint < block_size)
			{
				rawpoint++;
				curchar =  (block)[rawpoint];
				if (curchar == '@')
				{
					txtblock_linepoint++;
				}
				else
				{
					(txtblock[txtblock_linepoint]).append(1, curchar);
				}
			}


			butt_command.screen_man.credits_update(lines, txtblock);
			delete[] block;

		}

	}

	void set_story(int lines, unsigned char* block, int block_size)
	{
		if (lines > 0 && block_size > 0)
		{
			string* txtblock = new string[lines];
			int txtblock_linepoint = 0;
			int rawpoint = 0;
			unsigned char curchar;

			while (txtblock_linepoint < lines && rawpoint < block_size)
			{
				rawpoint++;
				curchar =  (block)[rawpoint];
				if (curchar == '@')
				{
					txtblock_linepoint++;
				}
				else
				{
					(txtblock[txtblock_linepoint]).append(1, curchar);
				}
			}



			butt_command.screen_man.world_story_update(lines, txtblock);
			butt_command.screen_man.world_story_reset_scroller();

			delete[] block;

		}

	}

	void set_blob_story(int no)
	{

		string test = (*global).binblob.get_story(no);

		butt_command.screen_man.world_story_blob_update(test);
		butt_command.screen_man.world_story_reset_scroller();

	}





};
