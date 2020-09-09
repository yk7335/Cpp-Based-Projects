// implementation of the DLList class
#include <stdexcept>
#include "DLList.h"


// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error {
  explicit EmptyDLList(char const* msg=nullptr): runtime_error(msg) {}
};

// copy constructor
DLList::DLList(const DLList& dll)
{
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  /* Complete this function */
  DLListNode *temp = dll.first_node();
  while(temp != dll.after_last_node()){
    insert_last(temp->obj);
    temp = temp->next;
  }
}
// move constructor
DLList::DLList(DLList&& dll)
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
DLList& DLList::operator=(const DLList& dll)
{
  if(&dll!=this){
    this->~DLList();
    header.obj = 0;
    trailer.obj = 0;
    header.prev = nullptr;
    header.next = &trailer;
    trailer.next = nullptr;
    trailer.prev = &header;
    DLListNode *tempnode = dll.first_node();
    while(tempnode!=dll.after_last_node()){
      insert_last(tempnode->obj);
      tempnode = tempnode->next;
    }}
  /* Complete this function */
  return *this;
}

// move assignment operator
DLList& DLList::operator=(DLList&& dll)
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
DLList::~DLList()
{
  /* Complete this function */
  DLListNode *prev_node, *node = header.next;
  while (node != &trailer) {
      prev_node = node;
      node = node->next;
      delete prev_node;}
  header.next = &trailer;
  trailer.prev = &header;
}

// insert a new object as the first one
void DLList::insert_first(int obj)
{
  DLListNode *tempnode = new DLListNode(obj, &header, header.next);
  header.next->prev = tempnode;
  header.next = tempnode;}

// insert a new object as the last one
void DLList::insert_last(int obj)
{
  /* Complete this function */
  DLListNode *tempnode = new DLListNode(obj, trailer.prev, &trailer);
  trailer.prev->next = tempnode;
  trailer.prev = tempnode;
}

// remove the first node from the list
int DLList::remove_first()
{
  /* Complete this function */
  if (is_empty())
      throw ("Empty Doubly Linked List");
  DLListNode *tempnode = header.next;
  tempnode->next->prev = &header;
  header.next = tempnode->next;
  int obj = tempnode->obj;
  tempnode->next = nullptr;
  tempnode->prev = nullptr;
  delete tempnode;
  return obj;
}

// remove the last node from the list
int DLList::remove_last()
{
  /* Complete this function */
  if (is_empty())
    throw ("Empty Doubly Linked List");
  DLListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  node->next = nullptr;
  node->prev = nullptr;
  delete node;
  return obj;
}

// return the first object (do not remove)
int DLList::first() const
{
  /* Complete this function */
  if (is_empty())
    throw ("Empty Doubly Linked List");
  return header.next->obj;
}

// return the last object (do not remove)
int DLList::last() const
{
  /* Complete this function */
  if (is_empty())
      throw ("Empty Doubly Linked List");
  return trailer.prev->obj;
}

// insert a new node after the node p
void DLList::insert_after(DLListNode &p, int obj)
{
  /* Complete this function */
  if (&p == &trailer)
    throw ("cannot insert after trailer");
  DLListNode *NewNode = new DLListNode(obj);
  DLListNode *node = header.next;
  while(node!=&p && node->next!= nullptr){
    node = node->next;}

  NewNode->next = node->next;
  NewNode->prev = node;
  (node->next)->prev = NewNode;
  node->next = NewNode;
}

// insert a new node before the node p
void DLList::insert_before(DLListNode &p, int obj)
{
  /* Complete this function */
  if (&p == &header)
    throw ("cannot insert before header");
  DLListNode *newNode = new DLListNode(obj);
  DLListNode *node = header.next;
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
int DLList::remove_after(DLListNode &p)
{
  if(is_empty())
        throw ("Empty Doubly Linked List");
    if(&p == &trailer)
        throw ("you're trying to remove something not there");
    if(p.next == &trailer)
        throw ("you're trying to remove trailer");
  /* Complete this function */
  DLListNode *node = &p;
  node = node->next;
  p.next = node->next;
  node->next->prev = &p;
  delete node;
  node = NULL;
// add link back to node

}

// remove the node before the node p
int DLList::remove_before(DLListNode &p)
{
  if(is_empty())
        throw ("Empty Doubly Linked List");
    if(&p == &header)
        throw ("you're trying to remove the header");
    if(p.next == &header)
        throw ("you're trying to remove after header");
  /* Complete this function */
  DLListNode *node = &p;
  node = node->prev;
  p.prev = node->prev;
  node->prev->next = &p;
  delete node;
  node = NULL;


}

// output operator
ostream& operator<<(ostream& out, const DLList& dll)
{
  /* Complete this function */
  DLListNode *node = dll.first_node();
  while (node != dll.after_last_node()){
    out << node->obj << " ";
    node = node->next;
  }
  return out;
}
