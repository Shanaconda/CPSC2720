#ifndef PENDING_H
#define PENDING_H
#include "State.h"
#include "Paper.h"
#include <string>

class Pending : public State {
 public:
    Pending() {}
    /**
     * add product
     * implements state interface
     * @return true or false
     */
    bool addProduct();
    /**
     * edit product
     * implements state interface
     * @return true or false
     */
    bool edit();
    /**
     * submit order
     * implements state interface
     * @return true or false
     */
    bool submit();
    /**
     * cancel order
     * implements state interface
     * @return true or false
     */
    bool cancel();
    /**
     * adds to waitlist
     * implements state interface
     * @return true or false
     */
    bool addToWaitlist();
    /**
     * display current status
     */
    void display() {
         std::cout<< "Pending";
    }
    /**
     * getter function for status
     * implements state interface
     * @return status
     */
    std::string getStatus() {return "Pending";}

 private:
    State* state;
};
#endif





