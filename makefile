all: PQ minHeap stdpq

PQ: pq.o timer.o
	g++ pq.o timer.o -o pq
minHeap: minHeap.o timer.o
	g++ minHeap.o timer.o -o minHeap
PQ.o: pq.cpp timer.cpp
	g++ -c pq.cpp timer.cpp
minHeap.o: minHeap.cpp timer.cpp
	g++ -c minHeap.cpp timer.cpp

stdpq: stdpq.o timer.o
	g++ stdpq.o timer.o -o stdpq

stdpq.o: stdpq.cpp timer.cpp
	g++ -c stdpq.cpp timer.cpp

clean:
	rm -f *.o pq
	rm -f *.o timer.o
	rm -f *.o stdpq
	rm -f *.o minHeap
