EXEC = assignment7
CPP = g++
CFLAGS = -c -Wall

$(EXEC)	: Assignment7.o Graph.o LinkedList.o MinHeap.o
	$(CPP) -o $(EXEC) Assignment7.o Graph.o LinkedList.o MinHeap.o

Assignment7.o : Assignment7.cpp
	$(CPP) $(CFLAGS) Assignment7.cpp

Graph.o	: Graph.h Graph.cpp
	$(CPP) $(CFLAGS) Graph.cpp

LinkedList.o : LinkedList.h LinkedList.cpp
	$(CPP) $(CFLAGS) LinkedList.cpp

MinHeap.o : MinHeap.h MinHeap.cpp
	$(CPP) $(CFLAGS) MinHeap.cpp

clean	:
	rm *.o
