#ifndef STRESS_BALL_H
#define STRESS_BALL_H
#include <string>

enum class Stress_ball_colors{
  red,blue,yellow,green
};
enum class Stress_ball_sizes{
  small,medium,large
};

class Stress_ball{
  Stress_ball_colors color;
  Stress_ball_sizes size;
public:
    //creates a stress ball with a random color and size
  Stress_ball()
{
      color = Stress_ball_colors(rand()%4);
      size = Stress_ball_sizes(rand()%3);
}
    // creates a stress balll with the given color (c) and given size (s)
  Stress_ball(Stress_ball_colors c, Stress_ball_sizes s){
    color = c;
    size = s;
    }

  // returns the color of a stress ball using its enum class
  Stress_ball_colors get_color() const{
      return color;}
    // returns the size of a stress ball using its enum class
  Stress_ball_sizes get_size() const{
      return size;}


bool operator == (const Stress_ball& sb)
{
  bool col = false;
  bool siz = false;
  if(get_color() == sb.get_color()){col = true;}
  if(get_size() == sb.get_size()){siz = true;}
  if(col && siz){return true;}
    else{return false;}
}};

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb){

  if(sb.get_color() == Stress_ball_colors::red){
  o << "(" << "red" << ", ";
  }else if(sb.get_color() == Stress_ball_colors::blue){
    o << "(" << "blue" << ", ";
  }else if(sb.get_color() == Stress_ball_colors::yellow){
    o << "(" << "yellow" << ", ";
  }else {
    o << "(" << "green" << ", ";}

    if(sb.get_size() == Stress_ball_sizes::small){
      o << "small" << ")";
    }else if(sb.get_size() == Stress_ball_sizes::medium){
      o << "medium" << ")";
    }else{
      o << "Large" << ")";
    }


  return o;}



#endif
