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




#include "levx_fsy_filemaster.cpp"
using namespace std;


class ui_name_enter_string
{
	public:
	unsigned char name[MAX_CHAR_NAME_LENGTH];
	int size;
	//MAX_CHAR_NAME_LENGTH

	ui_name_enter_string()
	{
		reset();
	}

	void reset()
	{
		size = 0;
	}

	void add(unsigned char c)
	{
		if (c == '<')
		{
			if (size > 0)
			{
				size--;
			}
		}
		else if (c == '@')
		{
			size = 0;
		}
		else if (size < MAX_CHAR_NAME_LENGTH)
		{
			name[size] = c;
			size++;
		}
	}

	string give()
	{
		string out = "";
		for (int i = 0; i < size; i++)
		{
			out.push_back(name[i]);
		}
		return out;
	}


	string give_with_cursor()
	{
		string out = give();
		out.append("[verti]");
		return out;
	}

	bool exists_in_this_list(int lcount, string* list)
	{
		bool out = false;
		string ours = give();


		for (int i = 0; i < lcount; i++)
		{
			if (ours == list[i])
			{
				out = true;
			}
		}
		return out;
	}

};

class ui_grfx_atom
{
	public:

	float anchor_x;
	float anchor_y; // where should we draw this
	int tex_group; // texkeeper refference, can also  be VOID_TEXTURE
	int tex_sub_group; // texkeeper refference, can also be VOID_TEXTURE or IDLE_ANIMATED
	float rmod; // color stuff
	float gmod;
	float bmod;
	float amod;


	ui_grfx_atom()
	{
		set(0, 0, VOID_TEXTURE, VOID_TEXTURE, 1.0, 1.0, 1.0, 1.0);

	}

	void set(float ax, float ay, int gro, int sgro)
	{
		set(ax, ay, gro, sgro, 1.0, 1.0, 1.0, 1.0);
	}

	void set(float ax, float ay, int gro, int sgro, float rm, float gm, float bm, float am)
	{

		anchor_x = ax;
		anchor_y = ay;
		tex_group = gro;
		tex_sub_group = sgro;
		rmod = rm; gmod = gm; bmod = bm; amod = am;
	}
};

class ui_border
{
	public:

	float anchor_x;
	float anchor_y;
	int streching_x;
	int streching_y;
	int active_members;

	float bgr; //background
	float bgg;
	float bgb;
	float bga;

	ui_grfx_atom* atom;
	int* x_off;
	int* y_off;
	int* repeat;
	int* repeatstep_x;
	int* repeatstep_y;

	int grfx_size; //hardcoded value corresponding to the bitmap

	ui_border()
	{
		atom = new ui_grfx_atom[8];
		x_off = new int[8];
		y_off = new int[8];
		repeat = new int[8];
		repeatstep_x = new int[8];
		repeatstep_y = new int[8];
		grfx_size = 11;
		clean();
	}

	void clean()
	{
		anchor_x = 0; anchor_y = 0;
		streching_x = 0; streching_y = 0;
		active_members = 0;
		bgr = 0.0; bgg = 0.0; bgb = 0.0; bga = 0.0;
	}

	void set_center( float x, float y, int x_strech, int y_strech)
	{
		set ( x - 0.5*(x_strech*grfx_size), y - 0.5*(y_strech*grfx_size), x_strech, y_strech);
	}

