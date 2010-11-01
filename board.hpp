/*

Board rappresentantion

 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <utility>

#ifndef GO_BOARD_HPP
#define GO_BOARD_HPP
#include "action.hpp"
#include "lowlevelboard.hpp"
#include "history.hpp"
#include "functor.hpp"
#include "utils.hpp"


/*

Higher rappresentation of the board


 */

class Board{
  
  std::vector < Snake > snakes; // Snakes on the Board (groups of stones)
  LowLevelBoard *board;
  History *hh;
public:
 
  Board();
  ~Board();
  void printBoard();
  int getStone(int, int);
  void finalScore();
  LowLevelBoard* getInfluenceMap();
  void putStone( Action&);
  void putStone(int, int, int);
  void removeStone(int,int);
  LowLevelBoard* getLowLevelBoard();
};
#endif
