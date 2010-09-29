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
  History();
  void addAction(Action a);
  void addAction(int x, int y, int color);

  std::vector<Action> getActions();
  Action getLastAction();
  int size();

};

#endif
