#include "lowlevelboard.hpp"

LowLevelBoard::LowLevelBoard(){

    //alloc board

  board = new int*[9];
    //empty board
    for(int i = 0; i < 9;i++)
      board[i] = new int[9];
    for(int i= 0; i < 9;i++){
      for(int j=0 ; j < 9;j++)
	board[i][j] = 0;
    }
  }
LowLevelBoard::~LowLevelBoard(){
    for(int i = 0; i < 9;i++)
      delete[] board[i];
    delete[] board;
  }
void LowLevelBoard::printRawBoard(){

    for(int i = 0; i < 9;i++){
      for(int j = 0; j < 9;j++)
	
	std::cout << board[i][j] << "  ";

      std::cout << std::endl;
    }
  }
void LowLevelBoard::printBoard(){

  for(int i = 0; i < 9;i++){
    for(int j = 0; j < 9;j++)
      
      if( board[i][j]  == 0){
	std::cout << ". " ;
	
      }
      else if(board[i][j] == 1){
	
	std::cout << "X " ;
      }
      else if(board[i][j] == 2){
	
	std::cout << "O " ;
      }
      else if(board[i][j] >= 10){
	
	std::cout << board[i][j]/10 << " " ;
      }
      else if(board[i][j] <= 10){
	
	std::cout << board[i][j]/(-10)  << " ";
      }

  

      std::cout << std::endl;
    }
  }

void LowLevelBoard::putStone(int x, int y, int color){

      board[x][y] = color;
      
  }
  
int LowLevelBoard::getStone(int x, int y){

    return board[x][y];
  }

int** LowLevelBoard::getBoard(){
  
  return board;
  }

void LowLevelBoard::copyBoard(LowLevelBoard* ll){
  for(int i = 0; i < 9;i++)
    for(int j = 0; j < 9;j++)
      board[i][j] = ll->getBoard()[i][j];
}
