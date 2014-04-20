<begin>

<datablock>[....][level]

(sectors)[.200] 


  // tristram
  (sector)[...0]

    (recursec)[.187][..00][..00] // grass
    (recursec)[.102][..00][..00] // rivers and walls collection
    (recursec)[.138][..00][..00] // graveyard
    (recursec)[.159][..00][..00] // roads collection
    (recursec)[.166][..00][..00] // stone collection
    (recursec)[.180][..00][..00] // tree collection
    (recursec)[.181][..00][..00] // wildgroth collection
    (recursec)[.182][..00][..00] // nogo collection


    (recursec)[..80][..71][..50] // the inn
    (recursec)[..82][..71][..34] // healers howse
    (recursec)[..93][..93][..41] // north-south streching house big
    (recursec)[..92][..49][..61] // north-south streching house small
    (recursec)[..94][..84][..50] // smiths house
    (recursec)[..99][..89][..32] // east-west streching house small closed door
    (recursec)[.100][..66][..68] // east-west streching house big closed door
    (recursec)[.101][..59][..46] // east-west streching house small open door
    (recursec)[..83][.104][..96] // cooking pot
    (recursec)[..84][..97][..91] // scary lady house house
    (recursec)[.141][..39][..77] // the chruch

    (tile)[..79][.102] (monster)[...1][ra] //animal
    (tile)[..83][..99] (monster)[...1][ra] //animal
    (tile)[..85][.101] (monster)[...1][ra] //animal
    (tile)[..81][.103] (monster)[...1][ra] //animal
    (tile)[..79][..99] (monster)[...1][ra] //animal
    (tile)[..86][..52] (monster)[...2][nn] //smith
    (tile)[..96][..30] (monster)[...3][nn] //addict
    (tile)[..79][..36] (monster)[...4][nn] //doctor
    (tile)[..86][..44] (monster)[...5][nn] //elder
    (tile)[..79][..53] (monster)[...6][nn] //hotel owner
    (tile)[..67][..49] (monster)[...7][nn] //waitress
    (tile)[..38][..60] (monster)[...8][nn] //profiteer
    (tile)[.104][..95] (monster)[...9][nn] //scary lady





    (tile)[..99][..44] (move)[none] (mech)[...0][+] //stash


    (tile)[..49][..85] (mech)[..13][+] //warp to l1



              (tile)[..83][..44] (mech)[.150][+] //Dummy a for fountain fix
    (recursec)[.111][..83][..44] // elders fountain base
    (recursec)[.112][..83][..44] // elders fountain clear
    (recursec)[.113][..83][..44] // elders fountain murky


              (tile)[..70][..93] (mech)[.151][+] //Dummy b for cat shortcut fix
    (recursec)[..86][..70][..93] // catacombs entrance
    (recursec)[..88][..70][..93] // catacombs entrance close
    *recursec)[..87][..70][..93] // catacombs entrance open

              (tile)[..36][..44] (mech)[.152][+] //Dummy c for caves shortcut fix
    (recursec)[.105][..36][..44]  //caves entrace closed
    *recursec)[.106][..36][..44]  //caves entrace make opening


              (tile)[..61][..36] (mech)[.153][+] //Dummy d for hell shortcut fix
    (recursec)[.104][..61][..36] // hellhole close
    *recursec)[.103][..61][..36] // hellhole open


                     (tile)[.102][..50] (mech)[.154][+] //Dummy e for hive shortcut fix
    (if_hf)(recursec)[.107][.102][..50]  //hellfire hive closed
    *if_hf)*recursec)[.108][.102][..50]  //hellfire hive open up

                     (tile)[..60][..93] (mech)[.155][+] //Dummy f for crypt shotcut fix
    (if_hf)(recursec)[.109][..60][..93]  //hellfire crypt closed
    *if_hf)*recursec)[.110][..60][..93]  //hellfire crypt open up

    (tile)[..47][..82] (mech)[.156][+] //Dummy g for deadguy fix
    (tile)[..48][..83](monster)[..10][nn] //deadguy

    (tile)[..81][..97] (mech)[.157][+] //Dummy h for cowqgiver fix
    (tile)[.102][..60] (mech)[.158][+] //Dummy i for girl fix

    (tile)[..53][..64] (mech)[.159][+] //Dumy j for test level warp


  (sector_end)

   // test level shortcut application
  (sector)[..01]

    (tile)[...1][...1] (mech)[...1][+] //warp to test church

  (sector_end)

  // empty 4x4 patch of grass
  (sector)[..50] (texg)[...0]
    (tile)[...0][...0] (ground)[..00][..01](self_lum)[.255][.255][255]
    (tile)[...1][...0] (ground)[..02][..03](self_lum)[.255][.255][255]
    (tile)[...2][...0] (ground)[..04][..05](self_lum)[.255][.255][255]
    (tile)[...3][...0] (ground)[..06][..07](self_lum)[.255][.255][255]
    (tile)[...0][...1] (ground)[..08][..09](self_lum)[.255][.255][255]
    (tile)[...1][...1] (ground)[..0a][..0b](self_lum)[.255][.255][255]
    (tile)[...2][...1] (ground)[..0c][..0d](self_lum)[.255][.255][255]
    (tile)[...3][...1] (ground)[..0e][..0f](self_lum)[.255][.255][255]
    (tile)[...0][...2] (ground)[..10][..11](self_lum)[.255][.255][255]
    (tile)[...1][...2] (ground)[..12][..13](self_lum)[.255][.255][255]
    (tile)[...2][...2] (ground)[..14][..15](self_lum)[.255][.255][255]
    (tile)[...3][...2] (ground)[..16][..17](self_lum)[.255][.255][255]
    (tile)[...0][...3] (ground)[..18][..19](self_lum)[.255][.255][255]
    (tile)[...1][...3] (ground)[..1a][..1b](self_lum)[.255][.255][255]
    (tile)[...2][...3] (ground)[..1c][..1d](self_lum)[.255][.255][255]
    (tile)[...3][...3] (ground)[..1e][..1f](self_lum)[.255][.255][255]
  (sector_end)

  // river 2x2 straight a
  (sector)[..51] (texg)[...0]
    (tile)[...0][...0] (ground)[.25d][.25e] (move)[none]
    (tile)[...1][...0] (ground)[.25f][.260] (move)[none]
    (tile)[...0][...1] (ground)[.261][.262] (move)[none]
    (tile)[...1][...1] (ground)[.263][.264] (move)[none]
  (sector_end)

  // river 2x2 straight b
  (sector)[..52] (texg)[...0]
    (tile)[...0][...0] (ground)[.265][.266] (move)[none]
    (tile)[...1][...0] (ground)[.267][.268] (move)[none]
    (tile)[...0][...1] (ground)[.269][.26a] (move)[none]
    (tile)[...1][...1] (ground)[.26b][.26c] (move)[none]
  (sector_end)

  // river 2x2 straight c
  (sector)[..53] (texg)[...0]
    (tile)[...0][...0] (ground)[.26d][.26e] (move)[none]
    (tile)[...1][...0] (ground)[.26f][.270] (move)[none]
    (tile)[...0][...1] (ground)[.271][.272] (move)[none]
    (tile)[...1][...1] (ground)[.273][.274] (move)[none]
  (sector_end)

  // river 2x2 straight d
  (sector)[..54] (texg)[...0]
    (tile)[...0][...0] (ground)[.275][.276] (move)[none]
    (tile)[...1][...0] (ground)[.277][.278] (move)[none]
    (tile)[...0][...1] (ground)[.279][.27a] (move)[none]
    (tile)[...1][...1] (ground)[.27b][.27c] (move)[none]
  (sector_end)

  // river 2x4 straight combi
  (sector)[..55] (texg)[...0]
    (recursec)[..51][...0][...0]
    (recursec)[..52][...0][...2]
  (sector_end)

  // river 2x8 straight combi
  (sector)[..56] (texg)[...0]
    (recursec)[..51][...0][...0]
    (recursec)[..52][...0][...2]
    (recursec)[..54][...0][...4]
    (recursec)[..52][...0][...6]
  (sector_end)

  // bridge 2x2
  (sector)[..57] (texg)[...0]
    (tile)[...0][...0] (ground)[.2c1][.2c2]
    (tile)[...1][...0] (ground)[.2c3][.2c4]
    (tile)[...0][...1] (ground)[.2bd][.2be] (move)[none]
    (tile)[...1][...1] (ground)[.2bf][.2c0] (move)[none]
  (sector_end)

  // river swirl up
  (sector)[..58] (texg)[...0]
    (tile)[...1][...0] (ground)[.27d][.27e]
    (tile)[...2][...0] (ground)[.291][.292] (move)[none]
    (tile)[...3][...0] (ground)[.293][.294] (move)[none]
    (tile)[...1][...1] (ground)[.27f][.280] (move)[none]
    (tile)[...2][...1] (ground)[.28d][.28e] (move)[none]
    (tile)[...3][...1] (ground)[.28f][.290]
    (tile)[...0][...2] (ground)[.289][.28a]
    (tile)[...1][...2] (ground)[.28b][.28c] (move)[none]
    (tile)[...2][...2] (ground)[.299][.29a]
    (tile)[...3][...2] (ground)[.29b][.29c]
    (tile)[...0][...3] (ground)[.285][.286] (move)[none]
    (tile)[...1][...3] (ground)[.287][.288] (move)[none]
  (sector_end)

  // river swirl down
  (sector)[..59] (texg)[...0]
    (tile)[...0][...0] (ground)[.2a1][.2a2] (move)[none]
    (tile)[...1][...0] (ground)[.2a3][.2a4] (move)[none]
    (tile)[...0][...1] (ground)[.29d][.29e]
    (tile)[...1][...1] (ground)[.29f][.2a0] (move)[none]
    (tile)[...2][...1] (ground)[.2ad][.2ae] (move)[none]
    (tile)[...1][...2] (ground)[.2ab][.2ac]
    (tile)[...2][...2] (ground)[.2b9][.2ba] (move)[none]
    (tile)[...3][...2] (ground)[.2bb][.2bc] (move)[none]
    (tile)[...2][...3] (ground)[.2b5][.2b6] (move)[none]
    (tile)[...3][...3] (ground)[.2b7][.2b8] (move)[none]
  (sector_end)

  // river split
  (sector)[..60] (texg)[...0]
    (tile)[...1][...0] (ground)[.27d][.27e] 
    (tile)[...2][...0] (ground)[.291][.292] (move)[none]
    (tile)[...3][...0] (ground)[.2a3][.2a4] (move)[none]

    (tile)[...1][...1] (ground)[.27f][.280] (move)[none]
    (tile)[...2][...1] (ground)[.28d][.28e] (move)[none]
    (tile)[...3][...1] (ground)[.cd3][.2a0] (move)[none]
    (tile)[...4][...1] (ground)[.2ad][.2ae] (move)[none]

    (tile)[...0][...2] (ground)[.289][.28a]
    (tile)[...1][...2] (ground)[.28b][.28c] (move)[none]
    (tile)[...2][...2] (ground)[.299][.29a] (move)[none]
    (tile)[...3][...2] (ground)[.2ab][.2ac] (move)[none]
    (tile)[...4][...2] (ground)[.2b9][.2ba] (move)[none]
    (tile)[...5][...2] (ground)[.2bb][.2bc] (move)[none]

    (tile)[...0][...3] (ground)[.285][.286] (move)[none]
    (tile)[...1][...3] (ground)[.287][.288] (move)[none]
    (tile)[...4][...3] (ground)[.2b5][.2b6] (move)[none]
    (tile)[...5][...3] (ground)[.2b7][.2b8] (move)[none]
  (sector_end)

  // 4 river swirlups in a row
  (sector)[..61]
    (recursec)[..58][...0][...0]
    (recursec)[..58][-..2][...4]
    (recursec)[..58][-..4][...8]
    (recursec)[..58][-..6][..12]
  (sector_end)

   //tree overhanging water
   (sector)[..62]  (texg)[...0]
     (tile)[...3][...0] (ground)[.2e9][.2ea] (move)[none]
     (tile)[...4][...0] (ground)[.2eb][.2ec] (move)[none]
     (tile)[...5][...0] (ground)[.2ef][.2f0]

     (tile)[...0][...1] (ground)[.2cf][.2d0]
     (tile)[...1][...1] (ground)[.2dd][.2de]
     (tile)[...2][...1] (ground)[.2df][.2e0]
     (tile)[...3][...1] (ground)[.2e5][.2e6] (move)[none]
     (tile)[...4][...1] (ground)[.2e7][.2e8] (move)[none]
     (tile)[...5][...1] (ground)[.2ed][.2ee] (move)[none]
     (tile)[...6][...1] (ground)[.2f1][.2f2]

     (tile)[...0][...2] (ground)[.2cb][.2cc]
     (tile)[...1][...2] (ground)[.2d9][.2da]
     (tile)[...2][...2] (ground)[.2db][.2dc]
     (tile)[...3][...2] (ground)[.335][.336]
     (tile)[...4][...2] (ground)[.337][.338] (move)[none]
     (tile)[...5][...2] (ground)[.2f9][.2fa] (move)[none]
     (tile)[...6][...2] (ground)[.2fb][.2fc] (move)[none]

     (tile)[...0][...3] (ground)[.2c7][.2c8]
     (tile)[...1][...3] (ground)[.2d5][.2d6]
     (tile)[...2][...3] (ground)[.2d7][.2d8]
     (tile)[...3][...3] (ground)[.327][.328]
     (tile)[...4][...3] (ground)[.32f][.330] (move)[none]
     (tile)[...5][...3] (ground)[.2f5][.2f6] (move)[none]
     (tile)[...6][...3] (ground)[.2f7][.2f8] (move)[none]

     (tile)[...1][...4] (ground)[.301][.302]
     (tile)[...2][...4] (ground)[.303][.304]
     (tile)[...3][...4] (ground)[.309][.30a]
     (tile)[...4][...4] (ground)[.30b][.30c] (move)[none]
     (tile)[...5][...4] (ground)[.34d][.34e] (move)[none]
     (tile)[...6][...4] (ground)[.34f][.350] (move)[none]

     (tile)[...2][...5] (ground)[.2ff][.300]
     (tile)[...3][...5] (ground)[.305][.306]
     (tile)[...4][...5] (ground)[.307][.308] (move)[none]
     (tile)[...5][...5] (ground)[.343][.344] (move)[none]
     (tile)[...6][...5] (ground)[.347][.348] (move)[none]

     (tile)[...3][...6] (ground)[.311][.312] (move)[none]
     (tile)[...4][...6] (ground)[.313][.314] (move)[none]
     (tile)[...5][...6] (ground)[.319][.31a] (move)[none]
     (tile)[...6][...6] (ground)[.31b][.31c]

     (tile)[...3][...7] (ground)[.30d][.30e] (move)[none]
     (tile)[...4][...7] (ground)[.30f][.310] (move)[none]
     (tile)[...5][...7] (ground)[.315][.316]

     (tile)[...4][...4]
       (air)[.32e][..00][..16]
       (air)[.32d][..00][..48]
       (air)[.32c][..00][..80]
       (air)[.32b][..00][.112]
       (air)[.32a][..00][.144]
       (air)[.329][..00][.176]

       (air)[.34c][..32][..48]
       (air)[.34b][..32][..80]
       (air)[.34a][..32][.112]
       (air)[.349][..32][.144]

       (air)[.341][..64][..32]
       (air)[.33f][..64][..64]
       (air)[.33d][..64][..96]
       (air)[.33b][..64][.128]
       (air)[.339][..64][.160]

       (air)[.342][..96][..32]
       (air)[.340][..96][..64]
       (air)[.33e][..96][..96]
       (air)[.33c][..96][.128]

       (air)[.346][.128][..80]
       (air)[.345][.128][.112]

       (air)[.326][-.32][..64]
       (air)[.324][-.32][..96]
       (air)[.322][-.32][.128]
       (air)[.320][-.32][.160]
       (air)[.31e][-.32][.192]

       (air)[.325][-.64][..64]
       (air)[.323][-.64][..96]
       (air)[.321][-.64][.128]
       (air)[.31f][-.64][.160]
       (air)[.31d][-.64][.192]


       (air)[.334][-.96][..48]
       (air)[.333][-.96][..80]
       (air)[.332][-.96][.112]
       (air)[.331][-.96][.144]
  (sector_end)


   //wall corner facing away
   (sector)[..63]  (texg)[...0]
     (tile)[...0][...0] (ground)[.bf2][.bf3] (air)[.bf1][..00][..32] (move)[none]
     (tile)[...0][...1] (ground)[.bf6][.bf7] (air)[.bf4][..00][..32] (air)[.bf5][..32][..32](move)[none]
     (tile)[...1][...1] (ground)[.bf9][.bfa] (air)[.bf8][..32][..32] (move)[none]
     (tile)[-..1][...0] (move)[none]
     (tile)[-..1][...1] (move)[none]
     (tile)[...0][...2] (move)[none]
     (tile)[...1][...2] (move)[none]
     (tile)[-..1][...2] (move)[none]
   (sector_end)

   //wall dead end west no shadow
   (sector)[..64]  (texg)[...0]
     (tile)[...0][...0] (ground)[.bae][.baf] (air)[.bac][..00][..32] (air)[.bad][..32][..32](move)[none]
     (tile)[...1][...0] (ground)[.bb1][.bb2] (air)[.bb0][..32][..32] (move)[none]
     (tile)[...0][...1] (move)[none]
     (tile)[...1][...1] (move)[none]
   (sector_end)

   //wall corner facing towards
   (sector)[..65]  (texg)[...0]
     (tile)[...0][...0] (ground)[.bea][.beb] (air)[.be9][..32][..32](move)[none]
     (tile)[...1][...0] (ground)[.bec][.bed] (move)[none]
     (tile)[...0][...1] (move)[none]
     (tile)[...1][...1] (ground)[.c10][.c11] (air)[.cof][..00][..32](move)[none]
   (sector_end)

   //wall crossing
   (sector)[..66]
     (recursec)[..65][-..1][...1]
     (recursec)[..63][...0][...0]
   (sector_end)

   // wall crumbeling towards north
   (sector)[..67]  (texg)[...0]
     (tile)[...0][...0] (ground)[.c33][.c34] (air)[.c32][..00][..32](move)[none]
     (tile)[...0][...1] (ground)[.c30][.c31]
   (sector_end)

   // wall crumbeling towards south
   (sector)[..68]  (texg)[...0]
     (tile)[...0][...0] (ground)[.c39][.c3a] (air)[.c38][..00][..32]
     (tile)[...0][...1] (ground)[.c36][.c37] (air)[.c35][..00][..32](move)[none]
     (tile)[-..1][...1] (move)[none]
   (sector_end)

   // wall west corner shadow
   (sector)[..69]  (texg)[...0]
     (tile)[...0][...0] (ground)[.bd7][.bd8]
     (tile)[...1][...0] (ground)[.bdb][.bdc] (air)[.bd9][..00][..32] (air)[.bda][..32][..32](move)[none]
     (tile)[...2][...0] (ground)[.bde][.bdf] (air)[.bdd][..32][..32](move)[none]
     (tile)[...1][...1] (move)[none]
     (tile)[...2][...1] (move)[none]
   (sector_end)

   // wall east corner no bend
   (sector)[..70]  (texg)[...0]
     (tile)[...0][...0] (ground)[.bd2][.bd3] (air)[.bd1][..32][..32](move)[none]
     (tile)[...1][...0] (ground)[.bd5][.bd6] (air)[.bd4][..32][..32](move)[none]
     (tile)[...0][...1] (move)[none]
     (tile)[...1][...1] (move)[none]
   (sector_end)

   // wall north corner
   (sector)[..71]  (texg)[...0]
     (tile)[...0][...0] (ground)[.c40][.c41] (air)[.c3f][..00][..32](move)[none]
     (tile)[...0][...1] (ground)[.c3d][.c3e] (air)[.c3b][..00][..32](air)[.c3c][..32][..32](move)[none]
     (tile)[-..1][...0] (move)[none]
     (tile)[-..1][...1] (move)[none]
   (sector_end)

   // wall north-souh single
   (sector)[..72]  (texg)[...0]
     (tile)[...0][...0] (ground)[.c13][.c14] (air)[.c12][..00][..32](move)[none]
     (tile)[-..1][...0] (move)[none]
   (sector_end)

   // wall north-south double
   (sector)[..73]  (texg)[...0]
     (tile)[...0][...0] (ground)[.c16][.c17] (air)[.c15][..00][..32](move)[none]
     (tile)[-..1][...0] (move)[none]
     (tile)[...0][...1] (ground)[.c19][.c1a] (air)[.c18][..00][..32](move)[none]
     (tile)[-..1][...1] (move)[none]
   (sector_end)

   // wall north-south quad
   (sector)[..74]  (texg)[...0]
     (tile)[...0][...0] (ground)[.c1c][.c1d] (air)[.c1b][..00][..32](move)[none]
     (tile)[-..1][...0] (move)[none]
     (tile)[...0][...1] (ground)[.c1f][.c20] (air)[.c1e][..00][..32](move)[none]
     (tile)[-..1][...1] (move)[none]
     (tile)[...0][...2] (ground)[.c22][.c23] (air)[.c21][..00][..32](move)[none]
     (tile)[-..1][...2] (move)[none]
     (tile)[...0][...3] (ground)[.c25][.c26] (air)[.c24][..00][..32](move)[none]
     (tile)[-..1][...3] (move)[none]
   (sector_end)

   // wall north-south 11x
   (sector)[..75]  (texg)[...0]
     (recursec)[..74][...0][...0]
     (recursec)[..74][...0][...4]
     (recursec)[..73][...0][...8]
     (recursec)[..72][...0][..10]
   (sector_end)

   // wall east-west single
   (sector)[..76]  (texg)[...0]
     (tile)[...0][...0] (ground)[.bb4][.bb5] (air)[.bb3][..32][..32](move)[none]
     (tile)[...0][...1] (move)[none]
   (sector_end)

   // wall east-west double
   (sector)[..77]  (texg)[...0]
     (tile)[...0][...0] (ground)[.bb7][.bb8] (air)[.bb6][..32][..32](move)[none]
     (tile)[...0][...1] (move)[none]
     (tile)[...1][...0] (ground)[.bba][.bbb] (air)[.bb9][..32][..32](move)[none]
     (tile)[...1][...1] (move)[none]
   (sector_end)

   // wall east-west quad
   (sector)[..78]  (texg)[...0]
     (tile)[...0][...0] (ground)[.bbd][.bbe] (air)[.bbc][..32][..32](move)[none]
     (tile)[...0][...1] (move)[none]
     (tile)[...1][...0] (ground)[.bc0][.bc1] (air)[.bbf][..32][..32](move)[none]
     (tile)[...1][...1] (move)[none]
     (tile)[...2][...0] (ground)[.bc3][.bc4] (air)[.bc2][..32][..32](move)[none]
     (tile)[...2][...1] (move)[none]
     (tile)[...3][...0] (ground)[.bc6][.bc7] (air)[.bc5][..32][..32](move)[none]
     (tile)[...3][...1] (move)[none]
   (sector_end)

   // wall east-west octa
   (sector)[..79]  (texg)[...0]
     (tile)[...0][...0] (ground)[.bc9][.bca] (air)[.bc8][..32][..32](move)[none]
     (tile)[...0][...1] (move)[none]
     (tile)[...1][...0] (ground)[.bcc][.bcd] (air)[.bcb][..32][..32](move)[none]
     (tile)[...1][...1] (move)[none]
     (tile)[...2][...0] (ground)[.bcf][.bd0] (air)[.bce][..32][..32](move)[none]
     (tile)[...2][...1] (move)[none]
     (tile)[...3][...0] (ground)[.be1][.be2] (air)[.be0][..32][..32](move)[none]
     (tile)[...3][...1] (move)[none]
     (tile)[...4][...0] (ground)[.be4][.be5] (air)[.be3][..32][..32](move)[none]
     (tile)[...4][...1] (move)[none]
     (tile)[...5][...0] (ground)[.be7][.be8] (air)[.be6][..32][..32](move)[none]
     (tile)[...5][...1] (move)[none]
     (tile)[...6][...0] (ground)[.bff][.c00] (air)[.bfe][..32][..32](move)[none]
     (tile)[...6][...1] (move)[none]
     (tile)[...7][...0] (ground)[.c02][.c03] (air)[.c01][..32][..32](move)[none]
     (tile)[...7][...1] (move)[none]
   (sector_end)

   //the inn building
    (sector)[..80]  (texg)[...0]

       (tile)[...0][...0] (ground)[.36f][.370]
       (tile)[...1][...0] (ground)[.37e][.37f]
       (tile)[...2][...0] (ground)[.380][.381]
       (tile)[...3][...0] (ground)[.38e][.38f]
       (tile)[...4][...0] (ground)[.390][.391]
       (tile)[...5][...0] (ground)[.396][.397]
       (tile)[...6][...0] (ground)[.398][.399]
       (tile)[...7][...0] (ground)[.39e][.39f]
       (tile)[...8][...0] (ground)[.3a0][.3a1]
       (tile)[...9][...0] (ground)[.3a6][.3a7]
       (tile)[..10][...0] (ground)[.3a8][.3a9]

       (tile)[...0][...1] (ground)[.36b][.36c]
       (tile)[...1][...1] (ground)[.374][.375]  (move)[none]
       (tile)[...2][...1] (ground)[.37c][.37d]  (move)[none]
       (tile)[...3][...1] (ground)[.386][.387]  (move)[none]
       (tile)[...4][...1] (ground)[.38c][.38d]  (move)[none]
       (tile)[...5][...1] (ground)[.392][.393]  (move)[none]
       (tile)[...6][...1] (ground)[.394][.395]
       (tile)[...7][...1] (ground)[.39a][.39b]
       (tile)[...8][...1] (ground)[.39c][.39d]
       (tile)[...9][...1] (ground)[.3a2][.3a3]
       (tile)[..10][...1] (ground)[.3a4][.3a5]

       (tile)[...0][...2] (ground)[.36f][.370]
       (tile)[...1][...2] (ground)[.374][.375](move)[none]
       (tile)[...2][...2] (move)[none]
       (tile)[...3][...2] (move)[none]
       (tile)[...4][...2] (move)[none]
       (tile)[...5][...2] (move)[none]
       (tile)[...6][...2] (ground)[.412][.413]
       (tile)[...7][...2] (ground)[.3f8][.3f9]
       (tile)[...8][...2] (ground)[.3fa][.3fb]
       (tile)[...9][...2] (ground)[.3ae][.3af]
       (tile)[..10][...2] (ground)[.3b0][.3b1]

       (tile)[...0][...3] (ground)[.36b][.36c]
       (tile)[...1][...3] (move)[none]
       (tile)[...2][...3] (move)[none]
       (tile)[...3][...3] (move)[none]
       (tile)[...4][...3] (move)[none]
       (tile)[...5][...3] (move)[none]
       (tile)[...6][...3] (ground)[.40a][.40b](move)[none]
       (tile)[...7][...3] (ground)[.3ee][.3ef]
       (tile)[...8][...3] (ground)[.3f6][.3f7]
       (tile)[...9][...3] (ground)[.3aa][.3ab]
       (tile)[..10][...3] (ground)[.3ac][.3ad]

       (tile)[...1][...4] (move)[none]
       (tile)[...2][...4] (move)[none]
       (tile)[...3][...4] (move)[none]
       (tile)[...4][...4] (move)[none]
       (tile)[...5][...4] (move)[none]
       (tile)[...6][...4] (ground)[-..1][-..1](move)[none]
       (tile)[...7][...4] (ground)[.41a][.41b](move)[none]
       (tile)[...8][...4] (ground)[.41c][-..1](move)[none]
       (tile)[...9][...4] (ground)[.3c1][.3c2]
       (tile)[..10][...4] (ground)[.3c3][.3c4]

       (tile)[...1][...5] (move)[none]
       (tile)[...2][...5] (move)[none]
       (tile)[...3][...5] (move)[none]
       (tile)[...4][...5] (move)[none]
       (tile)[...5][...5] (ground)[-..1][-..1](move)[none]
       (tile)[...6][...5] (ground)[.419][-..1](move)[none]
       (tile)[...7][...5] (ground)[.415][-..1](move)[none]
       (tile)[...8][...5] (move)[none]
       (tile)[...9][...5] (ground)[.3b7][.3b8]
       (tile)[..10][...5] (ground)[.3b9][.3ba]

       (tile)[...1][...6] (move)[none]
       (tile)[...2][...6] (move)[none]
       (tile)[...3][...6] (move)[none]
       (tile)[...4][...6] (move)[none]
       (tile)[...5][...6] (ground)[.418][-..1](move)[none]
       (tile)[...6][...6] (ground)[.414][-..1](move)[none]
       (tile)[...7][...6] (move)[none]
       (tile)[...8][...6] (move)[none]
       (tile)[...9][...6] (ground)[.3d1][.3d2]
       (tile)[..10][...6] (ground)[.3d3][.3d4]

       (tile)[...1][...7] (move)[none]
       (tile)[...2][...7] (move)[none]
       (tile)[...3][...7] (move)[none]
       (tile)[...4][...7] (move)[none]
       (tile)[...5][...7] (move)[none]
       (tile)[...6][...7] (move)[none]
       (tile)[...7][...7] (move)[none]
       (tile)[...8][...7] (move)[none]
       (tile)[...9][...7] (ground)[.3c9][.3ca] (move)[none]
       (tile)[..10][...7] (ground)[.3cb][.3cc]

       (tile)[...1][...8] (move)[none]
       (tile)[...2][...8] (move)[none]
       (tile)[...3][...8] (move)[none]
       (tile)[...4][...8] (move)[none]
       (tile)[...5][...8] (move)[none]
       (tile)[...6][...8] (move)[none]
       (tile)[...7][...8] (move)[none]
       (tile)[...8][...8] (move)[none]
       (tile)[...9][...8] (ground)[.3e5][.3e6] (move)[none]
       (tile)[..10][...8] (ground)[.3e7][.3e8]

       (tile)[...1][...9] (move)[none]
       (tile)[...2][...9] (move)[none]
       (tile)[...3][...9] (move)[none]
       (tile)[...4][...9] (move)[none]
       (tile)[...5][...9] (move)[none]
       (tile)[...6][...9] (move)[none]
       (tile)[...7][...9] (move)[none]
       (tile)[...8][...9] (move)[none]
       (tile)[...9][...9] (ground)[.3dc][.3dd]
       (tile)[..10][...9] (ground)[.3de][.3df]

       (tile)[...1][...2]
          (air)[.373][..00][..16]
          (air)[.372][..00][..80]
          (air)[.371][..00][.112]

       (tile)[...2][...2]
          (air)[.37b][..00][..16]
          (air)[.37a][..00][..48]
          (air)[.379][..00][..80]
          (air)[.378][..00][.112]
          (air)[.377][..00][.144]
          (air)[.376][..00][.176]

       (tile)[...3][...2]
          (air)[.385][..00][..16]
          (air)[.384][..00][..48]
          (air)[.383][..00][..80]
          (air)[.382][..00][.112]
          (air)[.431][..00][.128]
          (air)[.430][..00][.160]
          (air)[.42f][..00][.192]
          (air)[.42e][..00][.224]

       (tile)[...4][...2]
          (air)[.38b][..00][..16]
          (air)[.38a][..00][..48]
          (air)[.389][..00][..80]
          (air)[.388][..00][.112]
          (air)[.433][..00][.128]
          (air)[.432][..00][.144]
          (air)[.424][..00][.160]
          (air)[.422][..00][.192]
          (air)[.420][..00][.224]
          (air)[.41e][..00][.256]

       (tile)[...5][...2]
          (air)[.410][..00][..00]
          (air)[.40f][..00][..32]
          (air)[.40e][..00][..64]
          (air)[.40d][..00][..96]
          (air)[.40c][..00][.128]
          (air)[.434][..00][.144]
          (air)[.42b][..00][.160]
          (air)[.425][..00][.176]
          (air)[.423][..00][.208]
          (air)[.421][..00][.240]
          (air)[.41f][..00][.272]
          (air)[.41d][..00][.304]

          (air)[.411][..32][..00]
          (air)[.404][..32][..16]
          (air)[.402][..32][..48]
          (air)[.400][..32][..80]
          (air)[.3fe][..32][.112]
          (air)[.3fc][..32][.144]
          (air)[.42c][..32][.160]
          (air)[.42a][..32][.192]
          (air)[.429][..32][.224]
          (air)[.428][..32][.256]
          (air)[.427][..32][.288]
          (air)[.426][..32][.320]

       (tile)[...5][...3]
          (air)[.405][..32][..00]
          (air)[.403][..32][..32]
          (air)[.401][..32][..64]
          (air)[.3ff][..32][..96]
          (air)[.3fd][..32][.128]
          (air)[.44d][..32][.144]
          (air)[.44c][..32][.176]
          (air)[.44b][..32][.208]
          (air)[.44a][..32][.240]
          (air)[.449][..32][.272]
          (air)[.448][..32][.304]

       (tile)[...5][...4]
          (air)[.409][..32][..00]
          (air)[.408][..32][..32]
          (air)[.407][..32][..64]
          (air)[.406][..32][..96]
          (air)[.44f][..32][.112]
          (air)[.44e][..32][.128]
          (air)[.43f][..32][.144]
          (air)[.43d][..32][.176]
          (air)[.43b][..32][.208]
          (air)[.439][..32][.240]
          (air)[.437][..32][.272]
          (air)[.435][..32][.304]

       (tile)[...6][...4]
          (air)[.3ed][..32][..00]
          (air)[.3ec][..32][..32]
          (air)[.3eb][..32][..64]
          (air)[.3ea][..32][..96]
          (air)[.450][..32][.128]
          (air)[.3e9][..32][.128]
          (air)[.446][..32][.144]
          (air)[.440][..32][.160]
          (air)[.43e][..32][.192]
          (air)[.43c][..32][.224]
          (air)[.43a][..32][.256]
          (air)[.438][..32][.288]
          (air)[.436][..32][.320]

       (tile)[...7][...4]
          (air)[.3f5][..32][..00]
          (air)[.3f4][..32][..32]
          (air)[.3f3][..32][..64]
          (air)[.3f2][..32][..96]
          (air)[.3f1][..32][.128]
          (air)[.447][..32][.160]
          (air)[.3f0][..32][.160]
          (air)[.445][..32][.192]
          (air)[.444][..32][.224]
          (air)[.443][..32][.256]
          (air)[.442][..32][.288]
          (air)[.441][..32][.320]

       (tile)[...8][...4]
          (air)[.3c0][..32][..16]
          (air)[.3bf][..32][..48]
          (air)[.3be][..32][..80]
          (air)[.3bd][..32][.112]
          (air)[.3bc][..32][.144]
          (air)[.465][..32][.176]
          (air)[.3bb][..32][.176]
          (air)[.464][..32][.208]
          (air)[.463][..32][.240]
          (air)[.462][..32][.272]
          (air)[.461][..32][.304]
          (air)[.460][..32][.336]

       (tile)[...8][...5]
          (air)[.3b6][..32][..16]
          (air)[.3b5][..32][..48]
          (air)[.3b4][..32][..80]
          (air)[.3b3][..32][.112]
          (air)[.467][..32][.144]
          (air)[.3b2][..32][.144]
          (air)[.466][..32][.160]
          (air)[.459][..32][.176]
          (air)[.457][..32][.208]
          (air)[.455][..32][.240]
          (air)[.453][..32][.272]
          (air)[.451][..32][.304]

       (tile)[...8][...6]
          (air)[.3d0][..32][..16]
          (air)[.3cf][..32][..48]
          (air)[.3ce][..32][..80]
          (air)[.3cd][..32][.112]
          (air)[.468][..32][.128]
          (air)[.45e][..32][.144]
          (air)[.45a][..32][.160]
          (air)[.458][..32][.192]
          (air)[.456][..32][.224]
          (air)[.454][..32][.256]
          (air)[.452][..32][.288]

       (tile)[...8][...7]
          (air)[.3c8][..32][..16]
          (air)[.3c7][..32][..48]
          (air)[.3c6][..32][..80]
          (air)[.3c5][..32][.112]
          (air)[.45f][..32][.128]
          (air)[.45d][..32][.160]
          (air)[.45c][..32][.192]
          (air)[.45b][..32][.224]

       (tile)[...8][...8]
          (air)[.3e4][..32][..16]
          (air)[.3e3][..32][..48]
          (air)[.3e2][..32][..80]
          (air)[.3e1][..32][.112]
          (air)[.3e0][..32][.144]

       (tile)[...8][...9]

          (air)[.3db][..64][..16]
          (air)[.3d9][..64][..48]
          (air)[.3d7][..64][..80]

          (air)[.3da][..32][..16]
          (air)[.3d8][..32][..48]
          (air)[.3d6][..32][..80]
          (air)[.3d5][..32][.112]

  (sector_end)

   //sector reserved due to mistake
    (sector)[..81] 
    (sector_end)

   //healers house
    (sector)[..82]  (texg)[...0]
        (tile)[...0][...0] (ground)[.5b3][.5b4]
        (tile)[...1][...0] (ground)[.5a9][.5aa]
        (tile)[...2][...0] (ground)[.5ab][.5ac]
        (tile)[...3][...0] (ground)[.56d][.56e]
        (tile)[...4][...0] (ground)[.56f][.570]
        (tile)[...5][...0] (ground)[.535][.536]
        (tile)[...6][...0] (ground)[.537][.538]
        (tile)[...7][...0] (ground)[.52c][.52d]
        (tile)[...8][...0] (ground)[.52e][.52f]
        (tile)[...9][...0] (ground)[.513][.514]
        (tile)[..10][...0] (ground)[.515][.516]

        (tile)[...0][...1] (ground)[.5af][.5b0]
        (tile)[...1][...1] (ground)[.5a1][..01](move)[none]
        (tile)[...2][...1] (move)[none]
        (tile)[...3][...1] (move)[none]
        (tile)[...4][...1] (move)[none]
        (tile)[...5][...1] (move)[none]
        (tile)[...6][...1] (move)[none]
        (tile)[...7][...1] (move)[none]
        (tile)[...8][...1] (ground)[.52a][.52b]
        (tile)[...9][...1] (ground)[.50f][.510]
        (tile)[..10][...1] (ground)[.511][.512]

        (tile)[...0][...2] (ground)[.5b8][..01]
        (tile)[...1][...2] (move)[none]
        (tile)[...2][...2] (move)[none]
        (tile)[...3][...2] (move)[none]
        (tile)[...4][...2] (move)[none]
        (tile)[...5][...2] (move)[none]
        (tile)[...6][...2] (ground)[-..1][.5bc] (move)[none]
        (tile)[...7][...2] (ground)[.53d][.53e] (move)[none]
        (tile)[...8][...2] (ground)[.53f][.540]
        (tile)[...9][...2] (ground)[.51b][.51c]
        (tile)[..10][...2] (ground)[.51d][.51e]

        (tile)[...1][...3] (move)[none]
        (tile)[...2][...3] (move)[none]
        (tile)[...3][...3] (move)[none]
        (tile)[...4][...3] (move)[none]
        (tile)[...5][...3] (move)[none]
        (tile)[...6][...3] (ground)[.5ba][.5bb] (move)[none]
        (tile)[...7][...3] (ground)[.539][-..1] (move)[none]
        (tile)[...8][...3] (ground)[.53b][.53c] (move)[none]
        (tile)[...9][...3] (ground)[.517][.518]
        (tile)[..10][...3] (ground)[.519][.51a]

        (tile)[...1][...4] (move)[none]
        (tile)[...2][...4] (move)[none]
        (tile)[...3][...4] (move)[none]
        (tile)[...4][...4] (move)[none]
        (tile)[...5][...4] (ground)[-..1][.5b9] (move)[none]
        (tile)[...6][...4] (ground)[-..1][..01](move)[none]
        (tile)[...7][...4] (move)[none]
        (tile)[...8][...4] (ground)[.57b][.57c] (move)[none]

        (tile)[...1][...5] (move)[none]
        (tile)[...2][...5] (move)[none]
        (tile)[...3][...5] (move)[none]
        (tile)[...4][...5] (move)[none]
        (tile)[...5][...5] (move)[none]
        (tile)[...6][...5] (move)[none]
        (tile)[...7][...5] (move)[none]
        (tile)[...8][...5] (ground)[.575][.576]

        (tile)[...1][...6] (move)[none]
        (tile)[...2][...6] (move)[none]
        (tile)[...3][...6] (move)[none]
        (tile)[...4][...6] (move)[none]
        (tile)[...5][...6] (move)[none]
        (tile)[...6][...6] (move)[none]
        (tile)[...7][...6] (move)[none]
        (tile)[...8][...6] (ground)[.58e][.58f]

        (tile)[...1][...7] (move)[none]
        (tile)[...2][...7] (move)[none]
        (tile)[...3][...7] (move)[none]
        (tile)[...4][...7] (move)[none]
        (tile)[...5][...7] (move)[none]
        (tile)[...6][...7] (move)[none]
        (tile)[...7][...7] (ground)[..00][.584] (move)[none]
        (tile)[...8][...7] (ground)[.585][.586]

       (tile)[...1][...1]
          (air)[.59f][..00][..32]
          (air)[.59d][..00][..64]
          (air)[.59b][..00][..96]

       (tile)[...2][...1]
          (air)[.5a7][..00][..00]
          (air)[.5a2][..00][..16]
          (air)[.5a0][..00][..48]
          (air)[.59e][..00][..80]
          (air)[.59c][..00][.112]

       (tile)[...3][...1]
          (air)[.563][..00][..00]
          (air)[.5a8][..00][..16]
          (air)[.5a6][..00][..48]
          (air)[.5a5][..00][..80]
          (air)[.5a4][..00][.112]
          (air)[.5a3][..00][.144]

       (tile)[...4][...1]
          (air)[.56b][..00][..00]
          (air)[.564][..00][..16]
          (air)[.562][..00][..48]
          (air)[.561][..00][..80]
          (air)[.560][..00][.112]
          (air)[.55f][..00][.144]
          (air)[.55e][..00][.176]

       (tile)[...5][...1]
          (air)[.532][..00][..00]
          (air)[.56c][..00][..16]
          (air)[.56a][..00][..48]
          (air)[.569][..00][..80]
          (air)[.568][..00][.112]
          (air)[.567][..00][.144]
          (air)[.566][..00][.176]
          (air)[.565][..00][.208]

       (tile)[...6][...1]
          (air)[.534][..00][..00]
          (air)[.533][..00][..16]
          (air)[.531][..00][..48]
          (air)[.530][..00][..80]
          (air)[.55a][..00][..96]
          (air)[.559][..00][.128]
          (air)[.558][..00][.160]
          (air)[.557][..00][.192]
          (air)[.556][..00][.224]
          (air)[.555][..00][.256]

       (tile)[...7][...1]
          (air)[.525][..00][..00]
          (air)[.523][..00][..32]
          (air)[.521][..00][..64]
          (air)[.55c][..00][..96]
          (air)[.51f][..00][..96]
          (air)[.55b][..00][.112]
          (air)[.54b][..00][.128]
          (air)[.549][..00][.160]
          (air)[.547][..00][.192]
          (air)[.545][..00][.224]
          (air)[.543][..00][.256]
          (air)[.541][..00][.288]

          (air)[.526][..32][..00]
          (air)[.524][..32][..32]
          (air)[.522][..32][..64]
          (air)[.55d][..32][..96]
          (air)[.520][..32][..96]
          (air)[.553][..32][.112]
          (air)[.54c][..32][.128]
          (air)[.54a][..32][.160]
          (air)[.548][..32][.192]
          (air)[.546][..32][.224]
          (air)[.544][..32][.256]
          (air)[.542][..32][.288]

       (tile)[...7][...2]
          (air)[.529][..32][..32]
          (air)[.528][..32][..64]
          (air)[.554][..32][..96]
          (air)[.527][..32][..96]
          (air)[.552][..32][.128]
          (air)[.551][..32][.160]
          (air)[.550][..32][.192]
          (air)[.54f][..32][.224]
          (air)[.54e][..32][.256]
          (air)[.54d][..32][.288]

       (tile)[...7][...3]
          (air)[.53a][..32][..00]
          (air)[.579][..32][..16]
          (air)[.578][..32][..48]
          (air)[.577][..32][..80]
          (air)[.59a][..32][..80]
          (air)[.599][..32][.112]
          (air)[.598][..32][.144]
          (air)[.597][..32][.176]
          (air)[.596][..32][.208]
          (air)[.595][..32][.240]

       (tile)[...7][...4]
          (air)[.57a][..32][..00]
          (air)[.573][..32][..16]
          (air)[.572][..32][..48]
          (air)[.571][..32][..80]
          (air)[.594][..32][..80]
          (air)[.593][..32][.112]
          (air)[.592][..32][.144]
          (air)[.591][..32][.176]
          (air)[.590][..32][.208]

       (tile)[...7][...5]
          (air)[.574][..32][..00]
          (air)[.58c][..32][..16]
          (air)[.58b][..32][..48]
          (air)[.58a][..32][..80]
          (air)[.589][..32][.112]
          (air)[.588][..32][.144]
          (air)[.587][..32][.176]

       (tile)[...7][...6]
          (air)[.58d][..32][..00]
          (air)[.583][..32][..16]
          (air)[.581][..32][..48]
          (air)[.57f][..32][..80]
          (air)[.57d][..32][.112]

       (tile)[...7][...7]
          (air)[.582][..32][..32]
          (air)[.580][..32][..64]
          (air)[.57e][..32][..96]
     (sector_end)

     //cooking pot
     (sector)[..83]  (texg)[...0]
        (tile)[...0][...0] (ground)[.5c4][.5c5]
        (tile)[...1][...0] (ground)[.5c6][.5c7]
        (tile)[...2][...0] (ground)[.5cf][.5d0]
        (tile)[...3][...0] (ground)[.5d5][.5d6]
        (tile)[...0][...1] (ground)[.5bf][.5c0](move)[none]
        (tile)[...1][...1] (ground)[.5c2][.5c3](move)[none]
        (tile)[...2][...1] (ground)[.5cd][.5ce](move)[none]
        (tile)[...3][...1] (ground)[.5d3][.5d4]
        (tile)[...0][...2] (move)[none]
        (tile)[...1][...2] (ground)[.068][.069]
        (tile)[...2][...2] (ground)[.06a][.06b]
        (tile)[...3][...2] (ground)[.030][.031]

        (tile)[...1][...1]  
          (air)[.5d2][..00][..00]
          (air)[.5d1][..00][..32]
          (air)[.5be][..00][..48]
          (air)[.5bd][..00][..80]

        (tile)[...2][...1]
          (air)[.5cb][..00][..32]
          (air)[.5c9][..00][..64]
          (air)[.5c1][..00][..80]
          (air)[.5cc][..32][..32]
          (air)[.5ca][..32][..64]
     (sector_end)

     //witches house
     (sector)[..84]  (texg)[...0]
        (tile)[...1][...0] (ground)[.614][.615]
        (tile)[...2][...0] (ground)[.616][.617]

        (tile)[...0][...1] (ground)[.62a][.62b]
        (tile)[...1][...1] (ground)[.630][.631]
        (tile)[...2][...1] (ground)[.632][.633]
        (tile)[...3][...1] (ground)[.638][.639]
        (tile)[...4][...1] (ground)[.63a][.63b]

        (tile)[...0][...2] (ground)[.626][.627]
        (tile)[...1][...2] (ground)[.62c][.62d]
        (tile)[...2][...2] (ground)[.62e][.62f]
        (tile)[...3][...2] (ground)[.634][.635]

        (tile)[...0][...3] (ground)[.652][.653]
        (tile)[...1][...3] (ground)[.66b][.66c](move)[none]
        (tile)[...2][...3] (ground)[.66d][.66e](move)[none]
        (tile)[...3][...3] (ground)[.67f][.680](move)[none]
        (tile)[...4][...3] (ground)[.681][.682](move)[none]
        (tile)[...5][...3] (ground)[.648][.649]
        (tile)[...6][...3] (ground)[.64a][.64b]

        (tile)[...0][...4] (ground)[.64e][.64f](move)[none]
        (tile)[...1][...4] (ground)[.660][.661](move)[none]
        (tile)[...2][...4] (ground)[.668][.669](move)[none]
        (tile)[...3][...4] (ground)[.675][.676](move)[none]
        (tile)[...4][...4] (ground)[.67d][.67e](move)[none]
        (tile)[...5][...4] (ground)[.644][.645](move)[none]
        (tile)[...6][...4] (ground)[.646][.647]

        (tile)[...0][...5] (move)[none]
        (tile)[...1][...5] (move)[none]
        (tile)[...2][...5] (move)[none]
        (tile)[...3][...5] (move)[none]
        (tile)[...4][...5] (move)[none]
        (tile)[...5][...5] (ground)[.692][.693](move)[none]
        (tile)[...6][...5] (ground)[.694][.695]

        (tile)[...0][...6] (move)[none]
        (tile)[...1][...6] (move)[none]
        (tile)[...2][...6] (move)[none]
        (tile)[...3][...6] (move)[none]
        (tile)[...4][...6] (move)[none]
        (tile)[...5][...6] (ground)[.688][.689](move)[none]
        (tile)[...6][...6] (ground)[.68a][.68b]

        (tile)[...0][...7] (move)[none]
        (tile)[...1][...7] (move)[none]
        (tile)[...2][...7] (move)[none]
        (tile)[...3][...7] (move)[none]
        (tile)[...4][...7] (move)[none]
        (tile)[...5][...7] (ground)[.6a3][.6a4](move)[none]
        (tile)[...6][...7] (ground)[.6a5][.6a6]

        (tile)[...0][...8] (move)[none]
        (tile)[...1][...8] (move)[none]
        (tile)[...2][...8] (move)[none]
        (tile)[...3][...8] (move)[none]
        (tile)[...4][...8] (move)[none]
        (tile)[...5][...8] (ground)[.69b][.69c](move)[none]
        (tile)[...6][...8] (ground)[.69d][.69e]

        (tile)[...1][...4]  
          (air)[.66a][-.32][..16]
          (air)[.65e][..00][..32]
          (air)[.65c][..00][..64]
          (air)[.65a][..00][..96]
          (air)[.658][..00][.129]

        (tile)[...2][...4]  
          (air)[.65f][..00][..48]
          (air)[.65d][..00][..80]
          (air)[.65b][..00][.112]
          (air)[.659][..00][.144]

        (tile)[...3][...4]  
          (air)[.667][..00][..48]
          (air)[.666][..00][..80]
          (air)[.665][..00][.112]
          (air)[.664][..00][.144]
          (air)[.663][..00][.176]
          (air)[.662][..00][.208]

        (tile)[...4][...4]  
          (air)[.674][..00][..48]
          (air)[.673][..00][..80]
          (air)[.672][..00][.112]
          (air)[.671][..00][.144]
          (air)[.670][..00][.176]
          (air)[.66f][..00][.208]

        (tile)[...5][...4]  
          (air)[.67c][..00][..48]
          (air)[.67b][..00][..80]
          (air)[.67a][..00][.112]
          (air)[.679][..00][.144]
          (air)[.678][..00][.176]
          (air)[.677][..00][.208]

          (air)[.691][..32][..48]
          (air)[.690][..32][..80]
          (air)[.68f][..32][.112]
          (air)[.68e][..32][.144]
          (air)[.68d][..32][.176]
          (air)[.68c][..32][.208]

        (tile)[...5][...5]  
          (air)[.687][..32][..48]
          (air)[.686][..32][..80]
          (air)[.685][..32][.112]
          (air)[.684][..32][.144]
          (air)[.683][..32][.176]

        (tile)[...5][...6]  
          (air)[.6a2][..32][..48]
          (air)[.6a1][..32][..80]
          (air)[.6a0][..32][.112]
          (air)[.69f][..32][.144]

        (tile)[...5][...7]  
          (air)[.699][..32][..48]
          (air)[.697][..32][..80]
          (air)[.696][..32][.112]

        (tile)[...5][...8]  
          (air)[.69a][..32][..32]
          (air)[.698][..32][..64]
     (sector_end)

   //sector reserved due to mistake
    (sector)[..85]  
    (sector_end)

   //catcombs entrance default open
    (sector)[..86]  (texg)[...0]
        (tile)[...0][...0] (ground)[.d1e][.d1f]
        (tile)[...1][...0] (ground)[.d20][.d21]
        (tile)[...2][...0] (ground)[.d26][.d27]
        (tile)[...3][...0] (ground)[.d28][.d29]
        (tile)[...4][...0] (ground)[.d2c][.d2d]

        (tile)[...0][...1] (ground)[.d31][.d32]
        (tile)[...1][...1] (ground)[.d33][.d34](move)[none]
        (tile)[...2][...1] (ground)[.ceb][.cf5](move)[none]
        (tile)[...3][...1] (ground)[.cf6][.cf7](move)[none]
        (tile)[...4][...1] (ground)[.d06][.d07](move)[none]
        (tile)[...5][...1] (ground)[.d08][.d09]

        (tile)[...0][...2] (ground)[.d2e][.d2f](move)[none]
        (tile)[...1][...2] (ground)[.d30][-..1](move)[none]
        (tile)[...2][...2] (ground)[.cf2][.cf3](move)[none]
        (tile)[...3][...2] (ground)[.cf4][-..1](move)[none]
        (tile)[...4][...2] (ground)[.cfd][.cfe](move)[none]
        (tile)[...5][...2] (ground)[.cff][.d00]

        (tile)[...0][...3] (move)[none]
        (tile)[...1][...3] (ground)[.cf0][.cf1](move)[none]
        (tile)[...2][...3] (ground)[-..1][-..1](move)[none]
        (tile)[...3][...3] (move)[none]
        (tile)[...4][...3] (ground)[.d1a][.d1b](move)[none]
        (tile)[...5][...3] (ground)[.d1c][.d1d]

        (tile)[...1][...4] (move)[none]
        (tile)[...2][...4] (move)[none]
        (tile)[...3][...4] (move)[none]
        (tile)[...4][...4] (ground)[.d11][.d12](move)[none]
        (tile)[...5][...4] (ground)[.d13][.d14]

       (tile)[...2][...1]
          (air)[.cea][..00][..32]
          (air)[.ce9][..00][..64]
          (air)[.ce8][..00][..96]

       (tile)[...3][...1]
          (air)[.ce1][..00][..96]
          (air)[.ce0][..00][.128]

          (air)[.d05][..32][..16]
          (air)[.d04][..32][..48]
          (air)[.d03][..32][..80]
          (air)[.d02][..32][.112]
          (air)[.d01][..32][.144]

       (tile)[...3][...2]
          (air)[.cfc][..32][..16]
          (air)[.cfb][..32][..48]
          (air)[.cfa][..32][..80]
          (air)[.cf9][..32][.112]
          (air)[.cf8][..32][.144]

       (tile)[...3][...3]
          (air)[.d19][..32][..16]
          (air)[.d18][..32][..48]
          (air)[.d17][..32][..80]
          (air)[.d16][..32][.112]
          (air)[.d15][..32][.144]

       (tile)[...3][...4]
          (air)[.d0f][..32][..16]
          (air)[.d0d][..32][..48]
          (air)[.d0b][..32][..80]
          (air)[.d0a][..32][.112]

       (tile)[...3][...5]
          (air)[.d10][..32][..00]
          (air)[.d0e][..32][..32]
          (air)[.d0c][..32][..64]
  (sector_end)


   //catcombs entrance open
   (sector)[..87]  (texg)[...0]
        (tile)[...2][...1] (ground)[.ceb][.cf5]
        (tile)[...3][...1] (ground)[.cf6][.cf7]

        (tile)[...2][...2] (ground)[.cf2][.cf3]
        (tile)[...3][...2] (ground)[.cf4][-..1]

        (tile)[...1][...3] (ground)[.cf0][.cf1]
       
        (tile)[...3][...0] (mech)[..69][+] //warp to lev5
        (tile)[...4][...0] (mech)[..69][+] //warp to lev5

  (sector_end)

   //catcombs entrance close
   (sector)[..88]  (texg)[...0]
        (tile)[...2][...1] (ground)[.ceb][.cec]
        (tile)[...3][...1] (ground)[.ced][.cee]

        (tile)[...2][...2] (ground)[.ce4][.ce5]
        (tile)[...3][...2] (ground)[.ce6][-..1]

        (tile)[...1][...3] (ground)[.ce2][.ce3]
  (sector_end)

   //south-north streching house: south part
   (sector)[..89]  (texg)[...0]
        (tile)[...0][...0] (ground)[.9bd][.9be]
        (tile)[...1][...0] (ground)[.9b3][.9b4]
        (tile)[...2][...0] (ground)[.9b5][.9b6]

        (tile)[...0][...1] (ground)[.9c9][.9ca]
        (tile)[...1][...1] (ground)[.9af][.9b0]
        (tile)[...2][...1] (ground)[.9b1][.9b2]
        (tile)[...3][...1] (ground)[.99d][.99e]
        (tile)[...4][...1] (ground)[.99f][.9a0]

        (tile)[...0][...2] (ground)[.9c5][.9c6]
        (tile)[...1][...2] (ground)[.9a6][.9a7](move)[none]
        (tile)[...2][...2] (ground)[.9ad][.9ae](move)[none]
        (tile)[...3][...2] (ground)[.993][.994](move)[none]
        (tile)[...4][...2] (ground)[.99b][.99c](move)[none]
        (tile)[...5][...2] (ground)[.970][.971]

       (tile)[...1][...2]
          (air)[.9a4][..00][..32]
          (air)[.9a2][..00][..64]

       (tile)[...2][...2]
          (air)[.9a5][..00][..48]
          (air)[.9a3][..00][..80]
          (air)[.9a1][..00][.112]

       (tile)[...3][...2]
          (air)[.9ac][..00][..48]
          (air)[.9ab][..00][..80]
          (air)[.9aa][..00][.112]
          (air)[.9a9][..00][.144]

       (tile)[...4][...2]
          (air)[.992][..00][..48]
          (air)[.991][..00][..80]
          (air)[.990][..00][.112]
          (air)[.98f][..00][.144]
          (air)[.98e][..00][.176]

          (air)[.99a][..32][..32]
          (air)[.999][..32][..64]
          (air)[.998][..32][..96]
          (air)[.997][..32][.128]
          (air)[.996][..32][.160]
          (air)[.995][..32][.192]
  (sector_end)

   //south-north streching house: middle part
   (sector)[..90]  (texg)[...0]
        (tile)[...1][...3] (move)[none]
        (tile)[...2][...3] (move)[none]
        (tile)[...3][...3] (move)[none]
        (tile)[...4][...3] (move)[none]
        (tile)[...5][...3] (ground)[.98a][.98b]

        (tile)[...1][...4] (move)[none]
        (tile)[...2][...4] (move)[none]
        (tile)[...3][...4] (move)[none]
        (tile)[...4][...4] (move)[none]
        (tile)[...5][...4] (ground)[.98a][.98b]

       (tile)[...5][...3]
          (air)[.989][..00][..32]
          (air)[.988][..00][..64]
          (air)[.987][..00][..96]
          (air)[.986][..00][.128]
          (air)[.985][..00][.160]
          (air)[.984][..00][.192]
          (air)[.983][..00][.224]

       (tile)[...5][...4]
          (air)[.97e][..00][..32]
          (air)[.97d][..00][..64]
          (air)[.97c][..00][..96]
          (air)[.97b][..00][.128]
          (air)[.97a][..00][.160]
          (air)[.979][..00][.192]
          (air)[.978][..00][.224]
  (sector_end)

   //south-north streching house: north part
   (sector)[..91]  (texg)[...0]
        (tile)[...1][...3] (move)[none]
        (tile)[...2][...3] (move)[none]
        (tile)[...3][...3] (move)[none]
        (tile)[...4][...3] (move)[none]
        (tile)[...5][...3] (ground)[.96c][.96d](move)[none]

        (tile)[...1][...4] (move)[none]
        (tile)[...2][...4] (move)[none]
        (tile)[...3][...4] (move)[none]
        (tile)[...4][...4] (move)[none]
        (tile)[...5][...4] (ground)[.961][.962]
        (tile)[...6][...4] (ground)[.963][.964]

        (tile)[...1][...5] (move)[none]
        (tile)[...2][...5] (move)[none]
        (tile)[...3][...5] (move)[none]
        (tile)[...4][...5] (move)[none]
        (tile)[...5][...5] (ground)[.956][.957]
        (tile)[...6][...5] (ground)[.958][.959]

        (tile)[...1][...6] (move)[none]
        (tile)[...2][...6] (move)[none]
        (tile)[...3][...6] (move)[none]
        (tile)[...4][...6] (move)[none]
        (tile)[...5][...6] (ground)[.94c][.94d]

       (tile)[...5][...3]
          (air)[.96b][..00][..32]
          (air)[.96a][..00][..64]
          (air)[.969][..00][..96]
          (air)[.968][..00][.128]
          (air)[.967][..00][.160]
          (air)[.966][..00][.192]
          (air)[.965][..00][.224]

       (tile)[...5][...4]
          (air)[.960][..00][..32]
          (air)[.95f][..00][..64]
          (air)[.95e][..00][..96]
          (air)[.95d][..00][.128]
          (air)[.95c][..00][.160]
          (air)[.95b][..00][.192]
          (air)[.95a][..00][.224]

       (tile)[...5][...5]
          (air)[.955][..00][..32]
          (air)[.954][..00][..64]
          (air)[.953][..00][..96]
          (air)[.952][..00][.128]
          (air)[.951][..00][.160]
          (air)[.950][..00][.192]

       (tile)[...5][...6]
          (air)[.94b][..00][..32]
          (air)[.94a][..00][..64]
          (air)[.949][..00][..96]
  (sector_end)

   //south-north streching house: small assembly
   (sector)[..92]
     (recursec)[..89][..00][..00]
     (recursec)[..91][..00][..00]
  (sector_end)

   //south-north streching house: big assembly
   (sector)[..93]
     (recursec)[..89][..00][..00]
     (recursec)[..90][..00][..00]
     (recursec)[..91][..00][..02]
   (sector_end)

   //smiths house
   (sector)[..94]  (texg)[...0]
        (tile)[...0][...0](ground)[.9f7][.9f8]
        (tile)[...1][...0](ground)[.9f9][.9fa]
        (tile)[...2][...0](ground)[.a04][.a05]
        (tile)[...3][...0](ground)[.a06][.a07]
        (tile)[...4][...0](ground)[.a0c][.a0d]
        (tile)[...5][...0](ground)[.a0e][.a0f]

        (tile)[...0][...1](ground)[.9f3][.9f4]
        (tile)[...1][...1](ground)[.9f5][.9f6]
        (tile)[...2][...1](ground)[.9fd][.9fe]
        (tile)[...3][...1](ground)[.a02][.a03]
        (tile)[...4][...1](ground)[.a08][.a09]
        (tile)[...5][...1](ground)[.a0a][.a0b]

        (tile)[...0][...2](ground)[.a57][.a58](move)[none]
        (tile)[...1][...2](ground)[.a59][.a5a](move)[none]
        (tile)[...2][...2](ground)[.a2b][.a2c](move)[none]
        (tile)[...3][...2](ground)[.a2d][.a2e](move)[none]
        (tile)[...4][...2](ground)[.a23][.a24](move)[none]
        (tile)[...5][...2](ground)[.a25][.a26]

        (tile)[...0][...3](ground)[.a4e][.a4f](move)[none]
        (tile)[...1][...3](ground)[.a54][.a55](move)[none]
        (tile)[...2][...3](ground)[.a27][.a28](move)[none]
        (tile)[...3][...3](ground)[.a29][.a2a](move)[none]
        (tile)[...4][...3](ground)[.a18][.a19](move)[none]
        (tile)[...5][...3](ground)[.a1d][.a1e]

        (tile)[...0][...4](ground)[-001][.a53](move)[none]
        (tile)[...1][...4](ground)[-001][-001](move)[none]
        (tile)[...2][...4](move)[none]
        (tile)[...3][...4](ground)[.a47][.a48](move)[none]
        (tile)[...4][...4](ground)[.ac7][.ac8](move)[none]
        (tile)[...5][...4](ground)[.ac9][.aca]
        (tile)[...6][...4](ground)[.aaf][.ab0]
        (tile)[...7][...4](ground)[.ab1][.ab2]
        (tile)[...8][...4](ground)[.a99][.a9a]
        (tile)[...9][...4](ground)[.a9b][.a9c]
        (tile)[..10][...4](ground)[.a5f][.a60]

        (tile)[...0][...5](move)[none]
        (tile)[...1][...5](move)[none]
        (tile)[...2][...5](move)[none]
        (tile)[...3][...5](ground)[.a41][.a42](move)[none]
        (tile)[...4][...5](ground)[.abb][.abc](move)[none]
        (tile)[...5][...5](ground)[.ac4][.ac5](move)[none]
        (tile)[...6][...5](ground)[.aad][.aae](move)[none]
        (tile)[...7][...5](ground)[.aa4][.aa5](move)[none]
        (tile)[...8][...5](ground)[.a97][.a98](move)[none]
        (tile)[...9][...5](ground)[.a8e][.a8f](move)[none]
        (tile)[..10][...5](ground)[.a5b][.a5c](move)[none]
        (tile)[..11][...5](ground)[.a5d][.a5e](move)[none]

        (tile)[...0][...6](move)[none]
        (tile)[...1][...6](move)[none]
        (tile)[...2][...6](move)[none]
        (tile)[...3][...6](move)[none]
        (tile)[...4][...6](move)[none]
        (tile)[...5][...6](move)[none]
        (tile)[...6][...6](move)[none]
        (tile)[...7][...6](move)[none]
        (tile)[...8][...6](move)[none]
        (tile)[...9][...6](move)[none]
        (tile)[..10][...6](ground)[.a72][.a73](move)[none]
        (tile)[..11][...6](ground)[.a74][.a75](move)[none]

        (tile)[...0][...7](move)[none]
        (tile)[...1][...7](move)[none]
        (tile)[...2][...7](move)[none]
        (tile)[...3][...7](move)[none]
        (tile)[...4][...7](move)[none]
        (tile)[...5][...7](move)[none]
        (tile)[...6][...7](move)[none]
        (tile)[...7][...7](move)[none]
        (tile)[...8][...7](move)[none]
        (tile)[...9][...7](move)[none]
        (tile)[..10][...7](ground)[.a68][.a69](move)[none]
        (tile)[..11][...7](ground)[.a6a][.a6b](move)[none]

        (tile)[...0][...8](move)[none]
        (tile)[...1][...8](move)[none]
        (tile)[...2][...8](move)[none]
        (tile)[...3][...8](move)[none]
        (tile)[...4][...8](move)[none]
        (tile)[...5][...8](move)[none]
        (tile)[...6][...8](move)[none]
        (tile)[...7][...8](move)[none]
        (tile)[...8][...8](move)[none]
        (tile)[...9][...8](move)[none]
        (tile)[..10][...8](ground)[.a83][.a84](move)[none]
        (tile)[..11][...8](ground)[.a85][.a86](move)[none]

        (tile)[...0][...9](move)[none]
        (tile)[...1][...9](move)[none]
        (tile)[...2][...9](move)[none]
        (tile)[...3][...9](move)[none]
        (tile)[...4][...9](move)[none]
        (tile)[...5][...9](move)[none]
        (tile)[...6][...9](move)[none]
        (tile)[...7][...9](move)[none]
        (tile)[...8][...9](move)[none]
        (tile)[...9][...9](move)[none]
        (tile)[..10][...9](ground)[.a7b][.a7c](move)[none]
        (tile)[..11][...9](ground)[.a7d][.a7e](move)[none]

       (tile)[...0][...2]
          (air)[.a56][..00][..32]

       (tile)[...1][...2]
          (air)[.a4c][..00][..64]
          (air)[.a4a][..00][..96]

       (tile)[...2][...2]
          (air)[.9fc][..00][..80]
          (air)[.a4d][..00][..80]
          (air)[.9fb][..00][.112]
          (air)[.a4b][..00][.112]
          (air)[.a49][..00][.144]

       (tile)[...3][...2]
          (air)[.a01][..00][..48]
          (air)[.a00][..00][..80]
          (air)[.9ff][..00][.112]
          (air)[.a52][..00][.112]
          (air)[.a51][..00][.144]
          (air)[.a50][..00][.176]

       (tile)[...3][...3]
          (air)[.a22][..00][..00]
          (air)[.a21][..00][..32]
          (air)[.a20][..00][..64]
          (air)[.a1f][..00][..96]
          (air)[.a46][..00][..96]
          (air)[.a45][..00][.128]
          (air)[.a44][..00][.160]
          (air)[.a43][..00][.192]

       (tile)[...3][...4]
          (air)[.a16][..00][..00]
          (air)[.a14][..00][..32]
          (air)[.a12][..00][..64]
          (air)[.a10][..00][..96]
          (air)[.a39][..00][..96]
          (air)[.a37][..00][.128]
          (air)[.a35][..00][.160]
          (air)[.a33][..00][.192]
          (air)[.a31][..00][.224]
          (air)[.a2f][..00][.256]

       (tile)[...4][...4]
          (air)[.a17][..00][..16]
          (air)[.a15][..00][..48]
          (air)[.a13][..00][..80]
          (air)[.a11][..00][.112]
          (air)[.a3a][..00][.112]
          (air)[.a38][..00][.144]
          (air)[.a36][..00][.176]
          (air)[.a34][..00][.208]
          (air)[.a32][..00][.240]
          (air)[.a30][..00][.272]

       (tile)[...4][...5]
          (air)[.a1c][..00][..16]
          (air)[.ab9][..00][..32]
          (air)[.a1b][..00][..48]
          (air)[.a1a][..00][..80]
          (air)[.a40][..00][..80]
          (air)[.a3f][..00][.112]
          (air)[.a3e][..00][.144]
          (air)[.a3d][..00][.176]
          (air)[.a3c][..00][.208]
          (air)[.a3b][..00][.240]

       (tile)[...5][...5]
          (air)[.aba][..00][..48]
          (air)[.ab8][..00][..80]
          (air)[.ab7][..00][.112]
          (air)[.ab6][..00][.144]
          (air)[.ab5][..00][.176]
          (air)[.ab4][..00][.208]
          (air)[.ab3][..00][.240]

       (tile)[...6][...5]
          (air)[.ac3][..00][..48]
          (air)[.ac2][..00][..80]
          (air)[.ac1][..00][.112]
          (air)[.ac0][..00][.144]
          (air)[.abf][..00][.176]
          (air)[.abe][..00][.208]
          (air)[.abd][..00][.240]

       (tile)[...7][...5]
          (air)[.aac][..00][..48]
          (air)[.aab][..00][..80]
          (air)[.aaa][..00][.112]
          (air)[.aa9][..00][.144]
          (air)[.aa8][..00][.176]
          (air)[.aa7][..00][.208]
          (air)[.aa6][..00][.240]

       (tile)[...8][...5]
          (air)[.aa3][..00][..48]
          (air)[.aa2][..00][..80]
          (air)[.aa1][..00][.112]
          (air)[.aa0][..00][.144]
          (air)[.a9f][..00][.176]
          (air)[.a9e][..00][.208]
          (air)[.a9d][..00][.240]

       (tile)[...9][...5]
          (air)[.a96][..00][..48]
          (air)[.a95][..00][..80]
          (air)[.a94][..00][.112]
          (air)[.a93][..00][.144]
          (air)[.a92][..00][.176]
          (air)[.a91][..00][.208]

       (tile)[..10][...5]
          (air)[.a8d][..00][..48]
          (air)[.a8c][..00][..80]
          (air)[.a8b][..00][.112]
          (air)[.a8a][..00][.144]
          (air)[.a89][..00][.176]
          (air)[.a88][..00][.208]

          (air)[.a71][..32][..48]
          (air)[.a70][..32][..80]
          (air)[.a6f][..32][.112]
          (air)[.a6e][..32][.144]
          (air)[.a6d][..32][.176]
          (air)[.a6c][..32][.208]

       (tile)[..10][...6]
          (air)[.a67][..32][..48]
          (air)[.a66][..32][..80]
          (air)[.a65][..32][.112]
          (air)[.a64][..32][.144]
          (air)[.a63][..32][.176]

       (tile)[..10][...7]
          (air)[.a82][..32][..48]
          (air)[.a81][..32][..80]
          (air)[.a80][..32][.112]
          (air)[.a7f][..32][.144]

       (tile)[..10][...8]
          (air)[.a79][..32][..48]
          (air)[.a77][..32][..80]
          (air)[.a76][..32][.112]

       (tile)[..10][...9]
          (air)[.a7a][..32][..32]
          (air)[.a78][..32][..64]
   (sector_end)

   //east-west steching house, back end
    (sector)[..95]  (texg)[...0]
        (tile)[...3][...0] (ground)[.4b1][.4b2]
        (tile)[...4][...0] (ground)[.4b3][.4b4]
        (tile)[...5][...0] (ground)[.4bd][.4be]
        (tile)[...6][...0] (ground)[.4bf][.4c0]

        (tile)[...0][...1] (ground)[.473][.474]
        (tile)[...1][...1] (ground)[.489][.48a]
        (tile)[...2][...1] (ground)[.48b][.48c]
        (tile)[...3][...1] (ground)[.4a6][.4a7]
        (tile)[...4][...1] (ground)[.4af][.4b0]
        (tile)[...5][...1] (ground)[.4b7][.4b8]
        (tile)[...6][...1] (ground)[.4bb][.4bc]

        (tile)[...0][...2] (ground)[.497][.498]
        (tile)[...1][...2] (ground)[.49a][.49b]
        (tile)[...2][...2] (ground)[.49c][.46a] (move)[none]
        (tile)[...3][...2] (move)[none]
        (tile)[...4][...2] (move)[none]
        (tile)[...5][...2] (move)[none]
        (tile)[...6][...2] (move)[none]

        (tile)[...0][...3] (ground)[.493][.494]
        (tile)[...1][...3] (ground)[.499][.46a]
        (tile)[...2][...3] (move)[none]
        (tile)[...3][...3] (move)[none]
        (tile)[...4][...3] (move)[none]
        (tile)[...5][...3] (move)[none]
        (tile)[...6][...3] (move)[none]


        (tile)[...2][...4] (move)[none]
        (tile)[...3][...4] (move)[none]
        (tile)[...4][...4] (move)[none]
        (tile)[...5][...4] (move)[none]
        (tile)[...6][...4] (move)[none]


        (tile)[...2][...5] (move)[none]
        (tile)[...3][...5] (move)[none]
        (tile)[...4][...5] (move)[none]
        (tile)[...5][...5] (move)[none]
        (tile)[...6][...5] (move)[none]


       (tile)[...2][...2]
          (air)[.4a4][...0][..00]
          (air)[.4a2][...0][..32]
          (air)[.4a0][...0][..64]

       (tile)[...3][...2]
          (air)[.4a5][...0][..16]
          (air)[.4a3][...0][..48]
          (air)[.4a1][...0][..80]
          (air)[.49f][...0][.112]
          (air)[.49e][...0][.144]
          (air)[.49d][...0][.176]

       (tile)[...4][...2]
          (air)[.4ae][...0][..16]
          (air)[.4ad][...0][..48]
          (air)[.4ac][...0][..80]
          (air)[.4ab][...0][.112]
          (air)[.4aa][...0][.144]
          (air)[.4a9][...0][.176]
          (air)[.4a8][...0][.208]

       (tile)[...5][...2]
          (air)[.4b6][...0][..16]
          (air)[.4b5][...0][..48]
          (air)[.4d4][...0][..64]
          (air)[.4d3][...0][..96]
          (air)[.4d2][...0][.128]
          (air)[.4d1][...0][.160]
          (air)[.4d0][...0][.192]
          (air)[.4cf][...0][.224]

       (tile)[...6][...2]
          (air)[.4ba][...0][..16]
          (air)[.4b9][...0][..48]
          (air)[.4d6][...0][..64]
          (air)[.4d5][...0][..80]
          (air)[.4c8][...0][..96]
          (air)[.4c6][...0][.128]
          (air)[.4c4][...0][.160]
          (air)[.4c2][...0][.192]
          (air)[.4c1][...0][.224]
  (sector_end)

   //east-west streching house middel part
    (sector)[..96]  (texg)[...0]
        (tile)[...3][...0] (ground)[.4b1][.4b2]
        (tile)[...4][...0] (ground)[.4b3][.4b4]
        (tile)[...5][...0] (ground)[.4bd][.4be]
        (tile)[...6][...0] (ground)[.4bf][.4c0]

        (tile)[...3][...1] (ground)[.4a6][.4a7]
        (tile)[...4][...1] (ground)[.4af][.4b0]
        (tile)[...5][...1] (ground)[.4b7][.4b8]
        (tile)[...6][...1] (ground)[.4bb][.4bc]

        (tile)[...3][...2] (move)[none]
        (tile)[...4][...2] (move)[none]
        (tile)[...5][...2] (move)[none]
        (tile)[...6][...2] (move)[none]

        (tile)[...3][...3] (move)[none]
        (tile)[...4][...3] (move)[none]
        (tile)[...5][...3] (move)[none]
        (tile)[...6][...3] (move)[none]

        (tile)[...3][...4] (move)[none]
        (tile)[...4][...4] (move)[none]
        (tile)[...5][...4] (move)[none]
        (tile)[...6][...4] (move)[none]

        (tile)[...3][...5] (move)[none]
        (tile)[...4][...5] (move)[none]
        (tile)[...5][...5] (move)[none]
        (tile)[...6][...5] (move)[none]

       (tile)[...3][...2]
          (air)[.4a5][...0][..16]
          (air)[.4a3][...0][..48]
          (air)[.4d1][...0][..80]
          (air)[.464][...0][.112]
          (air)[.4c7][...0][.144]
          (air)[.4c5][...0][.176]
          (air)[.4c3][...0][.208]

       (tile)[...4][...2]
          (air)[.4ae][...0][..16]
          (air)[.4ad][...0][..48]
          (air)[.4ac][...0][..80]
          (air)[.4ab][...0][.112]
          (air)[.4aa][...0][.144]
          (air)[.4cb][...0][.176]
          (air)[.4ca][...0][.208]

       (tile)[...5][...2]
          (air)[.4b6][...0][..16]
          (air)[.4b5][...0][..48]
          (air)[.4d4][...0][..64]
          (air)[.4d3][...0][..96]
          (air)[.4d2][...0][.128]
          (air)[.4d1][...0][.160]
          (air)[.4d0][...0][.192]
          (air)[.4cf][...0][.224]

       (tile)[...6][...2]
          (air)[.4ba][...0][..16]
          (air)[.4b9][...0][..48]
          (air)[.4d6][...0][..64]
          (air)[.4d5][...0][..80]
          (air)[.4c8][...0][..96]
          (air)[.4c6][...0][.128]
          (air)[.4c4][...0][.160]
          (air)[.4c2][...0][.192]
          (air)[.4c1][...0][.224]

  (sector_end)

   //east-west streching house front part closed door
    (sector)[..97]  (texg)[...0]
        (tile)[...7][...1] (ground)[.481][.482]

        (tile)[...7][...2] (move)[none]
        (tile)[...8][...2] (ground)[.4e2][.4e3]
        (tile)[...9][...2] (ground)[.47d][.47e]
        (tile)[..10][...2] (ground)[.47f][.480]

        (tile)[...7][...3] (move)[none]
        (tile)[...8][...3] (ground)[.4dc][.4dd]
        (tile)[...9][...3] (ground)[.479][.47a]
        (tile)[..10][...3] (ground)[.47b][.47c]

        (tile)[...7][...4] (move)[none]
        (tile)[...8][...4] (ground)[.4f5][.4f6]

        (tile)[...7][...5] (ground)[.48d][.4eb](move)[none]
        (tile)[...8][...5] (ground)[.4ec][.4ed]

       (tile)[...7][...2]
          (air)[.4e0][...0][..00]
          (air)[.4df][...0][..32]
          (air)[.4de][...0][..64]
          (air)[.4d7][...0][..80]
          (air)[.4cd][...0][..96]
          (air)[.4c9][...0][.112]
          (air)[.4c7][...0][.144]
          (air)[.4c5][...0][.176]
          (air)[.4c3][...0][.208]

          (air)[.4e1][..32][..00]
          (air)[.4da][..32][..16]
          (air)[.4d9][..32][..48]
          (air)[.4d8][..32][..80]
          (air)[.4ce][..32][..96]
          (air)[.4cc][..32][.128]
          (air)[.4cb][..32][.160]
          (air)[.4ca][..32][.192]

       (tile)[...7][...3]
          (air)[.4db][..32][..00]
          (air)[.4f3][..32][..16]
          (air)[.4f2][..32][..48]
          (air)[.4f1][..32][..80]
          (air)[.4f0][..32][.112]
          (air)[.4ef][..32][.144]
          (air)[.4ee][..32][.176]

       (tile)[...7][...4]
          (air)[.4f4][..32][..00]
          (air)[.4ea][..32][..16]
          (air)[.4e8][..32][..48]
          (air)[.4e6][..32][..80]
          (air)[.4e5][..32][.112]
          (air)[.4e4][..32][.144]

       (tile)[...7][...5]
          (air)[.4e9][..32][..32]
          (air)[.4e7][..32][..64]
  (sector_end)

   //east-west streching house front part open door
    (sector)[..98]  (texg)[...0]
        (tile)[...7][...1] (ground)[.481][.482]

        (tile)[...7][...2] (move)[none]
        (tile)[...8][...2] (ground)[.ca0][.ca1]
        (tile)[...9][...2] (ground)[.cbd][.cbe]
        (tile)[..10][...2] (ground)[.cbf][.cc0]

        (tile)[...7][...3] (move)[none]
        (tile)[...8][...3] (ground)[.c9a][.c9b]
        (tile)[...9][...3] (ground)[.cb9][.cba]
        (tile)[..10][...3] (ground)[.cbb][.cbc]

        (tile)[...6][...4] (ground)[.000][.cb8]
        (tile)[...7][...4] (ground)[.caf][.cb0](move)[none]
        (tile)[...8][...4] (ground)[.cb1][.cb2](move)[none]
        (tile)[...9][...4] (ground)[.cc1][.cc2]
        (tile)[..10][...4] (ground)[.cc3][..01]

        (tile)[...5][...5] (ground)[.000][.cb4]
        (tile)[...6][...5] (ground)[.cb5][.cb6]
        (tile)[...7][...5] (ground)[.cb3][.ca8](move)[none]
        (tile)[...8][...5] (ground)[.ca9][.4ed](move)[none]

       (tile)[...7][...2]
          (air)[.c9e][...0][..00]
          (air)[.c9d][...0][..32]
          (air)[.c9c][...0][..64]
          (air)[.4d7][...0][..80]
          (air)[.4cd][...0][..96]
          (air)[.4c9][...0][.112]
          (air)[.4c7][...0][.144]
          (air)[.4c5][...0][.176]
          (air)[.4c3][...0][.208]

          (air)[.c9f][..32][..00]
          (air)[.c98][..32][..16]
          (air)[.c96][..32][..48]
          (air)[.c94][..32][..80]
          (air)[.4ce][..32][..96]
          (air)[.4cc][..32][.128]
          (air)[.4cb][..32][.160]
          (air)[.4ca][..32][.192]

       (tile)[...7][...3]
          (air)[.c99][..32][..00]
          (air)[.c97][..32][..32]
          (air)[.c95][..32][..64]
          (air)[.cad][..32][..80]
          (air)[.4f0][..32][.112]
          (air)[.4ef][..32][.144]
          (air)[.4ee][..32][.176]

       (tile)[...7][...4]
          (air)[.ca7][..32][..16]
          (air)[.ca5][..32][..48]
          (air)[.ca3][..32][..80]
          (air)[.4e5][..32][.112]
          (air)[.4e4][..32][.144]

       (tile)[...7][...5]
          (air)[.ca6][..32][..32]
          (air)[.ca4][..32][..64]
  (sector_end)

