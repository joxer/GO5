#include <vector>

/*

Structure file

Defines basic structures needed by the game to work

 */



#ifndef ACTION_HPP
#define ACTION_HPP

class Action{
  // This Class enwrap the action to put a stone on the board
  // x y coordinates and color of the point on the board
  
  int x,y,color;
public:
  explicit Action(int xx, int yy, int ccolor);  
  int getX();
  int getY();
  int getColor();
  bool operator==(Action* cc);
};
#endif

#ifndef POSITION_HPP
#define POSITION_HPP
class Position: public Action{
  //Define the position on the board
public:
  explicit Position(int x, int y, int color);
};
#endif
  
#ifndef SNAKE
#define SNAKE

/*

Snake is definited as a group of stones connected all togheter
You can get the occupied position and the liberty position, all enwrapped in vectors

 */

class Snake{
  std::vector<Position> occupies;
  std::vector<Position> liberties;
public:
  explicit Snake(std::vector<Position> pp, std::vector<Position> oo);
  std::vector<Position> getOccupies();
  std::vector<Position> getLiberty();
};

#endif
