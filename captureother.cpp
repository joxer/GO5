#include "functor.hpp"
#ifndef CAPTUREOTHER_CPP
#define CAPTUREOTHER_CPP
void CaptureOther::operator()(LowLevelBoard* bb,Action& aa, History&,     std::vector < Snake > *snakes) const{

  /*

    Prevent situations like

    .OX.......
    OX........

    where the first point is evalutated has a ground not playable
    So we need to verify if  the first white can be eaten.

   */

  
  for(int i = 0; i < snakes->size();i++){
    if((snakes)->at(i).getLiberty().size() == 1){
      if(aa.getX() == (snakes)->at(i).getLiberty()[0].getX() && aa.getY() == (snakes)->at(i).getLiberty()[0].getY())
	//verify if the only liberty place on the stone to place
	for(int j = 0; j < snakes->at(i).getOccupies().size();j++){

	  bb->getBoard()[snakes->at(i).getOccupies()[j].getX()][snakes->at(i).getOccupies()[j].getY()] = 0;
	  
	}
      
    }
    
    
  }
 
}

#endif
