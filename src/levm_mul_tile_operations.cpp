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




#include "levn_mul_shared_gamedata.cpp"
using namespace std;

/*

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
*/



class tileopp
{
	public:

	static di_int find_and_lock_tile_to_drop_item(globals* global, bool prev_lock, int prevlock_x, int prevlock_y, int intent_x, int intent_y)
	{



		int ring = 1;
		int ring_min_x = intent_x - 1;
		int ring_min_y = intent_y - 1;
		int ring_max_x = intent_x + 1;
		int ring_max_y = intent_y + 1;

		bool tried_origin = false;

		while (ring < 10)
		{
			//horizontal parts of the ring
			for ( int x = ring_min_x; x < ring_max_x + 1 ; x++)
			{
				if (lock_tile_if_item_can_be_dropped(global, prev_lock, prevlock_x, prevlock_y, x, ring_min_y)) { return di_int(x, ring_min_y);}
				if (lock_tile_if_item_can_be_dropped(global, prev_lock, prevlock_x, prevlock_y, x, ring_max_y)) { return di_int(x, ring_max_y);}
			}

			//vertical parts of the ring
			for ( int y = ring_min_y + 1 ; y < ring_max_y ; y++)
			{
				if (lock_tile_if_item_can_be_dropped(global, prev_lock, prevlock_x, prevlock_y, ring_min_x, y)) { return di_int(ring_min_x, y);}
				if (lock_tile_if_item_can_be_dropped(global, prev_lock, prevlock_x, prevlock_y, ring_max_x, y)) { return di_int(ring_max_x, y);}
			}

			ring++;
			ring_min_x--;
			ring_min_y--;
			ring_max_x++;
			ring_max_y++;


			if (ring == 2 && !tried_origin)
			{
				tried_origin = true;
				if(lock_tile_if_item_can_be_dropped(global, prev_lock, prevlock_x, prevlock_y, intent_x, intent_y)) {return di_int(intent_x, intent_y);}
			}

		}

		return di_int(-1, -1);

	}



	static bool lock_tile_if_item_can_be_dropped(globals* global, bool prev_lock, int prevlock_x, int prevlock_y, int tar_x, int tar_y)
	{

		(*global).lock_tile(prev_lock, prevlock_x, prevlock_y, tar_x, tar_y);

		if((*global).tile_exists(tar_x, tar_y))
		{

			world_tile* probe = &((*global).tile[tar_x][tar_y]);

			if ((*probe).walkable && (*probe).flyable)
			{
				if ((!(*probe).has_item) && (!(*probe).has_mechanic))
				{
					if (!(*probe).monsters.has_monster_unrelyable())
					{
						return true;
						//yes, deliberately jumping out of a lock here.
					}
				}
			}
		}

		(*global).unlock_tile(prev_lock, prevlock_x, prevlock_y, tar_x, tar_y);
		return false;
	}
};
