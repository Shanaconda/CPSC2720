#include <Paper.h>
#include <string>
#include <iostream>

Paper::Paper(std::string n, int q, int w) {
    productName = n;
    quantity = q;
    weight = w;
}

std::string Paper::getProductName() const {
    return productName;
}

int Paper::getQuantity() const {
    return quantity;
}

void Paper::setQuantity(int q) {
    quantity = q;
}

int Paper::getWeight() const {
    return weight;
}

std::ostream& operator<<(std::ostream& os, const Paper&p) {
    os << p.getProductName() <<"  " << p.getQuantity() <<"  " << p.getWeight();
    return os;
}
