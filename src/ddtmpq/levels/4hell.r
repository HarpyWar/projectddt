<begin>


<datablock>[....][level]

(sectors)[.350] 


**************************************************************************************************
***Test level*************************************************************************************
**************************************************************************************************
(sector)[...0]
    (recursec)[..57][...0][...0] // empty 128x128 patch of ground tiles

    (tile)[...2][...0] (mech)[...8][+] //up to test caves
    (tile)[...0][...2] (mech)[...9][+] //down to test hive

    (tile)[...0][...5] (monster)[...1][ra] //cow


    (recursec)[..60][...0][...0]  //unlid pentagram on ground

    (recursec)[..61][...0][...9]  //lid pentagram on ground

    (recursec)[..62][...0][..18]  //stairs up
    (recursec)[..63][...0][..27]  //stairs down

    (recursec)[..10][..12][..00]  //test-room 1 12x12
    (recursec)[..11][..30][..00]  //test room 2 lava

    (recursec)[.114][..16][..21]  
    (recursec)[.115][..12][..21]  
    (recursec)[.116][..12][..25] 
    (recursec)[.117][..12][..29] 

    (recursec)[.125][..12][..35] //random doodad meta-ready
    (recursec)[.125][..12][..40] //random doodad meta-ready
    (recursec)[.125][..12][..45] //random doodad meta-ready
    (recursec)[.125][..12][..50] //random doodad meta-ready
    (recursec)[.125][..12][..55] //random doodad meta-ready
    (recursec)[.125][..12][..60] //random doodad meta-ready
    (recursec)[.125][..12][..65] //random doodad meta-ready

    (recursec)[.125][..16][..35] //random doodad meta-ready
    (recursec)[.125][..16][..40] //random doodad meta-ready
    (recursec)[.125][..16][..45] //random doodad meta-ready
    (recursec)[.125][..16][..50] //random doodad meta-ready
    (recursec)[.125][..16][..55] //random doodad meta-ready
    (recursec)[.125][..16][..60] //random doodad meta-ready
    (recursec)[.125][..16][..65] //random doodad meta-ready

    (recursec)[.161][..26][..26] //double wall left-up to right-down 2x4 161
    (recursec)[.162][..30][..26] //double wall left-down to right-up 4x2 162
    (recursec)[.163][..35][..26] //double wall corner up 4x4 163
    (recursec)[.164][..40][..26] //double wall corner down 4x4 164
    (recursec)[.165][..45][..26] //double wall corner left 4x4 165
    (recursec)[.166][..50][..26] //double wall corner right 4x4 166
    (recursec)[.167][..55][..26] //double wall dead-end right-down 2x4 167

   (recursec)[.170][...4][..40]//pillar 170




    (recursec)[.200][..27][..41] // lev16 challange 1 spiral 200
    (recursec)[.201][..50][..41] // lev16 challange 2 closed 201
    (recursec)[.202][..50][..55] // lev16 challange 2 opened 202


    (recursec)[.205][..62][..40] // lev16 challange 3 opened 205
    (recursec)[.204][..62][..65] // lev16 challange 3 closed 204

    (recursec)[.206][..90][..40]  // lev16 challange 4 final closed 206
    (recursec)[.207][..90][..60] // lev16 challange 4 final open 207






(sector_end)

(sector)[..10] test room 1 12x12
    (recursec)[.100][...0][...6] //wall dead-end up_left meta-ready
    (recursec)[.113][...2][...6] //wall tri-fork dead-end right-down meta-ready
    (recursec)[..69][...2][...4] //wall left alt random 2x2 meta-ready
    (recursec)[..99][...2][...2] //wall left corner meta-ready
    (recursec)[..75][...4][...2] //wall right alt random 2x2  meta-ready
    (recursec)[..88][...6][...2] //wall trifork right-up deadend meta-ready
    (recursec)[.103][...6][...0] //wall dead-end down-left meta-ready
    (recursec)[..86][...2][...8] //wall corner up meta-ready
    (recursec)[..94][...8][...2] //wall corner down meta-ready
    (recursec)[.112][...4][...8] //wall tri-fork dead-end left-down meta-ready 112
    (recursec)[.111][...4][..10] //wall dead-end up_right meta-ready
    (recursec)[..87][...8][...4] //wall trifork left-up deadend meta-ready
    (recursec)[.110][..10][...4] //wall dead-end down right meta-ready
    (recursec)[..69][...8][...6] //wall left alt random 2x2 meta-ready
    (recursec)[..75][...6][...8] //wall right alt random 2x2  meta-ready
    (recursec)[..85][...8][...8] //wall crossing meta-ready
    (recursec)[..86][...8][..10] //wall corner up meta-ready
    (recursec)[..94][..10][...8] //wall corner down meta-ready
    (recursec)[.109][..10][..10] //wall right corner meta-ready
(sector_end)

(sector)[..11] test room 2 lava

    (recursec)[..99][...0][...6] //wall left corner meta-ready
    (recursec)[.129][...0][...8] //lavablock wall left meta-ready
    (recursec)[.138][..00][..10] //lavablock wall upper_corner meta-ready
    (recursec)[.100][...0][..14] //wall dead-end up_left meta-ready

    (recursec)[.100][...2][...2] //wall dead-end up_left meta-ready
    (recursec)[..75][...2][...6] //wall right alt random 2x2  meta-ready
    (recursec)[.144][...2][...8] //lavablock no wall meta-ready
    (recursec)[.139][...2][..10] //lavablock wall lower_corner meta-ready
    (recursec)[.129][...2][..12] //lavablock wall left meta-ready
    (recursec)[.137][...2][..14] //lavablock wall crossing meta-ready
    (recursec)[.111][...2][..16] //wall dead-end up_right meta-ready

    (recursec)[..99][...4][...0] //wall left corner meta-ready
    (recursec)[.142][...4][...2] //lavablock crossing lava down&right meta-ready
    (recursec)[.129][...4][...4] //lavablock wall left meta-ready
    (recursec)[.127][...4][...6] //lavablock corner right meta-ready
    (recursec)[.144][...4][...8] //lavablock no wall meta-ready
    (recursec)[.144][...4][..10] //lavablock no wall meta-ready
    (recursec)[.144][...4][..12] //lavablock no wall meta-ready
    (recursec)[.130][...4][..14] //lavablock wall right meta-ready

    (recursec)[..94][...6][...0] //wall corner down meta-ready
    (recursec)[..69][...6][...2] //wall left alt random 2x2 meta-ready
    (recursec)[..87][...6][...4] //wall trifork left-up deadend meta-ready
    (recursec)[..69][...6][...6] //wall left alt random 2x2 meta-ready
    (recursec)[..86][...6][...8] //wall corner up meta-ready
    (recursec)[.128][...6][..10] //lavablock corner left meta-ready
    (recursec)[..69][...6][..12] //wall left alt random 2x2 meta-ready
    (recursec)[.109][...6][..14] //wall right corner meta-ready

    (recursec)[.129][...8][...2] //lavablock wall left meta-ready
    (recursec)[.140][...8][...4] //lavablock tri dead-end right-up lava only down meta-ready
    (recursec)[..75][...8][...8] //wall right alt random 2x2  meta-ready
    (recursec)[.130][...8][..10] //lavablock wall right meta-ready

    (recursec)[.144][..10][...2] //lavablock no wall meta-ready
    (recursec)[.139][..10][...4] //lavablock wall lower_corner meta-ready 139
    (recursec)[.141][..10][...6] //lavablock tri dead-end left-up lava only down meta-ready
    (recursec)[..88][..10][...8] //wall trifork right-up deadend meta-ready
    (recursec)[.143][..10][..10] //lavablock crossing lava down&left meta-ready
    (recursec)[.111][..10][..12] //wall dead-end up_right meta-ready

    (recursec)[..69][..12][...2] //wall left alt random 2x2 meta-ready
    (recursec)[..69][..12][...4] //wall left alt random 2x2 meta-ready
    (recursec)[.109][..12][...6] //wall right corner meta-ready 109
    (recursec)[..94][..12][...8] //wall corner down meta-ready
    (recursec)[.109][..12][..10] //wall right corner meta-ready


(sector_end)

**************************************************************************************************
***Level 13***************************************************************************************
**************************************************************************************************
(sector)[...1]

  (recursec)[..57][...0][...0] // empty 128x128 patch of ground tiles
  (tile)[...2][...0] (mech)[..38][+] //warp up 
  (tile)[...0][...2] (mech)[..39][+] //warp down
  (tile)[...2][...2] (mech)[..74][+] //warp town shortcut
(sector_end)


**************************************************************************************************
***Level 14***************************************************************************************
**************************************************************************************************
(sector)[...2]

  (recursec)[..57][...0][...0] // empty 128x128 patch of ground tiles
  (tile)[...2][...0] (mech)[..40][+] //warp up 
  (tile)[...0][...2] (mech)[..41][+] //warp down
(sector_end)

**************************************************************************************************
***Level 15***************************************************************************************
**************************************************************************************************
(sector)[...3]
   

   (rnd_dum_disp)[.150][.151][.152][.153][.154][.155][.156][.157] //dumies a to h

   (recursec)[.220][...0][...0] //radom level basis 220


(sector_end)

**************************************************************************************************
***Level 16***************************************************************************************
**************************************************************************************************
(sector)[...4]

  (tile)[..00][..00] (mech)[.125][+] //assure load lever
  (tile)[..01][..00] (monster)[..50][ra] //assure load big-daddy

  (recursec)[..57][...0][...0] // empty 128x128 patch of ground tiles



   // pool border


  (recursec)[.148][...0][...0] //lavablock 32x32
  (recursec)[.148][..32][...0] //lavablock 32x32
  (recursec)[.148][..64][...0] //lavablock 32x32
  (recursec)[.148][..96][...0] //lavablock 32x32

  (recursec)[.148][...0][..32] //lavablock 32x32
  (recursec)[.148][...0][..64] //lavablock 32x32
  (recursec)[.148][...0][..96] //lavablock 32x32

  (recursec)[.148][.100][..32] //lavablock 32x32
  (recursec)[.148][.100][..64] //lavablock 32x32
  (recursec)[.148][.100][..96] //lavablock 32x32

  (recursec)[.148][..32][.104] //lavablock 32x32
  (recursec)[.148][..64][.104] //lavablock 32x32
  (recursec)[.148][..96][.104] //lavablock 32x32


  (recursec)[.146][..36][..64] //lavablock 8x8 146
  (recursec)[.146][..44][..64] //lavablock 8x8 146
  (recursec)[.146][..52][..64] //lavablock 8x8 146
  (recursec)[.146][..72][..64] //lavablock 8x8 146
  (recursec)[.146][..80][..64] //lavablock 8x8 146
  (recursec)[.146][..88][..64] //lavablock 8x8 146

  (recursec)[.145][..32][..64]//lavablock 4x4 145
  (recursec)[.145][..32][..68]//lavablock 4x4 145
  (recursec)[.145][..96][..64]//lavablock 4x4 145
  (recursec)[.145][..96][..68]//lavablock 4x4 145

  (recursec)[.128][..32][..32] //lavablock corner left meta-ready
  (recursec)[.154][..32][..34] //wall left 8x
  (recursec)[.153][..32][..50] //wall left 4x
  (recursec)[.152][..32][..58] //wall left 2x
  (recursec)[..86][..32][..62]//wall  corner up meta-ready 86

  (recursec)[.157][..34][..32]//lava wall right 8x 157
  (recursec)[.157][..50][..32]//lava wall right 8x 157
  (recursec)[.157][..66][..32]//lava wall right 8x 157
  (recursec)[.157][..82][..32]//lava wall right 8x 157

  (recursec)[.139][..98][..32]//lavablock wall lower_corner meta-ready 139
  (recursec)[.151][..98][..34] //lava wall left 8x
  (recursec)[.150][..98][..50] //lava wall left 4x
  (recursec)[.149][..98][..58] //lava wall left 2x

  (recursec)[.160][..34][..62]//wall right 8x 160
  (recursec)[.159][..50][..62]//wall right 4x 159
  (recursec)[..75][..58][..62] //wall right alt random 2x2  meta-ready 75

  (recursec)[.127][..98][..62]//lavablock corner right meta-ready 127

  (recursec)[.160][..82][..62]//wall right 8x 160
  (recursec)[.159][..74][..62]//wall right 4x 159
  (recursec)[..75][..72][..62] //wall right alt random 2x2  meta-ready 75

  (recursec)[.112][..60][..62]//wall tri-fork dead-end left-down meta-ready 112
  (recursec)[..75][..62][..62]//wall right alt random 2x2  meta-ready 75
  (recursec)[.115][..64][..62]//wall arch dead-end right-down meta-ready 115
  (recursec)[.112][..70][..62]//wall tri-fork dead-end left-down meta-ready 112
  (recursec)[.114][..68][..62]//wall arch dead-end left-up meta-ready 114

  (recursec)[.153][..60][..64] //wall left 4x
  (recursec)[.150][..70][..64] //lava wall left 4x

  (recursec)[..88][..60][..72] //wall trifork right-up deadend meta-ready
  (recursec)[.140][..70][..72] //lavablock tri dead-end right-up lava only down meta-ready

  (recursec)[.115][..64][..72]//wall arch dead-end right-down meta-ready 115
  (recursec)[.114][..68][..72]//wall arch dead-end left-up meta-ready 114
  (recursec)[..75][..62][..72]//wall right alt random 2x2  meta-ready 75

  (recursec)[.157][..34][..72]//lava wall right 8x 157
  (recursec)[.156][..50][..72]//lava wall right 4x 156
  (recursec)[.130][..58][..72]//lavablock wall right meta-ready 130

  (recursec)[.157][..72][..72]//lava wall right 8x 157
  (recursec)[.156][..88][..72]//lava wall right 4x 156
  (recursec)[.130][..96][..72]//lavablock wall right meta-ready 130

  (recursec)[.128][..32][..72] //lavablock corner left meta-ready
  (recursec)[.139][..98][..72]//lavablock wall lower_corner meta-ready 139

  (recursec)[.154][..32][..74] //wall left 8x
  (recursec)[.153][..32][..90] //wall left 4x
  (recursec)[.152][..32][..98] //wall left 2x
  (recursec)[..86][..32][.102]//wall  corner up meta-ready 86

  (recursec)[.151][..98][..74] //lava wall left 8x
  (recursec)[.150][..98][..90] //lava wall left 4x
  (recursec)[.149][..98][..98] //lava wall left 2x
  (recursec)[.127][..98][.102]//lavablock corner right meta-ready 127

  (recursec)[.160][..34][.102]//wall right 8x 160
  (recursec)[.160][..50][.102]//wall right 8x 160
  (recursec)[.160][..66][.102]//wall right 8x 160
  (recursec)[.160][..82][.102]//wall right 8x 160



  (recursec)[..62][..62][..52]  //stairs up
  (tile)[..65][..54] (mech)[..44][+] //warp up
  (tile)[..65][..55] (mech)[..44][+] //warp up 

  (recursec)[.200][..74][..76] // lev16 challange 1 spiral 200

  (recursec)[.201][..43][..83] // lev16 challange 2 closed 201
            (tile)[..43][..83] (mech)[.150][+] //dummy a, reception of: lev16 challange 2 opened 202
  #recursec)[.202][..43][..83] // lev16 challange 2 opened 202


  (recursec)[.204][..37][..37] // lev16 challange 3 closed 204
            (tile)[..37][..37] (mech)[.151][+] //dummy b, reception of: lev16 challange 3 opened 205


  (recursec)[.206][..76][..39] // lev16 challange 4 final closed 206
            (tile)[..76][..39] (mech)[.152][+] //dummy c, reception of: lev16 challange 4 final opened 206



