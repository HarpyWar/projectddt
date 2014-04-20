<begin>



***stash*************************
<datablock>[...0][mechanic]
   (pakref)[.500][.500]
   (name)[(whi)Stash]
   (height)[...1]
   (interaction_ref)[...0] // MECHANIC_INTERACTION_REF_STASH 0
   (open_closed_grfx)[...0][...3][...0][...3]
   (loadme)
      <begin>
      <pakset>[.500]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\chest3.cel]
      <end>
   (loadme_end)
<datablock_end>


***Test level warps****************************************************************************
***********************************************************************************************
***Warp Tristram - Test Chruch ***
<datablock>[...1][mechanic]
   (name)[(whi)Down to Test church]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[...2] 
   (dungeon_ref)[..31]
   (loadref)[ddtmpq?bgs?wait_quote.r]
<datablock_end>

<datablock>[...2][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.701]
   (name_ap)[ yeey!]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[...1] 
   (dungeon_ref)[...0] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_0up.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Test Chruch- Test Cat ***
<datablock>[...3][mechanic]
   (name)[(whi)Down to Test Catacombs]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[...4] 
   (dungeon_ref)[..32] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_1dwn.r]
<datablock_end>

<datablock>[...4][mechanic]
   (name)[(whi)Up to Test Church]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[...3]
   (dungeon_ref)[..31] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Test Cat - Test Caves ***
<datablock>[...5][mechanic]
   (name)[(whi)Down to Test Caves]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[...6]
   (dungeon_ref)[..33] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]
<datablock_end>

<datablock>[...6][mechanic]
   (name)[(whi)Up to Test Cat]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[...5] 
   (dungeon_ref)[..32] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Test Caves - Test Hell***
<datablock>[...7][mechanic]
   (name)[(whi)Down to Test Hell]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[...8] 
   (dungeon_ref)[..34] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
<datablock_end>

<datablock>[...8][mechanic]
   (name)[(whi)Up to Test Caves]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[...7] 
   (dungeon_ref)[..33] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Test Hell - Test hive***
<datablock>[...9][mechanic]
   (name)[(whi)Down to Test hive]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..10] 
   (dungeon_ref)[..35] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_4dwn.r]
<datablock_end>

<datablock>[..10][mechanic]
   (name)[(whi)Up to Test Hell]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[...9] 
   (dungeon_ref)[..34] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_4dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Test hive - Test Crypt***
<datablock>[..11][mechanic]
   (name)[(whi)Down to Test Crypt]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..12]
   (dungeon_ref)[..36] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_5dwn.r]
<datablock_end>

<datablock>[..12][mechanic]
   (name)[(whi)Up to Test Hive]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..11] 
   (dungeon_ref)[..35] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_5dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Level warps*********************************************************************************
***********************************************************************************************
***Warp Town - Lev 1 ***
<datablock>[..13][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.702]
   (height)[...3]
   (interaction_ref)[...1]
   (ref_other)[..14] 
   (dungeon_ref)[...1]
   (loadref)[ddtmpq?bgs?wait_0dwn.r] 
<datablock_end>

<datablock>[..14][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.701]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..13] 
   (dungeon_ref)[...0] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_0dwn.r] 
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 1 - lev 2 ***
<datablock>[..15][mechanic]
   (name)[(whi)Down to Level 2]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..16] 
   (dungeon_ref)[..02]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
     (loadref)[ddtmpq?bgs?wait_1dwn.r]
<datablock_end>

<datablock>[..16][mechanic]
   (name)[(whi)Up to Level 1]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..15] 
   (dungeon_ref)[...1] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_1dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 2 - level 3 ***
<datablock>[..17][mechanic]
   (name)[(whi)Down to Level 3]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..18] 
   (dungeon_ref)[..03]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_1dwn.r]  
<datablock_end>

<datablock>[..18][mechanic]
   (name)[(whi)Up to Level 2]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..17] 
   (dungeon_ref)[...2] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_1dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 3 - level 4 ***
