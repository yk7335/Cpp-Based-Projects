// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<class T> class DLList;
// doubly linked list node
template<typename T>
struct DLListNode {
  T obj;
  DLListNode *prev, *next;
  // constructor
  DLListNode(T e= T(), DLListNode<T> *p = nullptr, DLListNode<T> *n = nullptr)
    : obj(e), prev(p), next(n) {}
};

// doubly linked list class
template<typename T>
class DLList {
private:
    DLListNode<T> header, trailer;
public:
    DLList() : header(), trailer() // default constructor
    {
        header.next = &trailer;
        trailer.prev = &header;
    }
    DLList(const DLList<T>& dll); // copy constructor
    DLList(DLList<T>&& dll); // move constructor
    ~DLList(); // destructor
    DLList<T>& operator=(const DLList<T>& dll); // copy assignment operator
    DLList<T>& operator=(DLList<T>&& dll); // move assignment operator
    // return the pointer to the first node
    DLListNode<T> *first_node() const {return header.next;}
    // return the pointer to the trailer
    const DLListNode<T> *after_last_node() const {return &trailer;}
    bool is_empty() const {return header.next == &trailer;}
    T first() const; // return the first object
    T last() const; // return the last object
    void insert_first(T obj); // insert to the first node
    T remove_first(); // remove the first node
    void insert_last(T obj); // insert to the last node
    T remove_last(); // remove the last node
    void insert_after(DLListNode<T> &p, T obj);
    void insert_before(DLListNode<T> &p, T obj);
    void remove_after(DLListNode<T> &p);
    void remove_before(DLListNode<T> &p);
};

// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error {
    explicit EmptyDLList(char const* msg=nullptr): runtime_error(msg) {}
};

// copy constructor
template<typename T>
DLList<T>::DLList(const DLList<T>& dll)
{
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  /* Complete this function */
  DLListNode<T> *temp = dll.first_node();
  while(temp != dll.after_last_node()){
    insert_last(temp->obj);
    temp = temp->next;
  }
}
// move constructor
template<typename T>
DLList<T>::DLList(DLList<T>&& dll)
{
  /* Complete this function */
  dll.header.next->prev = &header;
  dll.trailer.prev->next = &header;
  header.next = dll.header.next;
  trailer.prev = dll.trailer.prev;
  dll.header.next = &dll.trailer;
  dll.trailer.prev = &dll.header;
}


// copy assignment operator --- exceptions
template<typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& dll)
{
  if(&dll!=this){
    this->~DLList();
    header.prev = nullptr;
    header.next = &trailer;
    trailer.next = nullptr;
    trailer.prev = &header;
    DLListNode<T> *tempnode = dll.first_node();
    while(tempnode!=dll.after_last_node()){
      insert_last(tempnode->obj);
      tempnode = tempnode->next;
    }}
  /* Complete this function */
  return *this;
}

// move assignment operator
template<typename T>
DLList<T>& DLList<T>::operator=(DLList<T>&& dll)
{
// delete stuff before and point back
  if(&dll == this){
    return *this;
  }else{
    this->~DLList();
    dll.header.next->prev = &header;
    dll.trailer.prev->next = &header;
    header.next = dll.header.next;
    trailer.prev = dll.trailer.prev;
    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
    }
  return *this;
}

// destructor
template<typename T>
DLList<T>::~DLList()
{
  /* Complete this function */
  DLListNode<T> *prev_node, *node = header.next;
  while (node != &trailer) {
      prev_node = node;
      node = node->next;
      delete prev_node;}
  header.next = &trailer;
  trailer.prev = &header;
}

// insert a new object as the first one
template<typename T>
void DLList<T>::insert_first(T obj)
{
  if(is_empty()){
    DLListNode<T> *tempnode = new DLListNode<T>(obj, &header, &trailer);
    header.next = tempnode;
    trailer.prev = tempnode;
    return;
  }else{
  DLListNode<T> *tempnode = new DLListNode<T>(obj, &header, header.next);
  header.next->prev = tempnode;
  header.next = tempnode;
  return;}
}

