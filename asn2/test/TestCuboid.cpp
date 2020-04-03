/**
* @author Shannon Abeda
* @date 2020-02-24
*/


#include "Cuboid.h"
#include <cmath>
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestCuboid, getWidthTest) {
  Cuboid a(5.5, 4.2, 2.3);
 EXPECT_DOUBLE_EQ(5.5, a.getWidth());
}

TEST(TestCuboid, getHeightTest) {
  Cuboid a(5.5, 4.2, 2.3);
  EXPECT_DOUBLE_EQ(4.2, a.getHeight());
}

TEST(TestCuboid, getLengthTest) {
  Cuboid a(5.5, 4.2, 2.3);
  EXPECT_DOUBLE_EQ(2.3, a.getLength());
}

TEST(TestCuboid, getAreaTest) {
  double a;
  Cuboid b(5.5, 4.2, 2.3);
  a = 2*((2.3*5.5)+(5.5*4.2)+(4.2*2.3));
  EXPECT_NEAR(a, b.area(), 0.001);
}

TEST(TestCuboid, getVolumeTest) {
  double v;
  Cuboid a(6.2, 4.4, 2.2);
  v = 6.2 * 4.4 * 2.2;
  EXPECT_DOUBLE_EQ(v, a.volume());
}

TEST(TestCuboid, parameterErrorTesting) {
  EXPECT_THROW(Cuboid a(-5, 4, 2), invalid_parameter_error);
  EXPECT_THROW(Cuboid b(5, -4, 2), invalid_parameter_error);
  EXPECT_THROW(Cuboid c(5, 4, -2), invalid_parameter_error);
  EXPECT_THROW(Cuboid d(-5, -4, -2), invalid_parameter_error);
}