<datablock>[..19][mechanic]
   (name)[(whi)Down to Level 4]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..20] 
   (dungeon_ref)[..04] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_1dwn.r] 
<datablock_end>

<datablock>[..20][mechanic]
   (name)[(whi)Up to Level 3]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..19]
   (dungeon_ref)[...3] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_1dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 4 - level 5 ***
<datablock>[..21][mechanic]
   (name)[(whi)Down to Level 5]
   (height)[...3]
   (interaction_ref)[...1]
   (ref_other)[..22] 
   (dungeon_ref)[..05]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_1dwn.r]  
<datablock_end>

<datablock>[..22][mechanic]
   (name)[(whi)Up to Level 4]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..21] 
   (dungeon_ref)[...4] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_1dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 5 - level 6 ***
<datablock>[..23][mechanic]
   (name)[(whi)Down to Level 6]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..24] 
   (dungeon_ref)[..06]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]  
<datablock_end>

<datablock>[..24][mechanic]
   (name)[(whi)Up to Level 5]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..23] 
   (dungeon_ref)[...5] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 6 - level 7 ***
<datablock>[..25][mechanic]
   (name)[(whi)Down to Level 7]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..26] 
   (dungeon_ref)[..07]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]  
<datablock_end>

<datablock>[..26][mechanic]
   (name)[(whi)Up to Level 6]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..25] 
   (dungeon_ref)[...6] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>


***Warp Lev 7 - level 8 ***
<datablock>[..27][mechanic]
   (name)[(whi)Down to Level 8]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..28] 
   (dungeon_ref)[..08]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]  
<datablock_end>

<datablock>[..28][mechanic]
   (name)[(whi)Up to Level 7]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..27] 
   (dungeon_ref)[...7] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 8 - level 9 ***
<datablock>[..29][mechanic]
   (name)[(whi)Down to Level 9]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..30] 
   (dungeon_ref)[..09]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]  
<datablock_end>

<datablock>[..30][mechanic]
   (name)[(whi)Up to Level 8]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..29] 
   (dungeon_ref)[...8] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 9 - level 10 ***
<datablock>[..31][mechanic]
   (name)[(whi)Down to Level 10]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..32] 
   (dungeon_ref)[..10]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]  
<datablock_end>

<datablock>[..32][mechanic]
   (name)[(whi)Up to Level 9]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..31] 
   (dungeon_ref)[...9] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 10 - level 11 ***
<datablock>[..33][mechanic]
   (name)[(whi)Down to Level 11]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..34] 
   (dungeon_ref)[..11]
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]  
<datablock_end>

<datablock>[..34][mechanic]
   (name)[(whi)Up to Level 10]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..33] 
   (dungeon_ref)[..10] 
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 11 - level 12 ***
<datablock>[..35][mechanic]
   (name)[(whi)Down to Level 12]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..36] 
   (dungeon_ref)[..12]
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]  
<datablock_end>

<datablock>[..36][mechanic]
   (name)[(whi)Up to Level 11]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..35]
   (dungeon_ref)[..11] 
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 12 - level 13 ***
<datablock>[..37][mechanic]
   (name)[(whi)Down to Level 13]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..38] 
   (dungeon_ref)[..13]
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]  
<datablock_end>

<datablock>[..38][mechanic]
   (name)[(whi)Up to Level 12]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..37] 
   (dungeon_ref)[..12] 
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 13 - level 14 ***
<datablock>[..39][mechanic]
   (name)[(whi)Down to Level 14]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..40] 
   (dungeon_ref)[..14]
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_4dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]  
<datablock_end>

<datablock>[..40][mechanic]
   (name)[(whi)Up to Level 13]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..39] 
   (dungeon_ref)[..13] 
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_4dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Lev 14 - level 15 ***
<datablock>[..41][mechanic]
   (name)[(whi)Down to Level 15]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..42] 
   (dungeon_ref)[..15]
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_4dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]  
<datablock_end>

