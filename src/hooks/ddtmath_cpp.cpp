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


#include <cstdlib>
#include <ctime>

using namespace std;


class ddtmath
{
	public:


	static double save_positive_division(int dividee, int divider)
	{
		if ( dividee < 1 || divider < 1) {return 0.0;}
		return (double)dividee / (double)divider;
	}

	static double weighted_average(double factor_a, double factor_b, double bias_to_a)
	{
		return bias_to_a*factor_a + (1.0 - bias_to_a)*factor_b;
	}

	static void init()
	{
		srand((unsigned)time(0));
	}


	static int random_int(int max)
	{
		//min = 0 implied

		if (max < 1) {return 0;}

		double floater = ( (double)rand() )  /  (  (double)RAND_MAX );
		int ajusted =  (floater * (double)(max + 1));

		if (ajusted > max) {ajusted = max;}

		return ajusted;

	}


	static int random_int(int min, int max)
	{
		if (!(min < max)) {return min;}

		return random_int( max - min) + min;
	}


	static int modu(int raw, int mod)
	{
		if ( mod < 1) { return 0;}
		if ( raw < 1) {return 0;}


		return raw - (raw/ mod)*mod;

	}

	static int idle_frame(int ticks, int total_frames, double frames_per_tick)
	{
		if (frames_per_tick < 0.01) {return 0;}

		return modu(ticks,((double)total_frames*frames_per_tick))/frames_per_tick;

	}




	static int directional_ilde_frame(int ticks, int total_frames, double frames_per_tick, int direction)
	{
		return direction*(total_frames/8) + idle_frame(ticks, total_frames/8, frames_per_tick);

	}

	static int directional_sequential_frame(int total_frames, int action_dur, int action_dur_passed, int direction)
	{
		if (total_frames < 8 || action_dur < 1 || action_dur_passed < 0) {return 0;}

		float phase = (float)action_dur_passed / (float)action_dur;
		int phase_frame = ((float)total_frames /8) *  phase;
		return phase_frame + direction*total_frames/8;
	}

	static int item_flip_frame(int total_frames, float action_fraction)
	{
		if(action_fraction == 0.0)
		{
			return 0;
		}

		if (  (!(action_fraction > 0.0)) || (!(action_fraction < 1.0)) )
		{
			return total_frames -1;
		}

		float out = (float)total_frames * action_fraction;
		return out;
	}

	/*
	static float pulsating_alpha(int ticks, float engine_speedup)
	{
		int mod = 126*engine_speedup; //is 5 secs
		int half_mod = 63*engine_speedup;
		int fase = modu(ticks, mod);

		if (fase > half_mod)
		{
			fase = half_mod - (fase - half_mod);
		}

		return  0.5 *((float)fase / (float)half_mod);
	}
	*/

	static float biggest_float_of(float a, float b)
	{
		if (a > b) {return a;}
		return b;
	}

	static int smallest_int_of(int a, int b)
	{
		if (a > b) {return b;}
		return a;
	}

	static int biggest_int_of(int a, int b)
	{
		if (a < b) {return b;}
		return a;
	}

	static int tile_distance_sq(int ax, int ay, int bx, int by)
	{
		return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
	}

	static float static_lightness(int tile_distance_sq, int light_radius_sq)
	{
		if (light_radius_sq < 1)  {return 0.0;}
		if ( tile_distance_sq < light_radius_sq) {return 1.0;}
		if ( tile_distance_sq == light_radius_sq) {return 1.0;}


		double mod = (double)light_radius_sq / (double)tile_distance_sq;
		return  mod;
	}

	static bool is_even_positive_int(int in)
	{
		if (in < 2) {return false;}

		int compare = in/2;

		if (compare*2 != in) {return false;}

		return true;
	}

	static __int16 save_add_s16(__int16 a, __int16 b, __int32* temp)
	{
		(*temp) = (__int32)a + (__int32)b;

		if((*temp) >  0x7fff) {return  0x7fff;}
		if((*temp) < -0x7fff) {return -0x7fff;}

		return (*temp);
	}

	//used to transcode 8 b/sample to 16b/sample PCM audio
	static float floor_byte_to_sound_float(unsigned char in)
	{

		return (((float)in ) - 0x80) * 0x100;

	}

	static __int16 float_to_s16(float in)
	{

		if(in >  0x7fff)
		{
			return 0x7fff;
		}

		if(in < -0x7fff)
		{
			return -0x7fff;
		}

		return (__int16)in;
	}






};



