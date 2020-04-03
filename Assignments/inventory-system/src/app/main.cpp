#include "Inventory.h"
#include "Warehouse.h"
#include "Order.h"
#include "Paper.h"
#include "Pending.h"
#include "Complete.h"
#include "Incart.h"
#include "State.h"
#include "ShippingMethod.h"
#include <iostream>

int main() {
    Inventory *i = new Inventory();
    int input;
    std::string location, productName, location1;
    int weight, quantity;
    start1:
    std::cout << "Inventory System" << std::endl;
    std::cout << "You must add at least one Warehouse before";
    std::cout << "adding product into the system" << std::endl;
    std::cout << "Please select from the following options" << std::endl;
    std::cout << "1: to add Warehouse to system" << std::endl;
    std::cout << "2: Add product to system" << std::endl;
    std::cout << "3: Display Inventory" << std::endl;
    std::cout << "4: Make an Order" << std::endl;
    std::cout << "5: Search for a product" << std::endl;
    std::cout << "6: Exit system " << std::endl;
    std::cin >> input;
    if (input == 1) {
        std::cout<< "Please enter the location of the Warehouse: " << std::endl;
        std::cin >> location;
        Warehouse * w = new Warehouse(location);
        i->addWarehouse(w);
        std::cout<< "Warehouse created! " << std::endl;
        delete w;
        goto start1;
    } else if (input == 2) {
        std::cout << "Please enter the product name: ";
        std::cin >> productName;
        std::cout << "Please enter the quantity: ";
        std::cin >> quantity;
        std::cout << "Please enter the weight: ";
        std::cin >> weight;
        std::cout<< "Please enter the location of the Warehouse: " ;
        std::cin >> location1;
        Paper *p = new Paper(productName, quantity, weight);
        i->addToInventory(location1, p);
        delete p;
        goto start1;
    } else if (input == 3) {
        i->displayInventory();
        goto start1;
    } else if (input == 4) {
        std::cout << "Please enter the weight of the order";
        int orderWeight;
        std::cin >> orderWeight;
        std::cout << "Please enter the productName for the order";
        std::string PN;
        std::cin >> PN;
        State* s = new Incart();
        Order* o = new Order(s, orderWeight);
        Paper* p = new Paper(PN, 1, orderWeight);
        o->addProduct(p);
        delete p;
        i->addOrder(o);
        delete o;
        std::cout << "Would you like to submit your order Y/N:  ";
        std::string prompt;
        std::cin >> prompt;
        if (prompt == "Y" || prompt == "y") {
            o->submit();
            goto start1;
        } else {
            goto start1;
        }
        } else if (input == 5) {
            std::string productWanted;
            std::cout << "What product are you looking for: ";
            std::cin >> productWanted;
            if (i->searchInventory(productWanted).size() > 0) {
                std::cout << "Product was located ";
                goto start1;
            } else {
                std::cout << "Product does not exist in warehouse ";
                goto start1; 
                }
        } else if (input == 6) {
            std::cout << "GOODBYE";
        } else {
            std::cout << "Invalid input! Please select a valid input from the menu above";
            goto start1;
        }
    delete i;
    return 0;
}
