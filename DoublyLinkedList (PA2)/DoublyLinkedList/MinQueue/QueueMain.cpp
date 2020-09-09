#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include "MinQueue.h"
#include "TemplatedDLList.h"
using namespace std;

int main(){
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  MinQueue dll;
  cout << "List: " << dll.get_List() << endl;

  cout << "enqueueing the list" << endl;
  dll.enqueue(0);
  dll.enqueue(999);
  dll.enqueue(1);
  dll.enqueue(2);
  dll.enqueue(3);
  dll.enqueue(4);
  dll.enqueue(5);
  dll.enqueue(0);

  cout << "List: " << dll.get_List() << endl;

  cout << "List size BEFORE dequeue: " << dll.length() << endl;

  cout << "dequeueing the list" << endl;

  dll.dequeue();

  cout << "List size AFTER dequeue: " << dll.length() << endl;

  cout << "List: " << dll.get_List() << endl;

  cout << "The min of the list is " << dll.min() << endl;

  cout << "List: " << dll.get_List() << endl;

  cout << "Deleting the list" << endl;
  dll.~MinQueue();
  cout << "List: " << dll.get_List();

return 0;
}
