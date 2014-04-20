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



#include "levk_wld_savegame_master.cpp"
using namespace std;


class level_updater
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


	void update_tiles()
	{

		(*global).engine_tick++;

		int player_was_at_x_int = (*global).player.player_at_x_int;
		int player_was_at_y_int = (*global).player.player_at_y_int;
		double player_was_at_x_doub = (*global).player.player_at_x_doub;
		double player_was_at_y_doub = (*global).player.player_at_y_doub;

		unsigned int ddt_time = (*global).ddt_time;


		for (int y = player_was_at_y_int - WORLD_UPDATE_RADIUS; y < player_was_at_y_int + WORLD_UPDATE_RADIUS; y++)
		{
			for (int x = player_was_at_x_int - WORLD_UPDATE_RADIUS; x < player_was_at_x_int + WORLD_UPDATE_RADIUS; x++)
			{
				(*global).lock_tile(x,y);

				if ( (*global).tile_exists(x,y))
				{

					(*global).tile[x][y].distance_to_playersq =
							((double)x - player_was_at_x_doub)*((double)x - player_was_at_x_doub) +
							((double)y - player_was_at_y_doub)*((double)y - player_was_at_y_doub);



					if ((*global).tile[x][y].distance_to_playersq < 25.0)
					{
						(*global).tile[x][y].player_lightness = 1.0;
						(*global).tile[x][y].result_light_r = 1.0;
						(*global).tile[x][y].result_light_g = 1.0;
						(*global).tile[x][y].result_light_b = 1.0;

						(*global).tile[x][y].discovered = true;;

					}
					else
					{

						(*global).tile[x][y].player_lightness =
								(25.0 / (*global).tile[x][y].distance_to_playersq)*
								(25.0 / (*global).tile[x][y].distance_to_playersq);

						(*global).tile[x][y].result_light_r = ddtmath::biggest_float_of(
								(*global).tile[x][y].player_lightness,
								(*global).tile[x][y].passive_light_r);
						(*global).tile[x][y].result_light_g = ddtmath::biggest_float_of(
								(*global).tile[x][y].player_lightness,
								(*global).tile[x][y].passive_light_g);
						(*global).tile[x][y].result_light_b = ddtmath::biggest_float_of(
								(*global).tile[x][y].player_lightness,
								(*global).tile[x][y].passive_light_b);
					}




					if ((*global).tile[x][y].distance_to_playersq < 230.0)
					{
						(*global).tile[x][y].dist_alpha = 1.0;

					}
					else
					{
						//(*global).tile[x][y].alpha = (250.0  /  (*global).tile[x][y].distance_to_playersq);
						(*global).tile[x][y].dist_alpha =
								(230.0 / (*global).tile[x][y].distance_to_playersq)*
								(230.0 / (*global).tile[x][y].distance_to_playersq)*
								(230.0 / (*global).tile[x][y].distance_to_playersq)*
								(230.0 / (*global).tile[x][y].distance_to_playersq);

					}


					if (((*global).tile[x][y].distance_to_playersq > 16.0) || ((*global).tile[x][y].lighting_option != TILE_LIGHTING_OPTION_PROXFADE))
					{
						(*global).tile[x][y].prox_alpha = 1.0;
					}
					else
					{
						(*global).tile[x][y].prox_alpha = 0.0625*(*global).tile[x][y].distance_to_playersq;
						if ((*global).tile[x][y].prox_alpha < 0.5)
						{
							(*global).tile[x][y].prox_alpha = 0.5;
						}

					}


					if ( (*global).tile[x][y].hoover_over)
					{
						if (ddt_time >  (*global).tile[x][y].hoovered_at + MOUSEOVER_TIMEOUT + 10)
						{
							(*global).tile[x][y].hoover_over = false;
						}
					}



					(*global).tile[x][y].monsters.reset_itt();
					while ((*global).tile[x][y].monsters.can_request_next())
					{
						update_monster( (*global).tile[x][y].monsters.request_next(), x, y);

					}

				}
				(*global).unlock_tile(x,y);

			}
		}

	}

	void update_monster(tile_monster* mon, int tile_x, int tile_y)
	{
		if (!(*global).monsters.exists((*mon).type)) {return;}

		int tar_x = (*mon).action_target_x;
		int tar_y = (*mon).action_target_y;

		if ((*mon).intention == INTENTION_IDLE && (*mon).action == ACTION_IDLE)
		{
			(*mon).action_dur_passed++;
			 monster_ai(mon, tile_x, tile_y);
		}
		else if ((*mon).intention == INTENTION_WALK && (*mon).action == ACTION_IDLE)
		{
			di_int pathing = figure_out_and_tag_second_tile_to_walk_to(tile_x, tile_y, (*mon).intention_target_x, (*mon).intention_target_y);

			if ( pathing.x == tile_x && pathing.y == tile_y)
			{
				//action is denied
				(*mon).intention = INTENTION_IDLE;
				(*mon).prev_action = ACTION_WALK_PRE;
				(*mon).facing = figure_out_facing_direction(tile_x, tile_y, (*mon).intention_target_x, (*mon).intention_target_y, (*mon).facing);
			}
			else
			{
				(*mon).facing = figure_out_facing_direction(tile_x, tile_y, pathing.x, pathing.y, (*mon).facing);
				(*mon).action = ACTION_WALK_PRE;
				(*mon).action_origin_x = tile_x;
				(*mon).action_origin_y = tile_y;
				(*mon).action_target_x = pathing.x;
				(*mon).action_target_y = pathing.y;
				(*mon).action_dur = 20;
				(*mon).action_dur_passed = 0;

				monster_step_sound((*mon).type);
			}

		}
		else if ((*mon).action == ACTION_WALK_PRE)
		{

			(*mon).action_dur_passed ++;
			double action_fraction = ddtmath::save_positive_division((*mon).action_dur_passed, (*mon).action_dur);
			(*mon).pos_x_doub = ddtmath::weighted_average((*mon).action_target_x, (*mon).action_origin_x, action_fraction);
			(*mon).pos_y_doub = ddtmath::weighted_average((*mon).action_target_y, (*mon).action_origin_y, action_fraction);

			if ((*mon).type == MON_PLAYER )
			{
				(*global).player.player_at_x_doub = (*mon).pos_x_doub;
				(*global).player.player_at_y_doub = (*mon).pos_y_doub;
			}


			if ( (*mon).action_dur_passed  > (*mon).action_dur /2)
			{

				(*global).lock_second_tile(tile_x,  tile_y, tar_x, tar_y);

				if ( (*global).tile_exists(tar_x, tar_y ))
				{
					(*global).tile[tile_x][tile_y].monsters.unlist_last_requested();
					(*global).tile[tar_x][tar_y].monsters.add(mon);

					(*mon).action = ACTION_WALK_POST;
					(*global).tile[tar_x][tar_y].move_to_reserved = false;
					monster_step_sound((*mon).type);


					if ((*mon).type == MON_PLAYER )
					{
						(*global).player.player_at_x_int = tar_x;
						(*global).player.player_at_y_int = tar_y;
					}

				}
				else { cout << "DDT> update_monster intertile movement is fucked!" << endl; }

				(*global).unlock_second_tile(tile_x,  tile_y, tar_x, tar_y);
			}
		}

		else if ((*mon).action == ACTION_WALK_POST)
		{
			(*mon).action_dur_passed ++;

			if ( (*mon).action_dur_passed  > (*mon).action_dur - 1)
			{
				(*mon).action = ACTION_IDLE;
				(*mon).prev_action = ACTION_WALK_POST;
				(*mon).pos_x_doub = tile_x;
				(*mon).pos_y_doub = tile_y;
				(*mon).action_dur_passed = 0;

			}
			else
			{
				double action_fraction = ddtmath::save_positive_division((*mon).action_dur_passed, (*mon).action_dur);
				(*mon).pos_x_doub = ddtmath::weighted_average((*mon).action_target_x, (*mon).action_origin_x, action_fraction);
				(*mon).pos_y_doub = ddtmath::weighted_average((*mon).action_target_y, (*mon).action_origin_y, action_fraction);
			}


			if ((*mon).type == MON_PLAYER )
			{
				(*global).player.player_at_x_doub = (*mon).pos_x_doub;
				(*global).player.player_at_y_doub = (*mon).pos_y_doub;
			}



		}
		else if ((*mon).intention == INTENTION_TELEPORT && (*mon).action == ACTION_IDLE)
		{
			di_int pathing = figure_out_and_tag_second_tile_to_teleport_to(tile_x, tile_y, (*mon).intention_target_x, (*mon).intention_target_y);

			if ( pathing.x == tile_x && pathing.y == tile_y)
			{
				//action denied
				(*mon).intention = ACTION_IDLE;
				(*mon).prev_action = ACTION_TELEPORT_PRE;
				(*mon).facing = figure_out_facing_direction(tile_x, tile_y, (*mon).intention_target_x, (*mon).intention_target_y, (*mon).facing);
			}
			else
			{
				(*mon).action = ACTION_TELEPORT_PRE;
				(*mon).action_origin_x = tile_x;
				(*mon).action_origin_y = tile_y;
				(*mon).action_target_x = pathing.x;
				(*mon).action_target_y = pathing.y;
				(*mon).action_dur = 20;
				(*mon).action_dur_passed = 0;
				(*mon).facing = figure_out_facing_direction(tile_x, tile_y, pathing.x, pathing.y, (*mon).facing);
			}

		}
		else if ((*mon).action == ACTION_TELEPORT_PRE)
		{
			(*mon).action_dur_passed ++;

			if ( (*mon).action_dur_passed  > (*mon).action_dur /2)
			{
				(*global).lock_second_tile(tile_x,  tile_y, tar_x, tar_y);

				if ( (*global).tile_exists(tar_x, tar_y ))
				{

					(*mon).action = ACTION_TELEPORT_POST;
					(*mon).intention = ACTION_IDLE;
					(*mon).pos_x_doub = tar_x;
					(*mon).pos_y_doub = tar_y;

					(*global).tile[tar_x][tar_y].move_to_reserved = false;

					if ((*mon).type == MON_PLAYER )
					{
						(*global).player.player_at_x_int = tar_x;
						(*global).player.player_at_y_int = tar_y;
						(*global).player.player_at_x_doub = tar_x;
						(*global).player.player_at_y_doub = tar_y;
					}

					(*global).tile[tile_x][tile_y].monsters.unlist_last_requested();
					(*global).tile[tar_x][tar_y].monsters.add(mon);


				}
				else { cout << "DDT> update_monster intertile movement is fucked!" << endl; }

				(*global).unlock_second_tile(tile_x,  tile_y, tar_x, tar_y);

			}

		}

		else if ((*mon).action == ACTION_TELEPORT_POST)
		{
			(*mon).action_dur_passed ++;

			if ( (*mon).action_dur_passed  > (*mon).action_dur - 1)
			{
				(*mon).action = ACTION_IDLE;
				(*mon).prev_action = ACTION_TELEPORT_POST;
				(*mon).action_dur_passed = 0;

			}
		}


	}

	//lock of xy assumed, the moster type must exist
	void monster_ai(tile_monster* mon, int tile_x, int tile_y)
	{
		int16_t ai = (*global).monsters.mon[(*mon).type].brains;

		if (ai == BRAINS_NONE)
		{
			//nothing
		}
		else if (ai == BRAINS_WANDERER)
		{
			if ((*mon).action_dur_passed > 100)
			{
				int wish_x = ddtmath::random_int(tile_x -4, tile_x +4);
				int wish_y = ddtmath::random_int(tile_y -4, tile_y +4);

				(*mon).intention = INTENTION_WALK;
				(*mon).intention_target_x = wish_x;
				(*mon).intention_target_y = wish_y;

			}
		}


	}



	di_int figure_out_and_tag_second_tile_to_teleport_to(int start_x, int start_y, int intent_x, int intent_y)
	{
		if (tag_second_tile_if_suitable_for_walking(start_x, start_y, intent_x, intent_y)) { return di_int(intent_x, intent_y);}

		int ring = 1;
		int ring_min_x = intent_x - 1;
		int ring_min_y = intent_y - 1;
		int ring_max_x = intent_x + 1;
		int ring_max_y = intent_y + 1;


		while (ring < 10)
		{
			//horizontal parts of the ring
			for ( int x = ring_min_x; x < ring_max_x + 1 ; x++)
			{
				if (tag_second_tile_if_suitable_for_walking(start_x, start_y, x, ring_min_y)) { return di_int(x, ring_min_y);}
				if (tag_second_tile_if_suitable_for_walking(start_x, start_y, x, ring_max_y)) { return di_int(x, ring_max_y);}
			}

			//vertical parts of the ring
			for ( int y = ring_min_y + 1 ; y < ring_max_y ; y++)
			{
				if (tag_second_tile_if_suitable_for_walking(start_x, start_y, ring_min_x, y)) { return di_int(ring_min_x, y);}
				if (tag_second_tile_if_suitable_for_walking(start_x, start_y, ring_max_x, y)) { return di_int(ring_max_x, y);}
			}

			ring++;
			ring_min_x--;
			ring_min_y--;
			ring_max_x++;
			ring_max_y++;

		}




		return di_int(start_x, start_y);
	}



	di_int figure_out_and_tag_second_tile_to_walk_to(int start_x, int start_y, int intent_x, int intent_y)
	{
		if ( intent_x > start_x && intent_y > start_y) //wanna go NE
		{
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x + 1, start_y + 1)) { return di_int(start_x + 1, start_y + 1);}
			if (util.tiles_are_one_appart(start_x, start_y, intent_x, intent_y)) { return di_int(start_x, start_y);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x + 0, start_y + 1)) { return di_int(start_x + 0, start_y + 1);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x + 1, start_y + 0)) { return di_int(start_x + 1, start_y + 0);}
		}
		else if ( intent_x < start_x && intent_y < start_y) //wanna go SW
		{
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x - 1, start_y - 1)) { return di_int(start_x - 1, start_y - 1);}
			if (util.tiles_are_one_appart(start_x, start_y, intent_x, intent_y)) { return di_int(start_x, start_y);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x - 0, start_y - 1)) { return di_int(start_x - 0, start_y - 1);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x - 1, start_y - 0)) { return di_int(start_x - 1, start_y - 0);}

		}
		else if ( intent_x > start_x && intent_y < start_y) //wanna go SE
		{
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x + 1, start_y - 1)) { return di_int(start_x + 1, start_y - 1);}
			if (util.tiles_are_one_appart(start_x, start_y, intent_x, intent_y)) { return di_int(start_x, start_y);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x + 0, start_y - 1)) { return di_int(start_x + 0, start_y - 1);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x + 1, start_y - 0)) { return di_int(start_x + 1, start_y - 0);}
		}
		else if ( intent_x < start_x && intent_y > start_y) //wanna go NW
		{
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x - 1, start_y + 1)) { return di_int(start_x - 1, start_y + 1);}
			if (util.tiles_are_one_appart(start_x, start_y, intent_x, intent_y)) { return di_int(start_x, start_y);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x - 0, start_y + 1)) { return di_int(start_x - 0, start_y + 1);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x - 1, start_y + 0)) { return di_int(start_x - 1, start_y + 0);}

		}
		else if ( intent_x > start_x) //wanna go E
		{
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x + 1, start_y    )) { return di_int(start_x + 1, start_y);}
			if (util.tiles_are_one_appart(start_x, start_y, intent_x, intent_y)) { return di_int(start_x, start_y);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x + 1, start_y + 1)) { return di_int(start_x + 1, start_y + 1);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x + 1, start_y - 1)) { return di_int(start_x + 1, start_y - 1);}

		}
		else if ( intent_x < start_x) //wanna go W
		{
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x - 1, start_y    )) { return di_int(start_x - 1, start_y);}
			if (util.tiles_are_one_appart(start_x, start_y, intent_x, intent_y)) { return di_int(start_x, start_y);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x - 1, start_y + 1)) { return di_int(start_x - 1, start_y + 1);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x - 1, start_y - 1)) { return di_int(start_x - 1, start_y - 1);}

		}
		else if ( intent_y > start_y) //wanna go N
		{
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x    , start_y + 1)) { return di_int(start_x    , start_y + 1);}
			if (util.tiles_are_one_appart(start_x, start_y, intent_x, intent_y)) { return di_int(start_x, start_y);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x + 1, start_y + 1)) { return di_int(start_x + 1, start_y + 1);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x - 1, start_y + 1)) { return di_int(start_x - 1, start_y + 1);}

		}
		else if ( intent_y < start_y) //wanna go S
		{
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x    , start_y - 1)) { return di_int(start_x    , start_y - 1);}
			if (util.tiles_are_one_appart(start_x, start_y, intent_x, intent_y)) { return di_int(start_x, start_y);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x + 1, start_y - 1)) { return di_int(start_x + 1, start_y - 1);}
			if (tag_second_tile_if_suitable_for_walking(start_x, start_y, start_x - 1, start_y - 1)) { return di_int(start_x - 1, start_y - 1);}

		}

		return di_int(start_x, start_y);

	}

	int figure_out_facing_direction(int start_x, int start_y, int intent_x, int intent_y, int old_direction)
	{
		if ( intent_x > start_x && intent_y > start_y){return DIRECTION_NE;} //wanna go NE
		if ( intent_x < start_x && intent_y < start_y){return DIRECTION_SW;} //wanna go SW
		if ( intent_x > start_x && intent_y < start_y){return DIRECTION_SE;} //wanna go SE
		if ( intent_x < start_x && intent_y > start_y){return DIRECTION_NW;} //wanna go NW
		if ( intent_x > start_x){return DIRECTION_E;} //wanna go E
		if ( intent_x < start_x){return DIRECTION_W;} //wanna go W
		if ( intent_y > start_y){return DIRECTION_N;} //wanna go N
		if ( intent_y < start_y){return DIRECTION_S;} //wanna go S
		return old_direction;

	}



	bool tag_second_tile_if_suitable_for_walking(int prev_locked_x, int prev_locked_y, int tar_x, int tar_y)
	{
		(*global).lock_second_tile(prev_locked_x, prev_locked_y, tar_x, tar_y);
		if ((*global).tile_exists(tar_x,tar_y))
		{
			(*global).tile[tar_x][tar_y].monsters.reset_itt();
			if ( (*global).tile[tar_x][tar_y].monsters.can_request_next())
			{
				(*global).unlock_second_tile(prev_locked_x, prev_locked_y, tar_x, tar_y);
				return false;
			}
			if ( (*global).tile[tar_x][tar_y].walkable == false)
			{
				(*global).unlock_second_tile(prev_locked_x, prev_locked_y, tar_x, tar_y);
				return false;
			}
			if ( (*global).tile[tar_x][tar_y].move_to_reserved == true)
			{
				(*global).unlock_second_tile(prev_locked_x, prev_locked_y, tar_x, tar_y);
				return false;
			}

			(*global).tile[tar_x][tar_y].move_to_reserved = true;
			(*global).unlock_second_tile(prev_locked_x, prev_locked_y, tar_x, tar_y);
			return true;


		}
		else
		{
			(*global).unlock_second_tile(prev_locked_x, prev_locked_y, tar_x, tar_y);
			return false;
		}


	}

	void monster_step_sound(int16_t montype)
	{
		if (!(*global).monsters.exists(montype)) {return;}
		if ((*global).monsters.mon[montype].stepsound_max < 1) {return;}

		int pak = (*global).monsters.mon[montype].pakref_aud;

		int sound = ddtmath::random_int(
				(*global).monsters.mon[montype].stepsound_min,
				(*global).monsters.mon[montype].stepsound_max);


		post = new mail(AUDIO_PLAY_PAK_SFX, pak, sound);
		(*global).threadpush_audio(post);

	}
};
