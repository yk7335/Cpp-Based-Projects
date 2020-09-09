// testing the templated class DLList

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

#include "TemplatedDLList.h"

using namespace std;

int main ()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList<string> dll;
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_last(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_first(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  cout << "Copy to a new list" << endl;
  DLList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;

  cout << "Assign to another new list" << endl;
  DLList<string> dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;

  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;

  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;

  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;

  // more testing...
  // add tests for insert_after, insert_before
  // add tests for remove_after, remove_before
cout << endl;
cout << "Insert 20 nodes at back with value 5,10,15,20,25..,100" << endl;
    for (int i=5; i<=100; i+=5) {
      stringstream ss;
      ss << i;
      dll.insert_last(ss.str());
    }
    cout << "list: " << dll << endl << endl;

    DLListNode<string> *Node = dll.first_node();
    while(Node->obj != "100"){
        Node = Node->next;
    }
    cout << "Inserting YASH after 100..." << endl;
    dll.insert_after(*Node, "YASH");
    cout << "list: " << dll << endl << endl;

    DLListNode<string> *Node2 = dll.first_node();
    while(Node2->obj != "5"){
        Node2 = Node2->next;
    }
    cout << "Inserting YASH before 5..." << endl;
    dll.insert_before(*Node2, "YASH");
    cout << "list: " << dll << endl << endl;

    cout << "Deleting YASH after 100..." << endl;
    dll.remove_after(*Node);
    cout << "list: " << dll << endl << endl;

    cout << "Deleting YASH before 5..." << endl;
    dll.remove_before(*Node2);
    cout << "list: " << dll << endl << endl;

    /////////////////
    DLListNode<string> *NewNode = dll.first_node();
    while(NewNode->obj != "40"){
        NewNode = NewNode->next;
    }
    cout << "Inserting YASH after 40..." << endl;
    dll.insert_after(*NewNode, "YASH");
    cout << "list: " << dll << endl << endl;

    DLListNode<string> *NewNode2 = dll.first_node();
    while(NewNode2->obj != "35"){
        NewNode2 = NewNode2->next;
    }
    cout << "Inserting YASH before 35..." << endl;
    dll.insert_before(*NewNode2, "YASH");
    cout << "list: " << dll << endl << endl;

    cout << "Deleting YASH after 40..." << endl;
    dll.remove_after(*NewNode);
    cout << "list: " << dll << endl << endl;

    cout << "Deleting YASH before 35..." << endl;
    dll.remove_before(*NewNode2);
    cout << "list: " << dll << endl << endl;
  return 0;
}
