#include "Triangle.h"
#include "Exceptions.h"
#include <cmath>
#include "gtest/gtest.h"

TEST(TestTriangle, getSide1) {
  Triangle c(5.5, 4.4, 3.3);
  ASSERT_EQ(5.5, c.getSide1());
}

TEST(TestTriangle, getSide2) {
  Triangle c(5.5, 4.2, 3.3);
  ASSERT_EQ(4.2, c.getSide2());
}

TEST(TestTriangle, getSide3) {
  Triangle c(5.5, 4.4, 3.1);
  ASSERT_EQ(3.1, c.getSide3());
}

TEST(TestTriangle, getPerimeter) {
  Triangle d(3.3, 4.4, 5.5);
  double p = 3.3 + 4.4 + 5.5;

  ASSERT_EQ(p, d.perimeter());
}

TEST(TestTriangle, getArea) {
  double a = 7.4;
  double b = 6.3;
  double c = 5.2;
  double e;
  Triangle d(a, b, c);

  double s = (a+b+c)/2;
  e = sqrt(s*(s-a)*(s-b)*(s-c));

  ASSERT_EQ(e, d.area());
}

TEST(TestTriangle, parameterErrorTesting) {
  EXPECT_THROW(Triangle a(-1.1, 2.2, 3.3), invalid_parameter_error);
  EXPECT_THROW(Triangle b(1.1, -2.2, 3.3), invalid_parameter_error);
  EXPECT_THROW(Triangle c(1.1, 2.2, -3.3), invalid_parameter_error);
  EXPECT_THROW(Triangle d(5, 1, 1), invalid_parameter_error);
  EXPECT_THROW(Triangle e(7, 2, 1), invalid_parameter_error);
}