<datablock>[..42][mechanic]
   (name)[(whi)Up to Level 14]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..41] 
   (dungeon_ref)[..14] 
   (loadref)[ddtmpq?bgs?wait_4dwn.r]


<datablock_end>

***Warp Lev 15 - level 16 ***
<datablock>[..43][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.708]
   (height)[...1]
   (interaction_ref)[...1] 
   (ref_other)[..44] 
   (dungeon_ref)[..16]
   (loadref)[ddtmpq?bgs?wait_diab.r]
<datablock_end>

<datablock>[..44][mechanic]
   (name)[(whi)Up to Level 15]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..43]
   (dungeon_ref)[..15]
   (loadref)[ddtmpq?bgs?wait_4dwn.r] 
<datablock_end>




***Warp Town - Bugs1 ***
<datablock>[..45][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.706]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..46] 
   (dungeon_ref)[..21]
   (loadref)[ddtmpq?bgs?wait_5dwn.r]
<datablock_end>

<datablock>[..46][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.701]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..45] 
   (dungeon_ref)[...0] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_0up.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Bugs1 - Bugs2 ***
<datablock>[..47][mechanic]
   (name)[(whi)Down to Level 2]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..48] 
   (dungeon_ref)[..22]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_5dwn.r]  
<datablock_end>

<datablock>[..48][mechanic]
   (name)[(whi)Up to Level 1]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..47] 
   (dungeon_ref)[..21]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_5dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Bugs2 - Bugs3 ***
<datablock>[..49][mechanic]
   (name)[(whi)Down to Level 3]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..50] 
   (dungeon_ref)[..23]
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_5dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]  
<datablock_end>

<datablock>[..50][mechanic]
   (name)[(whi)Up to Level 2]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..49] 
   (dungeon_ref)[..22] 
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_5dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Warp Bugs3 - Bugs4 ***
<datablock>[..51][mechanic]
   (name)[(whi)Down to Level 4]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..52] 
   (dungeon_ref)[..24]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_5dwn.r]  
<datablock_end>

<datablock>[..52][mechanic]
   (name)[(whi)Up to Level 3]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..51] 
   (dungeon_ref)[..23] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_5dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>



***Warp Town - Grave1 ***
<datablock>[..53][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.707]
   (height)[...1]
   (interaction_ref)[...1] 
   (ref_other)[..54] 
   (dungeon_ref)[..25]
   (loadref)[ddtmpq?bgs?wait_6dwn.r]
<datablock_end>

<datablock>[..54][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.701]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..53] 
   (dungeon_ref)[...0] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_0up.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Grave1 - Grave2 ***
<datablock>[..55][mechanic]
   (name)[(whi)Down to Level 2]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..56] 
   (dungeon_ref)[..26]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_6dwn.r]
<datablock_end>

<datablock>[..56][mechanic]
   (name)[(whi)Up to Level 1]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..55] 
   (dungeon_ref)[..25] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_6dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Grave2 - Grave3 ***
<datablock>[..57][mechanic]
   (name)[(whi)Down to Level 3]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..58] 
   (dungeon_ref)[..27]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_6dwn.r]
<datablock_end>

<datablock>[..58][mechanic]
   (name)[(whi)Up to Level 2]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..57] 
   (dungeon_ref)[..26] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_6dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Grave3 - Grave4 ***
<datablock>[..59][mechanic]
   (name)[(whi)Down to Level 4]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..60] 
   (dungeon_ref)[..28]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_6dwn.r]
<datablock_end>

<datablock>[..60][mechanic]
   (name)[(whi)Up to Level 3]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..59] 
   (dungeon_ref)[..27] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_6dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>


***Lev2 - Stinky ***
<datablock>[..61][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.709]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..62] 
   (dungeon_ref)[..20]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
<datablock_end>

<datablock>[..62][mechanic]
   (name)[(whi)To level 2]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..61] 
   (dungeon_ref)[...2] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Lev3 - Archmed ***
