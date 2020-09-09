all: test

test: Collection_test.o
	c++ -std=c++11 Collection_test.o -o main

Collection_test.o: Collection_test.cpp templateCollection.h Stress_ball.h jean.h
	c++ -std=c++11 -c Collection_test.cpp

clean:
	rm -f *.o main

run:
		./main
