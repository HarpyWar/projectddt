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





#include "levg_mkb_player_interaction.cpp"

#define SLACK_COUNTER_MAX 130
#define DEF_DELAY_TIME 15


using namespace std;


class shadow
{

	utils util;
	globals* global;
	mail* post;


	int pixel_x_increase_for_tile_x;
	int pixel_y_increase_for_tile_x;
	int pixel_x_increase_for_tile_y;
	int pixel_y_increase_for_tile_y;

	unsigned char gold_r;
	unsigned char gold_g;
	unsigned char gold_b;
	unsigned char gold_a;
	unsigned char gold_aa;

	int slack_counter;
	bool hurry_up;
	int previous_maps_level;


	public:


	shadow()
	{
		pixel_x_increase_for_tile_x =  3;
		pixel_y_increase_for_tile_x = -2;
		pixel_x_increase_for_tile_y =  3;
		pixel_y_increase_for_tile_y =  2;


		gold_r = 0xd9;
		gold_g = 0xd5;
		gold_b = 0x9a;
		gold_a = 0x90;
		gold_aa = 0x60;

		slack_counter = 0;
		hurry_up = false;
		previous_maps_level = -1;

	}

	void in_thread_init(globals* glob)
	{
		global = glob;
	}


	void run()
	{
		if ( (*global).active_screen != SCREEN_WORLD)
		{
			previous_maps_level = -1;
			ddttime::delay(1000);
			return;
		}
		else
		{
			make_map();
		}
	}

	void make_map()
	{
		(*global).lock_shadow_token();
		int tile_count_x = (*global).tile_count_x;
		int tile_count_y = (*global).tile_count_y;
		int levelno = (*global).level_number;
		(*global).unlock_shadow_token();

		unsigned int delayed_this_round = 0;


		if (previous_maps_level != levelno) { hurry_up = true;}
		else { hurry_up = false;}
		previous_maps_level = levelno;


		int bigdim = tile_count_x;
		if ( tile_count_y > tile_count_x) {bigdim = tile_count_y;}

		int tex_size_x = util.power_of_two(bigdim*6);
		int tex_size_y = util.power_of_two(bigdim*4);


		int tex_size = tex_size_x*tex_size_y*4;
		unsigned char* tex = new unsigned char[tex_size];

		for (int i = 0; i < tex_size; i++)
		{
			tex[i] = 0x00;
		}

		bool cur_tile_discovered = false;
		bool cur_tile_walkable = false;
		bool cur_tile_monster = false;
		//bool cur_tile_monster_frendly = false;




		for (int x = 0; x <  tile_count_x; x++) //first render pass
		{
			for (int y = 0; y <  tile_count_y; y++)
			{
				(*global).lock_shadow_token();
				if ((*global).tile_exists(x, y))
				{
					cur_tile_discovered = (*global).tile[x][y].discovered;
					cur_tile_walkable = (*global).tile[x][y].walkable;
				}
				(*global).unlock_shadow_token();


				if (cur_tile_walkable && cur_tile_discovered)
				{

					paint_map_dot(tex, x+2, y,   tex_size_x, tex_size_y, gold_r, gold_g, gold_b, gold_aa);
					paint_map_dot(tex, x-2, y,   tex_size_x, tex_size_y, gold_r, gold_g, gold_b, gold_aa);
					paint_map_dot(tex, x,   y+2, tex_size_x, tex_size_y, gold_r, gold_g, gold_b, gold_aa);
					paint_map_dot(tex, x,   y-2, tex_size_x, tex_size_y, gold_r, gold_g, gold_b, gold_aa);
				}

				slack_counter++;
				if (slack_counter > SLACK_COUNTER_MAX)
				{
					 if (we_may_proceed_drawing(levelno))
					 {
						 if (!hurry_up)
						 {
							 ddttime::delay(DEF_DELAY_TIME);
							 delayed_this_round = delayed_this_round + DEF_DELAY_TIME;
						 }
						 slack_counter = 0;
					 }
					 else
					 {
						 delete[] tex;
						 return;
					 }

				}

			}
		}

		for (int x = 0; x <  tile_count_x; x++) //2nd render pass
		{
			for (int y = 0; y <  tile_count_y; y++)
			{
				(*global).lock_shadow_token();
				if ((*global).tile_exists(x, y))
				{
					cur_tile_discovered = (*global).tile[x][y].discovered;
					cur_tile_walkable = (*global).tile[x][y].walkable;
				}
				(*global).unlock_shadow_token();


				if (cur_tile_walkable && cur_tile_discovered)
				{
					paint_map_dot(tex, x+1, y,   tex_size_x, tex_size_y, gold_r, gold_g, gold_b, gold_a);
					paint_map_dot(tex, x-1, y,   tex_size_x, tex_size_y, gold_r, gold_g, gold_b, gold_a);
					paint_map_dot(tex, x,   y+1, tex_size_x, tex_size_y, gold_r, gold_g, gold_b, gold_a);
					paint_map_dot(tex, x,   y-1, tex_size_x, tex_size_y, gold_r, gold_g, gold_b, gold_a);


				}

				slack_counter++;
				if (slack_counter > SLACK_COUNTER_MAX)
				{
					 if (we_may_proceed_drawing(levelno))
					 {
						 if (!hurry_up)
						 {
							 ddttime::delay(DEF_DELAY_TIME);
							 delayed_this_round = delayed_this_round + DEF_DELAY_TIME;
						 }
						 slack_counter = 0;
					 }
					 else
					 {
						 delete[] tex;
						 return;
					 }

				}

			}
		}


		for (int x = 0; x <  tile_count_x; x++) //2nd render pass
		{
			for (int y = 0; y <  tile_count_y; y++)
			{
				(*global).lock_tile(x,y);
				if ((*global).tile_exists(x, y))
				{
					cur_tile_discovered = (*global).tile[x][y].discovered;
					cur_tile_walkable = (*global).tile[x][y].walkable;
					(*global).tile[x][y].monsters.reset_itt();
					cur_tile_monster = ((*global).tile[x][y].monsters.can_request_next());
				}
				(*global).unlock_tile(x,y);


				if ( !cur_tile_discovered)
				{
					paint_map_dot(tex, x, y, tex_size_x, tex_size_y, 0x00, 0x00, 0x00, 0x00);
				}
				else if (cur_tile_monster)
				{
					paint_map_dot(tex, x, y, tex_size_x, tex_size_y, 0xff, 0x00, 0x00, 0xff);
				}

				else if (cur_tile_walkable)
				{
					paint_map_dot(tex, x, y, tex_size_x, tex_size_y, 0x00, 0x00, 0x00, 0x00);
				}

				else
				{
					//paint_map_dot(tex, x, y, tex_size_x, tex_size_y, 0x00, 0x00, 0xff, 0xff);
				}

				slack_counter++;
				if (slack_counter > SLACK_COUNTER_MAX)
				{
					 if (we_may_proceed_drawing(levelno))
					 {
						 if (!hurry_up)
						 {
							 ddttime::delay(DEF_DELAY_TIME);
							 delayed_this_round = delayed_this_round + DEF_DELAY_TIME;
						 }
						 slack_counter = 0;
					 }
					 else
					 {
						 delete[] tex;
						 return;
					 }

				}
			}
		}


		int x_move = 0;
		int y_move = - 0.5*tex_size_y;

		if ((delayed_this_round < 2000) && !hurry_up)
		{
			ddttime::delay(2000 - delayed_this_round);
		}

		//post = new mail(TRANSCODE_GRFX,pakno, keeperno,algint,x_size,y_size,palno,frames,alpha_byte,chunkint,x_move,y_move,gfile.i,gfile.c,0,NULL);
		post = new mail(TRANSCODE_GRFX, PAK_DEFAULT, GAME_MAP, MAP, tex_size_x, tex_size_y, 0, 0, 0, CHUNKY_DEFUALT, x_move, y_move, tex_size, tex, 0, NULL);
		(*global).threadpush_transcode(post);



	}

