#include <iostream>
#include <istream>
#include <cstdlib>
#include <fstream>
#include <ostream>
#include "jean.h"
#include "templateCollection.h"

using namespace std;

using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

//input operator - reading from file
istream& operator>>(istream& is, CollectionJN& c){
    Jeans_sizes sz;
    Jeans_colors co;
    string clr;
    string sze;
    while(!is.eof()){
        is >> clr;
        is >> sze;
        if(is.fail()){
            break;
        }
        if(clr == "red"){
            co = Jeans_colors::red;
        }
        else if(clr == "black"){
            co = Jeans_colors::black;
        }
        else if(clr == "white"){
            co = Jeans_colors::white;
        }
        else{
            co = Jeans_colors::blue;
        }

        if(sze == "small"){
            sz = Jeans_sizes::small;
        }
        else if(sze == "medium"){
            sz = Jeans_sizes::medium;
        }
        else{
            sz = Jeans_sizes::large;
        }

        Jeans obj(co, sz);
        c.insert_item(obj);
    }
    return is;
}

//output operator -
ostream& operator<<(ostream& os, const CollectionJN& c){
    for(int i=0; i < c.total_items(); i++){
        if(c[i].get_color() == Jeans_colors::red){
            os << "(red, ";
        }
        else if(c[i].get_color() == Jeans_colors::black){
            os << "(black, ";
        }
        else if(c[i].get_color() == Jeans_colors::blue){
            os << "(blue, ";
        }
        else{
            os << "(white, ";
        }

        if(c[i].get_size() == Jeans_sizes::small){
            os << "small)" << endl;
        }
        else if(c[i].get_size() == Jeans_sizes::medium){
            os << "medium)" << endl;
        }
        else if(c[i].get_size() == Jeans_sizes::large){
            os << "large)" << endl;
        }
    }
    return os;
}

int main(){
  Collection<Jeans,Jeans_colors,Jeans_sizes> object1, object2, object3, object4;;

  ifstream inFile1("jeans1.data");
  inFile1 >> object1;
  cout << "Print elements in object1 after reading from file:" << endl << object1;
  cout << "Total number of blue stress balls in object1: : " << object1.total_items(Jeans_colors::blue) << endl;
  cout << "Total number of green stress balls in object1: : " << object1.total_items(Jeans_colors::white) << endl;
  cout << "Total number of red stress balls in object1: : " << object1.total_items(Jeans_colors::red) << endl;
  cout << "Total number of yellow stress balls in object1: " << object1.total_items(Jeans_colors::black) << endl;
  cout << "Total elements in col1 after reading from file:" << object1.total_items() << endl << endl;

  ifstream inFile2("jeans2.data");
  inFile2 >> object2;
  cout << "Print elements in object2 after reading from file:" << endl << object2;
  cout << "Total number of blue stress balls in object2 : " << object2.total_items(Jeans_colors::blue) << endl;
  cout << "Total number of green stress balls in object2 : " << object2.total_items(Jeans_colors::white) << endl;
  cout << "Total number of red stress balls in object2 : " << object2.total_items(Jeans_colors::red) << endl;
  cout << "Total number of yellow stress balls in object2 : " << object2.total_items(Jeans_colors::black) << endl;
  cout << "Total elements in object2 after reading from file:" << object2.total_items() << endl << endl;


  object3 = make_union(object1, object2);
  cout << "Print elements in object3 after Union:" << endl << object3;
  cout << "Total number of blue stress balls in object3 : " << object3.total_items(Jeans_colors::blue) << endl;
  cout << "Total number of green stress balls in object3 : " << object3.total_items(Jeans_colors::white) << endl;
  cout << "Total number of red stress balls in object3 : " << object3.total_items(Jeans_colors::red) << endl;
  cout << "Total number of yellow stress balls in object3 : " << object3.total_items(Jeans_colors::black) << endl;
  cout << "Total number of large stress balls in object3 : " << object3.total_items(Jeans_sizes::large) << endl;
  cout << "Total number of medium stress balls in object3 : " << object3.total_items(Jeans_sizes::medium) << endl;
  cout << "Total number of small stress balls in object3 : " << object3.total_items(Jeans_sizes::small) << endl;
  cout << "Print the total number of stress ball  after object1 and object2 Union:" << object3.total_items() << endl << endl;

  swap(object1, object2);
  cout << "Print elements in object1 after swapping:" << endl << object1;
  cout << "Total elements in object1 after swapping:" << object1.total_items() << endl << endl;
  cout << "Print elements in object2 after swapping:" << endl << object2;
  cout << "Total elements in object2 after swapping:" << object2.total_items() << endl << endl;

  object4 = object1;
  cout << "Print elements in object4 before bubble sort:" << endl << object4 << endl;
  sort_by_size(object4, Sort_choice::bubble_sort);
  cout << "Print elements in object4 after bubble sort:" << endl << object4 << endl;

  object4 = object1;
  cout << "Print elements in object4 before instertion sort:" << endl << object4 << endl;
  sort_by_size(object4, Sort_choice::insertion_sort);
  cout << "Print elements in object4 after instertion sort:" << endl << object4 << endl;

  object4 = object1;
  cout << "Print elements in object4 before selection sort:" << endl << object4 << endl;
  sort_by_size(object4, Sort_choice::selection_sort);
  cout << "Print elements in object4 after selection sort:" << endl << object4 << endl;


  inFile1.close();
  inFile2.close();


  return 0;
  }
