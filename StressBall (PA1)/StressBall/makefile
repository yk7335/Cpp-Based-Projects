all: test

test: Stress_Main.o
	c++ -std=c++11 Stress_Main.o -o main

Stress_Main.o: Stress_Main.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_Main.cpp

clean:
	rm -f *.o main

run:
		./main
