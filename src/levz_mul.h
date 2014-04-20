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




#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

#include "libsdl/SDL.h"
#include "libsdl/SDL_thread.h"

#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>



#include "libmpq/mpq.h"
#include "hooks/ddtrules.cpp"
#include "hooks/ddtsavegame.cpp"

#include "hooks/ddttime_sdl.cpp"
#include "hooks/ddtaudio_sdl.cpp"
#include "hooks/ddtmath_cpp.cpp"
#include "hooks/ddtutils.cpp"
#include "hooks/ddtblob.cpp"
#include "hooks/ddtpal.cpp"
#include "hooks/ddtinput_sdl.cpp"



#include "hooks/ddtgrfx_sdl_opengl.cpp"
//#include "hooks/ddtgrfx_sdl_surface.cpp"






using namespace std;

#ifndef LEVELZ_H_
#define LEVELZ_H_


//game modes

#define GAME_MODE_CLASSIC 0
#define GAME_MODE_EXP 1
#define GAME_MODE_UNSET 2

#define GAME_DIFF_NORMAL 0
#define GAME_DIFF_NIGHTMARE 1
#define GAME_DIFF_HELL 2


#define ORIGINAL_WIDTH 640
#define ORIGINAL_HEIGHT 480
#define ORIGINAL_FRAME_TIME 40 //in ms
#define WORLD_DELAY_TIME 20 //in ms
#define RENDER_DELAY_TIME 30 //in ms
#define DDT_SPEEDUP 2.0 //ORIGINAL_FRAME_TIME / WORLD_DELAY_TIME


#define MAX_WIDTH 6000
#define MAX_HEIGHT 5000
#define TEXTURE_SLOTS 2000

#define WORLD_UPDATE_RADIUS 27



#define BUTTON_TIMEOUT 500
#define MOUSEOVER_TIMEOUT 100 //how long has something the selection grfx after the mouse is gone?
#define WORLD_MSG_SCREEN_TIMEOUT 2000 //how long is a message displayed to the player
#define UI_SLOW_UPDATE 1000 //how long in ms for the ui to wait with the slow update routine



#define THREADSAVE_STRING_SIZE 64
#define LONG_THREADSAVE_STRING_SIZE 200
#define MAX_CHAR_NAME_LENGTH 14
#define MAX_MPQ_OPEN 20



#define UI_SAVE_BUTTON_COUNT 5
#define UI_CLASS_BUTTON_COUNT 5
#define UI_OPT_BUTTON_COUNT 8


//how many pallette slots do we have
#define PALKEEP_SIZE 250
// How big is a pal file
#define PALSIZE 768
#define TRNSIZE 256

#define IDLE_ANIMATED -66 // if this is set as y in texkeeper xy texture call, it means
//we should just be animating from y0 to yMAX based on real time
#define VOID_TEXTURE -67 // if this is set as y or y in texkeeper xy texture call, it means
//we should not be rendering anything

#define TILE_SCREEN_X_SIZE 64.0 //pixel dimentions of a tile
#define TILE_SCREEN_X_HALF_SIZE 32.0 //pixel dimentions of a tile
#define TILE_SCREEN_Y_SIZE 32.0

#define TILE_LIGHTING_OPTION_DEFAULT 0
#define TILE_LIGHTING_OPTION_PROXFADE 1
#define TILE_LIGHTING_OPTION_GOOZE 2




// Texture options

#define DEVELOPER_STAMP false
#define DEVELOPER_RENDER_PASS false
#define DEVELOPER_MUTE false
#define DEVELOPER_LEVEL_EXTRA false




#define TEXT_JUSTIFY_LEFT 0
#define TEXT_JUSTIFY_CENTER 1
#define TEXT_JUSTIFY_RIGHT 2


// the screens
#define SCREEN_COUNT 12
#define SCREEN_TITLE 0
#define SCREEN_MAIN_MENU 1
#define SCREEN_SETTINGS_MENU 2
#define SCREEN_CREDITS_SELECT_MENU 3
#define SCREEN_GAME_CREDITS 4
#define SCREEN_SINGE_PLAYER 5
#define SCREEN_CHOOSE_CLASS 6
#define SCREEN_ENTER_NAME 7
#define SCREEN_SELECT_GAMETYPE 8
#define SCREEN_WORLD 9
#define SCREEN_DELETE_CHAR 10
#define SCREEN_LOAD_WAIT 11
/// world screen subscreens
#define WORLD_SUBSCREEN_COUNT 9
#define SUBSCREEN_MENU 0
#define SUBSCREEN_STORY 1
#define SUBSCREEN_MSG 2
#define SUBSCREEN_SPELLS 3
#define SUBSCREEN_ORBS 4
#define SUBSCREEN_CHAR 5
#define SUBSCREEN_INV 6
#define SUBSCREEN_STASH 7
#define SUBSCREEN_MAP 8






