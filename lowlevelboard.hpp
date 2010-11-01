#include <iostream>
#include <cstring>
#ifndef GO_LOWLEVELBOARD_HPP
#define GO_LOWLEVELBOARD_HPP

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
  void putStone(int, int, int);
  int getStone(int, int);
  int** getBoard();
  void copyBoard(LowLevelBoard*);
};
#endif
