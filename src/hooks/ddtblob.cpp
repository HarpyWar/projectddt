#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <stdint.h>
#include <string>

using namespace std;

class ddtblob
{
	public:

	static int blob_size()
	{
		return 859136;
	}

	static string blob_name()
	{
		return "hellfire.exe";
	}


	static bool check(unsigned char* bl, int bl_size)
	{
		if (bl_size != blob_size())
		{
			cout << "DDT> "<<blob_name() << " size fail" << bl_size << " " << blob_size() << endl;
			return false;
		}

		if (bl[0xd1b40] != 0x74)
		{
			cout << "DDT> "<<blob_name() << "data fail" << (int)bl[0xd1b40] << " " << (int)0x74 << endl;
			return false;
		}

		//generate_ref(0x9e345, bl, bl_size);

		return true;
		//generate_ref(0x9e345, bl, bl_size);

	}


	static string get_game_name(int name, unsigned char* bl, int bl_size)
	{
		switch(name)
		{
		case   0 : return get_entry(0xb5680, bl, bl_size); // Classic
		case   1 : return get_entry(0xb2430, bl, bl_size); // Exp
		}

		return "Unknown Game version";
	}

	static string get_greeting(unsigned char* bl, int bl_size)
	{

		string out;

		out.append(1, get_char(0xcf51c, bl, bl_size));
		out.append(1, get_char(0xcf51e, bl, bl_size));
		out.append(1, get_char(0xcf520, bl, bl_size));
		out.append(1, get_char(0xcf522, bl, bl_size));
		out.append(1, get_char(0xcf524, bl, bl_size));
		out.append(1, get_char(0xcf526, bl, bl_size));
		out.append(1, get_char(0xcf528, bl, bl_size));
		out.append(1, get_char(0xcf52a, bl, bl_size));
		out.append(1, get_char(0xcf52c, bl, bl_size));
		out.append(1, get_char(0xcf542, bl, bl_size));
		out.append(1, get_char(0xce282, bl, bl_size));
		out.append(1, get_char(0xd137a, bl, bl_size));
		out.append(1, get_char(0xcf51e, bl, bl_size));
		out.append(1, get_char(0xcf520, bl, bl_size));
		out.append(1, get_char(0xcf522, bl, bl_size));
		out.append(1, get_char(0xcf524, bl, bl_size));
		out.append(1, get_char(0xd05f6, bl, bl_size));
		out.append(1, get_char(0xcf542, bl, bl_size));
		out.append(1, get_char(0xcf548, bl, bl_size));
		out.append(1, get_char(0xcf54a, bl, bl_size));
		out.append(1, get_char(0xcf54c, bl, bl_size));
		out.append(1, get_char(0xd185a, bl, bl_size));
		out.append(1, get_char(0xcf542, bl, bl_size));
		out.append(1, get_char(0xcf554, bl, bl_size));
		out.append(1, get_char(0xcf5e6, bl, bl_size));
		out.append(1, get_char(0xd1b3e, bl, bl_size));
		out.append(1, get_char(0xd0f82, bl, bl_size));
		out.append(1, get_char(0xd0f82, bl, bl_size));
		out.append(1, get_char(0xd155c, bl, bl_size));
		out.append(1, get_char(0xcf524, bl, bl_size));
		out.append(1, get_char(0xd156e, bl, bl_size));
		out.append(1, get_char(0xcf542, bl, bl_size));
		out.append(1, get_char(0xd1b3a, bl, bl_size));
		out.append(1, get_char(0xd1b12, bl, bl_size));
		out.append(1, get_char(0xcf52c, bl, bl_size));
		out.append(1, get_char(0xcf72a, bl, bl_size));
		out.append(1, get_char(0xcf524, bl, bl_size));
		out.append(1, get_char(0xcf52c, bl, bl_size));
		out.append(1, get_char(0xd155c, bl, bl_size));
		out.append(1, get_char(0xd1b3e, bl, bl_size));
		out.append(1, get_char(0xcf748, bl, bl_size));
		out.append(1, get_char(0xcf4f2, bl, bl_size));
		out.append(1, get_char(0xcf72a, bl, bl_size));
		out.append(1, get_char(0xcf748, bl, bl_size));
		out.append(1, get_char(0xcf52c, bl, bl_size));

		return out;


	}


	static string get_class_name(int name, unsigned char* bl, int bl_size)
	{
		switch(name)
		{
		case  0 : return get_entry(0xb493c, bl, bl_size); // Classic 0
		case  1 : return get_entry(0xb4934, bl, bl_size); // Classic 1
		case  2 : return get_entry(0xb4928, bl, bl_size); // Classic 2
		case  3 : return get_entry(0xb4920, bl, bl_size); // Exp 3
		case  4 : return get_entry(0xb4918, bl, bl_size); // Exp 4
		case  5 : return get_entry(0xb490c, bl, bl_size); // Exp 5
		}

		return "Unknown Class";
	}


