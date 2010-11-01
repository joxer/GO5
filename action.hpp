#include <vector>

/*

Structure file

Defines basic structures needed by the game to work

 */



#ifndef GO_ACTION_HPP
#define GO_ACTION_HPP

class Action{
  // This Class enwrap the action to put a stone on the board
  // x y coordinates and color of the point on the board
  
  int x,y,color;
public:
  explicit Action(int, int, int);  
  int getX();
  int getY();
  int getColor();
  bool operator==(Action*);
};
#endif

#ifndef GO_POSITION_HPP
#define GO_POSITION_HPP
class Position: public Action{
  //Define the position on the board
public:
  explicit Position(int, int, int);
};
#endif
  
#ifndef GO_SNAKE
#define GO_SNAKE

/*

Snake is definited as a group of stones connected all togheter
You can get the occupied position and the liberty position, all enwrapped in vectors

 */

class Snake{
  std::vector<Position> occupies;
  std::vector<Position> liberties;
public:
  explicit Snake(std::vector<Position> , std::vector<Position> );
  std::vector<Position> getOccupies();
  std::vector<Position> getLiberty();
};

#endif
