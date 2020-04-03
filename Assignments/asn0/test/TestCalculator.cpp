#include "Calculator.h"
#include "Exception.h"
#include "gtest/gtest.h"

TEST(TestCalculator, addTest) {
  Calculator calc;
  EXPECT_EQ(177, calc.add(177, 0));
}
TEST(TestCalculator, subTest) {
  Calculator calc;
  EXPECT_EQ(170, calc.sub(177, 7));
}
TEST(TestCalculator, multTest) {
  Calculator calc;
  EXPECT_EQ(170, calc.mult(17, 10));
}
TEST(TestCalculator, divTest) {
  Calculator calc;
  EXPECT_EQ(15, calc.div(150, 10));
  EXPECT_THROW(calc.div(150, 0), div_by_zero_error);
}