//east-west streching house small closed door
  (sector)[..99]
    (recursec)[..95][..00][..00]
    (recursec)[..97][..00][..00]
  (sector_end)

//east-west streching house big closed door
  (sector)[.100]
    (recursec)[..95][..00][..00]
    (recursec)[..96][..04][..00]
    (recursec)[..97][..04][..00]
  (sector_end)

//east-west streching house small open door
  (sector)[.101]
    (recursec)[..95][..00][..00]
    (recursec)[..98][..00][..00]
  (sector_end)

//big river and wall collection sector
  (sector)[.102]
    //river 2x8 blocks
    (recursec)[..56][..56][..06]
    (recursec)[..56][..56][..14]
    (recursec)[..56][..56][..22]
    (recursec)[..56][..30][.100]
    (recursec)[..56][..30][.108]
    (recursec)[..56][..30][.116]
    (recursec)[..56][..30][.124]
    (recursec)[..56][..30][.132]
    (recursec)[..56][.108][..04]
    (recursec)[..56][.108][..12]
    (recursec)[..56][.110][..84]
    (recursec)[..56][..86][.116]
    (recursec)[..56][..86][.124]
    (recursec)[..56][..86][.132]
    (recursec)[..56][.106][.114]
    (recursec)[..56][.106][.122]
    (recursec)[..56][.106][.130]

    // quad river swirlups
    (recursec)[..61][..54][..30]
    (recursec)[..61][..46][..48]
    (recursec)[..61][..38][..64]

    //single river swirlups
    (recursec)[..58][..32][..88]
    (recursec)[..58][..30][..96]
    (recursec)[..58][.106][..20]
    (recursec)[..58][.104][..24]
    (recursec)[..58][.104][..44]
    (recursec)[..58][.102][..48]
    (recursec)[..58][..98][..58]
    (recursec)[..58][..96][..64]
    (recursec)[..58][..94][..70]
    (recursec)[..58][..92][..78]
    (recursec)[..58][..90][..98]
    (recursec)[..58][..88][.106]
    (recursec)[..58][..86][.112]
    (recursec)[..58][.108][..76]
    (recursec)[..58][.108][..92]
    (recursec)[..58][.106][.110]

   //river swirdowns
    (recursec)[..59][..32][..80]
    (recursec)[..59][.104][..28]
    (recursec)[..59][.104][..58]
    (recursec)[..59][.106][..62]
    (recursec)[..59][.108][..70]
    (recursec)[..59][.108][..80]

    //river 2x4 combis
    (recursec)[..55][..34][..84]
    (recursec)[..55][..32][..92]
    (recursec)[..55][..94][..74]
    (recursec)[..55][.108][..66]
    (recursec)[..55][..92][..94]
    (recursec)[..55][.108][.106]

    //river bridge
    (recursec)[..57][..48][..46]
    (recursec)[..57][..96][..68]
    (recursec)[..57][..90][.102]

    // river split
    (recursec)[..60][.100][..54]

    // tree overhanging water
    (recursec)[..62][.103][..34]  
    (recursec)[..62][..89][..84]
    (recursec)[..62][.105][..98]

    // river 2x2 singles 51 52 54
    (recursec)[..51][.106][..32]
    (recursec)[..52][.106][..42]
    (recursec)[..54][.102][..52]
    (recursec)[..51][.098][..62]
    (recursec)[..52][.110][..74]
    (recursec)[..54][..92][..82]
    (recursec)[..51][..92][..92]
    (recursec)[..52][.108][..96]
    (recursec)[..54][..90][.104]
    (recursec)[..51][..88][.110]

    //wall dead end west no shadow at river
    (recursec)[..64][..34][..93]
    (recursec)[..64][..92][.105]
    (recursec)[..64][..36][..77]  

    //wall corner facing away 
    (recursec)[..63][..58][..80]
    (recursec)[..63][..50][.104] 

    //wall corner facing towards
    (recursec)[..65][..57][..77]
    (recursec)[..65][..63][..81]

    //wall crossing
    (recursec)[..66][..58][.104]

    //wall crumbeling towards north...
    (recursec)[..67][..64][..94]
    (recursec)[..67][..58][.118]
    (recursec)[..67][..66][.110]
    (recursec)[..67][..58][..60]

    //wall crumbeling towards south...
    (recursec)[..68][..64][..96]
    (recursec)[..68][.100][..50]

    // wall west corner shadow
    (recursec)[..69][..51][..77]
    (recursec)[..69][..57][..57]
    (recursec)[..69][..57][..99]

    // wall east corner no bend
    (recursec)[..70][..46][..77]
    (recursec)[..70][..44][..93]
    (recursec)[..70][..88][.105]
    (recursec)[..70][.106][.105]
    (recursec)[..70][..60][..57]

    // wall north corner
    (recursec)[..71][..64][..98]
    (recursec)[..71][.100][..52]

    // wall north-south singe
    (recursec)[..72][..58][..79]

    // wall north-south double
    (recursec)[..73][..58][..58]

    // wall north-south quad
    (recursec)[..74][..58][.100]
    (recursec)[..74][..66][.106]
    (recursec)[..74][..50][.100]

    // wall north-south 11x
    (recursec)[..75][..58][.107]
    (recursec)[..75][..64][..83]

    // wall east-west 8x
    (recursec)[..79][..38][..77]
    (recursec)[..79][..36][..93]
    (recursec)[..79][..60][.105]
    (recursec)[..79][..68][.105]
    (recursec)[..79][..76][.105]
    (recursec)[..79][..94][.105]

    // wall east-west 4x
    (recursec)[..78][..52][.105]
    (recursec)[..78][..60][..99]
    (recursec)[..78][..84][.105]
    (recursec)[..78][.102][.105]

    // wall east-west 2x
    (recursec)[..77][..54][..77]
    (recursec)[..77][..60][..81]

    // wall east-west 1x
    (recursec)[..76][..56][..77]
    (recursec)[..76][..62][..81]
    (recursec)[..76][..56][.105]
  (sector_end)

   //hellhole open
    (sector)[.103]  (texg)[...0]
        (tile)[...0][...0] (ground)[.db4][.db5]
        (tile)[...1][...0] (ground)[.dba][.dbb](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...2][...0] (ground)[.dbc][.dbd](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...3][...0] (ground)[.dc2][.dc3](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...4][...0] (ground)[.dc4][.dc5](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...5][...0] (ground)[.dca][.dcb](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...6][...0] (ground)[.dcc][.dcd](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...7][...0] (ground)[.dd1][.dd2]

        (tile)[...0][...1] (ground)[.db1][.db2]
        (tile)[...1][...1] (ground)[.db6][.db7](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...2][...1] (ground)[.db8][.db9](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...3][...1] (ground)[.dbe][.dbf](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...4][...1] (ground)[.dc0][.dc1](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...5][...1] (ground)[.dc6][.dc7](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...6][...1] (ground)[.dc8][.dc9](move)[none] (mech)[..73][+] //warp to lev13
        (tile)[...7][...1] (ground)[.dce][.dcf]
  (sector_end)

   //hellhole closed
    (sector)[.104]  (texg)[...0]

        (tile)[...1][...0] (ground)[.22c][.22d]
        (tile)[...2][...0] (ground)[.22e][.22f](move)[none]
        (tile)[...3][...0] (ground)[.232][.233](move)[none]
        (tile)[...4][...0] (ground)[.234][.235](move)[none]
        (tile)[...5][...0] (ground)[.238][.239](move)[none]
        (tile)[...6][...0] (ground)[.23a][.23b]
  (sector_end)

   //caves entrace closed
    (sector)[.105]  (texg)[...0]
        (tile)[...0][...0] (ground)[.d39][.d3a](move)[none]
        (tile)[...1][...0] (ground)[.d3b][-001](move)[none]
        (tile)[...2][...0] (ground)[.d43][.d44](move)[none]
        (tile)[...3][...0] (ground)[.d45][-001](move)[none]
        (tile)[...4][...0] (ground)[.d5c][.d5d](move)[none]
        (tile)[...5][...0] (ground)[.d5e][.d5f](move)[none]

        (tile)[...0][...1] (ground)[.d35][.001](move)[none]
        (tile)[...1][...1] (move)[none]
        (tile)[...2][...1] (move)[none]
        (tile)[...3][...1] (move)[none]
        (tile)[...4][...1] (move)[none]
        (tile)[...5][...1] (ground)[.d79][.d7a](move)[none] //replacable

        (tile)[...0][...2] (move)[none]
        (tile)[...1][...2] (move)[none]
        (tile)[...2][...2] (move)[none]
        (tile)[...3][...2] (move)[none]
        (tile)[...4][...2] (move)[none]
        (tile)[...5][...2] (ground)[.d85][.d86](move)[none] //replacable

        (tile)[...0][...3] (move)[none]
        (tile)[...1][...3] (move)[none]
        (tile)[...2][...3] (move)[none]
        (tile)[...3][...3] (move)[none]
        (tile)[...4][...3] (move)[none]
        (tile)[...5][...3] (ground)[.d82][.d83](move)[none] //replacable

       (tile)[...2][...0]
          (air)[.d42][...0][..32]
          (air)[.d41][...0][..64]
          (air)[.d40][...0][..96]

       (tile)[...3][...0]
          (air)[.d3f][...0][..32]
          (air)[.d3e][...0][..64]
          (air)[.d3d][...0][..96]
          (air)[.d3c][...0][.128]

       (tile)[...4][...0]
          (air)[.d5b][...0][..32]
          (air)[.d5a][...0][..64]
          (air)[.d59][...0][..96]
          (air)[.d58][...0][.128]
          (air)[.d57][...0][.160]

       (tile)[...5][...0]
          (air)[.d4e][...0][..32]
          (air)[.d4c][...0][..64]
          (air)[.d4a][...0][..96]
          (air)[.d48][...0][.128]
          (air)[.d46][...0][.160]

       (tile)[...5][...1] //replacable
          (air)[.d74][...0][..16]
          (air)[.d73][...0][..48]
          (air)[.d71][...0][..80]
          (air)[.d6f][...0][.112]
          (air)[.d6d][...0][.144]

       (tile)[...5][...2] //replacable
          (air)[.d78][...0][..16]
          (air)[.d77][...0][..48]
          (air)[.d76][...0][..80]
          (air)[.d75][...0][.112]
          (air)[.d50][...0][.144]

       (tile)[...5][...3] //replacable
          (air)[.d7f][...0][..16]
          (air)[.d7d][...0][..48]
          (air)[.d7c][...0][..80]
          (air)[.d81][..32][..32]
          (air)[.d80][..32][..64]

  (sector_end)

   //caves entrace make opening
    (sector)[.106]  (texg)[...0]
        (tile)[...5][...1] (ground)[.d55][.d56]
        (tile)[...4][...2] (ground)[.000][.d69]
        (tile)[...5][...2] (ground)[.d6a][.d6b]
        (tile)[...5][...3] (ground)[.d67][.d68]

       (tile)[...5][...1] (clean_air)
          (air)[.d4f][...0][..16]
          (air)[.d4d][...0][..48]
          (air)[.d4b][...0][..80]
          (air)[.d49][...0][.112]
          (air)[.d47][...0][.144]

       (tile)[...5][...2] (clean_air)
          (air)[.d54][...0][..16]
          (air)[.d63][...0][..32]
          (air)[.d53][...0][..48]
          (air)[.d61][...0][..64]
          (air)[.d52][...0][..80]
          (air)[.d51][...0][.112]
          (air)[.d50][...0][.144]

       (tile)[...5][...3] (clean_air)
          (air)[.d64][...0][..16]
          (air)[.d62][...0][..48]
          (air)[.d60][...0][..80]
          (air)[.d66][..32][..32]
          (air)[.d65][..32][..64]

        (tile)[...6][...1] (mech)[..71][+] //warp to lev9
        (tile)[...6][...2] (mech)[..71][+] //warp to lev9

  (sector_end)

   //hellfire hive entry closed
    (sector)[.107]  (texg)[...0]
        (tile)[...2][...1] (ground)[.e06][.e07]
        (tile)[...3][...1] (ground)[.e08][.e09]
        (tile)[...4][...1] (ground)[.e16][.e17]
        (tile)[...5][...1] (ground)[.e18][.e19]

        (tile)[...0][...2] (ground)[.de5][.de6]
        (tile)[...1][...2] (ground)[.de7][.de8]
        (tile)[...2][...2] (ground)[.e02][.e03]
        (tile)[...3][...2] (ground)[.e04][.e05]
        (tile)[...4][...2] (ground)[.e12][.e13]
        (tile)[...5][...2] (ground)[.e14][.e15]

        (tile)[...0][...3] (ground)[.de1][.de2](move)[all]
        (tile)[...1][...3] (ground)[.de3][.de4]
        (tile)[...2][...3] (ground)[.dfe][.dff]
        (tile)[...3][...3] (ground)[.e00][.e01]
        (tile)[...4][...3] (ground)[.e0e][.e0f]
        (tile)[...5][...3] (ground)[.e10][.e11]

        (tile)[...1][...4] (ground)[.ddf][.de0]
        (tile)[...2][...4] (ground)[.df1][.df2]
        (tile)[...3][...4] (ground)[.df3][.df4]
        (tile)[...4][...4] (ground)[.dfa][.dfb]
        (tile)[...5][...4] (ground)[.dfc][.dfd]

        (tile)[...1][...5] (ground)[.ddb][.ddc]
        (tile)[...2][...5] (ground)[.ded][.dee]
        (tile)[...3][...5] (ground)[.def][.df0]
        (tile)[...4][...5] (ground)[.df6][.df7]
  (sector_end)

   //hellfire hive entry open up
    (sector)[.108]  (texg)[...0]
        (tile)[...3][...0] (ground)[.e45][.e46]
        (tile)[...4][...0] (ground)[.e53][.e54]

        (tile)[...2][...1] (ground)[.e40][.e41]
        (tile)[...3][...1] (ground)[.e42][.e43]
        (tile)[...4][...1] (ground)[.e4f][.e50]
        (tile)[...5][...1] (ground)[.e51][.e52]

        (tile)[...2][...2] (ground)[.e3c][.e3d]
        (tile)[...3][...2] (ground)[.e3e][.e3f]
        (tile)[...4][...2] (ground)[.e4b][.e4c]
        (tile)[...5][...2] (ground)[.e4d][.e4e]


        (tile)[...1][...3] (ground)[.e23][.e24](move)[all] (mech)[..45][+] //warp to hive1
        (tile)[...2][...3] (ground)[.e38][.e39](move)[all] (mech)[..45][+] //warp to hive1
        (tile)[...3][...3] (ground)[.e3a][.e3b]
        (tile)[...4][...3] (ground)[.e47][.e48]
        (tile)[...5][...3] (ground)[.e49][.e4a]

        (tile)[...1][...4] (ground)[.2a3][.2a4]
        (tile)[...2][...4] (ground)[.e2c][.e2d]
        (tile)[...3][...4] (ground)[.e2e][.e2f]
        (tile)[...4][...4] (ground)[.e34][.e35]
        (tile)[...5][...4] (ground)[.e36][.e37]

        (tile)[...1][...5] (ground)[.cd3][.cd4]
        (tile)[...2][...5] (ground)[.e28][.e29]
        (tile)[...3][...5] (ground)[.e2a][.e2b]
        (tile)[...4][...5] (ground)[.e30][.e31]
        (tile)[...5][...5] (ground)[.e32][.e33]


  (sector_end)

   //hellfire crypt closed
    (sector)[.109]  (texg)[...0]
        (tile)[...0][...0] (ground)[.e6b][.e6c](clean_air)(move)[none]
        (tile)[...1][...0] (ground)[.e6d][.e6e](clean_air)(move)[none]

        (tile)[...0][...1] (ground)[.e67][.e68](clean_air)
        (tile)[...1][...1] (ground)[.e69][.e6a](clean_air)

        (tile)[...0][...2] (ground)[.e63][.e64](clean_air)
        (tile)[...1][...2] (ground)[.e65][.e66](clean_air)

        (tile)[-..1][...3] (ground)[.e7e][.e7f](clean_air)
        (tile)[...0][...3] (ground)[.e5c][.e5d](clean_air)(move)[none]
        (tile)[...1][...3] (ground)[.e61][.e62](clean_air)(move)[none]

       (tile)[...0][...3] 
          (air)[.e5a][...0][..32]
          (air)[.e58][...0][..64]

       (tile)[...1][...3] 
          (air)[.e5b][...0][..48]
          (air)[.e59][...0][..80]
          (air)[.e57][...0][.112]

          (air)[.e60][..32][..32]
          (air)[.e5f][..32][..64]
          (air)[.e5e][..32][..96]
  (sector_end)

   //hellfire crypt open up
    (sector)[.110]  (texg)[...0]
        (tile)[...0][...0] (ground)[.e7a][.e7b]
        (tile)[...1][...0] (ground)[.e7c][.e7d]

        (tile)[...0][...1] (ground)[.e76][.e77](move)[none]
          (mech)[..53][+] //warp to crypt1
        (tile)[...1][...1] (ground)[.e78][.e79](move)[none]
          (mech)[..53][+] //warp to crypt1

        (tile)[...0][...2] (ground)[.e72][.e73](move)[none]
          (mech)[..53][+] //warp to crypt1
        (tile)[...1][...2] (ground)[.e74][.e75](move)[none]
          (mech)[..53][+] //warp to crypt1

        (tile)[...0][...3] (ground)[.e6f][.e70]
        (tile)[...1][...3] (ground)[.e71][.e62]

  (sector_end)

   //cane fountain base
    (sector)[.111]  (texg)[...0]
        (tile)[...0][...0] (ground)[.24f][.250]
        (tile)[...1][...0] (ground)[.dd9][.dda](move)[none]
        (tile)[...2][...0] (ground)[.25b][.25c](move)[none]

        (tile)[...1][...1] (move)[none]
        (tile)[...2][...1] (ground)[.256][.257](move)[none]
  (sector_end)

   //cane fountain set clear
    (sector)[.112]  (texg)[...0]
        (tile)[...2][...0] (clean_air)
          (air)[.253][..00][..32]
          (air)[.251][..00][..64]
          (air)[.254][..32][..32]
          (air)[.252][..32][..64]
          (air)[.255][..64][..48]
  (sector_end)

   //cane fountain set murky
    (sector)[.113]  (texg)[...0]
        (tile)[...2][...0] (clean_air)
          (air)[.dd7][..00][..32]
          (air)[.dd5][..00][..64]
          (air)[.dd8][..32][..32]
          (air)[.dd6][..32][..64]
          (air)[.255][..64][..48]
  (sector_end)

   //single grave a
    (sector)[.114]  (texg)[...0]
        (tile)[...0][...0] (ground)[.ae0][.ae1](move)[none]
          (air)[.ade][..00][..32](air)[.adf][..32][..32]
  (sector_end)

   //single grave b
    (sector)[.115]  (texg)[...0]
        (tile)[...0][...0] (ground)[.ae9][.aea](move)[none]
          (air)[.ae8][..32][..32]
  (sector_end)

   //single grave c
    (sector)[.116]  (texg)[...0]
        (tile)[...0][...0] (ground)[.aec][.aed](move)[none]
          (air)[.aeb][..32][..32]
  (sector_end)

   //single grave d
    (sector)[.117]  (texg)[...0]
        (tile)[...0][...0] (ground)[.aff][.b00](move)[none]
          (air)[.afd][..00][..32](air)[.afe][..32][..32]
  (sector_end)

   //single grave e
    (sector)[.118]  (texg)[...0]
        (tile)[...0][...0] (ground)[.b1d][.b1e](move)[none]
          (air)[.b1b][..00][..32](air)[.b1c][..32][..32]
  (sector_end)

   //single grave f
    (sector)[.119]  (texg)[...0]
        (tile)[...0][...0] (ground)[.b3b][.b3c](move)[none]
          (air)[.b39][..00][..32](air)[.b3a][..32][..32]
  (sector_end)

   //single grave g
    (sector)[.120]  (texg)[...0]
        (tile)[...0][...0] (ground)[.b4e][.b4f](move)[none]
          (air)[.b4c][..00][..32](air)[.b4d][..32][..32]
  (sector_end)

   //single grave h
    (sector)[.121]  (texg)[...0]
        (tile)[...0][...0] (ground)[.b57][.b58](move)[none]
          (air)[.b56][..32][..32]
  (sector_end)

   //single grave i
    (sector)[.122]  (texg)[...0]
        (tile)[...0][...0] (ground)[.b5a][.b5b](move)[none]
          (air)[.b59][..32][..32]
  (sector_end)

   //single grave j
    (sector)[.123]  (texg)[...0]
        (tile)[...0][...0] (ground)[.b62][.b63](move)[none]
          (air)[.b61][..32][..32]
  (sector_end)

   //single grave k
    (sector)[.124]  (texg)[...0]
        (tile)[...0][...0] (ground)[.b73][.b74](move)[none]
          (air)[.b71][..00][..32](air)[.b72][..32][..32]
  (sector_end)

   //single grave l
    (sector)[.125]  (texg)[...0]
        (tile)[...0][...0] (ground)[.b76][.b77](move)[none]
          (air)[.b75][..32][..32]
  (sector_end)

   //single grave m
    (sector)[.126]  (texg)[...0]
        (tile)[...0][...0] (ground)[.b91][.b92](move)[none]
          (air)[.b90][..32][..32]
  (sector_end)

   //single grave n
    (sector)[.127]  (texg)[...0]
        (tile)[...0][...0] (ground)[.ba4][.ba5](move)[none]
          (air)[.ba2][..00][..32](air)[.ba3][..32][..32]
  (sector_end)

   //double grave a
    (sector)[.128]  (texg)[...0]
      (tile)[...0][...0] (ground)[.acc][.acd](move)[none]
         (air)[.acb][..32][..32]
      (tile)[...1][...0] (ground)[.acf][.ad0](move)[none]
          (air)[.ace][..32][..32]
  (sector_end)

   //double grave b with church light
    (sector)[.129]  (texg)[...0]
      (tile)[...0][...0] (ground)[.b09][.b0a](move)[none]
         (air)[.b07][..00][..32](air)[.b08][..32][..32]
      (tile)[...1][...0] (ground)[.b0c][.b0d](move)[none]
          (air)[.b0b][..32][..32]
  (sector_end)

   //double grave c
    (sector)[.130]  (texg)[...0]
      (tile)[...0][...0] (ground)[.ad5][.ad6]
      (tile)[...1][...0] (ground)[.ad8][.ad9](move)[none]
          (air)[.ad7][..32][..32]
  (sector_end)

  //double grave d
    (sector)[.131]  (texg)[...0]
      (tile)[...0][...0] (ground)[.b12][.b13]
      (tile)[...1][...0] (ground)[.b15][.b16](move)[none]
          (air)[.b14][..32][..32]
  (sector_end)

   //double grave e
    (sector)[.132]  (texg)[...0]
      (tile)[...0][...0] (ground)[.af4][.af5](move)[none]
         (air)[.af2][..00][..32](air)[.af3][..32][..32]
      (tile)[...1][...0] (ground)[.af7][.af8](move)[none]
          (air)[.af6][..32][..32]

      (tile)[...0][-..1] (ground)[.af9][.afa]
      (tile)[...1][-..1] (ground)[.afb][.afc]
  (sector_end)

   //double grave f
    (sector)[.133]  (texg)[...0]
      (tile)[...0][...0] (ground)[.b27][.b28](move)[none]
         (air)[.b25][..00][..32](air)[.b26][..32][..32]
      (tile)[...1][...0] (ground)[.b2a][.b2b](move)[none]
          (air)[.b29][..32][..32]
  (sector_end)

  //double grave g
    (sector)[.134]  (texg)[...0]
      (tile)[...0][...0] (ground)[.b30][.b31]
      (tile)[...1][...0] (ground)[.b33][.b34](move)[none]
          (air)[.b32][..32][..32]
  (sector_end)

  //double grave h
    (sector)[.135]  (texg)[...0]
      (tile)[...0][...0] (ground)[.b99][.b9a]
      (tile)[...1][...0] (ground)[.b9c][.b9d](move)[none]
          (air)[.b9b][..32][..32]
  (sector_end)

  //tripple grave a
    (sector)[.136]  (texg)[...0]
      (tile)[...0][...0] (ground)[.b7e][.b7f](move)[none]
         (air)[.b7c][..00][..32](air)[.b7d][..32][..32]
      (tile)[...1][...0] (ground)[.b81][.b82](move)[none]
          (air)[.b80][..32][..32]
      (tile)[...2][...0] (ground)[.b88][.b89]
          (air)[.b87][..00][..32]
  (sector_end)

  //tripple grave b with curchlight
    (sector)[.137]  (texg)[...0]
      (tile)[...0][...0] (ground)[.b43][.b44]
      (tile)[...1][...0] (ground)[.b46][.b47](move)[none]
          (air)[.b45][..32][..32]
      (tile)[...1][...1] (ground)[.b6f][.b70]
      (tile)[...2][...1] (ground)[.b78][.b79]
  (sector_end)

  // graveyard
  (sector)[.138] 
    (recursec)[.129][..58][..91]  // double grave with light

    (recursec)[.137][..56][..95]  // tripple grave with light
    (recursec)[.120][..58][..95]  // companion of tripple grave with light

    (recursec)[.114][..56][..97]  // above tripple grave with light
    (recursec)[.115][..57][..97]  // above tripple grave with light
    (recursec)[.135][..56][.100]  // even higher

    (recursec)[.136][..57][..93]  // between crypt and curch
    (recursec)[.133][..62][..91]  // between crypt and wall
    (recursec)[.134][..62][..93]  // between crypt and wall

    (recursec)[.130][..59][..98]  // behind the crypt
    (recursec)[.128][..61][..98]  // behind the crypt

    (recursec)[.131][..60][..93] // overwritable by crypt
    (recursec)[.132][..60][..95] // overwritable by crypt

    (recursec)[.116][..59][..89] // row under cypt
    (recursec)[.117][..60][..89] // row under cypt
    (recursec)[.118][..62][..89] // row under cypt
    (recursec)[.119][..63][..89] // row under cypt

    (recursec)[.121][..59][..87] // row under under cypt
    (recursec)[.122][..60][..87] // row under under cypt

    (recursec)[.125][..61][..85] // row under under cypt
    (recursec)[.123][..62][..85] // row under under cypt
    (recursec)[.124][..63][..85] // row under under cypt

    (recursec)[.126][..63][..87] // single lowest

    (recursec)[.122][..67][..97] // ouside grave yard
    (recursec)[.118][..67][..99] // ouside grave yard
    (recursec)[.119][..68][..99] // ouside grave yard

    (recursec)[.127][..64][.101] // ouside grave yard

    (recursec)[.139][..21][..80] // roadsign in the woods
    (recursec)[.140][.108][.117] // roadsign in the woods

    (recursec)[.118][.107][..73] // at witch island

  (sector_end)

  //double roadsign
    (sector)[.139]  (texg)[...0]
      (tile)[...0][...0] (ground)[.d8d][.d8e]
      (tile)[...0][...1] (ground)[.d89][.d8a]

      (tile)[...1][...1] (ground)[.d93][.d94](move)[none]
          (air)[.d91][..00][..32](air)[.d92][..32][..32]
          (air)[.d8f][..00][..64](air)[.d90][..32][..64]
  (sector_end)

  //single roadsign
    (sector)[.140]  (texg)[...0]
      (tile)[...0][...0] (ground)[.da1][.da2]
      (tile)[...0][...1] (ground)[.d9d][.d9e]

      (tile)[...1][...1] (ground)[.da7][.da8](move)[none]
          (air)[.da5][..00][..32](air)[.da6][..32][..32]
          (air)[.da3][..00][..64](air)[.da4][..32][..64]
  (sector_end)

   //the chruch. Whoever rastersed this in the first place must have had
   //a really good time. 
    (sector)[.141]  (texg)[...0]

      (tile)[...9][...0] (ground)[.c76][.c77]
      (tile)[..10][...0] (ground)[.c78][.c79]
      (tile)[..11][...0] (ground)[.c7c][.c7d]

      (tile)[...9][...1] (ground)[.6ab][.6ac]
      (tile)[..10][...1] (ground)[.6ad][.6ae]
      (tile)[..11][...1] (ground)[.6b3][.6b4]

      (tile)[...9][...2] (ground)[.6a7][.6a8]
      (tile)[..10][...2] (ground)[.6a9][.6aa]
      (tile)[..11][...2] (ground)[.6af][.6b0]

      (tile)[...7][...3] (ground)[.6bb][.6bc]
      (tile)[...9][...3] (ground)[.6c3][.6c4]
      (tile)[..10][...3] (ground)[.6c5][.6c6]
      (tile)[..11][...3] (ground)[.6cb][.6cc]
      (tile)[..13][...3] (ground)[.6d3][.6d4]

      (tile)[...7][...4] (ground)[.6b7][.6b8]
      (tile)[...8][...4] (ground)[.6b9][.6ba]
      (tile)[...9][...4] (ground)[.6bf][.6c0]
      (tile)[..10][...4] (ground)[.6c1][.6c2]
      (tile)[..11][...4] (ground)[.6c7][.6c8]
      (tile)[..12][...4] (ground)[.6c9][.6ca]
      (tile)[..13][...4] (ground)[.6cf][.6d0]

      (tile)[...7][...5] (ground)[.6db][.6bc]
      (tile)[...8][...5] (ground)[.6dd][.6de]
      (tile)[...9][...5] (ground)[.6e3][.6e4]
      (tile)[..10][...5] (ground)[.6e5][.6e6]
      (tile)[..11][...5] (ground)[.6eb][.6ec]
      (tile)[..12][...5] (ground)[.6ed][.6ee]
      (tile)[..13][...5] (ground)[.6f3][.6f4]

      (tile)[...8][...6] (ground)[.6d9][.6da]
      (tile)[...9][...6] (ground)[.6df][.6e0]
      (tile)[..10][...6] (ground)[.6e1][.6e2]
      (tile)[..11][...6] (ground)[.6e7][.6e8]
      (tile)[..12][...6] (ground)[.6e9][.6ea]

      (tile)[...7][...7] (ground)[.6fb][.6fc]
      (tile)[...8][...7] (ground)[.6fd][.6fe]
      (tile)[...9][...7] (ground)[.746][.747]
      (tile)[..10][...7] (ground)[.748][.749]
      (tile)[..11][...7] (ground)[.703][.704]
      (tile)[..12][...7] (ground)[.705][.706]
      (tile)[..14][...7] (ground)[.70d][.70e]
      (tile)[..15][...7] (ground)[.713][.714]
      (tile)[..16][...7] (ground)[.715][.716]

      (tile)[...7][...8] (ground)[.6f7][.6f8]
      (tile)[...8][...8] (ground)[.6f9][.6fa]
      (tile)[...9][...8] (ground)[.73c][.73d]
      (tile)[..10][...8] (ground)[.744][.745]
      (tile)[..11][...8] (ground)[.6ff][.700]
      (tile)[..12][...8] (ground)[.701][.702]
      (tile)[..13][...8] (ground)[.707][.708]
      (tile)[..14][...8] (ground)[.709][.70a]
      (tile)[..15][...8] (ground)[.70f][.710]
      (tile)[..16][...8] (ground)[.711][.712]
      (tile)[..17][...8] (ground)[.717][.718]

      (tile)[...0][...9] (ground)[.725][.726]
      (tile)[...1][...9] (ground)[.72b][.72c]
      (tile)[...2][...9] (ground)[.72d][.72e]
      (tile)[...3][...9] (ground)[.733][.734]
      (tile)[...4][...9] (ground)[.735][.736]
      (tile)[...5][...9] (ground)[.78c][.78d]
      (tile)[...6][...9] (ground)[.78e][.78f]
      (tile)[...7][...9] (ground)[.77e][.77f](move)[none]
      (tile)[...8][...9] (ground)[.780][.781](move)[none]
      (tile)[...9][...9] (ground)[.772][.773](move)[none]
      (tile)[..10][...9] (ground)[.774][-001](move)[none]
      (tile)[..11][...9] (ground)[.766][.767](move)[none]
      (tile)[..12][...9] (ground)[.768][.769]
      (tile)[..13][...9] (ground)[.7c4][.7c5]
      (tile)[..14][...9] (ground)[.7c6][.7c7]
      (tile)[..15][...9] (ground)[.7cc][.7cd]
      (tile)[..16][...9] (ground)[.7ce][.7cf]
      (tile)[..17][...9] (ground)[.7d4][.7d5]
      (tile)[..18][...9] (ground)[.7d6][.7d7]

      (tile)[...0][..10] (ground)[.721][.722]
      (tile)[...1][..10] (ground)[.727][.728]
      (tile)[...2][..10] (ground)[.729][.72a]
      (tile)[...3][..10] (ground)[.72f][.730]
      (tile)[...4][..10] (ground)[.731][.732]
      (tile)[...5][..10] (ground)[.783][.784]
      (tile)[...6][..10] (ground)[.78a][.78b](move)[none]
      (tile)[...7][..10] (ground)[.779][.77a](move)[none]
      (tile)[...8][..10] (ground)[.77d][-001](move)[none]
      (tile)[...9][..10] (ground)[.76b][.76c](move)[none]
      (tile)[..10][..10] (ground)[.76e][.76f](move)[none]
      (tile)[..11][..10] (ground)[.756][.757](move)[none]
      (tile)[..12][..10] (ground)[.75e][.75f](move)[none]
      (tile)[..13][..10] (ground)[.7c0][.7c1](move)[none]
      (tile)[..14][..10] (ground)[.7c2][.7c3](move)[none]
      (tile)[..15][..10] (ground)[.7c8][.7c9](move)[none]
      (tile)[..16][..10] (ground)[.7ca][.7cb](move)[none]
      (tile)[..17][..10] (ground)[.7d0][.7d1](move)[none]
      (tile)[..18][..10] (ground)[.7d2][.7d3](move)[none]

      (tile)[...0][..11] (ground)[.796][.797]
      (tile)[...1][..11] (ground)[.79c][.79d]
      (tile)[...2][..11] (ground)[.79e][.79f]
      (tile)[...3][..11] (ground)[.7a4][.7a5]
      (tile)[...4][..11] (ground)[.7a6][.7a7]
      (tile)[...5][..11] (ground)[.7a9][.7aa](move)[none]
      (tile)[...6][..11] (ground)[.7ab][.778](move)[none]
      (tile)[...7][..11] (ground)[-001][-001](move)[none]
      (tile)[...8][..11] (ground)[.76a][-001](move)[none]
      (tile)[...9][..11] (ground)[-001][.76d](move)[none]
      (tile)[..10][..11] (ground)[-001][-001](move)[none]
      (tile)[..11][..11] (ground)[-001][-001](move)[none]
      (tile)[..12][..11] (ground)[-001][-001](move)[none]
      (tile)[..13][..11] (ground)[.866][.867](move)[none]
      (tile)[..14][..11] (ground)[.768][.869](move)[none]
      (tile)[..15][..11] (ground)[.7ec][.7ed](move)[none]
      (tile)[..16][..11] (ground)[.7ee][.7ef](move)[none]
      (tile)[..17][..11] (ground)[.7dc][.7dd](move)[none]
      (tile)[..18][..11] (ground)[.7de][.7df](move)[none]

      (tile)[...0][..12] (ground)[.792][.793]
      (tile)[...1][..12] (ground)[.798][.799]
      (tile)[...2][..12] (ground)[.79a][.79b]
      (tile)[...3][..12] (ground)[.7a0][.7a1]
      (tile)[...4][..12] (ground)[.7a2][.7a3]
      (tile)[...5][..12] (ground)[.7a8][-001](move)[none]
      (tile)[...6][..12] (move)[none]
      (tile)[...7][..12] (move)[none]
      (tile)[...8][..12] (move)[none]
      (tile)[...9][..12] (move)[none]
      (tile)[..10][..12] (move)[none]
      (tile)[..11][..12] (move)[none]
      (tile)[..12][..12] (move)[none]
      (tile)[..13][..12] (ground)[.856][.857](move)[none]
      (tile)[..14][..12] (ground)[.85e][.85f](move)[none]
      (tile)[..15][..12] (ground)[.7e8][.7e9](move)[none]
      (tile)[..16][..12] (ground)[.7ea][.7eb](move)[none]
      (tile)[..17][..12] (ground)[.7d8][.7d9](move)[none]
      (tile)[..18][..12] (ground)[.7da][.7db](move)[none]

      (tile)[...2][..13] (ground)[.7ba][.7bb]
      (tile)[...3][..13] (ground)[.7bd][.7be]
      (tile)[...4][..13] (ground)[.7a8][-001]
      (tile)[...5][..13] (move)[none]
      (tile)[...6][..13] (move)[none]
      (tile)[...7][..13] (move)[none]
      (tile)[...8][..13] (move)[none]
      (tile)[...9][..13] (move)[none]
      (tile)[..10][..13] (move)[none]
      (tile)[..11][..13] (move)[none]
      (tile)[..12][..13] (move)[none]
      (tile)[..13][..13] (move)[none]
      (tile)[..14][..13] (move)[none]
      (tile)[..15][..13] (ground)[.800][.801](move)[none]
      (tile)[..16][..13] (ground)[.802][.803](move)[none]
      (tile)[..17][..13] (ground)[.7e4][.7e5](move)[none]
      (tile)[..18][..13] (ground)[.7e6][.7e7]

      (tile)[...0][..14] (ground)[.7ae][.7af]
      (tile)[...1][..14] (ground)[.7b4][.7b5]
      (tile)[...2][..14] (ground)[.7b6][.7b7]
      (tile)[...5][..14] (move)[none]
      (tile)[...6][..14] (move)[none]
      (tile)[...7][..14] (move)[none]
      (tile)[...8][..14] (move)[none]
      (tile)[...9][..14] (move)[none]
      (tile)[..10][..14] (move)[none]
      (tile)[..11][..14] (move)[none]
      (tile)[..12][..14] (move)[none]
      (tile)[..13][..14] (move)[none]
      (tile)[..14][..14] (move)[none]
      (tile)[..15][..14] (ground)[.7f6][.7f7](move)[none]
      (tile)[..16][..14] (ground)[.7f8][.7f9](move)[none]
      (tile)[..17][..14] (ground)[.7e0][.7e1]
      (tile)[..18][..14] (ground)[.7e2][.7e3]

      (tile)[...5][..15] (move)[none]
      (tile)[...6][..15] (move)[none]
      (tile)[...7][..15] (move)[none]
      (tile)[...8][..15] (move)[none]
      (tile)[...9][..15] (move)[none]
      (tile)[..10][..15] (move)[none]
      (tile)[..11][..15] (move)[none]
      (tile)[..12][..15] (move)[none]
      (tile)[..13][..15] (move)[none]
      (tile)[..14][..15] (move)[none]
      (tile)[..15][..15] (ground)[.814][.815](move)[none]
      (tile)[..16][..15] (ground)[.816][.817]

      (tile)[...5][..16] (move)[none]
      (tile)[...6][..16] (move)[none]
      (tile)[...7][..16] (move)[none]
      (tile)[...8][..16] (move)[none]
      (tile)[...9][..16] (move)[none]
      (tile)[..10][..16] (move)[none]
      (tile)[..11][..16] (move)[none]
      (tile)[..12][..16] (move)[none]
      (tile)[..13][..16] (move)[none]
      (tile)[..14][..16] (move)[none]
      (tile)[..15][..16] (ground)[.80a][.80b](move)[none]
      (tile)[..16][..16] (ground)[.80c][.80d]

      (tile)[...5][..17] (move)[none]
      (tile)[...6][..17] (move)[none]
      (tile)[...7][..17] (move)[none]
      (tile)[...8][..17] (move)[none]
      (tile)[...9][..17] (move)[none]
      (tile)[..10][..17] (move)[none]
      (tile)[..11][..17] (move)[none]
      (tile)[..12][..17] (move)[none]
      (tile)[..13][..17] (move)[none]
      (tile)[..14][..17] (move)[none]
      (tile)[..15][..17] (ground)[.828][.829](move)[none]
      (tile)[..16][..17] (ground)[.82a][.82b]

      (tile)[...5][..18] (move)[none]
      (tile)[...6][..18] (move)[none]
      (tile)[...7][..18] (move)[none]
      (tile)[...8][..18] (move)[none]
      (tile)[...9][..18] (move)[none]
      (tile)[..10][..18] (move)[none]
      (tile)[..11][..18] (move)[none]
      (tile)[..12][..18] (move)[none]
      (tile)[..13][..18] (move)[none]
      (tile)[..14][..18] (move)[none]
      (tile)[..15][..18] (ground)[.81e][.81f](move)[none]
      (tile)[..16][..18] (ground)[.820][.821]

      (tile)[...5][..19] (move)[none]
      (tile)[...6][..19] (move)[none]
      (tile)[...7][..19] (move)[none]
      (tile)[...8][..19] (move)[none]
      (tile)[...9][..19] (move)[none]
      (tile)[..10][..19] (move)[none]
      (tile)[..11][..19] (move)[none]
      (tile)[..12][..19] (move)[none]
      (tile)[..13][..19] (move)[none]
      (tile)[..14][..19] (move)[none]
      (tile)[..15][..19] (ground)[.83c][.83d](move)[none]
      (tile)[..16][..19] (ground)[.83e][.83f]

      (tile)[...5][..20] (move)[none]
      (tile)[...6][..20] (move)[none]
      (tile)[...7][..20] (move)[none]
      (tile)[...8][..20] (move)[none]
      (tile)[...9][..20] (move)[none]
      (tile)[..10][..20] (move)[none]
      (tile)[..11][..20] (move)[none]
      (tile)[..12][..20] (move)[none]
      (tile)[..13][..20] (move)[none]
      (tile)[..14][..20] (move)[none]
      (tile)[..15][..20] (ground)[.832][.833](move)[none]
      (tile)[..16][..20] (ground)[.834][.835]

      (tile)[...5][..21] (move)[none]
      (tile)[...6][..21] (move)[none]
      (tile)[...7][..21] (move)[none]
      (tile)[...8][..21] (move)[none]
      (tile)[...9][..21] (move)[none]
      (tile)[..10][..21] (move)[none]
      (tile)[..11][..21] (move)[none]
      (tile)[..12][..21] (move)[none]
      (tile)[..13][..21] (move)[none]
      (tile)[..14][..21] (move)[none]
      (tile)[..15][..21] (ground)[.846][.847](move)[none]
      (tile)[..16][..21] (ground)[.848][.849]

      (tile)[...5][..22] (move)[none]
      (tile)[...6][..22] (move)[none]
      (tile)[...7][..22] (move)[none]
      (tile)[...8][..22] (move)[none]
      (tile)[...9][..22] (move)[none]
      (tile)[..10][..22] (move)[none]
      (tile)[..11][..22] (move)[none]
      (tile)[..12][..22] (move)[none]
      (tile)[..13][..22] (move)[none]
      (tile)[..14][..22] (move)[none]
      (tile)[..15][..22] (ground)[.842][.843](move)[none]
      (tile)[..16][..22] (ground)[.844][.845]

      // first air layer

      (tile)[...7][...9] 
        (air)[.782][..00][..176]

      (tile)[...8][...9]
        (air)[.789][..00][..80]
        (air)[.788][..00][.112]
        (air)[.787][..00][.144]
        (air)[.786][..00][.176]
        (air)[.785][..00][.208]

      (tile)[...9][...9]
        (air)[.73b][..00][..16]
        (air)[.771][..00][..32]
        (air)[.73a][..00][..48]
        (air)[.770][..00][..64]
        (air)[.739][..00][..80]
        (air)[.738][..00][.112]
        (air)[.777][..00][.112]
        (air)[.776][..00][.144]
        (air)[.737][..00][.144]
        (air)[.775][..00][.176]

      (tile)[..10][...9]
        (air)[.743][..00][..16]
        (air)[.742][..00][..48]
        (air)[.741][..00][..80]
        (air)[.740][..00][.112]
        (air)[.73f][..00][.144]
        (air)[.77c][..00][.144]
        (air)[.77b][..00][.176]
        (air)[.73e][..00][.176]

      (tile)[..10][..10]
        (air)[.765][..00][..00]
        (air)[.764][..00][..32]
        (air)[.763][..00][..64]
        (air)[.762][..00][..96]
        (air)[.761][..00][.128]
        (air)[.760][..00][.160]

      (tile)[..10][..11]
        (air)[.754][..00][..00]
        (air)[.752][..00][..32]
        (air)[.750][..00][..64]
        (air)[.74e][..00][..96]
        (air)[.74c][..00][.128]
        (air)[.74a][..00][.160]

      (tile)[..11][..11]
        (air)[.755][..00][..16]
        (air)[.753][..00][..48]
        (air)[.751][..00][..80]
        (air)[.74f][..00][.112]
        (air)[.74d][..00][.144]
        (air)[.74b][..00][.176]

      (tile)[..12][..11]
        (air)[.75d][..00][..16]
        (air)[.75c][..00][..48]
        (air)[.75b][..00][..80]
        (air)[.75a][..00][.112]
        (air)[.759][..00][.144]
        (air)[.758][..00][.176]

      (tile)[..13][..11]
        (air)[.865][..00][..32]
        (air)[.864][..00][..64]
        (air)[.863][..00][..96]
        (air)[.862][..00][.128]
        (air)[.861][..00][.160]
        (air)[.860][..00][.192]

      (tile)[..13][..12]
        (air)[.854][..00][..32]
        (air)[.852][..00][..64]
        (air)[.850][..00][..96]
        (air)[.84e][..00][.128]
        (air)[.84c][..00][.160]
        (air)[.84a][..00][.192]

      (tile)[..13][..13]
        (air)[.855][..00][..16]
        (air)[.853][..00][..48]
        (air)[.851][..00][..80]
        (air)[.84f][..00][.112]
        (air)[.84d][..00][.144]
        (air)[.84b][..00][.176]

      (tile)[..14][..13]
        (air)[.85d][..00][..16]
        (air)[.85c][..00][..48]
        (air)[.85b][..00][..80]
        (air)[.85a][..00][.112]
        (air)[.859][..00][.144]
        (air)[.858][..00][.176]

      (tile)[..15][..13]
        (air)[.7ff][..00][..32]
        (air)[.7fe][..00][..64]
        (air)[.7fd][..00][..96]
        (air)[.7fc][..00][.128]
        (air)[.7fb][..00][.160]
        (air)[.7fa][..00][.192]

      (tile)[..15][..14]
        (air)[.7f5][..00][..32]
        (air)[.7f4][..00][..64]
        (air)[.7f3][..00][..96]
        (air)[.7f2][..00][.128]
        (air)[.7f1][..00][.160]
        (air)[.7f0][..00][.192]

      (tile)[..15][..15]
        (air)[.813][..00][..32]
        (air)[.812][..00][..64]
        (air)[.811][..00][..96]
        (air)[.810][..00][.128]
        (air)[.80f][..00][.160]
        (air)[.80e][..00][.192]

      (tile)[..15][..16]
        (air)[.809][..00][..32]
        (air)[.808][..00][..64]
        (air)[.807][..00][..96]
        (air)[.806][..00][.128]
        (air)[.805][..00][.160]
        (air)[.804][..00][.192]

      (tile)[..15][..17]
        (air)[.827][..00][..32]
        (air)[.826][..00][..64]
        (air)[.825][..00][..96]
        (air)[.824][..00][.128]
        (air)[.823][..00][.160]
        (air)[.822][..00][.192]

      (tile)[..15][..18]
        (air)[.81d][..00][..32]
        (air)[.81c][..00][..64]
        (air)[.81b][..00][..96]
        (air)[.81a][..00][.128]
        (air)[.819][..00][.160]
        (air)[.818][..00][.192]

      (tile)[..15][..19]
        (air)[.83b][..00][..32]
        (air)[.83a][..00][..64]
        (air)[.839][..00][..96]
        (air)[.838][..00][.128]
        (air)[.837][..00][.160]
        (air)[.836][..00][.192]

      (tile)[..15][..20]
        (air)[.831][..00][..32]
        (air)[.830][..00][..64]
        (air)[.82f][..00][..96]
        (air)[.82e][..00][.128]
        (air)[.82d][..00][.160]
        (air)[.82c][..00][.192]

      (tile)[..15][..21]
        (air)[.88d][..00][..16]
        (air)[.88b][..00][..32]
        (air)[.885][..00][..48]
        (air)[.884][..00][..80]
        (air)[.883][..00][.112]
        (air)[.882][..00][.144]
        (air)[.881][..00][.176]

      (tile)[..15][..22]
        (air)[.88c][..00][..16]
        (air)[.88a][..00][..48]
        (air)[.889][..00][..80]
        (air)[.888][..00][.112]
        (air)[.887][..00][.144]
        (air)[.886][..00][.176]

      (tile)[..15][..23]
        (air)[.841][..00][.112]
        (air)[.840][..00][.144]

      //air second layer

      (tile)[...8][..10]
        (air)[.87b][..00][.160]
        (air)[.87a][..00][.192]
        (air)[.879][..00][.224]
        (air)[.878][..00][.256]

      (tile)[...9][..10]
        (air)[.87d][..00][.160]
        (air)[.87c][..00][.176]
        (air)[.870][..00][.192]
        (air)[.86e][..00][.224]
        (air)[.86c][..00][.256]
        (air)[.86a][..00][.288]

      (tile)[...9][..11]
        (air)[.87e][..00][.144]
        (air)[.876][..00][.160]
        (air)[.871][..00][.176]
        (air)[.86f][..00][.208]
        (air)[.86d][..00][.240]
        (air)[.86b][..00][.272]

      (tile)[...9][..12]
        (air)[.877][..00][.144]
        (air)[.875][..00][.176]
        (air)[.874][..00][.208]
        (air)[.873][..00][.240]
        (air)[.872][..00][.272]

      (tile)[..10][..12]
        (air)[.8aa][..00][.160]
        (air)[.8a9][..00][.192]
        (air)[.8a8][..00][.224]
        (air)[.8a7][..00][.256]
        (air)[.8a6][..00][.288]
        (air)[.8a5][..00][.320]
        (air)[.8a5][..00][.352]

      (tile)[..11][..12]
        (air)[.8ac][..00][.160]
        (air)[.8ab][..00][.176]
        (air)[.89a][..00][.192]
        (air)[.898][..00][.224]
        (air)[.896][..00][.256]
        (air)[.894][..00][.288]
        (air)[.892][..00][.320]
        (air)[.890][..00][.352]
        (air)[.88e][..00][.384]

      (tile)[..12][..12]
        (air)[.8ad][..00][.176]
        (air)[.8a2][..00][.192]
        (air)[.89b][..00][.208]
        (air)[.899][..00][.240]
        (air)[.897][..00][.272]
        (air)[.895][..00][.304]
        (air)[.893][..00][.336]
        (air)[.891][..00][.368]
        (air)[.88f][..00][.400]

      (tile)[..12][..13]
        (air)[.8a3][..00][.176]
        (air)[.8a1][..00][.208]
        (air)[.8a0][..00][.240]
        (air)[.89f][..00][.272]
        (air)[.89e][..00][.304]
        (air)[.89d][..00][.336]
        (air)[.89c][..00][.368]

      (tile)[..12][..14]
        (air)[.8be][..00][.160]
        (air)[.8bd][..00][.192]
        (air)[.8bc][..00][.224]
        (air)[.8bb][..00][.256]
        (air)[.8ba][..00][.288]
        (air)[.8b9][..00][.320]
        (air)[.8b8][..00][.352]

      (tile)[..13][..14]
        (air)[.8c0][..00][.160]
        (air)[.8bf][..00][.176]
        (air)[.8b4][..00][.192]
        (air)[.8b3][..00][.224]
        (air)[.8b2][..00][.256]
        (air)[.8b1][..00][.288]
        (air)[.8b0][..00][.320]
        (air)[.8af][..00][.352]
        (air)[.8ae][..00][.384]

      (tile)[..14][..14]
        (air)[.8c1][..00][.176]
        (air)[.8b6][..00][.192]
        (air)[.8b5][..00][.208]
        (air)[.8d2][..00][.224]
        (air)[.8d1][..00][.256]
        (air)[.8d0][..00][.288]
        (air)[.8cf][..00][.320]
        (air)[.8ce][..00][.352]
        (air)[.8cd][..00][.384]
        (air)[.8cc][..00][.416]

      (tile)[..14][..15]
        (air)[.8b7][..00][.176]
        (air)[.8d4][..00][.192]
        (air)[.8d3][..00][.208]
        (air)[.8c8][..00][.224]
        (air)[.8c7][..00][.256]
        (air)[.8c6][..00][.288]
        (air)[.8c5][..00][.320]
        (air)[.8c4][..00][.352]
        (air)[.8c3][..00][.384]
        (air)[.8c2][..00][.416]

      (tile)[..14][..16]
        (air)[.8d5][..00][.176]
        (air)[.8ca][..00][.192]
        (air)[.8c9][..00][.208]
        (air)[.8e7][..00][.224]
        (air)[.8e6][..00][.256]
        (air)[.8e5][..00][.288]
        (air)[.8e4][..00][.320]
        (air)[.8e3][..00][.352]
        (air)[.8e2][..00][.384]
        (air)[.8e1][..00][.416]

      (tile)[..14][..17]
        (air)[.8cb][..00][.176]
        (air)[.8e9][..00][.192]
        (air)[.8e8][..00][.208]
        (air)[.8dd][..00][.224]
        (air)[.8dc][..00][.256]
        (air)[.8db][..00][.288]
        (air)[.8da][..00][.320]
        (air)[.8d9][..00][.352]
        (air)[.8d8][..00][.384]
        (air)[.8d6][..00][.416]

      (tile)[..14][..18]
        (air)[.8ea][..00][.176]
        (air)[.8df][..00][.192]
        (air)[.8de][..00][.208]
        (air)[.904][..00][.224]
        (air)[.903][..00][.256]
        (air)[.902][..00][.288]
        (air)[.901][..00][.320]
        (air)[.900][..00][.352]
        (air)[.8ff][..00][.384]
        (air)[.8fe][..00][.416]

      (tile)[..14][..19]
        (air)[.8e0][..00][.176]
        (air)[.906][..00][.192]
        (air)[.905][..00][.208]
        (air)[.8f6][..00][.224]
        (air)[.8f4][..00][.256]
        (air)[.8f2][..00][.288]
        (air)[.8f0][..00][.320]
        (air)[.8ee][..00][.352]
        (air)[.8ec][..00][.384]

      (tile)[..14][..20]
        (air)[.907][..00][.176]
        (air)[.8fc][..00][.192]
        (air)[.8f7][..00][.208]
        (air)[.8f5][..00][.240]
        (air)[.8f3][..00][.272]
        (air)[.8f1][..00][.304]
        (air)[.8ef][..00][.336]
        (air)[.8ed][..00][.368]

      (tile)[..14][..21]
        (air)[.8fd][..00][.176]
        (air)[.8fb][..00][.208]
        (air)[.8fa][..00][.240]
        (air)[.8f9][..00][.272]
        (air)[.8f8][..00][.304]

      (tile)[..14][..22]
        (air)[.880][..00][.176]
        (air)[.87f][..00][.208]

      //air third layer

      (tile)[...9][..13]
        (air)[.936][..00][.352]
        (air)[.90a][..00][.384]
        (air)[.90a][..00][.416]

      (tile)[..10][..13]
        (air)[.90f][..00][.368]
        (air)[.90d][..00][.400]
        (air)[.90c][..00][.432]

      (tile)[..11][..13]
        (air)[.91d][..00][.384]
        (air)[.91c][..00][.416]
        (air)[.91b][..00][.448]

      (tile)[..11][..14]
        (air)[.91f][..00][.352]
        (air)[.91e][..00][.368]
        (air)[.915][..00][.384]
        (air)[.913][..00][.416]
        (air)[.911][..00][.448]

      (tile)[..11][..15]
        (air)[.920][..00][.336]
        (air)[.919][..00][.352]
        (air)[.916][..00][.368]
        (air)[.914][..00][.400]
        (air)[.912][..00][.432]

      (tile)[..12][..15]
        (air)[.91a][..00][.368]
        (air)[.918][..00][.400]
        (air)[.917][..00][.432]


      //air forth layer

      (tile)[...8][..14]
        (air)[.90a][..00][.416] 
        (air)[.90a][..00][.448]
        (air)[.90a][..00][.480] 
        (air)[.934][..00][.512]
        (air)[.908][-.32][.528]
        (air)[.933][..00][.544]

      (tile)[...9][..14]
        (air)[.939][..00][.416]
        (air)[.938][..00][.432]
        (air)[.92a][..00][.448]
        (air)[.928][..00][.480]
        (air)[.926][..00][.512]
        (air)[.924][..00][.544]
        (air)[.922][..00][.576]

      (tile)[..10][..14]
        (air)[.93a][..00][.432]
        (air)[.931][..00][.448]
        (air)[.92b][..00][.464]
        (air)[.929][..00][.496]
        (air)[.927][..00][.528]
        (air)[.925][..00][.560]
        (air)[.923][..00][.592]
        (air)[.921][..00][.624]

      (tile)[..10][..15]
        (air)[.932][..00][.432]
        (air)[.930][..00][.464]
        (air)[.92f][..00][.496]
        (air)[.92e][..00][.528]
        (air)[.92d][..00][.560]
        (air)[.92c][..00][.592]

      (tile)[..10][..16]
        (air)[.946][..00][.416]
        (air)[.945][..00][.448]
        (air)[.944][..00][.480]
        (air)[.943][..00][.512]
        (air)[.942][..00][.544]
        (air)[.941][..00][.576]

      (tile)[..11][..16]
        (air)[.948][-.02][.416] //strange offset
        (air)[.947][-.02][.432] //due to glitch
        (air)[.940][-.02][.448] //correction

        (air)[.93f][..00][.480]
        (air)[.93d][..00][.512]
        (air)[.93b][..00][.544]

        (air)[.93e][..32][.512]
        (air)[.93c][..32][.544]

  (sector_end)

   //empty 4x4 patch of dirt
    (sector)[.142]  (texg)[...0]
      (tile)[...0][...0] (ground)[..92][..93]
      (tile)[...1][...0] (ground)[..60][..61]
      (tile)[...2][...0] (ground)[..62][..63]
      (tile)[...3][...0] (ground)[..9e][..9f]

      (tile)[...0][...1] (ground)[..5a][..5b]
      (tile)[...1][...1] (ground)[..7c][..7d]
      (tile)[...2][...1] (ground)[..6c][..6d]
      (tile)[...3][...1] (ground)[..84][..85]

      (tile)[...0][...2] (ground)[..58][..59]
      (tile)[...1][...2] (ground)[..64][..65]
      (tile)[...2][...2] (ground)[..8a][..8b]
      (tile)[...3][...2] (ground)[..88][..89]

      (tile)[...0][...3] (ground)[..4a][..4b]
      (tile)[...1][...3] (ground)[..66][..67]
      (tile)[...2][...3] (ground)[..42][..43]
      (tile)[...3][...3] (ground)[..7c][..7d]
  (sector_end)

   //canes yard
    (sector)[.143]  (texg)[...0]
       (recursec)[.142][...1][...1] // empty 4x4 patch of dirt
       (recursec)[.142][...1][...5] // empty 4x4 patch of dirt
       (recursec)[.142][...5][...1] // empty 4x4 patch of dirt
       (recursec)[.142][...5][...5] // empty 4x4 patch of dirt

       (tile)[...0][...0] (ground)[..44][..45]
       (tile)[...1][...0] (ground)[..46][..47]
       (tile)[...2][...0] (ground)[..5e][..5f]
       (tile)[...3][...0] (ground)[..5c][..5d]
       (tile)[...4][...0] (ground)[..8c][..8d]
       (tile)[...5][...0] (ground)[..46][..47]
       (tile)[...6][...0] (ground)[..5e][..5f]
       (tile)[...7][...0] (ground)[..5c][..5d]
       (tile)[...8][...0] (ground)[..8c][..8d]
       (tile)[...9][...0] (ground)[..72][..73]

       (tile)[...0][...9] (ground)[..52][..53]
       (tile)[...1][...9] (ground)[..98][..99]
       (tile)[...2][...9] (ground)[..6a][..6b]
       (tile)[...3][...9] (ground)[..9a][..9b]
       (tile)[...4][...9] (ground)[..98][..99]
       (tile)[...5][...9] (ground)[..68][..69]
       (tile)[...6][...9] (ground)[..6a][..6b]
       (tile)[...7][...9] (ground)[..9a][..9b]
       (tile)[...8][...9] (ground)[..80][..81]

       (tile)[...0][...1] (ground)[..40][..41]
       (tile)[...0][...2] (ground)[..90][..91]
       (tile)[...0][...3] (ground)[..48][..49]
       (tile)[...0][...4] (ground)[..4c][..4d]
       (tile)[...0][...5] (ground)[..40][..41]
       (tile)[...0][...6] (ground)[..94][..95]
       (tile)[...0][...7] (ground)[..40][..41]
       (tile)[...0][...8] (ground)[..48][..49]

       (tile)[...9][...1] (ground)[..7e][..7f]
       (tile)[...9][...2] (ground)[..7a][..7b]
       (tile)[...9][...3] (ground)[..7e][..7f]
       (tile)[...9][...4] (ground)[..7a][..7b]
       (tile)[...9][...5] (ground)[..7e][..7f]
       (tile)[...9][...6] (ground)[..7a][..7b]
       (tile)[...9][...7] (ground)[..7e][..7f]
       (tile)[...9][...8] (ground)[..86][..87]
  (sector_end)

   //road north-east corner
    (sector)[.144]  (texg)[...0]
       (tile)[...0][...0] (ground)[..be][..bf]
  (sector_end)

   //road south-west corner
    (sector)[.145]  (texg)[...0]
       (tile)[...0][...0] (ground)[..b6][..b7]
  (sector_end)

   //road south-north single a
    (sector)[.146]  (texg)[...0]
       (tile)[...0][...0] (ground)[..ba][..bb]
  (sector_end)

   //road south-north single b
    (sector)[.147]  (texg)[...0]
       (tile)[...0][...0] (ground)[..a2][..a3]
  (sector_end)

   //road south-north single c
    (sector)[.148]  (texg)[...0]
       (tile)[...0][...0] (ground)[..a6][..a7]
  (sector_end)

   //road south-north single d
    (sector)[.149]  (texg)[...0]
       (tile)[...0][...0] (ground)[..c6][..c7]
  (sector_end)

   //road south-north single e
    (sector)[.150]  (texg)[...0]
       (tile)[...0][...0] (ground)[..ca][..cb]
  (sector_end)

   //road east-west single a
    (sector)[.151]  (texg)[...0]
       (tile)[...0][...0] (ground)[..ac][..ad]
  (sector_end)

   //road east-west single b
    (sector)[.152]  (texg)[...0]
       (tile)[...0][...0] (ground)[..ae][..af]
  (sector_end)

   //road east-west single c
    (sector)[.153]  (texg)[...0]
       (tile)[...0][...0] (ground)[..b4][..b5]
  (sector_end)

   //road east-west single d
    (sector)[.154]  (texg)[...0]
       (tile)[...0][...0] (ground)[..cc][..cd]
  (sector_end)

   //road south-north double
    (sector)[.155]
     (recursec)[.147][...0][...0]
     (recursec)[.148][...0][...1]
  (sector_end)

   //road south-north quad
    (sector)[.156]
     (recursec)[.146][...0][...0]
     (recursec)[.148][...0][...1]
     (recursec)[.149][...0][...2]
     (recursec)[.150][...0][...3]
  (sector_end)

   //road east-west double
    (sector)[.157]
     (recursec)[.151][...0][...0]
     (recursec)[.152][...1][...0]
  (sector_end)

   //road east-west quad
    (sector)[.158]
     (recursec)[.151][...0][...0]
     (recursec)[.152][...1][...0]
     (recursec)[.153][...2][...0]
     (recursec)[.154][...3][...0]
  (sector_end)

   //road collection sector
    (sector)[.159]
       (recursec)[.143][..80][..40] // canes dirt patch yard

       //road from cane to teleport
       (recursec)[.156][..83][..50]  //road south-north quad
       (recursec)[.156][..83][..54]  //road south-north quad
       (recursec)[.156][..83][..58]  //road south-north quad
       (recursec)[.156][..83][..62]  //road south-north quad
       (recursec)[.145][..83][..66]  //road south-west corner
       (recursec)[.154][..82][..66]  //road east-west single d
       (recursec)[.156][..81][..67]  //road south-north quad
       (recursec)[.155][..81][..71]  //road south-north double
       (recursec)[.158][..77][..66]  //road east-west quad
       (recursec)[.158][..73][..66]  //road east-west quad
       (recursec)[.158][..69][..66]  //road east-west quad
       (recursec)[.158][..65][..66]  //road east-west quad
       (recursec)[.144][..64][..66]  //north-east corner
       (recursec)[.156][..64][..67]  //road south-north quad
       (recursec)[.150][..64][..71]  //road south-north single
       (recursec)[.145][..64][..72]  //road south-west corner
       (recursec)[.158][..60][..72]  //road east-west quad
       (recursec)[.158][..56][..72]  //road east-west quad
       (recursec)[.158][..52][..72]  //road east-west quad
       (recursec)[.157][..50][..72]  //road east-west double
       (recursec)[.144][..49][..72]  //north-east corner
       (recursec)[.156][..49][..73]  //road south-north quad
       (recursec)[.160][..81][..66]  //road trident
       (recursec)[.161][..81][..73]  //road north-south fade away

       //road from cane upwards
       (recursec)[.158][..76][..46]  //road east-west quad
       (recursec)[.157][..74][..46]  //road east-west double
       (recursec)[.144][..73][..46]  //north-east corner
       (recursec)[.150][..73][..47]  //road south-north single
       (recursec)[.145][..73][..48]  //road south-west corner
       (recursec)[.157][..71][..48]  //road east-west double
       (recursec)[.144][..70][..48]  //north-east corner
       (recursec)[.156][..70][..49]  //road south-north quad
       (recursec)[.150][..70][..53]  //road south-north single
       (recursec)[.145][..70][..54]  //road south-west corner
       (recursec)[.158][..66][..54]  //road east-west quad
       (recursec)[.158][..62][..54]  //road east-west quad
       (recursec)[.158][..58][..54]  //road east-west quad
       (recursec)[.157][..56][..54]  //road east-west double
       (recursec)[.144][..55][..54]  //north-east corner
       (recursec)[.155][..55][..55]  //road south-north double
       (recursec)[.161][..55][..57]  //road north-south fade away

       //road at drunk
       (recursec)[.158][..95][..38]  //road east-west quad
       (recursec)[.160][..99][..38]  //road trident
       (recursec)[.155][..99][..39]  //road south-north double
       (recursec)[.161][..99][..41]  ///road north-south fade away

  (sector_end)

   //road trident
    (sector)[.160]  (texg)[...0]
       (tile)[...0][...0] (ground)[..ce][..cf]
  (sector_end)

   //road north-south fade away
    (sector)[.161]  (texg)[...0]
       (tile)[...0][...0] (ground)[..c2][..c3]
  (sector_end)

   //stone 1x1 a
    (sector)[.162]  (texg)[...0]
       (tile)[...0][...0] (ground)[.209][.204](move)[none]
        (air)[.208][..00][..32] (air)[.202][..32][..32]
  (sector_end)

   //stone 1x1 b
    (sector)[.163]  (texg)[...0]
       (tile)[...0][...0] (ground)[.206][.207](move)[none]
         (air)[.205][..32][..32]
  (sector_end)

   //stone 2x2
    (sector)[.164]  (texg)[...0]
       (tile)[...0][...0] (ground)[.225][.226](move)[none]
       (tile)[...1][...0] (ground)[.227][.228](move)[none]
       (tile)[...0][...1] (move)[none]
       (tile)[...1][...1] (ground)[.221][.222](move)[none]

       (tile)[...0][...0]
         (air)[.224][..00][..32]

       (tile)[...1][...0]
         (air)[.21e][..00][..32]
         (air)[.21c][..00][..64]

       (tile)[...1][...1]
         (air)[.21f][..00][..16]
         (air)[.21d][..00][..48]

         (air)[.220][..32][..32]
  (sector_end)

   //stone 3x2
    (sector)[.165]  (texg)[...0]

       (tile)[...0][...0] (ground)[.20d][.20e](move)[none]
       (tile)[...1][...0] (ground)[.20f][-001](move)[none]
       (tile)[...2][...0] (ground)[.218][.219](move)[none]

       (tile)[...0][...1] (move)[none]
       (tile)[...1][...1] (move)[none]
       (tile)[...2][...1] (ground)[.212][.213](move)[none]

       (tile)[...0][...0]
         (air)[.20c][..00][..32]

       (tile)[...1][...0]
         (air)[.20b][..00][..32]
         (air)[.20a][..00][..64]

       (tile)[...2][...0]
         (air)[.217][..00][..32]
         (air)[.216][..00][..64]

       (tile)[...2][...1]
         (air)[.210][..00][..32]
         (air)[.211][..32][..32]
   (sector_end)

   //stone collction
    (sector)[.166]

     // individuals above upper river
     (recursec)[.164][..21][..84] //2x2 stone
     (recursec)[.163][..24][..82] //1x1 stone b
     (recursec)[.165][..30][..83] //3x2 stone
     (recursec)[.162][..26][..83] //1x1 stone a
     (recursec)[.164][..32][..72] //2x2 stone
     (recursec)[.163][..30][..75] //1x1 stone b
     (recursec)[.164][..30][..68] //2x2 stone
     (recursec)[.162][..32][..71] //1x1 stone a
     (recursec)[.162][..34][..67] //1x1 stone a
     (recursec)[.164][..29][..80] //2x2 stone
     (recursec)[.163][..31][..82] //1x1 stone b
     (recursec)[.165][..32][..69] //3x2 stone
     (recursec)[.163][..35][..70] //1x1 stone b
     (recursec)[.162][..36][..69] //1x1 stone a
     (recursec)[.164][..36][..65] //2x2 stone
     (recursec)[.164][..31][..63] //2x2 stone
     (recursec)[.163][..33][..63] //1x1 stone b
     (recursec)[.165][..32][..60] //3x2 stone
     (recursec)[.162][..30][..62] //1x1 stone a
     (recursec)[.164][..32][..52] //2x2 stone
     (recursec)[.163][..31][..55] //1x1 stone b
     (recursec)[.164][..30][..58] //2x2 stone
     (recursec)[.162][..32][..59] //1x1 stone a
     (recursec)[.163][..32][..66] //1x1 stone b
     (recursec)[.164][..30][..54] //2x2 stone
     (recursec)[.162][..31][..53] //1x1 stone a
     (recursec)[.165][..30][..50] //3x2 stone
     (recursec)[.164][..35][..48] //2x2 stone
     (recursec)[.163][..33][..50] //1x1 stone b
     (recursec)[.164][..38][..49] //2x2 stone
     (recursec)[.163][..35][..51] //1x1 stone b
     (recursec)[.162][..34][..56] //1x1 stone a
     (recursec)[.164][..44][..51] //2x2 stone
     (recursec)[.163][..43][..52] //1x1 stone b
     (recursec)[.162][..45][..50] //1x1 stone a
     (recursec)[.165][..36][..42] //3x2 stone
     (recursec)[.164][..38][..40] //2x2 stone
     (recursec)[.162][..39][..43] //1x1 stone a
     (recursec)[.165][..40][..40] //3x2 stone
     (recursec)[.164][..40][..42] //2x2 stone
     (recursec)[.163][..42][..43] //1x1 stone b
     (recursec)[.164][..43][..39] //2x2 stone
     (recursec)[.162][..37][..50] //1x1 stone a
     (recursec)[.165][..46][..41] //3x2 stone
     (recursec)[.163][..45][..41] //1x1 stone b
     (recursec)[.162][..47][..40] //1x1 stone a
     (recursec)[.163][..47][..43] //1x1 stone b
     (recursec)[.164][..44][..42] //2x2 stone
     (recursec)[.162][..40][..49] //1x1 stone a
     (recursec)[.162][..45][..45] //1x1 stone a

     // individuals south side
     (recursec)[.164][..58][..20] //2x2 stone
     (recursec)[.163][..59][..24] //1x1 stone b
     (recursec)[.164][..60][..24] //2x2 stone
     (recursec)[.164][..62][..23] //2x2 stone
     (recursec)[.162][..58][..23] //1x1 stone a
     (recursec)[.165][..62][..25] //3x2 stone
     (recursec)[.164][..62][..27] //2x2 stone
     (recursec)[.165][..59][..28] //3x2 stone
     (recursec)[.164][..58][..26] //2x2 stone
     (recursec)[.163][..57][..33] //1x1 stone b
     (recursec)[.164][..56][..34] //2x2 stone
     (recursec)[.165][..62][..30] //3x2 stone
     (recursec)[.162][..65][..30] //1x1 stone a
     (recursec)[.163][..53][..42] //1x1 stone b
     (recursec)[.164][..73][..32] //2x2 stone
     (recursec)[.162][..75][..32] //1x1 stone a
     (recursec)[.165][..80][..30] //3x2 stone
     (recursec)[.164][..87][..29] //2x2 stone
     (recursec)[.164][..87][..31] //2x2 stone
     (recursec)[.163][..86][..29] //1x1 stone b
     (recursec)[.163][..86][..30] //1x1 stone b
     (recursec)[.162][..89][..31] //1x1 stone a
     (recursec)[.162][..82][..37] //1x1 stone a
     (recursec)[.164][..66][..41] //2x2 stone
     (recursec)[.163][..69][..38] //1x1 stone b
     (recursec)[.162][..71][..47] //1x1 stone a
     (recursec)[.164][..78][..44] //2x2 stone
     (recursec)[.163][..56][..56] //1x1 stone b
     (recursec)[.162][..91][..30] //1x1 stone a
     (recursec)[.163][..91][..41] //1x1 stone b
     (recursec)[.165][..92][..30] //3x2 stone
     (recursec)[.164][.102][..32] //2x2 stone
     (recursec)[.164][.106][..27] //2x2 stone
     (recursec)[.162][.108][..25] //1x1 stone a
     (recursec)[.163][.100][..38] //1x1 stone b
     (recursec)[.162][..94][..60] //1x1 stone a
     (recursec)[.164][..89][..62] //2x2 stone
     (recursec)[.165][..80][..76] //3x2 stone
     (recursec)[.163][..82][..75] //1x1 stone b
     (recursec)[.162][..80][..78] //1x1 stone a
     (recursec)[.163][..76][..63] //1x1 stone b
     (recursec)[.162][..61][..70] //1x1 stone a
     (recursec)[.163][..51][..75] //1x1 stone b
     (recursec)[.165][..52][..74] //3x2 stone
     (recursec)[.165][..66][..90] //3x2 stone
     (recursec)[.162][..68][..89] //1x1 stone a
     (recursec)[.164][..82][..84] //2x2 stone
     (recursec)[.163][..83][..94] //1x1 stone b
     (recursec)[.162][..84][..93] //1x1 stone a
     (recursec)[.164][.104][..21] //2x2 stone

     // individuals church grouds
     (recursec)[.163][..38][..81] //1x1 stone b
     (recursec)[.163][..59][..83] //1x1 stone b
     (recursec)[.164][..56][.102] //2x2 stone

     // individuals behind wall
     (recursec)[.165][..45][.106] //3x2 stone
     (recursec)[.162][..48][.105] //1x1 stone a
     (recursec)[.165][..62][.107] //3x2 stone
     (recursec)[.163][..64][.109] //1x1 stone b
     (recursec)[.164][..92][.110] //2x2 stone
     (recursec)[.162][..91][.110] //1x1 stone a
     (recursec)[.163][..93][.109] //1x1 stone b
     (recursec)[.162][..94][.111] //1x1 stone a
     (recursec)[.163][..92][.112] //1x1 stone b

     // individuals witch island
     (recursec)[.164][.108][..90] //2x2 stone
     (recursec)[.162][..97][..89] //1x1 stone a
     (recursec)[.163][..97][..90] //1x1 stone b
     (recursec)[.162][..98][..80] //1x1 stone a
     (recursec)[.164][..96][..73] //2x2 stone
     (recursec)[.165][.105][..74] //3x2 stone
     (recursec)[.165][.104][..66] //3x2 stone
     (recursec)[.163][.101][..64] //1x1 stone b



     // volume stamps

     (recursec)[.170][..94][..20] 10x10 random stone collection
     (recursec)[.170][..84][..20] 10x10 random stone collection
     (recursec)[.170][..74][..20] 10x10 random stone collection
     (recursec)[.170][..64][..20] 10x10 random stone collection
     (recursec)[.170][..46][..20] 10x10 random stone collection
     (recursec)[.170][..36][..20] 10x10 random stone collection
     (recursec)[.170][..26][..20] 10x10 random stone collection
     (recursec)[.170][..16][..20] 10x10 random stone collection
     (recursec)[.170][..06][..20] 10x10 random stone collection

     (recursec)[.170][.130][..10] 10x10 random stone collection
     (recursec)[.170][.120][..10] 10x10 random stone collection
     (recursec)[.170][.110][..10] 10x10 random stone collection
     (recursec)[.170][..98][..10] 10x10 random stone collection
     (recursec)[.170][..88][..10] 10x10 random stone collection
     (recursec)[.170][..78][..10] 10x10 random stone collection
     (recursec)[.170][..68][..10] 10x10 random stone collection
     (recursec)[.170][..58][..10] 10x10 random stone collection
     (recursec)[.170][..46][..10] 10x10 random stone collection
     (recursec)[.170][..36][..10] 10x10 random stone collection
     (recursec)[.170][..26][..10] 10x10 random stone collection
     (recursec)[.170][..16][..10] 10x10 random stone collection
     (recursec)[.170][..06][..10] 10x10 random stone collection

     (recursec)[.170][.130][..00] 10x10 random stone collection
     (recursec)[.170][.120][..00] 10x10 random stone collection
     (recursec)[.170][.110][..00] 10x10 random stone collection
     (recursec)[.170][..98][..00] 10x10 random stone collection
     (recursec)[.170][..88][..00] 10x10 random stone collection
     (recursec)[.170][..78][..00] 10x10 random stone collection
     (recursec)[.170][..68][..00] 10x10 random stone collection
     (recursec)[.170][..58][..00] 10x10 random stone collection
     (recursec)[.170][..46][..00] 10x10 random stone collection
     (recursec)[.170][..36][..00] 10x10 random stone collection
     (recursec)[.170][..26][..00] 10x10 random stone collection
     (recursec)[.170][..16][..00] 10x10 random stone collection
     (recursec)[.170][..06][..00] 10x10 random stone collection

     (recursec)[.170][..41][..30] 10x10 random stone collection
     (recursec)[.170][..31][..30] 10x10 random stone collection
     (recursec)[.170][..21][..30] 10x10 random stone collection
     (recursec)[.170][..11][..30] 10x10 random stone collection
     (recursec)[.170][..01][..30] 10x10 random stone collection

     (recursec)[.170][..26][..40] 10x10 random stone collection
     (recursec)[.170][..16][..40] 10x10 random stone collection
     (recursec)[.170][..06][..40] 10x10 random stone collection

     (recursec)[.170][..20][..50] 10x10 random stone collection
     (recursec)[.170][..10][..50] 10x10 random stone collection
     (recursec)[.170][..00][..50] 10x10 random stone collection

     (recursec)[.170][..20][..60] 10x10 random stone collection
     (recursec)[.170][..10][..60] 10x10 random stone collection
     (recursec)[.170][..00][..60] 10x10 random stone collection

     (recursec)[.170][..20][..70] 10x10 random stone collection
     (recursec)[.170][..10][..70] 10x10 random stone collection
     (recursec)[.170][..00][..70] 10x10 random stone collection

     (recursec)[.170][..10][..80] 10x10 random stone collection
     (recursec)[.170][..00][..80] 10x10 random stone collection

     (recursec)[.170][..00][..90] 10x10 random stone collection

  (sector_end)


   //5x5 nogo tiles
    (sector)[.167]
     (tile)[...0][...0] (move)[none]
     (tile)[...1][...0] (move)[none]
     (tile)[...2][...0] (move)[none]
     (tile)[...3][...0] (move)[none]
     (tile)[...4][...0] (move)[none]

     (tile)[...0][...1] (move)[none]
     (tile)[...1][...1] (move)[none]
     (tile)[...2][...1] (move)[none]
     (tile)[...3][...1] (move)[none]
     (tile)[...4][...1] (move)[none]

     (tile)[...0][...2] (move)[none]
     (tile)[...1][...2] (move)[none]
     (tile)[...2][...2] (move)[none]
     (tile)[...3][...2] (move)[none]
     (tile)[...4][...2] (move)[none]

     (tile)[...0][...3] (move)[none]
     (tile)[...1][...3] (move)[none]
     (tile)[...2][...3] (move)[none]
     (tile)[...3][...3] (move)[none]
     (tile)[...4][...3] (move)[none]

     (tile)[...0][...4] (move)[none]
     (tile)[...1][...4] (move)[none]
     (tile)[...2][...4] (move)[none]
     (tile)[...3][...4] (move)[none]
     (tile)[...4][...4] (move)[none]
  (sector_end)

   //10x10 nogo tiles
    (sector)[.168]
     (recursec)[.167][...0][...0]
     (recursec)[.167][...5][...0]
     (recursec)[.167][...0][...5]
     (recursec)[.167][...5][...5]
  (sector_end)

   //20x20 nogo tiles
    (sector)[.169]
     (recursec)[.168][...0][...0]
     (recursec)[.168][..10][...0]
     (recursec)[.168][...0][..10]
     (recursec)[.168][..10][..10]
  (sector_end)

   //10x10 random stones
    (sector)[.170]

     (recursec)[.165][...0][...0] // 3x2 stone
     (recursec)[.165][...5][...6] // 3x2 stone
     (recursec)[.165][...7][...2] // 3x2 stone
     (recursec)[.165][...1][...5] // 3x2 stone

     (recursec)[.164][...2][...2] // 2x2 stone
     (recursec)[.164][...4][...3] // 2x2 stone
     (recursec)[.164][...6][...0] // 2x2 stone
     (recursec)[.164][...5][...8] // 2x2 stone
     (recursec)[.164][...8][...5] // 2x2 stone
     (recursec)[.164][...1][...7] // 2x2 stone

     (recursec)[.162][...0][...2] // 1x1 stone b
     (recursec)[.162][...0][...9] // 1x1 stone b

     (recursec)[.162][...1][...4] // 1x1 stone b

     (recursec)[.162][...3][...0] // 1x1 stone b
     (recursec)[.162][...3][...7] // 1x1 stone b

     (recursec)[.162][...4][...2] // 1x1 stone b
     (recursec)[.162][...4][...6] // 1x1 stone b

     (recursec)[.162][...6][...3] // 1x1 stone b

     (recursec)[.162][...7][...5] // 1x1 stone b
     (recursec)[.162][...7][...8] // 1x1 stone b

     (recursec)[.162][...8][...1] // 1x1 stone b
     (recursec)[.162][...8][...4] // 1x1 stone b
     (recursec)[.162][...8][...9] // 1x1 stone b

     (recursec)[.163][...0][...3] // 1x1 stone a
     (recursec)[.163][...0][...7] // 1x1 stone a

     (recursec)[.163][...3][...4] // 1x1 stone a
     (recursec)[.163][...4][...8] // 1x1 stone a

     (recursec)[.163][...5][...0] // 1x1 stone a
     (recursec)[.163][...5][...5] // 1x1 stone a
     (recursec)[.163][...7][...4] // 1x1 stone a

     (recursec)[.163][...9][...0] // 1x1 stone a
     (recursec)[.163][...9][...7] // 1x1 stone a
   (sector_end)

   //wildgroth 1x1 a
    (sector)[.171]  (texg)[...0]
       (tile)[...0][...0] (ground)[..e4][..e5]
         (air)[..e3][..00][..32]
  (sector_end)

   //wildgroth 1x1 b
    (sector)[.172]  (texg)[...0]
       (tile)[...0][...0] (ground)[..da][..db]
         (air)[..d8][..00][..32] (air)[..d9][..32][..32]
  (sector_end)

   //wildgroth 2x1
    (sector)[.173]  (texg)[...0]
       (tile)[...0][...0] (ground)[..d1][..d2] (move)[none]
          (air)[..d0][..32][..32]
       (tile)[...1][...0] (ground)[..d4][..d5]
          (air)[..d3][..32][..32]
  (sector_end)

  // wirts tree
  (sector)[.174]  (texg)[...0]

    (tile)[...1][...0] (ground)[.13a][.13b]
    (tile)[...2][...0] (ground)[.140][.141]
    (tile)[...3][...0] (ground)[.142][.143]

    (tile)[...0][...1] (ground)[.134][.135]
    (tile)[...1][...1] (ground)[.136][.137]
    (tile)[...2][...1] (ground)[.13c][.13d]
    (tile)[...3][...1] (ground)[.13e][.13f]

    (tile)[...0][...2] (ground)[.118][.119]
    (tile)[...1][...2] (ground)[.11a][.11b]
    (tile)[...2][...2] (ground)[.159][.15a]
    (tile)[...3][...2] (ground)[.15b][.15c]
    (tile)[...4][...2] (ground)[.130][.131]

    (tile)[...0][...3] (ground)[.114][.115]
    (tile)[...1][...3] (ground)[.116][.117]
    (tile)[...2][...3] (ground)[.14e][.14f] (move)[none]
    (tile)[...3][...3] (ground)[.155][.156] (move)[none]
    (tile)[...4][...3] (ground)[.12c][.12d]

    (tile)[...0][...4] (ground)[.120][.121]
    (tile)[...1][...4] (ground)[.12a][.12b]
    (tile)[...2][...4] (ground)[.136][.137] (move)[none]
    (tile)[...3][...4] (ground)[.122][.123] (move)[none]
    (tile)[...4][...4] (ground)[.16e][.16f]

    (tile)[...2][...4] 
     (air)[.157][-.64][..32]

     (air)[.14c][-.32][..16]
     (air)[.14a][-.32][..48] 
     (air)[.148][-.32][..80]
     (air)[.146][-.32][.112] 
     (air)[.144][-.32][.144] 

     (air)[.14d][...0][..16] 
     (air)[.14b][...0][..48]
     (air)[.149][...0][..80]
     (air)[.147][...0][.112]
     (air)[.145][...0][.144] 

     (air)[.154][..32][...0]
     (air)[.153][..32][..32]
     (air)[.152][..32][..64]
     (air)[.151][..32][..96]
     (air)[.150][..32][.128]

     (air)[.16d][..64][...0]
     (air)[.16c][..64][..32]
     (air)[.16b][..64][..64]
     (air)[.16a][..64][..96]
     (air)[.169][..64][.128]

     (air)[.163][..96][..16] 
     (air)[.161][..96][..48]
     (air)[.15f][..96][..80]
     (air)[.15d][..96][.112]

     (air)[.164][.128][..16] 
     (air)[.162][.128][..48]
     (air)[.160][.128][..80]
     (air)[.15e][.128][.112]

  (sector_end)

  // small tree curving left 3x3
  (sector)[.175]  (texg)[...0]
    (tile)[...0][...0] (ground)[.184][.185]
    (tile)[...1][...0] (ground)[.174][.175]
    (tile)[...2][...0] (ground)[.196][.197]

    (tile)[...0][...1] (ground)[.190][.191]
    (tile)[...1][...1] (ground)[.192][.193]
    (tile)[...2][...1] (ground)[.188][.189]

    (tile)[...0][...2] (ground)[.18c][.18d]
    (tile)[...1][...2] (ground)[.18e][.18f]
    (tile)[...2][...2] (ground)[.180][.181]

    (tile)[...2][...2] (move)[none]

     (air)[.187][-.32][..48]
     (air)[.186][-.32][..80]
 
     (air)[.17e][..00][..32]
     (air)[.17c][..00][..64]
     (air)[.17a][..00][..96]

     (air)[.17f][..32][..32]
     (air)[.17d][..32][..64]
     (air)[.17b][..32][..96]

     (air)[.183][..64][..48]
     (air)[.182][..64][..80]

  (sector_end)

  // tree with split stem 4x4
  (sector)[.176]  (texg)[...0]
    (tile)[...1][...0] (ground)[..ee][..ef]

    (tile)[...0][...1] (ground)[..e6][..e7]
    (tile)[...1][...1] (ground)[..ea][..eb]
    (tile)[...2][...1] (ground)[..f0][..f1]
    (tile)[...3][...1] (ground)[..f2][..f3]

    (tile)[...0][...2] (ground)[..fc][..fd]
    (tile)[...1][...2] (ground)[..fe][..ff]
    (tile)[...2][...2] (ground)[.110][.111] (move)[none]
    (tile)[...3][...2] (ground)[.112][.113] (move)[none]

    (tile)[...1][...3] (ground)[..fa][..fb]
    (tile)[...2][...3] (ground)[.106][.107] (move)[none]

     (air)[.0e9][-.64][..16]
     (air)[.0e8][-.64][..48] 

     (air)[.10f][-.32][..16]
     (air)[.10e][-.32][..48] 
     (air)[.10d][-.32][..80]

     (air)[.104][..00][..32]
     (air)[.102][..00][..64]
     (air)[.100][..00][..96]

     (air)[.105][..32][..32]
     (air)[.103][..32][..64]
     (air)[.101][..32][..96]

     (air)[.10a][0.64][..16]
     (air)[.109][0.64][..48] 
     (air)[.108][0.64][..80]

     (tile)[...3][...3] (move)[none]
  (sector_end)

  // tree south-west of cain 3x3
  (sector)[.177]  (texg)[...0]
    (tile)[...0][...0] (ground)[.194][.195]
    (tile)[...1][...0] (ground)[.196][.197]

    (tile)[...0][...1] (ground)[.1ac][.1ad]
    (tile)[...1][...1] (ground)[.1ae][.1af]
    (tile)[...2][...1] (ground)[.1a5][.1a6]

    (tile)[...0][...2] (ground)[.1a8][.1a9]
    (tile)[...1][...2] (ground)[.1aa][.1ab]
    (tile)[...2][...2] (ground)[.19f][.1a0]

      (move)[none]
      (air)[.1a4][-.32][..48]
      (air)[.1a3][-.32][..80]

      (air)[.19d][...0][..32]
      (air)[.19b][...0][..64]
      (air)[.199][...0][..96]

      (air)[.19e][..32][..32]
      (air)[.19c][..32][..64]
      (air)[.19a][..32][..96]

      (air)[.1a1][..64][..48]
  
   (sector_end)
   //tree west of the cows
    (sector)[.178]  (texg)[...0]
      (tile)[...0][...0] (ground)[.1b0][.1b1]
      (tile)[...1][...0] (ground)[.1b2][.1b3]
      (tile)[...2][...0] (ground)[.1b8][.1b9]
      (tile)[...3][...0] (ground)[.1ba][.1bb]

      (tile)[...0][...1] (ground)[.1cc][.1cd]
      (tile)[...1][...1] (ground)[.1ce][.1cf]
      (tile)[...2][...1] (ground)[.1f4][.1f5]
      (tile)[...3][...1] (ground)[.1f6][.1f7]
      (tile)[...4][...1] (ground)[.1c4][.1c5]

      (tile)[...0][...2] (ground)[.1c8][.1c9]
      (tile)[...1][...2] (ground)[.1ca][.1cb]
      (tile)[...2][...2] (ground)[.1e9][.1ea] (move)[none]
      (tile)[...3][...2] (ground)[.1f0][.1f1] (move)[none]

      (tile)[...1][...3] (ground)[.1d6][.1d7]
      (tile)[...2][...3] (ground)[.1dc][.1dd] (move)[none]
      (tile)[...3][...3] (ground)[.1de][.1df] (move)[none]

      (tile)[...3][...2]

        (air)[.1f3][-.64][..64]
        (air)[.1f2][-.64][..96]

        (air)[.1e6][-.32][..80]
        (air)[.1e4][-.32][.112]
        (air)[.1e2][-.32][.144]
        (air)[.1e0][-.32][.176]

        (air)[.1e8][..00][..48]
        (air)[.1e7][..00][..80]
        (air)[.1e5][..00][.112]
        (air)[.1e3][..00][.144]
        (air)[.1e1][..00][.176]

        (air)[.1ef][..32][..32]
        (air)[.1ee][..32][..64]
        (air)[.1ed][..32][..96]
        (air)[.1ec][..32][.128]
        (air)[.1eb][..32][.160]

        (air)[.1fd][..64][..64]
        (air)[.1fc][..64][..96]
        (air)[.1fb][..64][.128]

       (air)[.1f9][..96][..80]
       (air)[.1f8][..96][.112]
   (sector_end)

   // 20x20 tree patch
    (sector)[.179]

         recursec)[.169][...0][...0] // 20x20 nogo

         (recursec)[.174][...0][...0] // wirts tree
         (recursec)[.175][...3][...5] // small tree curving left 3x3
         (recursec)[.176][...1][...7] // tree with split stem 4x4
         (recursec)[.177][...0][..12] // tree south-west of cain 3x3
         (recursec)[.178][...4][..15] //tree west of the cows

         (recursec)[.174][...5][..09] // wirts tree
         (recursec)[.178][..07][...1] //tree west of the cows
         (recursec)[.178][..10][...6] //tree west of the cows

         (recursec)[.176][..15][...2] // tree with split stem 4x4
         (recursec)[.176][..13][..10] // tree with split stem 4x4

         (recursec)[.175][..10][..15] // small tree curving left 3x3
         (recursec)[.177][..15][..16] // tree south-west of cain 3x3


   (sector_end)

   // tree collection
    (sector)[.180]

         (recursec)[.179][.110][..20]  20x20 tree patch
         (recursec)[.179][.110][..40]  20x20 tree patch
         (recursec)[.179][.112][..60]  20x20 tree patch
         (recursec)[.179][.112][..80]  20x20 tree patch
         (recursec)[.179][.112][.100]  20x20 tree patch
         (recursec)[.179][.112][.120]  20x20 tree patch

         (recursec)[.179][..67][.107]  20x20 tree patch
         (recursec)[.179][..36][.107]  20x20 tree patch

         (recursec)[.179][..10][..90]  20x20 tree patch
         (recursec)[.179][..10][.110]  20x20 tree patch

         //indviduals behid wall
         (recursec)[.175][.108][.113] // small tree curving left 3x3
         (recursec)[.174][.100][.108] // wirts tree
         (recursec)[.178][..95][.107] //tree west of the cows
         (recursec)[.176][..92][.118] // tree with split stem 4x4
         (recursec)[.178][..60][.110] //tree west of the cows
         (recursec)[.175][..98][.116] // small tree curving left 3x3
         (recursec)[.177][..88][.115] // tree south-west of cain 3x3
         (recursec)[.178][..35][..96] //tree west of the cows
         (recursec)[.176][..40][.104] // tree with split stem 4x4
         (recursec)[.176][..60][.117] // tree with split stem 4x4

         //indviduals behid upper river
         (recursec)[.178][..26][..84] //tree west of the cows
         (recursec)[.177][..22][..86] // tree south-west of cain 3x3
         (recursec)[.174][..35][..58] // wirts tree the real one
         (recursec)[.175][..37][..53] // small tree curving left 3x3
         (recursec)[.177][..51][..30] // tree south-west of cain 3x3

         //individuals south side
         (recursec)[.175][..60][..19] // small tree curving left 3x3
         (recursec)[.174][..58][..30] // wirts tree
         (recursec)[.178][..54][..40] //tree west of the cows
         (recursec)[.177][..55][..37] // tree south-west of cain 3x3

         //individuals church ground
         (recursec)[.174][..39][..78] // wirts tree    
         (recursec)[.177][..36][..87] // tree south-west of cain 3x3
         (recursec)[.176][..53][..78] // tree with split stem 4x4
         (recursec)[.174][..60][..74] // wirts tree  
         (recursec)[.176][..59][.101] // tree with split stem 4x4

         //individuals witch island
         (recursec)[.175][..98][.100] // small tree curving left 3x3
         (recursec)[.178][.104][..84] //tree west of the cows
         (recursec)[.174][..96][..82] // wirts tree
         (recursec)[.176][.103][..70] // tree with split stem 4x4
         (recursec)[.175][..99][..69] // small tree curving left 3x3
         (recursec)[.177][.101][..61] // tree south-west of cain 3x3
         (recursec)[.174][.103][..78] // wirts tree

         //individuals crypt area
         (recursec)[.175][..66][..93] // small tree curving left 3x3
         (recursec)[.178][..65][..84] //tree west of the cows
         (recursec)[.174][..70][..85] // wirts tree
         (recursec)[.176][..71][..99] // tree with split stem 4x4
         (recursec)[.178][..77][..95] //tree west of the cows
         (recursec)[.177][..80][.101] // tree south-west of cain 3x3
         (recursec)[.175][..85][..96] // small tree curving left 3x3
         (recursec)[.174][..84][.100] // wirts tree  
         (recursec)[.175][..77][..89] // small tree curving left 3x3
         (recursec)[.177][..85][..88] // tree south-west of cain 3x3
         (recursec)[.176][..69][..79] // tree with split stem 4x4
         (recursec)[.175][..74][..80] // small tree curving left 3x3
         (recursec)[.174][..84][..79] // wirts tree
         (recursec)[.177][..89][..78] // tree south-west of cain 3x3

         //individuals town area
         (recursec)[.178][..87][..74] //tree west of the cows
         (recursec)[.178][..90][..67] //tree west of the cows
         (recursec)[.174][..84][..67] // wirts tree
         (recursec)[.177][..84][..62] // tree south-west of cain 3x3
         (recursec)[.175][..73][..63] // small tree curving left 3x3
         (recursec)[.174][..68][..59] // wirts tree
         (recursec)[.174][..58][..64] // wirts tree
         (recursec)[.177][..52][..68] // tree south-west of cain 3x3
         (recursec)[.175][..44][..74] // small tree curving left 3x3
         (recursec)[.178][..38][..71] //tree west of the cows
         (recursec)[.176][..44][..68] // tree with split stem 4x4
         (recursec)[.178][..44][..61] //tree west of the cows
         (recursec)[.177][..51][..58] // tree south-west of cain 3x3
         (recursec)[.175][..48][..54] // small tree curving left 3x3
         (recursec)[.174][..54][..48] // wirts tree
         (recursec)[.176][..61][..39] // tree with split stem 4x4
         (recursec)[.177][..76][..31] // tree south-west of cain 3x3
         (recursec)[.178][..70][..42] //tree west of the cows
         (recursec)[.175][..74][..47] // small tree curving left 3x3
         (recursec)[.177][..64][..55] // tree south-west of cain 3x3
         (recursec)[.178][..59][..59] //tree west of the cows
         (recursec)[.176][..93][..50] // tree with split stem 4x4
         (recursec)[.175][.100][..42] // small tree curving left 3x3
         (recursec)[.177][..98][..30] // tree south-west of cain 3x3
         (recursec)[.175][..90][..43] // small tree curving left 3x3
   (sector_end)

   // wildgroth collection
    (sector)[.181]

         (recursec)[.171][.103][..30] // wildgroth 1x1 a
         (recursec)[.173][..78][..49] // wildgroth 2x1
         (recursec)[.172][..84][..32] // wildgroth 1x1 b
         (recursec)[.173][..68][..45] // wildgroth 2x1
         (recursec)[.171][..66][..32] // wildgroth 1x1 a
         (recursec)[.172][..51][..48] // wildgroth 1x1 b
         (recursec)[.173][..42][..44] // wildgroth 2x1
         (recursec)[.171][..41][..56] // wildgroth 1x1 a
         (recursec)[.172][..32][..58] // wildgroth 1x1 b
         (recursec)[.173][..31][..76] // wildgroth 2x1
         (recursec)[.171][..34][..79] // wildgroth 1x1 a
         (recursec)[.172][..43][..84] // wildgroth 1x1 b
         (recursec)[.173][..48][.107] // wildgroth 2x1
         (recursec)[.171][..51][.104] // wildgroth 1x1 a
         (recursec)[.172][..67][.102] // wildgroth 1x1 b
         (recursec)[.173][..84][..94] // wildgroth 2x1
         (recursec)[.171][..81][..75] // wildgroth 1x1 a
         (recursec)[.172][..81][..65] // wildgroth 1x1 b
         (recursec)[.173][.102][..57] // wildgroth 2x1
         (recursec)[.171][..99][..80] // wildgroth 1x1 a
         (recursec)[.172][.102][.104] // wildgroth 1x1 b
         (recursec)[.173][..75][..78] // wildgroth 2x1

   (sector_end)

   // nogo collection
    (sector)[.182]

         (recursec)[.169][..00][..00] // 20x20 nogo
         (recursec)[.169][..20][..00] // 20x20 nogo
         (recursec)[.169][..40][..00] // 20x20 nogo
         (recursec)[.169][..60][..00] // 20x20 nogo
         (recursec)[.169][..80][..00] // 20x20 nogo
         (recursec)[.169][.100][..00] // 20x20 nogo
         (recursec)[.169][.120][..00] // 20x20 nogo

         (recursec)[.169][..00][...9] // 20x20 nogo
         (recursec)[.169][..20][...9] // 20x20 nogo
         (recursec)[.169][..40][...9] // 20x20 nogo
         (recursec)[.169][..60][...9] // 20x20 nogo
         (recursec)[.169][..80][...9] // 20x20 nogo
         (recursec)[.169][.100][...9] // 20x20 nogo
         (recursec)[.169][.120][...9] // 20x20 nogo

         (recursec)[.169][..00][.120] // 20x20 nogo
         (recursec)[.169][..20][.120] // 20x20 nogo
         (recursec)[.169][..40][.120] // 20x20 nogo
         (recursec)[.169][..60][.120] // 20x20 nogo
         (recursec)[.169][..80][.120] // 20x20 nogo
         (recursec)[.169][.100][.120] // 20x20 nogo
         (recursec)[.169][.120][.120] // 20x20 nogo

         (recursec)[.169][..00][.106] // 20x20 nogo
         (recursec)[.169][..20][.106] // 20x20 nogo
         (recursec)[.169][..40][.106] // 20x20 nogo
         (recursec)[.169][..60][.106] // 20x20 nogo
         (recursec)[.169][..80][.106] // 20x20 nogo
         (recursec)[.169][.100][.106] // 20x20 nogo
         (recursec)[.169][.120][.106] // 20x20 nogo

         (recursec)[.169][..00][..20] // 20x20 nogo
         (recursec)[.169][..00][..40] // 20x20 nogo
         (recursec)[.169][..00][..60] // 20x20 nogo
         (recursec)[.169][..00][..80] // 20x20 nogo
         (recursec)[.169][..00][.100] // 20x20 nogo

         (recursec)[.169][..10][..20] // 20x20 nogo
         (recursec)[.169][..10][..40] // 20x20 nogo
         (recursec)[.169][..10][..60] // 20x20 nogo
         (recursec)[.169][..10][..80] // 20x20 nogo
         (recursec)[.169][..10][.100] // 20x20 nogo

         (recursec)[.169][.120][..20] // 20x20 nogo
         (recursec)[.169][.120][..40] // 20x20 nogo
         (recursec)[.169][.120][..60] // 20x20 nogo
         (recursec)[.169][.120][..80] // 20x20 nogo
         (recursec)[.169][.120][.100] // 20x20 nogo

         (recursec)[.169][.110][..20] // 20x20 nogo
         (recursec)[.169][.110][..40] // 20x20 nogo
         (recursec)[.169][.110][..60] // 20x20 nogo
         (recursec)[.169][.110][..80] // 20x20 nogo
         (recursec)[.169][.110][.100] // 20x20 nogo

         (recursec)[.169][..30][..94] // 20x20 nogo

         (recursec)[.168][..30][..29] // 10x10 nogo
         (recursec)[.168][..30][..39] // 10x10 nogo
         (recursec)[.168][..40][..29] // 10x10 nogo

         (recursec)[.167][..30][..82] // 5x5 nogo
         (recursec)[.167][..29][..87] // 5x5 nogo
         (recursec)[.167][..29][..92] // 5x5 nogo
         (recursec)[.167][..30][..70] // 5x5 nogo
         (recursec)[.167][..30][..75] // 5x5 nogo
         (recursec)[.167][..30][..49] // 5x5 nogo
         (recursec)[.167][..50][..29] // 5x5 nogo
         (recursec)[.167][..48][..34] // 5x5 nogo
         (recursec)[.167][..45][..38] // 5x5 nogo
         (recursec)[.167][.107][..29] // 5x5 nogo
         (recursec)[.167][.108][..40] // 5x5 nogo
         (recursec)[.167][.105][..45] // 5x5 nogo
         (recursec)[.167][.104][..50] // 5x5 nogo
         (recursec)[.167][.109][..50] // 5x5 nogo
         (recursec)[.167][.105][..55] // 5x5 nogo
         (recursec)[.167][.108][..60] // 5x5 nogo

         (recursec)[.183][..40][..39] // 3x3 nogo
         (recursec)[.183][..54][..28] // 3x3 nogo
         (recursec)[.183][..52][..33] // 3x3 nogo
         (recursec)[.183][..49][..38] // 3x3 nogo
         (recursec)[.183][..30][..60] // 3x3 nogo
         (recursec)[.183][..34][..70] // 3x3 nogo
         (recursec)[.183][..31][..80] // 3x3 nogo
         (recursec)[.183][..62][..29] // 3x3 nogo
         (recursec)[.183][..80][..28] // 3x3 nogo
         (recursec)[.183][..91][..28] // 3x3 nogo
         (recursec)[.183][.108][..34] // 3x3 nogo

   (sector_end)

   //3x3 nogo tiles
    (sector)[.183]
     (tile)[...0][...0] (move)[none]
     (tile)[...1][...0] (move)[none]
     (tile)[...2][...0] (move)[none]

     (tile)[...0][...1] (move)[none]
     (tile)[...1][...1] (move)[none]
     (tile)[...2][...1] (move)[none]

     (tile)[...0][...2] (move)[none]
     (tile)[...1][...2] (move)[none]
     (tile)[...2][...2] (move)[none]

   (sector_end)

   //8x8 patch of empty grass
    (sector)[.184]
      (recursec)[..50][...0][...0] // 4x4 grass
      (recursec)[..50][...4][...0] // 4x4 grass
      (recursec)[..50][...0][...4] // 4x4 grass
      (recursec)[..50][...4][...4] // 4x4 grass
   (sector_end)

   //16x16 patch of empty grass
    (sector)[.185]
      (recursec)[.184][...0][...0] // 8x8 grass
      (recursec)[.184][...8][...0] // 8x8 grass
      (recursec)[.184][...0][...8] // 8x8 grass
      (recursec)[.184][...8][...8] // 8x8 grass
   (sector_end)

   //32x32 patch of empty grass
    (sector)[.186]
      (recursec)[.185][...0][...0] // 16x16 grass
      (recursec)[.185][..16][...0] // 16x16 grass
      (recursec)[.185][...0][..16] // 16x16 grass
      (recursec)[.185][..16][..16] // 16x16 grass
   (sector_end)

   //full cover patch of empty grass
    (sector)[.187]
      (recursec)[.186][...0][...0] // 32x32 grass
      (recursec)[.186][..32][...0] // 32x32 grass
      (recursec)[.186][..64][...0] // 32x32 grass
      (recursec)[.186][..96][...0] // 32x32 grass
      (recursec)[.186][.128][...0] // 32x32 grass

      (recursec)[.186][...0][..32] // 32x32 grass
      (recursec)[.186][..32][..32] // 32x32 grass
      (recursec)[.186][..64][..32] // 32x32 grass
      (recursec)[.186][..96][..32] // 32x32 grass
      (recursec)[.186][.128][..32] // 32x32 grass

      (recursec)[.186][...0][..64] // 32x32 grass
      (recursec)[.186][..32][..64] // 32x32 grass
      (recursec)[.186][..64][..64] // 32x32 grass
      (recursec)[.186][..96][..64] // 32x32 grass
      (recursec)[.186][.128][..64] // 32x32 grass

      (recursec)[.186][...0][..96] // 32x32 grass
      (recursec)[.186][..32][..96] // 32x32 grass
      (recursec)[.186][..64][..96] // 32x32 grass
      (recursec)[.186][..96][..96] // 32x32 grass
      (recursec)[.186][.128][..96] // 32x32 grass

      (recursec)[.186][...0][.128] // 32x32 grass
      (recursec)[.186][..32][.128] // 32x32 grass
      (recursec)[.186][..64][.128] // 32x32 grass
      (recursec)[.186][..96][.128] // 32x32 grass
      (recursec)[.186][.128][.128] // 32x32 grass
   (sector_end)

(end)
****************************
<datablock_end>
****************************

<end>
****************************
