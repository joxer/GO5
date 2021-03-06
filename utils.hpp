#include "board.hpp"
#include "action.hpp"
#include <vector>
#ifndef GO_UTILS_HPP
#define GO_UTILS_HPP


template<class T> class guard{ 
  T* p;
public:
  guard(T* p_):p(p_){}
  T* release(){
    p = NULL;
    return p;
  }
  ~guard() throw(){
    delete p;
  }
};

struct GameWrapper{

  LowLevelBoard *board;
  Action *action;
  History *history;
  std::vector<Snake> *snakes;
  
};

#endif
