#include "functor.hpp"


void VerifyBoard::operator()(GameWrapper* gg) const{
#ifdef DEBUG
  std::cout << "Verifing board"<< std::endl;
#endif
  int **tmp = gg->board->getBoard();
  int lib = 0;
  //clear the snakes history
  gg->snakes->clear();

  /*see each groups of stones

    I use a iterative algorithm, i search for near stones, if the color is the same, it add it to the list and then redo the same process

   */
  for(int i = 0; i < 9;i++){
    for(int j = 0; j < 9;j++){
      if(tmp[i][j] == 1 || tmp[i][j] == 2){
#ifdef DEBUG
	std::cout << "new point" << std::endl;
#endif
	lib = 0;
	int x = i;
	int y = j;
	int mark_color, current_color,piece_color;
	if(tmp[x][y] == 1){
	   current_color = 1;
	   mark_color = 3;
	   piece_color = 4;
	}
	else if(tmp[x][y] == 2){
	  current_color = 2;
	  mark_color = 5;
	  piece_color = 6;
	}
	std::vector<Position> queue, total_points, liberties;
	queue.push_back(Position(x,y, tmp[x][y]));
	total_points.push_back(Position(x,y, tmp[x][y]));
	while(queue.size() != 0){

	  x = queue.front().getX();
	  y = queue.front().getY();
#ifdef DEBUG
	  std::cout << "x=" << x << std::endl;
	  std::cout << "y=" << y << std::endl;

	  
#endif
	  queue.erase(queue.begin());

	  tmp[x][y] = mark_color ;
	  
	  if(x > 0)
	    if(tmp[x-1][y] == current_color){
	      queue.push_back(Position(x-1,y, tmp[x-1][y]));
	      total_points.push_back(Position(x-1,y, tmp[x-1][y]));
	    }
	    else{
	      if(tmp[x-1][y] == 0){
		
		lib+=1;
		tmp[x-1][y] = piece_color;
		liberties.push_back(Position(x-1,y,tmp[x-1][y]));
	      }
	    }
	  if(x < 8)
	    if(tmp[x+1][y] == current_color){
	      queue.push_back(Position(x+1,y, tmp[x+1][y]));
	      total_points.push_back(Position(x+1,y, tmp[x+1][y]));
	    }
	    else{
	      if(tmp[x+1][y] == 0){

		lib+=1;
		tmp[x+1][y] = piece_color;
		liberties.push_back(Position(x+1,y,tmp[x+1][y]));
	      }
	    }
	  
	  if(y > 0)
	    if(tmp[x][y-1] == current_color){
	      queue.push_back(Position(x,y-1, tmp[x][y-1]));
	      total_points.push_back(Position(x,y-1, tmp[x][y-1]));	    
	    }
	    else{
	      if(tmp[x][y-1] == 0){
		
		lib+=1;
		tmp[x][y-1] = piece_color;
		liberties.push_back(Position(x,y-1,tmp[x][y-1]));
	      }
	    }
	  
	  if(x < 8)
	    if(tmp[x][y+1] == current_color){
	      queue.push_back(Position(x,y+1, tmp[x][y+1]));
	      total_points.push_back(Position(x,y+1, tmp[x][y+1]));
	    }
	    else{
	      if(tmp[x][y+1] == 0){
		
		lib+=1;
		tmp[x][y+1] = piece_color;
	      liberties.push_back(Position(x,y+1,tmp[x][y+1]));
	      }
	    }
	  
	}
      
	gg->snakes->push_back(Snake(total_points,liberties));
#ifdef DEBUG
      std::cout << "liberties = " << lib << std::endl;
#endif
      if(lib == 0){
	std::vector<Position>::iterator it;
	for(it = total_points.begin(); it != total_points.end();it++){
	  tmp[it->getX()][it->getY()] = 0;
	}
      }
      
    
      
      
    
      for(int  i = 0; i < 9;i++)
	for(int j = 0; j < 9;j++)
	  if(tmp[i][j] == 3)
	    tmp[i][j] = 1;
	  else if(tmp[i][j] == 4)
	    tmp[i][j] = 0;
	  else if(tmp[i][j] == 5)
	    tmp[i][j] = 2;
	  else if(tmp[i][j] == 6)
	    tmp[i][j] = 0;
      
      }
    }
  }
#ifdef DEBUG
  bb->printBoard();  
#endif
}


