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




#include "levl_mkb_screens_manager.cpp"
using namespace std;


// this is the class that transforms one cel or cl2 file into textures
// Yes, well written assembly would be a LOT faster. Sue me.
// With any luck we will end up mutithreading this though >;)
class celmaker
{
	private:

	utils util;
	globals* global;

	public:

	void init (globals* glob)
	{
		global = glob;
	}


	//*****double_indexed_bulk*****
	// This handeles a whole cel or cl2 file at once. The file must use an index that points to another index
	// Input:
	// x_size, y_size are the size of the pic as it is supposed to be in the cel file
	// cel is the file with bytesize celsize
	// pal is 768 byte palette file
	// allog defines what decode to use
	// chunkfactor defines how the textures need to be split up in the recursive texchunk class and if the rendering should be liniair or smooth
	// memoff is where we start to read the file
	// x and y move define how much we should shift the texture
	// Output:
	// A whole bunch of texchunks in an array with the array size specified

	int_texchunkp double_indexed_bulk(int x_size, int y_size, unsigned char* cel, int celsize, unsigned char* pal, int allog, int chunkfactor, int x_move, int y_move, int mask)
	{

		if ((x_size < 1) || (y_size < 1) || (celsize < 0x10))
		{
			cout << "DDT> celmaker bulk_load received invalid  input!" << endl;
			return int_texchunkp();
		}

		if ( (int)cel[0] > celsize-1 )
		{
			cout << "DDT> double_indexed bulk received invalid  input!" << endl;
			return int_texchunkp();
		}

		if (allog != DOUBLE_INDEXED_CEL && allog != DOUBLE_INDEXED_CLT)
		{
			cout << "DDT> double_indexed bulk received invalid  allog!" << endl;
			return int_texchunkp();
		}

		// where is the index of the first animation
		int first_direction_offset = (int)cel[0]; // prety much always 0x20

		// how many frames does one animation have
		int frames_per_direction =  (int)cel[first_direction_offset];
		int texcount = frames_per_direction*8 ;


		// now we know how to init our output
		int_texchunkp out(texcount);

		int texno = 0;

		//for every direction
		for (int direction = 0 ; direction < 8; direction ++)
		{
			//for every frame in that direction
			for (int dframe = 0 ; dframe < frames_per_direction; dframe ++)
			{
				if ( 4*direction +2 > celsize-1 )
				{
					cout << "DDT> bad double indexed header" << endl;
					return int_texchunkp();
				}

				//get our direction header
				int direction_header_value = (int)cel[4*direction] + 0x100* (int)cel[4*direction+1] + 0x10000 * (int)cel[4*direction +2];
				int pic_offset_pointer = direction_header_value + (dframe+1)*4;

				if (pic_offset_pointer +2 > celsize-1 )
				{
					cout << "DDT> bad double indexed header" << endl;
					return int_texchunkp();
				}

				//read pic offset pointer
				int pic_adress = (int)cel[pic_offset_pointer] + 0x100* (int)cel[pic_offset_pointer+1] + 0x10000 * (int)cel[pic_offset_pointer +2] + direction_header_value + 10;

				quad_int_ucharp indiv;

				if ((mask > -1) && ((*global).valuemap.get_value(mask,texno) < 1))
				{
					//unneeded texture
					indiv = empty_cel_indiv();
				}
				else if(allog == DOUBLE_INDEXED_CEL)
				{
					indiv = generalp_cel_indiv(x_size, y_size, cel, celsize, pal, pic_adress);
				}
				else //if (allog == DOUBLE_INDEXED_CLT)
				{
					indiv = cltwo_indiv(x_size, y_size, cel, celsize, pal, pic_adress);
				}


				if (DEVELOPER_STAMP) // stamp the texture to keep track of it, for development
				{
					util.stamp_tex(indiv.c, indiv.x, indiv.y, texno);
				}

				int chunki;
				if (chunkfactor ==  CHUNKY_MAXI) {chunki = util.maxi_chunkyness(indiv.x, indiv.y);}
				else {chunki = util.auto_chunkyness(indiv.x, indiv.y);}

				// make a texchunk from our texture
				texchunk tx;
				tx.set(indiv.c, indiv.x, indiv.y, chunki, (chunkfactor == CHUNKY_SMOOTH));
				tx.move_offset(x_move, y_move);
				out.chunk[texno] = tx;
				delete[] indiv.c;

				texno++;
			}
		}
		delete[] cel;
		return out;
	}

