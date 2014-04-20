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


#include "libsdl/SDL.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <stdint.h>

using namespace std;

typedef SDL_Event ddtinput_event;

#define DDTINPUT_QUEUE_EMPTY 0
#define DDTINPUT_QUIT 1

#define DDTINPUT_MOUSE_MOVE 2
#define DDTINPUT_MOUSE_LEFT_DOWN 3
#define DDTINPUT_MOUSE_LEFT_UP 4
#define DDTINPUT_MOUSE_RIGHT_DOWN 5
#define DDTINPUT_MOUSE_RIGHT_UP 6


#define DDTINPUT_UNKNOWN 999


class ddtinput
{
public:

	static int init()
	{
		return  SDL_InitSubSystem( SDL_INIT_EVENTTHREAD);

		//if (bla != 0) {cout << "SDL_INIT_EVENTTHREAD bad" << endl;}
		//else {cout << "SDL_INIT_EVENTTHREAD good" << endl;}
		//return bla;
	}

	static void close()
	{
		SDL_QuitSubSystem(SDL_INIT_EVENTTHREAD);
	}


	static void mouse_move_update(uint16_t* x, uint16_t* y)
	{

		int xx = 0;
		int yy = 0;
		SDL_GetMouseState(&xx, &yy);
		(*x) = xx; (*y) = yy;
	}


	static bool get_event(ddtinput_event* event, int* but, uint16_t* x, uint16_t* y)
	{
		if (SDL_PollEvent(event) < 1) { (*but) = DDTINPUT_QUEUE_EMPTY; return false; }

		switch((*event).type)
		{
			case SDL_QUIT : (*but) = DDTINPUT_QUIT; return true;
			case SDL_MOUSEMOTION : (*but) = DDTINPUT_MOUSE_MOVE; (*x) = (*event).motion.x; (*y) = (*event).motion.y; return true;
			case SDL_MOUSEBUTTONDOWN :
				switch((*event).button.button)
				{
					case SDL_BUTTON_LEFT : (*but) = DDTINPUT_MOUSE_LEFT_DOWN; (*x) = (*event).button.x; (*y) = (*event).button.y; return true;
					case SDL_BUTTON_RIGHT : (*but) = DDTINPUT_MOUSE_RIGHT_DOWN; (*x) = (*event).button.x; (*y) = (*event).button.y; return true;
				}
				break;
			case SDL_MOUSEBUTTONUP :
				switch((*event).button.button)
				{
					case SDL_BUTTON_LEFT : (*but) = DDTINPUT_MOUSE_LEFT_UP; (*x) = (*event).button.x; (*y) = (*event).button.y; return true;
					case SDL_BUTTON_RIGHT : (*but) = DDTINPUT_MOUSE_RIGHT_UP; (*x) = (*event).button.x; (*y) = (*event).button.y; return true;
				}
				break;
		}

		(*but) = DDTINPUT_UNKNOWN; return true;
	}
};





