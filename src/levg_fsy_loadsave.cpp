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


#include "levg_aud_audio.cpp"

using namespace std;

class loadsave
{
	private:

	utils util;
	file_master fmaster;
	mpq_master mpqmaster;
	staticsloader statload;
	string def_mpq; // the default source of rules files, either xxx.mpq, or 'windows' or 'unix'
	string rules_sep; //the directory separator for finding the rules files
	string defmpq_nexttime;

	mail* post;

	globals* global;


	public:

	loadsave()
	{
		def_mpq = ddtrules::def_archive(); //where the rules should be by default
		rules_sep = "\\"; // mpq's work with the windows separator
		defmpq_nexttime = ddtrules::def_archive();

	}

	void in_thread_init(globals* glob)
	{
		global = glob;
		statload.init(glob);
	}


	void load_config()
	{
		int_ucharp conffile = fmaster.get_file(ddtrules::config_file());

		if (conffile.i < 9)
		{
			cout << "DDT> " << ddtrules::config_file() << " corrupt or nonexistent, rolling with defaults." << endl;
			return;
		}

		bool done = false;
		int configpoint = -1;

		while ( !done && configpoint+20 < conffile.i )
		{
			configpoint++;

			if ( (conffile.c)[configpoint +0] != '<' )
			{
				// just skipping
			}
			else if (
					((conffile.c)[configpoint +1] == 'e') &&
					((conffile.c)[configpoint +2] == 'n') &&
					((conffile.c)[configpoint +3] == 'd') &&
					((conffile.c)[configpoint +4] == '>') )
			{ done = true; }
			else if (
					((conffile.c)[configpoint +1] == 'w') &&
					((conffile.c)[configpoint +2] == 'i') &&
					((conffile.c)[configpoint +3] == 'd') &&
					((conffile.c)[configpoint +4] == 't') &&
					((conffile.c)[configpoint +5] == 'h') &&
					((conffile.c)[configpoint +6] == '>') )
			{
				int value = util.get_int_at(configpoint+8, conffile);
				if (  (value > ORIGINAL_WIDTH -1) && (value < MAX_WIDTH +1))
				{
					(*global).display_w = value;
					(*global).display_w_nexttime = value;
				}
			}
			else if (
					((conffile.c)[configpoint +1] == 'h') &&
					((conffile.c)[configpoint +2] == 'e') &&
					((conffile.c)[configpoint +3] == 'i') &&
					((conffile.c)[configpoint +4] == 'g') &&
					((conffile.c)[configpoint +5] == 'h') &&
					((conffile.c)[configpoint +6] == 't') &&
					((conffile.c)[configpoint +7] == '>') )
			{
				int value = util.get_int_at(configpoint+9, conffile);
				if ((value > ORIGINAL_HEIGHT -1) && (value < MAX_HEIGHT +1))
				{
					(*global).display_h = value;
					(*global).display_h_nexttime = value;
				}
			}
			else if (
					((conffile.c)[configpoint +1] == 'z') &&
					((conffile.c)[configpoint +2] == 'o') &&
					((conffile.c)[configpoint +3] == 'o') &&
					((conffile.c)[configpoint +4] == 'm') &&
					((conffile.c)[configpoint +5] == '>') )
			{
				int value = util.get_int_at(configpoint+7, conffile);
				if ((value > -1) && (value < 11))
				{
					(*global).display_zoom = value;
					(*global).display_zoom_nexttime = value;
				}
			}
			else if (
					((conffile.c)[configpoint +1] == 'g') &&
					((conffile.c)[configpoint +2] == 'a') &&
					((conffile.c)[configpoint +3] == 'm') &&
					((conffile.c)[configpoint +4] == 'm') &&
					((conffile.c)[configpoint +5] == 'a') &&
					((conffile.c)[configpoint +6] == '>') )
			{
				int value = util.get_int_at(configpoint+8, conffile);
				if ((value >  -1) && (value < 11))
				{
					(*global).display_gamma = value;
					(*global).display_gamma_nexttime = value;
				}
			}
			else if (
					((conffile.c)[configpoint +1] == 'a') &&
					((conffile.c)[configpoint +2] == 'l') &&
					((conffile.c)[configpoint +3] == 'p') &&
					((conffile.c)[configpoint +4] == 'h') &&
					((conffile.c)[configpoint +5] == 'a') &&
					((conffile.c)[configpoint +6] == '>') )
			{
				int value = util.get_int_at(configpoint+8, conffile);
				if ((value >  -1) && (value < 11))
				{
					(*global).hud_transp = value;
					(*global).hud_transp_nexttime = value;
				}
			}
			else if (
					((conffile.c)[configpoint +1] == 'b') &&
					((conffile.c)[configpoint +2] == 'l') &&
					((conffile.c)[configpoint +3] == 'e') &&
					((conffile.c)[configpoint +4] == 'n') &&
					((conffile.c)[configpoint +5] == 'd') &&
					((conffile.c)[configpoint+ 6] == '>') )
			{
				int value = util.get_int_at(configpoint+8, conffile);
				(*global).blending = false;
				(*global).blending_nexttime = false;

				if (  value > 0)
				{
					(*global).blending = true;
					(*global).blending_nexttime = true;
				}

			}
			else if (
					((conffile.c)[configpoint +1] == 's') &&
					((conffile.c)[configpoint +2] == 'f') &&
					((conffile.c)[configpoint +3] == 'x') &&
					((conffile.c)[configpoint +4] == '>') )
			{
				int value = util.get_int_at(configpoint+6, conffile);
				if ((value >  -1) && (value < 11))
				{
					(*global).sfx_volume = value;
					(*global).sfx_volume_rollback = value;

				}
			}
			else if (
					((conffile.c)[configpoint +1] == 'm') &&
					((conffile.c)[configpoint +2] == 'u') &&
					((conffile.c)[configpoint +3] == 's') &&
					((conffile.c)[configpoint +4] == 'i') &&
					((conffile.c)[configpoint +5] == 'c') &&
					((conffile.c)[configpoint +6] == '>') )
			{
				int value = util.get_int_at(configpoint+8, conffile);
				if (  (value >  -1) && (value < 11))
				{
					(*global).music_volume = value;
					(*global).music_volume_rollback = value;
				}
			}
			else if (
					((conffile.c)[configpoint +1] == 'a') &&
					((conffile.c)[configpoint +2] == 'u') &&
					((conffile.c)[configpoint +3] == 't') &&
					((conffile.c)[configpoint +4] == 'o') &&
					((conffile.c)[configpoint +5] == 's') &&
					((conffile.c)[configpoint +6] == 'a') &&
					((conffile.c)[configpoint +7] == 'v') &&
					((conffile.c)[configpoint +8] == 'e') &&
					((conffile.c)[configpoint +9] == '>') )
			{
				int value = util.get_int_at(configpoint+11, conffile);
				bool as = false;
				if (value > 0) {as = true;}

				(*global).autosave = as;
				(*global).autosave_rollback = as;
			}

			else if (
					((conffile.c)[configpoint +1] == 'd') &&
					((conffile.c)[configpoint +2] == 'e') &&
					((conffile.c)[configpoint +3] == 'f') &&
					((conffile.c)[configpoint +4] == 'm') &&
					((conffile.c)[configpoint +5] == 'p') &&
					((conffile.c)[configpoint +6] == 'q') &&
					((conffile.c)[configpoint +7] == '>') )
			{
				string value = util.get_argument_at(configpoint+9, conffile);
				if (  value == "unix")
				{
					def_mpq =  "void";
					rules_sep = "/";
					defmpq_nexttime = value;

				}
				else if (  value == "windows")
				{
					def_mpq =  "void";
					rules_sep = "\\";
					defmpq_nexttime = value;

				}
				else // we will be looking inside the mpq
				{
					def_mpq =  value;
					rules_sep = "\\";
					defmpq_nexttime = value;

				}
			}
		}
		delete[] conffile.c;

	}

