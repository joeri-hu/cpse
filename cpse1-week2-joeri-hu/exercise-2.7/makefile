#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)

generator.exe: generator.o note_player_convert.o rtttl_player_desktop.o
	g++ -std=c++17 generator.o note_player_convert.o rtttl_player_desktop.o -o generator.exe

generator.o: generator.cpp note.hpp melody.hpp note_player.hpp note_player_convert.hpp rtttl_player.hpp
	g++ -std=c++17 -c generator.cpp -o generator.o

note_player_convert.o: note_player_convert.cpp note_player_convert.hpp note_player.hpp note.hpp
	g++ -std=c++17 -c note_player_convert.cpp -o note_player_convert.o

rtttl_player_desktop.o: rtttl_player.cpp rtttl_player.hpp note_player.hpp note.hpp
	g++ -std=c++17 -c rtttl_player.cpp -o rtttl_player_desktop.o

melody.cpp: generator.exe
	generator

HEADERS += note.hpp
HEADERS += melody.hpp
HEADERS += note_player.hpp
# HEADERS += fur_elise.hpp

HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp

# HEADERS += note_player_print.hpp
# SOURCES += note_player_print.cpp

# HEADERS += note_player_convert.hpp
# SOURCES += note_player_convert.cpp

HEADERS += rtttl_player.hpp
SOURCES += rtttl_player.cpp


SOURCES += melody.cpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
