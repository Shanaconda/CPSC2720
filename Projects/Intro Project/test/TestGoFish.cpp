#include "gtest/gtest.h"
#include "Card.h"
#include "SetOfCards.h"
#include "Player.h"
#include "PlayerAi.h"

//Testing Card class
TEST(TestGoFish, constructorTest) {
  Card c("1", "C");
  EXPECT_EQ("1", c.getVal());
  EXPECT_EQ("C", c.getSuit());
}
//Testing the Deck class
TEST(TestGoFish, deckTest) {
  SetOfCards d;
  d.newDeck();
  EXPECT_EQ(52, d.getSizeDeck());
}
//Testing Player constructor
TEST(TestGoFish, PlayerTest) {
  Player p1("Shannon");
  EXPECT_EQ("Shannon", p1.getName());
}
//Testing Ai Constructor
TEST(TestGoFish, AITest) {
  PlayerAi p3("COMPUTER1");
  EXPECT_EQ("COMPUTER1", p3.getName());
}

//Adding value into hand
TEST(TestGoFish, AddCardTest) {
  Card c("1", "C");
  Player p2;
  p2.addCard(c);

  EXPECT_EQ(1, p2.handSize());

}

//Drawing from the deck
TEST(TestGoFish, DrawFromDeckTest) {
  SetOfCards d1;
  Player p1;
  d1.newDeck();
  p1.addCard(d1.draw());

  EXPECT_EQ(1, p1.handSize());

}
//Comparing two cards of the same Rank
TEST(TestGoFish, RankComparisonTest) {
  Player p1;
  Card c1("1", "C");
  Card c2("1", "D");
  Card c3("2", "C");
  Card c4("3", "D");
  EXPECT_TRUE(p1.checkRank(c2, c1));
  EXPECT_FALSE(p1.checkRank(c3, c4));
}

//Test if Player has a rankCard
TEST(TestGoFish, hasCardTest) {
  Player p1;
  Card c1("1", "C");

  p1.addCard(c1);

  EXPECT_TRUE(p1.hasCard("1"));
  EXPECT_FALSE(p1.hasCard("2"));

}
//Test if the player has a scoreCount
TEST(TestGoFish, scoreTest) {
  Player p1;
  Card c1("1", "C");
  Card c2("1", "D");
  Card c3("1", "C");
  Card c4("1", "D");

  p1.addCard(c1);
  p1.addCard(c2);
  p1.addCard(c3);
  p1.addCard(c4);

  EXPECT_EQ(1, p1.scoreCount());

}

TEST(TestGoFish, eraseCardTest){
  Player p1;
  Card c1("1", "C");
  Card c2("1", "D");
  Card c3("1", "C");
  Card c4("1", "D");

  p1.addCard(c1);
  p1.addCard(c2);
  p1.addCard(c3);
  p1.addCard(c4);

  Card c5=p1.removeCard("1");


  EXPECT_EQ(3, p1.handSize());
  EXPECT_EQ("1", c5.getVal());

}