	void safe_config()
	{
		string out = ddtrules::program_name_and_version();
		out.append(" config file");
		out.append(".\n");
		out.append("\n");
		out.append("<begin> \n");

		out.append("<width>[");
		out.append(util.int_to_string_leading_zero((*global).display_w_nexttime));
		out.append("] \n");

		out.append("<height>[");
		out.append(util.int_to_string_leading_zero((*global).display_h_nexttime));
		out.append("] \n");

		out.append("<zoom>[");
		out.append(util.int_to_string_leading_zero((*global).display_zoom_nexttime));
		out.append("] \n");

		out.append("<gamma>[");
		out.append(util.int_to_string_leading_zero((*global).display_gamma_nexttime));
		out.append("] \n");

		out.append("<alpha>[");
		out.append(util.int_to_string_leading_zero((*global).hud_transp_nexttime));
		out.append("] \n");

		out.append("<sfx>[");
		out.append(util.int_to_string_leading_zero((*global).sfx_volume));
		out.append("] \n");

		out.append("<music>[");
		out.append(util.int_to_string_leading_zero((*global).music_volume));
		out.append("] \n");


		string stringbit = "0";
		if ((*global).autosave) {stringbit = "1";}
		out.append("<autosave>[000");
		out.append(stringbit);
		out.append("] \n");

		stringbit = "0";
		if ((*global).blending_nexttime) {stringbit = "1";}
		out.append("<blend>[000");
		out.append(stringbit);
		out.append("] \n");

		if (def_mpq != ddtrules::def_archive())
		{
			out.append("<defmpq>[");
			out.append(defmpq_nexttime);
			out.append("] \n");
		}

		out.append("<end> \n \n");
		out.append("If you edit this manually, make sure to remember the leading zeros. \n");
		out.append("\n");
		out.append("If you want to load the rules files form another source then ddt.mpq, do the following; \n");
		out.append("Add the line <defmpq>[ddt.mpq] where you replace [ddt.mpq] with: \n");
		out.append("either [alternative_file_name.mpq], \n");
		out.append("or [windows] if you want to load straight from the filesystem on a Windows machine,  \n");
		out.append("or [unix] if you want to load straight from the filesystem on a *nix machine.  \n");
		out.append("Happy modding!\n");

		fmaster.write_file(ddtrules::config_file(), out);


	}