(sector_end)

**************************************************************************************************
***Components*************************************************************************************
**************************************************************************************************


 //random ground tile 1x1
(sector)[..50] (texg)[...0]
    (tile)[...0][...0]
    (clean_air)
    (move)[all]
    (light_op)[normal]
    (rand)[..43]

    (if_rand)[...0] (ground)[.04e][.04f] (ground_alt)[.04e][.04f]
    (if_rand)[...1] (ground)[.04c][.04d] (ground_alt)[.04c][.04d]

    (if_rand)[...2] (ground)[.00a][.00b] (ground_alt)[.00a][.00b]
    (if_rand)[...3] (ground)[.050][.051] (ground_alt)[.050][.051]
    (if_rand)[...4] (ground)[.012][.013] (ground_alt)[.012][.013]
    (if_rand)[...5] (ground)[.040][.041] (ground_alt)[.040][.041]

    (if_rand)[...6] (ground)[.182][.183] (ground_alt)[.182][.183]
    (if_rand)[...7] (ground)[.0e6][.0e7] (ground_alt)[.0e6][.0e7]
    (if_rand)[...8] (ground)[.042][.043] (ground_alt)[.042][.043]
    (if_rand)[...9] (ground)[.0dd][.0de] (ground_alt)[.0dd][.0de]
    (if_rand)[..10] (ground)[.052][.053] (ground_alt)[.052][.053]
    (if_rand)[..11] (ground)[.0ed][.0ee] (ground_alt)[.0ed][.0ee]

    (if_rand)[..12] (ground)[.184][.185] (ground_alt)[.184][.185]
    (if_rand)[..13] (ground)[.1a0][.1a1] (ground_alt)[.1a0][.1a1]
    (if_rand)[..14] (ground)[.137][.138] (ground_alt)[.137][.138]
    (if_rand)[..15] (ground)[.139][.13a] (ground_alt)[.139][.13a]
    (if_rand)[..16] (ground)[.0df][.0e0] (ground_alt)[.0df][.0e0]
    (if_rand)[..17] (ground)[.024][.025] (ground_alt)[.024][.025]
    (if_rand)[..18] (ground)[.135][.136] (ground_alt)[.135][.136]
    (if_rand)[..19] (ground)[.143][.144] (ground_alt)[.143][.144]

    (if_rand)[..20] (ground)[.2ba][.2bb] (ground_alt)[.2ba][.2bb]
    (if_rand)[..21] (ground)[.18a][.18b] (ground_alt)[.18a][.18b]
    (if_rand)[..22] (ground)[.18c][.18d] (ground_alt)[.18c][.18d]
    (if_rand)[..23] (ground)[.1d3][.1d4] (ground_alt)[.1d3][.1d4]
    (if_rand)[..24] (ground)[.1a2][.1a3] (ground_alt)[.1a2][.1a3]
    (if_rand)[..25] (ground)[.1a4][.1a5] (ground_alt)[.1a4][.1a5]
    (if_rand)[..26] (ground)[.141][.142] (ground_alt)[.141][.142]

    (if_rand)[..27] (ground)[.316][.317] (ground_alt)[.316][.317]
    (if_rand)[..28] (ground)[.310][.311] (ground_alt)[.310][.311]
    (if_rand)[..29] (ground)[.340][.341] (ground_alt)[.340][.341]
    (if_rand)[..30] (ground)[.294][.295] (ground_alt)[.294][.295]
    (if_rand)[..31] (ground)[.266][.267] (ground_alt)[.266][.267]
    (if_rand)[..32] (ground)[.278][.279] (ground_alt)[.278][.279]
    (if_rand)[..33] (ground)[.27a][.27b] (ground_alt)[.27a][.27b]
    (if_rand)[..34] (ground)[.24a][.24b] (ground_alt)[.24a][.24b]
    (if_rand)[..35] (ground)[.21d][.21e] (ground_alt)[.21d][.21e]

    (if_rand)[..36] (ground)[.363][.364] (ground_alt)[.363][.364]
    (if_rand)[..37] (ground)[.2d8][.2d9] (ground_alt)[.2d8][.2d9]
    (if_rand)[..38] (ground)[.2d6][.2d7] (ground_alt)[.2d6][.2d7]
    (if_rand)[..39] (ground)[.201][.202] (ground_alt)[.201][.202]
    (if_rand)[..40] (ground)[.22e][.22f] (ground_alt)[.22e][.22f]
    (if_rand)[..41] (ground)[.21b][.21c] (ground_alt)[.21b][.21c]
    (if_rand)[..42] (ground)[.1c3][.1c4] (ground_alt)[.1c3][.1c4]
    (if_rand)[..43] (ground)[.19b][.19c] (ground_alt)[.19b][.19c]

    *if_rand)[..44] *ground)[.149][.14a]
    *if_rand)[..45] *ground)[.23e][.23f]
    *if_rand)[..46] *ground)[.13d][.13e]
    *if_rand)[..47] *ground)[.190][.191]
    *if_rand)[..48] *ground)[.145][.146]
    *if_rand)[..49] *ground)[.34e][.34f]
(sector_end)

// empty 2x2 patch of ground tiles
(sector)[..51] (texg)[...0]
    (recursec)[..50][...0][...0] //random ground tile 1x1
    (recursec)[..50][...1][...0]
    (recursec)[..50][...0][...1]
    (recursec)[..50][...1][...1]
(sector_end)

// empty 4x4 patch of ground tiles 52
(sector)[..52] (texg)[...0]
    (recursec)[..51][...0][...0] //random ground tile 2x2
    (recursec)[..51][...2][...0]
    (recursec)[..51][...0][...2]
    (recursec)[..51][...2][...2]
(sector_end)

// empty 8x8 patch of ground tiles 53
(sector)[..53] (texg)[...0]
    (recursec)[..52][...0][...0] //random ground tile 4x4
    (recursec)[..52][...4][...0]
    (recursec)[..52][...0][...4]
    (recursec)[..52][...4][...4]
(sector_end)

// empty 16x16 patch of ground tiles 54
(sector)[..54] (texg)[...0]
    (recursec)[..53][...0][...0] //random ground tile 8x8
    (recursec)[..53][...8][...0]
    (recursec)[..53][...0][...8]
    (recursec)[..53][...8][...8]
(sector_end)

// empty 32x32 patch of ground tiles
(sector)[..55] (texg)[...0]
    (recursec)[..54][...0][...0] //random ground tile 16x16
    (recursec)[..54][..16][...0]
    (recursec)[..54][...0][..16]
    (recursec)[..54][..16][..16]
(sector_end)

// empty 64x64 patch of ground tiles 56
(sector)[..56] (texg)[...0]
    (recursec)[..55][...0][...0] //random ground tile 32x32
    (recursec)[..55][..32][...0]
    (recursec)[..55][...0][..32]
    (recursec)[..55][..32][..32]
(sector_end)

// empty 128x128 patch of ground tiles
(sector)[..57] (texg)[...0]
    (recursec)[..56][...0][...0] //random ground tile 64x64
    (recursec)[..56][..64][...0]
    (recursec)[..56][...0][..64]
    (recursec)[..56][..64][..64]
(sector_end)





 //unlid pentagram on ground 8x8 60
(sector)[..60] (texg)[...0]
    (tile)[...1][...1] (ground)[.39b][.39c]
    (tile)[...2][...1] (ground)[.39d][.39e]
    (tile)[...3][...1] (ground)[.3b3][.3b4]
    (tile)[...4][...1] (ground)[.3b5][.3b6]
    (tile)[...5][...1] (ground)[.3c3][.3c4]
    (tile)[...6][...1] (ground)[.3c5][.3c6]

    (tile)[...1][...2] (ground)[.397][.398]
    (tile)[...2][...2] (ground)[.399][.39a]
    (tile)[...3][...2] (ground)[.3af][.3b0]
    (tile)[...4][...2] (ground)[.3b1][.3b2]
    (tile)[...5][...2] (ground)[.3bf][.3c0]
    (tile)[...6][...2] (ground)[.3c1][.3c2]

    (tile)[...1][...3] (ground)[.38b][.38c]
    (tile)[...2][...3] (ground)[.38d][.38e]
    (tile)[...3][...3] (ground)[.3a3][.3a4]
    (tile)[...4][...3] (ground)[.3a5][.3a6]
    (tile)[...5][...3] (ground)[.3bb][.3bc]
    (tile)[...6][...3] (ground)[.3bd][.3be]

    (tile)[...1][...4] (ground)[.387][.388]
    (tile)[...2][...4] (ground)[.389][.38a]
    (tile)[...3][...4] (ground)[.39f][.3a0]
    (tile)[...4][...4] (ground)[.3a1][.3a2]
    (tile)[...5][...4] (ground)[.3b7][.3b8]
    (tile)[...6][...4] (ground)[.3b9][.3ba]

    (tile)[...1][...5] (ground)[.383][.384]
    (tile)[...2][...5] (ground)[.385][.386]
    (tile)[...3][...5] (ground)[.393][.394]
    (tile)[...4][...5] (ground)[.395][.396]
    (tile)[...5][...5] (ground)[.3ab][.3ac]
    (tile)[...6][...5] (ground)[.3ad][.3ae]

    (tile)[...1][...6] (ground)[.37f][.380]
    (tile)[...2][...6] (ground)[.381][.382]
    (tile)[...3][...6] (ground)[.38f][.390]
    (tile)[...4][...6] (ground)[.391][.392]
    (tile)[...5][...6] (ground)[.3a7][.3a8]
    (tile)[...6][...6] (ground)[.3a9][.3aa]
(sector_end)

 //lid pentagram on ground 8x8 61
(sector)[..61] (texg)[...0]

    (tile)[...2][...1] (ground)[.39d][.3e0] (light_op)[gooze]
    (tile)[...3][...1] (ground)[.3f1][.3f2] (light_op)[gooze]
    (tile)[...4][...1] (ground)[.3f3][.3f4] (light_op)[gooze]
    (tile)[...5][...1] (ground)[.401][.402] (light_op)[gooze]

    (tile)[...1][...2] (ground)[.397][.3dd] (light_op)[gooze]
    (tile)[...2][...2] (ground)[.3de][.3df] (light_op)[gooze]
    (tile)[...3][...2] (ground)[.3ed][.3ee] (light_op)[gooze]
    (tile)[...4][...2] (ground)[.3ef][.3f0] (light_op)[gooze]
    (tile)[...5][...2] (ground)[.3fd][.3fe] (light_op)[gooze]
    (tile)[...6][...2] (ground)[.3ff][.400] (light_op)[gooze]

    (tile)[...1][...3] (ground)[.3d1][.3d2] (light_op)[gooze]
    (tile)[...2][...3] (ground)[.3d3][.3d4] (light_op)[gooze]
    (tile)[...3][...3] (ground)[.3e5][.3e6] (light_op)[gooze]
    (tile)[...4][...3] (ground)[.3e7][.3e8] (light_op)[gooze]
    (tile)[...5][...3] (ground)[.3f9][.3fa] (light_op)[gooze]
    (tile)[...6][...3] (ground)[.3fb][.3fc] (light_op)[gooze]

    (tile)[...1][...4] (ground)[.3cd][.3ce] (light_op)[gooze]
    (tile)[...2][...4] (ground)[.3cf][.3do] (light_op)[gooze]
    (tile)[...3][...4] (ground)[.3e1][.3e2] (light_op)[gooze]
    (tile)[...4][...4] (ground)[.3e3][.3e4] (light_op)[gooze]
    (tile)[...5][...4] (ground)[.3f5][.3f6] (light_op)[gooze]
    (tile)[...6][...4] (ground)[.3f7][.3f8] (light_op)[gooze]

    (tile)[...1][...5] (ground)[.3c9][.3ca] (light_op)[gooze]
    (tile)[...2][...5] (ground)[.3cb][.3cc] (light_op)[gooze]
    (tile)[...3][...5] (ground)[.3d9][.3da] (light_op)[gooze]
    (tile)[...4][...5] (ground)[.3db][.3dc] (light_op)[gooze]
    (tile)[...5][...5] (ground)[.3ea][.3eb] (light_op)[gooze]
    (tile)[...6][...5] (ground)[.3ec][.3ae] (light_op)[gooze]


    (tile)[...2][...6] (ground)[.3c7][.3c8] (light_op)[gooze]
    (tile)[...3][...6] (ground)[.3d5][.3d6] (light_op)[gooze]
    (tile)[...4][...6] (ground)[.3d7][.3d8] (light_op)[gooze]
    (tile)[...5][...6] (ground)[.3e9][.3a8] (light_op)[gooze]

(sector_end)


 //stairs up 8x8
