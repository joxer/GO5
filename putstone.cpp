#include "functor.hpp"
#ifndef PUTSTONE_CPP
#define PUTSTONE_CPP
void PutStone::operator()(LowLevelBoard* bb,Action& aa, History&, std::vector < Snake > *snakes) const{
  
  // simply put the stone

  bb->putStone(aa.getX(),aa.getY(),aa.getColor());
 
  
}

#endif
