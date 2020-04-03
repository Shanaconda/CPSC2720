/**
* @author Shannon Abeda
* @date 2020-02-24
*/

#include "Quadrilateral.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestQuadrilateral, getArea) {
  double a;
  Quadrilateral b(4.2 , 2.2);
  a = 4.2 * 2.2;
  EXPECT_DOUBLE_EQ(a, b.area());
}

TEST(TestQuadrilateral, getHeight) {
  Quadrilateral a(3.3 , 2.2);
  EXPECT_DOUBLE_EQ(2.2, a.getHeight());
}

TEST(TestQuadrilateral, getWidth) {
  Quadrilateral a(3.3, 2.2);
  EXPECT_DOUBLE_EQ(3.3, a.getWidth());
}

TEST(TestQuadrilateral, parameterErrorTesting) {
  EXPECT_THROW(Quadrilateral a(-1.2 , 1.2), invalid_parameter_error);
  EXPECT_THROW(Quadrilateral b(1.2 , -1.2), invalid_parameter_error);
  EXPECT_THROW(Quadrilateral c(-1.2 , -1.2), invalid_parameter_error);
}
