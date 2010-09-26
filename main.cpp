#include "board.hpp"
#include "functor.hpp"
#include <exception>
int main(){
  
  Board b;
  try{
    b.putStone(0,1,2);
    b.putStone(0,2,1);
    b.putStone(1,0,2);
    b.putStone(2,2,1);
    b.putStone(2,1,2);
    b.putStone(1,3,1);
    b.putStone(1,1,1);
    b.putStone(1,2,2);
    b.putStone(1,1,1);
    b.printBoard();
  }catch(StoneException e){

    std::cout << e.what() << std::endl;
  }
  catch(GoException e){
    
    std::cout << e.what() << std::endl;
  }

  return 0;
}
