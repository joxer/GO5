#include "history.hpp"
History::History(){


  }
void History::addAction(Action a){

  actions.push_back(a);
  
}
void History::addAction(int x, int y, int color){
  Action tmpa(x,y,color);
  actions.push_back(tmpa);
  
}

std::vector<Action> History::getActions(){

    return actions;
  }
Action History::getLastAction(){

  return actions.back();
}

void History::removeLastAction(){

  actions.erase(actions.end());
}

int History::size(){

  return actions.size();
}