	static string get_monster_name(int name, unsigned char* bl, int bl_size)
	{
		switch(name)
		{

		//Establishment inhabitants
		case   0 : return get_entry(0xb1fa8, bl, bl_size); // Bad Monster
		case   1 : return get_entry(0xb0cbc, bl, bl_size); // Your pet
		case   2 : return get_entry(0xca230, bl, bl_size); // Scary lady
		case   3 : return get_entry(0xca2d8, bl, bl_size); // Old man Identified
		case   4 : return get_entry(0xca370, bl, bl_size); // Crossdresser
		case   5 : return get_entry(0xca3b8, bl, bl_size); // Little Girl
		case   6 : return get_entry(0xca324, bl, bl_size); // Animal
		case   7 : return get_entry(0xb74d8, bl, bl_size); // Addict
		case   8 : return get_entry(0xca25c, bl, bl_size); // Waitress
		case   9 : return get_entry(0xca19c, bl, bl_size); // Smith
		case  10 : return get_entry(0xca340, bl, bl_size); // Landworker
		case  11 : return get_entry(0xca1d0, bl, bl_size); // Hotel Owner
		case  12 : return get_entry(0xca2a8, bl, bl_size); // Doctor
		case  13 : return get_entry(0xca3f0, bl, bl_size); // Deadguy
		case  14 : return get_entry(0xb73d8, bl, bl_size); // Old man Unidentified
		case  15 : return get_entry(0xb7328, bl, bl_size); // Profeteer
		case  16 : return get_entry(0xca200, bl, bl_size); // Not yet dead guy

		// Monsters with A
		case 100 : return get_entry(0xb0560, bl, bl_size);
		case 101 : return get_entry(0xb0fac, bl, bl_size);
		case 102 : return get_entry(0xb06d4, bl, bl_size);
		case 103 : return get_entry(0xb0cfc, bl, bl_size);
		case 104 : return get_entry(0xb16fc, bl, bl_size);
		case 105 : return get_entry(0xb0af8, bl, bl_size);

		// Monsters with B
		case 200 : return get_entry(0xaff50, bl, bl_size);
		case 201 : return get_entry(0xb00e0, bl, bl_size);
		case 202 : return get_entry(0xb01bc, bl, bl_size);
		case 203 : return get_entry(0xb01d8, bl, bl_size);
		case 204 : return get_entry(0xb0140, bl, bl_size);
		case 205 : return get_entry(0xb0164, bl, bl_size);
		case 206 : return get_entry(0xb0170, bl, bl_size);
		case 207 : return get_entry(0xb021c, bl, bl_size);
		case 208 : return get_entry(0xb030c, bl, bl_size);
		case 209 : return get_entry(0xb0328, bl, bl_size);
		case 210 : return get_entry(0xb0344, bl, bl_size);
		case 211 : return get_entry(0xb044c, bl, bl_size);
		case 212 : return get_entry(0xb045c, bl, bl_size);
		case 213 : return get_entry(0xb1818, bl, bl_size);
		case 214 : return get_entry(0xb1ab8, bl, bl_size);
		case 215 : return get_entry(0xb1ee8, bl, bl_size);
		case 216 : return get_entry(0xaffe0, bl, bl_size);
		case 217 : return get_entry(0xb004c, bl, bl_size);
		case 218 : return get_entry(0xb0094, bl, bl_size);
		case 219 : return get_entry(0xb0104, bl, bl_size);
		case 220 : return get_entry(0xb0258, bl, bl_size);
		case 221 : return get_entry(0xb0f60, bl, bl_size);
		case 222 : return get_entry(0xb068c, bl, bl_size);
		case 223 : return get_entry(0xb06fc, bl, bl_size);
		case 224 : return get_entry(0xb1c08, bl, bl_size);
		case 225 : return get_entry(0xb02b8, bl, bl_size);
		case 226 : return get_entry(0xb0370, bl, bl_size);
		case 227 : return get_entry(0xb1d84, bl, bl_size);
		case 228 : return get_entry(0xb04dc, bl, bl_size);
		case 229 : return get_entry(0xb04f4, bl, bl_size);
		case 230 : return get_entry(0xb0544, bl, bl_size);
		case 231 : return get_entry(0xb0ee4, bl, bl_size);
		case 232 : return get_entry(0xb04a8, bl, bl_size);
		case 233 : return get_entry(0xb113c, bl, bl_size);
		case 234 : return get_entry(0xb106c, bl, bl_size);

		// Monsters with C
		case 300 : return get_entry(0xb1e58, bl, bl_size);
		case 301 : return get_entry(0xb1b84, bl, bl_size);
		case 302 : return get_entry(0xb1520, bl, bl_size);
		case 303 : return get_entry(0xb1024, bl, bl_size);
		case 304 : return get_entry(0xb0730, bl, bl_size);
		case 305 : return get_entry(0xb01a8, bl, bl_size);
		case 306 : return get_entry(0xb1ad0, bl, bl_size);
		case 307 : return get_entry(0xb1d94, bl, bl_size);
		case 308 : return get_entry(0xb0d74, bl, bl_size);
		case 309 : return get_entry(0xb0d24, bl, bl_size);

		// Monsters with D
		case 400 : return get_entry(0xb5680, bl, bl_size);
		case 401 : return get_entry(0xaff20, bl, bl_size);
		case 402 : return get_entry(0xb1e24, bl, bl_size);
		case 403 : return get_entry(0xb1e4c, bl, bl_size);
		case 404 : return get_entry(0xb1508, bl, bl_size);
		case 405 : return get_entry(0xb1514, bl, bl_size);
		case 406 : return get_entry(0xb12a4, bl, bl_size);
		case 407 : return get_entry(0xb1114, bl, bl_size);
		case 408 : return get_entry(0xb0f38, bl, bl_size);
		case 409 : return get_entry(0xb02cc, bl, bl_size);
		case 410 : return get_entry(0xb0190, bl, bl_size);
		case 411 : return get_entry(0xb014c, bl, bl_size);
		case 412 : return get_entry(0xafff4, bl, bl_size);
		case 413 : return get_entry(0xaffa8, bl, bl_size);
		case 414 : return get_entry(0xb0298, bl, bl_size);
		case 415 : return get_entry(0xb041c, bl, bl_size);
		case 416 : return get_entry(0xb11e0, bl, bl_size);

		// Monsters with E
		case 500 : return get_entry(0xb03f4, bl, bl_size);

		// Monsters with F
		case 600 : return get_entry(0xaff38, bl, bl_size);
		case 601 : return get_entry(0xb01e8, bl, bl_size);
		case 602 : return get_entry(0xb00b4, bl, bl_size);
		case 603 : return get_entry(0xb00c0, bl, bl_size);
		case 604 : return get_entry(0xb18ec, bl, bl_size);
		case 605 : return get_entry(0xb0070, bl, bl_size);
		case 606 : return get_entry(0xb07e8, bl, bl_size);
		case 607 : return get_entry(0xb0300, bl, bl_size);
		case 608 : return get_entry(0xb0acc, bl, bl_size);
		case 609 : return get_entry(0xb1e7c, bl, bl_size);
		case 610 : return get_entry(0xb1820, bl, bl_size);
		case 611 : return get_entry(0xb17d4, bl, bl_size);
		case 612 : return get_entry(0xb189c, bl, bl_size);
		case 613 : return get_entry(0xb1550, bl, bl_size);
		case 614 : return get_entry(0xb0644, bl, bl_size);
		case 615 : return get_entry(0xb13bc, bl, bl_size);
		case 616 : return get_entry(0xb0ffc, bl, bl_size);
		case 617 : return get_entry(0xb12b0, bl, bl_size);
		case 618 : return get_entry(0xa4564, bl, bl_size);

		// Monsters with G
		case 700 : return get_entry(0xaff2c, bl, bl_size);
		case 701 : return get_entry(0xb0234, bl, bl_size);
		case 702 : return get_entry(0xaffb4, bl, bl_size);
		case 703 : return get_entry(0xaffc8, bl, bl_size);
		case 704 : return get_entry(0xb0264, bl, bl_size);
		case 705 : return get_entry(0xb0fd4, bl, bl_size);
		case 706 : return get_entry(0xb03c0, bl, bl_size);
		case 707 : return get_entry(0xb0478, bl, bl_size);
		case 708 : return get_entry(0xb1f3c, bl, bl_size);
		case 709 : return get_entry(0xb05ac, bl, bl_size);
		case 710 : return get_entry(0xb1168, bl, bl_size);
		case 711 : return get_entry(0xb0874, bl, bl_size);
		case 712 : return get_entry(0xb17f8, bl, bl_size);
		case 713 : return get_entry(0xb10b0, bl, bl_size);
		case 714 : return get_entry(0xb0110, bl, bl_size);

		// Monsters with H
		case 800 : return get_entry(0xb0000, bl, bl_size);
		case 801 : return get_entry(0xb090c, bl, bl_size);
		case 802 : return get_entry(0xb0a84, bl, bl_size);
		case 803 : return get_entry(0xb1a8c, bl, bl_size);
		case 804 : return get_entry(0xb1d60, bl, bl_size);
		case 805 : return get_entry(0xb0e8c, bl, bl_size);
		case 806 : return get_entry(0xb19f8, bl, bl_size);
		case 807 : return get_entry(0xb0708, bl, bl_size);
		case 808 : return get_entry(0xb0bcc, bl, bl_size);
		case 809 : return get_entry(0xb08c0, bl, bl_size);
		case 810 : return get_entry(0xb0de0, bl, bl_size);
		case 811 : return get_entry(0xb1480, bl, bl_size);
		case 812 : return get_entry(0xb1298, bl, bl_size);
		case 813 : return get_entry(0xb140c, bl, bl_size);
		case 814 : return get_entry(0xb02d8, bl, bl_size);

		// Monsters with I
		case 900 : return get_entry(0xb12bc, bl, bl_size);
		case 901 : return get_entry(0xb1a3c, bl, bl_size);
		case 902 : return get_entry(0xb1984, bl, bl_size);

		// Monsters with L
		case 1200 : return get_entry(0xb0530, bl, bl_size);
		case 1201 : return get_entry(0xb0778, bl, bl_size);
		case 1202 : return get_entry(0xb099c, bl, bl_size);
		case 1203 : return get_entry(0xb12f8, bl, bl_size);
		case 1204 : return get_entry(0xb1458, bl, bl_size);
		case 1205 : return get_entry(0xb1688, bl, bl_size);
		case 1206 : return get_entry(0xb0024, bl, bl_size);
		case 1207 : return get_entry(0xb00a0, bl, bl_size);

		// Monsters with M
		case 1300 : return get_entry(0xb03a0, bl, bl_size);
		case 1301 : return get_entry(0xb0d4c, bl, bl_size);
		case 1302 : return get_entry(0xb14c0, bl, bl_size);
		case 1303 : return get_entry(0xb1598, bl, bl_size);
		case 1304 : return get_entry(0xb13e4, bl, bl_size);
		case 1305 : return get_entry(0xb1230, bl, bl_size);
		case 1306 : return get_entry(0xb0408, bl, bl_size);
		case 1307 : return get_entry(0xb0184, bl, bl_size);

		// Monsters with N
		case 1400 : return get_entry(0xb1874, bl, bl_size);
		case 1401 : return get_entry(0xb05c0, bl, bl_size);
		case 1402 : return get_entry(0xb0a10, bl, bl_size);
		case 1403 : return get_entry(0xb0240, bl, bl_size);

		// Monsters with O
		case 1500 : return get_entry(0xb0128, bl, bl_size);
		case 1501 : return get_entry(0xb132c, bl, bl_size);
		case 1502 : return get_entry(0xb1390, bl, bl_size);
		case 1503 : return get_entry(0xb15b8, bl, bl_size);

		// Monsters with P
		case 1600 : return get_entry(0xb1c58, bl, bl_size);
		case 1601 : return get_entry(0xb16ac, bl, bl_size);
		case 1602 : return get_entry(0xb16d0, bl, bl_size);
		case 1603 : return get_entry(0xb0e80, bl, bl_size);
		case 1604 : return get_entry(0xb0b44, bl, bl_size);
		case 1605 : return get_entry(0xb00f8, bl, bl_size);
		case 1606 : return get_entry(0xb03ac, bl, bl_size);
		case 1607 : return get_entry(0xb04b8, bl, bl_size);

		// Monsters with R
		case 1800 : return get_entry(0xb1f10, bl, bl_size);
		case 1801 : return get_entry(0xb128c, bl, bl_size);
		case 1802 : return get_entry(0xb0e70, bl, bl_size);
		case 1803 : return get_entry(0xb0440, bl, bl_size);
		case 1804 : return get_entry(0xb0490, bl, bl_size);
		case 1805 : return get_entry(0xb1304, bl, bl_size);
		case 1806 : return get_entry(0xb0600, bl, bl_size);
		case 1807 : return get_entry(0xb0558, bl, bl_size);
		case 1808 : return get_entry(0xb0018, bl, bl_size);

		// Monsters with S
		case 1900 : return get_entry(0xb18c4, bl, bl_size);
		case 1901 : return get_entry(0xb1938, bl, bl_size);
		case 1902 : return get_entry(0xb19d4, bl, bl_size);
		case 1903 : return get_entry(0xb1afc, bl, bl_size);
		case 1904 : return get_entry(0xb1c84, bl, bl_size);
		case 1905 : return get_entry(0xb1dbc, bl, bl_size);
		case 1906 : return get_entry(0xb1c2c, bl, bl_size);
		case 1907 : return get_entry(0xaff70, bl, bl_size);
		case 1908 : return get_entry(0xaff7c, bl, bl_size);
		case 1909 : return get_entry(0xaff94, bl, bl_size);
		case 1910 : return get_entry(0xb0040, bl, bl_size);
		case 1911 : return get_entry(0xb0134, bl, bl_size);
		case 1912 : return get_entry(0xb02ec, bl, bl_size);
		case 1913 : return get_entry(0xb035c, bl, bl_size);
		case 1914 : return get_entry(0xb0388, bl, bl_size);
		case 1915 : return get_entry(0xb042c, bl, bl_size);
		case 1916 : return get_entry(0xb04cc, bl, bl_size);
		case 1917 : return get_entry(0xb0578, bl, bl_size);
		case 1918 : return get_entry(0xb07bc, bl, bl_size);
		case 1919 : return get_entry(0xb09e4, bl, bl_size);
		case 1920 : return get_entry(0xb0f10, bl, bl_size);
		case 1921 : return get_entry(0xb1258, bl, bl_size);
		case 1922 : return get_entry(0xb1280, bl, bl_size);
		case 1923 : return get_entry(0xb163c, bl, bl_size);
		case 1924 : return get_entry(0xb10d4, bl, bl_size);
		case 1925 : return get_entry(0xb0db8, bl, bl_size);
		case 1926 : return get_entry(0xb0e08, bl, bl_size);
		case 1927 : return get_entry(0xb0e2c, bl, bl_size);
		case 1928 : return get_entry(0xb03e8, bl, bl_size);
		case 1929 : return get_entry(0xb0b88, bl, bl_size);

		// Monsters with T
		case 2000 : return get_entry(0xb15f8, bl, bl_size);
		case 2001 : return get_entry(0xaff64, bl, bl_size);
		case 2002 : return get_entry(0xb0c14, bl, bl_size);
		case 2003 : return get_entry(0xb00ec, bl, bl_size);
		case 2004 : return get_entry(0xb0508, bl, bl_size);
		case 2005 : return get_entry(0xb0830, bl, bl_size);
		case 2006 : return get_entry(0xb0954, bl, bl_size);
		case 2007 : return get_entry(0xb0c6c, bl, bl_size);
		case 2008 : return get_entry(0xb0e98, bl, bl_size);
		case 2009 : return get_entry(0xb1574, bl, bl_size);

		// Monsters with U
		case 2100 : return get_entry(0xb19b0, bl, bl_size);
		case 2101 : return get_entry(0xb12e8, bl, bl_size);

		// Monsters with V
		case 2200 : return get_entry(0xb007c, bl, bl_size);
		case 2201 : return get_entry(0xb0088, bl, bl_size);
		case 2202 : return get_entry(0xb0a58, bl, bl_size);
		case 2203 : return get_entry(0xb108c, bl, bl_size);

		// Monsters with W
		case 2300 : return get_entry(0xb00cc, bl, bl_size);
		case 2301 : return get_entry(0xb152c, bl, bl_size);
		case 2302 : return get_entry(0xb1190, bl, bl_size);
		case 2303 : return get_entry(0xb0514, bl, bl_size);
		case 2304 : return get_entry(0xb03d4, bl, bl_size);
		case 2305 : return get_entry(0xb0394, bl, bl_size);
		case 2306 : return get_entry(0xb0204, bl, bl_size);
		case 2307 : return get_entry(0xb0058, bl, bl_size);
		case 2308 : return get_entry(0xb0034, bl, bl_size);
		case 2309 : return get_entry(0xaffd4, bl, bl_size);
		case 2310 : return get_entry(0xaff44, bl, bl_size);
		case 2311 : return get_entry(0xb027c, bl, bl_size);

		// Monsters with Z
		case 2600 : return get_entry(0xb1f60, bl, bl_size);
		case 2601 : return get_entry(0xaff5c, bl, bl_size);
		case 2602 : return get_entry(0xb058c, bl, bl_size);

		}

		return get_entry(0xb1fa8, bl, bl_size); // Bad Monster
	}

