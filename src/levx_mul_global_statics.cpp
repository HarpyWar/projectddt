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




#include "levx_mul_utils.cpp"
using namespace std;



//this is where we keep all the palate files from the mpq archives
// basically a simple 2D array of unsigned chars
class palkeeper
{

	public:
    unsigned char* pal[PALKEEP_SIZE];


    palkeeper()
	{

		for (int i = 0; i <  PALKEEP_SIZE; i++)
		{
			pal[i] = new unsigned char[PALSIZE];

			for(int j = 0; j < PALSIZE; j++)
			{
				pal[i][j] = 0;
			}
		}

	}

    bool exists(int no)
    {
    	if ( no < 0) {return false;}
    	if (no > PALKEEP_SIZE -1)  {return false;}
    	return true;
    }

	void set_pal(int no, int_ucharp pl)
	{
		if ((!exists(no)) || (!(pl.i == PALSIZE)))
		{
			cout << "DDT> palkeeper bad set " << pl.i <<  " " << PALSIZE << " "<< no << endl;
		}
		else
		{
			for(int j = 0; j < PALSIZE; j++)
			{
				pal[no][j] = (pl.c)[j];
			}

			delete[] pl.c;
		}
	}

/*
	// This sets a trn file, trn are basically 256 byte mappers of a pal
	// We are going to 'render' them to proper pals
	void set_trn(int no, int_ucharp tr, int palref)
	{
		if (( no < -1) || (no >  size -1) || (tr.i != TRNSIZE) || ( palref < -1) || (palref >  size -1)  )
		{
			cout << "DDT> palkeeper bad trn set" << endl;
		}
		else
		{
			for (int i = 0; i < TRNSIZE ; i++)
			{
				int curbyte = (int) tr.c[i];
				pal[no][ (3*i)+0 ] = pal[palref][ (3*curbyte)+0  ];
				pal[no][ (3*i)+1 ] = pal[palref][ (3*curbyte)+1  ];
				pal[no][ (3*i)+2 ] = pal[palref][ (3*curbyte)+2  ];
			}

			delete[] tr.c;
		}
	}

*/
};

class monster_ref
{
public:
	threadsave_string name;
	int16_t pakref_vid;
	int16_t pakref_aud;

	bool is_loaded;

	// ONLY TO BE SET AT GAME START
	unsigned char* loadme;
	int16_t loadme_size;

	bool clean_own_vid_pak;
	bool clean_own_aud_pak;

	// warning end

	int16_t ani_stand;
	int16_t ani_walk;
	int16_t ani_attack;
	int16_t ani_firec;
	int16_t ani_lightc;
	int16_t ani_bonec;
	int16_t ani_hitrec;
	int16_t ani_death;
	int16_t selection_height;
	bool ani_direction;

	int16_t stepsound_min;
	int16_t stepsound_max;

	int16_t interaction_ref;

	bool is_savable;
	int16_t brains;

	monster_ref()
	{
		pakref_vid = -1;
		pakref_aud = -1;
		is_loaded = false;
		loadme_size = 0;
		clean_own_vid_pak = true;
		clean_own_aud_pak = true;
        is_savable = true;


		ani_direction = true;
		selection_height = 0;
		stepsound_min = -1;
		stepsound_max = -1;
        interaction_ref =  MONSTER_INTERACTION_REF_VOID;
        brains = BRAINS_NONE;

	}

	unsigned char* give_loadme_rules()
	{
		if (loadme_size < 1) {return NULL;}

		unsigned char* out = new unsigned char[loadme_size];
		for (int i = 0; i < loadme_size; i++)
		{
			out[i] = loadme[i];
		}

		return out;
	}

};

class monster_ref_keeper
{
	public:

	monster_ref mon[MON_COUNT];

	bool exists(int16_t mn)
	{
		if ( mn < 0) {return false;}
		if ( mn > MON_COUNT -1) {return false;}
		return true;
	}

	bool selectable(int16_t mn)
	{
		if (!exists(mn)){return false;}
		if ( mon[mn].selection_height < 1){return false;}
		return true;
	}

	bool savable(int16_t mn)
	{
		if (!exists(mn)){return false;}
		return mon[mn].is_savable;
	}



};


class dungeonlook
{
	public:
	int16_t pakref_vid;
	int16_t pakref_aud;


	// ONLY TO BE SET AT GAME START
	unsigned char* loadme;
	int16_t loadme_size;


