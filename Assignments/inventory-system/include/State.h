#ifndef STATE_H
#define STATE_H
#include "Order.h"
#include "Paper.h"
#include <iostream>
#include <vector>
#include <string>

class Order;

class State {
 public:
 /**
 * @abstract
 * Abstract class depended on the state
 * of the Order
 * @abstract
 */
    ~State() { OrderState = NULL;}
    void setOrder(Order *Or) { OrderState = Or; }
    virtual bool addProduct() = 0;
    virtual bool edit() = 0;
    virtual bool submit() = 0;
    virtual bool cancel() = 0;
    virtual bool addToWaitlist() = 0;
    virtual void display() = 0;
    virtual std::string getStatus() = 0;

 protected:
    Order* OrderState;
};
#endif