	void set( float x, float y, int x_strech, int y_strech)
	{

		clean();
		anchor_x = x; anchor_y = y;

		if (((x_strech < 0) || (y_strech < 0)) ||  ((x_strech == 0) && (y_strech == 0)) )
		{
			cout << "DDT> ui_border bad init" << endl;
			return;
		}
		else if ((y_strech == 0) && x_strech > 0) // horizontal bar
		{
			atom[0].set(0,0,SCROLL_BAR,6); repeat[0] = x_strech;
			repeatstep_x[0] = grfx_size; repeatstep_y[0] = 0;
			streching_x = grfx_size*x_strech; streching_y = 0;
			active_members = 1;
		}
		else if ((x_strech == 0) && y_strech > 0) // vertical bar
		{
			atom[0].set(0,0,SCROLL_BAR,5); repeat[0] = y_strech;
			repeatstep_x[0] = 0; repeatstep_y[0] = grfx_size;
			streching_x = 0; streching_y = grfx_size*x_strech;
			active_members = 1;
		}
		else if ((x_strech > 1) && (y_strech > 1)) // box
		{
			atom[0].set(                      0,                     0,  SCROLL_BAR,1); repeat[0] = 1; //lowleft corner
			atom[1].set(                      0,(y_strech-1)*grfx_size,  SCROLL_BAR,0); repeat[1] = 1; //hileft corner
			atom[2].set( (x_strech-1)*grfx_size,                      0, SCROLL_BAR,2); repeat[2] = 1; //loright corner
			atom[3].set( (x_strech-1)*grfx_size, (y_strech-1)*grfx_size, SCROLL_BAR,3); repeat[3] = 1; //hiright corner

			streching_x = x_strech*grfx_size; streching_y = y_strech*grfx_size;
			active_members = 4;

			if ( x_strech > 2) // we need horizontal bars
			{
				atom[active_members].set( grfx_size,  0, SCROLL_BAR, 6);
				repeat[active_members] = x_strech - 2;
				repeatstep_x[active_members] = grfx_size;
				repeatstep_y[active_members] = 0;
				active_members++;

				atom[active_members].set( grfx_size, (y_strech-1)*grfx_size, SCROLL_BAR, 4);
				repeat[active_members] = x_strech - 2;
				repeatstep_x[active_members] = grfx_size;
				repeatstep_y[active_members] = 0;
				active_members++;

			}
			if ( y_strech > 2) // we need vertical bars
			{
				atom[active_members].set( 0,  grfx_size, SCROLL_BAR, 5);
				repeat[active_members] = y_strech - 2;
				repeatstep_x[active_members] = 0;
				repeatstep_y[active_members] = grfx_size;
				active_members++;

				atom[active_members].set( (x_strech-1)*grfx_size, grfx_size, SCROLL_BAR, 7);
				repeat[active_members] = y_strech - 2;
				repeatstep_x[active_members] = 0;
				repeatstep_y[active_members] = grfx_size;
				active_members++;
			}
		}

		else { cout << "DDT> ui_border.set got unsupported input" << endl; }

	}

	void set_color(float r, float g, float b, float a)
	{
		bgr = r; bgg = g; bgb = b; bga = a;
	}

};


class ui_button
{
	public:

	float anchor_x;
	float anchor_y; // where should the button be on screen
	float streching_x;
	float streching_y; // how many pixels, measured from the anchor, does the button occupy

	int button_command; //what should be done when the button is pressed
	bool sticky_select; //should the button stay selected even though the mouse is no longer there?

	ui_grfx_atom idle_grfx; //the allways visible idle graphic for this button
	ui_grfx_atom mouseover_grfx_a; //what to show when the mouse is passing
	ui_grfx_atom mouseover_grfx_b; // another thing to shoqw when the mouse is passing

	int mouseover_sound;
	int klick_it_sound;

	volatile bool is_selected; //are we selected at the moment
	volatile bool is_visisble; //should we render this at all

	float bgr; //button background
	float bgg;
	float bgb;
	float bga;


	ui_button() // safety init
	{
		anchor_x = 0; anchor_y = 0; streching_x = 32; streching_y = 32;
		button_command = BUTTON_VOID_COMMAND; sticky_select = false;
		mouseover_sound = VOID_SOUND; klick_it_sound = VOID_SOUND;
		is_selected = false; is_visisble = true;
		bgr = 1; bgg = 1; bgb = 1; bga = 0.0;
	}