	//*****indexed_bulk*****
	// This handeles a whole cel or cl2 file at once. The file must use a flat index
	// Input:
	// x_size, y_size are the size of the pic as it is supposed to be in the cel file
	// cel is the file with bytesize celsize
	// pal is 768 byte palette file
	// allog defines what decode to use
	// chunkfactor defines how the textures need to be split up in the recursive texchunk class and if the rendering should be liniair or smooth
	// memoff is where we start to read the file
	// x and y move define how much we should shift the texture
	// Output:
	// A whole bunch of texchunks in an array with the array size specified

	int_texchunkp indexed_bulk(int x_size, int y_size, unsigned char* cel, int celsize, unsigned char* pal, int allog, int chunkfactor, int x_move, int y_move, int mask)
	{

		if ((x_size < 1) || (y_size < 1) || (celsize < 0x10))
		{

			cout << "DDT> celmaker bulk_load received invalid  input!" << endl;
			return int_texchunkp();
		}

		if (allog != INDEXED_CEL && allog != INDEXED_CLT &&  allog !=  TOWN_CEL && allog != OBJCURS)
		{
			cout << "DDT> double_indexed bulk received invalid  allog!" << endl;
			return int_texchunkp();
		}

		di_int alt_rez(0,0); //special hight/width for OBJCURS

		// Lets get the total amount of textures in the archive
		int texcount = (int)cel[0] + 0x100 * (int)cel[1] + 0x10000 * (int)cel[2];

		// now we know how to init our output
		int_texchunkp out(texcount);

		// repeating for every texture in the cel
		for( int texno = 0; texno < texcount ; texno++)
		{
			//checking if we can read the index
			if ( (4*(texno+1))+5  < celsize )
			{
				// reading index
				int mempoint = (int)cel[(4*(texno+1))] + 0x100 * (int)cel[(4*(texno+1))+1] + 0x10000 * (int)cel[(4*(texno+1))+2];

				// checking if we can read the pic header
				if (mempoint + 12 < celsize)
				{
					quad_int_ucharp indiv;

					if ((mask > -1) && ((*global).valuemap.get_value(mask,texno) < 1))
					{
						//unneeded texture
						indiv = empty_cel_indiv();
					}
					else if(allog == INDEXED_CEL)
					{
						//We are now where the pic header should be, skipping it if its there
						if ( ( (int)cel[mempoint] == 0x0a )  && ( (int)cel[mempoint+1] == 0x00 )  && ( (int)cel[mempoint+8] == 0x00 )  && ( (int)cel[mempoint] == 0x09 ) )
						{
							mempoint = mempoint + 10;
						}

						indiv = generalp_cel_indiv(x_size, y_size, cel, celsize, pal, mempoint);
					}
					else if(allog == OBJCURS)
					{
						// skipping pic header
						mempoint = mempoint + 10;

						// gettin the xy rez values for this pic
						alt_rez = util.objcurs_xy(texno);

						indiv = generalp_cel_indiv(alt_rez.x, alt_rez.y, cel, celsize, pal, mempoint);
					}
					else if(allog == INDEXED_CLT)
					{
						mempoint = mempoint + 10;
						indiv = cltwo_indiv(x_size, y_size, cel, celsize, pal, mempoint);
					}
					else // TOWN_CEL
					{
						//We are now where the pic header should be, skipping it if its there
						if ( ( (int)cel[mempoint] == 0x0a )  && ( (int)cel[mempoint+1] == 0x00 ) && (y_size != 32))
						{
							mempoint = mempoint + 10;
						}

						indiv = town_cel_indiv(x_size, y_size, cel, celsize, pal, mempoint);

					}


					if (DEVELOPER_STAMP) // stamp the texture to keep track of it, for development
					{
						util.stamp_tex(indiv.c, indiv.x, indiv.y, texno);
					}


					int chunki;
					if (chunkfactor ==  CHUNKY_MAXI) {chunki = util.maxi_chunkyness(indiv.x, indiv.y);}
					else {chunki = util.auto_chunkyness(indiv.x, indiv.y);}

					// make a texchunk from our texture
					texchunk tx;
					tx.set(indiv.c, indiv.x, indiv.y, chunki, (chunkfactor == CHUNKY_SMOOTH));



					//OBJCURS are mouse pointers, so they need a special move
					if(allog == OBJCURS)
					{
						tx.move_offset(0, -alt_rez.y);
					}
					else
					{
						tx.move_offset(x_move, y_move);
					}
					out.chunk[texno] = tx;
					delete[] indiv.c;
				}
			}
		}
		delete[] cel;
		return out;
	}


