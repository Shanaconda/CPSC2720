#include "Order.h"
#include "Paper.h"
#include "ShippingMethod.h"
#include "State.h"
#include "Pending.h"
#include "Complete.h"
#include "Incart.h"
#include "gtest/gtest.h"

TEST(TestOrder, testConstructor) {
    State* init;
    init = new Pending();
    Order* o = new Order(init, 100);
    EXPECT_TRUE(o != NULL);
    delete init;
    delete o;

    State *init1;
    init1 = new Complete();
    Order* o1 = new Order(init1, 100);
    EXPECT_TRUE(o1 != NULL);
    delete init1;
    delete o1;

    State* init2;
    init2 = new Incart();
    Order* o2 = new Order(init2, 100);
    EXPECT_TRUE(o2 != NULL);
    delete init2;
    delete o2;
}

TEST(TestOrder, testPendingState) {
    State* init;
    init = new Incart();
    Paper* p = new Paper("Kleenex", 10, 10);
    Order *o = new Order(init, 100);
    o->addProduct(p);
    o->submit();
    EXPECT_EQ("Pending", o->getStatus());
    delete init;
    delete o;
    delete p;
}

TEST(TestOrder, testInCartState) {
    State* init;
    init = new Incart();
    Paper* p = new Paper("Kleenex", 10, 10);
    Order *o = new Order(init, 100);
    o->addProduct(p);
    EXPECT_EQ("In Cart", o->getStatus());
    delete init;
    delete p;
    delete o;
}

TEST(TestOrder, testCompleteState) {
    State* init;
    init = new Incart();
    Paper* p = new Paper("Kleenex", 10, 10);
    Order *o = new Order(init, 100);
    o->addProduct(p);
    o->submit();
    o->submit();
    EXPECT_EQ("Complete", o->getStatus());
    delete init;
    delete p;
    delete o;
}

TEST(TestOrder, TestAddOrder) {
    State* init;
    init = new Pending();
    Paper* p = new Paper("Kleenex", 10, 10);
    Order *o = new Order(init, 100);
    o->addProduct(p);
    EXPECT_EQ(1, o->OrderSize());
    delete init;
    delete p;
    delete o;
}

TEST(TestOrder, TestCancelOrder) {
    State* init;
    init = new Pending();
    Paper* p = new Paper("Kleenex", 10, 10);
    Order *o = new Order(init, 100);
    o->addProduct(p);
    o->cancel(p);
    EXPECT_EQ(0, o->OrderSize());
    delete init;
    delete p;
    delete o;
}

TEST(TestOrder, TestEditOrder) {
    State* init;
    int v = 20;
    init = new Pending();
    Paper* p = new Paper("Kleenex", 10, 10);
    Order *o = new Order(init, 100);
    o->addProduct(p);
    o->edit(p, v);
    EXPECT_EQ(20, p->getQuantity());
    delete init;
    delete p;
    delete o;
}

TEST(TestOrder, addToWaitlistOrder) {
    State* init;
    init = new Pending();
    Paper* p = new Paper("Kleenex", 10, 10);
    Order *o = new Order(init, 100);
    o->addProduct(p);
    o->addToWaitlist();
    o->orderStatus();
    EXPECT_EQ("Pending", o->getStatus());
    delete init;
    delete p;
    delete o;
}

TEST(TestOrder, completeStatus) {
    State* init;
    int v = 20;
    init = new Complete();
    Paper* p = new Paper("Kleenex", 10, 10);
    Order *o = new Order(init, 100);
    o->addToWaitlist();
    o->addProduct(p);
    o->edit(p, v);
    o->submit();
    o->cancel(p);
    EXPECT_EQ("Complete", o->getStatus());
    delete o;
    delete p;
    delete init;
}

