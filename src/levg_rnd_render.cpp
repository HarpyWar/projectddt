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




#include "levg_sha_shadow.cpp"

using namespace std;

class renderer
{
	public:
	utils util;
	tex_pak_keeper texkeep; //PAK
	globals* global;


	// stuff set only once
	int display_w;
	int display_h;
	float display_scale; //taking over the values for global

	unsigned char gamma_boost;
	float hud_alpha;

	float screen_size_x;
	float screen_size_y;

	float player_on_screen_x; //where to render the player
	float player_on_screen_y;

	int render_scope; //what is the 'radius' of the square of tiles we need to render

	double def_tile_off_x; //where is the 0,0 tile rendered if the player would be standing right on top of it
	double def_tile_off_y;

	double tile_to_screen_x_jump_x; //how many x should we add to tanslate one x tile movement on tile to x movement on screen
	double tile_to_screen_x_jump_y; //how many y should we add to tanslate one x tile movement on tile to x movement on screen
	double tile_to_screen_y_jump_x; //how many x should we add to tanslate one y tile movement on tile to y movement on screen
	double tile_to_screen_y_jump_y; //how many y should we add to tanslate one y tile movement on tile to y movement on screen

	double map_anchor_x;
	double map_anchor_y;
	double map_pixel_x_increase_for_tile_x;
	double map_pixel_y_increase_for_tile_x;
	double map_pixel_x_increase_for_tile_y;
	double map_pixel_y_increase_for_tile_y;




	//stuff set every frame

	unsigned int ddt_time;
	unsigned int engine_tick;
	int active; //the active screen
	int player_at_x_int; // where is the player on the tilegrid
	int player_at_y_int;
	double player_at_x_doub; // where is the player on the tilegrid
	double player_at_y_doub;
	double cur_tile_off_x; //where is the 0,0 tile rendered for this frame
	double cur_tile_off_y;

	double cur_map_anchor_x;
	double cur_map_anchor_y;

	int ooze_factor;
	int ooze_factor_last_frame;
	float ooze_phase;



	//stuff set every tile of every frame

	int this_tile_x_int;
	int this_tile_y_int;
	double this_tile_x_doub; // long of the tile currenly processed
	double this_tile_y_doub;
	double this_tile_off_x; // offstet of the tile currently processed
	double this_tile_off_y;
	double this_tile_player_sqdist; //what is the square of the distance between the this tile and the player
	float this_tile_lightness_r;
	float this_tile_lightness_g;
	float this_tile_lightness_b;
	float this_tile_alpha; //what should be the render alpha of this tile
	float this_tile_prox_alpha; //alpha in case of player close to a wall
	int this_tile_air_count; //how many air textures do we have on this tile
	//int this_tile_monster_count; //how many monsters do we have on this tile
	bool this_tile_ground_ooze;

	int mon_pak;
	int mon_tex;
	int mon_frame;
	double mon_x_off;
	double mon_y_off;

	int mouse_pointer_group;
	int mouse_pointer_frame;




	renderer()
	{

	}


