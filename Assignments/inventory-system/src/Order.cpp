#include "Order.h"
#include "State.h"
#include "Paper.h"
#include "ShippingMethod.h"
#include "Inventory.h"
#include <string>

Order::Order(State *init, int weight): currentState(NULL) {
  currentState = init;
  setState(init);
  shipMethod = new ShippingMethod();
  shipMethod->setShippingMethod(weight);
  method = shipMethod->getShippingMethod();
}

Order::~Order() {
    delete shipMethod;
    currentState == NULL;
}

void Order::setState(State* s) {
    if (currentState != NULL) {
        this->currentState == NULL;
        currentState = s;
        currentState->setOrder(this);
    }
}


void Order::addProduct(Paper *p) {
    if (this->currentState->addProduct()) {
       orders.push_back(p);
    } else {
        std::cout << "Cannot add product to a complete order" << std::endl;
    }
}

void Order::edit(Paper *p, int v) {
    int loc = Order::productLocation(p);
    if (this->currentState->cancel()) {
    orders.at(loc)->setQuantity(v);
    std::cout << "Order has been edited" << std::endl;
    } else {
        std::cout << "Cannot order complete order" <<std::endl;
    }
}

void Order::submit() {
    if (this->currentState->submit()) {
        std::cout<< "Order has been submitted" << std::endl;
    } else {
        std::cout << "Order has already been submitted" << std::endl;
    }
}

void Order::cancel(Paper *p) {
  int loc = Order::productLocation(p);
  if (this->currentState->cancel()) {
    orders.erase(orders.begin() + loc);
    std::cout<< "Order has been cancelled" << std::endl;
  } else {
      std::cout << "Order has been completed.. cannot be cancelled" <<std::endl;
  }
}

void Order::addToWaitlist() {
    if (this->currentState->addToWaitlist()) {
        std::cout <<"Order has been added to waitlist";
    } else {
        std::cout << "Order has already been added to waitlist ";
    }
}

int Order::productLocation(Paper *p) {
    int index;
    for (unsigned int i = 0; i < orders.size(); i++) {
        if (orders[i]->getProductName() == p->getProductName()) {
            index = i;
        }
    }
    return index;
}

void Order::orderStatus() {
      this->currentState->display();
}

std::string Order::getStatus() {
    return this->currentState->getStatus();
}

int Order::OrderSize() {
    return orders.size();
}
