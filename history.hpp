#include <vector>

#ifndef HISTORY_CPP
#define HISTORY_CPP
#include "action.hpp"

/*


Implementing History for the ko rule

 */

class History{
  std::vector<Action> actions;
public:
    History(){


  }
  void addAction(Action a){

    actions.push_back(a);

  }
  void addAction(int x, int y, int color){
    Action tmpa(x,y,color);
    actions.push_back(tmpa);
    
  }

  std::vector<Action> getActions(){

    return actions;
  }
  Action getLastAction(){

    return actions.back();
  }

  int size(){

    return actions.size();
  }

};

#endif
