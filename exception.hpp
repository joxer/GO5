#include <exception>
#include <iostream>
#include <sstream>

#ifndef GOEXCEPTION
#define GOEXCEPTION
class GoException: public std::exception{
public:
  GoException() throw(){};
  virtual ~GoException() throw(){};
  virtual const char* what() const throw(){
    std::cout << "some errors" << std::endl;
  }
};

class StoneException: public GoException{
  int x,y;

public:
  StoneException(int xx, int yy):x(xx), y(yy){};
  virtual ~StoneException() throw(){};
  virtual const char* what() const throw(){
      std::stringstream out;
      out << "Stone misplaced at (" <<x  << " , " << y << " )";
      return out.str().c_str();
  }
};
class KoException: public GoException{
  
public:
  KoException() throw(){};
  virtual ~KoException() throw(){};
  virtual const char* what() const throw(){
    return "ko rule";
  }

};

#endif