	static string get_dungeon_name(int name, unsigned char* bl, int bl_size)
	{
		switch(name)
		{
		case  0 : return get_entry(0xb40f4, bl, bl_size); //Level 0
		case 20 : return get_entry(0xb5558, bl, bl_size); //Stinky water
		case 19 : return get_entry(0xb5d54, bl, bl_size); //I kill you!
		case 18 : return get_entry(0xb5d44, bl, bl_size); //Chamber of Dogfood
		case 17 : return get_entry(0xb5d28, bl, bl_size); //Bad Arnies Hideout
		}

		return get_entry(0xb5568, bl, bl_size); //Labirinth

	}

	static string get_mech_name(int name, unsigned char* bl, int bl_size)
	{
		switch(name)
		{

		//Shrines
		case    0 : return get_entry(0xb415c, bl, bl_size); // A
		case    1 : return get_entry(0xb41a0, bl, bl_size); // C
		case    2 : return get_entry(0xb4154, bl, bl_size); // C
		case    3 : return get_entry(0xb4184, bl, bl_size); // D
		case    4 : return get_entry(0xb418c, bl, bl_size); // E
		case    5 : return get_entry(0xb4194, bl, bl_size); // E
		case    6 : return get_entry(0xb41c4, bl, bl_size); // E
		case    7 : return get_entry(0xb41a8, bl, bl_size); // F
		case    8 : return get_entry(0xb4114, bl, bl_size); // G
		case    9 : return get_entry(0xb412c, bl, bl_size); // G
		case   10 : return get_entry(0xb41ec, bl, bl_size); // G
		case   11 : return get_entry(0xb4108, bl, bl_size); // M
		case   12 : return get_entry(0xb41e4, bl, bl_size); // M
		case   13 : return get_entry(0xb41f4, bl, bl_size); // M
		case   14 : return get_entry(0xb40d4, bl, bl_size); // M
		case   15 : return get_entry(0xb411c, bl, bl_size); // O
		case   16 : return get_entry(0xb4138, bl, bl_size); // O
		case   17 : return get_entry(0xb414c, bl, bl_size); // Q
		case   18 : return get_entry(0xb41d0, bl, bl_size); // R
		case   19 : return get_entry(0xb40e0, bl, bl_size); // S
		case   20 : return get_entry(0xb40e8, bl, bl_size); // S
		case   21 : return get_entry(0xb40fc, bl, bl_size); // S
		case   22 : return get_entry(0xb4168, bl, bl_size); // S
		case   23 : return get_entry(0xb4170, bl, bl_size); // S
		case   24 : return get_entry(0xb417c, bl, bl_size); // S
		case   25 : return get_entry(0xb4140, bl, bl_size); // S
		case   26 : return get_entry(0xb41dc, bl, bl_size); // S
		case   27 : return get_entry(0xb4124, bl, bl_size); // T
		case   28 : return get_entry(0xb41b4, bl, bl_size); // T

		case   40 : return get_entry(0xb42f4, bl, bl_size); // Liquid Spray
		case   41 : return get_entry(0xb4284, bl, bl_size); // Cooking Pot
		case   42 : return get_entry(0xb4264, bl, bl_size); // Cry Baby
		case   43 : return get_entry(0xb4290, bl, bl_size); // Not Sheep
		case   44 : return get_entry(0xb4278, bl, bl_size); // Carlson
		case   45 : return get_entry(0xb429c, bl, bl_size); // Get Clean


		//Audio Books Cs Gang
		case  100 : return get_entry(0xb40c0, bl, bl_size); // The Big Fight
		case  101 : return get_entry(0xb40a4, bl, bl_size); // War is a racket
		case  102 : return get_entry(0xb4088, bl, bl_size); // Tell about yourself

		//Audio Books Arnies
		case  110 : return get_entry(0xb403c, bl, bl_size); // Other Worlds
		case  111 : return get_entry(0xb4028, bl, bl_size); // Not 1, not 2...
		case  112 : return get_entry(0xb4018, bl, bl_size); // Dark Ruler

		//Audio Books Demons
		case  120 : return get_entry(0xb4078, bl, bl_size); // Racist expulsion
		case  121 : return get_entry(0xb406c, bl, bl_size); // The vice fight
		case  122 : return get_entry(0xb4050, bl, bl_size); // 3Combo

		//Audio Books Quest
		case  130 : return get_entry(0xb42b0, bl, bl_size); // Book of Liquid
		case  131 : return get_entry(0xb4378, bl, bl_size); // Old tales book
		case  132 : return get_entry(0xb42cc, bl, bl_size); // Book for visually handicapped
		case  133 : return get_entry(0xb42c0, bl, bl_size); // Metal paperback

		//Audio Books Expantion
		case  140 : return get_entry(0xb3fe4, bl, bl_size); // Blog: Say hi
		case  141 : return get_entry(0xb3fb4, bl, bl_size); // Blog: Become popular
		case  142 : return get_entry(0xb3fd0, bl, bl_size); // Blog: The Drama
		case  143 : return get_entry(0xb3fa0, bl, bl_size); // Blog: Name and Shame
		case  144 : return get_entry(0xb3f8c, bl, bl_size); // Blog: Last post
		case  145 : return get_entry(0xb3ffc, bl, bl_size); // Blog: Unred post
		case  146 : return get_entry(0xb3f80, bl, bl_size); // A Blog entry
		case  147 : return get_entry(0xb5598, bl, bl_size); // Rock of the Planet

		//Savekeepers
		case  200 : return get_entry(0xb436c, bl, bl_size); // Small
		case  201 : return get_entry(0xb4364, bl, bl_size); // Normal
		case  202 : return get_entry(0xb4358, bl, bl_size); // Large
		case  203 : return get_entry(0xb3e3c, bl, bl_size); // Wood explosion
		case  204 : return get_entry(0xb4330, bl, bl_size); // Slime explosion
		case  205 : return get_entry(0xb3d54, bl, bl_size); // Ceramic explosion
		case  206 : return get_entry(0xb434c, bl, bl_size); // Stone surprise

		//Doors
		case  300 : return get_entry(0xb4398, bl, bl_size); // No look
		case  301 : return get_entry(0xb43a4, bl, bl_size); // Look
		case  302 : return get_entry(0xb4388, bl, bl_size); // Cant look away

		//Levers
		case  400 : return get_entry(0xb3f68, bl, bl_size); // Mechanic
		case  401 : return get_entry(0xb43b0, bl, bl_size); // Bone mechanic

		//Loot Corpses
		case  500 : return get_entry(0xb421c, bl, bl_size); // Dead friend
		case  501 : return get_entry(0xb42e0, bl, bl_size); // Headless friend
		case  502 : return get_entry(0xb43e0, bl, bl_size); // Always look on the bright side of life!
		case  503 : return get_entry(0xb3dd0, bl, bl_size); // Get chest here
		case  504 : return get_entry(0xb4244, bl, bl_size); // Get sword here

		//Paper Sources
		case  600 : return get_entry(0xb4334, bl, bl_size); // Wooden Paper display
		case  601 : return get_entry(0xb4340, bl, bl_size); // Wooden Paper display part
		case  602 : return get_entry(0xb4304, bl, bl_size); // Borrowed paper
		case  603 : return get_entry(0xb4314, bl, bl_size); // Bone paper
		case  604 : return get_entry(0xb43d0, bl, bl_size); // Very old paper

		//Warps
		case  700 : return get_entry(0xaa850, bl, bl_size); // Warp
		case  701 : return get_entry(0xca864, bl, bl_size); // Up to  0
		case  702 : return get_entry(0xca800, bl, bl_size); // Down to 1
		case  703 : return get_entry(0xca7ec, bl, bl_size); // Shortcut to 5
		case  704 : return get_entry(0xca7dc, bl, bl_size); // Shortcut to 9
		case  705 : return get_entry(0xca7cc, bl, bl_size); // Shortcut to 13
		case  706 : return get_entry(0xca810, bl, bl_size); // Down to 21
		case  707 : return get_entry(0xca7bc, bl, bl_size); // Down to 25
		case  708 : return get_entry(0xca894, bl, bl_size); // Down to 16
		case  709 : return get_entry(0xb5558, bl, bl_size); // Stinky
		case  710 : return get_entry(0xb5d54, bl, bl_size); // I kill you!
		case  711 : return get_entry(0xb5d44, bl, bl_size); // Dogfood room
		case  712 : return get_entry(0xb5d28, bl, bl_size); // Arnie

		//Misc
		case  800 : return get_entry(0xb3ef0, bl, bl_size); // Not a demon
		case  801 : return get_entry(0xb3f50, bl, bl_size); // SPQR
		case  802 : return get_entry(0xb4228, bl, bl_size); // Dirty display
		case  803 : return get_entry(0xb4234, bl, bl_size); // Drugs party
		case  804 : return get_entry(0xb4250, bl, bl_size); // Red sticky pole
		case  805 : return get_entry(0xb43bc, bl, bl_size); // Offbeat porn
		}

		return "Unknown Mechanic";

	}


