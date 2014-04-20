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



#include "levk_tsc_soundmaker_wav.cpp"
using namespace std;


class tile_object_interactor
{
	public:

	globals* global;
	world_local* local;
	utils util;
	mail* post;

	void init(globals* glob, world_local* loc)
	{
		global = glob;
		local = loc;
	}

	void player_going_for_a_walk(int dest_x, int dest_y)
	{
		int player_x = (*global).player.player_at_x_int;
		int player_y = (*global).player.player_at_y_int;

		(*global).lock_tile(player_x, player_y);
		if ( (*global).tile_exists(player_x, player_y))
		{
			tile_monster* player = find_player_on_tile(player_x, player_y);
			(*player).intention = INTENTION_WALK;
			(*player).intention_target_x = dest_x;
			(*player).intention_target_y = dest_y;
		}
		else
		{
			cout << "DDT>  tile_object_interactor failed to find the player tile!!!!!!!!!!!!!!!" << endl;
		}
		(*global).unlock_tile(player_x, player_y);
	}

	void player_to_teleport_to(int dest_x, int dest_y)
	{
		int player_x = (*global).player.player_at_x_int;
		int player_y = (*global).player.player_at_y_int;

		(*global).lock_tile(player_x, player_y);


		if ( (*global).tile_exists(player_x, player_y))
		{

			tile_monster* player = find_player_on_tile(player_x, player_y);
			(*player).intention = INTENTION_TELEPORT;
			(*player).intention_target_x = dest_x;
			(*player).intention_target_y = dest_y;

		}

		else
		{
			cout << "DDT>  world_manager player_left_clicked failed to find the player tile!!!!!!!!!!!!!!!" << endl;
		}

		(*global).unlock_tile(player_x, player_y);
	}


	void void_player_intention()
	{
		int player_x = (*global).player.player_at_x_int;
		int player_y = (*global).player.player_at_y_int;

		(*global).lock_tile(player_x, player_y);

		if ( (*global).tile_exists(player_x, player_y))
		{
			tile_monster* player = find_player_on_tile(player_x, player_y);
			(*player).intention = INTENTION_IDLE;
		}

		else
		{
			cout << "DDT>  world_manager void_player_intention failed to find the player tile!!!!!!!!!!!!!!!" << endl;
		}

		(*global).unlock_tile(player_x, player_y);
	}



	void player_to_monster_interaction(int16_t montype, int monster_at_x, int monster_at_y)
	{
		if ( !(*global).monsters.exists(montype)) {return;}


		switch((*global).monsters.mon[montype].interaction_ref)
		{
			case MONSTER_INTERACTION_REF_VOID : break;
			case MONSTER_INTERACTION_REF_ANIMAL : creature_poking((*global).monsters.mon[montype].pakref_aud); break;
			case MONSTER_INTERACTION_REF_GOLDGIVER : goldgiver(monster_at_x, monster_at_y); break;
		}

	}

	void player_to_mechanic_interaction(int16_t mechtype, int mech_at_x, int mech_at_y)
	{
		if ( !(*global).mechanics.exists(mechtype)) {return;}

		switch((*global).mechanics.mech[mechtype].interaction_ref)
		{
			case MECHANIC_INTERACTION_REF_VOID : break;
			case MECHANIC_INTERACTION_REF_STASH : open_stash(); break;
			case MECHANIC_INTERACTION_REF_WARP : warp_to_level(mechtype); break;
			case MECHANIC_INTERACTION_REF_AUDIOBOOK : audio_book(mechtype, mech_at_x, mech_at_y); break;
			case MECHANIC_INTERACTION_REF_LEVER : lever(mechtype, mech_at_x, mech_at_y); break;
		}

	}

	void creature_poking(int16_t pakref)
	{

		int sound = ddtmath::random_int(0,50);
		if ( sound > 1) {return;}

		post = new mail(AUDIO_PLAY_PAK_SFX, pakref, sound);
		(*global).threadpush_audio(post);
	}

