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



#include "levk_wld_level_updater.cpp"
using namespace std;

class level_loader
{


	globals* global;
	world_local* local;
	utils util;
	mail* post;

	bool load_savable_elements;
	int random_block_pointer;
	int random_dummy_dispence[8];
	int random_dummy_dispence_pointer;


	public:

	void init(globals* glob, world_local* loc)
	{
		global = glob;
		local = loc;
		load_savable_elements = false;
		random_block_pointer = 0;


	}

	void read_level_rules(unsigned char* levtxt, int levtxt_size)
	{

		//generate_texure_filter(levtxt, levtxt_size);


		int levtxt_point = -1;
		bool lev_end = false;


		while ((levtxt_point < levtxt_size - 10) && (lev_end == false))
		{
			levtxt_point++;

			if ( !(  levtxt[levtxt_point] == '(') )
			{
				// nothing
			}
			else if (
					(levtxt[levtxt_point +1] == 'e') &&
					(levtxt[levtxt_point +2] == 'n') &&
					(levtxt[levtxt_point +3] == 'd') &&
					(levtxt[levtxt_point +4] == ')') )
			{
					lev_end = true;
			}

			else if (
					(levtxt[levtxt_point +1] == 's') &&
					(levtxt[levtxt_point +2] == 'e') &&
					(levtxt[levtxt_point +3] == 'c') &&
					(levtxt[levtxt_point +4] == 't') &&
					(levtxt[levtxt_point +5] == 'o') &&
					(levtxt[levtxt_point +6] == 'r') &&
					(levtxt[levtxt_point +7] == 's') &&
					(levtxt[levtxt_point +8] == ')') )
			{


				delete_sectors();


				(*local).sectors_count =  util.get_int_at(levtxt_point +10, levtxt, levtxt_size);


				if ((*local).sectors_count < 1) {(*local).sectors_count = 1;}
				(*local).sector = new unsigned char*[(*local).sectors_count];
				(*local).sector_byte_size = new int[(*local).sectors_count];


				for (int i = 0; i < (*local).sectors_count; i++)
				{
					(*local).sector_byte_size[i] = 0;

				}


			}
			else if (
					(levtxt[levtxt_point +1] == 's') &&
					(levtxt[levtxt_point +2] == 'e') &&
					(levtxt[levtxt_point +3] == 'c') &&
					(levtxt[levtxt_point +4] == 't') &&
					(levtxt[levtxt_point +5] == 'o') &&
					(levtxt[levtxt_point +6] == 'r') &&
					(levtxt[levtxt_point +7] == ')') )
			{
				int secno =  util.get_int_at(levtxt_point +9, levtxt, levtxt_size);

				if ( secno > -1  && secno < (*local).sectors_count)
				{
					 delete_sector(secno);

					int seek_point = levtxt_point +14;
					int seek_count = 0;
					bool seek_done = false;

					while (seek_point < levtxt_size - 15 && !seek_done)
					{
						if (
							(levtxt[seek_point  +0] == '(') &&
							(levtxt[seek_point  +1] == 's') &&
							(levtxt[seek_point  +2] == 'e') &&
							(levtxt[seek_point  +3] == 'c') &&
							(levtxt[seek_point  +4] == 't') &&
							(levtxt[seek_point  +5] == 'o') &&
							(levtxt[seek_point  +6] == 'r') &&
							(levtxt[seek_point  +7] == '_') &&
							(levtxt[seek_point  +8] == 'e') &&
							(levtxt[seek_point  +9] == 'n') &&
							(levtxt[seek_point +10] == 'd') &&
							(levtxt[seek_point +11] == ')') )
						{
							seek_done = true;
						}
						else
						{
							seek_count++;
						}

						seek_point++;
					}

					if (seek_count > 0)
					{
						(*local).sector[secno] = new unsigned char[seek_count];
						(*local).sector_byte_size[secno] = seek_count;

						seek_point = levtxt_point +14;

						for ( int i = 0; i < seek_count; i++)
						{
							(*local).sector[secno][i] = levtxt[seek_point];
							seek_point++;
						}
					}
					else
					{
						cout << "DDT> level sector bad count" << endl; ;
					}


				}
				else
				{
					cout << "DDT> bad level sector" << endl; ;
				}

			}

		}

		delete[] levtxt;
	}


	void delete_sector(int secno)
	{
		if (secno < 0 || secno > (*local).sectors_count -1)
		{
			return;
		}

		if ((*local).sector_byte_size[secno] < 1)
		{
			return;
		}

		delete[] (*local).sector[secno];
		(*local).sector_byte_size[secno] = 0;
	}

	void delete_sectors()
	{
		if ( (*local).sectors_count < 1)
		{
			return;
		}


		for (int i = 0; i < (*local).sectors_count; i++)
		{
			delete_sector(i);
		}

		delete[](*local).sector_byte_size;
		(*local).sectors_count = 0;


	}



	void add_player_at(int x, int y)
	{
		bool panic = true;

		//(*global).lock_tile(x,y); not locking because all tile lock should be active
		if ( (*global).tile_exists(x,y) )
		{
			tile_monster* player = new tile_monster;
			(*player).type = MON_PLAYER;
			(*player).pos_x_doub = x;
			(*player).pos_y_doub = y;
			(*global).tile[x][y].monsters.add(player);
			panic = false;
		}
		//(*global).unlock_tile(x,y);

		if (panic)
		{
			add_player_at(0,0);
			//yes, an endless recursive loop is possible here.
			//but if it happens, everything if totally fubar regardless.....
		}

	}