<datablock>[..63][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.710]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..64] 
   (dungeon_ref)[..19]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_1dwn.r]
<datablock_end>

<datablock>[..64][mechanic]
   (name)[(whi)To level 3]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..63] 
   (dungeon_ref)[...3] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_1dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Lev6 - Dogfood ***
<datablock>[..65][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.711]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..66] 
   (dungeon_ref)[..18]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]
<datablock_end>

<datablock>[..66][mechanic]
   (name)[To level 6]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..65] 
   (dungeon_ref)[...6] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Lev15 - Arnie ***
<datablock>[..67][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.712]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..68] 
   (dungeon_ref)[..17]
   (pakref)[.505][.505]
   (open_closed_grfx)[-..0][-.66][...0][-.66] //idele animated
   (loadref)[ddtmpq?bgs?wait_redp.r]
   (loadme)
      <begin>
      <pakset>[.505]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][icl2][..96][.128][..12][auto][auto][auto][auto][..00][missiles\rportal2.cl2]
      <end>
   (loadme_end)
<datablock_end>

// silent reciever, should remove grfx here later
<datablock>[..68][mechanic]
   (height)[...0]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Town - Lev5 cat shortcut ***
<datablock>[..69][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.703]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..70] 
   (dungeon_ref)[..05]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_2dwn.r]
<datablock_end>

<datablock>[..70][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.701]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..69] 
   (dungeon_ref)[..00] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_0up.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Town - Lev9 caves shortcut ***
<datablock>[..71][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.704]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..72] 
   (dungeon_ref)[..09]
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_3dwn.r]
<datablock_end>

<datablock>[..72][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.701]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..71] 
   (dungeon_ref)[..00] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_0up.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Town - Lev13 Hell shortcut ***
<datablock>[..73][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.705]
   (height)[...1]
   (interaction_ref)[...1] 
   (ref_other)[..74] 
   (dungeon_ref)[..13]
   (pakref)[.501][.501]
   (loadref)[ddtmpq?bgs?wait_4dwn.r]
   (open_closed_grfx)[...0][...0][...0][...0]  
<datablock_end>

<datablock>[..74][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.701]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..73] 
   (dungeon_ref)[..00] 
   (pakref)[.501][.501]
   (open_closed_grfx)[...0][...0][...0][...0]
   (loadref)[ddtmpq?bgs?wait_0up.r]
   (loadme)
      <begin>
      <pakset>[.501]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][-.16][objects\mcirl.cel]
      <end>
   (loadme_end)
<datablock_end>

***Arnie - Level 15 ***
<datablock>[..75][mechanic]
   (name)[(whi)To level 15]
   (height)[...3]
   (interaction_ref)[...1] 
   (ref_other)[..67] 
   (dungeon_ref)[..15] 
   (pakref)[.505][.505]
   (open_closed_grfx)[-..0][-.66][...0][-.66] //idele animated
   (loadref)[ddtmpq?bgs?wait_redp.r]
   (loadme)
      <begin>
      <pakset>[.505]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][icl2][..96][.128][..12][auto][auto][auto][auto][..00][missiles\rportal2.cl2]
      <end>
   (loadme_end)
<datablock_end>


***Slack space*********************************************************************************
***********************************************************************************************



***Audio Books*********************************************************************************
***********************************************************************************************

// Blog: Say hi
<datablock>[.100][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.140]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?blog0hi.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[hellfire.mpq]
      <grfx>[...0][town][..96][..96][.192][auto][auto][auto][auto][..00][objects\l5books.cel]
      <mpqset>[diabdat.mpq] <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// Blog: Become popular
<datablock>[.101][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.141]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?blog2popi.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[hellfire.mpq]
      <grfx>[...0][town][..96][..96][.192][auto][auto][auto][auto][..00][objects\l5books.cel]
      <mpqset>[diabdat.mpq] <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// Blog: The Drama