	void goldgiver(int x, int y)
	{

		di_int spot = tileopp::find_and_lock_tile_to_drop_item(global, false, 0, 0, x, y);
		if(spot.x < 0) {return;}


		game_item* gld = new game_item;
		(*gld).type = ITEM_TYPE_MONEY;
		(*gld).stack_size = (uint32_t) ddtmath::random_int(1, 5000000);


		(*global).tile[spot.x][spot.y].place_item(gld);

		int flipsfx = (*global).itemtype.give_flip_sfx((*gld).type);



		(*global).unlock_tile(spot.x, spot.y);

		post = new mail(AUDIO_PLAY_PAK_SFX, PAK_DEFAULT, flipsfx);
		(*global).threadpush_audio(post);

	}



	void open_stash()
	{
		void_player_intention();
		post = new mail(MOUSEKEYB_SET_MSG, "Stash!");
		(*global).threadpush_mousekeyb(post);



	}

	void warp_to_level(int16_t mechtype)
	{
		(*global).active_screen = SCREEN_LOAD_WAIT;
		(*global).game_pause = true;

		string newbg = (*global).mechanics.get_loadref(mechtype);
		post = new mail(FILEIO_LOAD_RULES, newbg);
		(*global).threadpush_filesystem(post);

		post = new mail( WORLD_START_CHAIN_CHANGEDUN, mechtype);
		(*global).threadpush_world(post);

	}

	void audio_book(int16_t mechtype, int x, int y)
	{
		if (!(*global).mechanics.exists(mechtype)) {return;}

		(*global).lock_tile(x,y);
		if ((*global).tile_exists(x,y))
		{
			if ((*global).tile[x][y].has_mechanic)
			{
				(*(*global).tile[x][y].mech).is_open = true;
			}
		}
		(*global).unlock_tile(x,y);

		//use it sound
		int pakref = (*global).mechanics.mech[mechtype].pakref_aud;
		post = new mail(AUDIO_PLAY_PAK_SFX, pakref, 0);
		(*global).threadpush_audio(post);

		//payload
		string loadstring = (*global).mechanics.get_loadref(mechtype);
		post = new mail(FILEIO_LOAD_RULES, loadstring);
		(*global).threadpush_filesystem(post);

	}

	void lever(int16_t mechtype, int x, int y)
	{
		if (!(*global).mechanics.exists(mechtype)) {return;}

		bool proceed = false;
		(*global).lock_tile(x,y);
		if ((*global).tile_exists(x,y))
		{
			if ((*global).tile[x][y].has_mechanic)
			{
				if ((*(*global).tile[x][y].mech).is_open)
				{
					(*(*global).tile[x][y].mech).is_open = false;
					proceed = true;
				}
			}
		}
		(*global).unlock_tile(x,y);
		if (!proceed) {return;}

		//use it sound
		int pakref = (*global).mechanics.mech[mechtype].pakref_aud;
		post = new mail(AUDIO_PLAY_PAK_SFX, pakref, 0);
		(*global).threadpush_audio(post);

		//msg
		string msg = (*global).mechanics.mech[mechtype].loadref.get();
		post = new mail(MOUSEKEYB_SET_MSG, msg);
		(*global).threadpush_mousekeyb(post);

		//sectorfix
		int fix = (*global).mechanics.mech[mechtype].other_mech_ref;
		post = new mail(WORLD_SECTOR_HOTFIX, fix);
		(*global).threadpush_world(post);


	}






	// tile lock assumed and tile must exist!!!!!!!!!!!!!!
	tile_monster* find_player_on_tile(int x, int y)
	{
		tile_monster* out;
		(*global).tile[x][y].monsters.reset_itt();


		while( (*global).tile[x][y].monsters.can_request_next())
		{
			out = (*global).tile[x][y].monsters.request_next();

			if ( (*out).type == MON_PLAYER)
			{
				return out;
			}
		}

		cout << "DDT>   tile_object_interactor failed to find the player!!!!!!!!!!!!!!!" << endl;
		return new tile_monster;

	}



};
