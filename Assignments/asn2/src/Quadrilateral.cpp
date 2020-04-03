/**
* @author Shannon Abeda
* @date 2020-02-24
*/

#include "Quadrilateral.h"
#include <Shape2D.h>
#include <cmath>
#include "Exceptions.h"

Quadrilateral::Quadrilateral(double w, double h) {
  if(w <= 0 || h <= 0)
  {
    throw invalid_parameter_error("ERROR! DIMESIONS MUST BE >0");
  }
  width = w;
  height = h;

}

double Quadrilateral::area() const {
    return width * height;
}

double Quadrilateral::perimeter() const {
  return width * 2 + height * 2;
}

double Quadrilateral::getHeight() const {
  return height;
}

double Quadrilateral::getWidth() const {
  return width;
}
