#ifndef ORDER_H
#define ORDER_H
#include "State.h"
#include "ShippingMethod.h"
#include "Paper.h"
#include <string>
#include <vector>
class State;

class Order {
 public:
    /**
    * Constructor to create Order object
    * @param  initial state of Order 
    * @param the weight of the order
    */
    Order(State* init, int weight);
    /**
    * Destructor
    */
    virtual ~Order();
    /**
    * Setter method of the next state
    * @param the state of the object
    */
    void setState(State* state);
    /**
    * Adding product to orderList
    * @param paper object
    */
    void addProduct(Paper*p);
    /**
    * Edit a current order
    * @param paper object
    * @param  quantity to be changed
    */
    void edit(Paper*p, int v);
    /**
    * Submit an order in pending or inCart
    */
    void submit();
    /**
    * Cancel an order that is pending or inCart
    * @param Paper
    */
    void cancel(Paper *p);
    /**
    * add a Product to the waitlist if inventory is empty
    *
    */
    void addToWaitlist();
    /** 
    * display current Status of the order
    */
    void orderStatus();
    /**
    * Access to the shippingMethod use
    * @return method used
    */
    std::string getShippingMethod() {
        return method;
    }
    /**
    * Current status of order
    * @return status
    */
    std::string getStatus();
    /**
    * The current ## of orders request
    * @return the ## ordersize
    */
    int OrderSize();
    /**
    * Finding the where a product is located
    * @param paper object
    * @return  location of the product stored
    */
    int productLocation(Paper *p);

 private:
    State* currentState;
    ShippingMethod * shipMethod;
    std::string method;
    std::vector<Paper*> orders;
};
#endif