(sector)[..62] (texg)[...0]
    (tile)[...4][...1] (ground)[..d9][.0da]
    (tile)[...5][...1] (ground)[.0db][.0dc]

    (tile)[...1][...2] (ground)[.129][.12a]
    (tile)[...2][...2] (ground)[.106][.107]
    (tile)[...3][...2] (ground)[.108][.109]
    (tile)[...4][...2] (ground)[.0f3][.0f4] (move)[fly]
    (tile)[...5][...2] (ground)[.0f5][.0f6] (move)[fly]
    (tile)[...6][...2] (ground)[.0eb][.0ec]

    (tile)[...0][...3] (ground)[.123][.124]
    (tile)[...1][...3] (ground)[.125][.126]
    (tile)[...2][...3] (ground)[.0fc][.0fd] (move)[none]
    (tile)[...3][...3] (ground)[.101][.102]
    (tile)[...4][...3] (ground)[.0ef][.0f0] (move)[none](light)[.255][.255][.255][...6]
    (tile)[...5][...3] (ground)[.0f1][.0f2] (move)[none]
    (tile)[...6][...3] (ground)[.0e4][.0e5]

    (tile)[...0][...4] (ground)[.11f][.120]
    (tile)[...1][...4] (ground)[.121][.122]
    (tile)[...2][...4] (ground)[.12f][.130] (move)[none]
    (tile)[...3][...4] (ground)[.131][.132] (move)[none]
    (tile)[...4][...4] (move)[none]
    (tile)[...5][...4] (ground)[-001][.11a] (move)[none]

    (tile)[...0][...5] (ground)[.11b][.11c]
    (tile)[...1][...5] (ground)[.11d][.11e]
    (tile)[...2][...5] (ground)[.12b][.12c] (move)[none]
    (tile)[...3][...5] (ground)[.12d][.12e] (move)[none]
    (tile)[...4][...5] (ground)[-001][.111] (move)[none]
    (tile)[...5][...5] (ground)[.114][.115] (move)[none]

    (tile)[...4][...5]
       (air)[.10f][..32][..32]
       (air)[.10d][..32][..64]
       (air)[.10b][..32][..96]
       (air)[.113][..64][..16]
       (air)[.112][..64][..48]

    (tile)[...5][...4]
       (air)[..e3][..00][..00]
       (air)[..e2][..00][..32]
       (air)[.110][..00][..32]
       (air)[..e1][..00][..64]
       (air)[.10e][..00][..64]
       (air)[.10c][..00][..96]
       (air)[.10a][..00][.128]

    (tile)[...4][...4]
       (air)[..e9][..00][..00]
       (air)[.119][..00][..00]
       (air)[..e8][..00][..32]
       (air)[.118][..00][..32]
       (air)[.117][..00][..64]
       (air)[.116][..00][..96]

    (tile)[...3][...4]
       (air)[.100][..00][..16]
       (air)[..ff][..00][..48]
       (air)[..fe][..00][..80]

    (tile)[...2][...4]
       (air)[..fb][..00][..16]
       (air)[..f9][..00][..48]

    (tile)[...2][...3]
       (air)[..fa][..00][..32]
       (air)[..f8][..00][..64]
       (air)[..f7][..00][..96]
       (air)[.103][-.32][.112]

    (tile)[...1][...3]
       (air)[.105][..00][..00]

    (tile)[...5][...3]
       (air)[..ea][..00][..00]

(sector_end)

 //stairs down 8x8
(sector)[..63] (texg)[...0]
    (tile)[...4][...1] (ground)[.159][.15a]
    (tile)[...5][...1] (ground)[.15b][.15c]

    (tile)[...2][...2] (ground)[.17b][.17c] (move)[none]
    (tile)[...3][...2] (ground)[.180][.181] (move)[none]
    (tile)[...4][...2] (ground)[.151][.152] (move)[none]
    (tile)[...5][...2] (ground)[.157][.158] (move)[none]
    (tile)[...6][...2] (ground)[.133][.134] 

    (tile)[...2][...3] (move)[none]
    (tile)[...3][...3] (move)[none]
    (tile)[...4][...3] (ground)[.161][.162] (move)[none](light)[.255][.255][.255][...6]
    (tile)[...5][...3] (ground)[.163][.164] 
    (tile)[...6][...3] (ground)[.13f][.140] 

    (tile)[...2][...4] (move)[none]
    (tile)[...3][...4] (move)[none]
    (tile)[...4][...4] (ground)[.15d][.15e] (move)[none]
    (tile)[...5][...4] (ground)[.15f][.160] 
    (tile)[...6][...4] (ground)[.13b][.13c]

    (tile)[...2][...5] (move)[none]
    (tile)[...3][...5] (move)[none]
    (tile)[...4][...5] (ground)[.175][.176] (move)[none]
    (tile)[...5][...5] (ground)[.177][.178] (move)[none]
    (tile)[...6][...5] (ground)[.147][.148]

    (tile)[...2][...6] (move)[none]
    (tile)[...3][...6] (move)[none]
    (tile)[...4][...6] (ground)[.16f][.170] (move)[none]
    (tile)[...5][...6] (ground)[.171][.172] 

    (tile)[...2][...2]
       (air)[.17a][..32][..32]

    (tile)[...3][...2]
       (air)[.14f][..32][..16]
       (air)[.17f][..32][..32]
       (air)[.14d][..32][..48]
       (air)[.17e][..32][..64]
       (air)[.14b][..32][..80]
       (air)[.17d][..32][..96]
    (tile)[...2][...3]
       (air)[.167][..32][..16]
       (air)[.165][..32][..48]

    (tile)[...4][...2]
       (air)[.150][..32][..32]
       (air)[.16b][..32][..48]
       (air)[.14e][..32][..64]
       (air)[.14c][..32][..96]
    (tile)[...3][...3]
       (air)[.16d][..32][..00]
       (air)[.168][..32][..32]
       (air)[.166][..32][..64]

    (tile)[...5][...2]
       (air)[.156][..32][..32]
       (air)[.155][..32][..64]
       (air)[.154][..32][..96]
       (air)[.153][..32][.128]
    (tile)[...3][...4]
       (air)[.16c][..32][..00]
       (air)[.16a][..32][..32]
       (air)[.169][..32][..64]

    (tile)[...4][...4]
       (air)[.174][..32][..48]
       (air)[.173][..32][..80]

    (tile)[...4][...5]
       (air)[.16e][..32][..48]
(sector_end)


 //wall left alt a 2x2
(sector)[..64] (texg)[...0] 
    (tile)[...0][...0] (ground)[..10][..11]
       (air)[...f][..00][..32]
       (air)[...e][..00][..64]
       (air)[...d][..00][..96]
       (air)[...c][..00][.128]
    (tile)[...0][...1] (ground)[...6][...7]
       (air)[...4][..00][..32]
       (air)[...2][..00][..64]
       (air)[...0][..00][..96]
       (air)[...5][..32][..32]
       (air)[...3][..32][..64]
       (air)[...1][..32][..96]
       (air)[...8][..64][..80]
(sector_end)

 //wall left alt b 2x2
(sector)[..65] (texg)[...0] 
    (tile)[...0][...0] (ground)[.207][.208]
       (air)[.206][..00][..32]
       (air)[.205][..00][..64]
       (air)[.204][..00][..96]
       (air)[.203][..00][.128]
    (tile)[...0][...1] (ground)[.1fd][.1fe]
       (air)[.1fb][..00][..32]
       (air)[.1f9][..00][..64]
       (air)[.1f7][..00][..96]
       (air)[.1fc][..32][..32]
       (air)[.1fa][..32][..64]
       (air)[.1f8][..32][..96]
       (air)[.1ff][..64][..80]
(sector_end)

 //wall left alt c 2x2
(sector)[..66] (texg)[...0]
    (tile)[...0][...0] (ground)[.22c][.22d]
       (air)[.22b][..00][..32]
       (air)[.22a][..00][..64]
       (air)[.229][..00][..96]
    (tile)[...0][...1] (ground)[.225][.226]
       (air)[.223][..00][..32]
       (air)[.221][..00][..64]
       (air)[.21f][..00][..96]
       (air)[.224][..32][..32]
       (air)[.222][..32][..64]
       (air)[.220][..32][..96]
       (air)[.1ff][..64][..80]
(sector_end)

 //wall left alt d 2x2
(sector)[..67] (texg)[...0] 
    (tile)[...0][...0] (ground)[.250][.251]
       (air)[.24f][..00][..32]
       (air)[.24e][..00][..64]
       (air)[.24d][..00][..96]
       (air)[.24c][..00][.128]
    (tile)[...0][...1] (ground)[.246][.247]
       (air)[.244][..00][..32]
       (air)[.242][..00][..64]
       (air)[.240][..00][..96]
       (air)[.245][..32][..32]
       (air)[.243][..32][..64]
       (air)[.241][..32][..96]
       (air)[.249][..64][..48]
       (air)[.248][..64][..80]
(sector_end)

 //wall left alt e 2x2
(sector)[..68] (texg)[...0] 
    (tile)[...0][...0] (ground)[.264][.265]
       (air)[.263][..00][..32]
       (air)[.262][..00][..64]
       (air)[.261][..00][..96]
       (air)[.260][..00][.128]
    (tile)[...0][...1] (ground)[.25b][.25c]
       (air)[.259][..00][..32]
       (air)[.257][..00][..64]
       (air)[.255][..00][..96]
       (air)[.254][..00][.128]
       (air)[.25a][..32][..32]
       (air)[.258][..32][..64]
       (air)[.256][..32][..96]
       (air)[.25d][..64][..80]
(sector_end)

 //wall left alt random 2x2 meta-ready 69
(sector)[..69] (texg)[...0] 
    (tile)[...0][...0] (move)[none] (light_op)[proxfade]
    (tile)[...0][...1] (move)[none] (light_op)[proxfade]

    (rand)[...4]
    (if_rand)[...0] (recursec)[..64][...0][...0]  //wall left alt a 2x2
    (if_rand)[...1] (recursec)[..65][...0][...0]  //wall left alt b 2x2
    (if_rand)[...2] (recursec)[..66][...0][...0]  //wall left alt c 2x2
    (if_rand)[...3] (recursec)[..67][...0][...0]  //wall left alt d 2x2
    (if_rand)[...4] (recursec)[..68][...0][...0]  //wall left alt e 2x2
(sector_end)

 //wall right alt a 2x2
(sector)[..70] (texg)[...0] 
    (tile)[...0][...1] (ground)[..1a][..1b]
       (air)[..18][..00][..32]
       (air)[..16][..00][..64]
       (air)[..14][..00][..96]
       (air)[..22][-.32][..80]
    (tile)[...1][...1] (ground)[..20][..21]
       (air)[..19][..00][..48]
       (air)[..17][..00][..80]
       (air)[..15][..00][.112]
       (air)[..1f][..32][..32]
       (air)[..1e][..32][..64]
       (air)[..1d][..32][..96]
       (air)[..1c][..32][.128]
(sector_end)

 //wall right alt b 2x2
(sector)[..71] (texg)[...0] 
    (tile)[...0][...1] (ground)[.211][.212]
       (air)[.20f][..00][..32]
       (air)[.20d][..00][..64]
       (air)[.20b][..00][..96]
       (air)[.219][-.32][..80]
    (tile)[...1][...1] (ground)[.217][.218]
       (air)[.210][..00][..48]
       (air)[.20e][..00][..80]
       (air)[.20c][..00][.112]
       (air)[.216][..32][..32]
       (air)[.215][..32][..64]
       (air)[.214][..32][..96]
       (air)[.213][..32][.128]
(sector_end)


 //wall right alt c 2x2
(sector)[..72] (texg)[...0] 
    (tile)[...0][...1] (ground)[.235][.236]
       (air)[.233][..00][..32]
       (air)[.231][..00][..64]
       (air)[.230][..00][..96]
    (tile)[...1][...1] (ground)[.23a][.23b]
       (air)[.234][..00][..48]
       (air)[.232][..00][..80]
       (air)[.015][..00][.112]
       (air)[.239][..32][..32]
       (air)[.238][..32][..64]
       (air)[.237][..32][..96]
       (air)[.01c][..32][.128]
    (tile)[...0][...0] (ground)[.23c][.23d] (light_op)[proxfade]
(sector_end)

 //wall right alt d 2x2
(sector)[..73] (texg)[...0] 
    (tile)[...0][...1] (ground)[.26f][.270]
       (air)[.26d][..00][..32]
       (air)[.26b][..00][..64]
       (air)[.269][..00][..96]
       (air)[.277][-.32][..80]
    (tile)[...1][...1] (ground)[.275][.276]
       (air)[.26e][..00][..48]
       (air)[.26c][..00][..80]
       (air)[.26a][..00][.112]
       (air)[.268][..00][.144]
       (air)[.274][..32][..32]
       (air)[.273][..32][..64]
       (air)[.272][..32][..96]
       (air)[.271][..32][.128]
(sector_end)

 //wall right alt e 2x2
(sector)[..74] (texg)[...0] 
    (tile)[...0][...1] (ground)[.282][.283]
       (air)[.280][..00][..32]
       (air)[.27e][..00][..64]
       (air)[.27c][..00][..96]
       (air)[.28b][-.32][..48]
       (air)[.28a][-.32][..80]
    (tile)[...1][...1] (ground)[.288][.289]
       (air)[.281][..00][..48]
       (air)[.27f][..00][..80]
       (air)[.27d][..00][.112]
       (air)[.287][..32][..32]
       (air)[.286][..32][..64]
       (air)[.285][..32][..96]
       (air)[.284][..32][.128]
(sector_end)

 //wall right alt random 2x2  meta-ready 75
(sector)[..75] (texg)[...0] 
    (tile)[...0][...1] (move)[none] (light_op)[proxfade]
    (tile)[...1][...1] (move)[none] (light_op)[proxfade]

    (rand)[..12]
    (if_rand)[...0] (recursec)[..70][...0][...0]  //wall right alt a 2x2
    (if_rand)[...1] (recursec)[..70][...0][...0]
    (if_rand)[...2] (recursec)[..70][...0][...0]
    (if_rand)[...3] (recursec)[..71][...0][...0]  //wall right alt b 2x2
    (if_rand)[...4] (recursec)[..71][...0][...0]
    (if_rand)[...5] (recursec)[..71][...0][...0]
    (if_rand)[...6] (recursec)[..73][...0][...0]  //wall right alt d 2x2
    (if_rand)[...7] (recursec)[..73][...0][...0]
    (if_rand)[...8] (recursec)[..73][...0][...0]
    (if_rand)[...9] (recursec)[..74][...0][...0]  //wall right alt e 2x2
    (if_rand)[..10] (recursec)[..74][...0][...0]
    (if_rand)[..11] (recursec)[..74][...0][...0]
    (if_rand)[..12] (recursec)[..72][...0][...0]  //wall right alt c 2x2
(sector_end)



 //corner up left side alt a deadend
(sector)[..76] (texg)[...0]
    (tile)[...0][...1]
       (air)[.2e4][..00][..64]
       (air)[.2e2][..00][..96]
       (air)[.2e0][..00][.128]
    (tile)[...0][...0]
       (air)[.2e7][..00][..96]
(sector_end)

 //corner up left side alt b deadend
(sector)[..77] (texg)[...0]
    (tile)[...0][...1]
       (air)[.057][..00][..64]
       (air)[.055][..00][..96]
       (air)[.054][..00][.128]
    (tile)[...0][...0]
       (air)[.05d][..00][..96]
