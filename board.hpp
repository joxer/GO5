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
#include "utils.hpp"
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
    guard<Stone> Stone_guard(ss);
    PutStone *ps = new PutStone;
    guard<PutStone> PutStone_guard(ps);
    CaptureOther *co = new CaptureOther;
    guard<CaptureOther> CaptureOther_guard(co);
    VerifyBoard *vb = new VerifyBoard;
    guard<VerifyBoard> VerifyBoard_guard(vb);

    Stone_guard.release();
    PutStone_guard.release();
    CaptureOther_guard.release();
    VerifyBoard_guard.release();
    

    FunctorList ff;
    
    Action ac(x,y,color);
    ff.setNext(ss);
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

  void putStone(Action &ac){
    //TODO: verify the allocation

    Stone *ss = new Stone;
    guard<Stone> Stone_guard(ss);
    PutStone *ps = new PutStone;
    guard<PutStone> PutStone_guard(ps);
    CaptureOther *co = new CaptureOther;
    guard<CaptureOther> CaptureOther_guard(co);
    VerifyBoard *vb = new VerifyBoard;
    guard<VerifyBoard> VerifyBoard_guard(vb);

    Stone_guard.release();
    PutStone_guard.release();
    CaptureOther_guard.release();
    VerifyBoard_guard.release();


    FunctorList ff;
    ff.setNext(ss);
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


  void printBoard(){

    board->printBoard();
  }
};
#endif