	void in_thread_init(globals* glob)
	{

		global = glob;


		display_w = (*global).display_w;
		display_h = (*global).display_h;


		//if (ddtgrfx::init_display(display_w, display_h, ddtrules::program_name()) == 1)
		if (ddtgrfx::init_display(display_w, display_h, (*global).binblob.get_game_name((*global).game_mode)) == 1)
		{
			cout << "DDT> Display error!" << endl;
			(*global).quit_game = true;
			return;
		}


		display_scale = ddtgrfx::find_display_scale(display_w, display_h, (*global).display_zoom);


		gamma_boost = ddtpal::add_gamma (0, (*global).display_gamma);
		ddtgrfx::set_clear_color(gamma_boost, gamma_boost, gamma_boost);

		hud_alpha = util.find_hud_transparency((*global).hud_transp);


		screen_size_x = (float)display_w / display_scale;
		screen_size_y = (float)display_h / display_scale;

		player_on_screen_x = 0.5*screen_size_x - TILE_SCREEN_X_HALF_SIZE;
		player_on_screen_y = 0.5*screen_size_y;

		//texkeep.init(TEXTURE_SLOTS, display_scale, display_w, display_h);

		texkeep.set_display_var(display_scale, display_w, display_h);



		render_scope = WORLD_UPDATE_RADIUS -1;

		def_tile_off_x = 0.5*screen_size_x - 0.5*TILE_SCREEN_X_SIZE;
		def_tile_off_y = 0.5*screen_size_y;

		tile_to_screen_x_jump_x =   0.5*(double)TILE_SCREEN_X_SIZE;
		tile_to_screen_y_jump_x = - 0.5*(double)TILE_SCREEN_Y_SIZE;
		tile_to_screen_x_jump_y =   0.5*(double)TILE_SCREEN_X_SIZE;
		tile_to_screen_y_jump_y =   0.5*(double)TILE_SCREEN_Y_SIZE;

		map_anchor_x = screen_size_x / 2;
		map_anchor_y = screen_size_y / 2;
		map_pixel_x_increase_for_tile_x = -3.0;
		map_pixel_y_increase_for_tile_x =  2.0;
		map_pixel_x_increase_for_tile_y = -3.0;
		map_pixel_y_increase_for_tile_y = -2.0;



		ddt_time = 0;
		engine_tick = 0;
		active = 1;
		player_at_x_int = 0;
		player_at_y_int = 0;
		player_at_x_doub = 0.0;
		player_at_y_doub = 0.0;

		ooze_factor = 0;
		ooze_factor_last_frame = 0;
		ooze_phase = 0;
		this_tile_ground_ooze = false;

		cur_tile_off_x = 0.0;
		cur_tile_off_y = 0.0;

		this_tile_x_int = 0;
		this_tile_y_int = 0;
		this_tile_x_doub = 0.0;
		this_tile_y_doub = 0.0;
		this_tile_off_x = 0.0;
		this_tile_off_y = 0.0;
		this_tile_lightness_r = 0.0;
		this_tile_lightness_g = 0.0;
		this_tile_lightness_b = 0.0;
		this_tile_alpha = 1.0;
		this_tile_prox_alpha = 1.0;
		this_tile_air_count = 0;



		mouse_pointer_group = MOUSE_CURSOR;
		mouse_pointer_frame = 1;


	}

	void render_screen()
	{

		//	SCREEN_WORLD should not be subject to background gamma boost
		// here we determine if the screen has changed and change the bg gamma boost accordingly
		if (active !=  (*global).active_screen)
		{
			if ((*global).active_screen == SCREEN_WORLD)
			{
				ddtgrfx::set_clear_color(0, 0, 0);
			}
			else
			{
				ddtgrfx::set_clear_color(gamma_boost, gamma_boost, gamma_boost);
			}
		}

		ddtgrfx::swap_and_clear();
		ddt_time = (*global).ddt_time;
		engine_tick = (*global).engine_tick;

		active = (*global).active_screen; //copy this to local to prevent it changing on us mid-render
		if (active > -1 && active < SCREEN_COUNT )
		{

			if (active == SCREEN_WORLD)
			{

				render_world();
				render_map();
			}
			else
			{
				render_atom( &((*global).screen[active].backdrop) , 0, 0);
			}

			for (int i = (*global).screen[active].subscreen_count - 1; i > -1; i--)
			{
				render_subscreen(    &((*global).screen[active].subscreen[i]) );

			}
		}

		render_mouse();


	}

	void render_world()
	{

		player_at_x_int = (*global).player.player_at_x_int;
		player_at_y_int = (*global).player.player_at_y_int;
		player_at_x_doub = (*global).player.player_at_x_doub;
		player_at_y_doub = (*global).player.player_at_y_doub;

		int ooze = ddtmath::modu((ddt_time/4000), 4);
		if (ooze != ooze_factor)
		{
			ooze_factor_last_frame = ooze_factor;
			ooze_factor = ooze;
		}
		ooze_phase = (double)ddtmath::modu((ddt_time), 4000) /4000.0;


		cur_tile_off_x = def_tile_off_x - tile_to_screen_x_jump_x*player_at_x_doub - tile_to_screen_x_jump_y*player_at_y_doub;
		cur_tile_off_y = def_tile_off_y - tile_to_screen_y_jump_x*player_at_x_doub - tile_to_screen_y_jump_y*player_at_y_doub;

		first_render_pass();
		second_render_pass();
		if (DEVELOPER_RENDER_PASS) {developer_render_pass();}

	}


