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



#include "levu_wld_player_savegame.cpp"
using namespace std;



class player_class
{
public:

	int combat_texref_size[CLASSTX_COUNT];
	int no_combat_texref_size[CLASSTX_COUNT];
	unsigned char* no_combat_texref[CLASSTX_COUNT];
	unsigned char* combat_texref[CLASSTX_COUNT];


	int class_number;

	int str_start; int str_max;
	int mag_start; int mag_max;
	int dex_start; int dex_max;
	int vit_start; int vit_max;

	unsigned char* start_item[START_ITEM_COUNT];

	int packed_item_size;




	player_class()
	{

		for (int i = 0; i < CLASSTX_COUNT; i++)
		{
			no_combat_texref_size[i] = 0;
			combat_texref_size[i] = 0;
		}

		class_number = 0;

		str_start = 10; str_max = 255;
		mag_start = 10; mag_max = 255;
		dex_start = 10; dex_max = 255;
		vit_start = 10; vit_max = 255;


		packed_item_size = ddtsavegame::item_size();

		for (int i = 0; i < START_ITEM_COUNT; i++)
		{
			start_item[i] = new unsigned char[packed_item_size];

			for (int j = 0; j < packed_item_size; j++)
			{
				start_item[i][j] = 0;
			}
		}

	}

	void add_start_item(int slot, unsigned char* item, int item_size)
	{
		if ( slot < 0 || slot > START_ITEM_COUNT -1 || (item_size != packed_item_size))
		{
			cout << "DDT> player_class add_start_item received bad info" << endl;
			return;
		}

		for (int i = 0; i < packed_item_size; i ++)
		{
			start_item[slot][i] = item[i];
		}

		delete[] item;
	}



	void add_texref(int slot, bool combat, unsigned char* ref, int ref_size)
	{
		if (slot < 0 || slot > CLASSTX_COUNT -1 || ref_size < 1)
		{
			cout << "DDT> Bogus player_class add_texref call" << endl;
			return;
		}


		if (combat)
		{
			if ( combat_texref_size[slot] > 0)
			{
				delete[] combat_texref[slot];
			}

			combat_texref_size[slot] = ref_size;
			combat_texref[slot] = ref;
		}

		else // nocombat
		{
			if ( no_combat_texref_size[slot] > 0)
			{
				delete[] no_combat_texref[slot];
			}

			no_combat_texref_size[slot] = ref_size;
			no_combat_texref[slot] = ref;
		}

	}


	int_ucharp give_texref_rules( int slot, bool combat)
	{
		if ( slot < 0 || slot > CLASSTX_COUNT -1)
		{
			cout << "DDT> player_class give_texref_rules bad call" << endl;
			return int_ucharp();
		}

		if ( combat && combat_texref_size[slot] < 20)
		{
			cout << "DDT> player_class give_texref_rules requesting an empty" << endl;
			return int_ucharp();
		}

		if ( !combat && no_combat_texref_size[slot] < 20)
		{
			cout << "DDT> player_class give_texref_rules requesting an empty" << endl;
			return int_ucharp();
		}


		unsigned char* out;
		int out_size = 0;

		if ( combat)
		{
			out_size = combat_texref_size[slot];
			out = new unsigned char[out_size];

			for (int i = 0; i < out_size; i++)
			{
				out[i] = combat_texref[slot][i];
			}
		}
		else // !combat
		{
			out_size = no_combat_texref_size[slot];
			out = new unsigned char[out_size];

			for (int i = 0; i < out_size; i++)
			{
				out[i] = no_combat_texref[slot][i];
			}
		}

		return int_ucharp(out_size, out);

	}




};
