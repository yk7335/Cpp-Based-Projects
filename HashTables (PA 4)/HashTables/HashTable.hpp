// YASH KALYANI -- Section: 511 -- Email- yk7335@tamu.edu

#pragma once
#include <ostream>
#include <iostream>
#include <vector>
#include <regex>
#include <list>
#include <utility> 
using namespace std;

template<typename T>
class HashTable {
private:
	int size;
	//IMPLEMENT
	vector<list<pair<int, T>>> hashtable; 
    int hash(const int _key) {
        return _key % size;
    }
public:
    HashTable(const int _size) {
		this->size = _size;
		hashtable = vector<list<pair<int, T>>>(_size);
    }
	
	~HashTable(){
		this->size = 0;
		hashtable.clear();
	}
    
    void insert(const int _key, T _value) {
    	// don't update size bc that is the size of the vector.
		hashtable[hash(_key)].push_back(make_pair(_key,_value));
    }
	
	int minChainLen(){
		//IMPLEMENT
		int num = 0;
		int min = hashtable[0].size();;
		for(int i = 0; i < this->size; i++){
			num = hashtable[i].size();
			if(num <= min){
				min = num;
			}
		}
		return min;
	}
	
	int maxChainLen(){
		//IMPLEMENT
		int num = 0;
		int max = hashtable[0].size();;
		for(int i = 0; i < this->size; i++){
			num = hashtable[i].size();
			if(num >= max){
				max = num;
			}
		}
		return max;
	}
	
	double averageChainLen(){
		double num = 0; 
		for(int i = 0; i < this->size; i++){
			num += hashtable[i].size();
		}
		return num/size;
	}
   
    T* search(int _key) {
		//IMPLEMENT
		int index = hash(_key);
		for(auto it = hashtable[index].begin(); it != this->hashtable[index].end(); it++){
			if(it->first == _key){
				return &(it->second);
			}
		}
		return nullptr;
    }

};