	void first_render_pass()
	{
		(*global).lock_display_token(); // first render pass, only locking token

		for( int y = player_at_y_int + render_scope; y > player_at_y_int - render_scope ; y--)
		{
			for ( int x = player_at_x_int - render_scope; x < player_at_x_int + render_scope ; x++)
			{
				this_tile_x_int = x;
				this_tile_y_int = y;
				this_tile_x_doub = x;
				this_tile_y_doub = y;
				this_tile_off_x = cur_tile_off_x + tile_to_screen_x_jump_x*this_tile_x_doub + tile_to_screen_x_jump_y*this_tile_y_doub;
				this_tile_off_y = cur_tile_off_y + tile_to_screen_y_jump_x*this_tile_x_doub + tile_to_screen_y_jump_y*this_tile_y_doub;

				if ((*global).tile_exists(x,y) && should_render_this_tile_ground())
				{

					this_tile_lightness_r = (*global).tile[x][y].result_light_r;
					this_tile_lightness_g = (*global).tile[x][y].result_light_g;
					this_tile_lightness_b = (*global).tile[x][y].result_light_b;

					this_tile_alpha = (*global).tile[x][y].dist_alpha;
					this_tile_prox_alpha = (*global).tile[x][y].prox_alpha;
					this_tile_ground_ooze = ((*global).tile[x][y].lighting_option == TILE_LIGHTING_OPTION_GOOZE);

					render_tile_ground();



				}

			}
		}

		(*global).unlock_display_token(); //end first render pass

	}

	void second_render_pass()
	{
		for( int y = player_at_y_int + render_scope; y > player_at_y_int - render_scope ; y--)
		{
			for ( int x = player_at_x_int - render_scope; x < player_at_x_int + render_scope ; x++)
			{
				this_tile_x_int = x;
				this_tile_y_int = y;
				this_tile_x_doub = x;
				this_tile_y_doub = y;
				this_tile_off_x = cur_tile_off_x + tile_to_screen_x_jump_x*this_tile_x_doub + tile_to_screen_x_jump_y*this_tile_y_doub;
				this_tile_off_y = cur_tile_off_y + tile_to_screen_y_jump_x*this_tile_x_doub + tile_to_screen_y_jump_y*this_tile_y_doub;

				(*global).lock_tile(x,y);

				if ((*global).tile_exists(x,y) && should_render_this_tile_air())
				{
					this_tile_lightness_r = (*global).tile[x][y].result_light_r;
					this_tile_lightness_g = (*global).tile[x][y].result_light_g;
					this_tile_lightness_b = (*global).tile[x][y].result_light_b;

					this_tile_alpha = (*global).tile[x][y].dist_alpha;
					this_tile_prox_alpha = (*global).tile[x][y].prox_alpha;

					this_tile_air_count = (*global).tile[x][y].airtex.get_tex_count();
					//this_tile_monster_count = (*global).tile[x][y].monsters.get_monster_count();


					if (this_tile_air_count > 0)
					{
						(*global).tile[x][y].airtex.reset_tex_itt();

						for (int i = 0; i < this_tile_air_count; i++)
						{
							render_tile_air((*global).tile[x][y].airtex.request_next_tex());
						}
					}

					if ( (*global).tile[x][y].has_mechanic)
					{
						render_mechanic( (*global).tile[x][y].mech, (*global).tile[x][y].hoover_over);
					}

					if ( (*global).tile[x][y].has_item)
					{
						render_ground_item( (*global).tile[x][y].item, (*global).tile[x][y].hoover_over);
					}

					(*global).tile[x][y].monsters.reset_itt();
					while ( (*global).tile[x][y].monsters.can_request_next())
					{
						render_monster( (*global).tile[x][y].monsters.request_next(), (*global).tile[x][y].hoover_over);

					}


				}
				(*global).unlock_tile(x,y);

			}
		}

	}

