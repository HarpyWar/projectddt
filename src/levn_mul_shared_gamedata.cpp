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




#include "levu_mul_ontile_elements.cpp"
using namespace std;

class globals
{
	public:

	mailbox filesystem_inbox;
	mailbox transcode_inbox;
	mailbox display_inbox;
	mailbox mousekeyb_inbox;
	mailbox audio_inbox;
	mailbox world_inbox;

	ddtmutex* filesystem_inbox_locker;
	ddtmutex* transcode_inbox_locker;
	ddtmutex* display_inbox_locker;
	ddtmutex* mousekeyb_inbox_locker;
	ddtmutex* audio_inbox_locker;
	ddtmutex* world_inbox_locker;

	ddtmutex* world_mousekeyb_lock;
	ddtmutex* world_display_lock;
	ddtmutex* world_world_lock;
	ddtmutex* world_shadow_lock;

	ddtmutex* tile_locker[128][128];


	int game_mode; // should become GAME_MODE_UNSET and let the filesystem thread load the right value
	int game_diff;

	// Thread flags
	volatile bool quit_game;
	volatile bool config_is_loaded;
	volatile bool audio_is_loaded;
	volatile bool display_is_up;
	volatile bool screens_are_loaded;

	volatile bool filesystem_thread_busy;
	volatile bool transcode_thread_busy;
	volatile bool display_thread_busy;


	volatile bool game_pause;




	// config load and settings edit stuff
	int display_w; // should be changed by config load to 640 or more
	int display_w_nexttime;
	int display_h;  // should be changed by config load to 480 or more
	int display_h_nexttime;
	int display_zoom;  //0 = no, 10 = full
	int display_zoom_nexttime;
	int display_gamma;  // 0 = normal, 10 = max
	int display_gamma_nexttime;
	int hud_transp;  // 0 = no, 10 = max
	int hud_transp_nexttime;
	bool blending;
	bool blending_nexttime;
	int sfx_volume;  // 0 = mute, 10 = max
	int sfx_volume_rollback;  // 0 = mute, 10 = max
	int music_volume;  // 0 = mute, 10 = max
	int music_volume_rollback;  // 0 = mute, 10 = max
	bool autosave;
	bool autosave_rollback;

	// the palette repository, all sizes are set so threadsafe
	palkeeper palkeep;
	monster_ref_keeper monsters;
	mechanic_ref_keeper mechanics;
	dungeonlook_keeper dunlooks;
	dungeon_ref_keeper dungeons;
	value_map_keeper valuemap;
	sectorfix_keeper sectorfix;
	item_type_keeper itemtype;
	global_binblob binblob;
	global_player player;



	// mouekeyboard should be the the only thread to chanage stuff here
	// render thread read this after it is initialised
	//----------------------------------------------------------
	ui_screen screen[SCREEN_COUNT];
	int active_screen; //levelz: SCREEN_COUNT







	// Constantly updated values
	volatile int mouse_at_x; // mouse position in game pixels
	volatile int mouse_at_y;
	volatile unsigned int ddt_time;  // 	SDL_GetTicks(); should be called regularely to replace this
	volatile unsigned int engine_tick;  // 	how many sycles has the world engine done







	//-----------------
	// game world stuff
	//-----------------

	//world status
	int level_number;
	threadsave_string level_name;
	//the dimensions can only be SET under lock_all_tiles()
	//the dimentions can be READ under any tile locked
	world_tile** tile;
	int tile_count_x;
	int tile_count_y;





	int ondisk_savegame_mode;
	int ondisk_savegame_dunno;






