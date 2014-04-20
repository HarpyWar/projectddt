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



/*
project properties >
C/C++ build >
Settings >
Tool settings >
GCC C++ Linker >

Libraries:
GL
GLU
SDL
pthread
*/


#include "levg_tsc_transcode.cpp"

using namespace std;



SDL_Thread* filesystem_thread  = NULL;
SDL_Thread* transcode_thread = NULL;
SDL_Thread* display_thread = NULL;
SDL_Thread* mousekeyb_thread  = NULL;
SDL_Thread* audio_thread = NULL;
SDL_Thread* world_thread = NULL;
SDL_Thread* shadow_thread = NULL;

globals global;



int shadow_thread_func(void* data)
{

	shadow sha;

	while(!global.config_is_loaded) {ddttime::delay(50);}

	sha.in_thread_init(&global);

	while(!global.quit_game)
	{
		sha.run();
	}

	return 0;
}



int audio_thread_func(void* data )
{
	//global.audio_is_loaded = true;
	//return 0;

	while(!global.config_is_loaded) {ddttime::delay(50);}
	while(!global.display_is_up) {ddttime::delay(50);}

	audio_boss aud;
	mail* audio_mail;

	ddttime::delay(20);

	if( ddtaudio::init() != 0 ) {cout << "DDT> DDTaudio init fail" << endl; return 1;}


	aud.in_thread_init();


	global.audio_is_loaded = true;

	while(!global.quit_game)
	{
		if (global.audio_inbox.have_mail == false)
		{
			ddttime::delay(10);
		}
		else
		{

			audio_mail = global.threadpop_audio();


			if ((*audio_mail).command == THREAD_VOID_COMMAND)
			{
				ddttime::delay(10);
			}
			else if ((*audio_mail).command == AUDIO_LOAD)
			{
				aud.load((*audio_mail).pakno, (*audio_mail).keepno, (*audio_mail).floatarr, (*audio_mail).size_floatarr);
			}
			else if ((*audio_mail).command == AUDIO_PLAY_SFX)
			{

				aud.play_sfx((*audio_mail).keepno);

			}
			else if ((*audio_mail).command == AUDIO_PLAY_PAK_SFX)
			{

				aud.play_sfx((*audio_mail).keepno, (*audio_mail).allog);

			}
			else if ((*audio_mail).command == AUDIO_RESET_PAK_SIZE)
			{
				aud.init_pak((*audio_mail).keepno, (*audio_mail).allog);
			}

			else if ((*audio_mail).command == AUDIO_STOP_STORY)
			{
				aud.stop_story();
			}
			else if ((*audio_mail).command == AUDIO_START_STORY)
			{
				aud.start_story();
			}
			else
			{
				cout << "DDT> Audio thread received an unknown mail " << (*audio_mail).command << endl;
			}


			delete audio_mail;
		}

		aud.check_volume(global.sfx_volume, global.music_volume);

	}

	ddtaudio::close();

	return 0;
}


int filesystem_thread_func(void* data)
{
	loadsave io;
	mail* fs_mail;

	io.in_thread_init(&global);
	io.load_config();
	global.game_mode = io.check_game_mode();

	if (global.game_mode == GAME_MODE_UNSET )
	{
		global.quit_game = true;
		cout << "DDT> Can not find required files" << endl;
		return 1;
	}

	io.load_blob();

	ddttime::delay(20);
	global.config_is_loaded = true;

	cout << "DDT> Config is loaded." << endl;


	while(!global.quit_game)
	{
		if (global.filesystem_inbox.have_mail == false)
		{
			global.filesystem_thread_busy = false;
			ddttime::delay(30);
		}
		else
		{
			global.filesystem_thread_busy = true;

			fs_mail = global.threadpop_filesystem();

			if ((*fs_mail).command == THREAD_VOID_COMMAND)
			{
				ddttime::delay(30);
			}
			else if ((*fs_mail).command == FILEIO_LOAD_RULES)
			{
				io.load_rules((*fs_mail).argument);
			}
			else if ((*fs_mail).command == FILEIO_WRITE_CONFIG)
			{
				io.safe_config();
			}
			else if ((*fs_mail).command == FILEIO_GET_SAFELIST)
			{
				io.get_savelist();
			}
			else if ((*fs_mail).command == FILEIO_WRITE_SAVE)
			{
				io.write_save( (*fs_mail).filea,  (*fs_mail).size_filea);
			}
			else if ((*fs_mail).command == FILEIO_DELETE_SAVE)
			{
				io.remove_save( (*fs_mail).argument,  (*fs_mail).frames);
			}
			else if ((*fs_mail).command == FILEIO_LOAD_SAVE)
			{
				io.load_save();
			}
			else if ((*fs_mail).command == FILEIO_LOAD_PROVIDED_RULES)
			{
				io.load_rules(int_ucharp( (*fs_mail).size_filea, (*fs_mail).filea  ) )  ;
			}
			else
			{
				cout << "DDT> Filesys thread received an unknown mail " << (*fs_mail).command << endl;
			}

			delete fs_mail;
		}
	}

	return 0;
}

