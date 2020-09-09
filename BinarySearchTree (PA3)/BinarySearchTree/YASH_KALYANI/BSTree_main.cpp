#include <iostream>
#include <fstream>
#include "BSTree.h"
using namespace std;


BSTree read_file(string file_name)
{
  /*
    open the file and use the input operator (operator>>)
    to construct a new tree
  */
    
  BSTree new_tree;
  ifstream infile(file_name); 
  int temp;
  // use >> to read in to new_tree
  if(!infile){throw "file cannot be read";}
  while(!infile.eof()){
    infile >> temp;
    new_tree.insert(temp);
  }

  return new_tree;
}


int main()
{
    // created my own main
/*
for(int i = 1; i <= 12; i++) {
    string dir= "data-files/"+std::to_string(i);
    BSTree l = read_file(dir+"l");
    cout << "average search time linear " << i << " "
     << l.get_average_search_time() << endl;
    BSTree p = read_file(dir+"p");
    cout << "average search time perfect "<< i << " "
     << p.get_average_search_time() << endl;
    BSTree r = read_file(dir+"r");
    cout << "average search time random "<< i << " "
     << r.get_average_search_time() << endl;

    if(i <= 4) {
      cout << "prefect tree " << i << endl << p;
    }

    cout << endl;
  }
*/
  cout << endl << endl << endl; 

  srand(time(NULL));
    BSTree tree1;
    for(int i = 0; i < 16; i++){tree1.insert(rand()% 100);}
    cout << "first tree: ";
    tree1.inorder(cout);
    cout << endl;
    tree1.print_level_by_level(cout);
    cout << "number of nodes: " << tree1.get_size() << endl << "average search time: " << tree1.get_average_search_time() << endl << endl;
    
    // copy constructor test
    BSTree tree2(tree1);
    cout << "testing for copy constructor (tree1 and tree2):" << endl;
    cout << "tree2: ";
    tree2.inorder(cout);
    cout << endl << endl;
    
    // copy assignment test
    BSTree tree3;
    cout << "testing for copy assignment (tree2 and tree3): " << endl;
    tree3 = tree2;
    cout << "tree3: ";
    tree3.inorder(cout);
    cout << endl << endl;
    
    // move constructor test
    BSTree tree4 = tree3;
    BSTree tree5 = move(tree4);
    cout << "testing for move constructor (tree4 and tree3): " << endl;
    cout << "tree5: ";
    tree5.inorder(cout);
    cout << endl << endl;
    cout << "tree4: ";
    tree4.inorder(cout);
    cout << endl << endl;
    
    // move assignment test
    BSTree tree6 = move(tree5);
    cout << "testing for move assignment (tree 6):" << endl;
    cout << "tree6: ";
    tree6.inorder(cout);
    cout << endl << endl;
    cout << "tree5: ";
    tree5.inorder(cout);
    cout << endl << endl << endl;
    
    
    cout << "linear " << endl << endl;
    for(int i=1; i<=4; i++){
        string num = to_string(i);
        ifstream infile1(num + "l");
        BSTree lit3;
        infile1 >> lit3;
        lit3.inorder(cout);
        cout << endl;
        cout << "average search time: " << lit3.get_average_search_time() << endl;
        cout << "Nodes #: " << lit3.get_size() << endl;
        cout << endl << endl;
    }
    cout << endl;
    cout << "Perfect " << endl << endl;
    for(int i=1; i<=4; i++){
        string num2 = to_string(i);
        ifstream infile2(num2 + "p");
        BSTree lit2;
        infile2 >> lit2;
        lit2.inorder(cout);
        cout << endl;
        cout << "average search time: " << lit2.get_average_search_time() << endl;
        cout << "Nodes #: " << lit2.get_size() << endl;
        cout << endl << endl;
    }
    cout << endl;
    cout << "Random " << endl << endl;
    for(int i=1; i<=4; i++){
        string num3 = to_string(i);
        ifstream infile3(num3 + "r");
        BSTree lit;
        infile3 >> lit;
        lit.inorder(cout);
        cout << endl;
        cout << "average search time: " << lit.get_average_search_time() << endl;
        cout << "Nodes #:" << lit.get_size() << endl;
        cout << endl << endl;
    }
    

cout << endl;
cout << endl;
cout << endl;
cout << endl;

BSTree treetest;
treetest.insert(3);
treetest.insert(4);
treetest.insert(5);
treetest.insert(1);
treetest.insert(20);

treetest.update_search_times();

cout << treetest.get_average_search_time() << endl;

// treetest.~BSTree();

    return 0;
}

