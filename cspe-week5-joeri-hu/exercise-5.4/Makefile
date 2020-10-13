#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

encoder: generator.o encoder.o
	g++ -std=c++17 generator.o encoder.o -o encoder.exe

generator.o: generator.cpp generator.hpp
	g++ -std=c++17 -c generator.cpp -o generator.o

encoder.o: encoder.cpp match.hpp compressor.hpp decompressor.hpp
	g++ -std=c++17 -c encoder.cpp -o encoder.o

compressed.asm: encoder
	encoder

# source files in this project (main.cpp is automatically assumed)
SOURCES := compressed.asm decoder.asm

# header files in this project
HEADERS :=

# other places to look for files for this project
SEARCH  :=

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
