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



#include "levu_wld_player_class.cpp"
using namespace std;

class tile_air_tex
{
	public:

	tile_air_tex* next;

	int16_t tex_member;
	int16_t tex_frame;
	int16_t move_x;
	int16_t move_y;
	bool oozer;

	tile_air_tex()
	{
		tex_member = VOID_TEXTURE;
		tex_frame = VOID_TEXTURE;
		move_x = 0;
		move_y = 0;
		oozer = false;
	}

	tile_air_tex(int16_t m, int16_t f, int16_t mx, int16_t my)
	{
		tex_member = m;
		tex_frame = f;
		move_x = mx;
		move_y = my;
		oozer = false;
	}

	tile_air_tex(int16_t m, int16_t f, int16_t mx, int16_t my, bool ooze)
	{
		tex_member = m;
		tex_frame = f;
		move_x = mx;
		move_y = my;
		oozer = ooze;
	}


};

class tile_air_textures
{
	private:
	int16_t tex_count;
	tile_air_tex* first_tex;
	tile_air_tex* last_tex;

	int16_t last_requested_tex_no;
	tile_air_tex* last_requested_tex;

	public:

	tile_air_textures()
	{
		tex_count = 0;
		last_requested_tex_no = -1;
	}

	int16_t get_tex_count()
	{
		return tex_count;
	}

	void reset_tex_itt()
	{
		last_requested_tex_no = -1;
		last_requested_tex = NULL;
	}

	void add_tex( tile_air_tex* in)
	{
		if (tex_count < 1)
		{
			first_tex = in;
			last_tex = in;
			tex_count = 1;
		}
		else if (tex_count > 30000)
		{
			cout << "DDT> Waaay to many airtex" << endl;
		}
		else
		{
			(*last_tex).next = in;
			last_tex = (*last_tex).next;
			tex_count++;
		}
	}


	tile_air_tex* request_next_tex()
	{
		if ( tex_count < 1 || last_requested_tex_no > tex_count -2)
		{
			cout << "DDT> world_tile illegal air_texture requested" << endl;
			return new tile_air_tex;
		}
		else if ( last_requested_tex_no == -1)
		{
			last_requested_tex_no = 0;
			last_requested_tex = first_tex;
			return last_requested_tex;
		}
		else if ( last_requested_tex_no == 0)
		{
			last_requested_tex_no = 1;
			last_requested_tex = (*last_requested_tex).next;
			return last_requested_tex;
		}
		else
		{
			last_requested_tex_no++;
			last_requested_tex = (*last_requested_tex).next;
			return last_requested_tex;
		}

	}


	void kill()
	{
		while (tex_count > 0)
		{

			tile_air_tex* temptex = first_tex;
			first_tex = (*first_tex).next;
			tex_count--;
			delete temptex;
		}
	}


};


class tile_monster
{
	public:

	tile_monster* next;
	tile_monster* prev;


	int16_t type;

	int16_t facing; //direction the monster is looking at

	int16_t random_offset; //for animation diversity


	int16_t action;
	int16_t action_origin_x;
	int16_t action_origin_y;
	int16_t action_target_x;
	int16_t action_target_y;

	uint16_t action_dur;
	uint16_t action_dur_passed;

	int16_t intention;
	int16_t intention_target_x;
	int16_t intention_target_y;

	int16_t prev_action;


	double pos_x_doub;
	double pos_y_doub;

	tile_monster()
	{
		type = MON_VOID;

		facing = DIRECTION_SE;

		random_offset = ddtmath::random_int(256);


		action = ACTION_IDLE;
		action_origin_x = 0;
		action_origin_y = 0;
		action_target_x = 0;
		action_target_y = 0;
		action_dur = 0;
		action_dur_passed = 0;

		intention = INTENTION_IDLE;
		intention_target_x = 0;
		intention_target_y = 0;

		prev_action = ACTION_IDLE;

		pos_x_doub = 0;
		pos_y_doub = 0;


	}

};



class tile_monsters
{
	private:
	int mon_count;
	int requested_mon_no;
	bool last_action_was_unlist;


	tile_monster* first_mon;
	tile_monster* requested_mon;
	tile_monster* last_mon;



	public:

	tile_monsters()
	{
		mon_count = 0;
		requested_mon_no = -1;
		last_action_was_unlist = false;
	}

	bool has_monster_unrelyable()
	{
		return (mon_count > 0);
	}

	void add(tile_monster* in)
	{
		if (mon_count == 0)
		{
			first_mon = in;
			last_mon = in;
		}
		else
		{
			(*last_mon).next = in;
			(*in).prev = last_mon;
		}
		mon_count++;
		requested_mon_no = -1;
		last_action_was_unlist = false;
	}

	void reset_itt()
	{
		requested_mon_no = -1;
		last_action_was_unlist = false;
	}

	bool can_request_next()
	{
		if(mon_count >  requested_mon_no +1) {return true;}
		return false;
	}