	globals()
	{
		game_mode = GAME_MODE_UNSET; // should become GAME_MODE_UNSET and let the filesystem thread load the right value
		game_diff = GAME_DIFF_NORMAL;

		quit_game = false;
		config_is_loaded = false;
		audio_is_loaded = false;
		display_is_up = false;
		screens_are_loaded = false;

		filesystem_thread_busy = false;
		transcode_thread_busy = false;
		display_thread_busy = false;


		game_pause = true;


		ddt_time = 0;
		engine_tick = 0;
		mouse_at_x = 0;
		mouse_at_y = 0;

		display_w = ORIGINAL_WIDTH; // should be changed by config load to 640 or more
		display_w_nexttime = ORIGINAL_WIDTH;
		display_h = ORIGINAL_HEIGHT;  // should be changed by config load to 480 or more
		display_h_nexttime = ORIGINAL_HEIGHT;
		display_zoom = 10; //0 = no, 10 = full
		display_zoom_nexttime = 10;
		display_gamma = 0; // 0 = normal, 10 = max
		display_gamma_nexttime = 0;
		hud_transp = 7;  // 0 = no, 10 = max
		hud_transp_nexttime = 7;
		blending = true;
		blending_nexttime = true;
		sfx_volume = 10; // 0 = mute, 10 = max
		sfx_volume_rollback = 10; // 0 = mute, 10 = max
		music_volume = 7; // 0 = mute, 10 = max
		music_volume_rollback = 7; // 0 = mute, 10 = max
		autosave = true;
		autosave_rollback = true;



		active_screen = -1; // should become SCREEN_TITLE after handler init




		level_number = 0;
		tile_count_x = 0;
		tile_count_y = 0;



		ondisk_savegame_mode = GAME_MODE_CLASSIC;
		ondisk_savegame_dunno = LEVEL_TOWN;

	}

	void init_mutex()
	{
		filesystem_inbox_locker = ddttime::create_mutex();
		transcode_inbox_locker = ddttime::create_mutex();
		display_inbox_locker = ddttime::create_mutex();
		mousekeyb_inbox_locker = ddttime::create_mutex();
		audio_inbox_locker = ddttime::create_mutex();
		world_inbox_locker = ddttime::create_mutex();

		world_mousekeyb_lock = ddttime::create_mutex();
		world_display_lock = ddttime::create_mutex();
		world_world_lock = ddttime::create_mutex();
		world_shadow_lock = ddttime::create_mutex();

		for (int i = 0; i < 128; i ++)
		{
			for (int j = 0; j < 128; j ++)
			{
				tile_locker[i][j] = ddttime::create_mutex();
			}
		}
	}

	bool something_is_loading()
	{
		if(
				filesystem_thread_busy ||
				transcode_thread_busy  ||
				display_thread_busy     )
		{
			return true;
		}
		return false;
	}

	void threadpush_filesystem(mail* in)
	{

		ddttime::lock_mutex(filesystem_inbox_locker);
		filesystem_inbox.push(in);
		ddttime::unlock_mutex(filesystem_inbox_locker);
	}

	mail* threadpop_filesystem()
	{
		ddttime::lock_mutex(filesystem_inbox_locker);
		mail* out = filesystem_inbox.pop();
		ddttime::unlock_mutex(filesystem_inbox_locker);
		return out;
	}

	void threadpush_transcode(mail* in)
	{
		ddttime::lock_mutex(transcode_inbox_locker);
		transcode_inbox.push(in);
		ddttime::unlock_mutex(transcode_inbox_locker);
	}

	mail* threadpop_transcode()
	{
		ddttime::lock_mutex(transcode_inbox_locker);
		mail* out = transcode_inbox.pop();
		ddttime::unlock_mutex(transcode_inbox_locker);
		return out;
	}

	void threadpush_display(mail* in)
	{
		ddttime::lock_mutex(display_inbox_locker);
		display_inbox.push(in);
		ddttime::unlock_mutex(display_inbox_locker);
	}

	mail* threadpop_display()
	{
		ddttime::lock_mutex(display_inbox_locker);
		mail* out = display_inbox.pop();
		ddttime::unlock_mutex(display_inbox_locker);
		return out;
	}

	void threadpush_mousekeyb(mail* in)
	{
		ddttime::lock_mutex(mousekeyb_inbox_locker);
		mousekeyb_inbox.push(in);
		ddttime::unlock_mutex(mousekeyb_inbox_locker);
	}

	mail* threadpop_mousekeyb()
	{
		ddttime::lock_mutex(mousekeyb_inbox_locker);
		mail* out = mousekeyb_inbox.pop();
		ddttime::unlock_mutex(mousekeyb_inbox_locker);
		return out;
	}

