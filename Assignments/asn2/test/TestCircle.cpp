/**
* @author Shannon Abeda
* @date 2020-02-24
*/


#include "Circle.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestCircle, getRadiusTest) {
  Circle c(5.5);
  ASSERT_EQ(5.5, c.getRadius());
}

TEST(TestCircle, getAreaTest) {
  Circle c(2.4);
  ASSERT_NEAR(18.1, c.area(), 0.01);
}

TEST(TestCircle, getPerimeterTest) {
  Circle c(4.6);
  ASSERT_NEAR(28.9, c.perimeter(), 0.01);
}

TEST(TestCircle, exceptionTest) {
EXPECT_THROW(Circle(-1), invalid_parameter_error);
EXPECT_THROW(Circle(-5.5), invalid_parameter_error);
EXPECT_THROW(Circle(-100.0), invalid_parameter_error);
}
