rm := del
.PHONY: build clean
build: set
clean: $(rm) set set.o

set: main.o set.o 
	g++ -std=c++17 main.o set.o -o set.exe

main.o: main.cpp set.hpp
	g++ -std=c++17 -c main.cpp -o main.o

set.o: set.cpp # set.hpp
	g++ -std=c++17 -c set.cpp -o set.o


