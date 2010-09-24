#include "functor.hpp"
#ifndef KO_CPP
#define KO_CPP
void Ko::operator()(LowLevelBoard bb,int x, int y, int color, History ii){

  if(ii[ii.size()-2] == (new Action(x,y,color))){

    std::cout << "fail" << std::endl;
  }
}
#endif