	dungeonlook()
	{
		pakref_vid = -1;
		pakref_aud = -1;
		loadme_size = 0;
	}

	unsigned char* give_loadme_rules()
	{
		if (loadme_size < 1) {return NULL;}

		//cout << "dunlook loadme size " <<  loadme_size << endl;

		unsigned char* out = new unsigned char[loadme_size];
		for (int i = 0; i < loadme_size; i++)
		{
			out[i] = loadme[i];

		}


		return out;
	}
};

class dungeonlook_keeper
{
	public:
	dungeonlook dun[DUNLOOK_COUNT];


	bool exists(int16_t d)
	{
		if ( d < 0) {return false;}
		if ( d > DUNLOOK_COUNT -1) {return false;}
		return true;
	}

};

class dungeon_ref
{
	public:

	string name;
	string sector_source;
	string loadbg;
	string on_first_load_extra;

	int sector_prime;

	int dunlook_from;
	int dunlook_to;

	int tile_dim_x;
	int tile_dim_y;

	dungeon_ref()
	{
		name = "";
		sector_source = "";
		loadbg = "";
		on_first_load_extra = "";

		sector_prime = -1;
		dunlook_from = 0;
		dunlook_to = 0;

		tile_dim_x = 20;
		tile_dim_y = 20;
	}
};

class dungeon_ref_keeper
{
	private:
	dungeon_ref dun[LEVEL_COUNT];
	public:

	bool exists(int d)
	{
		if ( d < 0) {return false;}
		if ( d > LEVEL_COUNT -1) {return false;}
		return true;
	}

	int get_look_from_random(int dunno, uint8_t rnd)
	{
		if (!exists(dunno)){ return 0;}

		int choise_space = dun[dunno].dunlook_to - dun[dunno].dunlook_from +1;
		int mod = ddtmath::modu(rnd, choise_space);

		return mod + dun[dunno].dunlook_from;
	}

	void set_look(int dunno, int from, int to)
	{
		if (!exists(dunno)){return;}
		dun[dunno].dunlook_from = from;
		dun[dunno].dunlook_to = to;
	}

	di_int get_dungeon_xy(int dunno)
	{
		if (!exists(dunno)){ return di_int(20,20);}
		return di_int(
				ddtmath::biggest_int_of(dun[dunno].tile_dim_x, 20),
				ddtmath::biggest_int_of(dun[dunno].tile_dim_y, 20));
	}
	void set_dungeon_xy(int dunno, int x, int y)
	{
		if (!exists(dunno)){return;}
		dun[dunno].tile_dim_x = x;
		dun[dunno].tile_dim_y = y;
	}
	int get_prime_sec(int dunno)
	{
		if (!exists(dunno)){ return -1;}
		return dun[dunno].sector_prime;
	}
	void set_prime_sec(int dunno, int in)
	{
		if (!exists(dunno)){return;}
		dun[dunno].sector_prime = in;
	}

	string get_loadbg(int dunno)
	{
		if (!exists(dunno)){return " ";}
		return dun[dunno].loadbg;
	}
	void set_loadbg(int dunno, string in)
	{
		if (!exists(dunno)){return;}
		dun[dunno].loadbg = in;
	}

	string get_game(int dunno)
	{
		if (!exists(dunno)){return " ";}
		return dun[dunno].name;
	}

	void set_name(int dunno, string in)
	{
		if (!exists(dunno)){return;}
		dun[dunno].name = in;
	}

	string get_sector_source(int dunno)
	{
		if (!exists(dunno)){return " ";}
		return dun[dunno].sector_source;
	}
	void set_sector_source(int dunno, string in)
	{
		if (!exists(dunno)){return;}
		dun[dunno].sector_source = in;
	}

	string get_first_load_extra(int dunno)
	{
		if (!exists(dunno)){return " ";}
		return dun[dunno].on_first_load_extra;
	}
	void set_first_load_extra(int dunno, string in)
	{
		if (!exists(dunno)){return;}
		dun[dunno].on_first_load_extra = in;
	}

	bool has_first_load_extra(int dunno)
	{
		if (!exists(dunno)){return false;}
		if (dun[dunno].on_first_load_extra == ""){return false;}
		return true;
	}


};



class value_map
{
	public:
	int size;
	int16_t* value;
};

class value_map_keeper
{
	private:
	value_map map[VALUE_MAP_COUNT];

	public:

	bool exists(int mapno)
	{
		if (mapno < 0 || mapno > VALUE_MAP_COUNT -1) {return false;}
		return true;
	}