	void load_rules(string rulesname)
	{
		string argument = util.fix_dir_separator(rulesname, rules_sep);

		int_ucharp rules;

		if (def_mpq == "void")
		{
			rules = fmaster.get_file(argument);
		}
		else
		{
			mpqmaster.set_mpq(def_mpq);
			rules = mpqmaster.get_file(argument);
		}

		load_rules(rules);
	}



	void load_rules(int_ucharp rules)
	{


		if (rules.i < 9)
		{
			cout << "DDT> loadsave rules too short or nonexistent, not loading." << endl;
			return;
		}


		bool done = false;
		int rulespoint = -1;
		int pakno = 0;

		while ( !done && rulespoint+20 < rules.i )
		{
			rulespoint++;

			if ( !((rules.c)[rulespoint +0] == '<') )
			{
				// just skipping
			}
			else if (
					((rules.c)[rulespoint +1] == 'e') &&
					((rules.c)[rulespoint +2] == 'n') &&
					((rules.c)[rulespoint +3] == 'd') &&
					((rules.c)[rulespoint +4] == '>') )
			{
				done = true;
			}

			else if (
					((rules.c)[rulespoint + 1] == 'p') &&
					((rules.c)[rulespoint + 2] == 'a') &&
					((rules.c)[rulespoint + 3] == 'k') &&
					((rules.c)[rulespoint + 4] == 'i') &&
					((rules.c)[rulespoint + 5] == 'n') &&
					((rules.c)[rulespoint + 6] == 'i') &&
					((rules.c)[rulespoint + 7] == 't') &&
					((rules.c)[rulespoint + 8] == '_') &&
					((rules.c)[rulespoint + 9] == 'a') &&
					((rules.c)[rulespoint +10] == 'u') &&
					((rules.c)[rulespoint +11] == 'd') &&
					((rules.c)[rulespoint +12] == '>') )
			{

				int pak_size = util.get_int_at(rulespoint+14, rules);
				post = new mail(TRANSCODE_RESET_AUDIO_PAK,pakno, pak_size);
				(*global).threadpush_transcode(post);

			}

			else if (
					((rules.c)[rulespoint + 1] == 'p') &&
					((rules.c)[rulespoint + 2] == 'a') &&
					((rules.c)[rulespoint + 3] == 'k') &&
					((rules.c)[rulespoint + 4] == 'i') &&
					((rules.c)[rulespoint + 5] == 'n') &&
					((rules.c)[rulespoint + 6] == 'i') &&
					((rules.c)[rulespoint + 7] == 't') &&
					((rules.c)[rulespoint + 8] == '_') &&
					((rules.c)[rulespoint + 9] == 'v') &&
					((rules.c)[rulespoint +10] == 'i') &&
					((rules.c)[rulespoint +11] == 'd') &&
					((rules.c)[rulespoint +12] == '>') )
			{
				int pak_size = util.get_int_at(rulespoint+14, rules);
				post = new mail(TRANSCODE_RESET_GRFX_PAK,pakno, pak_size);
				(*global).threadpush_transcode(post);
			}

			else if (
					((rules.c)[rulespoint +1] == 'p') &&
					((rules.c)[rulespoint +2] == 'a') &&
					((rules.c)[rulespoint +3] == 'k') &&
					((rules.c)[rulespoint +4] == 's') &&
					((rules.c)[rulespoint +5] == 'e') &&
					((rules.c)[rulespoint +6] == 't') &&
					((rules.c)[rulespoint +7] == '>') )
			{
				pakno = util.get_int_at(rulespoint+9, rules);

			}

			else if (
					((rules.c)[rulespoint +1] == 'm') &&
					((rules.c)[rulespoint +2] == 'p') &&
					((rules.c)[rulespoint +3] == 'q') &&
					((rules.c)[rulespoint +4] == 's') &&
					((rules.c)[rulespoint +5] == 'e') &&
					((rules.c)[rulespoint +6] == 't') &&
					((rules.c)[rulespoint +7] == '>') )
			{
				string arg = util.get_argument_at(rulespoint+9, rules);
				mpqmaster.set_mpq(arg);
			}
			else if (
					((rules.c)[rulespoint +1] == 'p') &&
					((rules.c)[rulespoint +2] == 'a') &&
					((rules.c)[rulespoint +3] == 'l') &&
					((rules.c)[rulespoint +4] == '>') )
			{
				int keeperno = util.get_int_at(rulespoint+6, rules);
				string arg = util.get_argument_at(rulespoint+12, rules);
				int_ucharp pal = mpqmaster.get_file(arg);

				ddtpal::add_gamma(pal.c, pal.i, (*global).display_gamma);

				(*global).palkeep.set_pal(keeperno, pal);

			}
			else if (
					((rules.c)[rulespoint +1] == 'p') &&
					((rules.c)[rulespoint +2] == 'a') &&
					((rules.c)[rulespoint +3] == 'l') &&
					((rules.c)[rulespoint +4] == '_') &&
					((rules.c)[rulespoint +5] == 'o') &&
					((rules.c)[rulespoint +6] == 'o') &&
					((rules.c)[rulespoint +7] == 'z') &&
					((rules.c)[rulespoint +8] == 'e') &&
					((rules.c)[rulespoint +9] == '>') )
			{
				int keeperno = util.get_int_at(rulespoint+11, rules);
				int move = util.get_int_at(rulespoint+17, rules);
				string arg = util.get_argument_at(rulespoint+23, rules);
				int_ucharp pal = mpqmaster.get_file(arg);

				ddtpal::move_ooze(pal.c, pal.i, move);
				ddtpal::add_gamma(pal.c, pal.i, (*global).display_gamma);

				(*global).palkeep.set_pal(keeperno, pal);

			}
			else if (
					((rules.c)[rulespoint +1] == 's') &&
					((rules.c)[rulespoint +2] == 'f') &&
					((rules.c)[rulespoint +3] == 'x') &&
					((rules.c)[rulespoint +4] == '>') )
			{
				int keeperno = util.get_int_at(rulespoint+6, rules);
				string arg = util.get_argument_at(rulespoint+12, rules);
				int_ucharp sound = mpqmaster.get_file(arg);

				post = new mail(TRANSCODE_AUDIO,pakno,keeperno,sound.c, sound.i);
				(*global).threadpush_transcode(post);
				//cout << "read audio " << arg << endl;


			}

			else if (
					((rules.c)[rulespoint +1] == 'g') &&
					((rules.c)[rulespoint +2] == 'r') &&
					((rules.c)[rulespoint +3] == 'f') &&
					((rules.c)[rulespoint +4] == 'x') &&
					((rules.c)[rulespoint +5] == '>') )

			{
				int keeperno =  	util.get_int_at(rulespoint+7, rules);
				string allog = 		util.get_argument_at(rulespoint+13, rules);
				int x_size = 		util.get_int_at(rulespoint+19, rules);
				int y_size = 		util.get_int_at(rulespoint+25, rules);
				int palno = 		util.get_int_at(rulespoint+31, rules);
				int frames = 		util.get_int_at(rulespoint+37, rules);
				int alpha_byte = 	util.get_int_at(rulespoint+43, rules);
				string chunkyness = util.get_argument_at(rulespoint+49, rules);
				int x_move = 		util.get_int_at(rulespoint+55, rules);
				int y_move = 		util.get_int_at(rulespoint+61, rules);
				string arg = 		util.get_argument_at(rulespoint+67, rules);
				int_ucharp gfile =  mpqmaster.get_file(arg);

				int algint = -1;
				if		(allog == "town") {algint = TOWN_CEL;}
				else if (allog == "icel") {algint = INDEXED_CEL;}
				else if (allog == "icl2") {algint = INDEXED_CLT;}
				else if (allog == "dcel") {algint = DOUBLE_INDEXED_CEL;}
				else if (allog == "dcl2") {algint = DOUBLE_INDEXED_CLT ;}
				else if (allog == "pcx8") {algint = PCX;}
				else if (allog == "objc") {algint = OBJCURS;}
				else
				{
					cout << "DDT> Wrong alog for TRANSCODE_GRFX decoding " << arg << endl;
					return;
				}

				int chunkint = CHUNKY_DEFUALT;

				if (chunkyness == "line") { chunkint =  CHUNKY_LINEAR;}
				if (chunkyness == "maxi") { chunkint =  CHUNKY_MAXI;}
				if (chunkyness == "smoo") { chunkint =  CHUNKY_SMOOTH;}


				// see if x_move is auto
				if (util.get_argument_at(rulespoint+55, rules) == "auto")
				{
						x_move = 0.5*(64 - x_size);
				}

				post = new mail(TRANSCODE_GRFX,pakno, keeperno,algint,x_size,y_size,palno,frames,alpha_byte,chunkint,x_move,y_move,gfile.i,gfile.c,0,NULL);
				(*global).threadpush_transcode(post);


			}
			else if (
					((rules.c)[rulespoint +1] == 'g') &&
					((rules.c)[rulespoint +2] == 'r') &&
					((rules.c)[rulespoint +3] == 'f') &&
					((rules.c)[rulespoint +4] == 'm') &&
					((rules.c)[rulespoint +5] == '>') )

			{
				int keeperno =  	util.get_int_at(rulespoint+7, rules);
				string allog = 		util.get_argument_at(rulespoint+13, rules);
				int x_size = 		util.get_int_at(rulespoint+19, rules);
				int y_size = 		util.get_int_at(rulespoint+25, rules);
				int palno = 		util.get_int_at(rulespoint+31, rules);
				int frames = 		util.get_int_at(rulespoint+37, rules);
				int alpha_byte = 	util.get_int_at(rulespoint+43, rules);
				string chunkyness = util.get_argument_at(rulespoint+49, rules);
				int x_move = 		util.get_int_at(rulespoint+55, rules);
				int y_move = 		util.get_int_at(rulespoint+61, rules);
				int map =           util.get_int_at(rulespoint+67, rules);
				string arg = 		util.get_argument_at(rulespoint+73, rules);
				int_ucharp gfile =  mpqmaster.get_file(arg);

				int algint = -1;
				if		(allog == "town") {algint = TOWN_CEL;}
				else if (allog == "icel") {algint = INDEXED_CEL;}
				else if (allog == "icl2") {algint = INDEXED_CLT;}
				else if (allog == "dcel") {algint = DOUBLE_INDEXED_CEL;}
				else if (allog == "dcl2") {algint = DOUBLE_INDEXED_CLT ;}
				else if (allog == "pcx8") {algint = PCX;}
				else if (allog == "objc") {algint = OBJCURS;}
				else
				{
					cout << "DDT> Wrong alog for TRANSCODE_GRFX decoding " << arg << endl;
					return;
				}

				int chunkint = CHUNKY_DEFUALT;

				if (chunkyness == "line") { chunkint =  CHUNKY_LINEAR;}
				if (chunkyness == "maxi") { chunkint =  CHUNKY_MAXI;}
				if (chunkyness == "smoo") { chunkint =  CHUNKY_SMOOTH;}


				// see if x_move is auto
				if (util.get_argument_at(rulespoint+55, rules) == "auto")
				{
						x_move = 0.5*(64 - x_size);
				}

				post = new mail(TRANSCODE_GRFX,pakno, keeperno,algint,x_size,y_size,palno,frames,alpha_byte,chunkint,x_move,y_move,gfile.i,gfile.c,0,NULL, map);
				(*global).threadpush_transcode(post);


			}
			else if (
					((rules.c)[rulespoint +1] == 'g') &&
					((rules.c)[rulespoint +2] == 'r') &&
					((rules.c)[rulespoint +3] == 'f') &&
					((rules.c)[rulespoint +4] == 'x') &&
					((rules.c)[rulespoint +5] == 'u') &&
					((rules.c)[rulespoint +6] == '>') )

			{
				int keeperno =  util.get_int_at(rulespoint+8, rules);

				post = new mail(TRANSCODE_UNLOAD_GRFX, pakno, keeperno);
				(*global).threadpush_transcode(post);


			}
			else if (
					((rules.c)[rulespoint +1] == 'u') &&
					((rules.c)[rulespoint +2] == 'i') &&
					((rules.c)[rulespoint +3] == 'f') &&
					((rules.c)[rulespoint +4] == 'u') &&
					((rules.c)[rulespoint +5] == 's') &&
					((rules.c)[rulespoint +6] == 'e') &&
					((rules.c)[rulespoint +7] == '>') )
			{
				int keeperno =  	util.get_int_at(rulespoint+9, rules);
				string allog = 		util.get_argument_at(rulespoint+15, rules);
				int palno = 		util.get_int_at(rulespoint+21, rules);

				int_ucharp gfile_a;// =  fmaster.get_mpq_file(arg);
				int_ucharp gfile_b;

				int algint = -1;
				if		(allog == "orbs")
				{
					algint = UIFUSE_ORBS;
					gfile_a = mpqmaster.get_file("ctrlpan\\panel8.cel");
					gfile_b = mpqmaster.get_file("ctrlpan\\p8bulbs.cel");
				}
				else if (allog == "stsh")
				{
					algint = UIFUSE_STASH;
					gfile_a = mpqmaster.get_file("data\\quest.cel");
					gfile_b = mpqmaster.get_file("data\\inv\\inv.cel");
				}
				else
				{
					cout << "DDT> Wrong alog for UIFUSE decoding " << endl;
					return;
				}
				post = new mail(TRANSCODE_GRFX,pakno,keeperno,algint,666,666,palno,666,666,666,666,666,gfile_a.i,gfile_a.c,gfile_b.i,gfile_b.c);
				(*global).threadpush_transcode(post);

			}
			else if (
					((rules.c)[rulespoint +1] == 'd') &&
					((rules.c)[rulespoint +2] == 'a') &&
					((rules.c)[rulespoint +3] == 't') &&
					((rules.c)[rulespoint +4] == 'a') &&
					((rules.c)[rulespoint +5] == 'b') &&
					((rules.c)[rulespoint +6] == 'l') &&
					((rules.c)[rulespoint +7] == 'o') &&
					((rules.c)[rulespoint +8] == 'c') &&
					((rules.c)[rulespoint +9] == 'k') &&
					((rules.c)[rulespoint +10]== '>') )
			{

				int mark  =  		util.get_int_at(rulespoint+12, rules);
				string allog = 		util.get_argument_at(rulespoint+18, rules);



				int blockoff = rulespoint + 18 + allog.size() +1 ;

				//lets get the size of this block
				int block_size = 0;
				bool block_size_found = false;
				int clist_point = blockoff;
				while (clist_point < rules.i && !block_size_found)
				{
					if (
							(rules.c)[clist_point + 0] == '<' &&
							(rules.c)[clist_point + 1] == 'd' &&
							(rules.c)[clist_point + 2] == 'a' &&
							(rules.c)[clist_point + 3] == 't' &&
							(rules.c)[clist_point + 4] == 'a' &&
							(rules.c)[clist_point + 5] == 'b' &&
							(rules.c)[clist_point + 6] == 'l' &&
							(rules.c)[clist_point + 7] == 'o' &&
							(rules.c)[clist_point + 8] == 'c' &&
							(rules.c)[clist_point + 9] == 'k' &&
							(rules.c)[clist_point +10] == '_' &&
							(rules.c)[clist_point +11] == 'e' &&
							(rules.c)[clist_point +12] == 'n' &&
							(rules.c)[clist_point +13] == 'd' &&
							(rules.c)[clist_point +14] == '>' )


					{
						block_size_found = true;
					}
					else
					{
						block_size++;

					}

					clist_point ++;
				}

				unsigned char* block = new unsigned char[block_size];
				clist_point = blockoff;

				for(int i = 0; i < block_size;)
				{
					block[i] = (rules.c)[clist_point];
					clist_point ++;
					i++;
				}



				if (allog == "credits")
				{
					post = new mail(MOUSEKEYB_UPDATE_CREDITS, mark, block, block_size);
					(*global).threadpush_mousekeyb(post);
				}
				else if (allog == "classlist")
				{
					post = new mail(MOUSEKEYB_UPDATE_CLASSLIST, mark, block, block_size);
					(*global).threadpush_mousekeyb(post);

				}
				else if (allog == "story")
				{
					post = new mail(MOUSEKEYB_SET_STORY, mark, block, block_size);
					(*global).threadpush_mousekeyb(post);

				}
				else if (allog == "level")
				{
					post = new mail(WORLD_LOAD_LEVEL, block, block_size);
					(*global).threadpush_world(post);
				}
				else if (allog == "class")
				{
					post = new mail(WORLD_LOAD_CLASS, block, block_size);
					(*global).threadpush_world(post);
				}

				else if (allog == "monster")
				{
					statload.load_monster(mark, block, block_size);
				}
				else if (allog == "mechanic")
				{
					statload.load_mechanic(mark, block, block_size);
				}
				else if (allog == "dunlook")
				{
					statload.load_dunlook(mark, block, block_size);
				}
				else if (allog == "dungeon")
				{
					statload.load_dungeon(mark, block, block_size);
				}
				else if (allog == "valuemap")
				{
					statload.load_valuemap(mark, block, block_size);
				}
				else if (allog == "itemtype")
				{
					statload.load_itemtype(mark, block, block_size);

				}
				else if (allog == "sectorfix")
				{
					(*global).sectorfix.set(mark, block, block_size);

				}


				rulespoint = rulespoint + block_size + 11; // 11 bing the <datablock> header size

			}

			else if (
					((rules.c)[rulespoint +1] == 'r') &&
					((rules.c)[rulespoint +2] == 'u') &&
					((rules.c)[rulespoint +3] == 'l') &&
					((rules.c)[rulespoint +4] == 'e') &&
					((rules.c)[rulespoint +5] == 's') &&
					((rules.c)[rulespoint +6] == '>') )
			{
				string arg = util.get_argument_at(rulespoint+8, rules);

				post = new mail(FILEIO_LOAD_RULES, arg);
				(*global).threadpush_filesystem(post);


			}

			else if (
					((rules.c)[rulespoint + 1] == 'd') &&
					((rules.c)[rulespoint + 2] == 'i') &&
					((rules.c)[rulespoint + 3] == '_') &&
					((rules.c)[rulespoint + 4] == 'o') &&
					((rules.c)[rulespoint + 5] == 'n') &&
					((rules.c)[rulespoint + 6] == 'l') &&
					((rules.c)[rulespoint + 7] == 'y') &&
					((rules.c)[rulespoint + 8] == '>') )
			{

				if ((*global).game_mode != GAME_MODE_CLASSIC)
				{
					rulespoint  = rulespoint + 11;
				}


			}

			else if (
					((rules.c)[rulespoint + 1] == 'h') &&
					((rules.c)[rulespoint + 2] == 'f') &&
					((rules.c)[rulespoint + 3] == '_') &&
					((rules.c)[rulespoint + 4] == 'o') &&
					((rules.c)[rulespoint + 5] == 'n') &&
					((rules.c)[rulespoint + 6] == 'l') &&
					((rules.c)[rulespoint + 7] == 'y') &&
					((rules.c)[rulespoint + 8] == '>') )
			{

				if ((*global).game_mode != GAME_MODE_EXP)
				{
					rulespoint  = rulespoint + 11;
				}


			}

			else if (
					((rules.c)[rulespoint + 1] == 'i') &&
					((rules.c)[rulespoint + 2] == 'f') &&
					((rules.c)[rulespoint + 3] == '_') &&
					((rules.c)[rulespoint + 4] == 'c') &&
					((rules.c)[rulespoint + 5] == 'l') &&
					((rules.c)[rulespoint + 6] == 'a') &&
					((rules.c)[rulespoint + 7] == 's') &&
					((rules.c)[rulespoint + 8] == 's') &&
					((rules.c)[rulespoint + 9] == '>') )
			{

				int classno  =  util.get_int_at(rulespoint+11, rules);
				if ((*global).player.class_number == classno)
				{
					//match
				}
				else
				{
					rulespoint  = rulespoint + 22;
					//no match
				}
			}

			else if (
					((rules.c)[rulespoint + 1] == 'b') &&
					((rules.c)[rulespoint + 2] == 'l') &&
					((rules.c)[rulespoint + 3] == 'o') &&
					((rules.c)[rulespoint + 4] == 'b') &&
					((rules.c)[rulespoint + 5] == '_') &&
					((rules.c)[rulespoint + 6] == 's') &&
					((rules.c)[rulespoint + 7] == 't') &&
					((rules.c)[rulespoint + 8] == 'o') &&
					((rules.c)[rulespoint + 9] == 'r') &&
					((rules.c)[rulespoint +10] == 'y') &&
					((rules.c)[rulespoint +11] == '>') )
			{

				int storyno  =  util.get_int_at(rulespoint+13, rules);
				post = new mail(MOUSEKEYB_SET_BLOB_STORY, storyno);
				(*global).threadpush_mousekeyb(post);
			}

			else if (
					((rules.c)[rulespoint + 1] == 'm') &&
					((rules.c)[rulespoint + 2] == 'o') &&
					((rules.c)[rulespoint + 3] == 'v') &&
					((rules.c)[rulespoint + 4] == 'e') &&
					((rules.c)[rulespoint + 5] == '_') &&
					((rules.c)[rulespoint + 6] == 'l') &&
					((rules.c)[rulespoint + 7] == 'm') &&
					((rules.c)[rulespoint + 8] == 's') &&
					((rules.c)[rulespoint + 9] == 'g') &&
					((rules.c)[rulespoint +10] == '_') &&
					((rules.c)[rulespoint +11] == 'y') &&
					((rules.c)[rulespoint +12] == '>') )
			{

				int mark  =  util.get_int_at(rulespoint+14, rules);

				post = new mail(MOUSEKEYB_MOVE_LOADMSG_Y, mark);
				(*global).threadpush_mousekeyb(post);

			}

			else if (
					((rules.c)[rulespoint + 1] == 's') &&
					((rules.c)[rulespoint + 2] == 'e') &&
					((rules.c)[rulespoint + 3] == 'c') &&
					((rules.c)[rulespoint + 4] == '_') &&
					((rules.c)[rulespoint + 5] == 'f') &&
					((rules.c)[rulespoint + 6] == 'i') &&
					((rules.c)[rulespoint + 7] == 'x') &&
					((rules.c)[rulespoint + 8] == '>') )
			{

				int fix  =  util.get_int_at(rulespoint+10, rules);
				post = new mail(WORLD_SECTOR_HOTFIX, fix);
				(*global).threadpush_world(post);


			}

		}

		delete[] rules.c;

	}

