#include "functor.hpp"
#ifndef STONE_CPP
#define STONE_CPP
void Stone::operator()(LowLevelBoard* bb,Action& aa, History&,     std::vector<Snake> *snakes) const{
  
  //see if the position is occupied

  if(bb->getStone(aa.getX(),aa.getY()) == aa.getColor()){
    
    std::cout << "fail" << std::endl;
  }
}
#endif
