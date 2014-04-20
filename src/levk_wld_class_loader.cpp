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




#include "levk_wld_level_loader.cpp"
using namespace std;

class class_loader
{
	public:

	world_local* local;
	utils util;
	mail* post;

	void init(world_local* loc)
	{
		local = loc;
	}


	void read_class_rules(unsigned char* classtxt, int classtxt_size)
	{

		int classtxt_point = -1;

		while (classtxt_point < classtxt_size - 10)
		{
			classtxt_point++;

			if ( !(  classtxt[classtxt_point] == '(') )
			{
				// nothing
			}

			else if (
					classtxt[classtxt_point + 1] == 'c' &&
					classtxt[classtxt_point + 2] == 'l' &&
					classtxt[classtxt_point + 3] == 'a' &&
					classtxt[classtxt_point + 4] == 's' &&
					classtxt[classtxt_point + 5] == 's' &&
					classtxt[classtxt_point + 6] == '_' &&
					classtxt[classtxt_point + 7] == 'n' &&
					classtxt[classtxt_point + 8] == 'o' &&
					classtxt[classtxt_point + 9] == ')' )
			{

				(*local).pclass.class_number = util.get_int_at(classtxt_point +11, classtxt, classtxt_size);

			}

			else if (
					classtxt[classtxt_point + 1] == 's' &&
					classtxt[classtxt_point + 2] == 't' &&
					classtxt[classtxt_point + 3] == 'a' &&
					classtxt[classtxt_point + 4] == 'r' &&
					classtxt[classtxt_point + 5] == 't' &&
					classtxt[classtxt_point + 6] == '_' &&
					classtxt[classtxt_point + 7] == 'm' &&
					classtxt[classtxt_point + 8] == 'a' &&
					classtxt[classtxt_point + 9] == 'x' &&
					classtxt[classtxt_point +10] == ')' )
			{

				(*local).pclass.str_start = util.get_int_at(classtxt_point + 12, classtxt, classtxt_size);
				(*local).pclass.str_max   = util.get_int_at(classtxt_point + 18, classtxt, classtxt_size);

				(*local).pclass.mag_start = util.get_int_at(classtxt_point + 24, classtxt, classtxt_size);
				(*local).pclass.mag_max   = util.get_int_at(classtxt_point + 30, classtxt, classtxt_size);

				(*local).pclass.dex_start = util.get_int_at(classtxt_point + 36, classtxt, classtxt_size);
				(*local).pclass.dex_max   = util.get_int_at(classtxt_point + 42, classtxt, classtxt_size);

				(*local).pclass.vit_start = util.get_int_at(classtxt_point + 48, classtxt, classtxt_size);
				(*local).pclass.vit_max   = util.get_int_at(classtxt_point + 54, classtxt, classtxt_size);


			}

			else if (
					classtxt[classtxt_point + 1] == 's' &&
					classtxt[classtxt_point + 2] == 't' &&
					classtxt[classtxt_point + 3] == 'a' &&
					classtxt[classtxt_point + 4] == 'r' &&
					classtxt[classtxt_point + 5] == 't' &&
					classtxt[classtxt_point + 6] == '_' &&
					classtxt[classtxt_point + 7] == 'i' &&
					classtxt[classtxt_point + 8] == 't' &&
					classtxt[classtxt_point + 9] == 'e' &&
					classtxt[classtxt_point +10] == 'm' &&
					classtxt[classtxt_point +11] == ')' )
			{

				int packed_item_size = ddtsavegame::item_size();

				unsigned char* itm = new unsigned char[packed_item_size];
				int itm_no = util.get_int_at(classtxt_point +13, classtxt, classtxt_size);

				int r_off = classtxt_point + 19;
				for (int i = 0; i < packed_item_size; i++)
				{
					itm[i] = util.get_byte_at_hex(r_off, classtxt, classtxt_size);
					r_off = r_off + 4;
				}


				(*local).pclass.add_start_item(itm_no, itm, packed_item_size);




			}

			else if (
					classtxt[classtxt_point + 1] == 't' &&
					classtxt[classtxt_point + 2] == 'e' &&
					classtxt[classtxt_point + 3] == 'x' &&
					classtxt[classtxt_point + 4] == 'r' &&
					classtxt[classtxt_point + 5] == 'e' &&
					classtxt[classtxt_point + 6] == 'f' &&
					classtxt[classtxt_point + 7] == ')' )
			{

				int cur_texref = util.get_int_at(classtxt_point +9, classtxt, classtxt_size);
				string comb_argu = util.get_argument_at(classtxt_point +15, classtxt, classtxt_size);



				int texref_delta = 0;
				int texref_start = classtxt_point +20;
				int texref_point = texref_start;
				bool texref_end = false;

				while ((!texref_end) && texref_point < classtxt_size - 20 )
				{
					if ( classtxt[texref_point] == '(')
					{
						texref_end = true;
					}
					else
					{
						texref_delta++;
						texref_point++;

					}
				}


				if ( cur_texref < 0 || cur_texref > CLASSTX_COUNT -1)
				{
					cout << "DDT> illegal (texref) number in class rules" << endl;
					return;
				}

				if ( texref_delta < 20)
				{
					cout << "DDT> way to short (texref) delta in class rules " << texref_delta << endl;
					return;
				}


				unsigned char* txrf = new unsigned char[texref_delta];

				for (int i = 0; i < texref_delta; i++)
				{
					txrf[i] = classtxt[texref_start + i];
				}


				if ( comb_argu == "town")
				{
					(*local).pclass.add_texref(cur_texref, false, txrf, texref_delta);
				}
				else if ( comb_argu == "comb")
				{
					(*local).pclass.add_texref(cur_texref, true, txrf, texref_delta);
				}
				else
				{
					cout << "DDT> illegal combat argument in class (texref)" << endl;
				}

			}

		}

		delete[] classtxt;



	}

};
