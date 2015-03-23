Dwarf Fortress Text Fixer
=========================

Purpose
-------
This utility mitigates a bug in TrueType font rendering in Dwarf Fortress 0.40.xx (and some earlier versions) If you've used TrueType fonts (by pressing F12 or using a mod with TrueType on by default), you've likely noticed long lines of text in one column can overlap and "black out" the text in subsequent columns.

For more information on the bug, see http://www.bay12games.com/dwarves/mantisbt/view.php?id=5097.

What This Does
--------------
It runs in the background and tells Dwarf Fortress to redraw its screen over and over. While this does use up a few extra CPU cycles, our testing shows no noticeable change in FPS.

How to Get It
-------------
Download it from DWFD: https://www.google.com/.

How to Use It
-------------
1. Start `df_text_fixer.exe`
2. Start Dwarf Fortress

It also works if you do step #2 before step #1.

How to Build from Source
------------------------
The official binary file is built with mingw32 on cygwin. To built it yourself, follow these instructions:

1. Download and install Cygwin: http://cygwin.com/
2. Use Cygwin Setup to install the package named `mingw-gcc-g++` (dependencies will be installed automatically)
3. Get the Dwarf Fortress Text Fixer source code
4. Launch the Cygwin terminal and `cd` into the source code directory
5. Build the .exe by running `i686-pc-mingw32-g++ df_text_fix.cpp -Wall -Wextra -pedantic -static-libgcc -s -o df_text_fix.exe`

However, any C++ compiler with access to the Windows API should be able to compile the source (though the exact instructions will vary from the above).