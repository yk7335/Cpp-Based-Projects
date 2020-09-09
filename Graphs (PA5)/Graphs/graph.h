#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

struct Vertex {
  int label; // unique int for a vertex
  int indegree = 0; // Part 2
  int top_num; // Part 2: topological sorting number
  Vertex(int l) : label(l) {}
  Vertex(int l, int ind) : label(l), indegree(ind) {} //Part 2
};

class Graph {
private:
  vector<Vertex> node_list;
  vector<list<int>*> adj_list;
public:
  Graph() {};  // default constructor
  ~Graph(){
    node_list.clear();
    for(int i = 0; i < adj_list.size(); i++){
      delete adj_list.at(i);
    }
    
  }
  // build a graph
  void buildGraph(ifstream &input);
  // display the graph
  void displayGraph();
  // topological sort
  void topological_sort(); // Part 2
  // find indegree
  void compute_indegree(); // Part 2
  // print topological sort
  void print_top_sort();  // Part 2
};

#endif
