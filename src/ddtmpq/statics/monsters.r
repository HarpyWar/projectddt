<begin> 

************************************
***SPECIAL**************************
************************************



***player***********************

<mpqset>[diabdat.mpq]
<pakset>[...1]
<pakinit_vid>[...8] <pakinit_aud>[...4]
<sfx>[...0][sfx\misc\walk1.wav]
<sfx>[...1][sfx\misc\walk2.wav]
<sfx>[...2][sfx\misc\walk3.wav]
<sfx>[...3][sfx\misc\walk4.wav]


<datablock>[...0][monster]
   (name)[Player]
   (pakref)[...1][...1]
   (clean_own_paks)[...0][...0]
   (ani_direction)[true]
   (animation)[...0][...1][...2][...3][...4][...5][...6][...7]
   (height)[...0]
   (stepsounds)[...0][...3]
   (savable)[...0]

   (loadme)   ...   (loadme_end)

<datablock_end>


************************************
***TOWNERS**************************
************************************

***animal***********************

<datablock>[...1][monster]
   (blob_name)[...6][(gol)]
   (pakref)[...2][...2]
   (ani_direction)[true]
   (height)[...1]
   (animation)[...0][...0][...0][...0][...0][...0][...0][...0]
   (height)[...2]
   (interaction_ref)[...0] // MONSTER_INTERACTION_REF_ANIMAL

   (loadme)
      <begin>
      <pakset>[...2]
      <pakinit_vid>[...1] <pakinit_aud>[...2] //tex, aud 1,2
      <mpqset>[diabdat.mpq]
      <grfx>[...0][dcel][.128][.128][..12][auto][auto][auto][auto][-.10][towners\animals\cow.cel]
      <sfx>[...0][sfx\towners\Cow1.wav]
      <sfx>[...1][sfx\towners\Cow2.wav]
      <end>
   (loadme_end)

<datablock_end>

******smith********************

<datablock>[...2][monster]
   (blob_name)[...9][(whi)]
   (pakref)[...3][...3]
   (ani_direction)[false]
   (animation)[...0][...0][...0][...0][...0][...0][...0][...0]
   (height)[...2]

   (loadme)
      <begin>
      <pakset>[...3]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][...0][towners\smith\smithn.cel]
      <end>
   (loadme_end)

<datablock_end>

***addict********************

<datablock>[...3][monster]
   (blob_name)[...7][(whi)]
   (pakref)[...4][...4]
   (ani_direction)[false]
   (animation)[...0][...0][...0][...0][...0][...0][...0][...0]
   (height)[...1]

   (loadme)
      <begin>
      <pakset>[...4]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][...0][towners\drunk\twndrunk.cel]
      <end>
   (loadme_end)

<datablock_end>

***doctor***********************

<datablock>[...4][monster]
    (blob_name)[..12][(whi)]
    (pakref)[...5][...5]
    (ani_direction)[false]
    (animation)[...0][...0][...0][...0][...0][...0][...0][...0]
    (height)[...2]

   (loadme)
      <begin>
      <pakset>[...5]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][...0][towners\healer\healer.cel]
      <end>
   (loadme_end)

<datablock_end>

***elder*************************

<datablock>[...5][monster]
    (blob_name)[..14][(whi)]
    (pakref)[...6][...6]
    (ani_direction)[false]
    (animation)[...0][...0][...0][...0][...0][...0][...0][...0]
    (height)[...2]

   (loadme)
      <begin>
      <pakset>[...6]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][...0][towners\strytell\strytell.cel]
      <end>
   (loadme_end)

<datablock_end>

***hotel owner**********************

<datablock>[...6][monster]
   (blob_name)[..11][(whi)]
   (pakref)[...7][...7]
   (ani_direction)[false]
   (animation)[...0][...0][...0][...0][...0][...0][...0][...0]
   (height)[...2]

   (loadme)
      <begin>
      <pakset>[...7]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][...0][towners\twnf\twnfn.cel]
      <end>
   (loadme_end)

<datablock_end>

***waitresss**********************

<datablock>[...7][monster]
   (blob_name)[..08][(whi)]
   (pakref)[...8][...8]
   (ani_direction)[false]
   (animation)[...0][...0][...0][...0][...0][...0][...0][...0]
   (height)[...2]

   (loadme)
      <begin>
      <pakset>[...8]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][...0][towners\townwmn1\wmnn.cel]
      <end>
   (loadme_end)

<datablock_end>

***profiteer*************************

<datablock>[...8][monster]
   (blob_name)[..15][(whi)]
   (pakref)[...9][...9]
   (ani_direction)[false]
   (animation)[...0][...0][...0][...0][...0][...0][...0][...0]
   (height)[...2]
   (interaction_ref)[...1] // MONSTER_INTERACTION_REF_GOLDGIVER 1

   (loadme)
      <begin>
      <pakset>[...9]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..64][..12][auto][auto][auto][auto][...0][towners\townboy\pegkid1.cel]
      <end>
   (loadme_end)

<datablock_end>

***scary lady************************

<datablock>[...9][monster]
   (blob_name)[..02][(whi)]
   (pakref)[..10][..10]
   (ani_direction)[false]
   (animation)[...0][...0][...0][...0][...0][...0][...0][...0]
   (height)[...2]

   (loadme)
      <begin>
      <pakset>[..10]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][auto][...0][towners\townwmn1\witch.cel]
      <end>
   (loadme_end)

<datablock_end>

***deadguy**********************

<datablock>[..10][monster]
   (blob_name)[..16][(whi)]
   (pakref)[..11][..11]
   (ani_direction)[false]
   (animation)[...0][...0][...0][...0][...0][...0][...0][...0]
   (height)[...1]
   (savable)[...0]

   (loadme)
      <begin>
      <pakset>[..11]
      <pakinit_vid>[...1] <pakinit_aud>[...0] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[...0][town][..96][..96][..12][auto][auto][auto][-..7][-..5][towners\butch\deadguy.cel]
      <end>
   (loadme_end)

<datablock_end>



************************************
***HELL*****************************
************************************

***Big Daddy************************



<datablock>[..50][monster]
   (blob_name)[.400][(gol)]
   (pakref)[..50][..50]
   (ani_direction)[true]
            // stnd  walk  atta  fcst  lcst  bcst  htrc  deth
   (animation)[...0][...1][...0][...2][...3][...3][...4][...5]
   (height)[...3]
   (savable)[...1]
   (brains)[...1]
   (loadme)
      <begin>
      <pakset>[..50]
      <pakinit_vid>[...6] <pakinit_aud>[...8] //tex, aud
      <mpqset>[diabdat.mpq]
      <grfx>[..00][dcl2][.160][.160][..12][auto][auto][auto][auto][...0][monsters\diablo\diablon.cl2] //idle+attack
      <grfx>[..01][dcl2][.160][.160][..12][auto][auto][auto][auto][...0][monsters\diablo\diablow.cl2] //walk
      <grfx>[..02][dcl2][.160][.160][..12][auto][auto][auto][auto][...0][monsters\diablo\diabloa.cl2] //cast a
      <grfx>[..03][dcl2][.160][.160][..12][auto][auto][auto][auto][...0][monsters\diablo\diablos.cl2] //cast b
      <grfx>[..04][dcl2][.160][.160][..12][auto][auto][auto][auto][...0][monsters\diablo\diabloh.cl2] //hitrec
      <grfx>[..05][dcl2][.160][.160][..12][auto][auto][auto][auto][...0][monsters\diablo\diablod.cl2] //death
      <end>
   (loadme_end)

<datablock_end>



<end> 