	bool exists(int mapno, int valueno)
	{
		if (!exists(mapno)) {return false;}
		if (valueno < 0) {return false;}
		if (valueno > map[mapno].size -1) {return false;}
		return true;
	}

	int size(int mapno)
	{
		if (!exists(mapno)) {return 0;}
		return map[mapno].size;
	}

	void set_size(int mapno, int size)
	{
		if (!exists(mapno)) {return;}
		delete_map(mapno);

		if (size < 1) {return;}

		map[mapno].value = new int16_t[size];
		map[mapno].size = size;

		for(int i = 0; i < size; i++)
		{
			map[mapno].value[i] = 0;
		}
	}

	void set_value(int mapno, int valueno, int16_t val)
	{
		if (!exists(mapno, valueno)) {return;}
		map[mapno].value[valueno] = val;
	}

	int16_t get_value(int mapno, int valueno)
	{
		if (!exists(mapno, valueno)) {return 0;}
		return map[mapno].value[valueno];
	}

	void delete_map(int mapno)
	{
		if (!exists(mapno)) {return;}
		if (map[mapno].size < 1) {return;}

		delete[] map[mapno].value;
		map[mapno].size = 0;
	}
};


class item_type
{
	public:

	string name;

	int on_ground_tex; //in pak 0
	int flip_sfx; //in pak 0
	bool stackable; // as in cash or arrows
	int stack_limit;


	item_type()
	{
		name = "";
		on_ground_tex = VOID_TEXTURE;
		flip_sfx = VOID_SOUND;
		stackable = false;
		stack_limit = 1;
	}

};


class item_type_keeper
{
public:

	item_type type[ITEM_TYPE_COUNT];


	bool exists(int tp)
	{
		if ( tp < 0) {return false;}
		if ( tp > ITEM_TYPE_COUNT -1) {return false;}
		return true;
	}

	int give_flip_sfx(int tp)
	{
		if (!exists(tp)) {return VOID_SOUND;}
		return type[tp].flip_sfx;

	}

};



class mechanic_ref
{
	public:
	threadsave_string name;
	threadsave_string loadref;
	int16_t pakref_vid;
	int16_t pakref_aud;



	bool is_loaded;

	// ONLY TO BE SET AT GAME START
	unsigned char* loadme;
	int loadme_size;

	bool clean_own_vid_pak;
	bool clean_own_aud_pak;

	int16_t open_grfx_gr;
	int16_t open_grfx_sub;
	int16_t closed_grfx_gr;
	int16_t closed_grfx_sub;

	int16_t other_mech_ref; //this mechanic references another mechanic
	int16_t dungeon_ref; //this mechanic references a dungeon

	int16_t selection_height;

	int16_t interaction_ref;

	bool is_savable;

	mechanic_ref()
	{
		pakref_vid = -1;
		pakref_aud = -1;
		is_loaded = false;
		loadme_size = 0;

		clean_own_vid_pak = true;
		clean_own_aud_pak = true;
		is_savable = false;


		open_grfx_gr = VOID_TEXTURE;
		open_grfx_sub = VOID_TEXTURE;
		closed_grfx_gr = VOID_TEXTURE;
		closed_grfx_sub = VOID_TEXTURE;
		other_mech_ref = -1;
		dungeon_ref = -1;
		selection_height = 0;
		interaction_ref = MECHANIC_INTERACTION_REF_VOID;
	}

};



class mechanic_ref_keeper
{
	public:

	mechanic_ref mech[TILE_MECH_COUNT];

	bool exists(int16_t mn)
	{
		if ( mn < 0) {return false;}
		if ( mn > TILE_MECH_COUNT -1) {return false;}
		return true;
	}

	bool selectable(int16_t mn)
	{
		if (!exists(mn)){return false;}
		if ( mech[mn].selection_height < 1){return false;}
		return true;
	}

	bool savable(int16_t mn)
	{
		if (!exists(mn)){return false;}
		return mech[mn].is_savable;
	}


	int get_loadme_size(int mechno)
	{
		if (!exists(mechno)) {return 0;}
		return mech[mechno].loadme_size;
	}

	unsigned char* get_loadme_rules(int mechno)
	{
		int out_size = get_loadme_size(mechno);
		if (out_size < 1) {return NULL;}

		unsigned char* out = new unsigned char[out_size];
		for (int i = 0; i < out_size; i++)
		{
			out[i] = mech[mechno].loadme[i];
		}

		return out;
	}


