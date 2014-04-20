Project DDT Alpha Zero Readme
+++++++++++++++++++++++++++++


What is this?
=============
This is an instruction file for Project DDT. The effort to bring the classic Diablo game and it's Hellfire expansion to modern computers.
Project DDT is in an 'early alpha' stage. There is no real game-play yet and there are more features missing then not.


What do I need to do?
=============
a)  Make sure your machine meets these system requirements:
-------------
- A dual-core (or better) processor form AMD or Intel.
- A somewhat recent graphics card form AMD or Nvidia, or a recent one from Intel.
Basically you could say that a new, cheap laptop is just good enough but your netbook will not pull it.

b)  Make sure that OpenGL works
-------------
- You can check this quickly by running 'glxgears'.
- In case of an AMD or Nvidia graphics chip, see if your Linux distribution installed the 'non-free' video drivers. Those usually give the best performance.


c) Make sure libSDL and (if available) the libSDL OpenGL plug-in are installed
-------------
How to make your Linux distribution install this and if you need to install the libSDL OpenGL plug-in separately varies per case.

d) Gather the following files in one directory where you have write-access:
-------------

- "ddt.lin32.run" or "ddt.lin64.run" from this installation pack.
- "ddt.mpq" from this installation pack.
- "diabdat.mpq" from the Diablo game CD. 
- "hellfire.exe" from the Hellfire 1.01 patch.

notes:

- Whether you need  "ddt.lin32.run" or "ddt.lin64.run" depends on your Linux installation. Make sure the .run file is flagged as executable on your system.

- Getting the 1.01 version of hellfire.exe is a bit tricky. You need to download the patch hf101.exe and trick it into extracting itself.
You do this by creating an empty hellfire.exe file (with Notepad for example) and then run the patch and point it to the empty file. This will need to be done on Windows or in a Wine environment.

- The hf101.exe patch file can be found on many sites, like this one:
http://www.planetdiablo.com/hellfire/files/

- You can not use the hellfire.exe file form the Hellfire CD. It has to be the one from the 1.01 patch. 

- Make sure all files are named lower-case. "DIABDAT.MPQ" should be renamed to "diabdat.mpq" for example.

- Additionally you can include "hellfire.mpq", "hfvoice.mpq", "hfmonk.mpq" and "hfmusic.mpq" from your Hellfire CD to run Project DDT in expansion mode.

e) Run the .run file
-------------
Have fun exploring the unfinished world.
Hopefully more and better versions of Project DDT will be released in the future.


Ok, it runs, now what?
======================
You can see some game features that work by doing the following;
- Fiddle with the game settings. All the settings should be working-as-intended.
- Click on Wirt. Repeatedly.
- Go down to level 16 and release Diablo by pulling the levers.
- Find the test level entrance (house in town closest to the church), go down there and read some narrated books. 


Do I need to know about some legal stuff?
=============
- Please remember that the .mpq files taken from your Diablo (and Hellfire) CDs contain copyrighted material.
The sights, sounds, characters and lore of Diablo and Hellfire are property of their owners (undoubtedly this is Activision-Blizzard at this point in time).

- Project DDT is licenced under the GPLv2.
For more info, check the sources.tar.gz archive in this pack or simply look here: http://www.gnu.org/licenses/gpl-2.0.html



Wow, this is cool, can I help you out somehow?
=============
Yeah, there are some questions I have;

- Can anyone provide me the complete credits listing of the of Diablo 1.09 patch (or explain to me how to extract it)?
I would very much like to include all the additions that were made to that list since patch 1.00.

- Could anyone provide me some info (or code!) to help me read inside hf101.exe? It would be a lot more user-friendly if players needed not extract hellfire.exe form it manually.

- Is anyone interested in re-wring libMPQ in an endian-independent way? The idea is Project DDT should run on ARM someday but the way libMPQ is now makes that impossible.

- Is anyone up for providing me with a Smacker video decoder?
I am not sure how well the FFmpeg version would fit my code since in Project DDT the decoding, video and audio logic all run in separate threads.
(both MPQ files and Smacker files use Huffman encoding)



Best Regards,
Sanat Bosma, sabosma()gmail()com.