(sector_end)

 //corner up left side deadend rand
(sector)[..78]
     (rand)[...1]
     (if_rand)[...0](recursec)[..76][...0][...0]  //corner up left side alt a deadend
     (if_rand)[...1](recursec)[..77][...0][...0]  //corner up left side alt b deadend
(sector_end)

 //corner up left side alt c continue
(sector)[..79] (texg)[...0]
    (tile)[...0][...1]
       (air)[.074][..00][..64]
       (air)[.014][..00][..96]
    (tile)[...0][...0]
       (air)[.075][..00][..96]
(sector_end)

 //corner up right side alt a deadend a
(sector)[..80] (texg)[...0]
    (tile)[...0][...1]
       (air)[.2e5][..32][..64]
       (air)[.2e3][..32][..96]
       (air)[.2e1][..32][.128]
    (tile)[...1][...1]
       (air)[.2e6][..32][..96]
(sector_end)

 //corner up right side alt b dedend b
(sector)[..81] (texg)[...0]
    (tile)[...0][...1]
       (air)[.063][..32][..64]
       (air)[.062][..32][..96]
       (air)[.061][..32][.128]
    (tile)[...1][...1]
       (air)[.067][..32][..96]
(sector_end)

 //corner up right side deadend rand
(sector)[..82]
     (rand)[...1]
     (if_rand)[...0](recursec)[..80][...0][...0]  //corner up right side alt a deadend
     (if_rand)[...1](recursec)[..81][...0][...0]  //corner up right side alt b deadend
(sector_end)


 //corner up right side alt c continue
(sector)[..83] (texg)[...0]
    (tile)[...0][...1]
       (air)[.072][..32][..64]
       (air)[.001][..32][..96]
    (tile)[...1][...1]
       (air)[.073][..32][..96]
(sector_end)


 //wall cross basis 2x2
(sector)[..84] (texg)[...0]
    (tile)[...0][...0] (ground)[.070][.071] (light_op)[proxfade](move)[none]
       (air)[.00f][..00][..32]
       (air)[.05e][..00][..64]
    (tile)[...0][...1] (ground)[.06c][.06d] (light_op)[proxfade](move)[none]
       (air)[.058][..00][..32]
       (air)[.06b][..32][..32]
    (tile)[...1][...1] (ground)[.06e][.06f] (light_op)[proxfade](move)[none]
       (air)[.01f][..32][..32]
       (air)[.01e][..32][..64]
(sector_end)

 //wall  crossing meta-ready
(sector)[..85]
     (recursec)[..79][...0][...0]  //corner up left side alt c continue
     (recursec)[..83][...0][...0]  //corner up right side alt c continue
     (recursec)[..84][...0][...0]  //wall cross basis 2x2
(sector_end)

 //wall  corner up meta-ready 86
(sector)[..86]
     (recursec)[..78][...0][...0]  //corner up left side random deadend
     (recursec)[..82][...0][...0]  //corner up left side random deadend
     (recursec)[..84][...0][...0]  //wall cross basis 2x2
(sector_end)

 //wall trifork left-up deadend meta-ready 87
(sector)[..87]
     (recursec)[..78][...0][...0]  //corner up left side random deadend
     (recursec)[..83][...0][...0]  //corner up right side alt c continue
     (recursec)[..84][...0][...0]  //wall cross basis 2x2
(sector_end)

 //wall trifork right-up deadend meta-ready
(sector)[..88]
     (recursec)[..79][...0][...0]  //corner up left side alt c continue
     (recursec)[..82][...0][...0]  //corner up left side random deadend
     (recursec)[..84][...0][...0]  //wall cross basis 2x2
(sector_end)

//wall corner down air leftside alt a
(sector)[..89] (texg)[...0]
    (tile)[...0][...1]
       (air)[.079][..00][..32]
       (air)[.077][..00][..64]
       (air)[.081][..00][..96]
       (air)[.04a][-.32][..80]
(sector_end)

//wall corner down air leftside alt b
(sector)[..90] (texg)[...0]
    (tile)[...0][...1]
       (air)[.2ec][..00][..32]
       (air)[.2ea][..00][..64]
       (air)[.2e8][..00][..96]
       (air)[.04a][-.32][..80]
(sector_end)

//wall corner down air rightside alt a
(sector)[..91] (texg)[...0]
    (tile)[...0][...1]
       (air)[.07a][..32][..32]
       (air)[.078][..32][..64]
       (air)[.076][..32][..96]
       (air)[.03d][..64][..48]
       (air)[.03c][..64][..80]
    (tile)[...1][...1](ground)[.03e][.03f]
(sector_end)

//wall corner down air rightside alt b
(sector)[..92] (texg)[...0]
    (tile)[...0][...1]
       (air)[.2ed][..32][..32]
       (air)[.2eb][..32][..64]
       (air)[.2e9][..32][..96]
       (air)[.2ef][..64][..48]
       (air)[.2ee][..64][..80]
    (tile)[...1][...1](ground)[.03e][.03f]
(sector_end)

//wall corner down air rightside alt c broken spike
(sector)[..93] (texg)[...0]
    (tile)[...0][...1]
       (air)[.2f3][..32][..32]
       (air)[.2f2][..32][..64]
       (air)[.2f1][..32][..96]
       (air)[.2f6][..64][..48]
       (air)[.2f5][..64][..80]
    (tile)[...1][...1](ground)[.2f7][.2f8](light_op)[proxfade]
(sector_end)

 //wall corner down meta-ready 94
(sector)[..94](texg)[...0]
     (rand)[...1]
     (if_rand)[...0] (recursec)[..89][...0][...0]  //wall corner down air leftside alt a
     (if_rand)[...1] (recursec)[..90][...0][...0]  //wall corner down air leftside alt b
     (rand)[...6]
     (if_rand)[...0] (recursec)[..91][...0][...0]  //wall corner down air rightside alt a
     (if_rand)[...1] (recursec)[..91][...0][...0]
     (if_rand)[...2] (recursec)[..91][...0][...0]
     (if_rand)[...3] (recursec)[..92][...0][...0]  //wall corner down air rightside alt b
     (if_rand)[...4] (recursec)[..92][...0][...0]
     (if_rand)[...5] (recursec)[..92][...0][...0]
     (if_rand)[...6] (recursec)[..93][...0][...0]  //wall corner down air rightside alt c broken spike
     (tile)[...0][...1](light_op)[proxfade](move)[none](ground)[.07b][.07c]
(sector_end)

 //wall corner left alt a horns in
(sector)[..95](texg)[...0]
    (tile)[-..2][...1](ground)[.186][.187]
    (tile)[-..1][...1](ground)[.188][.189]
    (tile)[-..2][...2](ground)[.192][.193]
    (tile)[-..1][...2](ground)[.194][.1d2]
    (tile)[...0][...1]
       (air)[.02c][..00][..32]
       (air)[.02a][..00][..64]
       (air)[.028][..00][..96]
       (air)[.026][..00][.128]
       (air)[.033][-.32][.080]
(sector_end)

 //wall corner left alt b horns up
(sector)[..96](texg)[...0]
    (tile)[-..2][...1](ground)[.290][.291]
    (tile)[-..1][...1](ground)[.292][.293]
    (tile)[-..2][...2](ground)[.29c][.29d]
    (tile)[-..1][...2](ground)[.29e][.013]
    (tile)[...0][...1]
       (air)[.2a4][..00][..32]
       (air)[.2a2][..00][..64]
       (air)[.2a0][..00][..96]
       (air)[.2b0][-.32][.080]
       (air)[.2af][-.32][.112]
       (air)[.2ae][-.32][.144]
(sector_end)

 //wall corner left alt c horns out
(sector)[..97](texg)[...0]
    (tile)[-..2][...1](ground)[.2b6][.2b7]
    (tile)[-..1][...1](ground)[.2b8][.2b9]
    (tile)[-..2][...2](ground)[.2c2][.2c3]
    (tile)[-..1][...2](ground)[.2c4][.013]
    (tile)[...0][...1]
       (air)[.2cc][..00][..32]
       (air)[.2ca][..00][..64]
       (air)[.2c8][..00][..96]
       (air)[.2c6][..00][.128]
       (air)[.2d5][-.32][.048]
       (air)[.2d4][-.32][.080]
(sector_end)

//wall left corner random air 98
(sector)[..98](texg)[...0]
    (tile)[-..2][...1](light_op)[proxfade]
    (tile)[-..1][...1](light_op)[proxfade]
    (tile)[-..2][...2](light_op)[proxfade]
    (tile)[-..1][...2](light_op)[proxfade]
    (tile)[...0][...1](light_op)[proxfade](move)[none]

     (rand)[...2]
     (if_rand)[...0] (recursec)[..95][...0][...0] //wall corner left alt a horns in
     (if_rand)[...1] (recursec)[..96][...0][...0] //wall corner left alt b horns up
     (if_rand)[...2] (recursec)[..97][...0][...0] //wall corner left alt c horns out
(sector_end)

//wall left corner meta-ready 99
(sector)[..99](texg)[...0]
    (tile)[...0][...1](ground)[.02e][.086](light_op)[proxfade](move)[none]
       (air)[.06b][..32][..32]
       (air)[.072][..32][..64]
       (air)[.082][..32][..96]
    (tile)[...1][...1](ground)[.06e][.06f](light_op)[proxfade](move)[none]
       (air)[.01f][..32][..32]
       (air)[.01e][..32][..64]
       (air)[.073][..32][..96]
    (recursec)[..98][...0][...0] //wall left corner random air
(sector_end)

//wall dead-end up_left meta-ready
(sector)[.100](texg)[...0]
    (tile)[...0][...1](ground)[.02e][.086](light_op)[proxfade](move)[none]
       (air)[.064][..32][..32]
       (air)[.063][..32][..64]
       (air)[.062][..32][..96]
       (air)[.061][..32][.128]
    (tile)[...1][...1](ground)[.068][.069](light_op)[proxfade](move)[none]
       (air)[.01f][..32][..32]
       (air)[.01e][..32][..64]
       (air)[.067][..32][..96]
    (recursec)[..98][...0][...0] //wall left corner random air
(sector_end)

//wall dead-end down_left var a
(sector)[.101](texg)[...0]
   (tile)[...0][...1]
       (air)[.039][..32][..32]
       (air)[.038][..32][..64]
       (air)[.037][..32][..96]
       (air)[.036][..32][.128]
       (air)[.03d][..64][..48]
       (air)[.03c][..64][..80]
(sector_end)

//wall dead-end down_left var b
(sector)[.102](texg)[...0]
   (tile)[...0][...1]
       (air)[.2f3][..32][..32]
       (air)[.2f2][..32][..64]
       (air)[.2f1][..32][..96]
       (air)[.2f6][..64][..48]
       (air)[.2f5][..64][..80]
(sector_end)

//wall dead-end down-left meta-ready 103
(sector)[.103](texg)[...0]
    (rand)[...1]
    (if_rand)[...0](recursec)[.101][...0][...0] //wall dead-end down_left var a
    (if_rand)[...1](recursec)[.102][...0][...0] //wall dead-end down_left var b
    (recursec)[..98][...0][...0] //wall left corner random air
    (tile)[...0][...1](ground)[..3a][..3b](light_op)[proxfade](move)[none]
(sector_end)


 //wall corner right alt a horns in
(sector)[.104](texg)[...0]
    (tile)[...0][...1]
       (air)[.02d][..32][..32]
       (air)[.02b][..32][..64]
       (air)[.029][..32][..96]
       (air)[.027][..32][.128]
       (air)[.030][..64][..80]
(sector_end)

 //wall corner right alt b horns up
(sector)[.105](texg)[...0]
    (tile)[...0][...1]
       (air)[.2a5][..32][..32]
       (air)[.2a3][..32][..64]
       (air)[.2a1][..32][..96]
       (air)[.2aa][..64][..80]
       (air)[.2a9][..64][.112]
       (air)[.2a8][..64][.144]
(sector_end)

 //wall corner right alt c horns out
(sector)[.106](texg)[...0]
    (tile)[...0][...1]
       (air)[.2cd][..32][..32]
       (air)[.2cb][..32][..64]
       (air)[.2c9][..32][..96]
       (air)[.2c7][..32][.128]
       (air)[.2d1][..64][..48]
       (air)[.2d0][..64][..80]
(sector_end)

 //wall corner right alt d horns broken
(sector)[.107](texg)[...0]
    (tile)[...0][...1]
       (air)[.2fd][..32][..32]
       (air)[.2fc][..32][..64]
       (air)[.2fb][..32][..96]
       (air)[.2fa][..32][.128]
       (air)[.2ff][..64][..80]
(sector_end)

//wall right corner random air 108
(sector)[.108](texg)[...0]
     (rand)[...3]
     (if_rand)[...0] (recursec)[.104][...0][...0] //wall corner right alt a horns in
     (if_rand)[...1] (recursec)[.105][...0][...0] //wall corner right alt b horns up
     (if_rand)[...2] (recursec)[.106][...0][...0] //wall corner right alt c horns out
     (if_rand)[...3] (recursec)[.107][...0][...0] //wall corner right alt d horns broken
(sector_end)


//wall right corner meta-ready
(sector)[.109](texg)[...0]
    (tile)[...0][...0](ground)[.010][.071](light_op)[proxfade](move)[none]
       (air)[.00f][..00][..32]
       (air)[.00e][..00][..64]
       (air)[.075][..00][..96]
    (tile)[...0][...1](ground)[.06c][.02f](light_op)[proxfade](move)[none]
       (air)[.058][..00][..32]
       (air)[.07d][..00][..64]
       (air)[.014][..00][..96]
    (recursec)[.108][...0][...0] //wall right corner random air
(sector_end)

//wall dead-end down right meta-ready
(sector)[.110](texg)[...0]
    (tile)[...0][...1](ground)[.048][.049](light_op)[proxfade](move)[none]
       (air)[.047][..00][..32]
       (air)[.046][..00][..64]
       (air)[.045][..00][..96]
       (air)[.044][..00][.128]
       (air)[.04a][-.32][..80]
    (recursec)[.108][...0][...0] //wall right corner random air
(sector_end)

//wall dead-end up_right meta-ready
(sector)[.111](texg)[...0]
    (tile)[...0][...0](ground)[.05f][.060](light_op)[proxfade](move)[none]
       (air)[.00f][..00][..32]
       (air)[.05e][..00][..64]
       (air)[.05d][..00][..96]
    (tile)[...0][...1](ground)[.05a][.05b](light_op)[proxfade](move)[none]
       (air)[.058][..00][..32]
       (air)[.057][..00][..64]
       (air)[.055][..00][..96]
       (air)[.054][..00][.128]
    (recursec)[.108][...0][...0] //wall right corner random air
