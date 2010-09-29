#include "action.hpp"

 Action::Action(int xx, int yy, int ccolor){
  
  x = xx;
  y = yy;
  color = ccolor;
}

int Action::getX(){
    return x;
  }
int Action::getY(){
  return y;
}

int Action::getColor(){
  return color;
}

bool Action::operator==(Action* cc){
  
  if(x == cc->getX() && y == cc->getY() && color == cc->getColor())
    return true;
  return false;
}


 Position::Position(int x, int y, int color):Action(x,y,color){};


Snake::Snake(std::vector<Position> pp, std::vector<Position> oo): occupies(pp), liberties(oo){};
std::vector<Position> Snake::getOccupies(){
  return occupies;
}
std::vector<Position> Snake::getLiberty(){
  return liberties;
}

