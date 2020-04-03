#include <Paper.h>
#include "gtest/gtest.h"

TEST(TestPaper, constructorTest) {
    Paper *p = new Paper("Downey", 100, 1);
    EXPECT_TRUE(p != NULL);
    Paper *e = new Paper("Scott", 50, 2);
    EXPECT_TRUE(e != NULL);
    Paper *d = new Paper("GenericBrand", 20, 4);
    EXPECT_TRUE(d != NULL);
    delete p;
    delete e;
    delete d;
}

TEST(TestPaper, testGetterMethods) {
    Paper *p = new Paper("Downey", 100, 1);
    EXPECT_EQ("Downey", p->getProductName());
    EXPECT_EQ(100, p->getQuantity());
    EXPECT_EQ(1, p->getWeight());
    Paper *e = new Paper("Scott", 50, 2);
    EXPECT_EQ("Scott", e->getProductName());
    EXPECT_EQ(50, e->getQuantity());
    EXPECT_EQ(2, e->getWeight());
    Paper *d = new Paper("GenericBrand", 20, 4);
    EXPECT_EQ("GenericBrand", d->getProductName());
    EXPECT_EQ(20, d->getQuantity());
    EXPECT_EQ(4, d->getWeight());
    delete p;
    delete e;
    delete d;
}

TEST(TestPaper, testSetterMethods) {
    Paper *p = new Paper("Downey", 100, 1);
    p->setQuantity(50);
    EXPECT_EQ(50, p->getQuantity());
    delete p;
}

TEST(TestPaper, display) {
  Paper *p = new Paper("Downey", 100, 1);
  std::cout<< *p << std::endl;
  delete p;
}
