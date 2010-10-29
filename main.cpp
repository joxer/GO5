#define DEBUG
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
  //  while(i++ < 50){
  //  int a = rand()%9, d = rand()%9, c = rand()%2+1;

  b.putStone(0,1,1);
  b.putStone(1,0,1);
  b.putStone(0,2,2);
  b.putStone(2,2,2);
  
  b.putStone(1,1,1);
  std::cout << std::endl;
    b.getInfluenceMap()->printBoard();
  std::cout << std::endl;
  b.printBoard();
  Go_Analysis::under_attack_group(b.getLowLevelBoard(), 1,1,1);
    //  ia.generate_move(b,0);
  //  }
    
  /*
    int i = 0;
    std::vector<std::pair< int, int> > boo;
    while(i < 100){
      i++;
      int c = ia.generate_move(b,0);
      int j = 0, not_found = 1;
            for(j = 0; j < boo.size();j++){

	if(c == boo[j].second){

	  boo[j].first +=1;
	  not_found = 0;
	  break;
	}
	else 
	  not_found = 1;
      }
      if(not_found == 1){

	  boo.push_back(std::make_pair(1,c));
      }

    }
      
    for(int i = 0; i < boo.size();i++){
      
      std::cout << boo[i].first << " " << boo[i].second << std::endl;
    

      }
      */
   
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
