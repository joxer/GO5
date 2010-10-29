#include <iostream>
#include <cstring>
#ifndef LOWLEVELBOARD_HPP
#define LOWLEVELBOARD_HPP

/*


  Low level rappresentation of the board

  The board is a simple int matrix
 */


class LowLevelBoard{

  int **board;
public:
  LowLevelBoard();
  ~LowLevelBoard();
  void printRawBoard();
  void printBoard();
  void putStone(int x, int y, int color);
  int getStone(int x, int y);
  int** getBoard();
  void copyBoard(LowLevelBoard*);
};
#endif