	// ****** uifuse ******
	// this is a one-time-use-only hack to fuse the ui hud with the empty orbs
	// or the quest and inventory windows into the stash window
	int_texchunkp uifuse(int allog , unsigned char* cela, int cela_size, unsigned char* celb, int celb_size, unsigned char* pal)
	{
		if ( (allog == UIFUSE_ORBS) && ( cela_size > 82000) && (celb_size > 13000)  ) // cela is the hud, celb are the orbs
		{
			int memoff_hud =   (int)cela[(4*(0+1))]   + 0x100 * (int)cela[(4*(0+1))+1]   + 0x10000 * (int)cela[(4*(0+1))+2];
			int memoff_orbh =  (int)celb[(4*(0+1))]   + 0x100 * (int)celb[(4*(0+1))+1]   + 0x10000 * (int)celb[(4*(0+1))+2];
			int memoff_orbm =  (int)celb[(4*(1+1))]   + 0x100 * (int)celb[(4*(1+1))+1]   + 0x10000 * (int)celb[(4*(1+1))+2];

			// making sure that corrupt input doesnt make us go out of bounds
			if ((memoff_hud > cela_size - 100) || (memoff_orbh > celb_size - 100) || (memoff_orbm > celb_size - 100) )
			{
				cout << "DDT> uifuse received invalid  input! Memoff is too big" << endl;
				return int_texchunkp();
			}

			// getting the textures
			quad_int_ucharp hud =   generalp_cel_indiv(640, 144, cela,   cela_size,   pal, memoff_hud);
			quad_int_ucharp orbh =  generalp_cel_indiv( 88,  88, celb,   celb_size,   pal, memoff_orbh);
			quad_int_ucharp orbm =  generalp_cel_indiv( 88,  88, celb,   celb_size,   pal, memoff_orbm);

			//doing the fusing of the orbs into the hud
			util.insert_texture(hud.x, hud.y, hud.c, orbh.x, orbh.y, orbh.c,  96, 56, 88, 88);
			util.insert_texture(hud.x, hud.y, hud.c, orbm.x, orbm.y, orbm.c, 463, 56, 88, 88);

			// preparing the output
			texchunk hudchunk;
			hudchunk.set(hud.c, hud.x, hud.y, util.validate_chunkyness(hud.x, hud.y, 64), false);
			int_texchunkp out(1);
			out.chunk[0] = hudchunk;

			// cleaning up
			delete[] orbh.c;
			delete[] orbm.c;
			delete[] hud.c;

			delete[] cela;
			delete[] celb;

			return out;

		}
		else if ( (allog == UIFUSE_STASH) && ( cela_size > 112000) && (celb_size > 112000)  ) // cela is the quest window, celb is the char inventory
		{
			int memoff_quest = (int)cela[(4*(0+1))] + 0x100 * (int)cela[(4*(0+1))+1] + 0x10000 * (int)cela[(4*(0+1))+2];
			int memoff_inv =   (int)celb[(4*(0+1))] + 0x100 * (int)celb[(4*(0+1))+1] + 0x10000 * (int)celb[(4*(0+1))+2];

			// making sure that corrupt input doesnt make us go out of bounds
			if ((memoff_quest > cela_size - 100) || (memoff_inv > celb_size - 100) )
			{
				cout << "DDT> uifuse received invalid  input! Memoff is too big" << endl;
				return int_texchunkp();
			}

			// getting the textures
			quad_int_ucharp quest = generalp_cel_indiv(320, 352, cela, cela_size, pal, memoff_quest);
			quad_int_ucharp inv =   generalp_cel_indiv(320, 352, celb, celb_size, pal, memoff_inv);

			//doing the fusing of the quest and inventory texture
			util.insert_texture(quest.x, quest.y, quest.c, quest.x, quest.y, quest.c, 0, 242, 320,  40);
			util.insert_texture(quest.x, quest.y, quest.c, inv.x,   inv.y,   inv.c,   0, 116, 320, 140);
			util.insert_texture(quest.x, quest.y, quest.c, inv.x,   inv.y,   inv.c,   0,   0, 320, 130);

			// preparing the output
			texchunk stashchunk;
			stashchunk.set(quest.c, quest.x, quest.y, util.validate_chunkyness(quest.x, quest.y, 64), false);
			int_texchunkp out(1);
			out.chunk[0] = stashchunk;

			// cleaning up
			delete[] quest.c;
			delete[] inv.c;

			delete[] cela;
			delete[] celb;

			return out;

		}
		else
		{
			cout << "DDT> uifuse received invalid  input!" << endl;
			return int_texchunkp();
		}

	}


	private:

	//*****town_cel_indiv*****
	// This is a messenger between the classes above and the classes below.
	// We try some decodes and contemplate what to return. Use is for the level texture archives
	// Input:
	// x_size, y_size are the size of the pic as it is supposed to be in the cel file
	// cel is the file with bytesize celsize
	// pal is 768 byte palette file
	// memoff is where we start to read the file
	// Output:
	// A struct with i:the mempoint of where we stopped reading, j:how much the x size of the pic has been enlarged, xy: is the new size and c: is our output , RGBA texture

