#include "functor.hpp"

void FunctorList::setNext(Functor* next){
  list.push_back(next);
}

Functor* FunctorList::getFunctor() const{
  return *it;
}
void FunctorList::apply_list(LowLevelBoard* bb, Action& aa, History& hh,  std::vector < Snake > *snakes){
  for(it = list.begin();it != list.end(); ++it)
    (*(*it))(bb, aa, hh, snakes);
}

FunctorList::~FunctorList(){
  for(it = list.begin(); it != list.end(); ++it)
      delete(*it);
}
