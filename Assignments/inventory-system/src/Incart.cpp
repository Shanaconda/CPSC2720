#include "State.h"
#include "Order.h"
#include "Incart.h"
#include "Pending.h"
#include <iostream>

bool Incart::addProduct() {
    return true;
}

bool Incart::edit() {
    return true;
}

bool Incart::submit() {
    this->OrderState->setState(new Pending());
    return true;
}

bool Incart::cancel() {
    return true;
}

bool Incart::addToWaitlist() {
    this->OrderState->setState(new Pending);
    return true;
}


