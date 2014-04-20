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


#include "levx_mul_threadmail.cpp"

using namespace std;

class file_master
{
	utils util;

	public:

	file_master()
	{}

	int_ucharp get_file(string name)
	{
		int fsize = 0;
		char* f;
		ifstream filestream(name.c_str(), ios::in|ios::binary|ios::ate);

		if (filestream.is_open())
		{
			fsize = filestream.tellg();
			f = new char[fsize];
			filestream.seekg (0, ios::beg);
			filestream.read (f, fsize);
			filestream.close();

			return int_ucharp(fsize, (unsigned char*)f);
		}

		cout << "DDT> Error opening file " << name << endl;
		return int_ucharp();
	}


	int write_file(string name, unsigned char* file, int file_size)
	{
		ofstream filestream(name.c_str(), ios::out|ios::binary);

		if (filestream.is_open())
		{
			filestream.write ( (char*)file, file_size);
			filestream.close();
			return 0;
		}

		cout << "DDT> could not write file " << name << endl;
		return 1;

	}

	int write_file(string name, string txtfile)
	{
		if ((name != "") && (txtfile != ""))
		{
			int txfile_size = txtfile.size();
			unsigned char* txtfile_c = (unsigned char*)txtfile.c_str();
			return write_file(name, txtfile_c, txfile_size);
		}
		return 1;
	}

	int remove_file(string name)
	{
		if( remove( name.c_str() ) != 0 )
		{
			return 1;
		}

		return 0;
	}


	int_string list_and_probe_saves(int game_mode)
	{
		DIR* pdir;
		struct dirent* pent;

		int saves_count = 0;
		string saves = "";

		pdir = opendir("."); //"." refers to the current dir
		if (!pdir){ cout << "DDT> filemaster cant open directory" << endl; return int_string(); }
		//errno=0;

		while( (pent = readdir(pdir)) )
		{
			string entry = pent->d_name;


			if (  util.is_a_sane_savefile_name(entry, game_mode) )
			{

				int_ucharp candidate = get_file(entry);
				if ( candidate.i > ddtsavegame::static_size() -1)
				{

					int candidate_mode = ddtsavegame::get_expantion_mode(candidate.c, candidate.i);

					if ( ddtsavegame::has_file_header(candidate.c, candidate.i) &&
							(candidate_mode == GAME_MODE_CLASSIC || game_mode == GAME_MODE_EXP ) )
					{
						if(game_mode == GAME_MODE_EXP &&
						   candidate_mode == GAME_MODE_CLASSIC &&
						   file_exists( util.add_save_extention( util.remove_save_extention(entry), GAME_MODE_EXP )))
						{
							// we are in hf and have a classic save but a hf save with the same name exists. not processing
							cout << "DDT> Ignoring savegame " << entry << endl;
						}
						else if(!(candidate_mode == GAME_MODE_CLASSIC) &&
						        util.has_specific_save_extention(entry, GAME_MODE_CLASSIC))
						{
							// save extension is not corresponding to binary, not processing
							cout << "DDT> Ignoring savegame " << entry << endl;
						}

						else if(!(candidate_mode == GAME_MODE_EXP) &&
						        util.has_specific_save_extention(entry, GAME_MODE_EXP))
						{
							// save extension is not corresponding to binary, not processing
							cout << "DDT> Ignoring savegame " << entry << endl;
						}
						else
						{
							saves.append(util.int_to_string_leading_zero(  ddtsavegame::get_char_class(candidate.c, candidate.i) )); // add the class number
							saves.push_back('@');
							saves.append(util.int_to_string_leading_zero(  ddtsavegame::get_stars(candidate.c, candidate.i)  )); // add the stars
							saves.push_back('@');
							saves.append(util.int_to_string_leading_zero(  ddtsavegame::get_level(candidate.c, candidate.i)  )); // add the level
							saves.push_back('@');
							saves.append(util.int_to_string_leading_zero(  ddtsavegame::get_diff(candidate.c, candidate.i)  )); // add the diffic
							saves.push_back('@');
							saves.append(util.int_to_string_leading_zero(  ddtsavegame::get_expantion_mode(candidate.c, candidate.i)   )); // add the expantion flag
							saves.push_back('@');
							saves.append(util.int_to_string_leading_zero(  ddtsavegame::get_active_dungeon(candidate.c, candidate.i)   )); // add the expantion flag
							saves.push_back('@');
							saves.append(util.remove_save_extention(entry)); //file name
							saves.push_back('@');

							saves_count++;
						}

					}

					delete[] candidate.c;
				}
			}

		}
		//if (errno) { cout << "DDT> filemaster had something bad happen" << endl; }

		closedir(pdir);

		saves.append("@@@@@@@@@@@@@@@@@@@@@"); //file name

		return int_string(saves_count, saves);
		// rewinddir(pdir);
	}



	bool file_exists(string strFilename)
	{
		struct stat stFileInfo;
		int intStat;

		// Attempt to get the file attributes
		intStat = stat(strFilename.c_str(),&stFileInfo);
		if(intStat == 0)
		{
			// We were able to get the file attributes
			// so the file obviously exists.
			return true;
		}

		return false;
	}

};


class mpq_master
{
	private:

	mpq_archive_s* archive[MAX_MPQ_OPEN];
	string name[MAX_MPQ_OPEN];
	utils util;
	int active;

	public:

	mpq_master()
	{
		active = -1;

		for (int i = 0; i < MAX_MPQ_OPEN; i++)
		{
			name[i] = "";
		}
	}

	void set_mpq(string in)
	{

		//see if archive is open already
		for (int i = 0; i < MAX_MPQ_OPEN; i++)
		{
			if ( name[i] == in)
			{
				active = i;
				return;
			}
		}

		//seems not so lets open it
		for (int i = 0; i < MAX_MPQ_OPEN; i++)
		{
			if ( name[i] == "")
			{
				if (libmpq__archive_open(&(archive[i]), in.c_str(), -1) == 0)
				{
					name[i] = in;
					active = i;
				}
				else
				{
					cout << "DDT> coudn't open mpq archive " << name << endl;
					active = -1;
				}
				return;
			}
		}

		cout << "DDT> coudn't open mpq archive, mpq_master ran out of slots " << endl;
		active = -1;
	}

	void close_all()
	{
		for (int i = 0; i < MAX_MPQ_OPEN; i++)
		{
			if ( !(name[i] == ""))
			{
				libmpq__archive_close(archive[i]);
				name[i] = "";
			}
		}
	}

	int_ucharp get_file(string filename)
	{

		if (active < 0)
		{
			cout << "DDT>  mpq_master is trying to read an unopened mpq" << endl;
			return int_ucharp();
		}

		int64_t output_file_size = 0;
		int64_t transferred = 0;
		unsigned char* output_file;
		unsigned int filenumber = 66666666;
		int32_t file_key = 0;
		string crypto_name = util.strip_windows_file_path(filename);

		libmpq__file_number(archive[active], filename.c_str(), &filenumber);

		if ( filenumber == 66666666)
		{
			cout << "DDT> Can't find file in mpq (" << filename  << ")" << endl;
			return int_ucharp();
		}

		file_key = libmpq__key_from_name( crypto_name.c_str());
		libmpq__file_unpacked_size(archive[active], filenumber, &output_file_size);

		output_file = new unsigned char[output_file_size];
		libmpq__file_read(archive[active], filenumber, output_file, output_file_size, &transferred, file_key);




		return int_ucharp(output_file_size,output_file);
	}
};
