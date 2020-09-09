  #include <iostream>
  #include <fstream>
  #include <string>
  #include "Stress_ball.h"
  #include "Collection.h"

  using namespace std;

  int main()
  {
  Collection object1, object2, object3, object4;

  ifstream inFile1("stress_ball1.data");
  inFile1 >> object1;
  cout << "Print elements in object1 after reading from file:" << endl << object1;
  cout << "Total number of blue stress balls in object1: : " << object1.total_items(Stress_ball_colors::blue) << endl;
  cout << "Total number of green stress balls in object1: : " << object1.total_items(Stress_ball_colors::green) << endl;
  cout << "Total number of red stress balls in object1: : " << object1.total_items(Stress_ball_colors::red) << endl;
  cout << "Total number of yellow stress balls in object1: " << object1.total_items(Stress_ball_colors::yellow) << endl;
  cout << "Total elements in col1 after reading from file:" << object1.total_items() << endl << endl;

  ifstream inFile2("stress_ball2.data");
  inFile2 >> object2;
  cout << "Print elements in object2 after reading from file:" << endl << object2;
  cout << "Total number of blue stress balls in object2 : " << object2.total_items(Stress_ball_colors::blue) << endl;
  cout << "Total number of green stress balls in object2 : " << object2.total_items(Stress_ball_colors::green) << endl;
  cout << "Total number of red stress balls in object2 : " << object2.total_items(Stress_ball_colors::red) << endl;
  cout << "Total number of yellow stress balls in object2 : " << object2.total_items(Stress_ball_colors::yellow) << endl;
  cout << "Total elements in object2 after reading from file:" << object2.total_items() << endl << endl;


  object3 = make_union(object1, object2);
  cout << "Print elements in object3 after Union:" << endl << object3;
  cout << "Total number of blue stress balls in object3 : " << object3.total_items(Stress_ball_colors::blue) << endl;
  cout << "Total number of green stress balls in object3 : " << object3.total_items(Stress_ball_colors::green) << endl;
  cout << "Total number of red stress balls in object3 : " << object3.total_items(Stress_ball_colors::red) << endl;
  cout << "Total number of yellow stress balls in object3 : " << object3.total_items(Stress_ball_colors::yellow) << endl;
  cout << "Total number of large stress balls in object3 : " << object3.total_items(Stress_ball_sizes::large) << endl;
  cout << "Total number of medium stress balls in object3 : " << object3.total_items(Stress_ball_sizes::medium) << endl;
  cout << "Total number of small stress balls in object3 : " << object3.total_items(Stress_ball_sizes::small) << endl;
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
