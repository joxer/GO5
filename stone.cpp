#include "functor.hpp"
#ifndef STONE_CPP
#define STONE_CPP
void Stone::operator()(GameWrapper* gg) const{
  
  //see if the position is occupied


  LowLevelBoard* tmp_b = gg->board;
  Action* tmp_a = gg->action;


  if(tmp_b->getStone(tmp_a->getX(),tmp_a->getY()) != 0){
    throw StoneException(tmp_a->getX(),tmp_a->getY());
  }
}
#endif