// button stuff
#define BUTTON_VOID_COMMAND 0 //button does nothing
#define BUTTON_GOTO_MAINMENU_COMMAND 1 //go to main menu
#define BUTTON_GOTO_SETTINGS_COMMAND 2 //guess
#define BUTTON_GOTO_CREDITS_COMMAND 66 //guess

#define BUTTON_GOTO_GAME_CREDITS_COMMAND 67 //guess
#define BUTTON_GOTO_ENGINE_CREDITS_COMMAND 68 //guess
#define BUTTON_GOTO_EXPANTION_CREDITS_COMMAND 69 //guess

#define BUTTON_GOTO_SINGLE_PLAYER_COMMAND 80 //guess


#define BUTTON_QUIT_GAME_COMMAND 3 //guess

#define BUTTON_GAMEOPT_SELECTA_COMMAND 400
#define BUTTON_GAMEOPT_SELECTB_COMMAND 401
#define BUTTON_GAMEOPT_SELECTC_COMMAND 402
#define BUTTON_GAMEOPT_SELECTD_COMMAND 403
#define BUTTON_GAMEOPT_SELECTE_COMMAND 404
#define BUTTON_GAMEOPT_SELECTF_COMMAND 405
#define BUTTON_GAMEOPT_SELECTG_COMMAND 406
#define BUTTON_GAMEOPT_SELECTH_COMMAND 407
#define BUTTON_GAMEOPT_SCROLLUP_COMMAND 408
#define BUTTON_GAMEOPT_SCROLLDOWN_COMMAND 409
#define BUTTON_GAMEOPT_MIN_MIN_COMMAND 410
#define BUTTON_GAMEOPT_MIN_COMMAND 411
#define BUTTON_GAMEOPT_PLUS_COMMAND 412
#define BUTTON_GAMEOPT_PLUS_PLUS_COMMAND 413


#define BUTTON_SETTINGS_ACCEPT_COMMAND 32
#define BUTTON_SETTINGS_DEF_COMMAND 33
#define BUTTON_SETTINGS_CANCEL_COMMAND 34

#define BUTTON_CREDITS_SCROLLUP_COMMAND 100
#define BUTTON_CREDITS_SCROLLDOWN_COMMAND 101

#define BUTTON_SINGLE_PLAYER_SCROLLUP_COMMAND 102
#define BUTTON_SINGLE_PLAYER_SCROLLDOWN_COMMAND 103
#define BUTTON_SINGLE_PLAYER_SELECTA_COMMAND 104
#define BUTTON_SINGLE_PLAYER_SELECTB_COMMAND 105
#define BUTTON_SINGLE_PLAYER_SELECTC_COMMAND 106
#define BUTTON_SINGLE_PLAYER_SELECTD_COMMAND 107
#define BUTTON_SINGLE_PLAYER_SELECTE_COMMAND 108
#define BUTTON_SINGLE_PLAYER_OK_COMMAND 109
#define BUTTON_SINGLE_PLAYER_DELETE_COMMAND 1000

#define BUTTON_DELETE_SCREEN_OK_COMMAND 1001


#define BUTTON_CHOOSE_CLASS_SCROLLUP_COMMAND 110
#define BUTTON_CHOOSE_CLASS_SCROLLDOWN_COMMAND 111
#define BUTTON_CHOOSE_CLASS_SELECTA_COMMAND 112
#define BUTTON_CHOOSE_CLASS_SELECTB_COMMAND 113
#define BUTTON_CHOOSE_CLASS_SELECTC_COMMAND 114
#define BUTTON_CHOOSE_CLASS_SELECTD_COMMAND 115
#define BUTTON_CHOOSE_CLASS_SELECTE_COMMAND 116
#define BUTTON_CHOOSE_CLASS_OK_COMMAND 117

#define BUTTON_ENTER_NAME_OK_COMMAND 199
#define BUTTON_ENTER_NAME_CANCEL_COMMAND 200