	void set(float anch_x, float anch_y, float str_x, float str_y, int com, bool stick, int overs, int clsound)
	{
		anchor_x = anch_x; anchor_y = anch_y; streching_x = str_x; streching_y = str_y;
		button_command = com; sticky_select = stick;
		mouseover_sound = overs; klick_it_sound = clsound;
	}

	void set_color(float r, float g, float b, float a)
	{
		bgr = r; bgg = g; bgb = b; bga = a;
	}


	//are these screen coordinates in range of this button?
	bool is_this_in_range(int xr, int yr)
	{
		//return true;
		if (xr < anchor_x){return false;}
		if (yr < anchor_y){return false;}
		if (xr > anchor_x + streching_x){return false;}
		if (yr > anchor_y + streching_y){return false;}
		return true;
	}
};


//This facilitates text on screen. All values should be set only though functions but can be read directly.
class ui_textline
{
	public:

	utils util;

	int visible;
	int count; // how many letters, should never be changed after init, bad mulithread juju if you do.
	int font; // for valid fonttypes, check levelz, FONT_SMALL etc...
	float anchor_x;
	float anchor_y; // where should the textline be on screen
	int spacing; // how much slack pixels between the letters
	int justify; // center the text or not
	int active_count; // how many chars are actually non-void

	//the text color
	float cur_r;
	float cur_g;
	float cur_b;

	ui_grfx_atom* letter;


	ui_textline()
	{
		visible = false;
		count = 0;
		font = VOID_TEXTURE;
		anchor_x = 0;
		anchor_y = 0;
		spacing = 0;
		justify = TEXT_JUSTIFY_LEFT;
		active_count = 0;

		//opening values for the colors
		cur_r = 1.0;
		cur_g = 1.0;
		cur_b = 1.0;


	}

	void set(int cnt, float anch_x, float anch_y, string stext)
	{
		font = FONT_SMALL;
		anchor_x = anch_x;
		anchor_y = anch_y;
		spacing = 0;
		justify = TEXT_JUSTIFY_LEFT;
		active_count = 0;

		if (cnt < 1)
		{
			count = 0;
			cout << "DDT> Bad textbox init"<< endl;
		}
		else
		{
			count = cnt;
			letter = new ui_grfx_atom[cnt];
			reset(stext);
		}
	}


