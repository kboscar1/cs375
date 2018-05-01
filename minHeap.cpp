// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include<bits/stdc++.h>
#include <fstream>
#include <sys/time.h>
#include "timer.h"
#include <vector>
#include <stdlib.h>

#define INT_MAX 32767

using namespace std;

// node <vertex, weight>
typedef pair<int, int> node;

// This class represents a weighted directed
// graph using adjacency list representation
class Graph
{
  int num_nodes;    // number of nodes in graph

  list< pair<int, int> > *adj; // adjacency list of pairs of nodes with edge weights

public:
  Graph(int num_nodes);  // graph constructor

  void addEdge(int node1, int node2, int weight); // adds edge to graph

  void dijkstra(int s); // dijkstra's algorithm
};
class MinHeapNode{
	public:
			MinHeapNode(int av, int adist){
				v = av;
				dist = adist;
			}
			int v;
			int dist;
};

class MinHeap{
	public:
		int size;
		int maxSize;
		int * pos;
		MinHeapNode ** array;
		MinHeap(int aMaxSize){
			maxSize = aMaxSize;
			size = 0;
			pos = (int *)malloc(maxSize * sizeof(int));
			array = (MinHeapNode **)malloc(maxSize * sizeof(struct MinHeapNode*));
		}
		MinHeapNode * createNewMinHeapNode(int v, int dist){
			MinHeapNode * minHeapNode = new MinHeapNode(v,dist);
			return minHeapNode;
		}	
		void swap(MinHeapNode ** n1, MinHeapNode ** n2){
			MinHeapNode * temp = *n1;
			*n1 = *n2;
			*n2 = temp;
		}
		void heapify(int index){
			int smallest = index;
			int left = (2*index) + 1;
			int right = (2*index) + 2;
			if(left < size && array[left]->dist < array[smallest]->dist ) smallest = left;
			if(right < size &&  array[right]->dist <  array[smallest]->dist) smallest = right;
			if(smallest != index){
				MinHeapNode *smallestNode =  array[smallest];
				MinHeapNode * retNode =  array[index];
				pos[smallestNode->v] = index;
				pos[retNode->v] = smallest;
				swap(&array[smallest], &array[index]);
				heapify(smallest);
			}
		}
		bool isEmpty(){
			return size == 0;
		}
		MinHeapNode * popMin(){
		  if(isEmpty()) return NULL;
			MinHeapNode * root = array[0];
			MinHeapNode * lastNode = array[size-1];
			array[0] = lastNode;
			pos[root->v] = size-1;
			pos[lastNode->v] = 0;
			--size;
			heapify(0);
			return root;
		}
		void decreaseKey(int v, int dist){
			int i = pos[v];
			array[i]->dist = dist;
			while( i >= 0 && array[i]->dist < array[(i-1)/2]->dist){
				pos[array[i]->v] = (i-1)/2;
				pos[array[(i-1)/2]->v] = i;
				swap(&array[i],  &array[(i - 1) / 2]);
				i = (i-1)/2;
			}
		}
		bool isInMinHeap(int v){
			return pos[v] < size;
		}
};

// Graph constructor
// Allocates enough room in the adjancency list for the number of nodes
Graph::Graph(int num_nodes)
{
  this->num_nodes = num_nodes;
  adj = new list<node> [num_nodes]; // num_nodes lists that hold nodes/edges
}

void Graph::addEdge(int node1, int node2, int weight)
{
  adj[node1].push_back(make_pair(node2, weight));
  //adj[node2].push_back(make_pair(node1, weight)); // include if undirected?
}

// Executes dijkstra's algorithm by calcuating the single source shortest path
// from the source node given by the parameter src
void Graph::dijkstra(int src)
{
  MinHeap * PQ = new MinHeap(num_nodes);
	//int PQ[num_nodes]; // pair of vertex, distance from source
  int dist[num_nodes];
  
for (int v = 0; v < num_nodes; ++v){
	dist[v] = INT_MAX;
	PQ->array[v] = PQ->createNewMinHeapNode(v, dist[v]);
	PQ->pos[v] = v;
}


 PQ->array[src]->v   = src;
 PQ->array[src]->dist = 0;
 PQ->pos[src] = src;
 dist[src] = 0;
 PQ->decreaseKey(src, dist[src]);
 
 
 PQ->size = num_nodes;
  
 while(!PQ->isEmpty()){
   MinHeapNode * PQNode = PQ->popMin();
   int min_index = PQNode->v;       

    // 'i' is used to get all adjacent vertices of a vertex
    list< pair<int, int> >::iterator i;
      for (i = adj[min_index].begin(); i != adj[min_index].end(); i++)
	{
	  
	  // Get vertex label and weight of current adjacent
	  // of u.
	  int v = (*i).first;
	  int weight = (*i).second;

	  //  If there is shorted path to v through u.
	  if (PQ->isInMinHeap(v) && dist[min_index] != INT_MAX && (weight + dist[min_index] < dist[v]))
	    {
	      // Updating distance of v
	      dist[v] = dist[min_index] + weight;
	      PQ->decreaseKey(v, dist[v]);
	    }
	}      
 }

  // Print shortest distances stored in dist[]
 /*  printf("vertex   Distance from Source\n");
  for (int i = 0; i < num_nodes; i++){
    printf("%d \t\t %d\n", i, dist[i]);
    }*/
  
  return;
}

// Driver program to test methods of graph class
int main(int argc, char ** argv)
{
  if(argc!=2){
    cout << "usage: d1 <input file>" << endl;
    exit(1);
  }

  int v1, v2, w;
  int num_nodes = 0;
  bool first_line = true;
  string line;
  
  ifstream input(argv[1]);
  ifstream file;
  file.open(argv[1]);

  input >> num_nodes;
  Graph g(num_nodes);

  input.close();

  while(getline(file, line)){
    istringstream ls(line);

    if(first_line == true){
      first_line = false;
    } else {
      ls >> v1 >> v2 >> w;
      g.addEdge(v1, v2, w);
    }
  }

  file.close();

  timer_start();
  g.dijkstra(0);


  vector<time_t> time = timer_end();
  cout << to_string(time[0]) << " sec " << to_string(time[1]) << " microseconds " << endl;
  
  return 0;
}
