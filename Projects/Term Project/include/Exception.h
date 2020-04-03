/*
* CPSC 2720 Spring 2020
* Copyright 2020 Shannon Abeda <s.abeda@uleth.ca>
*/
#ifndef INCLUDE_EXCEPTION_H_
#define INCLUDE_EXCEPTION_H_

#include <stdexcept>
/**
* Exception for an invalid input passed to a constructor or method.
*/
class invalid_input: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit invalid_input(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};
class invalid_parameter: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit invalid_parameter(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};


class input_failure: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit input_failure(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};
/**
* Exception for an invalid name passed to a constructor or method.
*
*/
class invalid_name: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit invalid_name(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

class size_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit size_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

#endif  // INCLUDE_EXCEPTION_H_



