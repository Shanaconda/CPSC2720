#include <Inventory.h>
#include <Paper.h>
#include <Warehouse.h>
#include <Order.h>
#include <string>
#include <vector>

Inventory::~Inventory() {
    for (unsigned int i = 0; i < Warehouses.size(); i++) {
        Warehouses[i] == NULL;
    }

    for (unsigned int i = 0; i < orderList.size(); i++) {
        orderList[i] == NULL;
    }
}

void Inventory::addWarehouse(Warehouse *w) {
    Warehouses.push_back(w);
}

void Inventory::addToInventory(std::string l, Paper* p) {
    int size = Inventory::warehouseSize();
    for (unsigned int i = 0; i < size; i++) {
        if (Warehouses[i]->getLocation() == l) {
            Warehouses[i]->addProduct(p);
        }
    }
}

int Inventory::warehouseLocation(Warehouse* w) {
    int size = Inventory::warehouseSize();
    for (unsigned int i = 0; i < size; i++) {
        if (Warehouses[i]->getLocation() == w->getLocation()) {
            return i;
        }
    }
}

void Inventory::deleteWarehouse(Warehouse *w1, Warehouse *w2) {
    int currentPos = Inventory::warehouseLocation(w1);
    Warehouse w;
    w.swapWarehouse(w1, w2);
    Warehouses.at(currentPos) == NULL;
}

void Inventory::displayInventory() {
    for (Warehouse* w : Warehouses) {
        w->displayStock();
    }
}

std::vector<Paper*> Inventory::searchInventory(std::string n) {
     std::vector<Paper*> searchResults;
     for (Warehouse * w : Warehouses) {
         if (w->getProduct(n) != NULL) {
         searchResults.push_back(w->getProduct(n));
         }
     }
     return searchResults;
}

unsigned int Inventory::warehouseSize() {
    return Warehouses.size();
}
Warehouse * Inventory::getWarehouse(std::string location) {
    for (Warehouse * w : Warehouses) {
        if (w->getLocation() == location) {
            return w;
        }
    }
    return nullptr;
}

void Inventory::addOrder(Order *o) {
    orderList.push_back(o);
}

unsigned int Inventory::orderListSize() {
    return orderList.size();
}

