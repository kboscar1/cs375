Kristen Boscarino 
Alexander Benedict

To compile our program:
-- Type "make" into command line to create executables

To run our script to generate an input file:
--    python gen.py <fileName> <#nodes> <avgEdgesPerNode> <avgWeightPerNode>

-- To run the array implementation of dijkstra's algorithm type
--    ./pq <input.txt>
-- where input.txt is the name of the input file you wish to use

To run the min heap implementation type:
--     ./minHeap <input.txt>

To run the STL priority queue implementation type:
--     ./pqstd <input.txt>

-----

Data Structures:
All 3 implementations:
    Pair of ints to represent vertex and edge weight in adjacency list
    Array of list of pairs to represent adjacency list

Array implementation:
      Priority queue represented as just an array of nodes
      Visited array indicating if a node has been visited

Min Heap implementation:
    Min Heap is represented as an array of minHeap nodes

STL Priority Queue:
    uses STL priority_queue to represent priority queue of nodes

Classes:
All 3 implementations:
    Graph: which includes number of nodes and adjancency list for the graph
    	   Used to add edges, extract minimum value to pop off queue, and maintain the graph            in general

Min Heap implementation:
    MinHeap which holds the size and capacity of the min heap, and array of minheap nodes representing the graph itself, allows you to heapify, popmin and decrease key
    MinHeapNode: holds vertex number and weight from source

-----

Time Complexity:
O(|E| * Tdk + |V| * Tem) where Tdk = Time complexity for decrease key and Tem = Time complexity for extract minimum

Array implementation: O(|V|^2) bc decrease key is O(1) and extract min is O(V)

Min Heap and STL implementation: O(|E|lg|V|) bv decrease key and extract min are both O(lgV)
