#include "Player.h"
#include "Card.h"
#include "SetOfCards.h"
#include <algorithm>
#include <iostream>
#include <string>
#include "PlayerAi.h"
#include <vector>


Player::Player() {
}

Player::~Player() {
}


Player::Player(std::string n) {
  name = n;
}


std::string Player::getName() {
  return name;
}


void Player::addCard(Card C) {
  hand.push_back(C);
}


int Player::handSize() {
  return hand.size();
}


Card Player::removeCard(std::string c) {
unsigned int loc = findCard(c);
Card r = hand[loc];
hand.erase(begin(hand)+loc);
return r;
}

int Player::findCard(std::string c) {
  for (unsigned int i=0; i < hand.size(); i++)
    if (c == hand[i].getVal())
      return i;

      return false;
}

bool Player::hasCard(std::string c) {
  std::string key = c;

  for (unsigned int i=0; i < hand.size(); i++) {
    if (hand[i].getVal() == key) {
      return true;
    }
  }
  return false;
}

bool Player::checkRank(Card c, Card d) {
  if (c.getVal() != d.getVal()) {
    return false;
  }

  return true;
}


void Player::showHand() {
  for (unsigned int i=0; i < hand.size(); i++) {
    std::cout << hand[i];
  }
}
Card Player::randomCard() {
  std::vector<Card> randomCards;

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



  for (auto r : ranks) {
    for (auto s : suits) {
    randomCards.push_back(Card(r, s));
    }
  }
    srand(time(NULL));
    random_shuffle(randomCards.begin(), randomCards.end());

    Card T;

    T = randomCards.back();
    randomCards.pop_back();

    return T;
}

void Player::userPlay(Player* p2, SetOfCards* d) {
  std::cout<< "PLAY AGAINST " << p2->getName();
  std::cout<< std::endl;
  std::cout<< "----------------------------------";
  std::cout<< std::endl;
  bool check;
  std::string ask;
  std::cout<< std::endl;
  std::cout<< "From your hand what card do you want: ";
  std::cin>> ask;

  check = p2->hasCard(ask);

  if (check!= true) {
    std::cout<< "GOFISH"<< std::endl;
    Player::addCard(d->draw());
    std::cout<< "You lost your turn " <<p2->getName() << " will now play";
    std::cout<< std::endl;
    std::cout<< "------------------------------------"<< std::endl;
    std::cout<< std::endl;
  } else {
    Player::addCard(p2->removeCard(ask));
    std::cout<< "You received a card! ";
    std::cout<< "You will play again" << std::endl;
    std::cout<< "------------------------------------"<< std::endl;
    std::cout<< std::endl;
    Player::userPlay(p2, d);
  }
}


int Player::scoreCount() {
  int score = 0;

  for (unsigned int i = 0; i < hand.size(); i++) {
    int sum = 0;
    for (unsigned int j = i+1; j < hand.size(); j++) {
      if (checkRank(hand[i], hand[j])) {
        sum++;
      }

      if (sum == 3) {
        score++;
      }
    }
}
return score;
}
