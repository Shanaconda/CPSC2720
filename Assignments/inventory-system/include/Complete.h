#ifndef COMPLETE_H
#define COMPLETE_H
#include "State.h"
#include "Paper.h"
#include <string>


class Complete: public State {
 public:
    Complete() {}
     /**
     * add orders
     * implements state interface
     * @return true or false
     */
    bool addProduct();
     /**
     * edit order
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
     * submit to waitlist
     * implements state interface
     * @return true or false
     */
    bool addToWaitlist();
     /**
     * display status
     * implements state interface
     */
    void display() {
        std::cout<< "Complete";
    }
     /**
     * getter method
     * implements state interface
     * @return status
     */
    std::string getStatus() {return "Complete";}

 private:
    Order* ord;
};
#endif

