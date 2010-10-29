// data: lunedì, ottobre 11 2010

#include <ctime>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include "analysis.hpp"
#ifndef IA_HPP
#define IA_HPP
class IA{
  int color;
 

public:
  IA(int _color):color(_color){
    srand(time(0));
  }
  
  int generate_move(Board& bb, int level){
    
    LowLevelBoard *map = bb.getInfluenceMap();
    std::cout << "level " << level << std::endl;
    map->printRawBoard();
    std::vector < std::pair <Position,float>  > empty;
    float sum1 = 0, sum2 = 0;
    
    for(int i = 0; i < 9;i++)
      for(int j = 0; j < 9;j++)
	if(map->getBoard()[i][j] != 1 || map->getBoard()[i][j] != 2)
	  if(map->getBoard()[i][j] > 9)
	    sum1 += map->getBoard()[i][j];
	  else if(map->getBoard()[i][j] <-0)
	    sum2 += abs(map->getBoard()[i][j]);
    
    
    for(int i = 0; i < 9;i++)
      for(int j = 0; j < 9;j++)
	if(map->getBoard()[i][j] != 1 && map->getBoard()[i][j] != 2){
	  if(color == 1 && map->getBoard()[i][j] > 0){
	    Position pos = Position(i,j,map->getBoard()[i][j]);
	    float cv ;
	    if(empty.size() == 0)
	      cv = (float)map->getBoard()[i][j]/sum1;
	    else
	      cv = map->getBoard()[i][j]/sum1 ;
	    empty.push_back(std::make_pair(pos,cv));
	    
	  }
	  else if(color == 2 && map->getBoard()[i][j] < 0){	
	    Position pos = Position(i,j,map->getBoard()[i][j]);
	    float  cv;
	    if(empty.size() == 0)
	      cv = (float)-map->getBoard()[i][j]/sum2;
	    else
	      cv = -map->getBoard()[i][j]/sum2  ;
	    empty.push_back(std::make_pair(pos,cv));
	    
	  }
	}

    
    
    
    int i = 0;
    float r = (float)rand()/(float)RAND_MAX, o = 0; 
    std::cout << "empty " << empty.size() << std::endl;
    if(empty.size() != 0){
      
      if(level < 3){
	for(int j = 0; j < empty.size();j++){
	  o = 0;
	  try{
	    bb.putStone(empty[j].first.getX(), empty[j].first.getY(), color);
	  }
	  catch(StoneException e){
	    
	    std::cout << e.what() << std::endl;
	    break;
	  }
	  catch (KoException e){
	    std::cout << e.what() << std::endl;
	    break;
	    
	  }
	  IA* b;
	  if(color == 1)
	    b = new IA(2);
	  else
	    b = new IA(1);
	  o = b->generate_move(bb, level+1);
	   
	  std::cout << "level: "  << level << std::endl;
	  
	  bb.removeStone(empty[j].first.getX(), empty[j].first.getY());
	}
      }
    }
    else{

      std::cout << "empty" << std::endl;
      return o;
    }
    //      return empty[i].first.getColor();
  }
  
};

#endif
