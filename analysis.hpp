// data: venerdì, ottobre 22 2010
#ifndef GO_ANALYSIS_HPP
#define GO_ANALYSIS_HPP

#endif

namespace Go_Analysis{

  std::vector<Position> liberties_group(LowLevelBoard* map, int color, int i, int j){
    std::vector<Position> queue, liberties;
    int** tmp =  map->getBoard();
    if(tmp[i][j] == color){
      int lib = 0;
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

      queue.push_back(Position(x,y, tmp[x][y]));

      while(queue.size() != 0){
	
	x = queue.front().getX();
	y = queue.front().getY();
	queue.erase(queue.begin());
	tmp[x][y] = mark_color ;
	
	if(x > 0)
	  if(tmp[x-1][y] == current_color){
	    queue.push_back(Position(x-1,y, tmp[x-1][y]));

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

	  }
	  else{
	    if(tmp[x][y-1] == 0){
	      
	      lib+=1;
	      tmp[x][y-1] = piece_color;
	      liberties.push_back(Position(x,y-1,tmp[x][y-1]));
	    }
	  }
	
	if(y < 8)
	  if(tmp[x][y+1] == current_color){
	    queue.push_back(Position(x,y+1, tmp[x][y+1]));

	  }
	  else{
	    if(tmp[x][y+1] == 0){
	      
	      lib+=1;
	      tmp[x][y+1] = piece_color;
	      liberties.push_back(Position(x,y+1,tmp[x][y+1]));
	    }
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
    return liberties;
  }
  
  
  std::vector< std::vector < Position > > under_attack_group(LowLevelBoard* map, int color,int i,int j){
    int opponent_color;
    if(color == 1)
      opponent_color = 2;
    else
      opponent_color = 1;
    std::vector <Position> libert = liberties_group(map, color,i,j);
    std::vector <Position> under_attack, probable_move,internal_point;
    std::vector<Position>::iterator it;
    int** tmp = map->getBoard();
    int cc;
    for(it = libert.begin(); it != libert.end();it++){
      cc = 0;
      if(it->getX() > 0)
	if(tmp[it->getX()-1][it->getY()] == opponent_color)
	  cc+=1;
      if(it->getX() < 8)
	if(tmp[it->getX()+1][it->getY()] == opponent_color){
	  cc+=1;
	}
      if(it->getY() > 0)
	if(tmp[it->getX()][it->getY()-1] == opponent_color){
	  cc+=1;
	}
      if(it->getY() < 8)
	if(tmp[it->getX()][it->getY()+1] == opponent_color){
	  cc+=1;
	}
      
      if(cc == 0){
#ifdef DEBUG
	std::cout << it->getX() << " " << it->getY() << std::endl;
#endif
	internal_point.push_back(*it);
      }
      else if(cc == 2){
#ifdef DEBUG
	std::cout << it->getX() << " " << it->getY() << std::endl;
#endif
	under_attack.push_back(*it);

      }
    }
#ifdef DEBUG
    std::cout << libert.size() << std::endl;

      std::cout << "end analysis" << std::endl;
#endif

      std::vector < std::vector < Position > > final_vector;
      final_vector.push_back(under_attack);
      final_vector.push_back(internal_point);
      return final_vector;
  }

};
