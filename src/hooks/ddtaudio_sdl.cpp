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


using namespace std;


class ddtaudio
{
	public:

	static int init()
	{
		return SDL_InitSubSystem( SDL_INIT_AUDIO);
	}

	static void close()
	{
		SDL_QuitSubSystem(SDL_INIT_AUDIO);
	}



};