(sector_end)


//wall tri-fork dead-end left-down meta-ready 112
(sector)[.112](texg)[...0]
     (rand)[...1]
     (if_rand)[...0] (recursec)[..89][...0][...0]  //wall corner down air leftside alt a
     (if_rand)[...1] (recursec)[..90][...0][...0]  //wall corner down air leftside alt b
     (tile)[...0][...1](light_op)[proxfade](move)[none](ground)[.085][.086]
       (air)[.06b][..32][..32]
       (air)[.072][..32][..64]
       (air)[.082][..32][..96]
     (tile)[...1][...1](light_op)[proxfade](move)[none](ground)[.06e][.06f]
       (air)[.01f][..32][..32]
       (air)[.01e][..32][..64]
       (air)[.073][..32][..96]
(sector_end)


//wall tri-fork dead-end right-down meta-ready
(sector)[.113](texg)[...0]
     (rand)[...2]
     (if_rand)[...0] (recursec)[..91][...0][...0]  //wall corner down air rightside alt a
     (if_rand)[...1] (recursec)[..92][...0][...0]  //wall corner down air rightside alt b
     (if_rand)[...2] (recursec)[..93][...0][...0]  //wall corner down air rightside alt c
     (tile)[...0][...0](light_op)[proxfade](move)[none](ground)[.010][.011]
       (air)[.00f][..00][..32]
       (air)[.00e][..00][..64]
       (air)[.075][..00][..96]
     (tile)[...0][...1](light_op)[proxfade](move)[none](ground)[.07f][.080]
       (air)[.07e][..00][..32]
       (air)[.07d][..00][..64]
       (air)[.014][..00][..96]
(sector_end)

//wall arch dead-end left-up meta-ready 114
(sector)[.114](texg)[...0]
     (tile)[-..3][...2](ground)[.1ef][.1f0](light_op)[proxfade]
     (tile)[-..2][...1](ground)[.04c][.1f4](light_op)[proxfade]
     (tile)[-..2][...2](ground)[.1f1][.1f2](light_op)[proxfade]
     (tile)[-..1][...1](ground)[.1f5][.1f6](light_op)[proxfade]
     (tile)[-..1][...2](ground)[.1f3][.1d2](light_op)[proxfade]
     (tile)[...0][...1](ground)[.1dd][.1de](light_op)[proxfade](move)[none]
       (air)[.1e3][-.32][.112]
       (air)[.1e2][-.32][.144]
       (air)[.1db][..00][..32]
       (air)[.1d9][..00][..64]
       (air)[.1d7][..00][..96]
       (air)[.1d6][..00][.128]
       (air)[.1dc][..32][..32]
       (air)[.1da][..32][..64]
       (air)[.1d8][..32][..96]
     (tile)[...1][...1](ground)[.06e][.1e1](light_op)[proxfade](move)[none]
       (air)[.1e0][..32][..32]
       (air)[.1df][..32][..64]
       (air)[.073][..32][..96]
(sector_end)

//wall arch dead-end right-down meta-ready 115
(sector)[.115](texg)[...0]
     (tile)[...0][...1](ground)[.1ea][.1eb](light_op)[proxfade](move)[none]
       (air)[.1e8][..00][..32]
       (air)[.1e6][..00][..64]
       (air)[.1e4][..00][..96]
       (air)[.1e9][..32][..32]
       (air)[.1e7][..32][..64]
       (air)[.1e5][..32][..96]
       (air)[.1ed][..64][..80]
       (air)[.1ec][..64][.112]
(sector_end)

//wall arch dead-end right-up meta-ready 116
(sector)[.116](texg)[...0]
     (tile)[...0][...0](ground)[.010][.011](light_op)[proxfade](move)[none]
       (air)[.00f][..00][..32]
       (air)[.00e][..00][..64]
       (air)[.075][..00][..96]
     (tile)[...0][...1](ground)[.1af][.1b0](light_op)[proxfade](move)[none]
       (air)[.1ad][..00][..32]
       (air)[.1ab][..00][..64]
       (air)[.1a9][..00][..96]
       (air)[.1ae][..32][..32]
       (air)[.1ac][..32][..64]
       (air)[.1aa][..32][..96]
       (air)[.1a8][..32][.128]
       (air)[.1b2][..64][.112]
       (air)[.1b1][..64][.144]
(sector_end)

//wall arch dead-end left-down meta-ready 117
(sector)[.117](texg)[...0]
     (tile)[-..2][...1](ground)[.1cb][.1cc](light_op)[proxfade]
     (tile)[-..1][...1](ground)[.1ce][.1cf](light_op)[proxfade]
     (tile)[...0][...1](ground)[.1c1][.1c2](light_op)[proxfade](move)[none]
       (air)[.1c6][-.32][..80]
       (air)[.1c5][-.32][.112]
       (air)[.1bf][..00][..32]
       (air)[.1bd][..00][..64]
       (air)[.1bb][..00][..96]
       (air)[.1c0][..32][..32]
       (air)[.1be][..32][..64]
       (air)[.1bc][..32][..96]
(sector_end)

//doodad groundstar 118
(sector)[.118](texg)[...0]
     (tile)[...1][...0](ground)[.312][.313]
     (tile)[...2][...0](ground)[.320][.321]

     (tile)[...0][...1](ground)[.30c][.30d]
     (tile)[...1][...1](ground)[.30e][.30f]
     (tile)[...2][...1](ground)[.31c][.31d]
     (tile)[...3][...1](ground)[.31e][.31f]

     (tile)[...0][...2](ground)[.308][.309]
     (tile)[...1][...2](ground)[.30a][.30b]
     (tile)[...2][...2](ground)[.318][.319]
     (tile)[...3][...2](ground)[.31a][.31b]

     (tile)[...1][...3](ground)[.306][.307]
     (tile)[...2][...3](ground)[.314][.315]
(sector_end)

//doodad groundcurve a 119
(sector)[.119](texg)[...0]
     (tile)[...1][...1](ground)[.32a][.32b]
     (tile)[...2][...1](ground)[.330][.331]
     (tile)[...3][...1](ground)[.332][.333]

     (tile)[...0][...2](ground)[.324][.325]
     (tile)[...1][...2](ground)[.326][.327]
     (tile)[...2][...2](ground)[.32c][.32d]
(sector_end)

//doodad groundcurve b 120
(sector)[.120](texg)[...0]
     (tile)[...2][...0](ground)[.342][.343]

     (tile)[...1][...1](ground)[.33c][.33d]
     (tile)[...2][...1](ground)[.33e][.33f]

     (tile)[...1][...2](ground)[.338][.339]
     (tile)[...2][...2](ground)[.33a][.33b]

     (tile)[...1][...3](ground)[.334][.335]
(sector_end)

//doodad groundcurve c 121
(sector)[.121](texg)[...0]
     (tile)[...0][...0](ground)[.350][.351]
     (tile)[...1][...0](ground)[.352][.353]

     (tile)[...0][...1](ground)[.34c][.34d]

     (tile)[...0][...2](ground)[.348][.349]
     (tile)[...1][...2](ground)[.34a][.34b]

     (tile)[...0][...3](ground)[.344][.345]
     (tile)[...1][...3](ground)[.346][.347]
     (tile)[...2][...3](ground)[.354][.355]
     (tile)[...3][...3](ground)[.356][.357]
(sector_end)

//doodad spike a
(sector)[.122](texg)[...0]
     (tile)[...2][...1](ground)[.36d][.36e](move)[fly]
       (air)[.36b][...0][..32]
       (air)[.369][...0][..64]
       (air)[.36c][..32][..32]
       (air)[.36a][..32][..64]
(sector_end)

//doodad spike b
(sector)[.123](texg)[...0]
     (tile)[...2][...1](ground)[.361][.362](move)[fly]
       (air)[.35f][...0][..32]
       (air)[.35d][...0][..64]
       (air)[.35c][...0][..96]
       (air)[.360][..32][..32]
       (air)[.35e][..32][..64]
(sector_end)

//doodad spike c
(sector)[.124](texg)[...0]
     (tile)[...2][...1](ground)[.37b][.37c](move)[fly]
       (air)[.37a][...0][..32]
       (air)[.375][..32][..48]
     (tile)[...2][...2](ground)[.376][.377]
(sector_end)

//random doodad meta-ready
(sector)[.125](texg)[...0]
     (rand)[...6]
     (if_rand)[...0] (recursec)[.118][...0][...0]  //doodad groundstar
     (if_rand)[...1] (recursec)[.119][...0][...0]  //doodad groundcurve a
     (if_rand)[...2] (recursec)[.120][...0][...0]  //doodad groundcurve b
     (if_rand)[...3] (recursec)[.121][...0][...0]  //doodad groundcurve c
     (if_rand)[...4] (recursec)[.122][...0][...0]  //doodad spike a
     (if_rand)[...5] (recursec)[.123][...0][...0]  //doodad spike b
     (if_rand)[...6] (recursec)[.124][...0][...0]  //doodad spike c
(sector_end)

//lavablock basis
(sector)[.126](texg)[...0]
     (tile)[...0][...0](move)[none](light_op)[proxfade] (ground)[-001][-001] (ground_alt)[-001][-001]
     (tile)[...0][...1](move)[none](light_op)[proxfade] (ground)[-001][-001] (ground_alt)[-001][-001]
     (tile)[...1][...1](move)[none](light_op)[proxfade] (ground)[-001][-001] (ground_alt)[-001][-001]
     (tile)[...1][...0](move)[none](light_op)[proxfade] (ground)[-001][-001] (ground_alt)[-001][-001]
       (air_ooze)[.091][...0][..32]
       (air_ooze)[.0a5][...0][..64]
       (air_ooze)[.092][..32][..32]
       (air_ooze)[.0a6][..32][..64]
       (light)[.255][..20][...0][...6]
(sector_end)

//lavablock corner right meta-ready 127
(sector)[.127](texg)[...0]
     (recursec)[.126][...0][...0] //lavablock basis
     (tile)[...0][...0]
       (air_ooze)[.098][...0][..32]
       (air_ooze)[.0ae][...0][..64]
            (air)[.075][...0][..96]
     (tile)[...0][...1]
       (air_ooze)[.0b4][...0][..64]
       (air_ooze)[.0d0][...0][..96]
       (air_ooze)[.0d3][..32][..64]
       (air_ooze)[.0d1][..32][..96]
            (air)[.027][..32][.128]
     (tile)[...1][...1]
       (air_ooze)[.095][..32][..32]
       (air_ooze)[.0a8][..32][..64]
       (air_ooze)[.0d4][..32][..96]
(sector_end)

//lavablock corner left meta-ready 128
(sector)[.128](texg)[...0]
     (recursec)[.126][...0][...0] //lavablock basis
     (tile)[...0][...0]
       (air_ooze)[.0a0][...0][..32]
       (air_ooze)[.0aa][...0][..64]
       (air_ooze)[.0cf][...0][..96]
     (tile)[...0][...1]
       (air_ooze)[.0cb][...0][..64]
       (air_ooze)[.0c9][...0][..96]
            (air)[.026][..00][.128]
       (air_ooze)[.0af][..32][..64]
       (air_ooze)[.0ca][..32][..96]
     (tile)[...1][...1]
       (air_ooze)[.09d][..32][..32]
       (air_ooze)[.0ad][..32][..64]
            (air)[.073][..32][..96]
(sector_end)

//lavablock wall left meta-ready 129
(sector)[.129](texg)[...0]
     (recursec)[.126][...0][...0] //lavablock basis
     (tile)[...0][...0]
       (air_ooze)[.098][...0][..32]
       (air_ooze)[.097][...0][..64]
            (air)[.096][...0][..96]
            (air)[.00c][...0][.128]
     (tile)[...0][...1]
       (air_ooze)[.08d][...0][..64]
            (air)[.000][...0][..96]
       (air_ooze)[.08e][..32][..64]
            (air)[.08c][..32][..96]
     (tile)[...1][...1]
       (air_ooze)[.095][..32][..32]
       (air_ooze)[.094][..32][..64]
       (air_ooze)[.093][..32][..96]
(sector_end)

//lavablock wall right meta-ready 130
(sector)[.130](texg)[...0]
     (recursec)[.126][...0][...0] //lavablock basis
     (tile)[...0][...0]
       (air_ooze)[.0a0][...0][..32]
       (air_ooze)[.09f][...0][..64]
       (air_ooze)[.09e][...0][..96]
     (tile)[...0][...1]
       (air_ooze)[.09a][...0][..64]
            (air)[.099][...0][..96]
       (air_ooze)[.09b][..32][..64]
            (air)[.015][..32][..96]
     (tile)[...1][...1]
       (air_ooze)[.09d][..32][..32]
       (air_ooze)[.09c][..32][..64]
            (air)[.01d][..32][..96]
            (air)[.01c][..32][.128]
(sector_end)

//lavablock wall crossing part left side wall
(sector)[.131](texg)[...0]
     (tile)[...0][...0]
       (air_ooze)[.098][...0][..32]
       (air_ooze)[.0ae][...0][..64]
            (air)[.075][...0][..96]
     (tile)[...0][...1]
       (air_ooze)[.0be][...0][..64]
            (air)[.014][...0][..96]
(sector_end)

//lavablock wall crossing part right side wall
(sector)[.132](texg)[...0]
     (tile)[...0][...1]
       (air_ooze)[.0c5][..32][..64]
            (air)[.001][..32][..96]
     (tile)[...1][...1]
       (air_ooze)[.09d][..32][..32]
       (air_ooze)[.0ad][..32][..64]
            (air)[.073][..32][..96]
(sector_end)

//lavablock wall crossing part left side wall ornament left-up
(sector)[.133](texg)[...0]
     (tile)[...0][...0]
       (air_ooze)[.098][...0][..32]
       (air_ooze)[.0ae][...0][..64]
            (air)[.05d][...0][..96]
     (tile)[...0][...1]
       (air_ooze)[.0ab][...0][..64]
            (air)[.055][...0][..96]
            (air)[.054][...0][.128]
(sector_end)

//lavablock wall crossing part right side wall ornament right-up
(sector)[.134](texg)[...0]
     (tile)[...0][...1]
       (air_ooze)[.0ac][..32][..64]
            (air)[.062][..32][..96]
            (air)[.061][..32][.128]
     (tile)[...1][...1]
       (air_ooze)[.09d][..32][..32]
       (air_ooze)[.0ad][..32][..64]
            (air)[.067][..32][..96]
(sector_end)