	void developer_render_pass()
	{


		(*global).lock_display_token();


		for( int y = player_at_y_int + render_scope; y > player_at_y_int - render_scope ; y--)
		{
			for ( int x = player_at_x_int - render_scope; x < player_at_x_int + render_scope ; x++)
			{
				this_tile_x_int = x;
				this_tile_y_int = y;
				this_tile_x_doub = x;
				this_tile_y_doub = y;
				this_tile_off_x = cur_tile_off_x + tile_to_screen_x_jump_x*this_tile_x_doub + tile_to_screen_x_jump_y*this_tile_y_doub;
				this_tile_off_y = cur_tile_off_y + tile_to_screen_y_jump_x*this_tile_x_doub + tile_to_screen_y_jump_y*this_tile_y_doub;

				if ((*global).tile_exists(x,y) && should_render_this_tile_ground())
				{


					if ( (*global).tile[x][y].hoover_over)
					{
						render_diamond(this_tile_off_x, this_tile_off_y, 1.0, 1.0, 1.0, 0.3);
					}

					if ( !(*global).tile[x][y].walkable)
					{
						render_diamond(this_tile_off_x, this_tile_off_y, 1.0, 0.0, 0.0, 0.1);
					}

					if ((*global).tile[x][y].move_to_reserved)
					{
						render_diamond(this_tile_off_x, this_tile_off_y, 0.0, 1.0, 0.0, 0.1);
					}
					if ((*global).tile[x][y].has_item)
					{
						render_diamond(this_tile_off_x, this_tile_off_y, 1.0, 1.0, 0.0, 0.1);
					}

					if ( (*global).tile[x][y].has_mechanic)
					{
						render_diamond(this_tile_off_x, this_tile_off_y, 0.0, 1.0, 1.0, 0.3);
					}

					if ((*global).tile[x][y].monsters.has_monster_unrelyable())
					{
						render_diamond(this_tile_off_x, this_tile_off_y, 0.0, 0.0, 1.0, 0.3);
					}

				}

			}
		}

		(*global).unlock_display_token();

	}


	void render_tile_ground()
	{
		if (!(*global).blending)
		{
			texkeep.render(
					PAK_DUNLOOK,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_a_member,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_a_frame,
					this_tile_off_x,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha);
			texkeep.render(
					PAK_DUNLOOK,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_b_member,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_b_frame,
					this_tile_off_x + TILE_SCREEN_X_HALF_SIZE,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha);
			return;
		}



		if (this_tile_ground_ooze)
		{

			texkeep.render(
					PAK_DUNLOOK,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_a_member,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_a_backup_frame,
					this_tile_off_x,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha );
			texkeep.render(
					PAK_DUNLOOK,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_b_member,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_b_backup_frame,
					this_tile_off_x + TILE_SCREEN_X_HALF_SIZE,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha );


			texkeep.render(
					PAK_DUNLOOK,
					ooze_factor_last_frame,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_a_frame,
					this_tile_off_x,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha*(1.0 - ooze_phase));
			texkeep.render(
					PAK_DUNLOOK,
					ooze_factor_last_frame,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_b_frame,
					this_tile_off_x + TILE_SCREEN_X_HALF_SIZE,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha*(1.0 - ooze_phase));


			texkeep.render(
					PAK_DUNLOOK,
					ooze_factor,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_a_frame,
					this_tile_off_x,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha*ooze_phase);
			texkeep.render(
					PAK_DUNLOOK,
					ooze_factor,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_b_frame,
					this_tile_off_x + TILE_SCREEN_X_HALF_SIZE,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha*ooze_phase);


					return;
		}


		if(this_tile_prox_alpha < 1.0)
		{
			texkeep.render(
					PAK_DUNLOOK,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_a_member,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_a_backup_frame,
					this_tile_off_x,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha );
			texkeep.render(
					PAK_DUNLOOK,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_b_member,
					(*global).tile[this_tile_x_int][this_tile_y_int].ground_b_backup_frame,
					this_tile_off_x + TILE_SCREEN_X_HALF_SIZE,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha );
		}


		texkeep.render(
				PAK_DUNLOOK,
				(*global).tile[this_tile_x_int][this_tile_y_int].ground_a_member,
				(*global).tile[this_tile_x_int][this_tile_y_int].ground_a_frame,
				this_tile_off_x,
				this_tile_off_y,
				this_tile_lightness_r,
				this_tile_lightness_g,
				this_tile_lightness_b,
				this_tile_alpha*this_tile_prox_alpha );
		texkeep.render(
				PAK_DUNLOOK,
				(*global).tile[this_tile_x_int][this_tile_y_int].ground_b_member,
				(*global).tile[this_tile_x_int][this_tile_y_int].ground_b_frame,
				this_tile_off_x + TILE_SCREEN_X_HALF_SIZE,
				this_tile_off_y,
				this_tile_lightness_r,
				this_tile_lightness_g,
				this_tile_lightness_b,
				this_tile_alpha*this_tile_prox_alpha );
	}

