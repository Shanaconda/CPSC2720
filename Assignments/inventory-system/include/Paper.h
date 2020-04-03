#ifndef PAPER_H
#define PAPER_H
#include <iostream>
#include <string>

class Paper {
 public:
       /**
       * Overloaded ostream operator
       * @return the paper quantity, weight and name
       */
        friend std::ostream& operator<<(std::ostream& os, const Paper&p);
        /**
        * Default constructor
        */
        Paper() {}
        /**
        * Constructor 
        * @param string n name of product 
        * @param int q quantity of the product
        * @param int w weight of the product
        */
        Paper(std::string n, int q, int w);
        /**
        * Destructor
        */
        virtual ~Paper() {}
        /**
        * Access to the productName
        * @return productName
        */
        std::string getProductName() const;
        /** 
        * Access to the quantity of the product
        * @return quantity of product
        */
        int getQuantity() const;
        /** 
        * Access to the weight of the product
        * @return weight of product
        */
        int getWeight() const;
        /**
        * Setter method to change the quantity of the product
        *
        */
        void setQuantity(int q);

 private:
    std::string productName;
    int quantity;
    int weight;
};
#endif // PAPER_H
