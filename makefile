all: PQ

PQ: pq.o timer.o
	g++ pq.o timer.o -o pq
minHeap: minHeap.o timer.o
	g++ minHeap.o timer.o -o minHeap
PQ.o: pq.cpp timer.cpp
	g++ -c pq.cpp timer.cpp
minHeap.o: minHeap.cpp timer.cpp
	g++ -c minHeap.cpp timer.cpp

clean:
	rm -f *.o pq
	rm -f *.o timer.o