//lavablock wall crossing part left side wall ornament left-down
(sector)[.135](texg)[...0]
     (tile)[...0][...0]
       (air_ooze)[.0a0][...0][..32]
       (air_ooze)[.0aa][...0][..64]
       (air_ooze)[.0bb][...0][..96]
     (tile)[...0][...1]
       (air_ooze)[.0b7][...0][..64]
            (air)[.0b6][...0][..96]
(sector_end)

//lavablock wall crossing part right side wall ornament right-down
(sector)[.136](texg)[...0]
     (tile)[...0][...1]
       (air_ooze)[.0b8][..32][..64]
            (air)[.0bd][..32][..96]
     (tile)[...1][...1]
       (air_ooze)[.095][..32][..32]
       (air_ooze)[.0a8][..32][..64]
       (air_ooze)[.0b9][..32][..96]
(sector_end)

//lavablock wall crossing meta-ready
(sector)[.137](texg)[...0]
     (recursec)[.126][...0][...0] //lavablock basis
     (recursec)[.131][...0][...0] //lavablock wall crossing part left side wall
     (recursec)[.132][...0][...0] //lavablock wall crossing part right side wall
(sector_end)

//lavablock wall upper_corner meta-ready 138
(sector)[.138](texg)[...0]
     (recursec)[.126][...0][...0] //lavablock basis
     (recursec)[.133][...0][...0] //lavablock wall crossing part left side wall ornament left-up
     (recursec)[.134][...0][...0] //lavablock wall crossing part right side wall ornament right-up
(sector_end)

//lavablock wall lower_corner meta-ready 139
(sector)[.139](texg)[...0]
     (recursec)[.126][...0][...0] //lavablock basis
     (recursec)[.135][...0][...0] //lavablock wall crossing part left side wall ornament left-down
     (recursec)[.136][...0][...0] //lavablock wall crossing part right side wall ornament right-down
(sector_end)

//lavablock tri dead-end right-up lava only down meta-ready
(sector)[.140](texg)[...0]
     (recursec)[.126][...0][...0] //lavablock basis
     (recursec)[.131][...0][...0] //lavablock wall crossing part left side wall
     (recursec)[.134][...0][...0] //lavablock wall crossing part right side wall ornament right-up
(sector_end)

//lavablock tri dead-end left-up lava only down meta-ready 141
(sector)[.141](texg)[...0]
     (recursec)[.126][...0][...0] //lavablock basis
     (recursec)[.133][...0][...0] //lavablock wall crossing part left side wall ornament left-up
     (recursec)[.132][...0][...0] //lavablock wall crossing part right side wall
(sector_end)

//lavablock crossing lava down&right meta-ready
(sector)[.142](texg)[...0]
     (recursec)[.126][...0][...0] //lavablock basis
     (recursec)[.131][...0][...0] //lavablock wall crossing part left side wall
     (recursec)[.136][...0][...0] //lavablock wall crossing part right side wall ornament right-down
(sector_end)

//lavablock crossing lava down&left meta-ready
(sector)[.143](texg)[...0]
     (recursec)[.126][...0][...0] //lavablock basis
     (recursec)[.135][...0][...0] //lavablock wall crossing part left side wall ornament left-down
     (recursec)[.132][...0][...0] //lavablock wall crossing part right side wall
(sector_end)

//lavablock no wall meta-ready 144
(sector)[.144](texg)[...0]
     (tile)[...0][...0](clean_air) 
     (tile)[...1][...0](clean_air) 
     (tile)[...0][...1](clean_air) 
     (tile)[...1][...1](clean_air) 

     (recursec)[.126][...0][...0] //lavablock basis
     (tile)[...0][...0]
       (air_ooze)[.0a0][...0][..32]
       (air_ooze)[.0aa][...0][..64]
       (air_ooze)[.0a9][...0][..96]
     (tile)[...0][...1]
       (air_ooze)[.0a3][...0][..64]
       (air_ooze)[.0a1][...0][..96]
       (air_ooze)[.0a4][..32][..64]
       (air_ooze)[.0a2][..32][..96]
     (tile)[...1][...1]
       (air_ooze)[.095][..32][..32]
       (air_ooze)[.0a8][..32][..64]
       (air_ooze)[.0a7][..32][..96]
(sector_end)

//lavablock 4x4 145
(sector)[.145]
     (recursec)[.144][...0][...0] //lavablock no wall meta-ready
     (recursec)[.144][...2][...0] //lavablock no wall meta-ready
     (recursec)[.144][...0][...2] //lavablock no wall meta-ready
     (recursec)[.144][...2][...2] //lavablock no wall meta-ready
(sector_end)

//lavablock 8x8 146
(sector)[.146]
     (recursec)[.145][...0][...0] //lavablock 4x4
     (recursec)[.145][...4][...0] //lavablock 4x4
     (recursec)[.145][...0][...4] //lavablock 4x4
     (recursec)[.145][...4][...4] //lavablock 4x4
(sector_end)

//lavablock 16x16
(sector)[.147]
     (recursec)[.146][...0][...0] //lavablock 8x8
     (recursec)[.146][...8][...0] //lavablock 8x8
     (recursec)[.146][...0][...8] //lavablock 8x8
     (recursec)[.146][...8][...8] //lavablock 8x8
(sector_end)

//lavablock 32x32
(sector)[.148]
     (recursec)[.147][...0][...0] //lavablock 16x16
     (recursec)[.147][..16][...0] //lavablock 16x16
     (recursec)[.147][...0][..16] //lavablock 16x16
     (recursec)[.147][..16][..16] //lavablock 16x16
(sector_end)

//lava wall left 2x
(sector)[.149]
     (recursec)[.129][...0][...0] //lavablock wall left meta-ready 129
     (recursec)[.129][...0][...2] //lavablock wall left meta-ready 129
(sector_end)

//lava wall left 4x 150
(sector)[.150]
     (recursec)[.149][...0][...0] //lava wall left 2x
     (recursec)[.149][...0][...4] //lava wall left 2x
(sector_end)

//lava wall left 8x 151
(sector)[.151]
     (recursec)[.150][...0][...0] //lava wall left 4x
     (recursec)[.150][...0][...8] //lava wall left 4x
(sector_end)

//wall left 2x
(sector)[.152]
     (recursec)[..69][...0][...0] //wall left alt random 2x2 meta-ready 69
     (recursec)[..69][...0][...2] //wall left alt random 2x2 meta-ready 69
(sector_end)

//wall left 4x 153
(sector)[.153]
     (recursec)[.152][...0][...0] //wall left 2x
     (recursec)[.152][...0][...4] //wall left 2x
(sector_end)

//wall left 8x 154
(sector)[.154]
     (recursec)[.153][...0][...0] //wall left 4x
     (recursec)[.153][...0][...8] //wall left 4x
(sector_end)


//lava wall right 2x 155
(sector)[.155]
     (recursec)[.130][...0][...0] //lavablock wall right meta-ready 130
     (recursec)[.130][...2][...0] //lavablock wall right meta-ready 130
(sector_end)

//lava wall right 4x 156
(sector)[.156]
     (recursec)[.155][...0][...0] //lava wall right 2x
     (recursec)[.155][...4][...0] //lava wall right 2x
(sector_end)

//lava wall right 8x 157
(sector)[.157]
     (recursec)[.156][...0][...0] //lava wall right 4x
     (recursec)[.156][...8][....] //lava wall right 4x
(sector_end)

//wall right 2x 158
(sector)[.158]
     (recursec)[..75][...0][...0]  //wall right alt random 2x2  meta-ready 75
     (recursec)[..75][...2][...0]  //wall right alt random 2x2  meta-ready 75
(sector_end)

//wall right 4x 159
(sector)[.159]
     (recursec)[.158][...0][...0] //wall right 2x
     (recursec)[.158][...4][...0] //wall right 2x
(sector_end)

//wall right 8x 160
(sector)[.160]
     (recursec)[.159][...0][...0] //wall right 4x
     (recursec)[.159][...8][....] //wall right 4x
(sector_end)


//double wall left-up to right-down 2x4 161
(sector)[.161]
     (recursec)[..75][...0][...0]  //wall right alt random 2x2  meta-ready 75
     (recursec)[.130][...0][...2] //lavablock wall right meta-ready 130
(sector_end)

//double wall left-down to right-up 4x2 162
(sector)[.162]
     (recursec)[.129][...0][...0]//lavablock wall left meta-ready 129
     (recursec)[..69][...2][...0] //wall left alt random 2x2 meta-ready 69     
(sector_end)

//double wall corner up 4x4 163
(sector)[.163]
     (recursec)[.129][...0][...0]//lavablock wall left meta-ready 129
     (recursec)[.138][...0][...2]//lavablock wall upper_corner meta-ready 138
     (recursec)[.130][...2][...2] //lavablock wall right meta-ready 130
     (recursec)[..86][...2][...0] //wall corner up meta-ready 86
(sector_end)

//double wall corner down 4x4 164
(sector)[.164]
     (recursec)[..75][...0][...0] //wall right alt random 2x2  meta-ready
     (recursec)[..94][...2][...0] //wall corner down meta-ready
     (recursec)[..69][...2][...2] //wall left alt random 2x2 meta-ready 69
     (recursec)[.139][...0][.. 2] //lavablock wall lower_corner meta-ready
(sector_end)

//double wall corner left 4x4 165
(sector)[.165]
    (recursec)[..99][...0][...0] //wall left corner meta-ready
    (recursec)[.129][...0][...2]//lavablock wall left meta-ready 129
    (recursec)[..75][...2][...0]  //wall right alt random 2x2  meta-ready 75
    (recursec)[.128][...2][...2] //lavablock corner left meta-ready
(sector_end)

//double wall corner right 4x4 166
(sector)[.166]
    (recursec)[.127][...0][...0]//lavablock corner right meta-ready 127
    (recursec)[.130][...0][...2] //lavablock wall right meta-ready 130
    (recursec)[..69][...2][...0] //wall left alt random 2x2 meta-ready 69
    (recursec)[.109][...2][...2] //wall right corner meta-ready
(sector_end)

//double wall dead-end right-down 167
(sector)[.167]
    (recursec)[..94][...0][...0] //wall corner down meta-ready
    (recursec)[.109][...0][...2] //wall right corner meta-ready
(sector_end)

//double wall dead-end left-down 168
(sector)[.168]
    (recursec)[..99][...0][...0] //wall left corner meta-ready 99
    (recursec)[..94][...2][...0] //wall corner down meta-ready
(sector_end)

//double wall dead-end right-up 169
(sector)[.169]
    (recursec)[.138][...0][...0] //lavablock wall upper_corner meta-ready 138
    (recursec)[.109][...2][...0]  //wall right corner meta-ready 109
(sector_end)


//pillar meta-ready 170
(sector)[.170](texg)[...0]
    (recursec)[..98][...0][...0] //wall left corner random air 98
    (recursec)[.108][...0][...0] //wall right corner random air 108
    (tile)[...0][...1](ground)[.02e][.02f] 
(sector_end)


//double wall dead-end left-up 171
(sector)[.171]
    (recursec)[..99][...0][...0] //wall left corner meta-ready 99
    (recursec)[.138][...0][...2] //lavablock wall upper_corner meta-ready 138
(sector_end)


**************************************************************************************************
***Slackspace*************************************************************************************
**************************************************************************************************






**************************************************************************************************
***Slackspace*************************************************************************************
**************************************************************************************************


// lev16 challange 1 spiral 200
(sector)[.200]
    (recursec)[.165][...0][...0] //double wall corner left 4x4 165
    (recursec)[.162][...0][...4]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][...6]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][...8]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][..10]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][..12]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][..14]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][..16]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][..18]//double wall left-down to right-up 4x2 162
    (recursec)[.163][...0][..20]//double wall corner up 4x4 163

    (recursec)[.161][...4][..20]//double wall left-up to right-down 2x4 161
    (recursec)[.161][...6][..20]//double wall left-up to right-down 2x4 161
    (recursec)[.161][...8][..20]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..10][..20]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..12][..20]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..14][..20]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..16][..20]//double wall left-up to right-down 2x4 161
    (recursec)[.167][..18][..20]//double wall dead-end right-down 2x4 167

    (recursec)[.161][...4][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.161][...6][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.161][...8][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..10][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..12][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..14][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.164][..16][...0]//double wall corner down 4x4 164

    (recursec)[.162][..16][...4]//double wall left-down to right-up 4x2 162
    (recursec)[.162][..16][...6]//double wall left-down to right-up 4x2 162
    (recursec)[.162][..16][...8]//double wall left-down to right-up 4x2 162
    (recursec)[.162][..16][..10]//double wall left-down to right-up 4x2 162
    (recursec)[.162][..16][..12]//double wall left-down to right-up 4x2 162

    (recursec)[.166][..16][..14]//double wall corner right 4x4 166

    (recursec)[.161][..14][..14]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..12][..14]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..10][..14]//double wall left-up to right-down 2x4 161

    (recursec)[.163][..06][..14]//double wall corner up 4x4 163

    (recursec)[.162][...6][..12]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...6][..10]//double wall left-down to right-up 4x2 162

    (recursec)[.165][...6][...6] //double wall corner left 4x4 165

    (recursec)[.161][..10][...6]//double wall left-up to right-down 2x4 161
    (recursec)[.167][..12][...6]//double wall dead-end right-down 2x4 167

    (recursec)[.118][..10][..10] //doodad groundstar 118
    (tile)[..10][..13] (move)[fly] (mech)[.126][+] // Big Ds lever chain first


(sector_end)

// lev16 challange 2 closed 201
(sector)[.201]

    (recursec)[..99][...0][...0] //wall left corner meta-ready 99
    (recursec)[.129][...0][...2] //lavablock wall left meta-ready 129
    (recursec)[.129][...0][...4] //lavablock wall left meta-ready 129
    (recursec)[.129][...0][...6] //lavablock wall left meta-ready 129
    (recursec)[.138][...0][...8] //lavablock wall upper_corner meta-ready 138
    (recursec)[..75][...2][...0] //wall right alt random 2x2  meta-ready 75
    (recursec)[..75][...4][...0] //wall right alt random 2x2  meta-ready 75
    (recursec)[..75][...6][...0] //wall right alt random 2x2  meta-ready 75
    (recursec)[..94][...8][...0] //wall corner down meta-ready 94
    (recursec)[.130][...2][...8] //lavablock wall right meta-ready 130
    (recursec)[.130][...4][...8] //lavablock wall right meta-ready 130
    (recursec)[.130][...6][...8] //lavablock wall right meta-ready 130
    (recursec)[..69][...8][...2] //wall left alt random 2x2 meta-ready 69
    (recursec)[..69][...8][...4] //wall left alt random 2x2 meta-ready 69
    (recursec)[..69][...8][...6] //wall left alt random 2x2 meta-ready 69
    (recursec)[.109][...8][...8] //wall right corner meta-ready 109
    (recursec)[.144][...2][...2] //lavablock no wall meta-ready 144
    (recursec)[.144][...4][...2] //lavablock no wall meta-ready 144
    (recursec)[.144][...6][...2] //lavablock no wall meta-ready 144
    (recursec)[.144][...2][...4] //lavablock no wall meta-ready 144
    (recursec)[.144][...4][...4] //lavablock no wall meta-ready 144
    (recursec)[.144][...6][...4] //lavablock no wall meta-ready 144
    (recursec)[.144][...2][...6] //lavablock no wall meta-ready 144
    (recursec)[.144][...4][...6] //lavablock no wall meta-ready 144
    (recursec)[.144][...6][...6] //lavablock no wall meta-ready 144

