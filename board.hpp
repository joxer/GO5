/*

Board rappresentantion

 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#ifndef BOARD_HPP
#define BOARD_HPP
#include "action.hpp"
#include "lowlevelboard.hpp"
#include "history.hpp"
#include "functor.hpp"
#include "utils.hpp"
#include <utility>

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
  int getStone(int x,int y);
  void finalScore();
  LowLevelBoard* getInfluenceMap();
  void putStone(Action &ac);
  void putStone(int x, int y, int color);

};
#endif