int transcode_thread_func(void *data)
{
	transcoder transc;
	mail* trans_mail;

	while(!global.config_is_loaded) {ddttime::delay(50);}

	ddttime::delay(100);

	transc.in_thread_init(&global);

	while(!global.quit_game)
	{
		if (global.transcode_inbox.have_mail == false)
		{
			global.transcode_thread_busy = false;
			ddttime::delay(30);
		}
		else
		{
			global.transcode_thread_busy = true;
			trans_mail = global.threadpop_transcode();


			if ((*trans_mail).command == THREAD_VOID_COMMAND )
			{
				ddttime::delay(30);
			}
			else if ((*trans_mail).command == TRANSCODE_GRFX )
			{
				transc.transcode_grfx(trans_mail);
			}
			else if ((*trans_mail).command == TRANSCODE_RESET_GRFX_PAK )
			{
				//just forwarding this this
				global.threadpush_display(new mail(DISPLAY_RESET_PAK_SIZE, (*trans_mail).keepno, (*trans_mail).allog));
			}
			else if ((*trans_mail).command == TRANSCODE_UNLOAD_GRFX )
			{
				//just forwarding this this
				global.threadpush_display(new mail(DISPLAY_UNLOAD_PAK_MEMBER, (*trans_mail).keepno, (*trans_mail).allog));
			}
			else if ((*trans_mail).command == TRANSCODE_RESET_AUDIO_PAK )
			{
				//just forwarding this this
				global.threadpush_audio(new mail(AUDIO_RESET_PAK_SIZE, (*trans_mail).keepno, (*trans_mail).allog));
			}
			else if ((*trans_mail).command == TRANSCODE_AUDIO )
			{
				transc.transcode_audio(trans_mail);
			}
			else
			{
				cout << "DDT> Transcode thread received an unknown mail " << (*trans_mail).command << endl;
			}

			delete trans_mail;
		}
	}

	return 0;
}

int display_thread_func(void *data)
{
	renderer rendy;
	mail* disp_mail;

	while(!global.config_is_loaded) {ddttime::delay(50);}

	if( ddtgrfx::init() != 0 ) {cout << "DDT>  DDTgrfx Init Display fail" << endl; return 1;}

	uint32_t pre_loop_time;
	uint32_t post_loop_time;
	uint32_t loop_duration;

	while(!global.screens_are_loaded) {ddttime::delay(50);}


	ddttime::delay(100);

	rendy.in_thread_init(&global);


	ddttime::delay(200);
	global.display_is_up = true;

	cout << "DDT> Display is up." << endl;




	while (!global.quit_game)
	{
		pre_loop_time = global.ddt_time;

		if (global.display_inbox.have_mail == true)
		{
			global.display_thread_busy = true;
			disp_mail = global.threadpop_display();

			if ((*disp_mail).command == THREAD_VOID_COMMAND )
			{
				global.display_thread_busy = false;
			}
			else if ((*disp_mail).command == DISPLAY_LOAD_CHUNKS )
			{
				rendy.texkeep.set_pak_member((*disp_mail).pakno,(*disp_mail).keepno, (*disp_mail).tchunk, (*disp_mail).size_tchunk);
			}
			else if ((*disp_mail).command == DISPLAY_UNLOAD_PAK_MEMBER )
			{
				rendy.texkeep.kill_pak_member((*disp_mail).keepno, (*disp_mail).allog);
			}

			else if ((*disp_mail).command == DISPLAY_RESET_PAK_SIZE)
			{
				rendy.texkeep.init_pak((*disp_mail).keepno, (*disp_mail).allog);

			}
			else
			{
				cout << "DDT> Display thread received an unknown mail " << (*disp_mail).command << endl;
			}

			delete disp_mail;
		}
		else
		{
			global.display_thread_busy = false;
		}

		rendy.render_screen();

		post_loop_time = global.ddt_time;
		loop_duration = post_loop_time - pre_loop_time;
		if (loop_duration < RENDER_DELAY_TIME)
		{
			ddttime::delay(RENDER_DELAY_TIME - loop_duration);
		}


	}

	cout << "DDT> Closing display." << endl;
	ddtgrfx::close();

	return 0;
}

