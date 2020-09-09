all: test

test: collection_test.o
	c++ -std=c++11 collection_test.o -o main

collection_test.o: collection_test.cpp Collection.h Stress_ball.h
	c++ -std=c++11 -c collection_test.cpp

clean:
	rm -f *.o main

run:
		./main
