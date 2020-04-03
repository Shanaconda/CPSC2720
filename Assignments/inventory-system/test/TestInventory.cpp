#include <Inventory.h>
#include <Warehouse.h>
#include <Order.h>
#include <State.h>
#include <Incart.h>
#include <Paper.h>
#include <gtest/gtest.h>


TEST(TestInventory, addWarehouse) {
    Inventory *i = new Inventory();
    Warehouse *w = new Warehouse("Calgary");
    Warehouse *w1 = new Warehouse("Edmonton");
    Warehouse *w2 = new Warehouse("Toronto");
    i->addWarehouse(w);
    i->addWarehouse(w1);
    i->addWarehouse(w2);
    EXPECT_EQ(3, i->warehouseSize());
    delete i;
    delete w;
    delete w1;
    delete w2;
}

TEST(TestInventory, addToInventoryTest) {
    Inventory *i = new Inventory();
    Warehouse *w = new Warehouse("Calgary");
    Warehouse *w1 = new Warehouse("Edmonton");
    Warehouse *w2 = new Warehouse("Torontn");
    Paper *p = new Paper("Kleenex", 50, 10);
    i->addWarehouse(w);
    i->addWarehouse(w1);
    i->addWarehouse(w2);
    i->addToInventory("Calgary", p);
    EXPECT_EQ(1, w->inventorySize());
    delete i;
    delete w;
    delete w1;
    delete w2;
    delete p;
}

TEST(TestInventory, getWarehousePosition) {
    int pos, pos1, pos2;
    Inventory *i = new Inventory();
    Warehouse *w = new Warehouse("Calgary");
    Warehouse *w1 = new Warehouse("Edmonton");
    Warehouse *w2 = new Warehouse("Toronto");
    pos = i->warehouseLocation(w);
    pos1 = i->warehouseLocation(w1);
    pos2 = i->warehouseLocation(w2);
    EXPECT_EQ(1, pos);
    EXPECT_EQ(2, pos1);
    EXPECT_EQ(3, pos2);
    delete i;
    delete w;
    delete w1;
    delete w2;
}

TEST(TestInventory, testDisplay) {
    Inventory *i = new Inventory();
    Warehouse *w = new Warehouse("Calgary");
    Warehouse *w1 = new Warehouse("Edmonton");
    Warehouse *w2 = new Warehouse("Torontn");
    Paper * p = new Paper("Kleenex", 50, 10);
    i->addWarehouse(w);
    i->addWarehouse(w1);
    i->addWarehouse(w2);
    i->addToInventory("Calgary", p);
    i->displayInventory();
    delete i;
    delete w;
    delete w1;
    delete w2;
    delete p;
}

TEST(TestInventory, testSearchResult) {
    Inventory *i = new Inventory();
    Warehouse *w = new Warehouse("Calgary");
    Warehouse *w1 = new Warehouse("Edmonton");
    Warehouse *w2 = new Warehouse("Torontn");
    i->addWarehouse(w);
    i->addWarehouse(w1);
    i->addWarehouse(w2);
    Paper *p = new Paper("Kleenex", 50, 10);
    i->addToInventory("Calgary", p);
    EXPECT_EQ(1, i->searchInventory("Kleenex").size());
    delete i;
    delete w;
    delete w1;
    delete w2;
    delete p;
}


TEST(TestInventory, deleteWarehouse) {
    Inventory *i = new Inventory();
    Warehouse *Calgary = new Warehouse("Calgary");
    Warehouse *Edmonton = new Warehouse("Edmonton");
    Warehouse *Toronto = new Warehouse("Toronto");
    Paper *Kleenex = new Paper("Kleenex", 50, 10);
    Paper *Scott = new Paper("Scott", 20, 10);
    Paper *Generic = new Paper("GenericBrand", 10, 10);
    i->addWarehouse(Calgary);
    i->addWarehouse(Edmonton);
    i->addWarehouse(Toronto);
    i->addToInventory("Calgary", Kleenex);
    i->addToInventory("Edmonton", Scott);
    i->addToInventory("Toronto", Generic);
    i->deleteWarehouse(Calgary, Toronto);
    EXPECT_EQ(2, Toronto->inventorySize());
    delete i;
    delete Calgary;
    delete Edmonton;
    delete Toronto;
    delete Kleenex;
    delete Scott;
    delete Generic;
}

TEST(TestInventory, addOrder) {
    Inventory *i = new Inventory();
    State* init;
    init = new Incart();
    Order *o = new Order(init, 100);
    i->addOrder(o);
    EXPECT_EQ(1, i->orderListSize());
    delete i;
    delete init;
    delete o;
}


