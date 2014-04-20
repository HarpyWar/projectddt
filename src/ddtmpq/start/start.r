<begin>


<pakset>[...0]
<pakinit_vid>[.200] <pakinit_aud>[.200] //tex, aud



<mpqset>[ddt.mpq]
<grfx>[...0][pcx8][auto][auto][auto][.097][...1][auto][...0][-..5][ddtmpq\nontxt\neosys.pcx] //FONT_SYS
<mpqset>[diabdat.mpq]
<grfx>[...1][icel][..13][..11][..12][auto][auto][smoo][...0][-..1][ctrlpan\smaltext.cel] //FONT_SMALL
#grfx>[...2][pcx8][auto][auto][auto][.256][..32][smoo][...0][-..4][ui_art\font16g.pcx] //FONT_SIXTEEN_G //hard to read
#grfx>[...3][pcx8][auto][auto][auto][.256][..32][smoo][...0][-..4][ui_art\font16s.pcx] //FONT_SIXTEEN_S //hard to read
<grfx>[...4][pcx8][auto][auto][auto][.256][..32][smoo][...0][-..4][ui_art\font24g.pcx] //FONT_TWENTYFOUR_G
<grfx>[...5][pcx8][auto][auto][auto][.256][..32][smoo][...0][-..4][ui_art\font24s.pcx] //FONT_TWENTYFOUR_S
<grfx>[...6][pcx8][auto][auto][auto][.256][..32][smoo][...0][-..4][ui_art\font30g.pcx] //FONT_THIRTY_G
<grfx>[...7][pcx8][auto][auto][auto][.256][..32][smoo][...0][-..4][ui_art\font30s.pcx] //FONT_THIRTY_S
<grfx>[...8][pcx8][auto][auto][auto][.256][..32][smoo][...0][-..7][ui_art\font42g.pcx] //FONT_FOURTYTWO_G
<grfx>[...9][pcx8][auto][auto][auto][.256][..32][smoo][...0][-..7][ui_art\font42y.pcx] // FONT_FOURTYTWO_S


<grfx>[..10][objc][..32][..32][..12][auto][auto][..32][...0][...0][data\inv\objcurs.cel] //MOUSE_CURSOR
11 //MOUSE_CURSOR_HF

/* rotating pentagram */
<grfx>[..12][icel][..12][..12][..12][auto][auto][auto][-..6][...0][data\pentspn2.cel] //PENTA_SMALLEST
<grfx>[..13][pcx8][auto][auto][auto][...8][.250][auto][-.10][...0][ui_art\focus16.pcx] //PENTA_SMALL
<grfx>[..14][pcx8][auto][auto][auto][...8][.250][auto][-.15][...0][ui_art\focus.pcx] //PENTA_MEDIUM
<grfx>[..15][pcx8][auto][auto][auto][...8][.250][auto][-.21][...0][ui_art\focus42.pcx] // PENTA_BIG
#grfx>[..16][icel][..48][..48][..12][auto][auto][auto][-.24][...0][data\PentSpin.cel] //PENTA_BIGGEST just too damn big

<grfx>[..17][icel][..12][..12][..12][auto][auto][auto][...0][...0][data\textslid.cel] //SCROLL_BAR


/* burning logo */
#grfx>[..18][icel][.296][..95][...0][auto][auto][auto][-148][...0][data\diabsmal.cel] //LOGO_STATIC is loaded on demand

<di_only><grfx>[..19][pcx8][auto][auto][auto][..15][.250][auto][-130][...0][ui_art\xsmlogo.pcx] //LOGO_SMALL
<di_only><grfx>[..20][pcx8][auto][auto][auto][..15][.250][auto][-195][...0][ui_art\smlogo.pcx] // LOGO_MEDIUM
<di_only><grfx>[..21][pcx8][auto][auto][auto][..15][.250][auto][-275][...0][ui_art\logo.pcx] // LOGO_BIG

<hf_only><mpqset>[hellfire.mpq]
<hf_only><grfx>[..19][pcx8][auto][auto][auto][..16][.000][auto][-320][...0][ui_art\hf_logo2.pcx] //LOGO_SMALL
<hf_only><mpqset>[diabdat.mpq]


/* char creation portraits */
<di_only><grfx>[..25][pcx8][auto][auto][auto][...4][.666][auto][...0][...0][ui_art\heros.pcx] //CHAR_PORTRAIT

