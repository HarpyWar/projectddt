<begin>

<datablock>[....][level]

(sectors)[.200] 


// test level
(sector)[...0]

  (tile)[...2][...0] (mech)[..10][+] //up to test hell
  (tile)[...0][...2] (mech)[..11][+] //Down to test crypt

(sector_end)

// hive1 - 21
(sector)[...1]

  (tile)[...2][...0] (mech)[..46][+] //up to Tristram
  (tile)[...0][...2] (mech)[..47][+] //Down to hive2

(sector_end)

// hive2 - 22
(sector)[...2]

  (tile)[...2][...0] (mech)[..48][+] //up to hive1
  (tile)[...0][...2] (mech)[..49][+] //Down to hive3

(sector_end)

// hive3 - 23
(sector)[...3]

  (tile)[...2][...0] (mech)[..50][+] //up to hive2
  (tile)[...0][...2] (mech)[..51][+] //Down to hive4

(sector_end)

// hive4 - 24
(sector)[...4]

  (tile)[...2][...0] (mech)[..52][+] //up to hive3


(sector_end)



(end)
****************************
<datablock_end>
****************************

<end>
**********