#define BUTTON_ENTER_NAME_A_COMMAND 201
#define BUTTON_ENTER_NAME_B_COMMAND 202
#define BUTTON_ENTER_NAME_C_COMMAND 203
#define BUTTON_ENTER_NAME_D_COMMAND 204
#define BUTTON_ENTER_NAME_E_COMMAND 205
#define BUTTON_ENTER_NAME_F_COMMAND 206
#define BUTTON_ENTER_NAME_G_COMMAND 207
#define BUTTON_ENTER_NAME_H_COMMAND 208
#define BUTTON_ENTER_NAME_I_COMMAND 209
#define BUTTON_ENTER_NAME_J_COMMAND 210
#define BUTTON_ENTER_NAME_K_COMMAND 211
#define BUTTON_ENTER_NAME_L_COMMAND 212
#define BUTTON_ENTER_NAME_M_COMMAND 213
#define BUTTON_ENTER_NAME_N_COMMAND 214
#define BUTTON_ENTER_NAME_O_COMMAND 215
#define BUTTON_ENTER_NAME_P_COMMAND 216
#define BUTTON_ENTER_NAME_Q_COMMAND 217
#define BUTTON_ENTER_NAME_R_COMMAND 218
#define BUTTON_ENTER_NAME_S_COMMAND 219
#define BUTTON_ENTER_NAME_T_COMMAND 220
#define BUTTON_ENTER_NAME_U_COMMAND 221
#define BUTTON_ENTER_NAME_V_COMMAND 222
#define BUTTON_ENTER_NAME_W_COMMAND 223
#define BUTTON_ENTER_NAME_X_COMMAND 224
#define BUTTON_ENTER_NAME_Y_COMMAND 225
#define BUTTON_ENTER_NAME_Z_COMMAND 226
#define BUTTON_ENTER_NAME_0_COMMAND 227
#define BUTTON_ENTER_NAME_1_COMMAND 228
#define BUTTON_ENTER_NAME_2_COMMAND 229
#define BUTTON_ENTER_NAME_3_COMMAND 230
#define BUTTON_ENTER_NAME_4_COMMAND 231
#define BUTTON_ENTER_NAME_5_COMMAND 232
#define BUTTON_ENTER_NAME_6_COMMAND 233
#define BUTTON_ENTER_NAME_7_COMMAND 234
#define BUTTON_ENTER_NAME_8_COMMAND 235
#define BUTTON_ENTER_NAME_9_COMMAND 236
#define BUTTON_ENTER_NAME_BACK_COMMAND 237
#define BUTTON_ENTER_NAME_USCORE_COMMAND 238

#define BUTTON_GAMETYPE_LOAD_COMMAND 300
#define BUTTON_GAMETYPE_NORMAL_COMMAND 301
#define BUTTON_GAMETYPE_NIGHTMARE_COMMAND 302
#define BUTTON_GAMETYPE_HELL_COMMAND 303
#define BUTTON_GAMETYPE_OK_COMMAND 304

#define BUTTON_WORLD_TOGGLE_MENU_ON 500
#define BUTTON_WORLD_TOGGLE_MENU_OFF 501
#define BUTTON_WORLD_TOGGLE_CHARSTATS 502
#define BUTTON_WORLD_TOGGLE_INVENTORY 503

#define BUTTON_WORLD_TOGGLE_MAP 504
#define BUTTON_WORLD_MAP_RIGHT 505
#define BUTTON_WORLD_MAP_LEFT 506
#define BUTTON_WORLD_MAP_UP 507
#define BUTTON_WORLD_MAP_DOWN 508

#define BUTTON_WORLD_LEAVE_GAME 510
#define BUTTON_WORLD_MAKE_SAVEGAME 511
#define BUTTON_WORLD_LOAD_SAVEGAME 512


#define BUTTON_WORLD_STORY_SCROLL_UP 550
#define BUTTON_WORLD_STORY_SCROLL_DOWN 551
#define BUTTON_WORLD_STORY_EXIT 552









// Texture alogarithems

#define TOWN_CEL 0
#define INDEXED_CEL 1
#define INDEXED_CLT 2
#define DOUBLE_INDEXED_CEL 3
#define DOUBLE_INDEXED_CLT 4
#define PCX 5
#define OBJCURS 6
#define UIFUSE_ORBS 7
#define UIFUSE_STASH 8
#define MAP 9


// audio alogarithems

