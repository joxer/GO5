#include "board.hpp"
#include "functor.hpp"

int main(){
  
  Board b;

  b.putStone(0,1,1);
  b.putStone(0,2,2);
  b.putStone(1,1,2);
  b.putStone(1,0,1);
  b.putStone(0,0,2);
  b.putStone(0,1,1);
  b.printBoard();

  return 0;
}