	quad_int_ucharp town_cel_indiv(int x_size, int y_size, unsigned char* cel , int celsize , unsigned char* pal, int mem_off)
	{
		if ( (x_size != 32) || (y_size != 32) )
		{
			// No need to try anything else then smart_cel
			return town_cel_smart_indiv(x_size, y_size, cel , celsize , pal, mem_off);
		}

		// Ok so we have 32*32. Lets see if smart_cel works
		quad_int_ucharp smart = town_cel_smart_indiv(32, 32, cel , celsize , pal, mem_off);
		if (!(util.texture_get_error(smart.c)))
		{
			// smart_cel worked ;)
			return smart;
		}
		delete[] smart.c;

		// Ok, now see about bigthen and smallthen
		quad_int_ucharp bigthen = town_cel_bigthen_indiv(cel , celsize , pal, mem_off);
		quad_int_ucharp smallthen = town_cel_smallthen_indiv(cel , celsize , pal, mem_off);

		bool bigerror = util.texture_get_error(bigthen.c);
		bool smallerror = util.texture_get_error(smallthen.c);
		bool bigwarning = util.texture_get_warning(bigthen.c);
		bool smallwarning = util.texture_get_warning(smallthen.c);

		// Preferably returning something without warning, else a warning but no error is ok
		if (!bigwarning)
		{
			delete[] smallthen.c;
			return bigthen;
		}
		if (!smallwarning)
		{
			delete[] bigthen.c;
			return smallthen;
		}
		if (!bigerror)
		{
			delete[] smallthen.c;
			return bigthen;
		}
		if (!smallerror)
		{
			delete[] bigthen.c;
			return smallthen;
		}

		// Nothing works so we go for pure raw rendering
		delete[] bigthen.c;
		delete[] smallthen.c;
		return raw_cel_indiv(32, 32, cel , celsize , pal, mem_off);

	}

	//*****town_cel_smart_indiv*****
	// This is for the textures in level files that have arbitrary transparency.
	// This is fussy, but it needs to be, because we need to detect decode failures
	// Input:
	// x_size, y_size are the size of the pic as it is supposed to be in the cel file
	// cel is the file with bytesize celsize
	// pal is 768 byte palette file
	// memoff is where we start to read the file
	// Output:
	// A struct with i:the mempoint of where we stopped reading, j:how much the x size of the pic has been enlarged, xy: is the new size and c: is our output , RGBA texture

	quad_int_ucharp town_cel_smart_indiv(int x_size, int y_size, unsigned char* cel , int celsize , unsigned char* pal, int mem_off)
	{

		//our pointer to the right value in the memory block
		int mempoint = mem_off;

		// Blow up the size to a power of 2
		int final_x_size = util.power_of_two(x_size);
		int final_y_size = util.power_of_two(y_size);

		// init output
		unsigned char* tex = util.empty_texture(final_x_size, final_y_size);


		//this is the pixel on the new texture
		int pixpointer_x = 0;
		int pixpointer_y = 0;


		//while we are not out of bounds of our pic and we havent reached eof
		while(pixpointer_y < y_size && mempoint < celsize-1)
		{

			//read and reverse first byte
			int newline_rbyte = x_size; //safety init
			newline_rbyte = 256 -(cel[mempoint]); //get the reverse of the first byte in the line


			//is true we have 100% spacing, so jump to a new line
			if ( newline_rbyte ==  x_size)
			{
				//newline
				pixpointer_y++;
				mempoint++;
				pixpointer_x = 0;
			}
			else
			{
				//this is the special case where the line starts with the pixelcount and not the spacing and THEN pixelcount
				//this happens when the spacing is supposed to be 0
				bool zero_spacing_special_case = newline_rbyte >  x_size;

				//while we havnt reached the width of our pic yet
				while(pixpointer_x < x_size)
				{
					if (!zero_spacing_special_case)
					{
						pixpointer_x = pixpointer_x + 256 - cel[mempoint]; //jump spacing
						mempoint++; //go to the pixelcount
						if (pixpointer_x > x_size)
						{
							//if this happens we have a decode failure
							util.texture_set_error(tex);
							return quad_int_ucharp(mempoint, x_size, final_x_size, final_y_size, tex);
						}
					}
					else
					{
						zero_spacing_special_case = false; //reset the special case, because we handeled it.
					}

					if (pixpointer_x < x_size) //making sure the spacing hasn't reached the end of the line
					{

						int writepix_no = 0; //safety init
						writepix_no = cel[mempoint]; //get the amount of pixels we need to write
						mempoint++;

						//eof check
						if (writepix_no < celsize - mempoint)
						{

							for (int p = writepix_no ; (p > 0); p--)
							{
								if (pixpointer_x > x_size -1)
								{
									//if this happens we have a decode failure
									util.texture_set_error(tex);
									return quad_int_ucharp(mempoint, x_size, final_x_size, final_y_size, tex);
								}
								else
								{
									//makepix(pixpointer_x + x_off, pixpointer_y+ y_off, cel[mempoint], pal); //draw pixel
									util.raster_pix(tex, final_x_size, final_y_size ,pixpointer_x, pixpointer_y, cel[mempoint], pal);
								}
								pixpointer_x++; //point to next pixel
								mempoint++; //go to the next pixel
							}
						}
					}
				}
			pixpointer_y++;
			pixpointer_x = 0;
			}
		}
		return quad_int_ucharp(mempoint, x_size, final_x_size, final_y_size, tex);
	}

