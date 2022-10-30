CXX = /usr/bin/g++

all : main

main : global.h global.cpp disjointSet.h disjointSet.cpp maxHeap.h maxHeap.cpp c3.h c3.cpp test.cpp
	g++ -o 1.out global.h global.cpp disjointSet.h disjointSet.cpp maxHeap.h maxHeap.cpp c3.h c3.cpp test.cpp

debug : global.h global.cpp disjointSet.h disjointSet.cpp maxHeap.h maxHeap.cpp c3.h c3.cpp test.cpp
	g++ -g -o debug.out global.h global.cpp disjointSet.h disjointSet.cpp maxHeap.h maxHeap.cpp c3.h c3.cpp test.cpp


clean :
	rm 1.out