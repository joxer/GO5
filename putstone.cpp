#include "functor.hpp"
#ifndef PUTSTONE_CPP
#define PUTSTONE_CPP
void PutStone::operator()(GameWrapper* gg) const{
  
  // simply put the stone
  
    LowLevelBoard* tmp_b = gg->board;
    Action* tmp_a = gg->action;
    History* tmp_h = gg->history;
    
    tmp_b->putStone(tmp_a->getX(),tmp_a->getY(),tmp_a->getColor());
    tmp_h->addAction(*tmp_a);
}

#endif