	void rasterise_level(int level, bool s_e)
	{
		load_savable_elements = s_e;
		load_dungeon_info_from_statics(level);
		di_int dundim = (*global).dungeons.get_dungeon_xy(level);
		int sector_prime = (*global).dungeons.get_prime_sec(level);
		reset_tilegrid(dundim.x, dundim.y);
		random_block_pointer = level + LEVEL_COUNT; //just something

		raster_map(sector_prime, 0, 0);
	}


	void check_sectorfixes(int lev)
	{
		for (int i = 0; i < SECTORFIX_COUNT; i++)
		{
			if ((*global).player.get_sector_fix(i))
			{
				apply_sectorfix(i, false);
			}
		}
	}




	void apply_sectorfix(int fixno, bool fix_is_hot)
	{
		load_savable_elements = fix_is_hot;
		random_block_pointer = fixno + LEVEL_COUNT; //just something
		int fix_size = (*global).sectorfix.get_size(fixno);
		unsigned char* fix = (*global).sectorfix.get_fix(fixno);
		int fixpoint = -1;

		if (fix_size < 4) {return;}

		while (fixpoint < fix_size - 10)
		{
			fixpoint ++;

			if (fix[fixpoint] == '(')
			{
				if (
						fix[fixpoint + 1] == 's' &&
						fix[fixpoint + 2] == 'e' &&
						fix[fixpoint + 3] == 'c' &&
						fix[fixpoint + 4] == '_' &&
						fix[fixpoint + 5] == 'f' &&
						fix[fixpoint + 6] == 'i' &&
						fix[fixpoint + 7] == 'x' &&
						fix[fixpoint + 8] == ')')
				{
					int lev = util.get_int_at(fixpoint + 10, fix, fix_size);
					int sec = util.get_int_at(fixpoint + 16, fix, fix_size);
					int mech = util.get_int_at(fixpoint + 22, fix, fix_size);

					if (lev == (*global).level_number)
					{
						di_int target = find_mechanic_on_tiles(mech);
						if (target.x < 1 && target.y < 1)
						{
							cout << "DDT> level_loader apply_sectorfix could not find mech " << mech << endl;
						}
						else
						{
							raster_map(sec, target.x, target.y);

							cout << "applying sectorfix " << fixno << " on mech " << mech << " " << target.x<< "t" << target.y << " sec " << sec << endl;
						}
					}


				}

				else if (
						fix[fixpoint + 1] == 's' &&
						fix[fixpoint + 2] == 'a' &&
						fix[fixpoint + 3] == 'v' &&
						fix[fixpoint + 4] == 'e' &&
						fix[fixpoint + 5] == '_' &&
						fix[fixpoint + 6] == 'f' &&
						fix[fixpoint + 7] == 'i' &&
						fix[fixpoint + 8] == 'x' &&
						fix[fixpoint + 9] == ')')
				{
					if (fix_is_hot)
					{
						int fixno = util.get_int_at(fixpoint + 11, fix, fix_size);
						bool value =  (util.get_int_at(fixpoint + 17, fix, fix_size) > 0);
						(*global).player.set_sector_fix(value,fixno);
					}
				}
			}
		}
	}


	void load_tile_dwellers()
	{
		unload_all_monsters();
		unload_all_mechs();

		//(*global).lock_world_token(); //not locking because all tile lock should be active
		int tiles_x = (*global).tile_count_x;
		int tiles_y = (*global).tile_count_y;
		// (*global).unlock_world_token();

		for (int x = 0; x < tiles_x; x++)
		{
			for (int y = 0; y < tiles_y; y++)
			{
				//(*global).lock_tile(x,y); //not locking because all tile lock should be active
				if ( (*global).tile_exists(x,y) )
				{
					if ((*global).tile[x][y].has_mechanic)
					{
						load_mech((*(*global).tile[x][y].mech).type);
					}


					(*global).tile[x][y].monsters.reset_itt();
					while((*global).tile[x][y].monsters.can_request_next())
					{
						tile_monster* mon = (*global).tile[x][y].monsters.request_next();
						load_monster((*mon).type);
					}
				}
				//(*global).unlock_tile(x,y); //not locking because all tile lock should be active
			}
		}
	}