	static string get_story(int no, unsigned char* bl, int bl_size)
	{
		switch(no)
		{

		//---Book narrator speak-----------------------------------------

		case    0: return get_entry(0xc5230, bl, bl_size); // nar01 Cs gang The Big Fight
		case    1: return get_entry(0xc5428, bl, bl_size); // nar02 Cs gang War is a racket
		case    2: return get_entry(0xc5600, bl, bl_size); // nar03 Cs gang Tell about yourself
		case    3: return get_entry(0xc5a50, bl, bl_size); // nar04 Demons Racist expulsion
		case    4: return get_entry(0xc5c48, bl, bl_size); // nar05 Demons The vice fight
		case    5: return get_entry(0xc5dc0, bl, bl_size); // nar06 Demons 3Combo
		case    6: return get_entry(0xc6100, bl, bl_size); // nar07 Arnie  Other Worlds
		case    7: return get_entry(0xc62c0, bl, bl_size); // nar08 Arnie  Not 1, not 2...
		case    8: return get_entry(0xc6468, bl, bl_size); // nar09 Arnie Dark Ruler
		case    9: return get_entry(0xc7c58, bl, bl_size); // NARATR3 Rock of the world
		case   10: return get_entry(0xc8b10, bl, bl_size); // Naratr6 Blog: Say hi I
		case   11: return get_entry(0xc8bc8, bl, bl_size); // Naratr7 Blog: The Drama
		case   12: return get_entry(0xc8cd8, bl, bl_size); // Naratr8 Blog: Become popular
		case   13: return get_entry(0xc8e00, bl, bl_size); // Naratr5 Blog: Name and Shame
		case   14: return get_entry(0xc8f08, bl, bl_size); // Naratr9 Blog: Last post
		case   15: return get_entry(0xc9000, bl, bl_size); // Naratr4 Glued up note


		//---Books class speak----------------------------------------

		case  100: return get_entry(0xc4ef8, bl, bl_size); // rogue01 Old tales book Dogfood quest
		case  101: return get_entry(0xc4fc3, bl, bl_size); // rogue10 Book of Liquid, mythical strength of spirit
		case  102: return get_entry(0xc5040, bl, bl_size); // rogue11 Book for visually handicapped, blind quest
		case  103: return get_entry(0xc5140, bl, bl_size); // rogue12 Metal paperback, red admiral quest
		case  104: return get_entry(0xc9658, bl, bl_size); // rogue54 latin i.s.s.
		case  105: return get_entry(0xc9670, bl, bl_size); // rogue55 latin p.o.
		case  106: return get_entry(0xc9688, bl, bl_size); // rogue56 latin e.o.u.i.


		//---Speaking monsters-----------------------------------------

		case  200: return get_entry(0xb8178, bl, bl_size); // sking01 You have entered my grave

		case  201: return get_entry(0xb8b48, bl, bl_size); // snot01 Go get neon for us
		case  202: return get_entry(0xb8c10, bl, bl_size); // snot02 Go get neon fro us 2
		case  203: return get_entry(0xb8c50, bl, bl_size); // snot03 Tnaks sucker, now die

		case  204: return get_entry(0xbc0c8, bl, bl_size); // lach01 Queststart shower drink
		case  205: return get_entry(0xbc360, bl, bl_size); // lach02 No shower drink yet? keep looking
		case  206: return get_entry(0xbc3c8, bl, bl_size); // lach03 Thanks for the shower drink, now here is your reward

		case  207: return get_entry(0xbfe08, bl, bl_size); // garbud01 Here is 1st item, come back later
		case  208: return get_entry(0xbfe58, bl, bl_size); // garbud02 working on another item, come back later
		case  209: return get_entry(0xbfed8, bl, bl_size); // garbud02 working on 3rd item
		case  210: return get_entry(0xbff48, bl, bl_size); // garbud04 third item to good, die!

		case  211: return get_entry(0xbff88, bl, bl_size); // zhar01 Take this and leave me alone
		case  212: return get_entry(0xc0020, bl, bl_size); // zhar02 Ok thats it, you die

		case  213: return get_entry(0xbdef0, bl, bl_size); // warlrd01 i see you, now you die

		case  214: return get_entry(0xb9b50, bl, bl_size); // laz01 You have come here, now die

		case  215: return get_entry(0xc94a0, bl, bl_size); // DEFILER6 1st msg
		case  216: return get_entry(0xc9538, bl, bl_size); // DEFILER7 2nd msg
		case  217: return get_entry(0xc9618, bl, bl_size); // DEFILER8 3rd msg

		}

		return "Unknown story";
	}


