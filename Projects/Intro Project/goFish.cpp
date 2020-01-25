#include "goFish.h"
#include<iostream>

using namespace std;

GoFish::GoFish() {

}

GoFish::~GoFish() {

}

void GoFish::play() {


}

void GoFish::help() {
  cout<<"These are the rules for the following game"<<endl;

  cout<<"The objective of the game"<<endl;
  cout<<"The goal is to win the most books of cards. A book is any four of a kind, such as four kings, four aces, and so on."<<endl;

  cout<<"The Play"<<endl;
  cout<<"The player to the left of the dealer looks directly at any opponent and says: do you have kings. If the player does not have the card then you must draw from the piles of cards.";
  cout<<"If you have the card, then the other players must give all of the same cards to the other opponent";

}