	void raster_map(int sec_no, int level_off_x, int level_off_y)
	{
		if (sec_no < 0 || sec_no > (*local).sectors_count -1)
		{
			cout << "DDT> level_load raster_map bad call" << endl;
			return;
		}


		int sector_point = -1;
		int cur_tile_x = 0;
		int cur_tile_y = 0;
		int cur_texg = -1;
		int current_random = 0;;

		while (sector_point < (*local).sector_byte_size[sec_no] - 10)
		{
			sector_point++;

			if ( !(  (*local).sector[sec_no][sector_point] == '(') )
			{
				// nothing
			}

			else if (
					((*local).sector[sec_no][sector_point + 1] == 't') &&
					((*local).sector[sec_no][sector_point + 2] == 'i') &&
					((*local).sector[sec_no][sector_point + 3] == 'l') &&
					((*local).sector[sec_no][sector_point + 4] == 'e') &&
					((*local).sector[sec_no][sector_point + 5] == ')') )
			{
					cur_tile_x = util.get_int_at(sector_point+  7, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					cur_tile_y = util.get_int_at(sector_point+  13, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);

					//cout << dec << cur_tile_x << " tile " << cur_tile_y <<  endl;
			}

			else if (
					((*local).sector[sec_no][sector_point + 1] == 't') &&
					((*local).sector[sec_no][sector_point + 2] == 'e') &&
					((*local).sector[sec_no][sector_point + 3] == 'x') &&
					((*local).sector[sec_no][sector_point + 4] == 'g') &&
					((*local).sector[sec_no][sector_point + 5] == ')') )
			{
					cur_texg = util.get_int_at(sector_point+  7, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);

			}


			else if (
					((*local).sector[sec_no][sector_point + 1] == 'm') &&
					((*local).sector[sec_no][sector_point + 2] == 'o') &&
					((*local).sector[sec_no][sector_point + 3] == 'v') &&
					((*local).sector[sec_no][sector_point + 4] == 'e') &&
					((*local).sector[sec_no][sector_point + 5] == ')') )
			{

				//(*global).lock_world_token(); //not locking because all tile lock should be active
				if ( (*global).tile_exists(cur_tile_x + level_off_x, cur_tile_y + level_off_y))
				{

					string argu = util.get_argument_at(sector_point+  7, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);

					if      ( argu == "all")  { (*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].set_walk_fly(true, true);}
					else if ( argu == "none") { (*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].set_walk_fly(false, false);}
					else if ( argu == "walk") { (*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].set_walk_fly(true, false);}
					else if ( argu == "fly")  { (*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].set_walk_fly(false, true);}
				}
				//(*global).unlock_world_token();

			}

			else if (
					((*local).sector[sec_no][sector_point + 1] == 'l') &&
					((*local).sector[sec_no][sector_point + 2] == 'i') &&
					((*local).sector[sec_no][sector_point + 3] == 'g') &&
					((*local).sector[sec_no][sector_point + 4] == 'h') &&
					((*local).sector[sec_no][sector_point + 5] == 't') &&
					((*local).sector[sec_no][sector_point + 6] == '_') &&
					((*local).sector[sec_no][sector_point + 7] == 'o') &&
					((*local).sector[sec_no][sector_point + 8] == 'p') &&
					((*local).sector[sec_no][sector_point + 9] == ')') )
			{
				string argu = util.get_argument_at(sector_point+  11, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);

				//(*global).lock_world_token();
				if ( (*global).tile_exists(cur_tile_x + level_off_x, cur_tile_y + level_off_y))
				{
					if ( argu == "proxfade")
					{
						(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].lighting_option = TILE_LIGHTING_OPTION_PROXFADE;
					}
					else if ( argu == "gooze")
					{
						(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].lighting_option = TILE_LIGHTING_OPTION_GOOZE;
					}
					else
					{
						(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].lighting_option = TILE_LIGHTING_OPTION_DEFAULT;
					}
				}
				//(*global).unlock_world_token();
			}

			else if (
					((*local).sector[sec_no][sector_point + 1] == 's') &&
					((*local).sector[sec_no][sector_point + 2] == 'e') &&
					((*local).sector[sec_no][sector_point + 3] == 'l') &&
					((*local).sector[sec_no][sector_point + 4] == 'f') &&
					((*local).sector[sec_no][sector_point + 5] == '_') &&
					((*local).sector[sec_no][sector_point + 6] == 'l') &&
					((*local).sector[sec_no][sector_point + 7] == 'u') &&
					((*local).sector[sec_no][sector_point + 8] == 'm') &&
					((*local).sector[sec_no][sector_point + 9] == ')') )
			{
				float r = (double)util.get_int_at_hex(sector_point  + 11, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]) /255.0;
				float g = (double)util.get_int_at_hex(sector_point  + 17, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]) /255.0;
				float b = (double)util.get_int_at_hex(sector_point  + 23, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]) /255.0;


				//(*global).lock_world_token();
				if ( (*global).tile_exists(cur_tile_x + level_off_x, cur_tile_y + level_off_y))
				{

					(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].passive_light_r = ddtmath::biggest_float_of(
							r,
							(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].passive_light_r);
					(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].passive_light_g = ddtmath::biggest_float_of(
							g,
							(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].passive_light_g);
					(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].passive_light_b = ddtmath::biggest_float_of(
							b,
							(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].passive_light_b);
				}
				//(*global).unlock_world_token();
			}

