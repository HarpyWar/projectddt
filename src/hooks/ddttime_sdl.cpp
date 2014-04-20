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
using namespace std;



//typedef SDL_mutex ddtmutex;
typedef SDL_sem ddtmutex;

class ddttime
{
	public:

	static int init()
	{
		return SDL_Init( SDL_INIT_TIMER);
	}

	static void close()
	{
		SDL_QuitSubSystem(SDL_INIT_TIMER);
	}

	static void delay(unsigned int ms)
	{
		SDL_Delay(ms);
	}

	static unsigned int get()
	{
		return SDL_GetTicks();
	}


	static ddtmutex* create_mutex()
	{
		return SDL_CreateSemaphore(1);
	}

	static void destroy_mutex(ddtmutex* mu)
	{
		SDL_DestroySemaphore(mu);
	}

	static void lock_mutex(ddtmutex* mu)
	{
		SDL_SemWait(mu);
	}

	static void unlock_mutex(ddtmutex* mu)
	{
		SDL_SemPost(mu);
	}


	/*


	static void create_mutex(ddtmutex* mu)
	{
		mu = SDL_CreateMutex();
	}

	static void destroy_mutex(ddtmutex* mu)
	{
		SDL_DestroyMutex(mu);
	}

	static void lock_mutex(ddtmutex* mu)
	{
		SDL_mutexP(mu);
	}

	static void unlock_mutex(ddtmutex* mu)
	{
		SDL_mutexV(mu);
	}

	*/


};
