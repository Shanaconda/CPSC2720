#include "Pending.h"
#include "Complete.h"
#include "Paper.h"
#include "State.h"

bool Pending::addProduct() {
    return true;
}
bool Pending::edit() {
    return true;
}
bool Pending::submit() {
    this->OrderState->setState(new Complete());
    return true;
}
bool Pending::cancel() {
    return true;
}
bool Pending::addToWaitlist() {
    return false;
}


