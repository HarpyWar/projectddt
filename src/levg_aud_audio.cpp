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



#include "levg_rnd_render.cpp"

#define MIX_CHANS 16

using namespace std;


class audio_boss
{
	private:

	audio_pak_keeper keeper;
	ddtmutex* mix_mutex;

	int sfx_vol_int;
	float sfx_vol_float;
	int music_vol_int;
	float music_vol_float;

	bool chan_active[MIX_CHANS];
	int chan_sample_pak[MIX_CHANS];
	int chan_sample_slot[MIX_CHANS];
	int chan_sample_off[MIX_CHANS];
	float chan_volume[MIX_CHANS];

	bool music_chan_active;
	int music_chan_sample_off;
	bool story_chan_active;
	int story_chan_sample_off;
	bool story_eligable_to_play;


	float mxtmp;



    public:


	audio_boss()
	{
		sfx_vol_int = 0;
		sfx_vol_float = 0.0;
		music_vol_int = 0;
		music_vol_float = 0;

		for(int i = 0; i < MIX_CHANS; i++) { chan_active[i] = false;}
		music_chan_active = false;
		story_chan_active = false;
		story_eligable_to_play = false;
	}


	void in_thread_init()
	{
		mix_mutex = ddttime::create_mutex();
		ddttime::lock_mutex(mix_mutex);

		init_audio();

		ddttime::unlock_mutex(mix_mutex);
	}

	void init_pak(int pak, int slotcount)
	{
		ddttime::lock_mutex(mix_mutex);

		keeper.init_pak(pak, slotcount);



		for( int i = 0; i < MIX_CHANS; i++)
		{
			if (chan_active[i])
			{
				if((chan_sample_pak[i] == pak) )
				{
					chan_active[i] = false;
				}
			}
		}



		ddttime::unlock_mutex(mix_mutex);

	}

	void load(int pak, int slot, float* file, int fsize)
	{
		ddttime::lock_mutex(mix_mutex);

		if (fsize < 20)
		{
			cout << "DDT>> audio load file too small" << endl;

		}
		else if (slot == -1) //music
		{
			if (fsize == keeper.music.i)
			{
				//same track doing nothing
				delete[] file;
			}
			else
			{
				keeper.music_load(file, fsize);
				music_chan_sample_off = 0;
				music_chan_active = true;
			}
		}
		else if (slot == -2) //story
		{
			keeper.story_load(file, fsize);
			story_chan_sample_off = 0;
			story_chan_active = false;

			if (pak > 0)
			{
				story_eligable_to_play = true;
			}
		}
		else
		{
			keeper.pak_load(pak, slot, file, fsize);

			for( int i = 0; i < MIX_CHANS; i++)
			{
				if (chan_active[i])
				{
					if((chan_sample_pak[i] == pak) && (chan_sample_slot[i] == slot))
					{
						chan_active[i] = false;
					}
				}
			}

		}
		ddttime::unlock_mutex(mix_mutex);
	}

	void play_sfx(int slot)
	{
		play_sfx(PAK_DEFAULT, slot, 10);
	}

	void play_sfx(int pakno, int slot)
	{
		play_sfx(pakno, slot, 10);
	}

	void play_sfx(int pak, int slot, int vol)
	{


		//check if we have a volume
		float v = ddtutils::int_to_float_volume(vol);
		v = v * sfx_vol_float;
		if (v < 0.001){return;}


		ddttime::lock_mutex(mix_mutex);

		//check if we have a subject
		if(keeper.slot_size(pak, slot) < 2)
		{
			ddttime::unlock_mutex(mix_mutex);
			return;
		}


		//check if we have a free chan
		int chan = -1;
		for (int i = 0; (i < MIX_CHANS) && (chan < 0) ; i++)
		{
			if (chan_active[i] == false)
			{
				chan = i;
			}
		}
		if (chan < 0)
		{
			cout << "DDT> not enough chans to play sound!" << endl;
			ddttime::unlock_mutex(mix_mutex);
			return;
		}

		//enqueue for mixing;

		chan_active[chan] = true;
		chan_sample_pak[chan] = pak;
		chan_sample_slot[chan] = slot;
		chan_sample_off[chan] = 0;
		chan_volume[chan] = v;

		ddttime::unlock_mutex(mix_mutex);
	}

	void start_story()
	{
		ddttime::lock_mutex(mix_mutex);
		story_eligable_to_play = true;
		ddttime::unlock_mutex(mix_mutex);
	}

