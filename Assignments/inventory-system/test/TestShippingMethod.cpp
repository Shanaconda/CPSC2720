#include "ShippingMethod.h"
#include "gtest/gtest.h"

TEST(TestShippingMethod, testConstructor) {
    ShippingMethod* shipMethod;
    shipMethod = new ShippingMethod();
    EXPECT_TRUE(shipMethod != NULL);
    delete shipMethod;
}

TEST(TestShippingMethod, testTypes) {
    ShippingMethod* airMethod = new ShippingMethod();
    airMethod->setShippingMethod(101);
    EXPECT_EQ("AIR", airMethod->getShippingMethod());
    delete airMethod;
    ShippingMethod* truckMethod = new ShippingMethod();
    truckMethod->setShippingMethod(99);
    EXPECT_EQ("TRUCK", truckMethod->getShippingMethod());
    delete truckMethod;
    ShippingMethod* trainMethod = new ShippingMethod();
    trainMethod->setShippingMethod(1001);
    EXPECT_EQ("TRAIN", trainMethod->getShippingMethod());
    delete trainMethod;
    ShippingMethod* shipMethod = new ShippingMethod();
    shipMethod->setShippingMethod(10001);
    EXPECT_EQ("SHIP", shipMethod->getShippingMethod());
    delete shipMethod;
}
