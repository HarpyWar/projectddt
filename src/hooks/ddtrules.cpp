#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

class ddtrules
{
	public:

	static string program_name()
	{
		return "Project DDT";
	}

	static string program_name_and_version()
	{
		return "Project DDT 2011.07.21 Alpha Zero";
	}

	static string def_archive()
	{
		return "ddt.mpq";
	}

	static string classic_archive()
	{
		return "diabdat.mpq";
	}

	static string exp_archive()
	{
		return "hellfire.mpq";
	}

	static string exp_class_archive()
	{
		return "hfmonk.mpq";
	}

	static string exp_music_archive()
	{
		return "hfmusic.mpq";
	}

	static string exp_voice_archive()
	{
		return "hfvoice.mpq";
	}

	static string config_file()
	{
		return "ddtconfig.txt";
	}

	static string start()
	{
		return "ddtmpq?start?start.r";
	}

	static string intro_music()
	{
		return "ddtmpq?bgs?intromus.r";
	}


	static string def_bg()
	{
		return "ddtmpq?bgs?menubg.r";
	}

	static string cred_diab()
	{
		return "ddtmpq?bgs?creddiab.r";
	}

	static string cred_ddt()
	{
		return "ddtmpq?bgs?credddt.r";
	}

	static string cred_hf()
	{
		return "ddtmpq?bgs?credhf.r";
	}

	static string gameselect_bg()
	{
		return "ddtmpq?bgs?gameselect.r";
	}

	static string gametype_bg()
	{
		return "ddtmpq?bgs?gametype.r";
	}

	static string clear_bg()
	{
		return "ddtmpq?bgs?clearbg.r";
	}

	static string pals()
	{
		return "ddtmpq?statics?pals.r";
	}
	static string monsters()
	{
		return "ddtmpq?statics?monsters.r";
	}
	static string mechs()
	{
		return "ddtmpq?statics?mech.r";
	}
	static string dunlooks()
	{
		return "ddtmpq?statics?dunlook.r";
	}
	static string dungeons()
	{
		return "ddtmpq?statics?dungeons.r";
	}
	static string valuemap()
	{
		return "ddtmpq?statics?valuemap.r";
	}

	static string sectorfix()
	{
		return "ddtmpq?statics?secfix.r";
	}

	static string itemtype()
	{
		return "ddtmpq?statics?itemtype.r";
	}

	static string classlist()
	{
		return "ddtmpq?class?list.r";
	}




};