	//*****town_cel_smallthen_indiv*****
	// this decodes pictures according to the 'smallthen_then_cel" algorithm
	// i called it like that because all the pictures look like the < sign.
	// they are the left side of a complete tile
	// Input:
	// x_size, y_size have to be 32 so no need to specify
	// cel is the file with bytesize celsize
	// pal is 768 byte palette file
	// memoff is where we start to read the file
	// Output:
	// A struct with i:the mempoint of where we stopped reading, j x and y all 32 and  c: is our output , RGBA texture

	quad_int_ucharp town_cel_smallthen_indiv( unsigned char* cel , int celsize , unsigned char* pal, int mem_off)
	{
		int x_size = 32; //this alog is never going to work for anything else
		int y_size = 32;
		int mempoint = mem_off;

		// init output
		unsigned char* tex = util.empty_texture(x_size, y_size);

		// See if we have to collapse to raw render after the first half
		bool second_part_raw = true;

		if (celsize > mem_off + 540)
		{
			// check for the markers of the first half
			if (
				cel[mem_off+   0] == 0  &&  cel[mem_off+    1] == 0  &&
				cel[mem_off+   8] == 0  &&  cel[mem_off+    9] == 0  &&
				cel[mem_off+  24] == 0  &&  cel[mem_off+   25] == 0  &&
				cel[mem_off+  48] == 0  &&  cel[mem_off+   49] == 0  &&
				cel[mem_off+  80] == 0  &&  cel[mem_off+   81] == 0  &&
				cel[mem_off+ 120] == 0  &&  cel[mem_off+  121] == 0  &&
				cel[mem_off+ 168] == 0  &&  cel[mem_off+  169] == 0  &&
				cel[mem_off+ 224] == 0  &&  cel[mem_off+  225] == 0
				)
			{}
			else
			{
				// first part is raw, we are not decoding this
				// we are aborting and sending a panic pixel back
				util.texture_set_error(tex);
				return quad_int_ucharp(mempoint, x_size, x_size, y_size, tex);
			}
			// check for the markers of the second half
			if (
				cel[mem_off+ 288] == 0  &&  cel[mem_off+  289] == 0  &&
				cel[mem_off+ 348] == 0  &&  cel[mem_off+  349] == 0  &&
				cel[mem_off+ 400] == 0  &&  cel[mem_off+  401] == 0  &&
				cel[mem_off+ 444] == 0  &&  cel[mem_off+  445] == 0  &&
				cel[mem_off+ 480] == 0  &&  cel[mem_off+  481] == 0  &&
				cel[mem_off+ 508] == 0  &&  cel[mem_off+  509] == 0  &&
				cel[mem_off+ 528] == 0  &&  cel[mem_off+  529] == 0
				)
			{second_part_raw = false;}
			else
			{
				// second part is raw
				//warning code is set, means decode might have failed
				util.texture_set_warning(tex);
			}
		}
		else
		{
			// memory chunk to small, we are not decoding this
			// we are aborting and sending a panic pixel back
			util.texture_set_error(tex);
			return quad_int_ucharp(mempoint, x_size, x_size, y_size, tex);
		}

		// draw first part
		int control_line = 0;

		for (; control_line < 8; control_line++)
		{
			mempoint = mempoint +2; // skipping control bytes

			int xdraw = control_line*4 +2;
			int xoffs = 32 - xdraw;
			int yoffs = 2*control_line;

			for (int px = xoffs ; px < 32 ; px++)
			{
				util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
				mempoint++;
			}

			xdraw = control_line*4+4;
			xoffs = 32 - xdraw;
			yoffs++;

			for (int px = xoffs ; px < 32 ; px++)
			{
				util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
				mempoint++;
			}

		}

		if (!second_part_raw)
		{
			//draw second part
			for (; control_line < 16; control_line++)
			{
				mempoint = mempoint+2;

				int xdraw = (15-control_line)*4 +2;
				int xoffs = 32 - xdraw;
				int yoffs = 2*control_line;

				for (int px = xoffs ; px < 32 ; px++)
				{
					util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
					mempoint++;
				}

				xdraw = (15-control_line)*4;
				xoffs = 32 - xdraw;
				yoffs++;

				for (int px = xoffs ; px < 32 ; px++)
				{
					util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
					mempoint++;
				}
			}
		}
		else
		{
			//draw second part raw
			//mempoint = mempoint +2; // skipping control bytes

			for (; control_line < 16; control_line++)
			{
				int xdraw = 32;
				int xoffs = 0;
				int yoffs = 2*control_line;

				for (int px = xoffs ; px < 32 ; px++)
				{
					util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
					mempoint++;
				}
					xdraw = 32;
					xoffs = 0;
					yoffs++;

				for (int px = xoffs ; px < 32 ; px++)
				{
					util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
					mempoint++;
				}
			}
		}
		return quad_int_ucharp(mempoint, x_size, x_size, y_size, tex);
	}