	void threadpush_audio(mail* in)
	{
		ddttime::lock_mutex(audio_inbox_locker);
		audio_inbox.push(in);
		ddttime::unlock_mutex(audio_inbox_locker);
	}

	mail* threadpop_audio()
	{
		ddttime::lock_mutex(audio_inbox_locker);
		mail* out = audio_inbox.pop();
		ddttime::unlock_mutex(audio_inbox_locker);
		return out;
	}

	void threadpush_world(mail* in)
	{
		ddttime::lock_mutex(world_inbox_locker);
		world_inbox.push(in);
		ddttime::unlock_mutex(world_inbox_locker);
	}

	mail* threadpop_world()
	{
		ddttime::lock_mutex(world_inbox_locker);
		mail* out = world_inbox.pop();
		ddttime::unlock_mutex(world_inbox_locker);
		return out;
	}


	void lock_all_tiles()
	{
		for (int i = 0; i < 128 ; i ++)
		{
			for (int j = 0; j < 128; j++)
			{
				ddttime::lock_mutex(tile_locker[i][j]);
			}
		}

		ddttime::lock_mutex(world_mousekeyb_lock);
		ddttime::lock_mutex(world_display_lock);
		ddttime::lock_mutex(world_world_lock);
		ddttime::lock_mutex(world_shadow_lock);
	}

	void unlock_all_tiles()
	{
		for (int i = 0; i < 128 ; i ++)
		{
			for (int j = 0; j < 128; j++)
			{
				ddttime::unlock_mutex(tile_locker[i][j]);
			}
		}

		ddttime::unlock_mutex(world_mousekeyb_lock);
		ddttime::unlock_mutex(world_display_lock);
		ddttime::unlock_mutex(world_world_lock);
		ddttime::unlock_mutex(world_shadow_lock);
	}


	void lock_mousekeyb_token() { ddttime::lock_mutex(world_mousekeyb_lock);}
	void unlock_mousekeyb_token() { ddttime::unlock_mutex(world_mousekeyb_lock);}

	void lock_display_token() { ddttime::lock_mutex(world_display_lock);}
	void unlock_display_token() { ddttime::unlock_mutex(world_display_lock);}

	void lock_world_token() { ddttime::lock_mutex(world_world_lock);}
	void unlock_world_token() { ddttime::unlock_mutex(world_world_lock);}

	void lock_shadow_token() { ddttime::lock_mutex(world_shadow_lock);}
	void unlock_shadow_token() { ddttime::unlock_mutex(world_shadow_lock);}

	void lock_tile(uint32_t tile_x, uint32_t tile_y)
	{
		uint32_t x_mod = tile_x & 0b00000000000000000000000001111111;
		uint32_t y_mod = tile_y & 0b00000000000000000000000001111111;
		ddttime::lock_mutex(tile_locker[x_mod][y_mod]);
	}

	void unlock_tile(uint32_t tile_x, uint32_t tile_y)
	{
		uint32_t x_mod = tile_x & 0b00000000000000000000000001111111;
		uint32_t y_mod = tile_y & 0b00000000000000000000000001111111;
		ddttime::unlock_mutex(tile_locker[x_mod][y_mod]);
	}

	void lock_second_tile(uint32_t own_x, uint32_t own_y, uint32_t tile_x, uint32_t tile_y)
	{
		uint32_t ox_mod = own_x  & 0b00000000000000000000000001111111;
		uint32_t oy_mod = own_y  & 0b00000000000000000000000001111111;
		uint32_t tx_mod = tile_x & 0b00000000000000000000000001111111;
		uint32_t ty_mod = tile_y & 0b00000000000000000000000001111111;
		if ( (ox_mod == tx_mod) && (oy_mod == ty_mod)) { return; }
		ddttime::lock_mutex(tile_locker[tx_mod][ty_mod]);
	}

