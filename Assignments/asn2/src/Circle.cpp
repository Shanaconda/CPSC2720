/**
* @author Shannon Abeda
* @date 2020-02-24
*/

#include "Circle.h"
#include "Exceptions.h"
#include <cmath>
#include <Shape2D.h>

Circle::Circle(double r) {
    if (r < 0)
    throw invalid_parameter_error("Invalid input");

    else
    radius = r;
}

double Circle::area() const {
  double a;

  a = M_PI*(pow(radius, 2));

  return a;
}

double Circle::perimeter() const {
  double p;
  p = 2*M_PI*(radius);

  return p;
}

double Circle::getRadius() const {
  return radius;
}
