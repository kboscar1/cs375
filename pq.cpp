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

// Graph constructor
// Allocates enough room in the adjancency list for the number of nodes
Graph::Graph(int num_nodes)
{
  this->num_nodes = num_nodes;
  adj = new list<node> [num_nodes]; // num_nodes lists that hold nodes/edges
}


//Adds an edge to the graph given the source vertex, destination vertex, and weight of edge
void Graph::addEdge(int node1, int node2, int weight)
{
  adj[node1].push_back(make_pair(node2, weight));
  //adj[node2].push_back(make_pair(node1, weight)); // include if undirected?
}

// Executes dijkstra's algorithm by calcuating the single source shortest path
// from the source node given by the parameter src
void Graph::dijkstra(int src)
{
  int PQ[num_nodes]; // pair of vertex, distance from source
  int visited[num_nodes]; // array to indicate if nodes have been visited yet
  
  for(int i = 0; i < num_nodes; i++){
    PQ[i] = INT_MAX - 1;
    visited[i] = 0;
  }
  
  PQ[src] = 0; // distance to source is 0
  
  int k = 0; // counter variable for while loop
  while(k < num_nodes)
  {
    k++;

    int min = INT_MAX; // current minimum value, set to INT_MAX so any number is lower
    int min_index; // index of the node with the minimum index so far
    for(int i = 0 ; i < num_nodes ; i++){
      if((PQ[i] < min) && (visited[i] == 0)){
	min = PQ[i];
	min_index = i;
      }
    }

    visited[min_index] = 1;

    // 'i' is used to get all adjacent vertices of a vertex
    list< pair<int, int> >::iterator i;
      for (i = adj[min_index].begin(); i != adj[min_index].end(); i++)
	{

	  // Get vertex label and weight of current adjacent
	  // of u.
	  int v = (*i).first; // the vertex number of the adjacent node
	  int weight = (*i).second; // the weight number of the adjacent node

	  //  If there is shorted path to v through u.
	  if (PQ[v] > PQ[min_index] + weight)
	    {
	      // Updating distance of v
	      PQ[v] = PQ[min_index] + weight;
	    }
	}
    }

  // Print shortest distances stored in dist[]
  printf("vertex   Distance from Source\n");
    for (int i = 0; i < num_nodes; i++){
    printf("%d \t\t %d\n", i, PQ[i]);
    }
  
  return;
}

// Driver program to test methods of graph class
int main(int argc, char ** argv)
{
  if(argc!=2){
    cout << "usage: d1 <input file>" << endl;
    exit(1);
  }

  int v1, v2, w; // dummy  nodes (v1, v2) to read from file, dummy weight (w) to read from file
  int num_nodes = 0; // number of nodes in file
  bool first_line = true; // first line of input array (formatted seperately)
  string line; // dummy line to use in getline
  
  ifstream input(argv[1]); // creates stream from the file
  ifstream file; // creates stream to open file with
  file.open(argv[1]);

  input >> num_nodes;
  Graph g(num_nodes); // creates graph to use 

  input.close();

  while(getline(file, line)){
    istringstream ls(line); // makes line into a string stream to split it

    if(first_line == true){
      first_line = false;
    } else {
      ls >> v1 >> v2 >> w;
      g.addEdge(v1, v2, w);
    }
  }

  file.close();

  timer_start(); // starts timer function
  g.dijkstra(0);

  vector<time_t> time = timer_end(); //ends timer function and gets vector of times
  cout << to_string(time[0]) << " sec " << to_string(time[1]) << " microseconds " << endl;
  
  return 0;
}