	//assumed xy lock
	void render_tile_air(tile_air_tex* airtex)
	{

		if (!(*global).blending)
		{
			texkeep.render(
					PAK_DUNLOOK,
					(*airtex).tex_member,
					(*airtex).tex_frame,
					this_tile_off_x + (*airtex).move_x,
					this_tile_off_y + (*airtex).move_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha);
			return;
		}


		if (!(*airtex).oozer)
		{
			texkeep.render(
					PAK_DUNLOOK,
					(*airtex).tex_member,
					(*airtex).tex_frame,
					this_tile_off_x + (*airtex).move_x,
					this_tile_off_y + (*airtex).move_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha*this_tile_prox_alpha);
			return;
		}


		mon_tex = (*airtex).tex_member + ooze_factor;
		mon_pak = (*airtex).tex_member + ooze_factor_last_frame;

		texkeep.render(
				PAK_DUNLOOK,
				mon_tex,
				(*airtex).tex_frame,
				this_tile_off_x + (*airtex).move_x,
				this_tile_off_y + (*airtex).move_y,
				this_tile_lightness_r,
				this_tile_lightness_g,
				this_tile_lightness_b,
				this_tile_alpha*this_tile_prox_alpha*ooze_phase);

		texkeep.render(
				PAK_DUNLOOK,
				mon_pak,
				(*airtex).tex_frame,
				this_tile_off_x + (*airtex).move_x,
				this_tile_off_y + (*airtex).move_y,
				this_tile_lightness_r,
				this_tile_lightness_g,
				this_tile_lightness_b,
				this_tile_alpha*this_tile_prox_alpha*(1.0-ooze_phase));
	}

	//assumed xy lock
	void render_monster(tile_monster* mon, bool selected)
	{
		if (! (*global).monsters.exists( (*mon).type)) {return;}

		mon_pak =  (*global).monsters.mon[(*mon).type].pakref_vid;

		if((*mon).action == ACTION_WALK_PRE  || (*mon).action == ACTION_WALK_POST || ((*mon).action == ACTION_IDLE && (*mon).intention == ACTION_WALK_PRE))
		{
			mon_tex =  (*global).monsters.mon[(*mon).type].ani_walk;
			mon_frame = ddtmath::directional_ilde_frame(
					engine_tick + (*mon).random_offset,
					texkeep.texcount_at( mon_pak, mon_tex),
					DDT_SPEEDUP,
					(*mon).facing);


			if ((*mon).type == MON_PLAYER)
			{
				mon_x_off = player_on_screen_x;
				mon_y_off = player_on_screen_y;
			}
			else
			{
				mon_x_off = cur_tile_off_x + tile_to_screen_x_jump_x*(*mon).pos_x_doub + tile_to_screen_x_jump_y*(*mon).pos_y_doub;
				mon_y_off = cur_tile_off_y + tile_to_screen_y_jump_x*(*mon).pos_x_doub + tile_to_screen_y_jump_y*(*mon).pos_y_doub;
			}

		}
		else if((*mon).action == ACTION_IDLE)
		{
			mon_tex =  (*global).monsters.mon[(*mon).type].ani_stand;

			if ( (*global).monsters.mon[(*mon).type].ani_direction)
			{
				mon_frame = ddtmath::directional_ilde_frame(
						engine_tick + (*mon).random_offset,
						texkeep.texcount_at( mon_pak, mon_tex),
						DDT_SPEEDUP*6,
						(*mon).facing);
			}
			else
			{
				mon_frame = ddtmath::idle_frame(
						engine_tick + (*mon).random_offset,
						texkeep.texcount_at( mon_pak, mon_tex),
						DDT_SPEEDUP*20);
			}



			if ((*mon).type == MON_PLAYER)
			{
				mon_x_off = player_on_screen_x;
				mon_y_off = player_on_screen_y;
			}
			else
			{
				mon_x_off = this_tile_off_x;
				mon_y_off = this_tile_off_y;
			}


		}
		else if((*mon).action == ACTION_TELEPORT_PRE || (*mon).action == ACTION_TELEPORT_POST)
		{
			mon_tex =  (*global).monsters.mon[(*mon).type].ani_bonec;
			mon_frame = ddtmath::directional_sequential_frame(
					texkeep.texcount_at(mon_pak, mon_tex),
					(*mon).action_dur,
					(*mon).action_dur_passed,
					(*mon).facing);

			if ((*mon).type == MON_PLAYER)
			{
				mon_x_off = player_on_screen_x;
				mon_y_off = player_on_screen_y;
			}
			else
			{
				mon_x_off = this_tile_off_x;
				mon_y_off = this_tile_off_y;
			}

		}
		else
		{
			return;
		}



		if(selected && (*global).monsters.selectable((*mon).type))
		{
			texkeep.render_highlight(
					HIGHLIGHT_RED,
					mon_pak,
					mon_tex,
					mon_frame,
					mon_x_off,
					mon_y_off);
		}
		else
		{
			texkeep.render(
					mon_pak,
					mon_tex,
					mon_frame,
					mon_x_off,
					mon_y_off,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha);
		}



	}