(sector_end)

// lev16 challange 2 opened 202
(sector)[.202]

     (recursec)[..53][...0][...0]// empty 8x8 patch of ground tiles 53
     (recursec)[..53][...2][...0]// empty 8x8 patch of ground tiles 53
     (recursec)[..53][...0][...2]// empty 8x8 patch of ground tiles 53
     (recursec)[..53][...2][...2]// empty 8x8 patch of ground tiles 53

     (recursec)[..99][...0][...0] //wall left corner meta-ready 99
     (recursec)[.109][...8][...8] //wall right corner meta-ready 109
     (recursec)[..94][...8][...0] //wall corner down meta-ready 94
     (recursec)[..86][...0][...8] //wall corner up meta-ready 86

     (recursec)[.114][...6][...0] //wall arch dead-end left-up meta-ready 114
     (recursec)[.114][...6][...8] //wall arch dead-end left-up meta-ready 114
     (recursec)[.115][...2][...0] //wall arch dead-end right-down meta-ready 115
     (recursec)[.115][...2][...8] //wall arch dead-end right-down meta-ready 115
     (recursec)[.116][...0][...2] //wall arch dead-end right-up meta-ready 116
     (recursec)[.116][...8][...2] //wall arch dead-end right-up meta-ready 116
     (recursec)[.117][...0][...6] //wall arch dead-end left-down meta-ready 117
     (recursec)[.117][...8][...6] //wall arch dead-end left-down meta-ready 117

    (tile)[...3][...6] (move)[fly] (mech)[.127][+] // Big Ds lever chain 2nd

(sector_end)


//dummy lever dump 203
(sector)[.203]

  (tile)[..00][..00] (mech)[.125][+] //Dummy lever

(sector_end)



// lev16 challange 3 closed 204
(sector)[.204]

    (recursec)[.120][-..2][...0] //doodad groundcurve b 120
    (recursec)[.119][..18][..20] //doodad groundcurve a 119
    (recursec)[.121][-..3][..21] //doodad groundcurve c 121
    (recursec)[.118][..18][..00] //doodad groundstar 118

    (recursec)[.165][...0][...4] //double wall corner left 4x4 165
    (recursec)[.162][...0][...8]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][..10]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][..12]//double wall left-down to right-up 4x2 162
    (recursec)[.163][...0][..14] //double wall corner up 4x4 163
    (recursec)[.164][...4][..14]//double wall corner down 4x4 164
    (recursec)[.163][...4][..18] //double wall corner up 4x4 163
    (recursec)[.161][...8][..18]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..10][..18]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..12][..18]//double wall left-up to right-down 2x4 161
    (recursec)[.166][..14][..18]//double wall corner right 4x4 166
    (recursec)[.165][..14][..14] //double wall corner left 4x4 165
    (recursec)[.166][..18][..14]//double wall corner right 4x4 166
    (recursec)[.162][..18][..12]//double wall left-down to right-up 4x2 162
    (recursec)[.162][..18][..10]//double wall left-down to right-up 4x2 162
    (recursec)[.162][..18][...8]//double wall left-down to right-up 4x2 162
    (recursec)[.164][..18][...4]//double wall corner down 4x4 164
    (recursec)[.163][..14][...4] //double wall corner up 4x4 163
    (recursec)[.164][..14][...0]//double wall corner down 4x4 164
    (recursec)[.161][..12][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..10][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.161][...8][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.165][...4][...0] //double wall corner left 4x4 165
    (recursec)[.166][...4][...4]//double wall corner right 4x4 166


    (recursec)[..99][...8][...8] //wall left corner meta-ready 99
    (recursec)[..75][..10][...8] //wall right alt random 2x2  meta-ready 75
    (recursec)[..94][..12][..08] //wall corner down meta-ready 94
    (recursec)[..69][..12][..10] //wall left alt random 2x2 meta-ready 69
    (recursec)[.109][..12][..12] //wall right corner meta-ready 109
    (recursec)[.129][...8][..10] //lavablock wall left meta-ready 129
    (recursec)[.138][...8][..12] //lavablock wall upper_corner meta-ready 138
    (recursec)[.130][..10][..12] //lavablock wall right meta-ready 130
    (recursec)[.144][..10][..10] //lavablock no wall meta-ready 144

    (recursec)[.302][...2][...8] //8x8 nogo tiles 302
    (recursec)[.302][...7][...2] //8x8 nogo tiles 302
    (recursec)[.302][...7][..14] //8x8 nogo tiles 302
    (recursec)[.302][..10][...8] //8x8 nogo tiles 302

  


(sector_end)


// lev16 challange 3 opened 205
(sector)[.205]

    (recursec)[..54][-..2][-..2] // empty 16x16 patch of ground tiles 54
    (recursec)[..54][...6][...6] // empty 16x16 patch of ground tiles 54
    (recursec)[..54][...6][-..2] // empty 16x16 patch of ground tiles 54
    (recursec)[..54][-..2][...6] // empty 16x16 patch of ground tiles 54

    (recursec)[.120][-..2][...0] //doodad groundcurve b 120
    (recursec)[.119][..18][..20] //doodad groundcurve a 119
    (recursec)[.121][-..3][..21] //doodad groundcurve c 121
    (recursec)[.118][..18][..00] //doodad groundstar 118

    (recursec)[..99][...0][...4] //wall left corner meta-ready 99
    (recursec)[..75][...2][...4] //wall right alt random 2x2  meta-ready 75
    (recursec)[.109][...4][...4] //wall right corner meta-ready 109
    (recursec)[..69][...4][...2] //wall left alt random 2x2 meta-ready 69
    (recursec)[..99][...4][...0] //wall left corner meta-ready 99
    (recursec)[..69][...0][...6] //wall left alt random 2x2 meta-ready 69
    (recursec)[.116][...0][...8] //wall arch dead-end right-up meta-ready 116
    (recursec)[..75][...6][...0] //wall right alt random 2x2  meta-ready 75
    (recursec)[.115][...8][...0] //wall arch dead-end right-down meta-ready 115

    (recursec)[.117][...0][..12] //wall arch dead-end left-down meta-ready 117
    (recursec)[..69][...0][..14] //wall left alt random 2x2 meta-ready 69
    (recursec)[..86][...0][..16] //wall corner up meta-ready 86
    (recursec)[..75][...2][..16] //wall right alt random 2x2  meta-ready 75
    (recursec)[..94][...4][..16] //wall corner down meta-ready 94
    (recursec)[..69][...4][..18] //wall left alt random 2x2 meta-ready 69
    (recursec)[..86][...4][..20] //wall corner up meta-ready 86
    (recursec)[..75][...6][..20] //wall right alt random 2x2  meta-ready 75
    (recursec)[.115][...8][..20] //wall arch dead-end right-down meta-ready 115

    (recursec)[.114][..12][..20] //wall arch dead-end left-up meta-ready 114
    (recursec)[..75][..14][..20] //wall right alt random 2x2  meta-ready 75
    (recursec)[.109][..16][..20] //wall right corner meta-ready 109
    (recursec)[..69][..16][..18] //wall left alt random 2x2 meta-ready 69
    (recursec)[..99][..16][..16] //wall left corner meta-ready 99
    (recursec)[..75][..18][..16] //wall right alt random 2x2  meta-ready 75
    (recursec)[.109][..20][..16] //wall right corner meta-ready 109
    (recursec)[..69][..20][..14] //wall left alt random 2x2 meta-ready 69
    (recursec)[.117][..20][..12] //wall arch dead-end left-down meta-ready 117

    (recursec)[.116][..20][...8] //wall arch dead-end right-up meta-ready 116
    (recursec)[..69][..20][...6] //wall left alt random 2x2 meta-ready 69
    (recursec)[..94][..20][...4] //wall corner down meta-ready 94
    (recursec)[..75][..18][...4] //wall right alt random 2x2  meta-ready 75
    (recursec)[..86][..16][...4] //wall corner up meta-ready 86
    (recursec)[..69][..16][...2] //wall left alt random 2x2 meta-ready 69
    (recursec)[..94][..16][...0] //wall corner down meta-ready 94
    (recursec)[..75][..14][...0] //wall right alt random 2x2  meta-ready 75
    (recursec)[.114][..12][...0] //wall arch dead-end left-up meta-ready 114

    (recursec)[.170][..04][..08] //pillar meta-ready 170
    (recursec)[.170][..04][..12] //pillar meta-ready 170
    (recursec)[.170][..08][...4] //pillar meta-ready 170
    (recursec)[.170][..12][...4] //pillar meta-ready 170
    (recursec)[.170][..16][...8] //pillar meta-ready 170
    (recursec)[.170][..16][..12] //pillar meta-ready 170
    (recursec)[.170][..08][..16] //pillar meta-ready 170
    (recursec)[.170][..12][..16] //pillar meta-ready 170

    (recursec)[..99][...8][...8] //wall left corner meta-ready 99
    (recursec)[..75][..10][...8] //wall right alt random 2x2  meta-ready 75
    (recursec)[..94][..12][..08] //wall corner down meta-ready 94
    (recursec)[..69][..12][..10] //wall left alt random 2x2 meta-ready 69
    (recursec)[.109][..12][..12] //wall right corner meta-ready 109
    (recursec)[.129][...8][..10] //lavablock wall left meta-ready 129
    (recursec)[.138][...8][..12] //lavablock wall upper_corner meta-ready 138
    (recursec)[.130][..10][..12] //lavablock wall right meta-ready 130
    (recursec)[.144][..10][..10] //lavablock no wall meta-ready 144

    (tile)[..10][...5] (move)[fly] (mech)[.128][+] // Big Ds lever chain 3rd a
    (tile)[..10][..17] (move)[fly] (mech)[.129][+] // Big Ds lever chain 3rd b




(sector_end)

// lev16 challange 4 final closed 206
(sector)[.206]

    (recursec)[.165][...0][...0] //double wall corner left 4x4 165
    (recursec)[.162][...0][...4]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][...6]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][...8]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][..10]//double wall left-down to right-up 4x2 162
    (recursec)[.162][...0][..12]//double wall left-down to right-up 4x2 162
    (recursec)[.163][...0][..14] //double wall corner up 4x4 163
    (recursec)[.161][...4][..14]//double wall left-up to right-down 2x4 161
    (recursec)[.161][...6][..14]//double wall left-up to right-down 2x4 161
    (recursec)[.161][...8][..14]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..10][..14]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..12][..14]//double wall left-up to right-down 2x4 161
    (recursec)[.166][..14][..14]//double wall corner right 4x4 166
    (recursec)[.162][..14][..12]//double wall left-down to right-up 4x2 162
    (recursec)[.162][..14][..10]//double wall left-down to right-up 4x2 162
    (recursec)[.162][..14][...8]//double wall left-down to right-up 4x2 162
    (recursec)[.162][..14][...6]//double wall left-down to right-up 4x2 162
    (recursec)[.162][..14][...4]//double wall left-down to right-up 4x2 162
    (recursec)[.164][..14][...0]//double wall corner down 4x4 164
    (recursec)[.161][..12][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.161][..10][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.161][...8][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.161][...6][...0]//double wall left-up to right-down 2x4 161
    (recursec)[.161][...4][...0]//double wall left-up to right-down 2x4 161

    (recursec)[..60][...4][...6] //unlid pentagram on ground 8x8 60
    (recursec)[.303][...1][...1] //16x16 nogo tiles 303



(sector_end)


// lev16 challange 4 final open 207
(sector)[.207]

    (recursec)[..54][-..2][-..2] // empty 16x16 patch of ground tiles 54
    (recursec)[..54][...4][...4] // empty 16x16 patch of ground tiles 54
    (recursec)[..54][-..2][...4] // empty 16x16 patch of ground tiles 54
    (recursec)[..54][...4][-..2] // empty 16x16 patch of ground tiles 54

    (recursec)[.169][...0][...4]//double wall dead-end right-up 169
    (recursec)[.165][...0][...0] //double wall corner left 4x4 165
    (recursec)[.167][...4][...0] //double wall dead-end right-down 2x4 167


    (recursec)[.168][...0][..12] //double wall dead-end left-down 2x4 168
    (recursec)[.163][...0][..14] //double wall corner up 4x4 163
    (recursec)[.167][...4][..14] //double wall dead-end right-down 2x4 167

    (recursec)[.171][..12][..14]//double wall dead-end left-up 171
    (recursec)[.166][..14][..14]//double wall corner right 4x4 166
    (recursec)[.168][..14][..12] //double wall dead-end left-down 2x4 168

    (recursec)[.169][..14][...4]//double wall dead-end right-up 169
    (recursec)[.164][..14][...0]//double wall corner down 4x4 164
    (recursec)[.171][..12][...0]//double wall dead-end left-up 171

    (recursec)[..60][...4][...6] //unlid pentagram on ground 8x8 60


    (tile)[...8][...9] (monster)[..50][ra] //big-daddy


(sector_end)

//lev16 final lever dump dump 208
(sector)[.208]

  (tile)[..00][..00] (mech)[.130][+] //Big Ds lever chain final

(sector_end)


**************************************************************************************************
***Slackspace*************************************************************************************
**************************************************************************************************

