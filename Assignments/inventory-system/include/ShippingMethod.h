#ifndef SHIPPINGMETHOD_H
#define SHIPPINGMETHOD_H

#include <string>

class ShippingMethod {
 public:
    /**
    * Default constructor
    */
    ShippingMethod() {}
    /**
    * sets the shippingMethod depending on weight of the order
    * @param int weight of the order
    */
    void setShippingMethod(int weight) {
       if (weight <= 100) {
           type = "TRUCK";
       } else if (weight > 100 && weight < 1000) {
           type = "AIR";
       } else if (weight > 1000 && weight < 10000) {
           type = "TRAIN";
       } else {
           type = "SHIP";
       }
}
/**
* Access to the type of shippingMethod
* @return string type of shippingMethod
*/
std::string getShippingMethod() {
    return type;
}

 private:
    std::string type;
};
#endif
