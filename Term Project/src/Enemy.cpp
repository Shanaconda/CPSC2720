/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca
* Ross Visser <ross.visser@uleth.ca
* Shannon Abeda <shannon.abeda@uleth.ca
*/
#include "Enemy.h"
#include "Exception.h"
#include <string>
#include <ctime>
#include <cstdlib>
Enemy::Enemy(std::string n, int h, int d) {
    if (d <= 0) {
      throw invalid_input("DamageStat cannot be zero");
    } else {
      this->setHealth(h);
      this->setName(n);
      damageStat = d;
    }
    if (this->getName() == "Slime") {
      introLine = "The slime plops on the ground, menacingly";
    } else if (this->getName() == "Face Hugger") {
      introLine ="Face Hugger sees your face and licks its lips";
    } else if (this->getName() == "Moblin") {
      introLine = "Moblin looks disappointed that he has to fight today";
    } else if (this->getName() == "Hobgoblin") {
      introLine = "Just like a regular goblin, but this one has an extra hob";
    } else if (this->getName() == "Creeper") {
      introLine = "The creeper is hissing with excitement (and explosives)";
    } else if (this->getName() == "Monstro") {
      introLine = "He looks at you menacingly with his one eye and one tooth";
    } else if (this->getName() == "Zombie") {
      introLine = "'Brians'. The zombie moans, this one must be dyslexic";
    } else if (this->getName() == "Skelington") {
      introLine = "A skeleton with a top hat and a monacle, how fancy";
    } else if (this->getName() == "Orc") {
      introLine =
      "The Orc mumbles something about a single ring ruling them all";
    } else if (this->getName() == "Big Ass Spider") {
      introLine = "Yup, that sure is one big ass spider";
    } else if (this->getName() == "Demon") {
      introLine =
      "The Demon emerges from a hole in the ground, lookin real evil";
    } else if (this->getName() == "Slender Man") {
      introLine = "He is so very slender that you debate pitying him";
    } else if (this->getName() == "Man Bear Pig") {
      introLine = "50% Man, 50% Bear, 50% Pig, 100% Man Bear Pig";
    } else if (this->getName() == "Waluigi") {
      introLine = "He looks at you and lets out a 'WAAAAAAAAAAAHHHHHHHHHHH'";
    } else if (this->getName() == "Big Daddy") {
      introLine = "His drill for a hand, slowly drips blood, gross";
    } else if (this->getName() == "Sans") {
      introLine = "You just know that you're going to have a bad time";
    } else if (this->getName() == "Pyramid Head") {
      introLine = "You wonder how he can see out of the pyramid on its head";
    } else if (this->getName() == "Death Claw") {
      introLine = "You have finally found something scarier than your ex-wife";
    } else if (this->getName() == "General Grievous") {
      introLine = "You say 'Hello There', he turns and says 'General Kenobi'";
    } else if (this->getName() == "MewTwo") {
      introLine =
      "Mewtwo hates all people, and you happen to be a people";
    } else if (this->getName() == "Literally The Biggest Dragon Ever") {
      introLine =
      "It's literally the biggest dragon you've ever seen, like ever";
    } else if (this->getName() == "Chef") {
      introLine = "Hey, whats cookin good lookin? ;)";
    } else {
      throw invalid_name("Enemy is not within the list");
    }
  }
Enemy::~Enemy() {
}
void Enemy::setDamage() {
  double dmg;
  // Changing to rand_r
  /*
  srand(time(NULL));
  int rndm = rand()%11;
  */
  // ***************************
  unsigned int seed = time(NULL);
  int rndm = rand_r(&seed) % 11;
  // ****************************
  if (rndm == 0) {
    dmg = 0.5;
  }
  if (rndm == 1) {
    dmg = 0.6;
  }
  if (rndm == 2) {
    dmg = 0.7;
  }
  if (rndm == 3) {
    dmg = 0.8;
  }
  if (rndm == 4) {
    dmg = 0.9;
  }
  if (rndm == 5) {
    dmg = 1.0;
  }
  if (rndm == 6) {
    dmg = 1.1;
  }
  if (rndm == 7) {
    dmg = 1.2;
  }
  if (rndm == 8) {
    dmg = 1.3;
  }
  if (rndm == 9) {
    dmg = 1.4;
  }
  if (rndm == 10) {
    dmg = 1.5;
  }
  damage = (dmg * damageStat);
}
void Enemy::setDamage(int d) {
  if (d > 0) {
    damage = d;
  } else {
  damage = 0;
  }
}

int Enemy::getDamage() {
  return damage;
}

void Enemy::setHealth(int hp) {
  health = hp;
}

int Enemy::getHealth() {
  return health;
}

std::string Enemy::getIntroLine() {
  return introLine;
}

void Enemy::setName(std::string n) {
  name = n;
}

std::string Enemy::getName() {
  return name;
}

