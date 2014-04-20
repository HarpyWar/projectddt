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


#include "libsdl/SDL.h"
using namespace std;

class ddtgrfx_texob
{
	public:
	SDL_Surface* texob;
	unsigned char* texc;
};


class ddtgrfx
{
public:

	static int mouse_x(int sdl_mouse_x, int display_w)
	{
		return sdl_mouse_x;
	}

	static int mouse_y(int sdl_mouse_y, int display_h)
	{
		return display_h - sdl_mouse_y;
	}

	static float find_display_scale(int display_w, int display_h, int zoom)
	{
		return 1.0;
	}

	static int init()
	{
		return SDL_InitSubSystem(SDL_INIT_VIDEO);
	}

	static void close()
	{
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
	}

	static int init_display(int display_w, int display_h, char* caption)
	{
		SDL_SetVideoMode( display_w, display_h, 32, SDL_SWSURFACE );
		SDL_SetAlpha(SDL_GetVideoSurface(), SDL_SRCALPHA, 255 );
		SDL_WM_SetCaption( caption, NULL );


		SDL_ShowCursor(SDL_DISABLE); //hide the default mouse

		return 0;
	}


	static void swap_and_clear()
	{

		SDL_Flip( SDL_GetVideoSurface() );
		SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );

	}

	static void set_clear_color(unsigned char r, unsigned char g, unsigned char b)
	{

	}


	static void render_rect( float x, float y, float xs, float ys, float r, float g, float b, float a, int display_w, int display_h)
	{

	}

	static void render_diamond( float x, float y, float half_height, float r, float g, float b, float a, int display_w, int display_h)
	{


	}


	static void load_texob(ddtgrfx_texob* texob, unsigned char* c, int chunk_xy)
	{

		int byte_size = chunk_xy*chunk_xy*4;
		(*texob).texc = new unsigned char[byte_size];

		for (int y = 0; y < chunk_xy; y++)
		{
			int source_start = y*chunk_xy*4;
			int dest_start = (chunk_xy - y - 1)*chunk_xy*4;


			for( int x = 0; x < chunk_xy*4 ; x++)
			{
				(*texob).texc[dest_start + x] = c[source_start + x];
			}
		}

		delete[] c;
	}


	static void texob_make_renderable(ddtgrfx_texob* texob, int chunk_xy, bool smooth)
	{
		(*texob).texob = SDL_CreateRGBSurfaceFrom(
				(*texob).texc,
				chunk_xy,
				chunk_xy,
				32,
				chunk_xy*4,
				0x000000ff,
				0x0000ff00,
				0x00ff0000,
				0xff000000);
	}

	static void render_texob(ddtgrfx_texob* texob, float x, float y, float strech, float r, float g, float b, float a, int display_w, int display_h)
	{
		SDL_Rect offset;
		offset.x = x;
		offset.y = display_h - y - strech;

		SDL_BlitSurface( (*texob).texob, NULL, SDL_GetVideoSurface(), &offset );
	}

	static void render_texob_selected(ddtgrfx_texob* texob, float x, float y, float strech, int display_w, int display_h)
	{
		render_texob(texob, x, y, strech, 1.0, 1.0, 1.0, 1.0, display_w, display_h);
	}

	static void kill_texob(ddtgrfx_texob* texob)
	{
		SDL_FreeSurface((*texob).texob);
		delete[] (*texob).texc;
	}
};
