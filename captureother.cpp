#include "functor.hpp"
#ifndef CAPTUREOTHER_CPP
#define CAPTUREOTHER_CPP
void CaptureOther::operator()(GameWrapper* gg) const{

  /*

    Prevent situations like

    .OX.......
    OX........

    where the first point is evalutated has a ground not playable
    So we need to verify if  the first white can be eaten.

   */

  std::vector<Snake>* snakes = gg->snakes;
  Action* tmp_a = gg->action;
  LowLevelBoard *tmp_b = gg->board;
  for(int i = 0; i < snakes->size();i++){
    if(snakes->at(i).getLiberty().size() == 1){
	if(tmp_a->getX() == snakes->at(i).getLiberty()[0].getX() && tmp_a->getY() == snakes->at(i).getLiberty()[0].getY())
	//verify if the only liberty place on the stone to place
	for(int j = 0; j < snakes->at(i).getOccupies().size();j++){

	  tmp_b->getBoard()[snakes->at(i).getOccupies()[j].getX()][snakes->at(i).getOccupies()[j].getY()] = 0;
	  
	}
      
    }
    
    
  }
 
}

#endif
