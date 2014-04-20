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
//#include "stdafx.h"
#define B BINARY_LITERAL


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <stdint.h>

using namespace std;



template<bool> struct BinaryLiteralDigit;

template<> struct BinaryLiteralDigit<true> {
	static bool const value = true;
};

template<unsigned long long int OCT, unsigned long long int HEX>
struct BinaryLiteral {
	enum {
		value = (BinaryLiteralDigit<(OCT % 8 < 2)>::value && BinaryLiteralDigit<(HEX >= 0)>::value
		? (OCT % 8) + (BinaryLiteral<OCT / 8, 0>::value << 1)
		: -1)
	};
};

template<>
struct BinaryLiteral<0, 0> {
	enum {
		value = 0
	};
};

#define BINARY_LITERAL(n) BinaryLiteral<0##n##LU, 0x##n##LU>::value





class ddtsavegame
{

	public:



	static int static_size()
	{
		return 0xb00;
	}

	static int spell_slot_count()
	{
		return 35;
	}

	static int spell_slot_offset()
	{
		return 0x010;
	}



	static int inventory_columns()
	{
		return 10;
	}

	static int inventory_rows()
	{
		return 4;
	}

	static int belt_size()
	{
		return 8;
	}

	static int8_t monster_id()
	{
		return 0x1;
	}

	static int monster_size()
	{
		return 0x10;
	}

	static int item_size()
	{
		return 0x20;
	}

	static int8_t item_id()
	{
		return 0x2;
	}

	static int mech_size()
	{
		return 0x10;
	}

	static int8_t mech_id()
	{
		return 0x4;
	}


	static int8_t mapexplore_id()
	{
		return 0x3;
	}





	static int offset_inventory(int col, int row)
	{
		int offset = 0x200;
		offset = offset + item_size()*inventory_columns()*row;
		offset = offset + item_size()*col;

		return offset;
	}

	static int offset_belt(int slot)
	{
		int offset = 0x700;
		offset = offset +  item_size()*slot;
		return offset;
	}

	static int random_block_size()
	{
		return 0x100;
	}

	static int first_level_info_offset()
	{
		return 0x980;
	}




	//file defines
	//------------

	static void set_file_header(unsigned char* save, int save_size)
	{
		if (save_size < static_size())
		{
			size_warning(); return;
		}

		save[0x000] = 'd';
		save[0x001] = 'd';
		save[0x002] = 't';
		save[0x003] = 's';
		save[0x004] = 'a';
		save[0x005] = 'v';
		save[0x006] = 'e';
		save[0x007] = ' ';
	}

	static bool has_file_header(unsigned char* save, int save_size)
	{
		if (save_size < static_size()) { size_warning(); return false; }

		if (	save[0x000] == 'd' &&
		        save[0x001] == 'd' &&
		        save[0x002] == 't' &&
		        save[0x003] == 's' &&
		        save[0x004] == 'a' &&
		        save[0x005] == 'v' &&
		        save[0x006] == 'e' &&
		        save[0x007] == ' ' )
		{
			return true;
		}

		return false;
	}


	//game independant char characteristics
	//-------------------------------------

	static void set_expantion_mode(int mode, unsigned char* save, int save_size)
	{
		set_8bit_value_at(mode, 0x008, save, save_size);
	}

