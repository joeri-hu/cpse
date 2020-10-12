#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

desktop_app: generator.o desktop_app.o
	g++ -std=c++17 generator.o desktop_app.o -o desktop_app.exe

generator.o: generator.cpp generator.hpp
	g++ -std=c++17 -c generator.cpp -o generator.o

desktop_app.o: desktop_app.cpp match.hpp compressor.hpp decompressor.hpp
	g++ -std=c++17 -c desktop_app.cpp -o desktop_app.o

compressed.asm: desktop_app
	desktop_app

# source files in this project (main.cpp is automatically assumed)
SOURCES := compressed.asm decoder.asm# generator.cpp

# header files in this project
HEADERS := # match.hpp compressor.hpp decompressor.hpp generator.hpp

# other places to look for files for this project
SEARCH  :=

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