	//*****town_cel_bigthen_indiv*****
	// this decodes pictures according to the 'bigger_then_cel" algorithm
	// i called it like that because all the pictures look like the > sign.
	// they are the right side of a complete tile
	// Input:
	// x_size, y_size have to be 32 so no need to specify
	// cel is the file with bytesize celsize
	// pal is 768 byte palette file
	// memoff is where we start to read the file
	// Output:
	// A struct with i:the mempoint of where we stopped reading, j:32, xy: both 32 c: is our output  RGBA texture

	quad_int_ucharp town_cel_bigthen_indiv(unsigned char* cel , int celsize , unsigned char* pal, int mem_off)
	{

		int mempoint = mem_off;

		int x_size = 32; //this alog is never going to work for anything else
		int y_size = 32;

		// Init the output
		unsigned char* tex = util.empty_texture(x_size, y_size);

		// See if we have to collapse to raw render after the first half
		bool second_part_raw = true;

		if (celsize > mem_off + 511)
		{
			//checks of the markers of the first part are in place
			if (
				cel[mem_off+   2] == 0  &&  cel[mem_off+    3] == 0  &&
				cel[mem_off+  14] == 0  &&  cel[mem_off+   15] == 0  &&
				cel[mem_off+  34] == 0  &&  cel[mem_off+   35] == 0  &&
				cel[mem_off+  62] == 0  &&  cel[mem_off+   63] == 0  &&
				cel[mem_off+  98] == 0  &&  cel[mem_off+   99] == 0  &&
				cel[mem_off+ 142] == 0  &&  cel[mem_off+  143] == 0  &&
				cel[mem_off+ 194] == 0  &&  cel[mem_off+  195] == 0
				)
			{}
			else
			{
				// first part is raw, we are not decoding this
				// we are aborting and sending a panic pixel back
				util.texture_set_error(tex);
				return quad_int_ucharp(mempoint, x_size, x_size, y_size, tex);
			}

			//checks of the markers of the second part are in place
			if (
				cel[mem_off+ 254] == 0  &&  cel[mem_off+  255] == 0  &&
				cel[mem_off+ 318] == 0  &&  cel[mem_off+  319] == 0  &&
				cel[mem_off+ 374] == 0  &&  cel[mem_off+  375] == 0  &&
				cel[mem_off+ 422] == 0  &&  cel[mem_off+  423] == 0  &&
				cel[mem_off+ 462] == 0  &&  cel[mem_off+  463] == 0  &&
				cel[mem_off+ 494] == 0  &&  cel[mem_off+  495] == 0  &&
				cel[mem_off+ 518] == 0  &&  cel[mem_off+  519] == 0  &&
				cel[mem_off+ 534] == 0  &&  cel[mem_off+  535] == 0
				)
			{second_part_raw = false;}
			else
			{
				// second part is raw
				//setting a warning code, means decode might have failed.
				util.texture_set_warning(tex);
			}
		}
		else
		{
			// memory chunk to small, we are not decoding this
			// we are aborting and sending a panic pixel back
			util.texture_set_error(tex);
			return quad_int_ucharp(mempoint, x_size, x_size, y_size, tex);
		}


		//this takes care of the pixels that are there before the 00 00 encoding begins
		util.raster_pix(tex, x_size, y_size, 0, 0, cel[mempoint], pal);
		mempoint++;
		util.raster_pix(tex, x_size, y_size, 1, 0, cel[mempoint], pal);
		mempoint++;


		// draw first part
		int control_line = 0;

		for(; control_line < 7 ; control_line++)
		{
			mempoint = mempoint +2; //skipping control zeros

			int xdraw = (control_line+1)*4;
			int xoffs = 0;
			int yoffs = 2*control_line +1;

			for (int px = xoffs ; px < xdraw ; px++)
			{
				util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
				mempoint++;
			}

			xdraw = (control_line+1)*4 +2;
			xoffs = 0;
			yoffs++;

			for (int px = xoffs ; px < xdraw ; px++)
			{
				util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
				mempoint++;
			}
		}

		if (!second_part_raw)
		{
			//draw second part
			for(; control_line < 15 ; control_line++)
			{
				mempoint = mempoint +2; //skipping control zeros

				int xdraw = (15-control_line)*4;
				int xoffs = 0;
				int yoffs = 2*control_line +1;

				for (int px = xoffs ; px < xdraw ; px++)
				{
					util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
					mempoint++;
				}

				xdraw = ((15-control_line)*4) -2;
				xoffs = 0;
				yoffs++;

				for (int px = xoffs ; px < xdraw ; px++)
				{
					util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
					mempoint++;
				}
			}
		}
		else
		{
			//draw second part raw
			mempoint = mempoint +2; // skipping control bytes

			for (; control_line < 16; control_line++)
			{
				int xdraw = 32;
				int xoffs = 0;
				int yoffs = 2*control_line +1;

				for (int px = xoffs ; px < 32 ; px++)
				{
					util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
					mempoint++;
				}

					xdraw = 32;
					xoffs = 0;
					yoffs++;

				for (int px = xoffs ; px < 32 ; px++)
				{
					util.raster_pix(tex, x_size, y_size, px, yoffs, cel[mempoint], pal);
					mempoint++;

				}
			}
		}
		return quad_int_ucharp(mempoint, x_size, x_size, y_size, tex);
	}


