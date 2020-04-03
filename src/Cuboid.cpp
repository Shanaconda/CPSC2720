/**
* @author Shannon Abeda
* @date 2020-02-24
*/

#include <Shape3D.h>
#include "Quadrilateral.h"
#include "Cuboid.h"
#include <cmath>
#include "Exceptions.h"

Cuboid::Cuboid(double w, double h, double l) {
  if(w <= 0 || h <=0 || l <= 0)
    throw invalid_parameter_error("Parameter errors, sides must be 0<");
  else
    q = new Quadrilateral(w,l);
    height = h;
}

Cuboid::~Cuboid() {
  delete q;
}

double Cuboid::area() const {
  double a;
  a = q->area()*2 + q->getWidth()*height *2 + q->getHeight()*height*2;
  return a;
}

double Cuboid::volume() const {
  double v;
  v = q->area()*height;
  return v;
}

double Cuboid::getHeight() const {
  return height;
}

double Cuboid::getLength() const {
  return q->getHeight();
}

double Cuboid::getWidth() const {
  return q->getWidth();
}