// insert a new object as the last one
template<typename T>
void DLList<T>::insert_last(T obj)
{
  /* Complete this function */
  if(is_empty()){
      DLListNode<T> *tempnode = new DLListNode<T>(obj, &header, &trailer);
      header.next = tempnode;
      trailer.prev = tempnode;
      return;
  }
  else{
  DLListNode<T> *tempnode = new DLListNode<T>(obj, trailer.prev, &trailer);
  trailer.prev->next = tempnode;
  trailer.prev = tempnode;
  return;}
}

// remove the first node from the list
template<typename T>
T DLList<T>::remove_first()
{
  /* Complete this function */
  if (is_empty())
      throw ("Empty Doubly Linked List");
  DLListNode<T> *tempnode = header.next;
  tempnode->next->prev = &header;
  header.next = tempnode->next;
  T obj = tempnode->obj;
  tempnode->next = nullptr;
  tempnode->prev = nullptr;
  delete tempnode;
  tempnode = NULL;
  return obj;
}

// remove the last node from the list
template<typename T>
T DLList<T>::remove_last()
{
  /* Complete this function */
  if (is_empty())
    throw ("Empty Doubly Linked List");
  DLListNode<T> *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  T obj = node->obj;
  node->next = nullptr;
  node->prev = nullptr;
  delete node;
  node = NULL;
  return obj;
}

// return the first object (do not remove)
template<typename T>
T DLList<T>::first() const
{
  /* Complete this function */
  if (is_empty())
    throw ("Empty Doubly Linked List");
  return header.next->obj;
}

// return the last object (do not remove)
template<typename T>
T DLList<T>::last() const
{
  /* Complete this function */
  if (is_empty())
      throw ("Empty Doubly Linked List");
  return trailer.prev->obj;
}

// insert a new node after the node p
template<typename T>
void DLList<T>::insert_after(DLListNode<T> &p, T obj)
{
  /* Complete this function */
  if (&p == &trailer)
    throw ("cannot insert after trailer");
  DLListNode<T> *NewNode = new DLListNode<T>(obj);
  DLListNode<T> *node = header.next;
  while(node!=&p && node->next!= nullptr){
    node = node->next;}

  NewNode->next = node->next;
  NewNode->prev = node;
  (node->next)->prev = NewNode;
  node->next = NewNode;
}

// insert a new node before the node p
template<typename T>
void DLList<T>::insert_before(DLListNode<T> &p, T obj)
{
  /* Complete this function */
  if (&p == &header)
    throw ("cannot insert before header");
  DLListNode<T> *newNode = new DLListNode<T>(obj);
  DLListNode<T> *node = header.next;
  while (node != &p && node->next != NULL) {
		node = node->next;
	}
  node = node->prev;
	newNode->next = node->next;
	newNode->prev = node;
  node->next->prev = newNode;
	node->next = newNode;
}

// remove the node after the node p
template<typename T>
void DLList<T>::remove_after(DLListNode<T> &p)
{
  if(is_empty())
        throw ("Empty Doubly Linked List");
    if(&p == &trailer)
        throw ("you're trying to remove something not there");
    if(p.next == &trailer)
        throw ("you're trying to remove trailer");
  /* Complete this function */
  DLListNode<T> *node = &p;
  node = node->next;
  p.next = node->next;
  node->next->prev = &p;
  delete node;
  node = NULL;
// add link back to node

}

// remove the node before the node p
template<typename T>
void DLList<T>::remove_before(DLListNode<T> &p)
{
  if(is_empty())
        throw ("Empty Doubly Linked List");
    if(&p == &header)
        throw ("you're trying to remove the header");
    if(p.next == &header)
        throw ("you're trying to remove after header");
  /* Complete this function */
  DLListNode<T> *node = &p;
  node = node->prev;
  p.prev = node->prev;
  node->prev->next = &p;
  delete node;
  node = NULL;


}

// output operator
template<typename T>
ostream& operator<<(ostream& out, const DLList<T>& dll)
{
  /* Complete this function */
  DLListNode<T> *node = dll.first_node();
  while (node != dll.after_last_node()){
    out << node->obj << " ";
    node = node->next;
  }
  return out;
}


#endif