	//*****generalp_cel_indiv*****
	// This is like smart_cel, however less fussy and can not detect if it decode failed because it doesn't expect explicit newline jumps.
	// An example of use are the loading screens
	// Input:
	// x_size, y_size are the size of the pic as it is supposed to be in the cel file
	// cel is the file with bytesize celsize
	// pal is 768 byte palette file
	// memoff is where we start to read the file
	// Output:
	// A struct with i:the mempoint of where we stopped reading, j:how much the x size of the pic has been enlarged, xy: is the new size and c: is our output , RGBA texture

	quad_int_ucharp generalp_cel_indiv(int x_size, int y_size, unsigned char* cel, int celsize, unsigned char* pal, int mem_off)
	{

		int mempoint = mem_off;

		// getting the new size that MUST be a power of 2
		int final_x_size = util.power_of_two(x_size);
		int final_y_size = util.power_of_two(y_size);

		// init the output
		unsigned char* tex = util.empty_texture(final_x_size, final_y_size);

		int pixpoint_x = 0; //on the new texture
		int pixpoint_y = 0; //on the new texture

		int pixpoint_scalar_max = x_size*y_size; //total amount of pixels to be drawn
		int pixpoint_scalar = 0; //current pixels vs the total amount

		// Just go till we run out of space
		while ((mempoint+5 < celsize) && (pixpoint_scalar < pixpoint_scalar_max))
		{
			// this is if we need to jump
			if (  (int)cel[mempoint] > 0x7F )
			{
				int jump_byte = (int)cel[mempoint];

				pixpoint_x = pixpoint_x + (0x100 - jump_byte);
				pixpoint_scalar = pixpoint_scalar + (0x100 - jump_byte);

				while (pixpoint_x > x_size -1)
				{
						pixpoint_x = pixpoint_x - x_size;
						pixpoint_y++;
				}
				mempoint++;
			}
			else // this is if we need to write
			{
				int write_byte = (int)cel[mempoint];

				for( int i = 0;  ( i < write_byte ) && (mempoint+write_byte) < celsize  ; i++)
				{
					util.raster_pix(tex, final_x_size, final_y_size, pixpoint_x, pixpoint_y, cel[mempoint+1+i], pal);
					pixpoint_x++;
					if (pixpoint_x > x_size -1) { pixpoint_x = 0; pixpoint_y++;}
				}
				mempoint = mempoint + write_byte +1;
				pixpoint_scalar = pixpoint_scalar + write_byte;
			}
		}
		return quad_int_ucharp(mempoint, x_size, final_x_size, final_y_size, tex);
	}



	//*****cltwo_indiv*****
	// Lots of stuff uses this, the hero, monsters and spell textures.
	// Input:
	// x_size, y_size are the size of the pic as it is supposed to be in the cl2 file
	// cel is the file with bytesize celsize
	// pal is 768 byte palette file
	// memoff is where we start to read the file
	// Output:
	// A struct with i:the mempoint of where we stopped reading, j:original x size, xy: is the new size and c: is our output , RGBA texture

