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




#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>


#define HIGHLIGHT_RED 0
#define HIGHLIGHT_YELLOW 1


using namespace std;





class ddtgrfx_texob
{
	public:
	GLuint texob;
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
		float width_allowed_scale = ((float)display_w) / (float)640 ;
		float hight_allowed_scale = ((float)display_h) / (float)480 ;
		float scale = 1.0 + (  ((float)zoom) * 0.1  *  (hight_allowed_scale-1.0)   );

		if (scale > width_allowed_scale)
		{
		scale = width_allowed_scale;
		}

		return scale;
	}

	static int init()
	{
		return SDL_InitSubSystem(SDL_INIT_VIDEO);
	}

	static void close()
	{
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
	}

	static int init_display(int display_w, int display_h, string caption)
	{


		if( SDL_SetVideoMode( display_w, display_h, 32, SDL_OPENGL ) == NULL ) {return 1;}
		SDL_WM_SetCaption( caption.c_str(), NULL );
		glClearColor( 0, 0, 0, 0 );
		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
		glOrtho( 0, display_w, 0, display_h, -1, 1 );
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();
		if( glGetError() != GL_NO_ERROR ){return 1;}
		glEnable( GL_TEXTURE_2D );
		glEnable (GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

		glClearColor(0.0, 0.0, 0.0, 1.0);

		glPointSize(4.0);

		SDL_ShowCursor(SDL_DISABLE); //hide the default mouse

		return 0;
	}


	static void swap_and_clear()
	{

		SDL_GL_SwapBuffers();
		glClear(GL_COLOR_BUFFER_BIT);


	}


	static void set_clear_color(unsigned char r, unsigned char g, unsigned char b)
	{
		glClearColor(
				(float)r * 0.00390625,
				(float)g * 0.00390625,
				(float)b * 0.00390625,
				1.0);

	}



	static void render_rect( float x, float y, float xs, float ys, float r, float g, float b, float a, int display_w, int display_h)
	{
		glLoadIdentity();
		glBindTexture( GL_TEXTURE_2D, NULL );
		glBegin( GL_QUADS );
		glColor4f( r, g, b, a ); //rgba
		glVertex2d( x,		y		);
		glVertex2d( x + xs,	y 		);
		glVertex2d( x + xs, y + ys	);
		glVertex2d( x, 		y + ys	);
		glEnd();
	}

	static void render_diamond( float x, float y, float half_height, float r, float g, float b, float a, int display_w, int display_h)
	{

		glLoadIdentity();
		glBindTexture( GL_TEXTURE_2D, NULL );
		glBegin( GL_QUADS );
		glColor4f( r , g , b , a ); //rgba
		glVertex2d( x,					y + half_height		);
		glVertex2d( x + 2*half_height,	y					);
		glVertex2d( x + 4*half_height, 	y + half_height 	);
		glVertex2d( x + 2*half_height, 	y + 2*half_height 	);
		glEnd();
	}


	static void load_texob(ddtgrfx_texob* texob, unsigned char* c, int chunk_xy)
	{
		(*texob).texc = c;
	}


	static void texob_make_renderable(ddtgrfx_texob* texob, int chunk_xy, bool smooth)
	{
		glGenTextures( 1, &((*texob).texob));
		glBindTexture( GL_TEXTURE_2D, (*texob).texob );

		if(smooth)
		{
			glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
			glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		}
		else
		{
			glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
			glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
		}

		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );
		gluBuild2DMipmaps( GL_TEXTURE_2D, 4, chunk_xy, chunk_xy, GL_RGBA, GL_UNSIGNED_BYTE, (*texob).texc);

		delete[] (*texob).texc;
	}

	static void render_texob(ddtgrfx_texob* texob, float x, float y, float strech, float r, float g, float b, float a, int display_w, int display_h)
	{
		glLoadIdentity();
		glBindTexture( GL_TEXTURE_2D, (*texob).texob );
		glColor4f( r, g, b, a ); //rgba
		glBegin( GL_QUADS );
		glTexCoord2d(0.0, 0.0); glVertex2d(x,			y);
		glTexCoord2d(1.0, 0.0); glVertex2d(x + strech, 	y);
		glTexCoord2d(1.0, 1.0); glVertex2d(x + strech,	y+ strech);
		glTexCoord2d(0.0, 1.0); glVertex2d(x,			y+ strech);
		glEnd();
	}

	static void render_texob_highlight(int hi_code, ddtgrfx_texob* texob, float x, float y, float strech, int display_w, int display_h)
	{
		glLoadIdentity();
		glBindTexture( GL_TEXTURE_2D, (*texob).texob );
		glColor4f( 1.0, 0.3, 0.3, 1.0 ); //rgba
		glBegin( GL_QUADS );
		glTexCoord2d(0.0, 0.0); glVertex2d(x,			y);
		glTexCoord2d(1.0, 0.0); glVertex2d(x + strech, 	y);
		glTexCoord2d(1.0, 1.0); glVertex2d(x + strech,	y+ strech);
		glTexCoord2d(0.0, 1.0); glVertex2d(x,			y+ strech);
		glEnd();

		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		glLoadIdentity();
		glBindTexture( GL_TEXTURE_2D, (*texob).texob );

		switch(hi_code)
		{
			case HIGHLIGHT_RED : glColor4f( 1.0, 0.3, 0.3, 1.0 ); break;
			case HIGHLIGHT_YELLOW : glColor4f( 1.0, 1.0, 0.0, 1.0 ); break;
		}

		glBegin( GL_QUADS );
		glTexCoord2d(0.0, 0.0); glVertex2d(x,			y);
		glTexCoord2d(1.0, 0.0); glVertex2d(x + strech, 	y);
		glTexCoord2d(1.0, 1.0); glVertex2d(x + strech,	y+ strech);
		glTexCoord2d(0.0, 1.0); glVertex2d(x,			y+ strech);
		glEnd();
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	static void kill_texob(ddtgrfx_texob* texob)
	{
		glDeleteTextures( 1, &((*texob).texob));
	}
};
