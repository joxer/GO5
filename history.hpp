#include <vector>

#ifndef GO_HISTORY_CPP
#define GO_HISTORY_CPP
#include "action.hpp"

/*


Implementing History for the ko rule

 */

class History{
  std::vector<Action> actions;
public:
  History();
  void addAction(Action);
  void addAction(int, int, int);

  std::vector<Action> getActions();
  Action getLastAction();
  int size();
  void removeLastAction();
};

#endif
