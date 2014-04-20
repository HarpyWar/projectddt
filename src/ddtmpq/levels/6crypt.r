 
<begin>

<datablock>[....][level]

(sectors)[.200] 


// test level
(sector)[...0]

  (tile)[...2][...0] (mech)[..12][+] //up to test hive
  (tile)[...0][...2] (mech)[...2][+] //up tp town

(sector_end)

// crypt1
(sector)[...1]

  (tile)[...2][...0] (mech)[..54][+] //up to town
  (tile)[...0][...2] (mech)[..55][+] //down to crypt2

  (tile)[...4][...4] (mech)[.100][-] // audio book Blog: Say hi
  (tile)[...6][...6] (mech)[.105][-] //audio book Rock of the Planet



(sector_end)

// crypt2
(sector)[...2]

  (tile)[...2][...0] (mech)[..56][+] //up to crypt1
  (tile)[...0][...2] (mech)[..57][+] //down to crypt3

  (tile)[...4][...4] (mech)[.101][-] //audio book Blog: Become popular
  (tile)[...6][...6] (mech)[.102][-] //audio book Blog: The Drama

(sector_end)

// crypt3
(sector)[...3]

  (tile)[...2][...0] (mech)[..58][+] //up to crypt2
  (tile)[...0][...2] (mech)[..59][+] //down to crypt4

  (tile)[...4][...4] (mech)[.103][-] //audio book Blog: Name and Shame
  (tile)[...6][...6] (mech)[.104][-] //audio book Blog: Last post

(sector_end)

// crypt4
(sector)[...4]

  (tile)[...2][...0] (mech)[..60][+] //up to crypt3

  (tile)[...6][...6] (mech)[.106][-] //audio book A Blog entry "i.s.s."
  (tile)[...6][...8] (mech)[.107][-] //audio book A Blog entry "p.o"
  (tile)[...6][..10] (mech)[.108][-] //audio book A Blog entry "e.o.u.i."


(sector_end)





(end)
****************************
<datablock_end>
****************************

<end>
**********