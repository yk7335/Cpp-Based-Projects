#ifndef COLLECTION_H
#define COLLECTION_H


#include <string>
using namespace std;

template<class obj, class F1, class F2>
class Collection{
private:
    obj *array;
    int size;
    int capacity;

    void resize(){
      if(capacity == 0){capacity = 2;}
        else{capacity = 2*capacity;}
      obj *c_Temp = new obj[capacity];
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
        array = new obj[capacity];
      } // constructor W arguement

    Collection(const Collection &c){
        size = c.size;
        capacity = c.capacity;
        array = new obj[capacity];
        for(int i = 0; i < size; i++){
          array[i] = c.array[i];
        }
    } // copy constructor
    Collection& operator = (const Collection &c){
      if(&c != this){
        delete[] array;
        size = c.size;
        capacity = c.capacity;
        array = new obj[capacity]; // allocating memory
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

    Collection(Collection&& c) //move constructor
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


    void insert_item(const obj& sb){
      if(size == capacity){
        resize();
      }
      array[size] = sb;
      size+=1;
    } // should use resize

    bool contains(const obj& sb){
      for(int i = 0; i < size; i++){
        if(array[i] == sb){return true;}
      }
        return false;
    }

    obj remove_any_itme(){
      if(size == 0){
        throw "array is empty";
      }else{
        int Ran_Num = rand() % size;
        obj Removed_Ball = array[Ran_Num];
        for(int i = Ran_Num+1; i < size; i++){
          array[i-1] = array[i];
        }
        size--;
        return Removed_Ball;
      }
    }

    void remove_this_item(const obj& sb){
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

    int total_items(F2 s) const{
      int num = 0;
      for(int i = 0; i < size; i++){
        if(array[i].get_size() == s){num++;}
      }
      return num;
    }

    int total_items(F1 t) const{
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

    obj& operator[](int f){
      return array[f];
    }

    const obj& operator[](int f) const{
      return array[f];
    }



};

template<class obj, class F1, class F2>
Collection<obj, F1, F2> make_union(const Collection<obj, F1, F2>& c1, const Collection<obj, F1, F2>& c2){
  Collection<obj, F1, F2> c3;
  int i = 0;
  for(i; i < c1.total_items(); i++){
    c3.insert_item(c1[i]);
  }
  for(int j = 0; j < c2.total_items(); j++){
    c3.insert_item(c2[j]);
  }
  return c3;
}

template<typename obj, typename F1, typename F2>
void swap(Collection<obj, F1, F2>& c1, Collection<obj, F1, F2>& c2){
  Collection<obj, F1, F2> temp = move(c1);
  c1 = c2;
  c2 = temp;

  /*Collection temp = std::move(c1);
  c1 = std::move(c2);
  c2 = std::move(temp);*/
}

enum class Sort_choice{bubble_sort, insertion_sort, selection_sort};

template<class obj, class F1, class F2>
void sort_by_size(Collection<obj, F1, F2>& c, Sort_choice sort){
  switch (sort) {
    case Sort_choice::bubble_sort:{
      for(int i = 0; i < c.total_items()-1; i++){
        for(int j = 0; j < c.total_items() - 1 - i; j++){
          if(c[j].get_size() > c[j+1].get_size()){
            obj temp = c[j+1];
            c[j+1] = c[j];
            c[j] = temp;}}}
      break;}
    case Sort_choice::insertion_sort:{
    int m = 0;
      for(int i = 1; i < c.total_items(); i++){
        obj temp = c[i];
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
        obj temp = c[min_spot];
        c[min_spot] = c[i];
        c[i] = temp;
      }
      break;}
  }
}



#endif