	static char get_char(int off, unsigned char* bl, int bl_size)
	{
		if (off > bl_size -1){return ' ';}

		return bl[off];
	}





	static string get_entry(int off, unsigned char* bl, int bl_size)
	{
		string out = "";
		int index = off;


		while(index < bl_size)
		{
			char c = bl[index];

			if (char_cool(c))
			{
				out.append(1,c);
				index++;
			}
			else
			{
				index = bl_size + 1000;
			}
		}

		return out;
	}



	static bool char_is_sepparator(unsigned char in)
	{
		if (in == 0x00){return true;}
		if (in == '|'){return true;}
		return false;
	}

	static bool char_cool(unsigned char in)
	{
		if (in == ' '){return true;}

		if (in == 0x0a){return true;}
		if (in == 0x2e){return true;}
		if (in == 0x09){return true;}

		if (in == '0'){return true;}
		if (in == '1'){return true;}
		if (in == '2'){return true;}
		if (in == '3'){return true;}
		if (in == '4'){return true;}
		if (in == '5'){return true;}
		if (in == '6'){return true;}
		if (in == '7'){return true;}
		if (in == '8'){return true;}
		if (in == '9'){return true;}

		if (in == 'a'){return true;}
		if (in == 'b'){return true;}
		if (in == 'c'){return true;}
		if (in == 'd'){return true;}
		if (in == 'e'){return true;}
		if (in == 'f'){return true;}
		if (in == 'g'){return true;}
		if (in == 'h'){return true;}
		if (in == 'i'){return true;}
		if (in == 'j'){return true;}
		if (in == 'k'){return true;}
		if (in == 'l'){return true;}
		if (in == 'm'){return true;}
		if (in == 'n'){return true;}
		if (in == 'o'){return true;}
		if (in == 'p'){return true;}
		if (in == 'q'){return true;}
		if (in == 'r'){return true;}
		if (in == 's'){return true;}
		if (in == 't'){return true;}
		if (in == 'u'){return true;}
		if (in == 'v'){return true;}
		if (in == 'w'){return true;}
		if (in == 'x'){return true;}
		if (in == 'y'){return true;}
		if (in == 'z'){return true;}

		if (in == 'A'){return true;}
		if (in == 'B'){return true;}
		if (in == 'C'){return true;}
		if (in == 'D'){return true;}
		if (in == 'E'){return true;}
		if (in == 'F'){return true;}
		if (in == 'G'){return true;}
		if (in == 'H'){return true;}
		if (in == 'I'){return true;}
		if (in == 'J'){return true;}
		if (in == 'K'){return true;}
		if (in == 'L'){return true;}
		if (in == 'M'){return true;}
		if (in == 'N'){return true;}
		if (in == 'O'){return true;}
		if (in == 'P'){return true;}
		if (in == 'Q'){return true;}
		if (in == 'R'){return true;}
		if (in == 'S'){return true;}
		if (in == 'T'){return true;}
		if (in == 'U'){return true;}
		if (in == 'V'){return true;}
		if (in == 'W'){return true;}
		if (in == 'X'){return true;}
		if (in == 'Y'){return true;}
		if (in == 'Z'){return true;}

		if (in == '`'){return true;}
		if (in == '\''){return true;}
		if (in == ','){return true;}
		if (in == '.'){return true;}
		if (in == '?'){return true;}
		if (in == '!'){return true;}
		if (in == '('){return true;}
		if (in == ')'){return true;}
		if (in == '-'){return true;}
		if (in == '+'){return true;}
		if (in == '='){return true;}
		if (in == '*'){return true;}

		if (in == '&'){return true;}
		if (in == '%'){return true;}
		if (in == '"'){return true;}
		if (in == ':'){return true;}
		if (in == ';'){return true;}

		return false;
	}






	static void generate_ref(int off, unsigned char* bl, int bl_size)
	{

		string candidate= "";
		int candidate_off = 0;

		bool last_char_was_cool = false;
		bool last_char_was_sepp = true;


		for (int i = off; i < bl_size; i++)
		{
			if (char_cool(bl[i]))
			{
				if (last_char_was_cool || last_char_was_sepp)
				{
					candidate.append(1, bl[i]);
					if (candidate_off == 0){candidate_off = i;}
				}
				last_char_was_cool = true;

			}
			else
			{
				if ((candidate.size() > 3) && char_is_sepparator(bl[i]))
				{
					cout << "[" <<hex << candidate_off << "]"<< " " << candidate << endl;
				}

				candidate = "";
				candidate_off = 0;

				last_char_was_cool = false;

			}

			last_char_was_sepp = char_is_sepparator(bl[i]);


		}

	}


};
