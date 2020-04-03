#include "Circle.h"
#include <cmath>
#include "Exceptions.h"
#include "gtest/gtest.h"


TEST(TestCircle, getRadiusTesting) {
  Circle c(5.5);
  ASSERT_EQ(5.5, c.getRadius());
}

TEST(TestCircle, getAreaTesting) {
  double a;
  Circle c(3.2);
  a = M_PI*(pow(3.2, 2));

  ASSERT_EQ(a, c.area());
}

TEST(TestCircle, getPerimeterTesting) {
  double p;
  Circle c(4.6);
  p = 2*M_PI*(4.6);

  ASSERT_EQ(p, c.perimeter());
}

TEST(TestCircle, parameterErrorTesting) {
  EXPECT_THROW(Circle C(-1.2), invalid_parameter_error);
  EXPECT_THROW(Circle C(-89.4), invalid_parameter_error);
}
