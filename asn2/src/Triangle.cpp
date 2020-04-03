/**
* @author Shannon Abeda
* @date 2020-02-24
*/

#include "Triangle.h"
#include <cmath>
#include "Exceptions.h"

Triangle::Triangle(double s1, double s2, double s3) {
  if((s1+s2) <= s3 || (s2+s3) <= s1 || (s1+s3) <= s2)
    throw invalid_parameter_error
    ("Triangle inequality theorem violiated");
  else if (s1 <=0 || s2 <=0 || s3 <=0)
    throw invalid_parameter_error
    ("Dimension error! Must be greater than zero");
  else
  side1 = s1;
  side2 = s2;
  side3 = s3;
}

double Triangle::area() const {
  double a, s;
  s = (side1+side2+side3)/2;
  a = sqrt(s*(s-side1)*(s-side2)*(s-side3));
}

double Triangle::perimeter() const {
  return side1 + side2 + side3;
}

double Triangle::getSide1() const {
  return side1;
}

double Triangle::getSide2() const {
  return side2;
}

double Triangle::getSide3() const {
  return side3;
}
