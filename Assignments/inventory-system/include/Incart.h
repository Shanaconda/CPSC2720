#ifndef INCART_H
#define INCART_H
#include "State.h"
#include "Paper.h"
#include <string>

class Incart : public State {
 public:
    Incart() {}
    virtual ~Incart() {
        OrderState == NULL;
    }
    /**
     * submit order
     * implements state interface
     * @return true or false
     */
    bool addProduct();
     /**
     * edits order
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
     * cancels order
     * implements state interface
     * @return true or false
     */
    bool cancel();
     /**
     * add order to waitlist
     * implements state interface
     * @return true or false
     */
    bool addToWaitlist();
     /**
     * display orderStatus
     * implements state interface
     */
    void display() {
        std::cout<< "In Cart";
    }
     /**
     * getter method 
     * implements state interface
     * @return status
     */
    std::string getStatus() {
        return "In Cart";
    }
};
#endif