	//assumed xy lock
	void render_mechanic(tile_mechanic* me, bool selected)
	{
		if (! (*global).mechanics.exists( (*me).type)) {return;}

		mon_pak =  (*global).mechanics.mech[(*me).type].pakref_vid;

		if(mon_pak < 0){return;}

		if ((*global).mechanics.mech[(*me).type].open_grfx_sub == IDLE_ANIMATED)
		{
			mon_tex = (*global).mechanics.mech[(*me).type].open_grfx_gr;
			mon_frame = ddtmath::idle_frame(
					engine_tick,
					texkeep.texcount_at( mon_pak, mon_tex),
					DDT_SPEEDUP*2);
		}
		else if ((*me).is_open)
		{
			mon_tex = (*global).mechanics.mech[(*me).type].open_grfx_gr;
			mon_frame = (*global).mechanics.mech[(*me).type].open_grfx_sub;
		}
		else
		{
			mon_tex = (*global).mechanics.mech[(*me).type].closed_grfx_gr;
			mon_frame = (*global).mechanics.mech[(*me).type].closed_grfx_sub;
		}


		if((*global).mechanics.selectable((*me).type) && selected)
		{
			texkeep.render_highlight(
					HIGHLIGHT_YELLOW,
					mon_pak,
					mon_tex,
					mon_frame,
					this_tile_off_x,
					this_tile_off_y);
		}
		else
		{
			texkeep.render(
					mon_pak,
					mon_tex,
					mon_frame,
					this_tile_off_x,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha);
		}



	}

	//assumed xy lock
	void render_ground_item(game_item* it, bool selected)
	{
		if (! (*global).itemtype.exists( (*it).type)) {return;}

		mon_pak =  PAK_DEFAULT;
		mon_tex = (*global).itemtype.type[(*it).type].on_ground_tex;
		mon_frame = ddtmath::item_flip_frame(
				texkeep.texcount_at( mon_pak, mon_tex),
				(*it).grfx_flip_progress);

		if ((*it).grfx_flip_progress < 1.0)
		{
			(*it).grfx_flip_progress = (*it).grfx_flip_progress + 0.04;
		}



		if(selected)
		{
			texkeep.render_highlight(
					HIGHLIGHT_YELLOW,
					mon_pak,
					mon_tex,
					mon_frame,
					this_tile_off_x,
					this_tile_off_y);
		}
		else
		{
			texkeep.render(
					mon_pak,
					mon_tex,
					mon_frame,
					this_tile_off_x,
					this_tile_off_y,
					this_tile_lightness_r,
					this_tile_lightness_g,
					this_tile_lightness_b,
					this_tile_alpha);
		}



	}



	void render_map()
	{

		if (!(*global).player.show_map) {return;}
		if (texkeep.texcount_at(GAME_MAP) < 1 ) { return; }


		cur_map_anchor_x = map_anchor_x +
				player_at_x_doub*map_pixel_x_increase_for_tile_x +
				player_at_y_doub*map_pixel_x_increase_for_tile_y;

		cur_map_anchor_y = map_anchor_y +
				player_at_x_doub*map_pixel_y_increase_for_tile_x +
				player_at_y_doub*map_pixel_y_increase_for_tile_y;

		texkeep.render(
				GAME_MAP,
				0,
				cur_map_anchor_x + (*global).player.map_move_x_pix,
				cur_map_anchor_y + (*global).player.map_move_y_pix,
				1.0,
				1.0,
				1.0,
				hud_alpha);

		render_rect(
				map_anchor_x -2.0 + (*global).player.map_move_x_pix,
				map_anchor_y -2.0 + (*global).player.map_move_y_pix,
				4.0,
				4.0,
				1.0,
				1.0,
				1.0,
				hud_alpha);


	}



