#ifndef LOWLEVELBOARD_HPP
#define LOWLEVELBOARD_HPP
class LowLevelBoard{

  int **board;
public:
  LowLevelBoard(){

    //alloc board

    board = (int**)malloc(sizeof(int)*9);
    //empty board
    for(int i = 0; i < 9;i++)
      board[i] = (int*)malloc(sizeof(int)*9);
    for(int i= 0; i < 9;i++){
      for(int j=0 ; j < 9;j++)
	board[i][j] = 0;
    }
  }

  void printBoard(){

    for(int i = 0; i < 9;i++){
      for(int j = 0; j < 9;j++)
	
	std::cout << board[i][j];

      std::cout << std::endl;
    }
  }

  void putStone(int x, int y, int color){

      board[x][y] = color;
      
  }
  
  int getStone(int x, int y){

    return board[x][y];
  }

  int** getBoard(){

    return board;
  }

};
#endif
