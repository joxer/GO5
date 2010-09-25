#include "functor.hpp"

void FunctorList::setNext(Functor* next){
  list.push_back(next);
}

Functor* FunctorList::getFunctor() const{
  return *it;
}
void FunctorList::apply_list(GameWrapper *gg){
  for(it = list.begin();it != list.end(); ++it)
    (*(*it))(gg);
}

FunctorList::~FunctorList(){
  for(it = list.begin(); it != list.end(); ++it)
      delete(*it);
}
