#include "board.hpp"
#include "functor.hpp"
#include <exception>
#include <cstdlib>
#include <ctime>
int main(){
  
  Board b;
  try{
    srand(time(0));
    for(int i = 0; i < 29;i++){
      int tmp1 = rand()%9;
      int tmp2 = rand()%9;
      int color = (tmp1*tmp2)%2 + 1;
      b.printBoard();
      std::cout << std::endl;
      if(b.getStone(tmp1, tmp2) == 0)
	b.putStone(tmp1,tmp2,color);

    }

    
    b.putStone(1,2,2);
    b.finalScore();
    b.printBoard();
  }catch(StoneException e){

    std::cout << e.what() << std::endl;
  }
  catch (KoException e){
 std::cout << e.what() << std::endl;

  }
  catch(GoException e){
    
    std::cout << e.what() << std::endl;
  }

  return 0;
}
