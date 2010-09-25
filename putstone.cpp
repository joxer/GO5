#include "functor.hpp"
#ifndef PUTSTONE_CPP
#define PUTSTONE_CPP
void PutStone::operator()(GameWrapper* gg) const{
  
  // simply put the stone
  
    LowLevelBoard* tmp_b = gg->board;
    Action* tmp_a = gg->action;

    
    tmp_b->putStone(tmp_a->getX(),tmp_a->getY(),tmp_a->getColor());
 
  
}

#endif
