#ifndef CALCULATOR_H
#define CALCULATOR_H


class Calculator {
 public:
  Calculator();
  virtual ~Calculator();
  int add(int x, int y);
  int sub(int x, int y);
  int mult(int x, int y);
  int div(int x, int y);

 private:
  int x, y;
};

#endif // CALCULATOR_H
