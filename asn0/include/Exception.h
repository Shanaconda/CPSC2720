#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

#include<stdexcept>

/**
* Exception for when the given number is divided by 0
*/

class div_by_zero_error:public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */

  explicit div_by_zero_error(const char* errMessage):
    std::runtime_error(errMessage) {
  }
};
#endif // EXCEPTION_H_INCLUDED
