#include "board.hpp"

Board::Board(){

    board = new LowLevelBoard(); 
    hh = new History;
  }

Board::~Board(){

    delete(board);
    delete(hh);
}

void Board::putStone(int x, int y, int color){
    
    //TODO: verify the allocation
   
    Stone *ss = new Stone;
    guard<Stone> Stone_guard(ss);
    PutStone *ps = new PutStone;
    guard<PutStone> PutStone_guard(ps);
    CaptureOther *co = new CaptureOther;
    guard<CaptureOther> CaptureOther_guard(co);
    Ko *ko = new Ko;
    guard<Ko> Ko_guard(ko);
    VerifyBoard *vb = new VerifyBoard;
    guard<VerifyBoard> VerifyBoard_guard(vb);

    Stone_guard.release();
    PutStone_guard.release();
    CaptureOther_guard.release();
    VerifyBoard_guard.release();
    Ko_guard.release();

    FunctorList ff;
    
    Action ac(x,y,color);
    ff.setNext(ss);
    ff.setNext(ko);
    ff.setNext(ps);
    ff.setNext(co);
    ff.setNext(vb);

    GameWrapper gg;
    gg.board = board;
    gg.action = &ac;
    gg.history = hh;
    gg.snakes=&snakes;

    ff.apply_list(&gg);
   
}

void Board::putStone(Action &ac){
    //TODO: verify the allocation

    Stone *ss = new Stone;
    guard<Stone> Stone_guard(ss);
    PutStone *ps = new PutStone;
    guard<PutStone> PutStone_guard(ps);
    Ko *ko = new Ko;
    guard<Ko> Ko_guard(ko);
    CaptureOther *co = new CaptureOther;
    guard<CaptureOther> CaptureOther_guard(co);
    VerifyBoard *vb = new VerifyBoard;
    guard<VerifyBoard> VerifyBoard_guard(vb);

    Stone_guard.release();
    PutStone_guard.release();
    CaptureOther_guard.release();
    VerifyBoard_guard.release();
    Ko_guard.release();

    FunctorList ff;
    ff.setNext(ss);
    ff.setNext(ko);
    ff.setNext(ps);
    ff.setNext(co);
    ff.setNext(vb);

    GameWrapper gg;
    gg.board = board;
    gg.action = &ac;
    gg.history = hh;
    gg.snakes=&snakes;

    ff.apply_list(&gg);
   
  }



void Board::finalScore(){
    int** tmp_board = board->getBoard();
    std::vector <Position> seki;
    int lib = 0;
    /*  for(int i = 0; i < 9;i++){
      for(int j = 0; j < 9;j++){
	lib = 0;
	if(tmp_board[i][j] == 0 ){
	  if(i > 0 && i < 8)
	    if((tmp_board[i-1][j] ^ tmp_board[i+1][j]) != 0 && tmp_board[i-1][j] != 0 && tmp_board[i+1][j] != 0 && tmp_board[i-1][j] != tmp_board[i+1][j])
	      lib +=1;
	  if(j > 0 && j < 8)
	    if((tmp_board[i][j-1] ^   tmp_board[i][j+1]) != 0  && tmp_board[i][j-1] != 0 && tmp_board[i][j+1] != 0 && tmp_board[i][j-1] != tmp_board[i][j+1])
	      lib +=1;

	  if(i == 0){
	    if(j == 0){
	      if((tmp_board[i+1][j] ^ tmp_board[i][j+1]) != 0  && tmp_board[i+1][j] != 0 && tmp_board[i][j+1] != 0 && tmp_board[i][j+1] != tmp_board[i+1][j])		lib +=1;
	    }
	    else if(j == 8){
	      if((tmp_board[i][j-1] ^ tmp_board[i+1][j]) != 0)
		lib +=1;
	    }
	    else if( j > 0 && j <8){
	      if((tmp_board[i+1][j] ^ tmp_board[i][j+1]) != 0  && tmp_board[i+1][j] != 0 && tmp_board[i][j+1] != 0 && tmp_board[i][j+1] != tmp_board[i+1][j])		
		lib +=1;
	      else if((tmp_board[i+1][j] ^ tmp_board[i][j-1]) != 0  && tmp_board[i+1][j] != 0 && tmp_board[i][j-1] != 0 && tmp_board[i][j-1] != tmp_board[i+1][j])		
		lib +=1;
	    }
	  }
	  else if(i == 8){
	    if(j == 0){
	      if((tmp_board[i-1][j] ^ tmp_board[i][j+1]) != 0  && tmp_board[i-1][j] != 0 && tmp_board[i][j+1] != 0 && tmp_board[i][j+1] != tmp_board[i-1][j])		lib +=1;
	    }
	    else if(j == 8){
	      if((tmp_board[i][j-1] ^ tmp_board[i-1][j]) != 0)
		lib +=1;
	    }
	    else if( j > 0 && j <8){
	      if((tmp_board[i][j-1] ^ tmp_board[i-1][j]) != 0  && tmp_board[i-1][j] != 0 && tmp_board[i][j-1] != 0 && tmp_board[i][j-1] != tmp_board[i-1][j])		
		lib +=1;
	      else if((tmp_board[i][j+1] ^ tmp_board[i-1][j]) != 0  && tmp_board[i][j+1] != 0 && tmp_board[i-1][j] != 0 && tmp_board[i][j+1] != tmp_board[i-1][j])		
		lib +=1;
	    }
	    
	  }
	  if(lib > 0){
	    
	  seki.push_back(Position(i,j,tmp_board[i][j]));
	  tmp_board[i][j] = 8;
	  }
	  }
	  }
	  }
	  
    */
    
    for(int i = 0; i < snakes.size();i++){
      
      lib = 0;
      std::vector<Position> codon = snakes[i].getOccupies(); 
      for(int j = 0; j < codon.size();j++){
	if(codon[j].getX() > 0)
	  if(tmp_board[codon[j].getX()-1][codon[j].getY()] == 0)
	    lib +=1;
	
	if(codon[j].getX() < 8)
	  if(tmp_board[codon[j].getX()+1][codon[j].getY()] == 0)
	    lib +=1;
	if(codon[j].getY() > 0)
	  if(tmp_board[codon[j].getX()][codon[j].getY()-1] == 0)
	    lib +=1;
	if(codon[j].getY() < 8)
	  if(tmp_board[codon[j].getX()][codon[j].getY()+1] == 0)
	    lib +=1;
      }
      if(lib == 1){
	
	std::cout << "wii" << std::endl;
      }

    }

  }


int Board::getStone(int x,int y){
  
  return board->getBoard()[x][y];
}

void Board::printBoard(){
  
  board->printBoard();
}