int mousekeyb_thread_func(void *data)
{

	ui_handler uihand;
	mail* mk_mail;


	while(!global.config_is_loaded) {ddttime::delay(50);}

	ddttime::delay(100);

	uihand.in_thread_init(&global);

	ddttime::delay(100);
	global.screens_are_loaded = true;
	cout << "DDT> Screens are loaded." << endl;


	while(!global.display_is_up) {ddttime::delay(50);}

	ddttime::delay(50);


	ddtinput::init();


	while(!global.quit_game)
	{


		ddttime::delay( 10 );



		while (global.mousekeyb_inbox.have_mail == true)
		{

			mk_mail = global.threadpop_mousekeyb();


			if ((*mk_mail).command == THREAD_VOID_COMMAND )
			{
				//nothing
			}
			else if ((*mk_mail).command == MOUSEKEYB_UPDATE_SAVELIST)
			{
				uihand.update_savelist((*mk_mail).frames, (*mk_mail).argument);
			}
			else if ((*mk_mail).command == MOUSEKEYB_UPDATE_CLASSLIST)
			{
				uihand.update_classlist((*mk_mail).keepno, (*mk_mail).filea, (*mk_mail).size_filea);
			}
			else if ((*mk_mail).command == MOUSEKEYB_UPDATE_CREDITS)
			{
				uihand.update_credits((*mk_mail).keepno, (*mk_mail).filea, (*mk_mail).size_filea);
			}
			else if ((*mk_mail).command == MOUSEKEYB_SET_STORY)
			{
				uihand.set_story((*mk_mail).keepno, (*mk_mail).filea, (*mk_mail).size_filea);
			}
			else if ((*mk_mail).command == MOUSEKEYB_SET_BLOB_STORY)
			{
				uihand.set_blob_story((*mk_mail).keepno);
			}
			else if ((*mk_mail).command == MOUSEKEYB_SET_MSG)
			{
				uihand.set_msg((*mk_mail).argument);
			}
			else if ((*mk_mail).command == MOUSEKEYB_CLEAN_WORLD_UI)
			{
				uihand.butt_command.screen_man.clean_world_ui();
				uihand.butt_command.move_map(DIRECTION_SE);
			}
			else if ((*mk_mail).command == MOUSEKEYB_MOVE_LOADMSG_Y)
			{
				//cout << "move lmsgy " << (*mk_mail).keepno << endl;

				uihand.butt_command.screen_man.wait_move_loadmsg_y((*mk_mail).keepno);
			}
			else if ((*mk_mail).command == MOUSEKEYB_SET_LOADMSG)
			{
				//cout << "move lmsgy " << (*mk_mail).keepno << endl;

				uihand.butt_command.screen_man.wait_set_loadmsg((*mk_mail).argument);
			}




			else
			{
				cout << "DDT> Mousekeyb thread received an unknown mail" << (*mk_mail).command << endl;
			}


			delete mk_mail;
		}

		uihand.run();

	}

	ddtinput::close();

	return 0;
}

