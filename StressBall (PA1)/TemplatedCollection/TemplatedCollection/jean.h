#ifndef jeans_h
#define jeans_h

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

enum class Jeans_colors{
    blue,white,red,black
};

enum class Jeans_sizes{
    small,medium,large
};

class Jeans{
private:
    Jeans_colors color;
    Jeans_sizes size;
public:
    //constructor
    Jeans(Jeans_colors c, Jeans_sizes s){
        color = c;
        size = s;
    }
    Jeans() : color(Jeans_colors(rand() % 4)), size(Jeans_sizes(rand() % 3)) {}

    Jeans_sizes get_size() const{
        return size;
    }

    Jeans_colors get_color() const{
        return color;
    }

    bool operator==(const Jeans& j){
        bool color1=false;
        bool size1=false;
        if(this->get_color() == j.get_color())
            color1=true;
        if(this->get_size() == j.get_size())
            size1=true;
        if(color1 && size1)
            return true;
        else
            return false;
    }

    void print_jeans() const{
        switch(get_color()){
            case Jeans_colors::blue:
                cout << "blue";
                break;
            case Jeans_colors::white:
                cout << "white";
                break;
            case Jeans_colors::red:
                cout << "red";
                break;
            case Jeans_colors::black:
                cout << "black";
                break;
        }
        switch(get_size()){
            case Jeans_sizes::small:
                cout << ", small";
                break;
            case Jeans_sizes::medium:
                cout << ", medium";
                break;
            case Jeans_sizes::large:
                cout << ", large";
                break;}}};

ostream& operator<<(ostream& o, const Jeans& j){
    j.print_jeans();
    return o;
}

#endif