	static int get_expantion_mode(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x008, save, save_size);
	}

	static void set_char_class(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x009, save, save_size);
	}

	static int get_char_class(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x009, save, save_size);
	}

	static void set_stars(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x00a, save, save_size);
	}

	static int get_stars(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x00a, save, save_size);
	}

	static void set_level(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x00b, save, save_size);
	}

	static int get_level(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x00b, save, save_size);
	}


	static void set_xp(uint32_t value, unsigned char* save, int save_size)
	{
		set_32bit_value_at(value, 0x00c, save, save_size);
	}

	static uint32_t get_xp(unsigned char* save, int save_size)
	{
		return get_32bit_value_at(0x00c, save, save_size);
	}

	static void set_spell_level(int slot, int value, unsigned char* save, int save_size)
	{

		if (slot <  0 || slot > spell_slot_count() -1) { slot_warning(); return; }
		set_8bit_value_at(value, spell_slot_offset() + slot, save, save_size);

	}

	static int get_spell_level(int slot, unsigned char* save, int save_size)
	{

		if (slot <  0 || slot > spell_slot_count() -1) { slot_warning(); return 0; }
		return get_8bit_value_at(spell_slot_offset() + slot, save, save_size);
	}


	static void set_map_active(bool value, unsigned char* save, int save_size)
	{
		set_bool_at(value, 0x038, save, save_size);
	}

	static bool get_map_active(unsigned char* save, int save_size)
	{
		return get_bool_at(0x038, save, save_size);
	}

	static void set_map_move(int x, int y, unsigned char* save, int save_size)
	{
		set_signed_8bit_value_at(x, 0x039, save, save_size);
		set_signed_8bit_value_at(y, 0x03a, save, save_size);
	}

	static int get_map_move_x(unsigned char* save, int save_size)
	{
		return get_signed_8bit_value_at(0x039, save, save_size);
	}

	static int get_map_move_y(unsigned char* save, int save_size)
	{
		return get_signed_8bit_value_at(0x03a, save, save_size);
	}


	static void set_undistributed(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x03b, save, save_size);
	}

	static int get_undistributed(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x03b, save, save_size);
	}

	static void set_str(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x03c, save, save_size);
	}

	static int get_str(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x03c, save, save_size);
	}

	static void set_mag(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x03d, save, save_size);
	}

	static int get_mag(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x03d, save, save_size);
	}

	static void set_dex(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x03e, save, save_size);
	}

	static int get_dex(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x03e, save, save_size);
	}

	static void set_vit(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x03f, save, save_size);
	}

	static int get_vit(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x03f, save, save_size);;
	}

	//items on char
	//-------------

	static void set_item_mouse(unsigned char* item, unsigned char* save, int save_size)
	{
		set_item_at(0x040, item, save, save_size);
	}

	static unsigned char* get_item_mouse(unsigned char* save, int save_size)
	{
		return get_item_at(0x040, save, save_size);
	}

	static void set_item_head(unsigned char* item, unsigned char* save, int save_size)
	{
		set_item_at(0x060, item, save, save_size);
	}

	static unsigned char* get_item_head(unsigned char* save, int save_size)
	{
		return get_item_at(0x060, save, save_size);
	}

	static void set_item_neck(unsigned char* item, unsigned char* save, int save_size)
	{
		set_item_at(0x080, item, save, save_size);
	}

	static unsigned char* get_item_neck(unsigned char* save, int save_size)
	{
		return get_item_at(0x080, save, save_size);
	}

	static void set_item_chest(unsigned char* item, unsigned char* save, int save_size)
	{
		set_item_at(0x0a0, item, save, save_size);
	}

	static unsigned char* get_item_chest(unsigned char* save, int save_size)
	{
		return get_item_at(0x0a0, save, save_size);
	}

	static void set_item_finger_left(unsigned char* item, unsigned char* save, int save_size)
	{
		set_item_at(0x0c0, item, save, save_size);
	}

	static unsigned char* get_item_finger_left(unsigned char* save, int save_size)
	{
		return get_item_at(0x0c0, save, save_size);
	}

	static void set_item_finger_right(unsigned char* item, unsigned char* save, int save_size)
	{
		set_item_at(0x0e0, item, save, save_size);
	}

	static unsigned char* get_item_finger_right(unsigned char* save, int save_size)
	{
		return get_item_at(0x0e0, save, save_size);
	}

	static void set_item_hands_left(bool swich, unsigned char* item, unsigned char* save, int save_size)
	{
		if (swich) { set_item_at(0x140, item, save, save_size);}
		set_item_at(0x100, item, save, save_size);
	}

	static unsigned char* get_item_hands_left(bool swich, unsigned char* save, int save_size)
	{
		if (swich) { return get_item_at(0x140, save, save_size);}
		return get_item_at(0x100, save, save_size);
	}

	static void set_item_hands_right(bool swich, unsigned char* item, unsigned char* save, int save_size)
	{
		if (swich) { set_item_at(0x160, item, save, save_size);}
		set_item_at(0x120, item, save, save_size);
	}

	static unsigned char* get_item_hands_right(bool swich, unsigned char* save, int save_size)
	{
		if (swich) { return get_item_at(0x160, save, save_size);}
		return get_item_at(0x120, save, save_size);
	}


	static void set_item_inventory(int col, int row, unsigned char* item, unsigned char* save, int save_size)
	{
		if ( col < 0 || col > inventory_columns() -1) {slot_warning(); return;}
		if ( row < 0 || row > inventory_rows()    -1) {slot_warning(); return;}

		int offset = offset_inventory(col, row);
		set_item_at(offset, item, save, save_size);

	}

	static unsigned char* get_item_inventory(int col, int row, unsigned char* save, int save_size)
	{
		if ( col < 0 || col > inventory_columns() -1) {slot_warning(); return new unsigned char[item_size()];}
		if ( row < 0 || row > inventory_rows()    -1) {slot_warning(); return new unsigned char[item_size()];}

		int offset =  offset_inventory(col, row);
		return  get_item_at(offset, save, save_size);
	}

	static void set_item_belt(int slot, unsigned char* item, unsigned char* save, int save_size)
	{
		if ( slot < 0 || slot > belt_size() -1) {slot_warning(); return;}

		int offset = offset_belt(slot);
		set_item_at(offset, item, save, save_size);

	}

	static unsigned char* get_item_belt(int slot, unsigned char* save, int save_size)
	{
		if ( slot < 0 || slot > belt_size() -1) {slot_warning(); return new unsigned char[item_size()];}

		int offset =  offset_belt(slot);
		return  get_item_at(offset, save, save_size);
	}


	//game specific characteristics
	//-----------------------------

	static void set_diff(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x800, save, save_size);
	}

	static int get_diff(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x800, save, save_size);
	}

	static void set_active_dungeon(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x801, save, save_size);
	}

	static int get_active_dungeon(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x801, save, save_size);
	}

	static void set_facing_direction(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x802, save, save_size);
	}

	static int get_facing_direction(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x802, save, save_size);
	}

	static void set_char_tile_location(uint16_t x, uint16_t y, unsigned char* save, int save_size)
	{
		set_16bit_value_at(x, 0x803, save, save_size);
		set_16bit_value_at(y, 0x805, save, save_size);
	}

	static uint16_t get_char_tile_location_x(unsigned char* save, int save_size)
	{
		return get_16bit_value_at(0x803, save, save_size);
	}

	static uint16_t get_char_tile_location_y(unsigned char* save, int save_size)
	{
		return get_16bit_value_at(0x805, save, save_size);
	}

	static void set_hp(uint16_t value, unsigned char* save, int save_size)
	{
		set_16bit_value_at(value, 0x807, save, save_size);
	}

	static uint16_t get_hp(unsigned char* save, int save_size)
	{
		return get_16bit_value_at(0x807, save, save_size);
	}

	static void set_mana(uint16_t value, unsigned char* save, int save_size)
	{
		set_16bit_value_at(value, 0x809, save, save_size);
	}

	static uint16_t get_mana(unsigned char* save, int save_size)
	{
		return get_16bit_value_at(0x809, save, save_size);
	}

	static void set_buff(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x80b, save, save_size);
	}

	static int get_buff(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x80b, save, save_size);
	}

	static void set_swich(bool value, unsigned char* save, int save_size)
	{
		set_bool_at(value, 0x80f, save, save_size);
	}

	static bool get_swich(unsigned char* save, int save_size)
	{
		return get_bool_at(0x80f, save, save_size);
	}


	//sector fixes
	//---------------

	static void set_sector_fix(bool value, int fixno, unsigned char* save, int save_size)
	{
		set_bit_at_arr(value, fixno, save, save_size, 0x810);
	}

	static bool get_sector_fix(int fixno, unsigned char* save, int save_size)
	{
		return get_bit_at_arr(fixno, save, save_size, 0x810);
	}



	//open townportal
	//---------------

	static void set_townportal_active_level(int value, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, 0x87b, save, save_size);
	}

	static int get_townportal_active_level(unsigned char* save, int save_size)
	{
		return get_8bit_value_at(0x87b, save, save_size);
	}

	static void set_townportal_tile_location(uint16_t x, uint16_t y , unsigned char* save, int save_size)
	{
		set_16bit_value_at(x, 0x87c, save, save_size);
		set_16bit_value_at(y, 0x87e, save, save_size);
	}

	static uint16_t get_townportal_tile_location_x(unsigned char* save, int save_size)
	{
		return get_16bit_value_at(0x87c, save, save_size);
	}

	static uint16_t get_townportal_tile_location_y(unsigned char* save, int save_size)
	{
		return get_16bit_value_at(0x87e, save, save_size);
	}

	//random seed block
	//-----------------


	static void set_random_block(uint8_t value, int offset, unsigned char* save, int save_size)
	{
		set_8bit_value_at(value, offset+ 0x880, save, save_size);
	}

	static uint8_t get_random_block(int32_t member_byte,  unsigned char* save, int save_size)
	{
		int mod;

		if (member_byte < 0)
		{
			member_byte = -1 *member_byte;
			mod = member_byte - (member_byte/ random_block_size())*random_block_size();
			mod = random_block_size() - mod -1;
		}
		else
		{
			mod = member_byte - (member_byte/ random_block_size())*random_block_size();
		}

		return get_8bit_value_at(0x880 + mod, save, save_size);
	}

	//static int roll_randon_block(int32_t member_byte, int min_value, int max_value, unsigned char* save, int save_size)
	//{
		//if (max_value < min_value) {return min_value;}
		//if (min_value == max_value) {return min_value;}

		//int choise = max_value - min_value + 1;
		//uint32_t rnd = get_random_block(member_byte,  save, save_size);
		//int result = rnd - (rnd/choise)*choice;

		//return result + min_value;
	//}


	//offsets for variable length level blocks
	//---------------------------------------


	static void set_level_info_offset(uint32_t value, int level, unsigned char* save, int save_size)
	{
		int offset = first_level_info_offset() + 4*level;

		set_32bit_value_at(value, offset, save, save_size);
	}

	static uint32_t get_level_info_offset(int level, unsigned char* save, int save_size)
	{
		int offset = first_level_info_offset() + 4*level;

		return get_32bit_value_at(offset, save, save_size);
	}
	static uint32_t get_level_info_offset_end(int level, unsigned char* save, int save_size)
	{
		int offset = first_level_info_offset() + 4*(level+1);

		return get_32bit_value_at(offset, save, save_size);
	}
	static uint32_t get_level_info_size(int level, unsigned char* save, int save_size)
	{
		int out = get_level_info_offset_end(level, save, save_size);
		out = out - get_level_info_offset(level, save, save_size);

		return out;
	}



	//variable length members
	//---------------------------------------

	static void set_savegame_variable_length_member_id(uint8_t value, int member_memoff, unsigned char* file, int file_size)
	{
		set_8bit_value_at(value, member_memoff, file, file_size);

	}

	static int8_t get_savegame_variable_length_member_id(int member_memoff, unsigned char* file, int file_size)
	{
		return get_8bit_value_at(member_memoff, file, file_size);
	}

	//variable length member: monster
	//---------------------------------------


	static void set_savegame_monster_id(int monster_memoff, unsigned char* save, int save_size)
	{
		set_8bit_value_at(monster_id(), monster_memoff, save, save_size);
	}

	static bool has_savegame_monster_id(int monster_memoff, unsigned char* save, int save_size)
	{
		int id =  get_8bit_value_at(monster_memoff, save, save_size);
		if (id == monster_id()) {return true;}
		return false;
	}


	static void set_savegame_monster_tile_location(uint16_t x, uint16_t y, int monster_memoff, unsigned char* file, int file_size)
	{
		set_16bit_value_at(x, monster_memoff+1, file, file_size);
		set_16bit_value_at(y, monster_memoff+3, file, file_size);
	}

	static int16_t get_savegame_monster_tile_location_x(int monster_memoff, unsigned char* file, int file_size)
	{
		return get_16bit_value_at(monster_memoff+1, file, file_size);
	}

	static int16_t get_savegame_monster_tile_location_y(int monster_memoff, unsigned char* file, int file_size)
	{
		return get_16bit_value_at(monster_memoff+3, file, file_size);
	}

	static void set_savegame_monster_type(uint16_t value, int monster_memoff, unsigned char* file, int file_size)
	{
		set_16bit_value_at(value, monster_memoff+5, file, file_size);
	}

	static int16_t get_savegame_monster_type(int monster_memoff, unsigned char* file, int file_size)
	{
		return get_16bit_value_at(monster_memoff+5, file, file_size);
	}

	static void set_savegame_monster_level(int value, int monster_memoff, unsigned char* file, int file_size)
	{

		set_16bit_value_at(value, monster_memoff+7, file, file_size);
	}

	static int16_t get_savegame_monster_level(int monster_memoff, unsigned char* file, int file_size)
	{
		return get_16bit_value_at(monster_memoff+7, file, file_size);
	}

	static void set_savegame_monster_facing(int value, int monster_memoff, unsigned char* file, int file_size)
	{

		set_8bit_value_at(value, monster_memoff+8, file, file_size);
	}

	static int16_t get_savegame_monster_facing(int monster_memoff, unsigned char* file, int file_size)
	{
		return get_8bit_value_at(monster_memoff+8, file, file_size);
	}

	static void set_savegame_monster_hp_left(int value, int monster_memoff, unsigned char* file, int file_size)
	{

		set_16bit_value_at(value, monster_memoff+9, file, file_size);
	}

	static int16_t get_savegame_monster_hp_left(int monster_memoff, unsigned char* file, int file_size)
	{
		return get_16bit_value_at(monster_memoff+9, file, file_size);
	}


	//variable length member: mechanic
	//---------------------------------------


	static void set_savegame_mech_id(int mech_memoff, unsigned char* save, int save_size)
	{
		set_8bit_value_at(mech_id(), mech_memoff, save, save_size);
	}

	static bool has_savegame_mech_id(int mech_memoff, unsigned char* save, int save_size)
	{
		int id =  get_8bit_value_at(mech_memoff, save, save_size);
		if (id == mech_id()) {return true;}
		return false;
	}

	static void set_savegame_mech_tile_location(uint16_t x, uint16_t y, int mech_memoff, unsigned char* file, int file_size)
	{
		set_16bit_value_at(x, mech_memoff+1, file, file_size);
		set_16bit_value_at(y, mech_memoff+3, file, file_size);
	}

	static int16_t get_savegame_mech_tile_location_x(int mech_memoff, unsigned char* file, int file_size)
	{
		return get_16bit_value_at(mech_memoff+1, file, file_size);
	}

	static int16_t get_savegame_mech_tile_location_y(int mech_memoff, unsigned char* file, int file_size)
	{
		return get_16bit_value_at(mech_memoff+3, file, file_size);
	}

	static void set_savegame_mech_type(uint16_t value, int mech_memoff, unsigned char* file, int file_size)
	{
		set_16bit_value_at(value, mech_memoff+5, file, file_size);
	}

	static int16_t get_savegame_mech_type(int mech_memoff, unsigned char* file, int file_size)
	{
		return get_16bit_value_at(mech_memoff+5, file, file_size);
	}

	static void set_savegame_mech_on(bool value, int mech_memoff, unsigned char* save, int save_size)
	{
		set_bool_at(value, mech_memoff+7, save, save_size);
	}

	static bool get_savegame_mech_on(int mech_memoff, unsigned char* save, int save_size)
	{
		return get_bool_at(mech_memoff+7, save, save_size);
	}




	//variable length member: map
	//---------------------------------------



	static int mapexplore_get_size_for_tiles(int x, int y)
	{
		if (x < 1 || y < 1) {return 1;}

		return (x*y)/8 + 6;

		//(x*y)/8 + 1 for tile info
		//1 for mapexplore_id
		//4 for size info
	}

	static void set_mapexplore_id(int map_memoff, unsigned char* save, int save_size)
	{
		set_8bit_value_at(mapexplore_id(), map_memoff, save, save_size);
	}

	static bool has_mapexplore_id(int map_memoff, unsigned char* save, int save_size)
	{
		int id =  get_8bit_value_at(map_memoff, save, save_size);
		if (id == mapexplore_id()) {return true;}
		return false;
	}

	static void set_mapexplore_size(int value, int map_memoff, unsigned char* save, int save_size)
	{
		set_32bit_value_at(value, map_memoff+ 0x001, save, save_size);
	}

	static int get_mapexplore_size(int map_memoff, unsigned char* save, int save_size)
	{
		return get_32bit_value_at(map_memoff+0x001, save, save_size);
	}

	static void add_mapexplore_tile(bool discovered, int tileno, int map_memoff, unsigned char* save, int save_size)
	{
		set_bit_at_arr(discovered, tileno, save, save_size, map_memoff + 0x005);
	}

	static bool get_mapexplore_tile(int tileno, int map_memoff, unsigned char* save, int save_size)
	{
		return get_bit_at_arr(tileno, save, save_size, map_memoff + 0x005);
	}
















	static void set_item_at(int offset, unsigned char* item, unsigned char* save, int save_size)
	{
		if (offset < 0 || offset > save_size - item_size() -1) {slot_warning(); return; }

		for (int i = 0; i < item_size(); i++)
		{
			save[offset+i] = item[i];
		}
	}

	static unsigned char* get_item_at(int offset, unsigned char* save, int save_size)
	{
		unsigned char* item = new unsigned char[item_size()];

		if (offset < 0 || offset > save_size - item_size() -1) {slot_warning(); return item; }

		for (int i = 0; i < item_size(); i++)
		{
			item[i] = save[offset+i];
		}

		return item;

	}



	static void set_32bit_value_at(uint32_t value, int offset, unsigned char* save, int save_size)
	{
		if (offset < 0 || offset > save_size - 4) {slot_warning(); return; }

		uint32_t highest = (value                                                      ) / 0x1000000 ;
		uint32_t high    = (value - (highest*0x1000000)                                ) /   0x10000 ;
		uint32_t low     = (value - (highest*0x1000000) - (high*0x10000)               ) /     0x100;
		uint32_t lowest  = (value - (highest*0x1000000) - (high*0x10000) - (low*0x100) ) /       0x1;

		save[offset + 0] = (unsigned char)lowest;
		save[offset + 1] = (unsigned char)low;
		save[offset + 2] = (unsigned char)high;
		save[offset + 3] = (unsigned char)highest;

	}



	static uint32_t get_32bit_value_at(int offset, unsigned char* save, int save_size)
	{
		if (offset < 0 || offset > save_size - 4) {slot_warning(); return 0; }

		uint32_t lowest  = (uint32_t)save[offset + 0];
		uint32_t low     = (uint32_t)save[offset + 1];
		uint32_t high    = (uint32_t)save[offset + 2];
		uint32_t highest = (uint32_t)save[offset + 3];

		return (highest*0x1000000) + (high*0x10000) + (low*0x100) + lowest;
	}

	static void set_16bit_value_at(uint16_t value, int offset, unsigned char* save, int save_size)
	{
		if (offset < 0 || offset > save_size - 2) {slot_warning(); return; }

		uint16_t high = (value                ) / 0x100 ;
		uint16_t low  = (value - (high*0x100) ) / 0x1;

		save[offset + 0] = (unsigned char)low;
		save[offset + 1] = (unsigned char)high;
	}

	static uint16_t get_16bit_value_at(int offset, unsigned char* save, int save_size)
	{
		if (offset < 0 || offset > save_size - 2) {slot_warning(); return 0; }

		uint16_t low    = (uint16_t)save[offset + 0];
		uint16_t high   = (uint16_t)save[offset + 1];

		return + (high*0x100) + low;
	}

	static void set_8bit_value_at(uint8_t value, int offset, unsigned char* save, int save_size)
	{
		if (offset < 0 || offset > save_size - 1) {slot_warning(); return; }
		save[offset] = (unsigned char)value;
	}


	static uint8_t get_8bit_value_at(int offset, unsigned char* save, int save_size)
	{
		if (offset < 0 || offset > save_size - 1) {slot_warning(); return 0; }
		return (unsigned char)save[offset];
	}


	static uint8_t set_bit_at(bool value, uint8_t slot, int slot_pos)
	{
		if (slot_pos < 0 || slot_pos > 7) {return slot;}

		uint8_t mask;

		switch(slot_pos)
		{
			case 0: if (value){ mask = B(10000000); } else{ mask = B(01111111); } break;
			case 1: if (value){ mask = B(01000000); } else{ mask = B(10111111); } break;
			case 2: if (value){ mask = B(00100000); } else{ mask = B(11011111); } break;
			case 3: if (value){ mask = B(00010000); } else{ mask = B(11101111); } break;
			case 4: if (value){ mask = B(00001000); } else{ mask = B(11110111); } break;
			case 5: if (value){ mask = B(00000100); } else{ mask = B(11111011); } break;
			case 6: if (value){ mask = B(00000010); } else{ mask = B(11111101); } break;
			case 7: if (value){ mask = B(00000001); } else{ mask = B(11111110); } break;
		}

		if (value)
		{
			slot = slot | mask;
		}
		else
		{
			slot = slot & mask;
		}

		return slot;
	}

	static bool get_bit_at(uint8_t slot, int slot_pos)
	{
		if (slot_pos < 0 || slot_pos > 7) {return false;}
		uint8_t mask;

		switch(slot_pos)
		{
			case 0: mask = B(10000000); break;
			case 1: mask = B(01000000); break;
			case 2: mask = B(00100000); break;
			case 3: mask = B(00010000); break;
			case 4: mask = B(00001000); break;
			case 5: mask = B(00000100); break;
			case 6: mask = B(00000010); break;
			case 7: mask = B(00000001); break;
		}

		mask = mask & slot;

		if (mask > 0) {return true;}
		return false;
	}

	static void set_bit_at_arr(bool value, int bit_no, unsigned char* arr, int arr_size, int arr_memoff)
	{
		int byte_pointer = bit_no/8;
		int bit_pointer = bit_no - byte_pointer*8;

		if (byte_pointer < 0) { return;}
		if (arr_size -1 < byte_pointer) { return;}

		arr[arr_memoff+byte_pointer] = set_bit_at(value, arr[arr_memoff+byte_pointer], bit_pointer);

	}

	static bool get_bit_at_arr(int bit_no, unsigned char* arr, int arr_size, int arr_memoff)
	{
		int byte_pointer = bit_no/8;
		int bit_pointer = bit_no - byte_pointer*8;

		if (byte_pointer < 0) { return false;}
		if (arr_size -1 < byte_pointer) { return false;}

		return get_bit_at(arr[arr_memoff+byte_pointer], bit_pointer);
	}



	static void set_signed_8bit_value_at(int value, int offset, unsigned char* save, int save_size)
	{
		int i_out = value;

		if (i_out >  0x7f) {i_out =  0x7f;}
		if (i_out < -0x7f) {i_out = -0x7f;}

		uint8_t c_out;

		if (i_out > -1) {c_out = i_out;}
		else {c_out =  (0x100 + i_out);}

		set_8bit_value_at(c_out, offset, save, save_size);
	}

	static int get_signed_8bit_value_at(int offset, unsigned char* save, int save_size)
	{
		int v = get_8bit_value_at(offset, save, save_size);

		if (v < 0x7f) { return v; }
		else { return -0x100 + v; }

	}

	static void set_signed_16bit_value_at(int value, int offset, unsigned char* save, int save_size)
	{
		int i_out = value;

		if (i_out >  0x7FFF) {i_out =  0x7FFF;}
		if (i_out < -0x7FFF) {i_out = -0x7FFF;}

		uint16_t c_out;

		if (i_out > -1) {c_out = i_out;}
		else {c_out =  (0x10000 + i_out);}

		set_16bit_value_at(c_out, offset, save, save_size);
	}

	static int get_signed_16bit_value_at(int offset, unsigned char* save, int save_size)
	{
		int v = get_16bit_value_at(offset, save, save_size);

		if (v < 0x7fff) { return v; }
		else { return -0x10000 + v; }

	}

	static void set_bool_at(bool value, int offset, unsigned char* save, int save_size)
	{
		if (offset < 0 || offset > save_size - 1) {slot_warning(); return; }

		if (value) {save[offset] = 1;}
		else {save[offset] = 0;}
	}

	static bool get_bool_at(int offset, unsigned char* save, int save_size)
	{
		if (offset < 0 || offset > save_size - 1) {slot_warning(); return false; }

		if (save[offset] > 0) {return true;}
		return false;
	}


	static void size_warning()
	{
		cout << "DDT> ddtsavegame size too small" << endl;
	}

	static void slot_warning()
	{
		cout << "DDT> ddtsavegame illegal slot" << endl;
	}




};
