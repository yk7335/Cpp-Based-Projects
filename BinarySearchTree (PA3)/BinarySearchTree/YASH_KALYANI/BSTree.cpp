#ifndef BSTree_CPP
#define BSTree_CPP

#include "BSTree.h"

// input / output operators
ostream& operator<<(ostream& out, BSTree& tree)
{
  tree.print_level_by_level(out);
  return out;
}

ostream& operator<<(ostream& out, Node node)
{
  return out << "( " << node.value << ", "
	     << node.search_time << " )";
}

istream& operator>>(istream& in, BSTree& tree)
{
  /*
    take input from the in stream, and build your tree
    input will look like
    4
    2
    6
    1
    3
    5
    7
  */
  int next;
  while(in >> next)
    tree.insert(next);
  return in;
}

///////////// Implementation To Do ////////////////////

// copy constructor
BSTree::BSTree(const BSTree& other)
{
  /*
    complete this copy constructor
    make sure when copying nodes to copy
    the value and left and right children
  */
// not correct bc the BST class has root and makes a whole tree like singly
// linked list!!!

this->root = new Node;
this->root->value = other.root->value;
if(other.root == this->root){throw "the trees are the same.";}
copy_helper(this->root, other.root);
this->size = other.size;

}

// move constructor
BSTree::BSTree(BSTree&& other)
{
  if(other.root == this->root){throw "the trees are the same.";}
  this->root = other.root;
  this->size = other.size;
  other.root = nullptr;
}

//copy assignment
BSTree& BSTree::operator=(const BSTree& other)
{
  /*
    complete this assignment operator
    make sure when copying nodes to copy
    the value
    and left and right children
    not important for this part but will be used later
  */
this->root = new Node;
this->root->value = other.root->value;
if(other.root == this->root){throw "the trees are the same.";}
copy_helper(this->root, other.root);
this->size = other.size;


return *this;}

// move assignment
BSTree BSTree::operator=(BSTree&& other)
{
  this->root = other.root;
  this->size = other.size;
  other.root = NULL;
  return *this;
}

// destructor
BSTree::~BSTree()
{
  // use a helper function
  Delete_helper(this->root);
  this->size = 0;
}

void BSTree::Delete_helper(Node* node){
  if(node != nullptr){
  Delete_helper(node->left);
  Delete_helper(node->right);
  delete node;}
}

// recursive
void BSTree::copy_helper(Node* copy_to,
			 const Node* copy_from) const
{
  if(copy_from == nullptr)
    return;

  if(copy_from->left != nullptr) {
    copy_to->left = new Node(*copy_from->left);
    copy_helper(copy_to->left, copy_from->left);
  } else {
    copy_to->left = nullptr;
  }

  if(copy_from->right != nullptr) {
    copy_to->right = new Node(*copy_from->right);
    copy_helper(copy_to->right, copy_from->right);
  } else {
    copy_to->right = nullptr;
  }
}

void BSTree::insert(int obj)
{
    /*
    insert a node into the tree
    first find where the node should go
    then modify pointers to connect your new node
  */
insertHelper(obj,root);
  this->update_search_times();
  this->size = this->size +1;
}

void BSTree::insertHelper(int obj, Node* root){
if(root == nullptr){
        Node* root = new Node;
        this->root = root;
        root->value = obj;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if(obj < root->value){
        if(root->left != nullptr){
            insertHelper(obj, root->left);
        }
        else{
            Node *n = new Node;
            root->left = n;
            n->value = obj;
            n->left = nullptr;
            n->right = nullptr;
        }
    }
    else if(obj > root->value){
        if(root->right != nullptr){
            insertHelper(obj, root->right);
        }
        else{
            Node *n = new Node;
            root->right = n;
            n->value = obj;
            n->left = nullptr;
            n->right = nullptr;
        }
    }
}

Node* BSTree::search(int obj)
{
  /*
    recursivly search down the tree to find the node that contains obj
    if you dont find anything return null
  */
  return searchHelper(obj,root);
}

Node* BSTree::searchHelper(int obj, Node* root){
  if(root == nullptr){throw "the root with the obj does not exist";}
  if(obj > root->value){return searchHelper(obj,root->right);}
  else if(obj < root->value){return searchHelper(obj,root->left);}
  else{return root;}

  return 0;
}

void BSTree::update_search_times()
{
  /*
    do a BFS or DFS of your tree and update the searchtimes of all nodes
  */
  update_search_timesHELPER(this->root);
}

void BSTree::update_search_timesHELPER(Node* root){
  if(root==nullptr){return;}
  else{
    root->search_time = 1 + (HowDeepIsTheNode(this->root) - HowDeepIsTheNode(root));
    update_search_timesHELPER(root->right);
    update_search_timesHELPER(root->left);
  }
  return;

}

int BSTree::HowDeepIsTheNode(Node* root)
{
    if(root==nullptr){return 0;}
    int left = HowDeepIsTheNode(root->left);
    int right = HowDeepIsTheNode(root->right);
    if(left<right){return right+1;}
    else{return left+1;}   
}



ostream& BSTree::inorder(ostream& out)
{
  /*
    print your nodes in infix order
    if our tree looks like

    4
    2 6
    1 3 5 7

    we should get

    1 2 3 4 5 6 7
  */
  inorderHelper(this->root);
  return out;
}

void BSTree::inorderHelper(Node* root){
  if (root != nullptr){
      inorderHelper(root->left);
      cout<< root->value << "[" << root->search_time<< "]" << "    ";
      inorderHelper(root->right);}
}

// implemented
void BSTree::pretty_print_node(ostream& out,Node* node)
{
  out << node->value << "["<<node->search_time<<"] ";
}

// implemented
ostream& BSTree::print_level_by_level(ostream& out)
{
  /*
    print the tree using a BFS
    output should look like this if we dont have a full tree

    4
    2 6
    1 X 5 7
    X X X X X X X 9

    it will be helpfull to do this part iterativly,
    so do the BFS with the std stack data structure.

    it may also be helpfull to put the entire tree into a vector
    (probably google this if you dont know how to do it)
  */

  if(root == nullptr)
        return out;

    bool hasNodes = true;
    vector<Node*> current_level;
    vector<Node*> next_level;
    current_level.push_back(root);
    while(hasNodes){
        hasNodes = false;
        for(auto node : current_level){
            if(node != nullptr){
                pretty_print_node(out, node);
                if(node->left != nullptr)
                    hasNodes = true;
                if(node->right != nullptr)
                    hasNodes = true;
                next_level.push_back(node->left);
                next_level.push_back(node->right);
            }
            else{
                out << "X ";
                next_level.push_back(nullptr);
                next_level.push_back(nullptr);
            }
        }
        out << endl;
        current_level.clear();
        current_level = next_level;
        next_level.clear();
    }
    return out;
}

// implemented
int BSTree::get_total_search_time(Node* node)
{
  if(node == nullptr)
    return 0;

  return get_total_search_time(node->left) +
    get_total_search_time(node->right) + node->search_time;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if(total_search_time == 0)
    return - 1;

  return ((float)total_search_time)/size;
}

#endif