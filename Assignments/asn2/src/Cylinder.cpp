/**
* @author Shannon Abeda
* @date 2020-02-24
*/

#include "Cylinder.h"
#include "Circle.h"
#include <Shape3D.h>
#include "Exceptions.h"

Cylinder::Cylinder(double r, double h) {
  if(r <=0 || h <=0)
    throw invalid_parameter_error
    ("Dimension errors, must be greater than 0");
  else
    height = h;
    c = new Circle(r);
}

Cylinder::~Cylinder() {
  delete c;
}

double Cylinder::area() const {
  double a;
  a = c->perimeter()*height + 2*c->area();
  return a;
}

double Cylinder::volume() const {
  double v;
  v = c->area()*height;
  return v;
}

double Cylinder::getHeight() const {
  return height;
}

double Cylinder::getRadius() const {
  return c->getRadius();
}