	void reset(string stext)
	{
		visible = true;
		int stext_sz = (int)(stext.size());

		active_count = 0;



		int cur_x = 0; //start value x alignment
		int stringpoint = 0; //where are we in the input string
		int letterpoint = 0; //where are we in our letter array

		//now lets assign all the letters
		while ( (letterpoint < count ) && (stringpoint < stext_sz ) )
		{
			char curchar = stext.at(stringpoint);

			if ( curchar == '(' ) // this means that what follows should be a color code
			{
				if ( stext_sz  >  stringpoint + 5)
				{
					tri_float new_color =   util.textline_get_colorcode(   stext.substr(stringpoint, 5) );
					cur_r = new_color.x;
					cur_g = new_color.y;
					cur_b = new_color.z;
				}
				stringpoint = stringpoint + 5;
			}

			else if ( curchar == '{' ) // this means that what follows should be a font code
			{
				if ( stext_sz  >  stringpoint + 5)
				{
					font =  util.textline_get_fontcode(  stext.substr(stringpoint, 5) );

				}
				stringpoint = stringpoint + 5;
			}
			else if ( curchar == '<' ) // this means that what follows should be a justify code
			{
				if ( stext_sz  >  stringpoint + 5)
				{
					justify =  util.textline_get_justifycode(  stext.substr(stringpoint, 5) );

				}
				stringpoint = stringpoint + 5;
			}
			else if ( curchar == '$' ) // this means that what follows should be a spacing code
			{
				if ( stext_sz  >  stringpoint + 5)
				{
					spacing =  util.textline_get_spacingcode(  stext.substr(stringpoint, 5) );

				}
				stringpoint = stringpoint + 5;
			}
			else if (curchar == '[') //this means that what follows should be special char
			{

				if ( stext_sz  >  stringpoint + 6)
				{
					di_int w_and_n =  util.textline_get_width_and_number(   stext.substr(stringpoint, 7),  font);

					letter[letterpoint].tex_group = font;
					letter[letterpoint].tex_sub_group = w_and_n.y; //assigning the letter
					letter[letterpoint].anchor_x = cur_x; //assigning the spacing
					letter[letterpoint].anchor_y = 0; //assuming the letters have all the same y offset

					letter[letterpoint].rmod = cur_r; //assigning letter color
					letter[letterpoint].gmod = cur_g;
					letter[letterpoint].bmod = cur_b;
					letter[letterpoint].amod = 1.0;

					cur_x = cur_x + w_and_n.x + spacing; //increasing spacing for the next letter;
				}
				stringpoint = stringpoint + 7;
				letterpoint++;

			}
			else //this means we should be getting a normal char
			{
				if ( stext_sz  >  stringpoint )
				{
					di_int w_and_n =  util.textline_get_width_and_number(   stext.substr(stringpoint, 1),  font);

					letter[letterpoint].tex_group = font;
					letter[letterpoint].tex_sub_group = w_and_n.y; //assigning the letter
					letter[letterpoint].anchor_x = cur_x; //assigning the spacing
					letter[letterpoint].anchor_y = 0; //assuming the letters have all the same y offset

					letter[letterpoint].rmod = cur_r; //assigning letter color
					letter[letterpoint].gmod = cur_g;
					letter[letterpoint].bmod = cur_b;
					letter[letterpoint].amod = 1.0;

					cur_x = cur_x + w_and_n.x + spacing; //increasing spacing for the next letter;
				}
				stringpoint++;
				letterpoint++;
			}

		}


		if (cur_x > 0 && letterpoint > 0)
		{
			active_count = letterpoint;
		}


		if ( justify == TEXT_JUSTIFY_CENTER)
		{
			for (int i = 0; i < active_count ; i ++)
			{
				letter[i].anchor_x = letter[i].anchor_x - 0.5*cur_x;
			}
		}
		else if (justify == TEXT_JUSTIFY_RIGHT)
		{
			for (int i = 0; i < active_count ; i ++)
			{
				letter[i].anchor_x = letter[i].anchor_x - cur_x;
			}
		}
	}

};

class ui_textfield
{

	public:

	ui_textline* line;
	int line_count;
	int active_line_count; // how many of the textlines actually have text
	float pref_y_slack_spacing; //how far should, preferably, the lines be apart on the y-axis in addition to the font height
	float y_slack_spacing; //how far should the lines be apart on the y-axis in addition to the font height
	int font_height; //how big is the font we are using
	float anchor_x; //offset of the CENTER of the textfield
	float anchor_y;
	float height;
	float width;
	float scroller; //what is the y offset of the first line
	float autoscroll; // should a slow scrolldown happen automatically each frame
	bool fader; // should textlines that are too close to the edges fade
	bool visible;


	ui_textfield()
	{
		init(0, 0, 0, 0, 0, 0);
	}


	void init(float anch_x, float anch_y, float wi, float hi, int l_count, int c_count)
	{
		anchor_x = anch_x; anchor_y = anch_y;  height = hi;  width = wi;
		scroller = 0.0; active_line_count = 0; y_slack_spacing = 1; font_height = 1;
		line_count = 0; pref_y_slack_spacing = 1; fader = false;
		autoscroll = 0.0;
		if (l_count > 0){visible = true;} else {visible = false;}

		if (l_count > 0 && c_count > 0)
		{
			line_count = l_count;
			line = new ui_textline[line_count];

			for (int i = 0; i < line_count; i++)
			{
				line[i].set(c_count, 0, 0, " ");
			}
		}
	}

	void format(float y_slack, float fohi, string defline)
	{
		pref_y_slack_spacing = y_slack;
		y_slack_spacing = y_slack;
		font_height = fohi;
		for (int i = 0; i < line_count; i++)
		{
			line[i].reset(defline);
		}

		if (y_slack < 0 || fohi < 1)
		{
			cout << "DDT> ui_textfield format bad parameters passed" << endl;
		}
	}


