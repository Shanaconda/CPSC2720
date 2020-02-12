#include "SetOfCards.h"
#include "Card.h"
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>

SetOfCards::SetOfCards() {
  //ctor
}

SetOfCards::~SetOfCards() {
  //dtor
}

void SetOfCards::newDeck() {
  std::vector<std::string> suits(4);
  suits[0]="C";
  suits[1]="D";
  suits[2]="S";
  suits[3]="H";

  std::vector<std::string> ranks(13);
  ranks[0]="A";
  ranks[1]="2";
  ranks[2]="3";
  ranks[3]="4";
  ranks[4]="5";
  ranks[5]="6";
  ranks[6]="7";
  ranks[7]="8";
  ranks[8]="9";
  ranks[9]="10";
  ranks[10]="Q";
  ranks[11]="J";
  ranks[12]="K";


  //Creating card & feeding each combination into a vector
  for (auto s : suits) {
    for (auto r : ranks) {
      Deck.push_back(Card(r , s));
    }
    srand(time(NULL));
    random_shuffle(Deck.begin(), Deck.end());
  }
}

//Only for testing purposes
int SetOfCards::getSizeDeck() {
  return Deck.size();
}


Card SetOfCards::draw() {
  //Creating a card object
  Card C;

  if (Deck.size() > 0) {
    C = Deck.back();
    Deck.pop_back();
  }
  return C;
}

void SetOfCards::showDeck() {
  for (unsigned int i = 0; i < 52; i++) {
    std::cout<< Deck[i];
  }
}