	void render_subscreen(ui_subscreen* sub)
	{
		if ((*sub).visible)
		{
			if ( (*sub).bga > 0.0)
			{
				render_rect( (*sub).anchor_x, (*sub).anchor_y, (*sub).streching_x, (*sub).streching_y, (*sub).bgr, (*sub).bgg, (*sub).bgb, (*sub).bga);
			}

			for(int i = 0; i < (*sub).doodad_count; i++)
			{
				render_atom(  &((*sub).doodad[i]), (*sub).anchor_x, (*sub).anchor_y);
			}
			for(int i = 0; i < (*sub).border_count; i++)
			{
				render_border(  &((*sub).border[i]), (*sub).anchor_x, (*sub).anchor_y);
			}

			for(int i = 0; i < (*sub).button_count; i++)
			{
				render_button(  &((*sub).button[i]), (*sub).anchor_x, (*sub).anchor_y);
			}

			for(int i = 0; i < (*sub).textline_count; i++)
			{
				render_textline(  &((*sub).textline[i]), (*sub).anchor_x, (*sub).anchor_y, 1.0);
			}
			for(int i = 0; i < (*sub).textfield_count; i++)
			{
				render_textfield(  &((*sub).textfield[i]), (*sub).anchor_x, (*sub).anchor_y);
			}

		}

	}


	void render_button(ui_button* butt, float off_x, float off_y)
	{
		if ((*butt).is_visisble)
		{
			if ((*butt).bga > 0.0)
			{
				render_rect(
						off_x + (*butt).anchor_x,
						off_y + (*butt).anchor_y,
						(*butt).streching_x,
						(*butt).streching_y,
						(*butt).bgr,
						(*butt).bgg,
						(*butt).bgb,
						(*butt).bga );
			}

			render_atom( &((*butt).idle_grfx), off_x + (*butt).anchor_x, off_y + (*butt).anchor_y);

			if ((*butt).is_selected)
			{
					render_atom( &((*butt).mouseover_grfx_a), off_x + (*butt).anchor_x, off_y + (*butt).anchor_y);
					render_atom( &((*butt).mouseover_grfx_b), off_x + (*butt).anchor_x, off_y + (*butt).anchor_y);
			}
		}
	}

	void render_border(ui_border* border, float off_x, float off_y)
	{
		render_rect(
				off_x + (*border).anchor_x,
				off_y + (*border).anchor_y,
				(*border).streching_x,
				(*border).streching_y,
				(*border).bgr,
				(*border).bgg,
				(*border).bgb,
				(*border).bga);

		for ( int i = 0;  i < (*border).active_members ; i ++)
		{
			for (int j = 0; j < (*border).repeat[i]; j++)
			{
				render_atom(
						&((*border).atom[i]),
						off_x +  (*border).anchor_x + j*((*border).repeatstep_x[i]) ,
						off_y +  (*border).anchor_y + j*((*border).repeatstep_y[i]) );
			}
		}
	}


	void render_atom(ui_grfx_atom* atom, float off_x, float off_y)
	{
		int gr = (*atom).tex_group;
		int subgr = (*atom).tex_sub_group;

		if (subgr == IDLE_ANIMATED) //calling our hacky modulo function
		{
			subgr = ddtmath::idle_frame(ddt_time, texkeep.texcount_at(gr), ORIGINAL_FRAME_TIME);
		}

		texkeep.render(
				gr,
				subgr,
				off_x + (*atom).anchor_x,
				off_y + (*atom).anchor_y,
				(*atom).rmod,
				(*atom).gmod,
				(*atom).bmod,
				(*atom).amod );
	}



