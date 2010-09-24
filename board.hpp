/*

Board rappresentantion

 */

#include <iostream>
#include <cstdlib>

#ifndef BOARD_HPP
#define BOARD_HPP
#include "action.hpp"
#include "lowlevelboard.hpp"
#include "history.hpp"
#include "functor.hpp"
/*

Higher rappresentation of the board


 */

class Board{
  
  std::vector < Snake > snakes; // Snakes on the Board (groups of stones)
  LowLevelBoard *board;
  History *hh;
public:
  Board(){

    board = new LowLevelBoard(); 
    hh = new History;
  }
  ~Board(){

    delete(board);
    delete(hh);
  }

  void putStone(int x, int y, int color){
    
    //TODO: verify the allocation

    Stone *ss = new Stone;
    PutStone *mm = new PutStone;
    VerifyBoard *vv = new VerifyBoard;
    History hist;
    FunctorList ff;
    Action ac(x,y,color);
    CaptureOther *cc = new CaptureOther;
   
    ff.setNext(ss);
    ff.setNext(mm);
    ff.setNext(cc);
    ff.setNext(vv);
    ff.apply_list(board, ac, hist, &snakes);
   
  }

  void putStone(Action &ac){
    //TODO: verify the allocation
    Stone *ss = new Stone;
    PutStone *mm = new PutStone;
    CaptureOther *oo = new CaptureOther;
    VerifyBoard *vv = new VerifyBoard;
    CaptureOther *cc = new CaptureOther;
    History hist;

   
    FunctorList ff;
    ff.setNext(ss);
    ff.setNext(mm);
    ff.setNext(cc);
    ff.setNext(vv);
    ff.apply_list(board, ac, hist, &snakes);
   
  }


  void printBoard(){

    board->printBoard();
  }
};
#endif
