#include "board.hpp"
#include "action.hpp"
#include "exception.hpp"
#include "utils.hpp"
#include <list>
#ifndef GO_FUNCTOR_HPP
#define GO_FUNCTOR_HPP

/*


Implemenenting a chain of responsability.

It's composed of 5 action

- See if the place is empty
- See the ko rule (implementing)
- put the stone
- verify if some stones can be eaten
- Update the board

 */


class Functor{
  public:
    virtual void operator()(GameWrapper*) const = 0;
    virtual ~Functor(){}
  };
  
  class FunctorList{
    std::list<Functor*>::iterator  it;
    std::list<Functor*> list;
  public:
    FunctorList(){};
    virtual ~FunctorList();
    virtual void setNext(Functor*);
    virtual Functor* getFunctor() const;
    virtual void apply_list(GameWrapper*);
  };

class Stone: virtual public Functor{
public:
  void operator()(GameWrapper*) const;
  
};

class Ko: virtual public Functor{
public:
  void operator()(GameWrapper*) const;
  
};

class PutStone: virtual public Functor{
public:
  void operator()(GameWrapper*) const;
};

class VerifyBoard: virtual public Functor{
public:
  void operator()(GameWrapper*) const;
};

class CaptureOther: virtual public Functor{
public:
  void operator()(GameWrapper*) const;
};


#endif