	// setting up a big scrollable chunk of text
	void reset(int x_count, string* stx)
	{
		if (x_count < 1){ cout << "DDT> ui_textfield reset x bad input" << endl; return;}
		if (x_count > line_count){ cout << "DDT> ui_textfield reset x overloading" << endl; return;}
		y_slack_spacing = pref_y_slack_spacing;

		active_line_count = x_count;
		scroller = 0;

		for (int i = 0; i < x_count; i ++)
		{
			line[i].reset(stx[i]);
		}

		delete[] stx;
	}

	void reset_and_line_out(string in, int max_width)
	{
		clear();

		if (max_width < 5){return;}
		int in_size = in.size();


		int in_pointer = 0;
		int string_pointer = 0;
		int string_pos = 0;
		string cur= "";

		while(string_pointer < line_count && in_pointer < in_size)
		{
			if (string_pos > max_width + 1)
			{

				line[string_pointer].reset(cur);
				active_line_count ++;
				string_pointer++;
				string_pos = 0;
				cur = "";
			}
			else
			{
				char c =  in.at(in_pointer);

				if ((string_pos == 0) && (c == ' '))
				{

				}
				else if (c == 0x0a || c == 0x2e)
				{
					line[string_pointer].reset(cur);
					active_line_count ++;
					string_pointer++;
					string_pos = 0;
					cur = "";

				}
				else if ((string_pos > max_width -15) && (c == ' '))
				{
					line[string_pointer].reset(cur);
					active_line_count ++;
					string_pointer++;
					string_pos = 0;
					cur = "";

				}
				else
				{
					cur.append(1, in.at(in_pointer));
					string_pos ++;

				}
				in_pointer++;
			}
		}
		line[string_pointer].reset(cur);
		active_line_count ++;
		string_pointer++;

		if (string_pointer < line_count )
		{
			line[string_pointer].reset("");
			active_line_count ++;
			string_pointer++;
		}

	}

	void clear()
	{
		active_line_count = 0;
		scroller = 0;
		y_slack_spacing = pref_y_slack_spacing;
	}

	void space_vertical()
	{
		y_slack_spacing = pref_y_slack_spacing;

		if (active_line_count < 1){return;}
		else if (active_line_count == 1)
		{
			scroller = 0.5*height - 0.5*font_height;
		}
		else
		{
			//lets see if the slack spacing is small enough to to fit the lines in the field
			if (font_height*active_line_count + y_slack_spacing*(active_line_count-1) > height)
			{
				//no its not, fixing it
				y_slack_spacing = (height  - font_height*active_line_count) / (active_line_count-1);
			}
			// adjusting the scroll so everything is in the middle
			scroller = 0.5*height  + 0.5*( (active_line_count-1)*y_slack_spacing + active_line_count*font_height ) - font_height ;
		}
	}

	void scroll_up(float scrollstep)
	{
		if (scroller - scrollstep < 0)
		{
			scroller = 0.0;
		}
		else
		{
			scroller = scroller - scrollstep;
		}
	}

	void scroll_down(float scrollstep)
	{
		float block_height = (active_line_count - 2) * (y_slack_spacing + font_height) + height;
		if (scroller + scrollstep > block_height)
		{
			scroller = block_height;
		}
		else
		{
			scroller = scroller + scrollstep;
		}
	}

};

class ui_subscreen
{
	public:
	volatile bool visible;

	bool solid; // if true, this screen does not allow clicks to pass underneath

	ui_textline* textline; // lines of text on this screen
	int textline_count;

	ui_textfield* textfield; // the textfields
	int textfield_count;

	ui_button* button; //buttons on this screen
	int button_count;

	ui_grfx_atom* doodad; //nonactive grfx
	int doodad_count;

	ui_border* border; //framing
	int  border_count;

	float anchor_x; //offset of this subscreen
	float anchor_y;