	quad_int_ucharp cltwo_indiv(int x_size, int y_size, unsigned char* cel , int celsize , unsigned char* pal, int mem_off)
	{
		int mempoint = mem_off;

		// getting the new size that MUST be a power of 2
		int final_x_size = util.power_of_two(x_size);
		int final_y_size = util.power_of_two(y_size);

		// init the output
		unsigned char* tex = util.empty_texture(final_x_size, final_y_size);

		int pixpoint_x = 0; //on the new texture
		int pixpoint_y = 0; //on the new texture

		int pixpoint_scalar_max = x_size*y_size; //total amount of pixels to be drawn
		int pixpoint_scalar = 0; //current pixels vs the total amount

		// Just go till we run out of space
		while ((mempoint+5 < celsize) && (pixpoint_scalar < pixpoint_scalar_max))
		{
			// Repeat rules, we keep repeating the same pixel a couple of times
			if (  (int)cel[mempoint] > 0x7f  && (int)cel[mempoint] < 0xbf)
			{
				int repeat_count = 0xbf - (int)cel[mempoint];
				mempoint ++;

				for (int i  = 0 ; i < repeat_count ; i++)
				{
					util.raster_pix(tex, final_x_size, final_y_size, pixpoint_x, pixpoint_y, cel[mempoint], pal);
					pixpoint_x++;
					pixpoint_scalar++;

					if (pixpoint_x > x_size -1)
					{
						pixpoint_x = pixpoint_x - x_size; pixpoint_y++;
					}
				}
				mempoint ++;
			}

			// Jump rules (transparency) , we jump ahead a specified amount
			else if (  (int)cel[mempoint] < 0x80 )
			{
				int jump_byte = (int)cel[mempoint];

				pixpoint_x = pixpoint_x + jump_byte;
				pixpoint_scalar = pixpoint_scalar +  jump_byte;

				while (pixpoint_x > x_size -1)
				{
					pixpoint_x = pixpoint_x - x_size;
					pixpoint_y++;
				}
				mempoint++;
			}

			// Individual pixel write rules
			else
			{
				int write_byte = 0x100 - (int)cel[mempoint];

				for( int i = 0;  ( i < write_byte ) && (mempoint+write_byte) < celsize  ; i++)
				{
					util.raster_pix(tex, final_x_size, final_y_size, pixpoint_x, pixpoint_y, cel[mempoint+1+i], pal);
					pixpoint_x++;
					if (pixpoint_x > x_size -1) { pixpoint_x = 0; pixpoint_y++;}

				}
				mempoint = mempoint + write_byte +1;
				pixpoint_scalar = pixpoint_scalar + write_byte;
			}
		}

		return quad_int_ucharp(mempoint, x_size, final_x_size, final_y_size, tex);
	}

	//*****raw_cel_indiv*****
	// Some textures in the big level packs (town.cel) use this.
	// Input:
	// x_size, y_size are the size of the pic as it is supposed to be in the cel file
	// cel is the file with bytesize celsize
	// pal is 768 byte palette file
	// memoff is where we start to read the file
	// Output:
	// A struct with i:the mempoint of where we stopped reading, j:original x size, xy: is the new size and c: is our output , RGBA texture

	quad_int_ucharp raw_cel_indiv(int x_size, int y_size, unsigned char* cel , int celsize , unsigned char* pal, int mem_off)
	{
		int mempoint = mem_off;

		// getting the new size that MUST be a power of 2
		int final_x_size = util.power_of_two(x_size);
		int final_y_size = util.power_of_two(y_size);

		// init the output
		unsigned char* tex = util.empty_texture(final_x_size, final_y_size);

		int pixpoint_x = 0; //on the new texture
		int pixpoint_y = 0; //on the new texture

		int pixpoint_scalar_max = x_size*y_size; //total amount of pixels to be drawn
		int pixpoint_scalar = 0; //current pixels vs the total amount

		while ( (mempoint < celsize) && (pixpoint_scalar < pixpoint_scalar_max)  )
		{
			util.raster_pix(tex, final_x_size, final_y_size, pixpoint_x, pixpoint_y, cel[mempoint], pal);

			pixpoint_scalar++;
			pixpoint_x++;
			mempoint++;

			//up the y pos at end of line
			if (pixpoint_x > x_size -1)
			{
				pixpoint_x = 0;
				pixpoint_y++;
			}
		}
		return quad_int_ucharp(mempoint, x_size, final_x_size, final_y_size, tex);
	}

	quad_int_ucharp empty_cel_indiv()
	{
		unsigned char* tex = util.empty_texture(8, 8);
		return quad_int_ucharp(0, 8,8,8,tex);
	}



};

