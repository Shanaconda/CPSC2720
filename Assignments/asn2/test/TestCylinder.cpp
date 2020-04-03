/**
* @author Shannon Abeda
* @date 2020-02-24
*/

#include "Cylinder.h"
#include "Exceptions.h"
#include <cmath>
#include "gtest/gtest.h"

TEST(TestCylinder, getHeightTest) {
  Cylinder c(2.4, 7.56);
  EXPECT_DOUBLE_EQ(7.56, c.getHeight());
}

TEST(TestCylinder, getRadiusTest) {
  Cylinder c(6.9, 9.86);
  EXPECT_DOUBLE_EQ(6.9, c.getRadius());
}

TEST(TestCylinder, getAreaTest) {
  double a;
  Cylinder c(2.4, 7.56);
  a = (2*M_PI*(2.4*7.56))+((2*M_PI)*(pow(2.4, 2)));
  EXPECT_NEAR(a, c.area(), 0.001);
}

TEST(TestCylinder, getVolumeTest) {
  double v;
  Cylinder c(2.78, 2.34);
  v = M_PI*(pow(2.78, 2))*(2.34);
  EXPECT_DOUBLE_EQ(v, c.volume());
}

TEST(TestCylinder, parameterErrorTesting) {
  EXPECT_THROW(Cylinder c(-5.5, 2.7), invalid_parameter_error);
  EXPECT_THROW(Cylinder c(5.5, -2.7), invalid_parameter_error);
}