//#define MUSIC_NOLOOP 50
//#define MUSIC_LOOP 51
//#define MUSIC_STOP 52
//#define ALL_STOP 53


//-------------------
//Program options
//-------------------

#define OPT_COUNT 9
#define OPT_WIDTH 0
#define OPT_HEIGHT 1
#define OPT_ZOOM 2
#define OPT_BLEND 3
#define OPT_GAMMA 4
#define OPT_ALPHA 5
#define OPT_SOUND 6
#define OPT_MUSIC 7
#define OPT_AUTOSAVE 8



//------------------
// Grfx loaded slots
//------------------

// if this is set as y or y in texkeeper xy texture call, it means
//we should not be rendering anything
#define VOID_TEXTURE -67

// fonts
#define FONT_SYS 0
#define FONT_SMALL 1
#define FONT_SIXTEEN_G 2
#define FONT_SIXTEEN_S 3
#define FONT_TWENTYFOUR_G 4
#define FONT_TWENTYFOUR_S 5
#define FONT_THIRTY_G 6
#define FONT_THIRTY_S 7
#define FONT_FOURTYTWO_G 8
#define FONT_FOURTYTWO_S 9

// some UI elements

#define MOUSE_CURSOR 10
#define MOUSE_CURSOR_HF 11

#define PENTA_SMALLEST 12
#define PENTA_SMALL 13
#define PENTA_MEDIUM 14
#define PENTA_BIG 15
#define PENTA_BIGGEST 16

#define SCROLL_BAR 17

#define LOGO_STATIC 18
#define LOGO_SMALL 19
#define LOGO_MEDIUM 20
#define LOGO_BIG 21

#define CHAR_PORTRAIT 25
#define BACKDROP 27

#define GAME_MAP 32
#define INV_BACKDROP 33
#define CHAR_BACKDROP 34
#define ORB_BAR 35
#define STASH_WINDOW 36
#define ORB_BAR_BUTTS 37

#define ITEM_FLIP_MONEY_G 50





#define CHUNKY_DEFUALT 0
#define CHUNKY_LINEAR 1
#define CHUNKY_MAXI 2
#define CHUNKY_SMOOTH 3






//---------------
// Grfx subslots
//---------------

#define IDLE_ANIMATED -66 // if this is set as y in texkeeper xy texture call, it means
//we should just be animating from y0 to yMAX based on real time


//-------------------
//Audio loaded slots
//-------------------
#define VOID_SOUND -66

#define SOUND_SELECT 1
#define SOUND_MOVE 2

#define ITEM_FLIP_MONEY_A 50



// thread commands
#define THREAD_VOID_COMMAND -1

#define FILEIO_WRITE_CONFIG 1
#define FILEIO_GET_SAFELIST 2
#define FILEIO_WRITE_SAVE 3
#define FILEIO_LOAD_SAVE 4
#define FILEIO_LOAD_RULES 5
#define FILEIO_DELETE_SAVE 6
#define FILEIO_LOAD_PROVIDED_RULES 7


#define TRANSCODE_GRFX 10
#define TRANSCODE_UNLOAD_GRFX 11
#define TRANSCODE_RESET_GRFX_PAK 12
#define TRANSCODE_AUDIO 13
#define TRANSCODE_RESET_AUDIO_PAK 14

#define DISPLAY_LOAD_CHUNKS 50
#define DISPLAY_RESET_PAK_SIZE 51
#define DISPLAY_UNLOAD_PAK_MEMBER 52

#define AUDIO_LOAD 101
#define AUDIO_PLAY_SFX 102
#define AUDIO_RESET_PAK_SIZE 103
#define AUDIO_PLAY_PAK_SFX 104
#define AUDIO_START_STORY 105
#define AUDIO_STOP_STORY 106


#define MOUSEKEYB_UPDATE_SAVELIST 201
#define MOUSEKEYB_UPDATE_CLASSLIST 202
#define MOUSEKEYB_UPDATE_CREDITS 203
#define MOUSEKEYB_SET_MSG 205
#define MOUSEKEYB_CLEAN_WORLD_UI 206
#define MOUSEKEYB_MOVE_LOADMSG_Y 207
#define MOUSEKEYB_SET_LOADMSG 208
#define MOUSEKEYB_SET_STORY 209
#define MOUSEKEYB_SET_BLOB_STORY 210

#define WORLD_LOAD_LEVEL 600
#define WORLD_LEFT_CLICK 601
#define WORLD_RIGHT_CLICK 602
#define WORLD_LOAD_CLASS 603
#define WORLD_LOAD_SAVE 604

