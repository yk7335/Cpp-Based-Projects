// test of the DLList class

#include <iostream>
#include <cstdlib>
#include "DLList.h"

using namespace std;

int main ()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList dll;
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_last(i);
  }
  cout << "list: " << dll << endl << endl;

  // more testing...
  // add tests for insert_after, insert_before
  // INSERT AFTER
  DLListNode *node = dll.first_node();
  while(node->obj != 50){node=node->next;}
  cout << "inserting node right After 50, putting node with value 3000" << endl;
  dll.insert_after(*node, 3000);
  cout << "list: " << dll << endl;
  // INSERT BEFORE
  DLListNode *node2 = dll.first_node();
  while(node2->obj != 50){node2=node2->next;}
  cout << "inserting node right before 50, putting node with value 3000" << endl;
  dll.insert_before(*node2, 3000);
  cout << "list: " << dll << endl;
  // add tests for remove_after, remove_before
  // REMOVE AFTER
  cout << "Removing the 3000 which is after 50" <<endl;
  dll.remove_after(*node);
  cout << "list: " << dll << endl;
  // REMOVE BEFORE
  cout << "Removing the 3000 which is before 50" <<endl;
  dll.remove_before(*node2);
  cout << "list: " << dll << endl;
  cout << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_first(i);
  }
  cout << "list: " << dll << endl << endl;

  cout << "Copy to a new list" << endl;
  DLList dll2(dll);
  cout << "list2: " << dll2 << endl << endl;

  cout << "Assign to another new list" << endl;
  DLList dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;

  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;

  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;

  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;


  return 0;
}