			else if (
					((*local).sector[sec_no][sector_point + 1] == 'l') &&
					((*local).sector[sec_no][sector_point + 2] == 'i') &&
					((*local).sector[sec_no][sector_point + 3] == 'g') &&
					((*local).sector[sec_no][sector_point + 4] == 'h') &&
					((*local).sector[sec_no][sector_point + 5] == 't') &&
					((*local).sector[sec_no][sector_point + 6] == ')') )
			{
				float r = (double)util.get_int_at_hex(sector_point  +  8, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]) /255.0;
				float g = (double)util.get_int_at_hex(sector_point  + 14, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]) /255.0;
				float b = (double)util.get_int_at_hex(sector_point  + 20, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]) /255.0;
				int rad_sq = (double)util.get_int_at_hex(sector_point  + 26, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);

				//(*global).lock_world_token();
				for (int xx = cur_tile_x + level_off_x - 3*rad_sq ; xx < cur_tile_x + level_off_x + 3*rad_sq; xx++)
				{
					for (int yy = cur_tile_y + level_off_y - 3*rad_sq ; yy < cur_tile_y + level_off_y + 3*rad_sq; yy++)
					{

						if ( (*global).tile_exists(xx, yy))
						{
							int tile_distance_sq = ddtmath::tile_distance_sq(xx,yy,cur_tile_x + level_off_x, cur_tile_y + level_off_y);
							float static_light_mod = ddtmath::static_lightness(tile_distance_sq, rad_sq);

							float rr = r*static_light_mod;
							float gg = g*static_light_mod;
							float bb = b*static_light_mod;

							(*global).tile[xx][yy].passive_light_r = ddtmath::biggest_float_of(rr,(*global).tile[xx][yy].passive_light_r);
							(*global).tile[xx][yy].passive_light_g = ddtmath::biggest_float_of(gg,(*global).tile[xx][yy].passive_light_g);
							(*global).tile[xx][yy].passive_light_b = ddtmath::biggest_float_of(bb,(*global).tile[xx][yy].passive_light_b);



						}

					}
				}
				//(*global).unlock_world_token();


			}

			else if (
					((*local).sector[sec_no][sector_point + 1] == 'g') &&
					((*local).sector[sec_no][sector_point + 2] == 'r') &&
					((*local).sector[sec_no][sector_point + 3] == 'o') &&
					((*local).sector[sec_no][sector_point + 4] == 'u') &&
					((*local).sector[sec_no][sector_point + 5] == 'n') &&
					((*local).sector[sec_no][sector_point + 6] == 'd') &&
					((*local).sector[sec_no][sector_point + 7] == ')') )
			{

					int a_tex_s = util.get_int_at_hex(sector_point  +  9, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int b_tex_s = util.get_int_at_hex(sector_point  + 15, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					//cout << dec << a_tex_g << " " << hex <<  a_tex_s << " " <<  dec << b_tex_g << " " << hex <<  b_tex_s << endl;

					//(*global).lock_world_token();
					if ( (*global).tile_exists(cur_tile_x + level_off_x, cur_tile_y + level_off_y))
					{
						(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].set_ground_textures(cur_texg, a_tex_s, cur_texg, b_tex_s);
					}
					//(*global).unlock_world_token();
			}
			else if (
					((*local).sector[sec_no][sector_point + 1] == 'g') &&
					((*local).sector[sec_no][sector_point + 2] == 'r') &&
					((*local).sector[sec_no][sector_point + 3] == 'o') &&
					((*local).sector[sec_no][sector_point + 4] == 'u') &&
					((*local).sector[sec_no][sector_point + 5] == 'n') &&
					((*local).sector[sec_no][sector_point + 6] == 'd') &&
					((*local).sector[sec_no][sector_point + 7] == '_') &&
					((*local).sector[sec_no][sector_point + 8] == 'a') &&
					((*local).sector[sec_no][sector_point + 9] == 'l') &&
					((*local).sector[sec_no][sector_point +10] == 't') &&
					((*local).sector[sec_no][sector_point +11] == ')') )
			{

					int a_tex_s = util.get_int_at_hex(sector_point  + 13, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int b_tex_s = util.get_int_at_hex(sector_point  + 19, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					//cout << dec  << " " << hex <<  a_tex_s << " " <<  dec <<  " " << hex <<  b_tex_s << endl;

					//(*global).lock_world_token();
					if ( (*global).tile_exists(cur_tile_x + level_off_x, cur_tile_y + level_off_y))
					{
						(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].set_alt_ground_textures(a_tex_s, b_tex_s);
					}
					//(*global).unlock_world_token();
			}

			else if (
					((*local).sector[sec_no][sector_point + 1] == 'a') &&
					((*local).sector[sec_no][sector_point + 2] == 'i') &&
					((*local).sector[sec_no][sector_point + 3] == 'r') &&
					((*local).sector[sec_no][sector_point + 4] == ')') )
			{
					int tex_s = util.get_int_at_hex(sector_point + 6, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int mov_x = util.get_int_at(sector_point     +12, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int mov_y = util.get_int_at(sector_point     +18, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					//cout << dec << a_tex_g << " " << hex <<  a_tex_s << " " <<  dec << b_tex_g << " " << hex <<  b_tex_s << endl;

					//(*global).lock_tile(cur_tile_x + level_off_x, cur_tile_y + level_off_y);
					if ( (*global).tile_exists(cur_tile_x + level_off_x, cur_tile_y + level_off_y))
					{
						tile_air_tex* air = new tile_air_tex(cur_texg, tex_s, mov_x, mov_y);
						(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].airtex.add_tex(air);
					}
					//(*global).unlock_tile(cur_tile_x + level_off_x, cur_tile_y + level_off_y);
			}
			else if (
					((*local).sector[sec_no][sector_point + 1] == 'a') &&
					((*local).sector[sec_no][sector_point + 2] == 'i') &&
					((*local).sector[sec_no][sector_point + 3] == 'r') &&
					((*local).sector[sec_no][sector_point + 4] == '_') &&
					((*local).sector[sec_no][sector_point + 5] == 'o') &&
					((*local).sector[sec_no][sector_point + 6] == 'o') &&
					((*local).sector[sec_no][sector_point + 7] == 'z') &&
					((*local).sector[sec_no][sector_point + 8] == 'e') &&
					((*local).sector[sec_no][sector_point + 9] == ')') )
			{
					int tex_s = util.get_int_at_hex(sector_point +11, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int mov_x = util.get_int_at(sector_point     +17, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int mov_y = util.get_int_at(sector_point     +23, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					//cout << dec << a_tex_g << " " << hex <<  a_tex_s << " " <<  dec << b_tex_g << " " << hex <<  b_tex_s << endl;

					//(*global).lock_tile(cur_tile_x + level_off_x, cur_tile_y + level_off_y);
					if ( (*global).tile_exists(cur_tile_x + level_off_x, cur_tile_y + level_off_y))
					{
						tile_air_tex* air = new tile_air_tex(cur_texg, tex_s, mov_x, mov_y, true);
						(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].airtex.add_tex(air);
					}
					//(*global).unlock_tile(cur_tile_x + level_off_x, cur_tile_y + level_off_y);
			}
			else if (
					((*local).sector[sec_no][sector_point + 1] == 'm') &&
					((*local).sector[sec_no][sector_point + 2] == 'o') &&
					((*local).sector[sec_no][sector_point + 3] == 'n') &&
					((*local).sector[sec_no][sector_point + 4] == 's') &&
					((*local).sector[sec_no][sector_point + 5] == 't') &&
					((*local).sector[sec_no][sector_point + 6] == 'e') &&
					((*local).sector[sec_no][sector_point + 7] == 'r') &&
					((*local).sector[sec_no][sector_point + 8] == ')') )
			{
					int monref   = util.get_int_at(     sector_point +10, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);


					if ((!(*global).monsters.savable(monref))  || (load_savable_elements) )
					{
						string direcs = util.get_argument_at(sector_point +16, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
						int direci;

						     if ( direcs == "nn") { direci = DIRECTION_N;}
						else if ( direcs == "ne") { direci = DIRECTION_NE;}
						else if ( direcs == "ee") { direci = DIRECTION_E;}
						else if ( direcs == "se") { direci = DIRECTION_SE;}
						else if ( direcs == "ss") { direci = DIRECTION_S;}
						else if ( direcs == "sw") { direci = DIRECTION_SW;}
						else if ( direcs == "ww") { direci = DIRECTION_W;}
						else if ( direcs == "nw") { direci = DIRECTION_NW;}
						else { direci = util.random_direction();}


						//(*global).lock_tile(cur_tile_x + level_off_x, cur_tile_y + level_off_y);
						if ( (*global).tile_exists(cur_tile_x + level_off_x, cur_tile_y + level_off_y))
						{
							tile_monster* mo = new tile_monster;
							(*mo).type = monref;
							(*mo).facing = direci;
							(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].monsters.add(mo);
						}
						//(*global).unlock_tile(cur_tile_x + level_off_x, cur_tile_y + level_off_y);

					}


			}
			else if (
					((*local).sector[sec_no][sector_point + 1] == 'm') &&
					((*local).sector[sec_no][sector_point + 2] == 'e') &&
					((*local).sector[sec_no][sector_point + 3] == 'c') &&
					((*local).sector[sec_no][sector_point + 4] == 'h') &&
					((*local).sector[sec_no][sector_point + 5] == ')') )
			{
					int mechref   = util.get_int_at(     sector_point + 7, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					string mech_is_on = util.get_argument_at(sector_point +13, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					bool mech_on = (mech_is_on == "+");

					if ((!(*global).mechanics.savable(mechref))  || (load_savable_elements) )
					{
						//(*global).lock_tile(cur_tile_x + level_off_x, cur_tile_y + level_off_y);
						if ( (*global).tile_exists(cur_tile_x + level_off_x, cur_tile_y + level_off_y))
						{
							tile_mechanic* me = new tile_mechanic;
							(*me).type = mechref;
							(*me).is_open = mech_on;
							(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].place_mechanic(me);

						}
						//(*global).unlock_tile(cur_tile_x + level_off_x, cur_tile_y + level_off_y);
					}


			}
			else if (
					((*local).sector[sec_no][sector_point + 1] == 'd') &&
					((*local).sector[sec_no][sector_point + 2] == 'u') &&
					((*local).sector[sec_no][sector_point + 3] == 'm') &&
					((*local).sector[sec_no][sector_point + 4] == 'm') &&
					((*local).sector[sec_no][sector_point + 5] == 'y') &&
					((*local).sector[sec_no][sector_point + 6] == ')') )
			{
					string mech_is_on = util.get_argument_at(sector_point +8, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					bool mech_on = (mech_is_on == "+");


					if (random_dummy_dispence_pointer < 8 && load_savable_elements)
					{
						int mechref = random_dummy_dispence[random_dummy_dispence_pointer];
						random_dummy_dispence_pointer ++;

						if ( (*global).tile_exists(cur_tile_x + level_off_x, cur_tile_y + level_off_y))
						{
							tile_mechanic* me = new tile_mechanic;
							(*me).type = mechref;
							(*me).is_open = mech_on;
							(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].place_mechanic(me);
						}
					}
			}

			else if (
					((*local).sector[sec_no][sector_point + 1] == 'r') &&
					((*local).sector[sec_no][sector_point + 2] == 'e') &&
					((*local).sector[sec_no][sector_point + 3] == 'c') &&
					((*local).sector[sec_no][sector_point + 4] == 'u') &&
					((*local).sector[sec_no][sector_point + 5] == 'r') &&
					((*local).sector[sec_no][sector_point + 6] == 's') &&
					((*local).sector[sec_no][sector_point + 7] == 'e') &&
					((*local).sector[sec_no][sector_point + 8] == 'c') &&
					((*local).sector[sec_no][sector_point + 9] == ')') )
			{
					int recsec = util.get_int_at(sector_point   + 11, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int recsec_x = util.get_int_at(sector_point + 17, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int recsec_y = util.get_int_at(sector_point + 23, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);

					raster_map(recsec, level_off_x + recsec_x, level_off_y+recsec_y);


			}

			else if (
					((*local).sector[sec_no][sector_point + 1] == 'c') &&
					((*local).sector[sec_no][sector_point + 2] == 'l') &&
					((*local).sector[sec_no][sector_point + 3] == 'e') &&
					((*local).sector[sec_no][sector_point + 4] == 'a') &&
					((*local).sector[sec_no][sector_point + 5] == 'n') &&
					((*local).sector[sec_no][sector_point + 6] == '_') &&
					((*local).sector[sec_no][sector_point + 7] == 'a') &&
					((*local).sector[sec_no][sector_point + 8] == 'i') &&
					((*local).sector[sec_no][sector_point + 9] == 'r') &&
					((*local).sector[sec_no][sector_point +10] == ')') )
			{

				//(*global).lock_tile(cur_tile_x + level_off_x, cur_tile_y + level_off_y);
				if ( (*global).tile_exists(cur_tile_x + level_off_x, cur_tile_y + level_off_y))
				{
					(*global).tile[cur_tile_x + level_off_x][cur_tile_y + level_off_y].airtex.kill();
				}
				//(*global).unlock_tile(cur_tile_x + level_off_x, cur_tile_y + level_off_y);

			}

			else if (
					((*local).sector[sec_no][sector_point + 1] == 'r') &&
					((*local).sector[sec_no][sector_point + 2] == 'a') &&
					((*local).sector[sec_no][sector_point + 3] == 'n') &&
					((*local).sector[sec_no][sector_point + 4] == 'd') &&
					((*local).sector[sec_no][sector_point + 5] == ')') )
			{
					int mod =  1 + util.get_int_at(sector_point + 7, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					if (mod < 1) {mod = 1;}
					unsigned char* save = (*local).psave.show_static_part();
					int pop_block = ddtsavegame::get_random_block(random_block_pointer, save,ddtsavegame::static_size());


					current_random = ddtmath::modu(pop_block,mod);
					random_block_pointer++;
			}
			else if (
					((*local).sector[sec_no][sector_point + 1] == 'i') &&
					((*local).sector[sec_no][sector_point + 2] == 'f') &&
					((*local).sector[sec_no][sector_point + 3] == '_') &&
					((*local).sector[sec_no][sector_point + 4] == 'r') &&
					((*local).sector[sec_no][sector_point + 5] == 'a') &&
					((*local).sector[sec_no][sector_point + 6] == 'n') &&
					((*local).sector[sec_no][sector_point + 7] == 'd') &&
					((*local).sector[sec_no][sector_point + 8] == ')') )
			{
					int rnd =  util.get_int_at(sector_point + 10, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);

					if (rnd == current_random)
					{
						//not skipping
					}
					else
					{
						sector_point = sector_point + 20; //to miss the next command
					}
			}
			else if (
					((*local).sector[sec_no][sector_point + 1] == 'i') &&
					((*local).sector[sec_no][sector_point + 2] == 'f') &&
					((*local).sector[sec_no][sector_point + 3] == '_') &&
					((*local).sector[sec_no][sector_point + 4] == 'h') &&
					((*local).sector[sec_no][sector_point + 5] == 'f') &&
					((*local).sector[sec_no][sector_point + 6] == ')') )
			{

				    if ( (*global).game_mode != GAME_MODE_EXP)
					{
				    	sector_point = sector_point + 10; //to miss the next command
					}

			}

			else if (
					((*local).sector[sec_no][sector_point + 1] == 'r') &&
					((*local).sector[sec_no][sector_point + 2] == 'n') &&
					((*local).sector[sec_no][sector_point + 3] == 'd') &&
					((*local).sector[sec_no][sector_point + 4] == '_') &&
					((*local).sector[sec_no][sector_point + 5] == 'd') &&
					((*local).sector[sec_no][sector_point + 6] == 'u') &&
					((*local).sector[sec_no][sector_point + 7] == 'm') &&
					((*local).sector[sec_no][sector_point + 8] == '_') &&
					((*local).sector[sec_no][sector_point + 9] == 'd') &&
					((*local).sector[sec_no][sector_point +10] == 'i') &&
					((*local).sector[sec_no][sector_point +11] == 's') &&
					((*local).sector[sec_no][sector_point +12] == 'p') &&
					((*local).sector[sec_no][sector_point +13] == ')') )
			{
				if (load_savable_elements)
				{
					int a =  util.get_int_at(sector_point + 15, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int b =  util.get_int_at(sector_point + 21, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int c =  util.get_int_at(sector_point + 27, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int d =  util.get_int_at(sector_point + 33, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int e =  util.get_int_at(sector_point + 39, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int f =  util.get_int_at(sector_point + 45, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int g =  util.get_int_at(sector_point + 51, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);
					int h =  util.get_int_at(sector_point + 57, (*local).sector[sec_no], (*local).sector_byte_size[sec_no]);

					reset_random_dummy_dispence(a, b, c, d, e, f, g, h);
				}

			}


		}


	}



	void reset_tilegrid(int new_x, int new_y)
	{

		//(*global).lock_all_tiles(); //this is done in the word main now


		if (new_x < 1 || new_y < 1 )
		{
			cout << "DDT> world_manager reset_tilegrid bad call" << endl;
			return;
		}


		if (( (*global).tile_count_x > 0) && ( (*global).tile_count_y > 0))
		{
			for (int i = 0; i < (*global).tile_count_x ; i ++)
			{
				for (int j = 0; j < (*global).tile_count_y ; j ++)
				{
					(*global).tile[i][j].kill();
				}

				delete[] (*global).tile[i];
			}
			delete[] (*global).tile;
		}

		(*global).tile = new world_tile*[new_x];

		for (int i = 0; i < new_x ; i ++)
		{
			(*global).tile[i] = new world_tile[new_y];
		}

		(*global).tile_count_x = new_x;
		(*global).tile_count_y = new_y;


		//(*global).unlock_all_tiles();


	}

	void unload_all_monsters()
	{
		for (int i = 0; i < MON_COUNT; i++)
		{
			if ((*global).monsters.mon[i].is_loaded)
			{
				if ((*global).monsters.mon[i].clean_own_vid_pak)
				{
					int ul_pak_v = (*global).monsters.mon[i].pakref_vid;
					if (ul_pak_v != PAK_DEFAULT && ul_pak_v > -1)
					{
						post = new mail(TRANSCODE_RESET_GRFX_PAK,ul_pak_v, 0);
						(*global).threadpush_transcode(post);
					}
				}
				if ((*global).monsters.mon[i].clean_own_aud_pak)
				{
					int ul_pak_a = (*global).monsters.mon[i].pakref_aud;
					if ( ul_pak_a != PAK_DEFAULT && ul_pak_a > -1)
					{
						post = new mail(TRANSCODE_RESET_AUDIO_PAK,ul_pak_a, 0);
						(*global).threadpush_transcode(post);
					}
				}

				(*global).monsters.mon[i].is_loaded = false;
			}
		}
	}

	void load_monster(int no)
	{
		if (!(*global).monsters.exists(no)) {return;}
		if ((*global).monsters.mon[no].is_loaded) {return;}

		int lo_sz = (*global).monsters.mon[no].loadme_size;
		if (lo_sz < 1){return;}
		unsigned char* lo = (*global).monsters.mon[no].give_loadme_rules();


		post = new mail(FILEIO_LOAD_PROVIDED_RULES, lo, lo_sz);
		(*global).threadpush_filesystem(post);
		(*global).monsters.mon[no].is_loaded = true;

	}

	void unload_all_mechs()
	{
		for (int i = 0; i < TILE_MECH_COUNT; i++)
		{
			if ((*global).mechanics.mech[i].is_loaded)
			{
				if ((*global).mechanics.mech[i].clean_own_vid_pak)
				{
					int ul_pak_v = (*global).mechanics.mech[i].pakref_vid;
					if (ul_pak_v != PAK_DEFAULT && ul_pak_v > -1)
					{
						post = new mail(TRANSCODE_RESET_GRFX_PAK,ul_pak_v, 0);
						(*global).threadpush_transcode(post);
					}
				}
				if ((*global).mechanics.mech[i].clean_own_aud_pak)
				{
					int ul_pak_a = (*global).mechanics.mech[i].pakref_aud;
					if ( ul_pak_a != PAK_DEFAULT && ul_pak_a > -1)
					{
						post = new mail(TRANSCODE_RESET_AUDIO_PAK,ul_pak_a, 0);
						(*global).threadpush_transcode(post);
					}
				}

				(*global).mechanics.mech[i].is_loaded = false;
			}
		}
	}

	void load_mech(int no)
	{
		if (!(*global).mechanics.exists(no)) {return;}
		if ((*global).mechanics.mech[no].is_loaded) {return;}

		int lo_sz = (*global).mechanics.get_loadme_size(no);
		if (lo_sz < 1) {return;}
		unsigned char* lo = (*global).mechanics.get_loadme_rules(no);


		post = new mail(FILEIO_LOAD_PROVIDED_RULES, lo, lo_sz);
		(*global).threadpush_filesystem(post);
		(*global).mechanics.mech[no].is_loaded = true;

	}


	void order_dun_sector_load_from_statics(int lev)
	{
		if (!(*global).dungeons.exists(lev)) {return;}

		string sec_source = (*global).dungeons.get_sector_source(lev);
		post = new mail(FILEIO_LOAD_RULES, sec_source);
		(*global).threadpush_filesystem(post);
	}


	void load_dungeon_info_from_statics(int lev)
	{
		if (!(*global).dungeons.exists(lev)) {return;}

		//the name
		(*global).level_name.set((*global).dungeons.get_game(lev));

		//the look
		unsigned char* savestat = (*local).psave.show_static_part();
		uint8_t rnd = ddtsavegame::get_random_block(lev,savestat, ddtsavegame::static_size());
		int dunlook_no = (*global).dungeons.get_look_from_random(lev, rnd);
		if (!(*global).dunlooks.exists(dunlook_no)) {return;}
		int lo_sz = (*global).dunlooks.dun[dunlook_no].loadme_size;
		if (lo_sz < 1) {return;}
		unsigned char* lo = (*global).dunlooks.dun[dunlook_no].give_loadme_rules();
		post = new mail(FILEIO_LOAD_PROVIDED_RULES, lo, lo_sz);
		(*global).threadpush_filesystem(post);

	}

	di_int find_mechanic_on_tiles(int mechno)
	{
		di_int out(0,0);

		for (int x = 0; x < (*global).tile_count_x; x++)
		{
			for (int y = 0; y < (*global).tile_count_y; y++)
			{
				//(*global).lock_tile(x,y); all tile lock assumed
				if ((*global).tile_exists(x,y))
				{
					if ((*global).tile[x][y].has_mechanic)
					{
						if( mechno == (*(*global).tile[x][y].mech).type )
						{
							out.x = x; out.y = y;
						}
					}
				}

				//(*global).unlock_tile(x,y);

			}
		}

		return out;
	}


	void reset_random_dummy_dispence(int a, int b, int c, int d, int e, int f, int g, int h)
	{

		int temp_hold[8];
		temp_hold[0] = a;
		temp_hold[1] = b;
		temp_hold[2] = c;
		temp_hold[3] = d;
		temp_hold[4] = e;
		temp_hold[5] = f;
		temp_hold[6] = g;
		temp_hold[7] = h;



		bool target_taken[8];

		for (int i = 0; i < 8; i++)
		{
			target_taken[i] = false;
		}


		for (int i = 0; i < 8; i++)
		{
			bool found = false;

			while(!found)
			{
				int target = ddtmath::random_int(7);

				if (!target_taken[target])
				{
					random_dummy_dispence[target] = temp_hold[i];
					target_taken[target] = true;
					found = true;
				}
			}
		}

		random_dummy_dispence_pointer = 0;


		for (int i = 0; i < 8; i++)
		{
			cout << dec << random_dummy_dispence[i] << " ";
		}
		cout << endl;




	}

	void generate_texure_filter(unsigned char* levtxt, int levtxt_size)
	{
		int texture_count = 0x443;
		bool post_used = true;

		bool* used = new bool[texture_count];

		for (int i = 0; i < texture_count; i ++)
		{
			used[i] = false;
		}

		int levtxt_point = -1;



		while (levtxt_point < levtxt_size - 12)
		{
			levtxt_point++;

			if ( !(  levtxt[levtxt_point] == '(') )
			{
				// nothing
			}
			else if (
					(levtxt[levtxt_point + 1] == 'g') &&
					(levtxt[levtxt_point + 2] == 'r') &&
					(levtxt[levtxt_point + 3] == 'o') &&
					(levtxt[levtxt_point + 4] == 'u') &&
					(levtxt[levtxt_point + 5] == 'n') &&
					(levtxt[levtxt_point + 6] == 'd') &&
					(levtxt[levtxt_point + 7] == ')') )
			{

					int frame = util.get_int_at_hex(levtxt_point  +  9, levtxt, levtxt_size);
					if (frame > 0 && frame < texture_count) {used[frame] = true;}


					frame = util.get_int_at_hex(levtxt_point  + 15, levtxt, levtxt_size);
					if (frame > 0 && frame < texture_count) {used[frame] = true;}

			}
			else if (
					(levtxt[levtxt_point + 1] == 'g') &&
					(levtxt[levtxt_point + 2] == 'r') &&
					(levtxt[levtxt_point + 3] == 'o') &&
					(levtxt[levtxt_point + 4] == 'u') &&
					(levtxt[levtxt_point + 5] == 'n') &&
					(levtxt[levtxt_point + 6] == 'd') &&
					(levtxt[levtxt_point + 7] == '_') &&
					(levtxt[levtxt_point + 8] == 'a') &&
					(levtxt[levtxt_point + 9] == 'l') &&
					(levtxt[levtxt_point +10] == 't') &&
					(levtxt[levtxt_point +11] == ')') )
			{

				int frame = util.get_int_at_hex(levtxt_point  +  13, levtxt, levtxt_size);
				if (frame > 0 && frame < texture_count) {used[frame] = true;}

				frame = util.get_int_at_hex(levtxt_point  + 19, levtxt, levtxt_size);
				if (frame > 0 && frame < texture_count) {used[frame] = true;}

			}

			else if (
					(levtxt[levtxt_point + 1] == 'a') &&
					(levtxt[levtxt_point + 2] == 'i') &&
					(levtxt[levtxt_point + 3] == 'r') &&
					(levtxt[levtxt_point + 4] == ')') )
			{
					int frame = util.get_int_at_hex(levtxt_point  +  6, levtxt, levtxt_size);
					if (frame > 0 && frame < texture_count) {used[frame] = true;}

			}
			else if (
					(levtxt[levtxt_point + 1] == 'a') &&
					(levtxt[levtxt_point + 2] == 'i') &&
					(levtxt[levtxt_point + 3] == 'r') &&
					(levtxt[levtxt_point + 4] == '_') &&
					(levtxt[levtxt_point + 5] == 'o') &&
					(levtxt[levtxt_point + 6] == 'o') &&
					(levtxt[levtxt_point + 7] == 'z') &&
					(levtxt[levtxt_point + 8] == 'e') &&
					(levtxt[levtxt_point + 9] == ')') )
			{
					int frame = util.get_int_at_hex(levtxt_point  +  11, levtxt, levtxt_size);
					if (frame > 0 && frame < texture_count) {used[frame] = true;}

			}

		}



		if (post_used)
		{
			for (int i = 0; i < texture_count; i ++)
			{
				if (used[i] == true)
				{
					if (i < 0x10)
					{
						cout << "(set0x)[..." << hex << i << "][...1]" << endl;
					}
					else if (i < 0x100)
					{
						cout << "(set0x)[.." << hex << i << "][...1]" << endl;
					}
					else if (i < 0x1000)
					{
						cout << "(set0x)[." << hex << i << "][...1]" << endl;
					}
				}
			}
		}




		if (!post_used)
		{
			int unused_count = 0;
			for (int i = 0; i < texture_count; i ++)
			{
				if (used[i] == false)
				{
					if (i < 0x10)
					{
						cout << "(set0x)[..." << hex << i << "][...0]" << endl;
					}
					else if (i < 0x100)
					{
						cout << "(set0x)[.." << hex << i << "][...0]" << endl;
					}
					else if (i < 0x1000)
					{
						cout << "(set0x)[." << hex << i << "][...0]" << endl;
					}
					unused_count++;
				}
			}
			cout << "unused textures " << dec << unused_count << " of total " << texture_count << endl;
		}





		delete[] used;
	}



};