<datablock>[.102][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.142]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?blog1drama.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[hellfire.mpq]
      <grfx>[...0][town][..96][..96][.192][auto][auto][auto][auto][..00][objects\l5books.cel]
      <mpqset>[diabdat.mpq] <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// Blog: Name and Shame
<datablock>[.103][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.143]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?blog3name.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[hellfire.mpq]
      <grfx>[...0][town][..96][..96][.192][auto][auto][auto][auto][..00][objects\l5books.cel]
      <mpqset>[diabdat.mpq] <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// Blog: Last post
<datablock>[.104][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.144]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?blog4last.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[hellfire.mpq]
      <grfx>[...0][town][..96][..96][.192][auto][auto][auto][auto][..00][objects\l5books.cel]
      <mpqset>[diabdat.mpq] <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// Rock of the Planet
<datablock>[.105][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.147]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?rockofworld.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[hellfire.mpq]
      <grfx>[...0][town][..96][..96][.192][auto][auto][auto][auto][..00][objects\l5books.cel]
      <mpqset>[diabdat.mpq] <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// A Blog entry "i.s.s."
<datablock>[.106][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.146]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?latin0iss.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[hellfire.mpq]
      <grfx>[...0][town][..96][..96][.192][auto][auto][auto][auto][..00][objects\l5books.cel]
      <mpqset>[diabdat.mpq] <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// A Blog entry "p.o"
<datablock>[.107][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.146]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?latin1po.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[hellfire.mpq]
      <grfx>[...0][town][..96][..96][.192][auto][auto][auto][auto][..00][objects\l5books.cel]
      <mpqset>[diabdat.mpq] <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// A Blog entry "e.o.u.i."
<datablock>[.108][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.146]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?latin2eoui.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[hellfire.mpq]
      <grfx>[...0][town][..96][..96][.192][auto][auto][auto][auto][..00][objects\l5books.cel]
      <mpqset>[diabdat.mpq] <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// The Big Fight
<datablock>[.109][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.100]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?csgang0bigfight.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>


 // War is a racket
<datablock>[.110][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.101]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...3][...0][...2]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?csgang1racket.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// Tell about yourself
<datablock>[.111][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.102]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...5][...0][...4]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?csgang2ourselfs.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// Racist expulsion
<datablock>[.112][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.120]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?demon0expultion.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// The vice fight
<datablock>[.113][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.121]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...3][...0][...2]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?demon1vicefight.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// 3-combo
<datablock>[.114][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.122]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...5][...0][...4]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?demon2combo3.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>


// Other worlds
<datablock>[.115][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.110]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?arnie0otherworld.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// Not 1 not 2...
<datablock>[.116][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.111]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...3][...0][...2]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?arnie1not1not2.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// The dark ruler
<datablock>[.117][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.112]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...5][...0][...4]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?arnie2darkruler.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>


// Old tales book Dogfood quest
<datablock>[.118][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.131]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...1][...0][...0]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?class0dogfood.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// Book of Liquid, mythical strength of spirit
<datablock>[.119][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.130]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...3][...0][...2]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?class1spiritstr.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// Book for visually handicapped, blind quest
<datablock>[.120][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.132]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...5][...0][...4]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?class2blind.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

// Metal paperback, red admiral quest
<datablock>[.121][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.133]
   (height)[...2]
   (pakref)[.502][.502]
   (open_closed_grfx)[...0][...5][...0][...4]
   (interaction_ref)[...2]
   (loadref)[ddtmpq?events?book?class3redadmir.r]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.502]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\bkslbrnt.cel]
      <sfx>[...0][sfx\items\invscrol.wav]
      <end>
   (loadme_end)
<datablock_end>

***Slack space*********************************************************************************
***********************************************************************************************



***Levers**************************************************************************************
***********************************************************************************************

// Dummy bony lever
<datablock>[.125][mechanic]
   (open_closed_grfx)[...0][...0][...0][...0]
   (pakref)[.503][.503]
   (savable)[...1]
   (loadme)
      <begin>
      <pakset>[.503]
      <pakinit_vid>[...1] <pakinit_aud>[...1] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][..00][objects\switch4.cel]
      <sfx>[...0][sfx\items\lever.wav]
      <end>
   (loadme_end)
