//#define DEBUG
#include "board.hpp"
#include "functor.hpp"
#include "ia.hpp"
#include <exception>
#include <cstdlib>
#include <ctime>

int main(){
  try{
  Board b;
  IA ia(1);
  int i = 0;

  b.putStone(0,1,1);
  b.putStone(1,0,1);
  b.putStone(0,2,2);
  b.putStone(2,2,2);
  
  b.putStone(1,1,1);
  std::cout << std::endl;
    b.getInfluenceMap()->printBoard();
  std::cout << std::endl;
  b.printBoard();

  ia.generate_move2(b);
  

  }
  catch (KoException e){
 std::cout << e.what() << std::endl;

  }
  catch(GoException e){
    
    std::cout << e.what() << std::endl;
  }

  return 0;
}