	void unlock_second_tile(uint32_t own_x, uint32_t own_y, uint32_t tile_x, uint32_t tile_y)
	{
		uint32_t ox_mod = own_x  & 0b00000000000000000000000001111111;
		uint32_t oy_mod = own_y  & 0b00000000000000000000000001111111;
		uint32_t tx_mod = tile_x & 0b00000000000000000000000001111111;
		uint32_t ty_mod = tile_y & 0b00000000000000000000000001111111;
		if ( (ox_mod == tx_mod) && (oy_mod == ty_mod)) { return; }
		ddttime::unlock_mutex(tile_locker[tx_mod][ty_mod]);
	}


	void lock_tile(bool prevlock, uint32_t prevl_x, uint32_t prevl_y, uint32_t tile_x, uint32_t tile_y)
	{
		if (prevlock)
		{
			lock_second_tile(prevl_x, prevl_y, tile_x, tile_y);
		}
		else
		{
			lock_tile(tile_x, tile_y);
		}
	}

	void unlock_tile(bool prevlock, uint32_t prevl_x, uint32_t prevl_y, uint32_t tile_x, uint32_t tile_y)
	{
		if (prevlock)
		{
			unlock_second_tile(prevl_x, prevl_y, tile_x, tile_y);
		}
		else
		{
			unlock_tile(tile_x, tile_y);
		}
	}


	//only to be called under lock
	bool tile_exists(int x, int y)
	{
		if ( (x < tile_count_x) && (y < tile_count_y) && (x > -1) && (y > -1))
		{
			return true;
		}
		return false;
	}


};

class mousekeyb_local
{
	public:

	//only the mouekeyboard thread can touch this
	//----------------------------------------------
	int savegame_count; // how many savegames have we detected
	string* savegame; //the names of the savegames
	int* savegame_class; //what class is the save
	int* savegame_stars; // what diff level allowed
	int* savegame_level; // what level is the saved char
	int* savegame_diff; //current diff level
	int* savegame_expantion_status; //corresponds with GAME_MODE_DIABLO and GAME_MODE_HELLFIRE
	int* savegame_active_dungeon; //on what level is the player
	int selected_savegame; //what savegame is selected in the ui
	int savegame_scroller; //how many spots down is the savegame list in the ui scrolled


	int player_class_count; // how many actual classes are there
	int* player_class_portrait_y;
	string* player_class_name; //what are their names
	string* player_class_path; //what rulesfile path belong to the classes
	string* player_class_tagline; // like 'the shield.' or 'magic.'
	int selected_class; //what class is selected in the ui
	int class_scroller; //how many spots down is the class list in the ui scrolled

	ui_name_enter_string  entered_char_name; //what is the user entering for a char name

	int selected_game_type; // 0 = load, 1=new normal, 2 = new nm, 3 = new hell; 4 = new char

	string* opt_name; // game settings screen option name strings
	int opt_selected; //selected option
	int opt_scroller;



	mousekeyb_local()
	{
		//only the ui thread can touch this
		savegame_count = 0; // how many savegames have we detected
		selected_savegame = 0; //what savegame is selected in the ui
		savegame_scroller = 0; //how many spots down is the savegame list in the ui scrolled
		player_class_count = 0; // how many player classes have we detected
		selected_class = 0; //what class is selected in the ui
		class_scroller = 0; //how many spots down is the class list in the ui scrolled
		selected_game_type = 0;

		opt_name = new string[OPT_COUNT];
		opt_name[OPT_WIDTH] = "Window Width";
		opt_name[OPT_HEIGHT] = "Window Height";
		opt_name[OPT_ZOOM] = "Zoom";
		opt_name[OPT_BLEND] = "Blending";
		opt_name[OPT_GAMMA] = "Brightness";
		opt_name[OPT_ALPHA] = "Transparency";
		opt_name[OPT_SOUND] = "Sound Volume";
		opt_name[OPT_MUSIC] = "Music Volume";
		opt_name[OPT_AUTOSAVE] = "Auto Save";
		opt_selected = 0;
		opt_scroller = 0;
	}
};

class world_local
{
	public:

	// level load stuff
	unsigned char** sector;
	int* sector_byte_size;
	int sectors_count;






	player_class pclass; //the player char class
	player_savegame psave;

	world_local()
	{
		// level load stuff
		sectors_count = 0;

	}


};
