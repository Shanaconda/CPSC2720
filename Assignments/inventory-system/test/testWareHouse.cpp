#include <Warehouse.h>
#include "gtest/gtest.h"

TEST(TestWarehouse, constructorTest) {
    Warehouse* w;
    w = new Warehouse("CALGARY");
    EXPECT_TRUE(w != NULL);
    EXPECT_FALSE(w == NULL);
    delete w;
}

TEST(TestWarehouse, testGetterMethods) {
    Warehouse * w;
    w = new Warehouse("Calgary");
    EXPECT_EQ("Calgary", w->getLocation());
    delete w;
}

TEST(TestWarehouse, testaddProduct) {
    Warehouse * w;
    Paper *p;
    Paper* d;
    p = new Paper("Kleenex", 10, 2);
    d = new Paper("Scott", 20, 5);
    w = new Warehouse("Calgary");
    w->addProduct(p);
    w->addProduct(d);
    EXPECT_EQ(2, w->inventorySize());
    delete p;
    delete d;
    delete w;
}

TEST(TestWarehouse, testChangeQuantity) {
    Warehouse * w;
    Paper* p;
    Paper* d;
    Paper *e;
    p = new Paper("Kleenex", 10, 2);
    d = new Paper("Scott", 20, 5);
    w = new Warehouse("Calgary");
    w->addProduct(p);
    w->addProduct(d);
    w->changeQuantity("Kleenex", 20);
    e = w->getProduct("Kleenex");
    EXPECT_EQ(20, e->getQuantity());
    delete p;
    delete d;
    delete w;
}

TEST(TestWarehouse, testGetProduct) {
    Warehouse* w;
    Paper* p;
    Paper* d;
    p = new Paper("Kleenex", 10, 2);
    w = new Warehouse("Calgary");
    w->addProduct(p);
    d = w->getProduct("Kleenex");
    EXPECT_EQ("Kleenex", d->getProductName());
    delete p;
    delete w;
}

TEST(TestWareHouse, testInventorySize) {
     Warehouse * w;
     w = new Warehouse("Calgary");
     Paper *p = new Paper("Kleenex", 10, 2);
     w->addProduct(p);
     EXPECT_EQ(1, w->inventorySize());
     delete p;
     delete w;
}

TEST(testWarehouse, testFindProduct) {
    Warehouse* w;
    bool found = true;
    bool f2 = true;
    w = new Warehouse("Calgary");
    Paper *p;
    Paper *d;
    Paper *e;
    p = new Paper("Kleenex", 10, 2);
    d = new Paper("Generic", 500, 2);
    e = new Paper("CostcoBrand", 20, 4);
    w->addProduct(p);
    w->addProduct(d);
    w->addProduct(e);
    EXPECT_TRUE(found == w->findProduct("Kleenex"));
    EXPECT_FALSE(f2 == w->findProduct("ScottBrand"));
    delete p;
    delete d;
    delete e;
    delete w;
}

TEST(testWarehouse, testDisplay) {
    Warehouse* w;
    w = new Warehouse("Calgary");
    Paper *p;
    Paper *d;
    Paper *e;
    p = new Paper("Kleenex", 10, 2);
    d = new Paper("Generic", 500, 2);
    e = new Paper("CostcoBrand", 20, 4);
    w->addProduct(p);
    w->addProduct(d);
    w->addProduct(e);
    w->displayStock();
    delete p;
    delete d;
    delete e;
    delete w;
}


