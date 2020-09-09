all: test

test: BSTree.o BSTree_main.o
	c++ -std=c++11 BSTree.o BSTree_main.o -o main
	
BSTree.o: BSTree.cpp BSTree.h
	c++ -std=c++11 -c BSTree.cpp

BSTree_main.o: BSTree_main.cpp
	c++ -std=c++11 -c BSTree_main.cpp
	
clean:
	rm -f *.o main
	
run:
	./main
