#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <Paper.h>
#include <string>
#include <iostream>
#include <vector>


class Warehouse {
 public:
      /**
      * Default constructor
      */
       Warehouse() {}
       /**
       * Constructor
       * @param  location of Warehouse
       */
       Warehouse(std::string l);
       /**
       * Deconstructor
       */
       virtual ~Warehouse();
       /**
       * Getter method
       * @return string location
       */
       std::string getLocation();
       /**
       * Setter method adds products to the warehouse
       * @param Paper object
       */
       void addProduct(Paper *p);
       /**
       * Setter method to adjust the quantity of the product
       * @param  productName 
       * @param  quantity to change
       */
       void changeQuantity(std::string ProductName, int v);
       /**
       * Method to swap inventory from a warehouses if delete function
       * is called
       * @param the warehouse to delete
       * @param the warehouse to store products
       */
       void swapWarehouse(Warehouse *w1, Warehouse *w2);
       /**
       * Method to obtain a product from the stock 
       * @param ProductName
       * @return Paper object wanted
       */
       Paper* getProduct(std::string ProductName);
       /**
       * Method to display the current stock of the Warehouse
       */
       void displayStock();
       /**
       * @return the size of the inventory
       */
       unsigned int inventorySize();
       /**
       * Searches inventory to see if product exists
       * @param  the ProductName
       * @return true if found otherwise false
       */
       bool findProduct(std::string n);

 private:
    std::string location;
    std::vector<Paper*> stock;
};
#endif // WAREHOUSE_H