	string get_loadref(int mechno)
	{
		if (!exists(mechno))
		{
			cout << "DDT> mechanic_ref_keeper illegal get_loadref requested" << endl;
			return " ";
		}
		else
		{
			return mech[mechno].loadref.get();
		}
	}

};


class sectorfix_keeper
{
	private:

	int_ucharp fix[SECTORFIX_COUNT];

	public:

	bool exists(int fixno)
	{
		if (fixno < 0 || fixno > SECTORFIX_COUNT - 1) {return false;}
		return true;
	}

	bool has_size(int fixno)
	{
		if (!exists(fixno)) {return false;}
		if (fix[fixno].i < 1) {return false;}
		return true;
	}

	int get_size(int fixno)
	{
		if (!has_size(fixno)) {return 0;}
		return fix[fixno].i;
	}

	unsigned char* get_fix(int fixno)
	{
		if (!has_size(fixno)) {return NULL;}

		return fix[fixno].c;
	}


	void set(int fixno, unsigned char* fix_c , int fix_size)
	{
		if (!exists(fixno) || fix_size < 1)
		{
			cout << "DDT> illegal sectorfix set" << endl;
			return;
		}

		if ( has_size(fixno) )
		{
			delete[] fix[fixno].c;
		}

		fix[fixno].c = fix_c;
		fix[fixno].i = fix_size;
	}

};





class global_binblob
{
	private:
	unsigned char* blobby;
	int blobby_size;
	bool checked;

	public:

	global_binblob()
	{
		blobby_size = 0;
		checked = false;
	}

	void set(unsigned char* blob, int blob_size)
	{
		blobby = blob;
		blobby_size = blob_size;

		checked = ddtblob::check(blobby, blobby_size);
		cout << "DDT> Binary string source loaded" << endl;

	}

	string get_game_name(int name)
	{
		if (!checked) {return "Data not loaded";}
		return ddtblob::get_game_name(name, blobby, blobby_size);
	}

	string get_notice()
	{
		if (!checked) {return "Data not loaded";}
		return ddtblob::get_greeting(blobby, blobby_size);
	}

	string get_class_name(int name)
	{
		if (!checked) {return "Data not loaded";}
		return ddtblob::get_class_name(name, blobby, blobby_size);
	}

	string get_monster_name(int name)
	{
		if (!checked) {return "Data not loaded";}
		return ddtblob::get_monster_name(name, blobby, blobby_size);
	}

	string get_dungeon_name(int name)
	{
		if (!checked) {return "Data not loaded";}
		return ddtblob::get_dungeon_name(name, blobby, blobby_size);
	}

	string get_mech_name(int name)
	{
		if (!checked) {return "Data not loaded";}
		return ddtblob::get_mech_name(name, blobby, blobby_size);
	}

	string get_story(int no)
	{
		if (!checked) {return "Data not loaded";}
		return ddtblob::get_story(no, blobby, blobby_size);
	}





};



class global_player
{
	public:

	volatile double player_at_x_doub; //where is the player in the tilegrid
	volatile double player_at_y_doub;
	volatile int player_at_x_int; //where is the player in the tilegrid
	volatile int player_at_y_int;

	//stuff the ui thread passes for a load
	threadsave_string char_name;
	threadsave_string char_class;
	long_threadsave_string char_class_path;
	int class_number;

	bool show_map;
	float map_move_x_pix;
	float map_move_y_pix;
	int map_move_x_percent;
	int map_move_y_percent;


	bool sector_fix[SECTORFIX_COUNT];


	global_player()
	{
		player_at_x_doub = 0;
		player_at_y_doub = 0;
		player_at_x_int = 0;
		player_at_y_int = 0;

		class_number = 0;

		show_map = false;
		map_move_x_pix = 0;
		map_move_y_pix = 0;
		map_move_x_percent = 0;
		map_move_y_percent = 0;

		for (int i = 0; i < SECTORFIX_COUNT; i++)
		{
			sector_fix[i] = false;
		}
	}


	void set_sector_fix(bool value, int fixno)
	{
		if (fixno < 0 || fixno > SECTORFIX_COUNT - 1) {return;}
		sector_fix[fixno] = value;
	}

	bool get_sector_fix(int fixno)
	{
		if (fixno < 0 || fixno > SECTORFIX_COUNT - 1) {return false;}
		return sector_fix[fixno];
	}




};


