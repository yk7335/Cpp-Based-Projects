
#ifndef MINQUEUE_H
#define MINQUEUE_H

#include "TemplatedDLList.h"
using namespace std;

class MinQueue {
private:
DLList<int> List; // internal LinkedList object
int size = 0;
public:
MinQueue() : List() { } // constructor
~MinQueue() { List.~DLList<int>(); } // destructor
DLList<int> get_List(){return List;}
bool is_Empty( ) const { return List.is_empty(); }
int length( ) {return size;}
void enqueue(int elem){
  List.insert_last(elem);
  size++;
 }
int dequeue(){
  int obj = List.remove_first();
  size--;
  return obj;
}
int min(){
  int low;
  if(List.is_empty()){throw "The list is empty!";}
  else{
    DLListNode<int> *Node = List.first_node();
    low = Node->obj;
    for(int i = 0; i < size; i++){
      if(low > Node->obj){low = Node->obj;}
      Node = Node->next;
    }
  }
  return low;}
};





#endif
