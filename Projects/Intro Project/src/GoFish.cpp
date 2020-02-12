#include "GoFish.h"
#include <string>
#include "Player.h"
#include "PlayerAi.h"
#include "SetOfCards.h"
#include "Card.h"

GoFish::GoFish() {
  //ctor
}

GoFish::~GoFish() {
  //dtor
}

void GoFish::help() {
  std::cout<< "The objective of this game is obtain the most four of kinds. \n";
  std::cout<< "Each time you receive a four a kind you will score a point. \n";
  std::cout<< "You will play first and ask the C1 or C2 if they have";
  std::cout<< "the card they're looking forward. \n";
  std::cout<< "If they do, they must give up that card"<< std::endl;
  std::cout<< "You will receive the card and add it to your deck (GOFISH).";
  std::cout<< "If you receive a four kind, it will count towards a point. \n";
  std::cout<< "If you don't have that card,";
  std::cout<< "then you will draw a random deck from the deck";
  std::cout<< "and you will give up your turn."<< std::endl;
  std::cout<< std::endl;
}
void GoFish::play() {
  std::string n;
  std::string command;
  SetOfCards *d;
  SetOfCards deck;
  deck.newDeck();
  d = &deck;

  std::cout<< "Welcome to GoFish game"<< std::endl;
  std::cout<< std::endl;

  std::cout<< "Please enter your name: "<< std::endl;
  std::cin>> n;
  Player *ptr1;
  PlayerAi *ptr2;
  PlayerAi *ptr3;
  Player p1(n);
  ptr1 = &p1;
  PlayerAi p2("C1");
  ptr2 = &p2;
  PlayerAi p3("C2");
  ptr3 = &p3;


  for (int i = 0; i < 5; i++) {
    ptr1->addCard(d->draw());
    ptr2->addCard(d->draw());
    ptr3->addCard(d->draw());
  }
  std::cout<< std::endl;
  std::cout<< "Current hand "<< p1.getName() <<std::endl;
  p1.showHand();
  std::cout<< std::endl;
  std::cout<< "Current score: "<< p1.scoreCount()<< std::endl;
do {
  std::cout<< "Type 'Help' (to display help) or any key to play game ";
  std::cin>> command;

  if (command == "Help") {
    GoFish::help();
  } else {
    p1.userPlay(ptr2, d);
    std::cout<< "Current score: "<< p1.scoreCount()<< std::endl;
    std::cout<< "------------------------------------" <<std::endl;
    p2.computerPlay(ptr1, ptr2, d);
    std::cout<< "Current score: "<< p1.scoreCount()<< std::endl;
    std::cout<< "------------------------------------" <<std::endl;
    p3.computerPlayII(ptr1, ptr3, d);
    std::cout<< "Current score: "<< p1.scoreCount()<< std::endl;
    std::cout<< "------------------------------------" <<std::endl;
  }
} while (d->getSizeDeck() != 0);

  int ScoreCount[3];
  ScoreCount[0] = ptr1->scoreCount();
  ScoreCount[1] = ptr2->scoreCount();
  ScoreCount[2] = ptr3->scoreCount();

  int index;

  for (int i = 1; i < 2; i++) {
    int largest = 0;
    if (largest < ScoreCount[i]) {
      largest = ScoreCount[i];
      index = i;
    }
  }

  if (index == 1) {
    std::cout<< "YOU WIN!";
  } else {
    std::cout<< "YOU LOST";
  }
  delete ptr1;
  delete ptr2;
  delete ptr3;
  delete d;
}
