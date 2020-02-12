#include "PlayerAi.h"
#include <string>


PlayerAi::PlayerAi() {
  //ctor
}

PlayerAi::~PlayerAi() {
  //dtor
}

PlayerAi::PlayerAi(std::string n) {
  name = n;
}

void PlayerAi::computerPlay(Player* p1, PlayerAi* p2, SetOfCards* d) {
  std::string ask;
  std::string c;
  std::cout<< "This is your current hand: " << std::endl;
  p1->showHand();
  std::cout<< std::endl;
  std::cout<< "Do you have: "<< p1->randomCard().getVal() << std::endl;
  std::cout<< "Type 'Yes' or no: ";
  std::cin>> ask;



    if (ask == "Yes") {
    std::cout<< "Just to confirm, what card are you giving up: ";
    std::cin>> c;
    p2->addCard(p1->removeCard(c));
    std::cout<< p2->getName() << " took your card. ";
    std::cout<< p2->getName() << " will play again" << std::endl;
    std::cout<< "------------------------------------"<< std::endl;
    std::cout<< std::endl;
      PlayerAi::computerPlay(p1, p2, d);
    } else {
    std::cout<< p2->getName() << " WILL GO FISH" <<std::endl;
    p2->addCard(d->draw());
    std::cout<< "Computer 2 will now play";
    std::cout<< std::endl;
    std::cout<< "---------------------------"<< std::endl;
    std::cout<< std::endl;
  }
}
void PlayerAi::computerPlayII(Player* p1, PlayerAi* p3, SetOfCards* d) {
  std::string ask;
  std::string c;
  std::cout<< "This is your current hand: " << std::endl;
  p1->showHand();
  std::cout<< std::endl;
  std::cout<< std::endl;
  std::cout<< "Do you have "<< p1->randomCard().getVal() << std::endl;
  std::cout<< "Type 'Yes' or no: ";
  std::cin>> ask;


  if (ask == "Yes") {
    std::cout<< "Just to confirm, what card are you giving up: ";
    std::cin>> c;
    p3->addCard(p1->removeCard(c));
    std::cout<< p3->getName() << " will play again" << std::endl;
    std::cout<< "------------------------------------" <<std::endl;
    PlayerAi::computerPlayII(p1, p3, d);
  } else {
    std::cout<< "COMPUTER2 WILL GO FISH" <<std::endl;
    p3->addCard(d->draw());
    std::cout<< "You will now play" <<std::endl;
    std::cout<< "------------------------------------" <<std::endl;
    std::cout<< std::endl;
  }
}