#define WORLD_START_CHAIN_NEWCHAR 610
#define WORLD_START_CHAIN_NEWGAME 611
#define WORLD_START_CHAIN_OLDGAME 612
#define WORLD_START_CHAIN_CHANGEDUN 613

#define WORLD_MAKE_SAVEGAME 615
#define WORLD_SAVEGAME_IS_WRITTEN 616

#define WORLD_SECTOR_HOTFIX 617











#define CLASSTX_COUNT 1
#define CLASSTX_LIGHT_UNARMED 0


#define START_ITEM_COUNT 5

#define SECTORFIX_COUNT 512




/*

#define CLASS_ARMOR_TYPE_COUNT 4
#define CLASS_ARMOR_TYPE_NO 0
#define CLASS_ARMOR_TYPE_LIGHT 1
#define CLASS_ARMOR_TYPE_MEDIUM 2
#define CLASS_ARMOR_TYPE_HEAVY 3

#define CLASS_HANDS_TYPE_COUNT 21
#define CLASS_HANDS_TYPE_UNARMED 0
#define CLASS_HANDS_TYPE_SHIELD 1
#define CLASS_HANDS_TYPE_STAFF 2
#define CLASS_HANDS_TYPE_AXE 3
#define CLASS_HANDS_TYPE_1HSWORD 4
#define CLASS_HANDS_TYPE_2HSWORD 5
#define CLASS_HANDS_TYPE_2HSWORD_SHIELD 6
#define CLASS_HANDS_TYPE_2HSWORD_STAFF 7
#define CLASS_HANDS_TYPE_2HSWORD_AXE 8
#define CLASS_HANDS_TYPE_2HSWORD_1HSWORD 9
#define CLASS_HANDS_TYPE_2HSWORD_2HSWORD 10
#define CLASS_HANDS_TYPE_1HSWORD_SHIELD 11
#define CLASS_HANDS_TYPE_1HSWORD_STAFF 12
#define CLASS_HANDS_TYPE_1HSWORD_AXE 13
#define CLASS_HANDS_TYPE_1HSWORD_1HSWORD 14
#define CLASS_HANDS_TYPE_AXE_SHIELD 15
#define CLASS_HANDS_TYPE_AXE_STAFF 16
#define CLASS_HANDS_TYPE_AXE_AXE 17
#define CLASS_HANDS_TYPE_STAFF_SHIELD 18
#define CLASS_HANDS_TYPE_STAFF_STAFF 19
#define CLASS_HANDS_TYPE_SHIELD_SHIELD 20


*/





// tile directions

#define DIRECTION_SE 0
#define DIRECTION_S 1
#define DIRECTION_SW 2
#define DIRECTION_W 3
#define DIRECTION_NW 4
#define DIRECTION_N 5
#define DIRECTION_NE 6
#define DIRECTION_E 7

// monster actions and intentions
#define ACTION_IDLE 0
#define ACTION_WALK_PRE 1
#define ACTION_WALK_POST 2
#define ACTION_TELEPORT_PRE 3
#define ACTION_TELEPORT_POST 4

#define INTENTION_IDLE 0
#define INTENTION_WALK 1
#define INTENTION_TELEPORT 2

#define BRAINS_NONE 0
#define BRAINS_WANDERER 1



#define LEVEL_COUNT 43
#define LEVEL_TOWN 0



#define MONSTER_INTERACTION_REF_VOID -1
#define MONSTER_INTERACTION_REF_ANIMAL 0
#define MONSTER_INTERACTION_REF_GOLDGIVER 1

#define MECHANIC_INTERACTION_REF_VOID -1
#define MECHANIC_INTERACTION_REF_STASH 0
#define MECHANIC_INTERACTION_REF_WARP 1
#define MECHANIC_INTERACTION_REF_AUDIOBOOK 2
#define MECHANIC_INTERACTION_REF_LEVER 3


#define DDT_OFF 0
#define DDT_ON 1
#define DDT_FLIP 2
#define DDT_SYNC 3





#endif


typedef float sf32;
typedef double sf64;


typedef uint8_t  byte;
typedef uint16_t dibyte;
typedef uint32_t quadbyte;
typedef uint64_t octabyte;

typedef int8_t  sbyte;
typedef int16_t sdibyte;
typedef int32_t squadbyte;
typedef int64_t soctabyte;