	tile_monster* request_next()
	{
		if (!can_request_next())
		{
			cout << "DDT> tile monster bad request" << endl;
			return new tile_monster;
		}
		else if (requested_mon_no == -1)
		{
			requested_mon = first_mon;
		}
		else
		{
			requested_mon = (*requested_mon).next;
		}
		last_action_was_unlist = false;
		requested_mon_no++;
		return requested_mon;
	}

	void unlist_last_requested()
	{
		if ((requested_mon_no < 0) || (requested_mon_no > mon_count -1) || last_action_was_unlist) //bad case
		{
			cout << "DDT> tile monster bad unlist request" << endl;
			return;
		}
		else if (mon_count == 1) //only one case
		{

		}
		else if(requested_mon_no == 0) //first of many case
		{
			first_mon = (*first_mon).next;
		}

		else if(requested_mon_no == mon_count -1) //last of many case
		{
			last_mon = (*last_mon).prev;
			requested_mon = last_mon;
		}
		else
		{
			tile_monster* pr = (*requested_mon).prev;
			tile_monster* nxt = (*requested_mon).next;

			(*pr).next = nxt;
			(*nxt).prev = pr;
			requested_mon = pr;

		}

		mon_count--;
		requested_mon_no--;
		last_action_was_unlist = true;

	}

	void kill()
	{
		reset_itt();

		while(can_request_next())
		{
			tile_monster* bla = request_next();
			unlist_last_requested();
			delete bla;
			reset_itt();
		}
	}






};


class tile_mechanic
{
	public:

	int16_t type;
	bool is_open;

	tile_mechanic()
	{
		type = TILE_MECH_VOID;
	}

};

class game_item
{
	public:
	int16_t type;
	float grfx_flip_progress;
	uint32_t stack_size;

	game_item()
	{
		type = ITEM_TYPE_VOID;
		grfx_flip_progress = 0.0;
		stack_size = 1;
	}

};


class world_tile
{
	public:

	bool walkable;
	bool flyable;
	bool discovered; //map logic
	int8_t lighting_option;

	bool move_to_reserved;



	int16_t ground_a_member;  //texkepper texture ref of ground textures
	int16_t ground_a_frame;
	int16_t ground_b_member;
	int16_t ground_b_frame;
	int16_t ground_a_backup_frame;
	int16_t ground_b_backup_frame;

	double distance_to_playersq;
	float dist_alpha;
	float prox_alpha;

	float player_lightness;
	float passive_light_r;
	float passive_light_g;
	float passive_light_b;
	float result_light_r;
	float result_light_g;
	float result_light_b;

	uint32_t hoovered_at;
	bool hoover_over;

	tile_monsters monsters;
	tile_air_textures airtex;

	bool has_mechanic;
	tile_mechanic* mech;

	bool has_item;
	game_item* item;






	public:

	world_tile()
	{
		walkable = true;
		flyable = true;
		discovered = false;
		lighting_option = TILE_LIGHTING_OPTION_DEFAULT;



		move_to_reserved = false;

		ground_a_member = VOID_TEXTURE;  //texkepper texture ref of ground textures
		ground_a_frame = VOID_TEXTURE;
		ground_b_member = VOID_TEXTURE;
		ground_b_frame = VOID_TEXTURE;
		ground_a_backup_frame = VOID_TEXTURE;
		ground_b_backup_frame = VOID_TEXTURE;
		distance_to_playersq = 1000.0;

		dist_alpha = 1.0;
		prox_alpha = 1.0;

		player_lightness = 0.0;
		passive_light_r = 0.0;
		passive_light_g = 0.0;
		passive_light_b = 0.0;
		result_light_r = 0.0;
		result_light_g = 0.0;
		result_light_b = 0.0;

		hoovered_at = 0;
		hoover_over = false;

		has_mechanic = false;
		has_item = false;


	}

	void set_walk_fly(bool wa, bool fl)
	{
		walkable = wa;
		flyable = fl;

	}


	void set_ground_textures(int16_t a_mem, int16_t a_fr, int16_t b_mem, int16_t b_fr)
	{
		ground_a_member = a_mem;
		ground_a_frame = a_fr;
		ground_b_member = b_mem;
		ground_b_frame = b_fr;
	}

	void set_alt_ground_textures(int16_t a_fr, int16_t b_fr)
	{
		ground_a_backup_frame = a_fr;
		ground_b_backup_frame = b_fr;
	}

	void place_mechanic(tile_mechanic* tm)
	{
		if (has_mechanic) {delete mech;}
		mech = tm;
		has_mechanic = true;
	}

	void place_item(game_item* itm)
	{
		if (has_item) {delete item;}
		item = itm;
		has_item = true;
	}

	void hoover(uint32_t htime)
	{
		hoover_over = true;
		hoovered_at = htime;
	}



	void kill()
	{
		monsters.kill();
		airtex.kill();

		if (has_mechanic) {delete mech;}
		has_mechanic = false;

		if (has_item) {delete item;}
		has_item = false;
	}
};