int world_thread_func(void *data)
{
	world_manager worldman;
	mail* world_mail;

	uint32_t pre_loop_time;
	uint32_t post_loop_time;
	uint32_t loop_duration;

	while(!global.config_is_loaded) {ddttime::delay(50);}
	ddttime::delay(100);

	worldman.in_thread_init(&global);

	ddttime::delay(100);

	while (!global.quit_game)
	{
		pre_loop_time = global.ddt_time;

		while (global.world_inbox.have_mail == true)
		{
			world_mail = global.threadpop_world();
			if ((*world_mail).command == THREAD_VOID_COMMAND )
			{
				//nothing
			}
			else if ((*world_mail).command == WORLD_START_CHAIN_NEWCHAR)
			{
				worldman.start_chain_newchar();
			}
			else if ((*world_mail).command == WORLD_START_CHAIN_NEWGAME)
			{
				worldman.start_chain_newgame();
			}
			else if ((*world_mail).command == WORLD_START_CHAIN_OLDGAME)
			{
				worldman.start_chain_oldgame();
			}

			else if ((*world_mail).command == WORLD_START_CHAIN_CHANGEDUN)
			{
				worldman.start_chain_change_dun((*world_mail).keepno);
			}

			else if ((*world_mail).command == WORLD_LOAD_LEVEL)
			{
				worldman.load_level((*world_mail).filea, (*world_mail).size_filea);
			}
			else if ((*world_mail).command == WORLD_LEFT_CLICK)
			{
				worldman.player_left_clicked((*world_mail).keepno, (*world_mail).allog);
			}
			else if ((*world_mail).command == WORLD_RIGHT_CLICK)
			{
				worldman.player_right_clicked((*world_mail).keepno, (*world_mail).allog);
			}
			else if ((*world_mail).command == WORLD_LOAD_CLASS)
			{
				worldman.load_class((*world_mail).filea, (*world_mail).size_filea);
			}
			else if ((*world_mail).command == WORLD_LOAD_SAVE)
			{
				worldman.load_save((*world_mail).filea, (*world_mail).size_filea);
			}
			else if ((*world_mail).command == WORLD_MAKE_SAVEGAME)
			{
				worldman.make_manual_savegame();
			}
			else if ((*world_mail).command == WORLD_SAVEGAME_IS_WRITTEN)
			{
				worldman.accept_manual_savegame_sucess();
			}
			else if ((*world_mail).command == WORLD_SECTOR_HOTFIX)
			{
				worldman.sector_hotfix((*world_mail).keepno);
			}
			else
			{
				cout << "DDT> World thread received an unknown mail " << (*world_mail).command << endl;
			}

			delete world_mail;
		}

		worldman.update_tiles();

		post_loop_time = global.ddt_time;
		loop_duration = post_loop_time - pre_loop_time;
		if (loop_duration <  WORLD_DELAY_TIME)
		{
			ddttime::delay(WORLD_DELAY_TIME - loop_duration);
		}

	}

	return 0;
}



int main( int argc, char *argv[] )
{

	ddtmath::init(); //random generator
	if( ddttime::init() != 0 ) {cout << "DDT> SDL_Init fail" << endl; return 1;}
	global.init_mutex();

	global.threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::pals()));
	global.threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::classlist()));
	global.threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::monsters()));
	global.threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::mechs()));
	global.threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::itemtype()));
	global.threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::dunlooks()));
	global.threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::dungeons()));
	global.threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::valuemap()));
	global.threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::sectorfix()));
	global.threadpush_filesystem(new mail(FILEIO_LOAD_RULES, ddtrules::start()));



	audio_thread = SDL_CreateThread( audio_thread_func, NULL );
	ddttime::delay(20);
	filesystem_thread = SDL_CreateThread(filesystem_thread_func, NULL);
	ddttime::delay(20);
	world_thread = SDL_CreateThread( world_thread_func, NULL );
	ddttime::delay(20);
	shadow_thread = SDL_CreateThread( shadow_thread_func, NULL );
	ddttime::delay(20);
	transcode_thread = SDL_CreateThread(transcode_thread_func, NULL);
	ddttime::delay(20);
	display_thread = SDL_CreateThread( display_thread_func, NULL );
	ddttime::delay(20);
	mousekeyb_thread = SDL_CreateThread( mousekeyb_thread_func, NULL );



	while (!global.quit_game)
	{

		global.ddt_time = ddttime::get();
		ddttime::delay(1);

	}

	ddttime::delay(200);

	ddttime::close();
	return 0;

}