//radom level basis 220 assuming 192x192 tile grid
(sector)[.220]

  (recursec)[..56][...0][...0] // empty 64x64 patch of ground tiles 56
  (recursec)[..56][..64][...0] // empty 64x64 patch of ground tiles 56
  (recursec)[..56][.128][...0] // empty 64x64 patch of ground tiles 56

  (recursec)[..56][...0][..64] // empty 64x64 patch of ground tiles 56
  (recursec)[..56][..64][..64] // empty 64x64 patch of ground tiles 56
  (recursec)[..56][.128][..64] // empty 64x64 patch of ground tiles 56

  (recursec)[..56][...0][.128] // empty 64x64 patch of ground tiles 56
  (recursec)[..56][..64][.128] // empty 64x64 patch of ground tiles 56
  (recursec)[..56][.128][.128] // empty 64x64 patch of ground tiles 56



  (recursec)[.148][...0][...0] //lavablock 32x32
  (recursec)[.148][..32][...0] //lavablock 32x32
  (recursec)[.148][..64][...0] //lavablock 32x32
  (recursec)[.148][..96][...0] //lavablock 32x32
  (recursec)[.148][.128][...0] //lavablock 32x32
  (recursec)[.148][.160][...0] //lavablock 32x32

  (recursec)[.148][...0][.160] //lavablock 32x32
  (recursec)[.148][..32][.160] //lavablock 32x32
  (recursec)[.148][..64][.160] //lavablock 32x32
  (recursec)[.148][..96][.160] //lavablock 32x32
  (recursec)[.148][.128][.160] //lavablock 32x32
  (recursec)[.148][.160][.160] //lavablock 32x32

  (recursec)[.148][...0][..32] //lavablock 32x32
  (recursec)[.148][...0][..64] //lavablock 32x32
  (recursec)[.148][...0][..96] //lavablock 32x32
  (recursec)[.148][...0][.128] //lavablock 32x32

  (recursec)[.148][.160][..32] //lavablock 32x32
  (recursec)[.148][.160][..64] //lavablock 32x32
  (recursec)[.148][.160][..96] //lavablock 32x32
  (recursec)[.148][.160][.128] //lavablock 32x32


 (recursec)[.221][..32][..32] //radom level left room variation boring  221
 (recursec)[.222][..96][..96] //radom level right room variation boring  222
 (recursec)[.223][..32][..96] //radom level upper room variation boring  223
 (recursec)[.224][..96][..32] //radom level down room variation boring  224

(sector_end)


//radom level left room variation boring  221
(sector)[.221]


   (tile)[..44][..44] (dummy)[+]
   (tile)[..44][..28] (dummy)[+]

  (recursec)[.128][..00][..00] //lavablock corner left meta-ready
  (recursec)[.154][..00][..02] //wall left 8x
  (recursec)[..69][..00][..18] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..20] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..22] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..24] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..26] //wall left alt random 2x2 meta-ready 69

  (recursec)[.153][..00][..28] //wall left 4x 153

  (recursec)[.154][..00][..36] //wall left 8x
  (recursec)[..69][..00][..52] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..54] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..56] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..58] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..60] //wall left alt random 2x2 meta-ready 69
  (recursec)[..86][..00][..62] //wall corner up meta-ready 86
  (recursec)[.160][..02][..62] //wall right 8x 160
  (recursec)[..75][..18][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..20][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..22][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..24][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..26][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..94][..28][..62] //wall corner down meta-ready 94

  (recursec)[..99][..34][..62] //wall left corner meta-ready 99
  (recursec)[..75][..36][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..38][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..40][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..42][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..44][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[.160][..46][..62] //wall right 8x 160
  (recursec)[.127][..62][..62] //lavablock corner right meta-ready 127
  (recursec)[.151][..62][..46] //lava wall left 8x
  (recursec)[.129][..62][..44] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..42] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..40] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..38] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..36] //lavablock wall left meta-ready 129
  (recursec)[..99][..62][..34] //wall left corner meta-ready 99

  (recursec)[.138][..62][..28] //lavablock wall upper_corner meta-ready 138
  (recursec)[.151][..62][..12] //lava wall left 8x
  (recursec)[.129][..62][..10] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...8] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...6] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...4] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...2] //lavablock wall left meta-ready 129
  (recursec)[.139][..62][...0] //lavablock wall lower_corner meta-ready 139
  (recursec)[.157][..46][...0] //lava wall right 8x 157
  (recursec)[.130][..44][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..42][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..40][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..38][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..36][..00] //lavablock wall right meta-ready 130

  (recursec)[.156][..28][..00] //lava wall right 4x 156

  (recursec)[.130][..26][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..24][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..22][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..20][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..18][..00] //lavablock wall right meta-ready 130
  (recursec)[.157][...2][...0] //lava wall right 8x 157


(sector_end)


//radom level right room variation boring  222
(sector)[.222]

   (tile)[..04][..04] (dummy)[+]
   (tile)[..04][..20] (dummy)[+]

  (recursec)[.128][..00][..00] //lavablock corner left meta-ready
  (recursec)[.154][..00][..02] //wall left 8x
  (recursec)[..69][..00][..18] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..20] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..22] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..24] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..26] //wall left alt random 2x2 meta-ready 69
  (recursec)[.109][..00][..28] //wall right corner meta-ready 109

  (recursec)[..94][..00][..34] //wall corner down meta-ready 94
  (recursec)[.154][..00][..36] //wall left 8x
  (recursec)[..69][..00][..52] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..54] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..56] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..58] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..60] //wall left alt random 2x2 meta-ready 69
  (recursec)[..86][..00][..62] //wall corner up meta-ready 86
  (recursec)[.160][..02][..62] //wall right 8x 160
  (recursec)[..75][..18][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..20][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..22][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..24][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..26][..62] //wall right alt random 2x2  meta-ready 75

  (recursec)[.159][..28][..62] //wall right 4x 159

  (recursec)[..75][..36][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..38][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..40][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..42][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..44][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[.160][..46][..62] //wall right 8x 160
  (recursec)[.127][..62][..62] //lavablock corner right meta-ready 127
  (recursec)[.151][..62][..46] //lava wall left 8x
  (recursec)[.129][..62][..44] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..42] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..40] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..38] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..36] //lavablock wall left meta-ready 129

  (recursec)[.150][..62][..28] //lava wall left 4x 150

  (recursec)[.151][..62][..12] //lava wall left 8x
  (recursec)[.129][..62][..10] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...8] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...6] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...4] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...2] //lavablock wall left meta-ready 129
  (recursec)[.139][..62][...0] //lavablock wall lower_corner meta-ready 139
  (recursec)[.157][..46][...0] //lava wall right 8x 157
  (recursec)[.130][..44][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..42][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..40][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..38][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..36][..00] //lavablock wall right meta-ready 130
  (recursec)[.138][..34][..00] //lavablock wall upper_corner meta-ready 138

  (recursec)[.109][..28][..00] //wall right corner meta-ready 109
  (recursec)[.130][..26][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..24][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..22][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..20][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..18][..00] //lavablock wall right meta-ready 130
  (recursec)[.157][...2][...0] //lava wall right 8x 157


(sector_end)


//radom level upper room variation boring  223
(sector)[.223]

   (tile)[..44][..20] (dummy)[+]
   (tile)[..44][..04] (dummy)[+]

  (recursec)[.128][..00][..00] //lavablock corner left meta-ready
  (recursec)[.154][..00][..02] //wall left 8x
  (recursec)[..69][..00][..18] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..20] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..22] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..24] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..26] //wall left alt random 2x2 meta-ready 69

  (recursec)[.153][..00][..28] //wall left 4x 153

  (recursec)[.154][..00][..36] //wall left 8x
  (recursec)[..69][..00][..52] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..54] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..56] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..58] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..60] //wall left alt random 2x2 meta-ready 69
  (recursec)[..86][..00][..62] //wall corner up meta-ready 86
  (recursec)[.160][..02][..62] //wall right 8x 160
  (recursec)[..75][..18][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..20][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..22][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..24][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..26][..62] //wall right alt random 2x2  meta-ready 75

  (recursec)[.159][..28][..62] //wall right 4x 159

  (recursec)[..75][..36][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..38][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..40][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..42][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..44][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[.160][..46][..62] //wall right 8x 160
  (recursec)[.127][..62][..62] //lavablock corner right meta-ready 127
  (recursec)[.151][..62][..46] //lava wall left 8x
  (recursec)[.129][..62][..44] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..42] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..40] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..38] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..36] //lavablock wall left meta-ready 129
  (recursec)[..99][..62][..34] //wall left corner meta-ready 99

  (recursec)[.138][..62][..28] //lavablock wall upper_corner meta-ready 138
  (recursec)[.151][..62][..12] //lava wall left 8x
  (recursec)[.129][..62][..10] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...8] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...6] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...4] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...2] //lavablock wall left meta-ready 129
  (recursec)[.139][..62][...0] //lavablock wall lower_corner meta-ready 139
  (recursec)[.157][..46][...0] //lava wall right 8x 157
  (recursec)[.130][..44][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..42][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..40][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..38][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..36][..00] //lavablock wall right meta-ready 130
  (recursec)[.138][..34][..00] //lavablock wall upper_corner meta-ready 138

  (recursec)[.109][..28][..00] //wall right corner meta-ready 109
  (recursec)[.130][..26][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..24][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..22][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..20][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..18][..00] //lavablock wall right meta-ready 130
  (recursec)[.157][...2][...0] //lava wall right 8x 157


(sector_end)


//radom level down room variation boring  224
(sector)[.224]

   (tile)[..04][..44] (dummy)[+]
   (tile)[..04][..28] (dummy)[+]

  (recursec)[.128][..00][..00] //lavablock corner left meta-ready
  (recursec)[.154][..00][..02] //wall left 8x
  (recursec)[..69][..00][..18] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..20] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..22] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..24] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..26] //wall left alt random 2x2 meta-ready 69
  (recursec)[.109][..00][..28] //wall right corner meta-ready 109

  (recursec)[..94][..00][..34] //wall corner down meta-ready 94
  (recursec)[.154][..00][..36] //wall left 8x
  (recursec)[..69][..00][..52] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..54] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..56] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..58] //wall left alt random 2x2 meta-ready 69
  (recursec)[..69][..00][..60] //wall left alt random 2x2 meta-ready 69
  (recursec)[..86][..00][..62] //wall corner up meta-ready 86
  (recursec)[.160][..02][..62] //wall right 8x 160
  (recursec)[..75][..18][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..20][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..22][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..24][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..26][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..94][..28][..62] //wall corner down meta-ready 94

  (recursec)[..99][..34][..62] //wall left corner meta-ready 99
  (recursec)[..75][..36][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..38][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..40][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..42][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[..75][..44][..62] //wall right alt random 2x2  meta-ready 75
  (recursec)[.160][..46][..62] //wall right 8x 160
  (recursec)[.127][..62][..62] //lavablock corner right meta-ready 127
  (recursec)[.151][..62][..46] //lava wall left 8x
  (recursec)[.129][..62][..44] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..42] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..40] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..38] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][..36] //lavablock wall left meta-ready 129

  (recursec)[.150][..62][..28] //lava wall left 4x 150

  (recursec)[.151][..62][..12] //lava wall left 8x
  (recursec)[.129][..62][..10] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...8] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...6] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...4] //lavablock wall left meta-ready 129
  (recursec)[.129][..62][...2] //lavablock wall left meta-ready 129
  (recursec)[.139][..62][...0] //lavablock wall lower_corner meta-ready 139
  (recursec)[.157][..46][...0] //lava wall right 8x 157
  (recursec)[.130][..44][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..42][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..40][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..38][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..36][..00] //lavablock wall right meta-ready 130

  (recursec)[.156][..28][..00] //lava wall right 4x 156

  (recursec)[.130][..26][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..24][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..22][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..20][..00] //lavablock wall right meta-ready 130
  (recursec)[.130][..18][..00] //lavablock wall right meta-ready 130
  (recursec)[.157][...2][...0] //lava wall right 8x 157


(sector_end)




**************************************************************************************************
***Slackspace*************************************************************************************
**************************************************************************************************

 //2x2 nogo tiles 300
(sector)[.300]
    (tile)[...0][...0] (move)[none]
    (tile)[...1][...0] (move)[none]
    (tile)[...0][...1] (move)[none]
    (tile)[...1][...1] (move)[none]
(sector_end)

 //4x4 nogo tiles 301
(sector)[.301]
    (recursec)[.300][...0][...0] //2x2 nogo tiles 300
    (recursec)[.300][...2][...0] //2x2 nogo tiles 300
    (recursec)[.300][...0][...2] //2x2 nogo tiles 300
    (recursec)[.300][...2][...2] //2x2 nogo tiles 300
(sector_end)

 //8x8 nogo tiles 302
(sector)[.302]
    (recursec)[.301][...0][...0] //4x4 nogo tiles 301
    (recursec)[.301][...4][...0] //4x4 nogo tiles 301
    (recursec)[.301][...0][...4] //4x4 nogo tiles 301
    (recursec)[.301][...4][...4] //4x4 nogo tiles 301
(sector_end)

 //16x16 nogo tiles 303
(sector)[.303]
    (recursec)[.302][...0][...0] //8x8 nogo tiles 302
    (recursec)[.302][...8][...0] //8x8 nogo tiles 302
    (recursec)[.302][...0][...8] //8x8 nogo tiles 302
    (recursec)[.302][...8][...8] //8x8 nogo tiles 302
(sector_end)

 //32x32 nogo tiles 304
(sector)[.304]
    (recursec)[.303][...0][...0] //16x16 nogo tiles 303
    (recursec)[.303][..16][...0] //16x16 nogo tiles 303
    (recursec)[.303][...0][..16] //16x16 nogo tiles 303
    (recursec)[.303][..16][..16] //16x16 nogo tiles 303
(sector_end)



**************************************************************************************************
***Slackspace*************************************************************************************
**************************************************************************************************


//level 15 sectorfix16x16: warp back up
(sector)[.310]

    (recursec)[..62][...4][...4]  //stairs back up
              (tile)[...7][...6] (mech)[..42][+] //warp up 
              (tile)[...7][...7] (mech)[..42][+] //warp up 

(sector_end)

//level 15 sectorfix16x16: closed warp down to d
(sector)[.311]
   //todo
(sector_end)

//level 15 sectorfix16x16: open warp down to d
(sector)[.312]

    (recursec)[..61][...4][...4] //lid pentagram on ground 8x8 61
              (tile)[...7][...7] (mech)[..43][+] //warp down
              (tile)[...7][...8] (mech)[..43][+] //warp down
              (tile)[...8][...7] (mech)[..43][+] //warp down
              (tile)[...8][...8] (mech)[..43][+] //warp down


(sector_end)

//level 15 sectorfix16x16: portal to arnie
(sector)[.313]

     (tile)[.005][..10] (mech)[..67][+] //warp to arnie
                        (light)[.255][..20][...0][...6]

(sector_end)

//level 15 sectorfix16x16: shower dinks guys drink
(sector)[.314]
   //todo
(sector_end)


**************************************************************************************************
***Slackspace*************************************************************************************
**************************************************************************************************

<datablock_end>

<end>
****************************

