	void stop_story()
	{
		ddttime::lock_mutex(mix_mutex);
		story_eligable_to_play = false;
		story_chan_active = false;
		keeper.kill_story();
		ddttime::unlock_mutex(mix_mutex);
	}




	void check_volume(int sfx_vol, int music_vol)
	{
		if (sfx_vol == sfx_vol_int) {}
		else
		{
			sfx_vol_int = sfx_vol;
			sfx_vol_float = ddtutils::int_to_float_volume(sfx_vol_int);
		}

		if (music_vol == music_vol_int) {}
		else
		{
			music_vol_int = music_vol;
			music_vol_float = ddtutils::int_to_float_volume(music_vol_int);
		}
	}


	void mix_call(int16_t* buff, int buff_size)
	{
		ddttime::lock_mutex(mix_mutex);

		for (int i = 0; i < buff_size; i++)
		{
			mxtmp = 0.0;

			for (int mc = 0; mc < MIX_CHANS; mc++)
			{
				if(chan_active[mc])
				{
					if(chan_sample_off[mc] < keeper.slot_size(chan_sample_pak[mc], chan_sample_slot[mc]) -1 )
					{
						mxtmp
						=
						mxtmp
						+
						keeper.sfx[chan_sample_pak[mc]][chan_sample_slot[mc]].f[chan_sample_off[mc]]
						*
						chan_volume[mc]
						;

						chan_sample_off[mc] ++;
					}
					else
					{
						chan_active[mc] = false; //sound ended
					}
				}
			}

			if(music_chan_active)
			{

				if(music_chan_sample_off < keeper.music.i -1)
				{
					mxtmp
					=
					mxtmp
					+
					keeper.music.f[music_chan_sample_off]
					*
					music_vol_float
					;

					music_chan_sample_off ++;
				}
				else if (keeper.music.i > 1000) //playing finished of an exiting file
				{
					//loop it
					music_chan_sample_off = 0;
				}
				else
				{
					music_chan_active = false;
				}
			}

			if(story_chan_active)
			{
				if (keeper.story.i == 0)
				{}
				else if(story_chan_sample_off < keeper.story.i -1)
				{

					mxtmp
					=
					mxtmp
					+
					keeper.story.f[story_chan_sample_off]
					*
					sfx_vol_float
					;

					story_chan_sample_off ++;


				}
				else
				{
					story_chan_active = false; //sound ended
					keeper.kill_story();
				}
			}
			else if (story_eligable_to_play)
			{
				story_chan_active = true;
				story_chan_sample_off = 0;
			}

			buff[i] = ddtmath::float_to_s16(mxtmp);
		}

		ddttime::unlock_mutex(mix_mutex);
	}

	void mix_call_mute(int16_t* buff, int buff_size)
	{
		ddttime::lock_mutex(mix_mutex);

		for (int i = 0; i < buff_size; i++)
		{

			for (int mc = 0; mc < MIX_CHANS; mc++)
			{
				if(chan_active[mc])
				{
					chan_active[mc] = false; //sound ended
				}
			}

			if(music_chan_active)
			{
				music_chan_active = false;
			}

			if(story_chan_active)
			{
				story_chan_active = false; //sound ended
			}

			buff[i] = 0;
		}

		ddttime::unlock_mutex(mix_mutex);
	}



	void init_audio()
	{

		SDL_AudioSpec desired;
		SDL_AudioSpec obtained;


		desired.freq = 22050;
		desired.format = AUDIO_S16SYS;
		desired.channels = 1;
		desired.samples = 1024;
		desired.userdata = this;
		desired.callback = mix_callback;

		if ( SDL_OpenAudio(&desired, &obtained) < 0 )
		{
			cout << "DDT> audio init error" << endl;
			return;
		}

		if (obtained.format != AUDIO_S16SYS)
		{
			cout << "DDT> audio init wrong format" << endl;
			return;
		}

		if (obtained.freq != 22050)
		{
			cout << "DDT> audio init wrong freq" << endl;
			return;
		}
		if (obtained.channels != 1)
		{
			cout << "DDT> audio init not mono" << endl;
			return;
		}


		SDL_PauseAudio(0);

	}

	static void mix_callback(void *ud, Uint8 *stream, int len)
	{
		audio_boss* master = (audio_boss*)ud;

		if (DEVELOPER_MUTE)
		{
			(*master).mix_call_mute((int16_t*)stream,  len/2);
		}
		else
		{
			(*master).mix_call((int16_t*)stream,  len/2);
		}

	}



};