	void render_textline(ui_textline* line, float off_x, float off_y, float alph)
	{

		if ((*line).visible)
		{
			for (int i = 0; i < (*line).active_count; i ++)
			{
				texkeep.render(
						(*line).letter[i].tex_group,
						(*line).letter[i].tex_sub_group,
						off_x + (*line).anchor_x + (*line).letter[i].anchor_x,
						off_y + (*line).anchor_y + (*line).letter[i].anchor_y,
						(*line).letter[i].rmod,
						(*line).letter[i].gmod,
						(*line).letter[i].bmod,
						alph );
			}
		}

	}

	void render_textfield(ui_textfield* field, float off_x, float off_y)
	{
		if ((*field).visible)
		{
			//render_rect( (*field).anchor_x + off_x , (*field).anchor_y + off_y, (*field).width, (*field).height, 1, 1, 1, 0.3);
			if((*field).autoscroll > 0.0)
			{
				// its dirty to issue changes here, but its the only way to have a smooth autoscroll
				(*field).scroll_down((*field).autoscroll);
			}

			int first_rendered_line = 0;
			int last_rendered_line = (*field).active_line_count -1;
			int textblock_height = (*field).active_line_count * ((*field).font_height + (*field).y_slack_spacing) - (*field).y_slack_spacing;
			int line_height = ((*field).font_height + (*field).y_slack_spacing);

			//lets figure out what the first line is we need to render
			if ((*field).height < (*field).scroller && ( line_height != 0))
			{
				int pix_discrep = (*field).scroller - (*field).height;
				first_rendered_line = pix_discrep / line_height;
			}
			// and the last line
			if ((*field).scroller < textblock_height && ( line_height != 0))
			{
				int pix_overflow = textblock_height - (*field).scroller;
				last_rendered_line = last_rendered_line - (pix_overflow /  line_height);
			}

			for (int i  = first_rendered_line; i < last_rendered_line +1; i ++)
			{
				float lineoff = (*field).scroller - i*(line_height);
				float linealph = 1.0;
				if ((*field).fader)
				{
					if ((lineoff < 1) || (lineoff > (*field).height -2))
					{
						linealph = 0.0;
					}
					else if (lineoff < 40)
					{
						linealph = 0.025*((float)(lineoff));
					}
					else if (lineoff > (*field).height - 40)
					{
						linealph = 0.025*((float)((*field).height-lineoff));
					}
				}
				render_textline(&((*field).line[i]), (*field).anchor_x + off_x, (*field).anchor_y + off_y + lineoff, linealph);
			}
		}
	}

	void render_mouse()
	{
		if (active == SCREEN_LOAD_WAIT)
		{
			mouse_pointer_group = MOUSE_CURSOR;
			mouse_pointer_frame = 10;
		}
		else
		{
			mouse_pointer_group = MOUSE_CURSOR;
			mouse_pointer_frame = 0;
		}


		texkeep.render(
				mouse_pointer_group,
				mouse_pointer_frame,
				(*global).mouse_at_x,
				(*global).mouse_at_y,
				1.0,
				1.0,
				1.0,
				1.0);
	}



	void render_rect( float x, float y, float xs, float ys, float r, float g, float b, float a)
	{

		ddtgrfx::render_rect(
				x*display_scale,
				y*display_scale,
				xs*display_scale,
				ys*display_scale,
				r,
				g,
				b,
				a,
				display_w,
				display_h );
	}

	void render_diamond( float x, float y, float r, float g, float b, float a)
	{
		ddtgrfx::render_diamond(
				x*display_scale,
				y*display_scale,
				16*display_scale,
				r,
				g,
				b,
				a,
				display_w,
				display_h);
	}


	bool should_render_this_tile_ground()
	{

		if (this_tile_off_x < -TILE_SCREEN_X_SIZE - 1.0 ) {return false;}
		if (this_tile_off_x >  screen_size_x      + 1.0 ) {return false;}
		if (this_tile_off_y < -TILE_SCREEN_Y_SIZE - 1.0 ) {return false;}
		if (this_tile_off_y >  screen_size_y      + 1.0 ) {return false;}
		return true;
	}

	bool should_render_this_tile_air()
	{

		if (this_tile_off_x < -TILE_SCREEN_X_SIZE - 128.0 ) {return false;}
		if (this_tile_off_x >  screen_size_x      + 128.0 ) {return false;}
		if (this_tile_off_y < -TILE_SCREEN_Y_SIZE - 256.0 ) {return false;}
		if (this_tile_off_y >  screen_size_y      +   1.0 ) {return false;}
		return true;
	}







};
