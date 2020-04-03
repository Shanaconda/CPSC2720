#include <Warehouse.h>
#include <Paper.h>
#include <string>

Warehouse::Warehouse(std::string l) : location(l) {}

Warehouse::~Warehouse() {
    for (unsigned int i = 0; i < stock.size(); i++) {
        stock[i] == NULL;
    }
}

std::string Warehouse::getLocation() {
    return location;
}

void Warehouse::addProduct(Paper *p) {
    stock.push_back(p);
}

Paper* Warehouse::getProduct(std::string ProductName) {
    for (Paper* p : stock) {
        if (findProduct(ProductName)) {
            return p;
        }
    }
    return nullptr;
}

void Warehouse::swapWarehouse(Warehouse *w1, Warehouse* w2) {
    int size = w1->stock.size();
    for (unsigned int i = 0; i < size; i++) {
        w2->addProduct(w1->stock[i]);
    }
}

void Warehouse::changeQuantity(std::string ProductName, int v) {
    for (Paper *p : stock) {
        if (findProduct(ProductName)) {
            p->setQuantity(v);
        }
    }
}

void Warehouse::displayStock() {
    for (unsigned int i = 0; i < stock.size(); i++) {
        std::cout<< *stock[i] << std::endl;
    }
}

bool Warehouse::findProduct(std::string ProductName) {
    for (unsigned int i =0; i < stock.size(); i++) {
        if (stock[i]->getProductName() == ProductName) {
            return true;
        }
    }
    return false;
}

unsigned int Warehouse::inventorySize() {
    return stock.size();
}
