#ifndef INVENTORY_H
#define INVENTORY_H
#include <Paper.h>
#include <Warehouse.h>
#include <Order.h>
#include <iostream>
#include <string>
#include <vector>


class Inventory {
 public:
       /**
       * Default constructor
       *
       */
        Inventory() {}
        /**
        * Destructor
        *
        */
        virtual ~Inventory();
        /**
        * setter method to add Warehouse to the systerm
        * @param Warehouse object
        */
        void addWarehouse(Warehouse *w);
        /**
        * setter method to add a product at a specific location
        * @param the location of warehouse
        * @param Paper object
        */
        void addToInventory(std::string l, Paper *p);
        /**
        * getter method to find the location store in the vector
        * @param Warehouse object
        * @return location of Warehouse
        */
        int warehouseLocation(Warehouse *w);
        /**
        * setter method to add an Order to the system;
        * @param Order object
        *
        */
        void addOrder(Order *o);
        /**
        * setter function to delete a warehouseLocation
        * @param Warehouse object to be delete
        * @param Warehouse object to store products
        */
        void deleteWarehouse(Warehouse* w1, Warehouse* w2);
        /**
        * display current Inventory across the Warehouses
        */
        void displayInventory();
        /**
        * search function find specific product across the Warehouses
        * @param string n of the productName
        * @return products found
        */
        std::vector<Paper*> searchInventory(std::string n);
        /**
        * Access to the amount of Warehouses active in the systerm
        * @return size of the warehouseList
        */
        unsigned int warehouseSize();
        /**
        * Access to the amount of Orders active in the systerm
        * @return the size of the orderList
        */
        unsigned int orderListSize();
        /**
        * Finding a warehouse
        * @param  location
        * @return Warehouse object
        */
        Warehouse *getWarehouse(std::string location);

 private:
    std::vector<Warehouse*> Warehouses;
    std::vector<Order*> orderList;
};
#endif // INVENTORY_H
