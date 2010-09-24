#include "board.hpp"
#include "action.hpp"
#include <list>
#ifndef FUNCTOR_HPP
#define FUNCTOR_HPP

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
    virtual void operator()(LowLevelBoard*,Action&, History&, std::vector < Snake >*) const = 0;
    virtual ~Functor(){}
  };
  
  class FunctorList{
    std::list<Functor*>::iterator  it;
    std::list<Functor*> list;
  public:
    FunctorList(){};
    virtual ~FunctorList();
    virtual void setNext(Functor* next);
    virtual Functor* getFunctor() const;
    virtual void apply_list(LowLevelBoard*,Action&,History&,std::vector < Snake > *);
  };

class Stone: virtual public Functor{
public:
  void operator()(LowLevelBoard*,Action&,History&, std::vector < Snake > *) const;
  
};

class Ko: virtual public Functor{
public:
  void operator()(LowLevelBoard*,Action&, History&, std::vector < Snake > *) const;
  
};

class PutStone: virtual public Functor{
public:
  void operator()(LowLevelBoard*, Action&, History&, std::vector < Snake > *) const;
};

class VerifyBoard: virtual public Functor{
public:
  void operator()(LowLevelBoard*, Action&, History&, std::vector < Snake > *) const;
};

class CaptureOther: virtual public Functor{
public:
  void operator()(LowLevelBoard*, Action&, History&, std::vector < Snake > *) const;
};


#endif