	void paint_map_dot(unsigned char* map, int tile_x, int tile_y, int tex_x, int tex_y,
			unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{

		int pixel_x = tile_x*pixel_x_increase_for_tile_x + tile_y*pixel_x_increase_for_tile_y;
		int pixel_y = tile_x*pixel_y_increase_for_tile_x + tile_y*pixel_y_increase_for_tile_y;


		 paint_calculated_map_dot(map, pixel_x, pixel_y + 0.5*tex_y, tex_x, tex_y,r,g,b,a);



	}





	void paint_calculated_map_dot(unsigned char* map, int pixel_x, int pixel_y, int size_x, int size_y,
			unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		util.raster_pix(map, size_x,  size_y, pixel_x +0, pixel_y + 0, r,g,b,a);
		util.raster_pix(map, size_x,  size_y, pixel_x +1, pixel_y + 0, r,g,b,a);
		util.raster_pix(map, size_x,  size_y, pixel_x +2, pixel_y + 0, r,g,b,a);
		util.raster_pix(map, size_x,  size_y, pixel_x +3, pixel_y + 0, r,g,b,a);
		util.raster_pix(map, size_x,  size_y, pixel_x +4, pixel_y + 0, r,g,b,a);
		util.raster_pix(map, size_x,  size_y, pixel_x +5, pixel_y + 0, r,g,b,a);

		util.raster_pix(map, size_x,  size_y, pixel_x +1, pixel_y + 1, r,g,b,a);
		util.raster_pix(map, size_x,  size_y, pixel_x +2, pixel_y + 1, r,g,b,a);
		util.raster_pix(map, size_x,  size_y, pixel_x +3, pixel_y + 1, r,g,b,a);

		util.raster_pix(map, size_x,  size_y, pixel_x +1, pixel_y - 1, r,g,b,a);
		util.raster_pix(map, size_x,  size_y, pixel_x +2, pixel_y - 1, r,g,b,a);
		util.raster_pix(map, size_x,  size_y, pixel_x +3, pixel_y - 1, r,g,b,a);

	}

	bool we_may_proceed_drawing(int cur_lev_no)
	{
		if ((*global).quit_game) { return false;}
		if ((*global).level_number != cur_lev_no) {return false;}
		if ((*global).active_screen != SCREEN_WORLD) {return false;}
		return true;

	}




};
