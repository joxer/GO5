#include "functor.hpp"
#ifndef KO_CPP
#define KO_CPP
void Ko::operator()(GameWrapper* gg) const{
  
  LowLevelBoard* tmp_b = gg->board;
  Action* tmp_a = gg->action;
  History* hh = gg->history;

  if(hh->size() > 1){
    Action mu = hh->getActions().at(hh->size()-2);
    if(mu == tmp_a){
      std::cout << hh->getActions().at(hh->size()-2).getX() << std::endl;
      std::cout << hh->getActions().at(hh->size()-2).getY() << std::endl;
      std::cout << "ko rule" << std::endl;
    }
  }
}
#endif