	void get_savelist()
	{
		int_string result = fmaster.list_and_probe_saves((*global).game_mode);


		post = new mail(MOUSEKEYB_UPDATE_SAVELIST, result.i, result.s);
		(*global).threadpush_mousekeyb(post);


	}

	int check_game_mode()
	{
		if ((!fmaster.file_exists(ddtrules::def_archive())) || (!fmaster.file_exists(ddtblob::blob_name())) )
		{
			cout << "DDT> critical files not detected....." << endl;
			return GAME_MODE_UNSET;
		}

		if (! fmaster.file_exists(ddtrules::classic_archive()))
		{
			cout << "DDT> No classic archive file detected, aborting....." << endl;
			return GAME_MODE_UNSET;
		}

		if (
				fmaster.file_exists(ddtrules::exp_archive()) &&
				fmaster.file_exists(ddtrules::exp_class_archive()) &&
				fmaster.file_exists(ddtrules::exp_voice_archive()) &&
				fmaster.file_exists(ddtrules::exp_music_archive())
			)
		{
			cout << "DDT> Expantion expansion detected...." << endl;
			return GAME_MODE_EXP;
		}

		cout << "DDT> Classic game without expansion detected...." << endl;
		return GAME_MODE_CLASSIC;

	}

	void write_save(unsigned char* save, int save_size)
	{

		string save_name =  util.add_save_extention((*global).player.char_name.get(), (*global).game_mode);
		int write_fail = fmaster.write_file(save_name, save, save_size);

		if (write_fail == 1)
		{
			cout << "DDT> Can't write save file " << save_name << endl;
			cout << "DDT> Check the directory permissions" << endl;
			(*global).quit_game = true;
			return;
		}

		(*global).threadpush_world(new mail(WORLD_SAVEGAME_IS_WRITTEN));



	}

	void remove_save(string name, int mode)
	{
		string fname = util.add_save_extention(name, mode);
		int del_fail = fmaster.remove_file(fname);

		if (del_fail == 1)
		{
			cout << "DDT> Can't delete save file " << name << endl;
			cout << "DDT> Check the directory permissions" << endl;
			(*global).quit_game = true;
		}

	}

	void load_save()
	{

		string save_name = util.add_save_extention(   (*global).player.char_name.get(), (*global).ondisk_savegame_mode);
		int_ucharp save = fmaster.get_file(save_name);

		if (save.i < 20)
		{
			cout << "DDT> Can't load save file " << save_name << endl;
			cout << "DDT> Check the directory permissions" << endl;
			(*global).quit_game = true;
		}
		else
		{
			post = new mail(WORLD_LOAD_SAVE, save.c, save.i);
			(*global).threadpush_world(post);

		}

	}

	void load_blob()
	{
		int_ucharp b = fmaster.get_file(ddtblob::blob_name());
		(*global).binblob.set(b.c, b.i);
	}

};
