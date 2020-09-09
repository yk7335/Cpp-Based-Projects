#include "graph.h"
#include <iostream>
#include <string>
using namespace std;
// to be implemented



void Graph::buildGraph(ifstream &input){
  int temp;
  adj_list = vector<list<int>*>(25);
  int i = 0;
  while (!input.eof()) {
    input >> temp;
    this->node_list.push_back(Vertex(temp));
    input >> temp;
    adj_list.at(i)= new list<int>();
    while(temp != -1){
      this->adj_list.at(i)->push_back(temp);
      input >> temp;
      }
    i++; 
  	}
	}

void Graph::displayGraph(){
    int num = 0;
    for(int i = 0; i < this->node_list.size()-1; i++){
      cout << node_list[i].label << " : ";
      auto it = adj_list[i]->begin();
      while(it!=adj_list[i]->end()){
        cout << *it << " ";
        ++it;
      }
        cout << endl;
        }
    }