#ifndef COLLECTION_H
#define COLLECTION_H
#include "Stress_ball.h"
using namespace std;

class Collection{
private:
    Stress_ball *array;
    int size;
    int capacity;

    void resize(){
      if(capacity == 0){capacity = 2;}
        else{capacity = 2*capacity;}
      Stress_ball *c_Temp = new Stress_ball[capacity];
      for(int i = 0; i < size; i++){
        c_Temp[i] = array[i];
      }
      delete[] array;
      array = c_Temp;}

  public:
    Collection() : array(nullptr), size(0), capacity(0) {}// basic constructor
    Collection(int s){
        size = 0;
        capacity = s;
        array = new Stress_ball[capacity];
      } // constructor W arguement

    Collection(const Collection &c){
        size = c.size;
        capacity = c.capacity;
        array = new Stress_ball[capacity];
        for(int i = 0; i < size; i++){
          array[i] = c.array[i];
        }
    } // copy constructor
    Collection& operator = (const Collection &c){
      if(&c != this){
        delete[] array;
        size = c.size;
        capacity = c.capacity;
        array = new Stress_ball[capacity]; // allocating memory
        for(int i = 0; i < size; i++){
          array[i] = c.array[i];
        }
      }
      return *this;
    } // copy assignment

    ~Collection(){
      delete[] array;
      array = nullptr;
      size = 0;
      capacity = 0;} // destructor

    Collection(Collection&& c): array(nullptr), // move constructor
                                size(0),
                                capacity(0)
    {
      array = c.array;
      size = c.size;
      capacity = c.capacity;
      c.array = nullptr;
      c.size = 0;
      c.capacity = 0;
    }

    Collection& operator=(Collection&& c){
      if(&c == this){
        return *this; // checks you see if your copying itself it is return this's refernce
      }else{
      delete[] array; // deleting the held resources
      array = c.array;
      size = c.size;
      capacity = c.capacity;
      c.array = nullptr;
      c.size = 0;
      c.capacity = 0;
      return *this;
    }} // move assignment


    void insert_item(const Stress_ball& sb){
      if(size == capacity){
        resize();
      }
      array[size] = sb;
      size+=1;
    } // should use resize

    bool contains(const Stress_ball& sb) const{
      for(int i = 0; i < size; i++){
        if(array[i] == sb){return true;}
      }
        return false;
    }

    Stress_ball remove_any_itme(){
      if(size == 0){
        throw "array is empty";
      }else{
        int Ran_Num = rand() % size;
        Stress_ball Removed_Ball = array[Ran_Num];
        for(int i = Ran_Num+1; i < size; i++){
          array[i-1] = array[i];
        }
        size--;
        return Removed_Ball;
      }
    }

    void remove_this_item(const Stress_ball& sb){
      if(size == 0){
        throw "array is empty";
      }else{
        int j = 0;
          for(int i = 0; i < size; i++){
            if(array[i] == sb){
              j = i;
            }
          }for(int i = j+1; i < size; i++){
            array[i-1] = array[i];
          }}
      size--;
    }

    void make_empty(){
      if(array!=nullptr){
      delete[] array;
      array = nullptr;
      size = 0;
      capacity = 0;}}

    bool is_empty() const{
      if(size == 0){
        return true;
      }else{return false;}
    }

    int total_items() const{
      return size;
    }

    int total_items(Stress_ball_sizes s) const{
      int num = 0;
      for(int i = 0; i < size; i++){
        if(array[i].get_size() == s){num++;}
      }
      return num;
    }

    int total_items(Stress_ball_colors t) const{
      int num = 0;
      for(int i = 0; i < size; i++){
        if(array[i].get_color() == t){num++;}
      }
      return num;
    }

    void print_items() const{
      for(int i = 0; i < size; i++){
        std::cout << array[i];
      }
    }

    Stress_ball& operator[](int f){
      return array[f];
    }

    const Stress_ball& operator[](int f) const{
      return array[f];
    }



};

std::istream& operator >> (std::istream& is, Collection& c){
  Stress_ball_sizes siz;
  Stress_ball_colors col;
  string co;
  string s;
  while(!is.eof()){
    is >> co;
    is >> s;
    if(is.fail()){break;}

    if(co == "red"){col = Stress_ball_colors::red;}
    else if(co == "blue"){col = Stress_ball_colors::blue;}
    else if(co == "yellow"){col = Stress_ball_colors::yellow;}
    else{col = Stress_ball_colors::green;}

    if(s == "small"){siz = Stress_ball_sizes::small;}
    else if(s == "medium"){siz = Stress_ball_sizes::medium;}
    else{siz = Stress_ball_sizes::large;}
    Stress_ball temp(col,siz);
    c.insert_item(temp);
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const Collection& c){
  for(int i = 0; i < c.total_items(); i++){
    if(c[i].get_color() == Stress_ball_colors::red){
      os << "(red, ";
    }else if(c[i].get_color() == Stress_ball_colors::blue){
      os << "(blue, ";
    }else if(c[i].get_color() == Stress_ball_colors::yellow){
      os << "(yellow, ";
    }else{
      os << "(green, ";
    }
    if(c[i].get_size() == Stress_ball_sizes::small){
      os << "small)";
    }else if(c[i].get_size() == Stress_ball_sizes::medium){
      os << "medium)";
    }else if(c[i].get_size() == Stress_ball_sizes::large){
      os << "large)";
    }
  }
  return os;
}

Collection make_union(const Collection& c1, const Collection& c2){
  Collection c3;
  int i = 0;
  for(i; i < c1.total_items(); i++){
    c3.insert_item(c1[i]);
  }
  for(int j = 0; j < c2.total_items(); j++){
    c3.insert_item(c2[j]);
  }
  return c3;
}

void swap(Collection& c1, Collection& c2){
  Collection temp = Collection(c1);
  c1 = c2;
  c2 = temp;
/*
  Collection temp = std::move(c1);
  c1 = std::move(c2);
  c2 = std::move(temp);*/
}

enum class Sort_choice{bubble_sort, insertion_sort, selection_sort};

void sort_by_size(Collection& c, Sort_choice sort){
  switch (sort) {
    case Sort_choice::bubble_sort:{
      for(int i = 0; i < c.total_items()-1; i++){
        for(int j = 0; j < c.total_items() - 1 - i; j++){
          if(c[j].get_size() > c[j+1].get_size()){
            Stress_ball temp = c[j+1];
            c[j+1] = c[j];
            c[j] = temp;}}}
      break;}
    case Sort_choice::insertion_sort:{
    int m = 0;
      for(int i = 1; i < c.total_items(); i++){
        Stress_ball temp = c[i];
        m = i - 1;
        while(m>=0 && c[m].get_size() > temp.get_size()){
          c[m+1] = c[m];
          m--;
        }
        c[m+1] = temp;
      }
      break;}
    case Sort_choice::selection_sort:{
      int min_spot = 0;
      for(int i = 0; i < c.total_items()-1; i++){
        min_spot = i;
        for(int j = i+1; j < c.total_items(); j++){
          if(c[j].get_size() < c[min_spot].get_size()){min_spot = j;}
        }
        Stress_ball temp = c[min_spot];
        c[min_spot] = c[i];
        c[i] = temp;
      }
      break;}
  }
}



#endif
