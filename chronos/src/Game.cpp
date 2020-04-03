/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "Game.h"
#include "Exception.h"
#include "Enemy.h"
#include "Items.h"
#include "Weapon.h"
#include "Shield.h"
#include "Armor.h"
#include "GameItems.h"
#include "Player.h"
#include<time.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
#include<sstream>

Game::Game() {
  player = nullptr;
  enmy = nullptr;
}

Game::~Game() {
  delete player;
  delete enmy;
}

//  Using this to help with testing
void Game::setSuperPlayer() {
  player = new Player("SUPER_PLAYER", 1, 20, 8, 13);
  player->setHealth(1000);
}
// Using this function to help with testing
void Game::setSuperPlayerFloor(int f) {
  player->setFloor(f);
}
Player* Game::getPlayer() {
  return player;
}

Enemy* Game::getEnemy() {
  return enmy;
}
bool Game::play() {
  int saveload;
  bool valid = false;
  bool success = true;
  std::cout << "Welcome to The Zeven Trials" << std::endl;
  std::cout << "would you like to load the game or start a new game?";
  while (!valid) {
    std::cout << std::endl << "New Game(1) Load Game(2): ";
    std::cin >> saveload;
    if (saveload == 1 || saveload == 2) {
      valid = true;
    } else {
      std::cout << "Invalid Input" << std::endl;
    }
  }
  if (saveload == 1) {
    newGame();
  } else if (saveload == 2) {
    loadGame();
  }
  while (success && player->getFloor() <= 7) {
    if (player->getFloor() == 1) {
      player->setHealth(100);
      success = this-> phaseOne();
      player->setFloor(2);
      saveGame();
      std::cout << "Game Saved" << std::endl;
      player->setHealth(100);
    } else if (player->getFloor() == 2) {
      player->setHealth(100);
      success = this->phaseTwo();
      player->setFloor(3);
      saveGame();
      std::cout << "Game Saved" << std::endl;
      player->setHealth(100);
    } else if (player->getFloor() == 3) {
      player->setHealth(100);
      success = this->phaseThree();
      player->setFloor(4);
      saveGame();
      std::cout << "Game Saved" << std::endl;
      player->setHealth(100);
    } else if (player->getFloor() == 4) {
      player->setHealth(100);
      success = this->phaseFour();
      player->setFloor(5);
      saveGame();
      std::cout << "Game Saved" << std::endl;
      player->setHealth(100);
    } else if (player->getFloor() == 5) {
      player->setHealth(100);
      success = this->phaseFive();
      player->setFloor(6);
      saveGame();
      std::cout << "Game Saved" << std::endl;
      player->setHealth(100);
    } else if (player->getFloor() == 6) {
      player->setHealth(100);
      success = this->phaseSix();
      player->setFloor(7);
      saveGame();
      std::cout << "Game Saved" << std::endl;
      player->setHealth(100);
    } else if (player->getFloor() == 7) {
      player->setHealth(100);
      success = this->phaseSeven();
      player->setFloor(8);
    }
  }
  if (success) {
    std::cout << "You have beaten the dungeon, Congrats!" << std::endl;
  } else {
    std::cout << "The Dungeon has beaten you, ya dead" << std::endl;
  }
  return success;
}
void Game::help() {
  bool valid = true;
  while (valid) {
    std::string help;
    std::cout << "(1) Saving and Loading Game" << std::endl;
    std::cout << "(2) Battle" << std::endl;
    std::cout << "(3) Selecting Treasure Chest Item" << std::endl;
    std::cout << "(4) Help with the puzzle I'm on" << std::endl;
    std::cout << "(5) Exit" << std::endl;
    std::cout << "Welcome to the HELP menu, What do you need help with?: ";
    std::cin >> help;
    if (help == "1") {
      std::cout <<
      "*********************************************************";
      std::cout << std::endl;
      std::cout << "The game automatically saves each time you enter a new";
      std::cout << " floor." << std::endl;
      std::cout << "You can only load a game if you have save data from ";
      std::cout << "another run." << std::endl;
      std::cout <<
      "*********************************************************";
      std::cout << std::endl;
    } else if (help == "2") {
      std::cout <<
      "*********************************************************";
      std::cout << std::endl;
      std::cout << "The Battle in this game works in turns." << std::endl;
      std::cout << "It will tell you how much the enemy intends to attack ";
      std::cout << "for." << std::endl << "You can either block the damage ";
      std::cout << "with your shield and armour." << std::endl;
      std::cout << "Or you can attack and let your armour block the damage.";
      std::cout << std::endl;
      std::cout << "*TIP* if the enemy is planning on attacking for a lot ";
      std::cout << std::endl;
      std::cout << "*TIP* of damage you should block. But if they are ";
      std::cout << std::endl;
      std::cout << "*TIP* attacking for a little damage you should attack ";
      std::cout << std::endl;
      std::cout << "*TIP* them and let your armour negate the damage.";
      std::cout << std::endl;
      std::cout <<
      "*********************************************************";
      std::cout << std::endl;
    } else if (help == "3") {
      std::cout <<
      "*********************************************************";
      std::cout << std::endl;
      std::cout << "When you get a treasure chest it will pick 3 random items.";
      std::cout << std::endl << "One weapon, One shield and One armour";
      std::cout << "Based on your current floor." << std::endl;
      std::cout << std::endl << "You have to choose one of the items to ";
      std::cout << "replace that type of item you already have." << std::endl;
      std::cout << "Weapon replaces Weapon, Shield replaces Shield";
      std::cout << "And Armour replaces Armour." << std::endl;
      std::cout <<
      "*********************************************************";
      std::cout << std::endl;
    } else if (help == "4") {
      int dummy = player->getFloor();
      if (dummy == 1) {
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
        std::cout << "The first puzzle is just a word unscramble" << std::endl;
        std::cout << "You just have to guess what the original word was";
        std::cout << std::endl;
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
      } else if (dummy == 2) {
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
        std::cout << "The second puzzle you have to select the correct door ";
        std::cout << "from 3 choices" << std::endl;
        std::cout << "If the game keeps telling you that you've ended up back ";
        std::cout << "in the foyer" << std::endl << "then you made the wrong ";
        std::cout << "choice" << std::endl;
        std::cout << "To clear the puzzle you have to enter the correct order";
        std::cout << std::endl;
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
      } else if (dummy == 3) {
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
        std::cout << "The third puzzle you have to find the value of the ";
        std::cout << "symbols" << std::endl;
        std::cout << "It will take a little bit of math to solve" << std::endl;
        std::cout << "*TIP* The first equation is 3 * @ = answer" << std::endl;
        std::cout << "*TIP* @ will always be divisible by 3" << std::endl;
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
      } else if (dummy == 4) {
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
        std::cout << "The fourth puzzle you have to pretend that you are ";
        std::cout << "cooking the dish" << std::endl;
        std::cout << "You add each item in stages " << std::endl;
        std::cout << "*TIP* Use the 'last guess' and the" << std::endl;
        std::cout << "*TIP* 'Numbers in the right position'" << std::endl;
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
      } else if (dummy == 5) {
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
        std::cout << "The fifth puzzle you have to answer disease based trivia";
        std::cout << "questions" << std::endl;
        std::cout << "Each time you guess wrong you will lose 10% of your ";
        std::cout << "maximum health" << std::endl;
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
      } else if (dummy == 6) {
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
        std::cout << "The sixth puzzle you have to enter numbers a ";
        std::cout << "certain amount of time apart" << std::endl;
        std::cout << "The timer starts when you hit enter on your first input ";
        std::cout << std::endl << "and stops when you hit enter on your ";
        std::cout << "second input" << std::endl;
        std::cout << "*TIP* the game will take into account plus or minus one";
        std::cout << " second" << std::endl;
        std::cout <<
        "*********************************************************";
        std::cout << std::endl;
      } else if (dummy == 7) {
        std::cout <<
        "**********************************************";
        std::cout<< std::endl;
        std::cout<< "You are Fighting the Boss" << std::endl;
        std::cout<< "This is no time for puzzle help" << std::endl;
        std::cout <<
        "**********************************************";
        std::cout << std::endl;
      }

    } else if (help == "5") {
      std::cout << "Press Control-C to exit the program " << std::endl;
      valid = false;
    }
  }
  return;
}
void Game::newGame() {
  std::string n;
  std::cout << "Please enter your name: " << std::endl;
  std::cin >> n;
  player = new Player(n, 1, 0, 0, 0);
  player->setHealth(100);
}
void Game::saveGame() {
  std::ofstream FILE;
  FILE.open("SaveGame.txt");
  FILE << player->getName() << std::endl;
  FILE << player->getFloor() << std::endl;
  FILE << player->getWeaponPosition() << std::endl;
  FILE << player->getShieldPosition() << std::endl;
  FILE << player->getArmorPosition() << std::endl;
  FILE.close();
  return;
}
void Game::loadGame() {
  std::ifstream FILE;
  FILE.open("SaveGame.txt");
  std::string NAME;
  int FLOOR;
  int WEAPON;
  int SHIELD;
  int ARMOUR;

  FILE >> NAME;
  FILE >> FLOOR;
  FILE >> WEAPON;
  FILE >> SHIELD;
  FILE >> ARMOUR;
  FILE.close();

  player = new Player(NAME, FLOOR, WEAPON, SHIELD, ARMOUR);
  player-> setHealth(100);
  return;
}
bool Game::battle() {
  randEnemy(player-> getFloor());  // creates random enemy based on floor
  std::cout << enmy->getName() << " attacks!" << std::endl;
  std::cout << enmy->getIntroLine() << std::endl;  // enemy intro line
  std::cout << "You hear battle music start playing!" << std::endl << std::endl;
  int turn = 0;  // tracks player / enemy turn
  int plyrAtk;  // stores player attack value
  int negDmg;  // negated damage, removes from enemy attack
  bool valid = false;  // tracks if user enters valid input
  std::string action;
  while (player->getHealth() > 0
         && enmy->getHealth() > 0) {  // while both not dead
    if (turn == 0) {  // player turn
      std::cout << enmy->getName() << " HP:" << enmy->getHealth() << "  ";
      std::cout << "  " << player->getName() << " HP:" << player->getHealth();
      std::cout << std::endl << std::endl;
      enmy->setDamage();  // sets enemy damage for display purposes
      std::cout << enmy->getName() << " will attack for " << enmy->getDamage();
      std::cout << " damage" << std:: endl;
      while (!valid) {
        std::cout << "Will you block(1) or attack(2)?: ";
        std::cin >> action;
        if (action == "help" || action == "Help" || action == "HELP") {
          this->help();
        }
        if (action == "1" || action == "2" || action == "69420") {
             // checks if command is valid
          valid = true;
        } else {
          std::cout << "invalid action" << std::endl;
        }
      }
      if (action == "1") {
        player->setBlock();  // sets block for character
      } else if (action == "2") {
        // stores player damage, because random value
        plyrAtk = player->getDamage();
        std::cout << std::endl;
        std::cout << "You attack " << enmy->getName() << " for " << plyrAtk;
        std::cout << " damage" << std::endl;
        if (plyrAtk > 0) {  // checks if player damage is negative
          enmy->setHealth(enmy->getHealth() - plyrAtk);
        }
      } else if (action == "69420") {
        enmy->setHealth(0);  // cheat code to skip fight
      }
      valid = false;  // resets valid action counter
      turn = 1;  // sets to enemy turn
    } else if (turn == 1) {  // enemy turn
      // sets blocked damage to armour value + shield value if player blocks
      negDmg = player->getBlock() + player->getArmorValue();
      enmy->setDamage(enmy->getDamage() - negDmg);  // removes blocked damage
      std::cout << enmy->getName() << " attacks for " << enmy->getDamage() <<
                " damage" << std::endl;
      std::cout << player->getName() << " blocked " << negDmg << " damage" <<
                std::endl;
      if ((enmy->getDamage() > negDmg) > 0) {  // checks if damage is negative
        // if damage > 0, apply damage to player
        player->setHealth(player->getHealth() - enmy->getDamage());
      }
      // removes block because block doesn't carry from turn to turn
      player->clearBlock();
      turn = 0;
      std::cout << "******************************************************" <<
                std::endl;
    }
  }
  if (player->getHealth() <= 0) {  // player died
    return false;
  }
  std::cout << enmy->getName() << "Has been defeated!" << std::endl;
  std::cout << "You get 0 Gold & 0 XP because this game doesn't do that" <<
            std::endl;
  std::cout << std::endl;
  return true;  // enemy dead
}
void Game::treasureChest(int level) {
  std::cout << std::endl;
  player-> displayInventory();
  std::string select;
  Player temp("Treasure Chest", 0);
  int randwpn = randWeapon(level);
  int randshld = randShield(level);
  int randarm = randArmor(level);
  temp.setWeapon(randwpn);
  temp.setShield(randshld);
  temp.setArmor(randarm);
  std:: cout << std::endl;
  temp.displayInventory();
  std:: cout << std::endl;
restart:
  std::cout << "Make selection (1 for Weapon, 2 for Shield, 3 for Armor): ";
  std::cin >> select;
  if (select == "1") {
    player-> setWeapon(randwpn);
  } else if (select == "2") {
    player ->setShield(randshld);
  } else if (select == "3") {
    player-> setArmor(randarm);
  } else if (select == "Help" || select == "help" || select == "HELP") {
    this->help();
    goto restart;
  } else {
    std::cout << "Invalid selection try again" << std::endl;
    goto restart;
  }
  std::cout << "Your new inventory: " << std::endl;
  player-> displayInventory();
  std::cout << std::endl;
}
bool Game::phaseOne() {
  bool success;
  std::cout << "You make you way down a dark corridor. You see a dark shadow.";
  std::cout << std::endl;
  std::cout << "It looks at you as if asking to fight!" << std::endl;
  success = this-> battle();
  if (success) {
    std::cout << "A chest appears from the enemy's corpse!" << std::endl;
    this->treasureChest(player->getFloor());
    success = this->puzzleOne();
  } else {
     success = false;
  }
  return success;
}
bool Game::puzzleOne() {
  std::string key;
  std::string s;
  std::string guess;
  bool gotIt = false;
  /*
  srand(time(NULL));
  int rndm = rand()%6;
  */
  // ****************************
  unsigned int seed = time(NULL);
  int rndm = rand_r(&seed) % 6;
  // ****************************
  if (rndm == 0) {
    key = "weapon";
  }
  if (rndm == 1) {
    key = "shield";
  }
  if (rndm == 2) {
    key = "armour";
  }
  if (rndm == 3) {
    key = "player";
  }
  if (rndm == 4) {
    key = "enemys";
  }
  if (rndm == 5) {
    key = "reward";
  }
  s += key[2];
  s += key[4];
  s += key[3];
  s += key[0];
  s += key[1];
  s += key[5];
  std::cout << "You find the exit door to the room." << std::endl;
  std::cout << "The door has tiles with the letters on them" << std::endl;
  std::cout << "To open the door you have to unscramble the word" << std::endl;
  do {
    std::cout << "The letters on the door are: ";
    for (unsigned int i = 0; i < s.size(); i ++) {
      std::cout << s[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "What is your guess?: ";
    std::cin >> guess;
    if (guess == key) {
      gotIt = true;
    } else if (guess == "help" ||guess == "Help" ||guess == "HELP") {
      this->help();
    } else {
      std::cout << "The door does nothing, you guess again" << std::endl;
    }
  } while (gotIt == false);
  std::cout << "The tiles sink into place and ";
  std::cout << "the door creaks open" << std::endl;
  std::cout << "the light creeps through the door and you enter" << std::endl;
  return true;
}
bool Game::phaseTwo() {
  bool success;
  std::cout << "You enter a trap door at the back of the room" << std::endl;
  std::cout << "The ladder is rusted and covered in blood of those less";
  std::cout << " fortunate than you" << std::endl;
  std::cout << "At the bottom an enemy waits for you" << std::endl;
  success = this->battle();
  if (success) {
    std::cout << "A chest appears from the enemy's corpse!" << std::endl;
    this->treasureChest(player->getFloor());
    success = this->puzzleTwo();
  } else {
     success = false;
  }
  return success;
}
bool Game::puzzleTwo() {
  /*
  srand(time(NULL));
  int sol1 = rand() % 3 + 1;
  int sol2 = rand() % 3 + 1;
  int sol3 = rand() % 3 + 1;
  */
  // ******************************
  unsigned int seed = time(NULL);
  int sol1 = rand_r(&seed) % 3 + 1;
  int sol2 = rand_r(&seed) % 3 + 1;
  int sol3 = rand_r(&seed) % 3 + 1;
  // *******************************
  std::stringstream s1, s2, s3;
  s1 << sol1;
  std::string sol1Char = s1.str();
  s2 << sol2;
  std::string sol2Char = s2.str();
  s3 << sol3;
  std::string sol3Char = s3.str();
  std::string choice;
  std::cout << std::endl;
  std::cout << "You find yourself in a foyer with 3 doors. " << std::endl;
  std::cout << "You need to go through three rooms to find a way out " <<
            std::endl;
  std::cout << "You will choose 3 doors in each room" << std::endl;
  std::cout << "If you guess wrong you will be sent back to the foyer" <<
            std::endl;
  std::cout << "Which door do you wish to go through" << std::endl;
start:
  std::cout << "Select 1, 2, or 3" << std::endl;
  std::cin >> choice;
  if (choice == "69420") {
    return true;
  } else if (choice == "help" || choice == "Help" || choice == "HELP") {
    this->help();
    goto start;
  } else if (choice != sol1Char) {
    std::cin.clear();
    std::cout << std::endl;
    std::cout << "You open the door... it's dark... the ";
    std::cout << "door slams behind you " << std::endl;
    std::cout <<  "A rag soaked in chloroform appears... " << std::endl;
    std::cout << "You awake several hours later... " << std::endl;
    std::cout << "You're back where you started in the foyer" << std::endl;
    goto start;
  }
  std::cin.clear();
  std::cout << std::endl;
  std::cout << "You open the door, and find yourself ";
  std::cout << "in the kitchen" << std::endl;
  std::cout << "You raid the pantry and now that your full, you want to move on"
            << std::endl;
  std::cout << "You have again 3 doors to choose from to leave" << std::endl;
  std::cout << "select 1, 2 or 3" << std::endl;
  std::cin >> choice;
  if (choice == "69420") {
    return true;
  } else if (choice == "help" || choice == "Help" || choice == "HELP") {
    this->help();
    goto start;
  } else if (choice != sol2Char) {
    std::cin.clear();
    std::cout << std::endl;
    std::cout << "You open the door and unfornately you arrive in the chef's ";
    std::cout << "office"<< std::endl;
    std::cout << "He's not happy you ate all his food" << std::endl;
    std::cout << "The chef cranks you in the head with a ";
    std::cout << "reciepe book" << std::endl;
    std::cout << "You awake back in the foyer" << std::endl;
    std::cout << "Choose a door to leave" << std::endl;
    goto start;
  }
  std::cin.clear();
  std::cout << std::endl;
  std::cout << "You open the door and enter " << std::endl;
  std::cout << "You find yourself in a torture chamber" << std::endl;
  std::cout << "You want to get out of here and fast!" << std::endl;
  std::cout << "Which door do you choose?" << std::endl;
  std::cout << "select 1, 2 or 3 " << std::endl;
  std::cin >> choice;
  if (choice == "69420") {
    return true;
  } else if (choice == "help" ||choice == "Help" ||choice == "HELP") {
    this->help();
    goto start;
  } else if (choice != sol3Char) {
    std::cin.clear();
    std::cout << std::endl;
    std::cout << "You open the door and hear a loud scream" << std::endl;
    std::cout << "You get scared and run back to the foyer" << std::endl;
    std::cout << "You need to get out of here!" << std::endl;
    std::cout << "Choose the door to get out of the foyer" << std::endl;
    goto start;
  }
  std::cout << std::endl;
  std::cout << "You made it!!!" << std::endl;
  std::cout << "Continue on your quest brave one!" << std::endl;
  std::cout << std::endl;
  return true;
}
bool Game::phaseThree() {
  bool success;
  std::cout << "At the end of the torture chamber a light shines from ";
  std::cout << "a crack in the wall" << std::endl;
  std::cout << "You break the wall and follow the light" << std::endl;
  std::cout << "A mathematician is playing with an abacus" << std::endl;
  std::cout << "He gives you a math problem" << std::endl;
  success = this->puzzleThree();
  if (success) {
    std::cout << "The mathematician lets out a scream and turns into ";
    std::cout << "an enemy and attacks you!" << std::endl;
    success = this->battle();
    if (success) {
      std::cout << "A treasure chest emerges from the mathematicians ";
      std::cout << "dead body as it turns to ash" << std::endl;
      this->treasureChest(player->getFloor());
    } else {
       success = false;
    }
  }
  return success;
}
bool Game::puzzleThree() {
  /*
  srand(time(NULL));
  int a = 2 * (rand() % 10) + 2;
  int b = rand() % 10 + 2;
  int c = rand() % 10 + 2;
  */
  // **********************************
  unsigned int seed = time(NULL);
  int a = 2 * (rand_r(&seed) % 10) + 2;
  int b = rand_r(&seed) % 10 + 2;
  int c = rand_r(&seed) % + 2;
  // ***********************************
  std::stringstream ss;
  ss << c;
  std::string C = ss.str();
  std::string choice;
  std::cout << std::endl;
  std::cout << "You break the wall and follow the light" << std::endl;
  std::cout << "A mathematician is playing with an abacus" << std::endl;
  std::cout << "He gives you a math problem" << std::endl;
  std::cout << std::endl;
start:
  std::cout << std::endl;
  std::cout << "@ + @ + @ = " << a + a + a << std::endl;
  std::cout << "@ + # + # = " << a + b + b << std::endl;
  std::cout << "@ + # + $ = " << a + b + c << std::endl;
  std::cout << std::endl;
  std::cout << "What is the vale of $?" << std::endl;
  std::cin >> choice;
  std::cin.clear();
  std::cin.ignore();
  if (choice == C || choice == "69420") {
    std::cout << "Correct! " << std::endl;
    std::cout << std::endl;
    return true;
  } else if (choice == "help" ||choice == "Help" ||choice == "HELP") {
    this->help();
    goto start;
  } else {
    std::cout << "Incorrect! Try again." << std::endl;
    std::cout << std::endl;
    goto start;
  }
}
bool Game::phaseFour() {
  bool success;
  std::cout << "Continuing on you find yourself in the chefs kitchen";
  std::cout << std::endl;
  success = this->puzzleFour();
  return success;
}
bool Game::puzzleFour() {
  bool success = false;
  int decision;
  bool valid = false;
  std::cout << "The chef who's food you ate all of stands in front of you";
  std::cout << std::endl << "And boy is he pissed"<< std::endl;
  std::cout << "He gives you an ultimatum. " << std::endl;
  std::cout << "You can solve his cooking";
  std::cout << " riddle OR you can fight him!" << std::endl;
  while (!valid) {
    std::cout << "Solve the riddle(1) Fight the chef(2):" << std::endl;
    std::cin >> decision;
    if (decision == 1 || decision == 2) {
      valid = true;
    } else {
      std::cout << "Invalid choice" << std::endl;
    }
  }
  if (decision == 1) {
    valid = false;
    int corNum = 0;  // correct Numbers
    bool firstGuess = true;
    std::string guess;
    std::string lastGuess = "";
    std::cout << "Little does the chef know, you minored in riddles ";
    std::cout << "at the lethbdrige clown college" << std::endl;
    std::cout << "The Chef says, give me the correct order ";
    std::cout << "of ingredients to make a lovely . . ." << std::endl;
    std::cout << "MUSHROOM RISOTTO!!!" << std::endl << std::endl;
    std::cout << "The chef lists off the ingredients and wants them ";
    std::cout << "in the right order." << std::endl;
    while (!valid) {
      std::cout << "Ingredients: Mushroom(1), Oil(2), Stock(3), ";
      std::cout << "Cheese(4), Rice(5)" << std::endl;
      std::cout << "( Enter as one number EXAMPLE: 15342 )";
      std::cout << std::endl;
      if (!firstGuess) {
        std::cout << "Your last guess: " << lastGuess << std::endl;
        std::cout << corNum << " numbers in the right position";
        std::cout << std::endl;
        corNum = 0;
      }
      std::cout << "Your Guess: ";
      std::cin >> guess;
      if (guess == "69420") {
        return true;
      } else if (guess == "help" ||guess == "Help" ||guess == "HELP") {
        this->help();
      }
      std::cout << std::endl << std::endl;
      firstGuess = false;
      lastGuess = guess;
      if (guess.length() > 5) {
        std::cout << "That is too many numbers!!" << std::endl;
      } else if (guess.length() < 5) {
        std::cout << "Thats not enough numbers!!" << std::endl;
      } else {
        if (guess[0] == '2') {
          corNum++;
        }
        if (guess[1] == '1') {
          corNum++;
        }
        if (guess[2] == '5') {
          corNum++;
        }
        if (guess[3] == '3') {
          corNum++;
        }
        if (guess[4] == '4') {
          corNum++;
        }
        if (corNum != 5) {
          std::cout << "The Chef laughs. Try again" << std::endl;
        } else {
          valid = true;
          success = true;
        }
      }
    }
  } else if (decision == 2) {
    std::cout << "You have chosen to Battle!" << std::endl;
    success = this->battle();
    if (success) {
      this->treasureChest(player->getFloor());
    }
  }
  if (decision == 1) {
    std::cout << "The Chef cannot believe it, you've solved his riddle";
    std::cout << "He pulls a treasure chest out of his pocket" << std::endl;
    this->treasureChest(player->getFloor());
    std::cout << std::endl << "He moves out of the way revealing a trap ";
    std::cout << "door to the next floor" << std::endl;
  }
  return success;
}
bool Game::phaseFive() {
  bool success;
  std::cout << "You can feel the presence of evil getting stronger in the";
  std::cout << " dungeon, its unsettling" << std::endl;
  std::cout << "All of a sudden the roof collapses in and an enemy falls";
  std::cout << " through the roof!" << std::endl;
  std::cout << "It brushes itself off and attacks you" << std::endl;
  success = this->battle();
  if (success) {
    std::cout << "A chest appears from the enemy's corpse!" << std::endl;
    this->treasureChest(player->getFloor());
    success = this->puzzleFive();
  } else {
     success = false;
  }
  return success;
}
bool Game::puzzleFive() {
  int counter = 10;
  std::string decision1, decision2, decision3;
  std::string key1 = "A";
  std::string key2 = "C";
  std::string key3 = "C";
  std::cout << "Surprise, you have encountered the COVID-19 and boy ";
  std::cout << "has it mutated" << std::endl;
  std::cout << "You have been infected and are ";
  std::cout << "the brink of death. " << std::endl;
  std::cout << "But there is hope, you can discover the cure " << std::endl;
  std::cout << "Sometimes, our past tells a story and is ";
  std::cout << "the key to our future. " << std::endl;
  std::cout << "H1N1, the Flu Pandemic, The Black Death ";
  std::cout << "all have the hidden keys to ";
  std::cout << "finding our cures " << std::endl;
  std::cout << "Solve the trivial questions, save the world. ";
  std::cout << "If you get one wrong, the virus will continue to deteriorate ";
  std::cout << "your health... until you die " << std::endl;
  std::cout << "the clock is ticking....." << std::endl;
start:
  if (player->getHealth() <= 0) {
    return false;
  } else {
    std::cout << "Your current health is: " << player->getHealth() << std::endl;
  }
  std::cout<< "Which of the following location was ground zero for H1N1: ";
  std::cout << std::endl;
  std::cout<< "A)Mexico" << std::endl;
  std::cout<< "B)China" << std::endl;
  std::cout<< "C)Iran" << std::endl;
  std::cout<< "Select A) B) or C): " << std::endl;
  std::cin >> decision1;

  if (decision1 == "69420") {
    return true;
  } else if (decision1 == "help" ||decision1 == "Help" ||decision1 == "HELP") {
    Game::help();
    goto start;
  }
  /**
  *Extraction failure case
  */
  if (std::cin.fail()) {
    std::cin.clear();
    throw input_failure("Extraction failure");
  } else if (decision1 == "69420") {
    return true;
  } else if (decision1 == "help" || decision1 == "Help" ||decision1 == "HELP") {
    Game::help();
    goto start;
  } else if (isdigit(decision1[0])) {
    std::cout << "You cannot enter a digit value! Try again" << std::endl;
    goto start;
  } else {
    /**
    *Uppercase user input
    **/
    decision1 = toupper(decision1[0]);
  }

    if (decision1 == key1) {
    std::cout << "Correct! You're one step closer to the cure" <<std::endl;
  } else if (decision1!= "A" && decision1 != "B" && decision1 != "C") {
      std::cout<< "Invalid input, select one of the listed letter"<< std::endl;
      goto start;
    } else {
    std::cout << "Wrong answer, you've now have ";
    std::cout << "developed pneumonia" << std::endl;
    player->setHealth(player->getHealth() - 10);
    goto start;
  }
start2:
  if (player->getHealth() <= 0) {
    return false;
  } else {
    std::cout << "Your current health is: "<< player->getHealth() << std::endl;
  }
  std::cout << "The 1918 flu infected 500mil and killed 20-50mil globally ";
  std::cout << "In relation to the global population, what was the ";
  std::cout << "percentage fatality" << std::endl;
  std::cout << "A)2.4" << std::endl;
  std::cout << "B)0.5" << std::endl;
  std::cout << "C)0.95" << std::endl;
  std::cout << "Select A) B) or C): ";
  std::cin >> decision2;

  if (decision2 == "help" ||decision2 == "Help" ||decision2 == "HELP") {
    Game::help();
    goto start2;
  }
  /**
  *Extraction failure case2
  */
  if (std::cin.fail()) {
    std::cin.clear();
    throw input_failure("Extraction failure");
  } else if (decision2 == "help" ||decision2 == "Help" ||decision2 == "HELP") {
    Game::help();
    goto start2;
  } else if (isdigit(decision2[0])) {
    std::cout << "You cannot enter a digit value! Try again" << std::endl;
    goto start2;
  } else {
    /**
    *Uppercase user input
    **/
    decision2 = toupper(decision2[0]);
  }
  if (decision2 == key2) {
    std::cout << "You're making progress, you've ";
    std:: cout << "contained the virus" << std::endl;
    std::cout << "Vaccines are now in development" << std::endl;
  } else if (decision2!= "A" && decision2 != "B" && decision2 != "C") {
      std::cout<< "Invalid input, select one of the listed letter"<< std::endl;
      goto start2;
    } else {
    std::cout << "The virus has now infected and killed " << counter;
    std::cout << " of the population and its growing" << std::endl;
    counter +=5;
    player->setHealth(player->getHealth() - 10);
    std::cout << std::endl;
    goto start2;
  }
start3:
  if (player->getHealth() <= 0) {
    return false;
  } else {
    std::cout << "Your current health is: " << player->getHealth() << std::endl;
  }
  std::cout << "The black death is historically remembered as the the most ";
  std::cout << "devastating pandemic in human history that resulted in ";
  std::cout << std::endl;
  std::cout << "75 to 200 million people in Eurasia. ";
  std::cout << "What year did the black plague first appeared?" << std::endl;
  std::cout << "A) 1452" << std::endl;
  std::cout << "B) 1351" << std::endl;
  std::cout << "C) 1347" << std::endl;
  std::cout << "D) 1419: ";
  std::cout << "Select A) B) C) or D): ";
  std::cin >> decision3;

  if (std::cin.fail()) {
    if (decision3 == "help" ||decision3 == "Help" ||decision3 == "HELP") {
      Game::help();
      goto start3;
    }
  if (std::cin.fail()) {
     std::cin.clear();
    throw input_failure("Extraction failure");
  } else if (decision3 == "help" ||decision3 == "Help" ||decision3 == "HELP") {
    Game::help();
    goto start3;
  } else if (isdigit(decision3[0])) {
    std::cout << "You cannot enter a digit value! Try again" << std::endl;
    goto start3;
  } else {
    /**
    *Uppercase user input
    **/
    decision3 = toupper(decision3[0]);
  }
  if (decision3 == key3) {
    std::cout << "The virus has successfully being eradicated" << std::endl;
    std::cout << "You've save the world and now may continue ";
    std:: cout << "along with your journey" << std::endl;
  } else if (decision3!= "A" && decision3 != "B" && decision3 != "C"
          && decision3 != "D") {
      std::cout<< "Invalid input, select one of the listed letter"<< std::endl;
      goto start3;
    } else {
    std::cout << "The virus is now out of control" << std::endl;
    std::cout<< "Your vital organs are starting to shut down" << std::endl;
    std::cout<< "Your health will now decrease by 30%.. hurry"<< std::endl;
    player->setHealth(player->getHealth() - 30);
    goto start3;
  }
  return true;
  }
}
bool Game::phaseSix() {
  bool success;
  std::cout << "Almost a the bottom, you can feel it" << std::endl;
  std::cout << "This place just gets worse and worse" << std::endl;
  std::cout << "An enemy glares up at you from the corner" << std::endl;
  std::cout << "It says ''You never should have come here''" << std::endl;
  success = this->battle();
  if (success) {
    std::cout << "Woah! 2 treasure chests appear" << std::endl;
    std::cout << "You open the first teasure chest" << std::endl;
    this->treasureChest(player->getFloor());
    std::cout << std::endl;
    std::cout << "You open the second bigger treasure chest!" << std::endl;
    this->treasureChest((player->getFloor() + 1));
    success = this->puzzleSix();
  } else {
     success = false;
  }
  return success;
}
bool Game::puzzleSix() {
  bool valid = false;
  time_t start, stop;
  double elapsed;
  int goneBy;
  std::string dummy;
  std::cout << "A Time Lizard appears in front of you, he knows his ";
  std::cout << "name should be Wizard, but the devs are lazy" << std::endl;
  std::cout << "Regardless he wants you to guess the right time!" << std::endl;
  std::cout << std::endl;
  std::cout << "**He whispers in your ear to explain the game**" << std::endl;
  std::cout << "**you can enter any number, the important part is when you hit";
  std::cout << " enter**" << std::endl << "**the time between when you hit ";
  std::cout << "enter is measured**" << std::endl;
  std::cout << "The Time lizard gives you the first test" << std::endl;
  while (!valid) {
    std::cout << std::endl;
    std::cout << "Enter two numbers 5 seconds apart (numbers don't matter)";
    std::cout << std::endl << "You will be judged on accuracy" << std::endl;
    std::cout << "Enter anything to start: ";
    std::cin >> dummy;
    if (dummy == "69420") {
      return true;
    } else if (dummy == "help" || dummy == "Help" || dummy == "HELP") {
      this->help();
    } else {
      start = time(0);
      std::cout << "Count to 5 and enter anything to stop: ";
      std::cin >> dummy;
      stop = time(0);
      elapsed = stop - start;
      goneBy = elapsed;
      std::cout << "You entered " << goneBy << " seconds apart" << std::endl;
      if (goneBy == 5) {
        std::cout << "Damn, that was perfect" << std::endl;
        std::cout << "*Success*" << std::endl;
        valid = true;
      } else if (4 == goneBy || goneBy == 6) {
        std::cout << "You were a little off, but I'll count it" << std::endl;
        std::cout << "*Success*" << std::endl;
        valid = true;
      } else {
        std::cout << "I might be a Lizard, but that wasn't even close";
        std::cout << "*Fail*" << std::endl;
        std::cout << std::endl << "Try Again" << std::endl;
      }
    }
  }
  valid = false;
  std::cout << std::endl << std::endl;
  std::cout << "Time for the next test!" << std::endl;
  while (!valid) {
    std::cout << std::endl;
    std::cout << "Enter two numbers 10 seconds apart ";
    std::cout << std::endl << "You will be judged on accuracy" << std::endl;
    std::cout << "Enter anything to start: ";
    std::cin >> dummy;
    if (dummy == "help" || dummy == "Help" || dummy == "HELP") {
      this->help();
    } else {
      start = time(0);
      std::cout << "Count to 10 and enter anything to stop: ";
      std::cin >> dummy;
      stop = time(0);
      elapsed = stop - start;
      goneBy = elapsed;
      std::cout << "You entered " << goneBy << " seconds apart" << std::endl;
      if (goneBy == 10) {
        std::cout << "Damn, that was perfect" << std::endl;
        std::cout << "*Success*" << std::endl;
        valid = true;
      } else if (9 == goneBy  || goneBy == 11) {
        std::cout << "You were a little off, but I'll count it" << std::endl;
        std::cout << "*Success*" << std::endl;
        valid = true;
      } else {
        std::cout << "I might be a Lizard, but that wasn't even close";
        std::cout << "*Fail*" << std::endl;
        std::cout << std::endl << "Try Again" << std::endl;
      }
    }
  }
  valid = false;
  std::cout << std::endl << std::endl;
  std::cout << "Time for the Final Test!" << std::endl;
  while (!valid) {
    std::cout << std::endl;
    std::cout << "Enter two numbers 17 seconds apart ";
    std::cout << std::endl << "You will be judged on accuracy" << std::endl;
    std::cout << "Enter anything to start: ";
    std::cin >> dummy;
    if (dummy == "help" || dummy == "Help" || dummy == "HELP") {
      this->help();
    } else {
      start = time(0);
      std::cout << "Count to 17 and enter anything to stop: ";
      std::cin >> dummy;
      stop = time(0);
      elapsed = stop - start;
      goneBy = elapsed;
      std::cout << "You entered " << goneBy << " seconds apart" << std::endl;
      if (goneBy == 17) {
        std::cout << "Damn, that was perfect" << std::endl;
        std::cout << "*Success*" << std::endl;
        valid = true;
      } else if (16 == goneBy || goneBy == 18) {
        std::cout << "You were a little off, but I'll count it" << std::endl;
        std::cout << "*Success*" << std::endl;
        valid = true;
      } else {
        std::cout << "I might be a Lizard, but that wasn't even close";
        std::cout << "*Fail*" << std::endl;
        std::cout << std::endl << "Try Again" << std::endl;
      }
    }
  }
  std::cout << std::endl << std::endl;
  std::cout << "The Time Lizard is happy with your results" << std::endl;
  std::cout << "He says he's happy that time hasn't been lost down here";
  std::cout << std::endl;
  return valid;
}
bool Game::phaseSeven() {
  std::cout << "You enter the final floor of the dungeon" << std::endl;
  std::cout << "The final boss stares you down with an evil look";
  std::cout << std::endl << "Well, lets do this" << std::endl;
  bool success = this->battle();
  return success;
}
void Game::randEnemy(int level) {
  delete enmy;
  enmy = nullptr;
  /*
  srand(time(NULL));
  unsigned int x = rand()%3;
  */
  // *******************************
  unsigned int seed = time(NULL);
  unsigned int x = rand_r(&seed) % 3;
  // ********************************

  if (level == 1) {
    if (x == 0) {
      enmy = new Enemy("Slime", 14, 5);
    } else if (x == 1) {
      enmy = new Enemy("Face Hugger", 20, 4);
    } else if (x == 2) {
      enmy = new Enemy("Moblin", 17, 7);
    }
  } else if (level == 2) {
    if (x == 0) {
      enmy = new Enemy("Hobgoblin", 27, 11);
    } else if (x == 1) {
      enmy = new Enemy("Creeper", 25, 10);
    } else if (x == 2) {
      enmy = new Enemy("Monstro", 30, 9);
    }
  } else if (level == 3) {
    if (x == 0) {
      enmy = new Enemy("Big Ass Spider", 35, 16);
    } else if (x == 1) {
      enmy = new Enemy("Skelington", 38, 18);
    } else if (x == 2) {
      enmy = new Enemy("Demon", 41, 17);
    }
  } else if (level == 4) {
    enmy = new Enemy("Chef", 40, 25);
  } else if (level == 5) {
    if (x == 0) {
      enmy = new Enemy("Man Bear Pig", 58, 22);
    } else if (x == 1) {
      enmy = new Enemy("Waluigi", 54, 24);
    } else if (x == 2) {
      enmy = new Enemy("Big Daddy", 62, 25);
    }
  } else if (level == 6) {
    if (x == 0) {
      enmy = new Enemy("Sans", 60, 25);
    } else if (x == 1) {
      enmy = new Enemy("Death Claw", 66, 27);
    } else if (x == 2) {
      enmy = new Enemy("Pyramid Head", 69, 28);
    }
  } else if (level == 7) {
    if (x == 0) {
      enmy = new Enemy("General Grievous", 80, 30);
    } else if (x == 1) {
      enmy = new Enemy("MewTwo", 81, 33);
    } else if (x == 2) {
      enmy = new Enemy("Literally The Biggest Dragon Ever", 88, 35);
    }
  }
}
int Game::randWeapon(const int level) {
  GameItems inventory;
  /*
  srand(time(NULL));
  //random number divided into 7 sections of array depending on level

  unsigned int x = rand()%4 + (level-1) * 3;
  */
  // **************************************************
  unsigned int seed = time(NULL);
  unsigned int x = rand_r(&seed) % 4 + (level - 1) * 3;
  // **************************************************
  // To prevent segmation fault for last weapon
  if (x >= inventory.wListSize()) {
    x = inventory.wListSize() -1;
  }
  return x;
}
int Game::randArmor(const int level) {
  GameItems inventory;
  /*
  srand(time(NULL));
  //random number divided into 7 sections of array depending on level
  unsigned int x = rand()%4 + (level-1) * 2;
  */
  // **************************************************
  unsigned int seed = time(NULL);
  unsigned int x = rand_r(&seed) % 4 + (level - 1) * 2;
  // **************************************************
  // To prevent segmation fault for last weapon
  if (x >= inventory.aListSize()) {
    x = inventory.aListSize() -1;
  }
  return x;
}
int Game::randShield(const int level) {
  GameItems inventory;
  /*
  srand(time(NULL));
  //random number divided into 7 sections of array depending on level
  unsigned int x = rand()%4 + (level-1);
  */
  // *********************************************
  unsigned int seed = time(NULL);
  unsigned int x = rand_r(&seed) % 4 + (level - 1);
  // **********************************************
  // To prevent segmation fault for last weapon
  if (x >= inventory.sListSize()) {
    x = inventory.sListSize() -1;
  }
  return x;
}
