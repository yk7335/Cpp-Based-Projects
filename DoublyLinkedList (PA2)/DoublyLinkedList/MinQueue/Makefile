all: MinQueue

MinQueue: QueueMain.o
	g++ -std=c++11 QueueMain.o -o MinQueue

QueueMain.o: QueueMain.cpp MinQueue.h TemplatedDLList.h
	g++ -std=c++11 -c QueueMain.cpp

clean:
	rm *.o MinQueue