	float streching_x;
	float streching_y; // how many pixels, measured from the anchor, does the button occupy

	float bgr;
	float bgg;
	float bgb; // background render options
	float bga;

	ui_subscreen()
	{
		visible = false;
		solid = true;
		textline_count = 0;
		textfield_count = 0;
		button_count = 0;
		doodad_count = 0;
		border_count = 0;
		anchor_x = 0;
		anchor_y = 0;
		streching_x = 0;
		streching_y = 0;
	}

	void init(int txtlines, int fields, int bttns, int doods, int borders)
	{
		visible = true;
		if (txtlines < 0) {textline_count = 0; cout << " bad ui_screen init" << endl;}
		else {textline_count = txtlines;}
		if (fields < 0) {textfield_count = 0; cout << " bad ui_screen init4" << endl;}
		else {textfield_count = fields;}
		if (bttns < 0) {button_count = 0; cout << " bad ui_screen init2" << endl;}
		else {button_count = bttns;}
		if (doods < 0) {doodad_count = 0; cout << " bad ui_screen init3" << endl;}
		else {doodad_count = doods;}
		if (borders < 0) {border_count = 0; cout << " bad ui_screen init4" << endl;}
		else {border_count = borders;}

		if(textline_count > 0)
		{
			textline = new ui_textline[textline_count];
		}

		if(textfield_count > 0)
		{
			textfield = new ui_textfield[textfield_count];
		}

		if(button_count > 0)
		{
			button = new ui_button[button_count];
		}
		if(doodad_count > 0)
		{
			doodad = new ui_grfx_atom[doodad_count];
		}
		if(border_count > 0)
		{
			border = new ui_border[border_count];
		}

		anchor_x = 0;
		anchor_y = 0;
		streching_x = 0;
		streching_y = 0;

		bgr = 0.0; bgg = 0.0; bgb = 0.0; bga = 0.0;
	}

	//are these screen coordinates in range of this button?
	bool is_this_in_range(int xr, int yr)
	{
		//return true;
		if (xr < anchor_x){return false;}
		if (yr < anchor_y){return false;}
		if (xr > anchor_x + streching_x){return false;}
		if (yr > anchor_y + streching_y){return false;}
		return true;
	}

};

class ui_screen
{
	public:




	ui_grfx_atom backdrop; // the graphic we render first

	ui_subscreen* subscreen;
	int subscreen_count;

	ui_screen()
	{
		subscreen_count = 0;

	}

	void init(int subscr)
	{
		if (subscr > 0){ subscreen = new ui_subscreen[subscr];}
		subscreen_count = subscr;
	}

	di_int susbscreen_and_button_for_mouse_at(int mouse_x, int mouse_y)
	{
		for (int i = 0 ; i < subscreen_count ; i++)
		{
			if (subscreen[i].is_this_in_range(mouse_x, mouse_y) && subscreen[i].visible )
			{
				for (int j = 0 ; j < subscreen[i].button_count ; j++)
				{
					if (subscreen[i].button[j].is_this_in_range(mouse_x - subscreen[i].anchor_x  , mouse_y - subscreen[i].anchor_y))
					{
						if (subscreen[i].button[j].is_visisble)
						{
							return di_int(i,j); // we have a button
						}
					}
				}

				if (subscreen[i].solid) {return di_int(i, -1);} // we have a solid subscreen in range but no button
			}
		}
		return di_int(-1, -1); // we have nu subscreens in range of the button
	}

	void unselect_all_buttons(bool the_sticky_ones_too)
	{
		for (int i = 0 ; i < subscreen_count ; i++)
		{
			if ( subscreen[i].visible)
			{
				for (int j = 0 ; j < subscreen[i].button_count ; j++)
				{
					if (the_sticky_ones_too)
					{
						subscreen[i].button[j].is_selected = false;
					}
					else
					{
						if (subscreen[i].button[j].sticky_select == false)
						{
							subscreen[i].button[j].is_selected = false;
						}

					}
				}

			}

		}
	}

};




