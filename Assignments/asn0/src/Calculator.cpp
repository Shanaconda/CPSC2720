#include "Calculator.h"
#include "Exception.h"

Calculator::Calculator() {
  //ctor
}

Calculator::~Calculator() {
  //dtor
}

int Calculator::add(int x, int y) {

  return x+y;

}

int Calculator::sub(int x, int y) {

  return x-y;

}

int Calculator::mult(int x, int y) {

    return x*y;

 }

 int Calculator::div(int x, int y) {
  if(y==0)
    throw div_by_zero_error("Error");
    return x/y;
 }