<hf_only><mpqset>[hellfire.mpq]
<hf_only><grfx>[..25][pcx8][auto][auto][auto][...6][.666][auto][...0][...0][ui_art\heros.pcx] //CHAR_PORTRAIT
<hf_only><mpqset>[diabdat.mpq]


/*backdrops */

<di_only><grfx>[..27][pcx8][auto][auto][auto][...1][.666][auto][...0][...0][ui_art\title.pcx] // BACKDROP red diablo 
<hf_only><mpqset>[hellfire.mpq]
<hf_only><grfx>[..27][pcx8][auto][auto][auto][..16][.666][auto][...0][...0][ui_art\hf_logo1.pcx]  // BACKDROP hf intro fkn huge
<hf_only><mpqset>[diabdat.mpq]

#grfx>[..27][pcx8][auto][auto][auto][...1][.666][auto][...0][...0][ui_art\mainmenu.pcx] /* black goathead backdrop /*
#grfx>[..27][pcx8][auto][auto][auto][...1][.666][auto][...0][...0][ui_art\selhero.pcx] /* select hero backdrop /*
#grfx>[..27][pcx8][auto][auto][auto][...1][.666][auto][...0][...0][ui_art\selgame.pcx] /* select difficutly backdrop */
#grfx>[..27][pcx8][auto][auto][auto][...1][.666][auto][...0][...0][ui_art\credits.pcx] /* credits */

#grfx>[..33][icel][.320][.352][..12][auto][auto][auto][...0][...0][data\inv\inv.cel] //INV_BACKDROP loaded per class
#grfx>[..33][icel][.320][.352][..12][auto][auto][auto][...0][...0][data\inv\inv_rog.cel] //INV_BACKDROP loaded per class
#grfx>[..33][icel][.320][.352][..12][auto][auto][auto][...0][...0][data\inv\inv_sor.cel] //INV_BACKDROP loaded per class

<grfx>[..34][icel][.320][.352][..12][auto][auto][auto][...0][...0][data\char.cel] //CHAR_BACKDROP 
<uifuse>[..35][orbs][..12] // [kepr][alog][paln] This is a hardcoded hack to fuse the dashboard with the empty orbs
<uifuse>[..36][stsh][..12] //  This is a hardcoded hack to fuse the stash from the quest and inventory
<grfx>[..37][icel][..71][..19][..12][auto][auto][auto][...0][...0][ctrlpan\panel8bu.cel] // the buttons on the dashboard



#grfx>[..49][pcx8][auto][auto][auto][...1][...3][auto][...0][...0][ddtmpq\grfx\bluetile.pcx]



#grfx>[..50][town][..32][..32][..12][auto][auto][auto][...0][...0][levels\towndata\town.cel]
#grfx>[..50][town][..32][..32][..12][auto][auto][auto][...0][...0][NLevels\TownData\Town.CEL]
#grfx>[..51][town][..64][.160][..12][auto][auto][auto][...0][...0][levels\towndata\towns.cel]

#grfx>[..50][town][..32][..32][..14][auto][auto][auto][...0][...0][levels\l1data\l1.cel]
#grfx>[..51][town][..64][.160][..14][auto][auto][auto][...0][...0][levels\l1data\l1s.cel]

#grfx>[..50][town][..32][..32][..21][auto][auto][auto][...0][...0][levels\l2data\l2.cel]
#grfx>[..51][town][..64][.160][..21][auto][auto][auto][...0][...0][levels\l2data\l2s.cel]

#grfx>[..50][town][..32][..32][..31][auto][auto][auto][...0][...0][levels\l3data\l3.cel]
#grfx>[..50][town][..32][..32][..40][auto][auto][auto][...0][...0][levels\l4data\l4.cel]

#grfx>[..50][town][..32][..32][.192][auto][auto][auto][...0][...0][NLevels\L5Data\L5.cel]
#grfx>[..51][town][..64][.160][.192][auto][auto][auto][...0][...0][NLevels\L5Data\L5S.cel]

#grfx>[..50][town][..32][..32][.194][auto][auto][auto][...0][...0][NLevels\l6data\L6.cel]


<grfx>[..50][town][..96][.160][..12][auto][auto][auto][auto][...0][items\goldflip.cel] // ITEM_FLIP_MONEY_G 50



/* music */
<sfx>[-..1][music\dintro.wav]

/* sounds */
<sfx>[...1][sfx\items\titlslct.wav]
<sfx>[...2][sfx\items\titlemov.wav]

<sfx>[..50][sfx\items\gold1.wav] // ITEM_FLIP_MONEY_A 50



<end>








***************************************************
