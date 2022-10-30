CXX = /usr/bin/g++

all : main

global.o : global.h global.cpp
	g++ -c global.cpp -std=c++11

disjointSet.o : disjointSet.h disjointSet.cpp
	g++ -c disjointSet.cpp -std=c++11

maxHeap.o : maxHeap.h maxHeap.cpp
	g++ -c maxHeap.cpp -std=c++11

c3.o : c3.h c3.cpp
	g++ -c c3.cpp -std=c++11

main : global.o disjointSet.o maxHeap.o c3.o test.cpp
	g++ -o 1.out global.o disjointSet.o maxHeap.o c3.o test.cpp -std=c++11

debug : global.h global.cpp disjointSet.h disjointSet.cpp maxHeap.h maxHeap.cpp c3.h c3.cpp test.cpp
	g++ -g -o debug.out global.cpp disjointSet.cpp maxHeap.cpp c3.cpp test.cpp


clean :
	rm 1.out