<datablock_end>

// Big Ds lever chain first
<datablock>[.126][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.401]
   (height)[...2]
   (pakref)[.503][.503]
   (open_closed_grfx)[...0][...1][...0][...0]
   (clean_own_paks)[...0][...0]
   (interaction_ref)[...3] //MECHANIC_INTERACTION_REF_LEVER
   (ref_other)[.400] //sectorfix ref 
   (loadref)[A room has opened ...]
   (savable)[...1]
<datablock_end>

// Big Ds lever chain 2nd
<datablock>[.127][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.401]
   (height)[...2]
   (pakref)[.503][.503]
   (open_closed_grfx)[...0][...1][...0][...0]
   (clean_own_paks)[...0][...0]
   (interaction_ref)[...3]
   (ref_other)[.401] //sectorfix ref 
   (loadref)[A room has opened ...]
   (savable)[...1]
<datablock_end>

// Big Ds lever chain 3rd a
<datablock>[.128][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.401]
   (height)[...2]
   (pakref)[.503][.503]
   (open_closed_grfx)[...0][...1][...0][...0]
   (clean_own_paks)[...0][...0]
   (interaction_ref)[...3]
   (ref_other)[.402] //sectorfix ref 
   (loadref)[One more ...]
   (savable)[...1]
<datablock_end>

// Big Ds lever chain 3rd b
<datablock>[.129][mechanic]
   (name)[(whi)]
   (blob_name_ap)[.401]
   (height)[...2]
   (pakref)[.503][.503]
   (open_closed_grfx)[...0][...1][...0][...0]
   (clean_own_paks)[...0][...0]
   (interaction_ref)[...3]
   (ref_other)[.403] //sectorfix ref 
   (loadref)[One more ...]
   (savable)[...1]
<datablock_end>

// Big Ds lever chain final
<datablock>[.130][mechanic]
   (name)[(whi)Final ]
   (blob_name_ap)[.401]
   (height)[...2]
   (pakref)[.503][.503]
   (open_closed_grfx)[...0][...1][...0][...0]
   (clean_own_paks)[...0][...0]
   (interaction_ref)[...3]
   (ref_other)[.404] //sectorfix ref 
   (savable)[...1]
<datablock_end>



***Slack space*********************************************************************************
***********************************************************************************************



***Target Dummies******************************************************************************
***********************************************************************************************


// Dummy a
<datablock>[.150][mechanic] (savable)[...1] <datablock_end>
// Dummy b
<datablock>[.151][mechanic] (savable)[...1] <datablock_end>
// Dummy c
<datablock>[.152][mechanic] (savable)[...1] <datablock_end>
// Dummy d
<datablock>[.153][mechanic] (savable)[...1] <datablock_end>
// Dummy e
<datablock>[.154][mechanic] (savable)[...1] <datablock_end>
// Dummy f
<datablock>[.155][mechanic] (savable)[...1] <datablock_end>
// Dummy g
<datablock>[.156][mechanic] (savable)[...1] <datablock_end>
// Dummy h
<datablock>[.157][mechanic] (savable)[...1] <datablock_end>
// Dummy i
<datablock>[.158][mechanic] (savable)[...1] <datablock_end>
// Dummy j
<datablock>[.159][mechanic] (savable)[...1] <datablock_end>
// Dummy k
<datablock>[.160][mechanic] (savable)[...1] <datablock_end>
// Dummy l
<datablock>[.161][mechanic] (savable)[...1] <datablock_end>
// Dummy m
<datablock>[.162][mechanic] (savable)[...1] <datablock_end>
// Dummy n
<datablock>[.163][mechanic] (savable)[...1] <datablock_end>
// Dummy o
<datablock>[.164][mechanic] (savable)[...1] <datablock_end>



<end>


 
