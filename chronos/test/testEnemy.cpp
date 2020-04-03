/*
* CPSC 2720 Spring 2019
* Copyright 2019
* Luke Leontowich <luke.leontowich@uleth.ca>
* Ross Visser <ross.visser@uleth.ca>
* Shannon Abeda <shannon.abeda@uleth.ca>
*/
#include "Enemy.h"
#include "Exception.h"
#include <string>
#include "gtest/gtest.h"

TEST(TestEnemy, constructorTest) {
  Enemy *e;
  e = new Enemy("Slime", 10, 10);
  EXPECT_EQ("Slime", e->getName());
  EXPECT_EQ(10, e->getHealth());
  delete e;
}

TEST(TestEnemy, ExceptionTest) {
  EXPECT_THROW(Enemy e("Slime", 0, 0), invalid_input);
  EXPECT_THROW(Enemy e("Shannon", 100, 100), invalid_name);
}

TEST(TestEnemy, introLineTest) {
  Enemy*s = new Enemy("Slime", 10, 10);
  EXPECT_EQ("The slime plops on the ground, menacingly",
            s->getIntroLine());
  delete s;
  Enemy*f = new Enemy("Face Hugger", 10, 10);
  EXPECT_EQ("Face Hugger sees your face and licks its lips",
            f->getIntroLine());
  delete f;
  Enemy *m = new Enemy("Moblin", 10, 10);
  EXPECT_EQ("Moblin looks disappointed that he has to fight today",
            m->getIntroLine());
  delete m;
  Enemy*h = new Enemy("Hobgoblin", 10, 10);
  EXPECT_EQ("Just like a regular goblin, but this one has an extra hob",
            h->getIntroLine());
  delete h;
  Enemy*c = new Enemy("Creeper", 10, 10);
  EXPECT_EQ("The creeper is hissing with excitement (and explosives)",
            c->getIntroLine());
  delete c;
  Enemy*mo = new Enemy("Monstro", 10, 10);
  EXPECT_EQ("He looks at you menacingly with his one eye and one tooth",
            mo->getIntroLine());
  delete mo;
  Enemy*sk = new Enemy("Skelington", 10, 10);
  EXPECT_EQ("A skeleton with a top hat and a monacle, how fancy",
            sk->getIntroLine());
  delete sk;
  Enemy*spider = new Enemy("Big Ass Spider", 10, 10);
  EXPECT_EQ("Yup, that sure is one big ass spider",
            spider->getIntroLine());
  delete spider;
  Enemy*demon = new Enemy("Demon", 10, 10);
  EXPECT_EQ("The Demon emerges from a hole in the ground, lookin real evil",
            demon->getIntroLine());
  delete demon;
  Enemy*wa = new Enemy("Waluigi", 10, 10);
  EXPECT_EQ("He looks at you and lets out a 'WAAAAAAAAAAAHHHHHHHHHHH'",
            wa->getIntroLine());
  delete wa;
  Enemy* Mbp = new Enemy("Man Bear Pig", 10, 10);
  EXPECT_EQ("50% Man, 50% Bear, 50% Pig, 100% Man Bear Pig",
            Mbp->getIntroLine());
  delete Mbp;
  Enemy*bg = new Enemy("Big Daddy", 10, 10);
  EXPECT_EQ("His drill for a hand, slowly drips blood, gross",
            bg->getIntroLine());
  delete bg;
  Enemy*san = new Enemy("Sans", 10, 10);
  EXPECT_EQ("You just know that you're going to have a bad time",
            san->getIntroLine());
  delete san;
  Enemy*Py = new Enemy("Pyramid Head", 10, 10);
  EXPECT_EQ("You wonder how he can see out of the pyramid on its head",
            Py->getIntroLine());
  delete Py;
  Enemy*dc = new Enemy("Death Claw", 10, 10);
  EXPECT_EQ("You have finally found something scarier than your ex-wife",
            dc->getIntroLine());
  delete dc;
  Enemy*MT  = new Enemy("MewTwo", 10, 10);
  EXPECT_EQ("Mewtwo hates all people, and you happen to be a people",
            MT->getIntroLine());
  delete MT;
  Enemy*dragon = new Enemy("Literally The Biggest Dragon Ever", 10, 10);
  EXPECT_EQ("It's literally the biggest dragon you've ever seen, like ever",
            dragon->getIntroLine());
  delete dragon;

  Enemy*chef = new Enemy("Chef", 10, 10);
  EXPECT_EQ("Hey, whats cookin good lookin? ;)", chef->getIntroLine());
  delete chef;

  Enemy* gen = new Enemy("General Grievous", 10, 10);
  EXPECT_EQ("You say 'Hello There', he turns and says 'General Kenobi'",
            gen->getIntroLine());
  delete gen;
}


TEST(TestEnemy, getDamageTest) {
  Enemy *slime = new Enemy("Slime", 14, 5);
  slime->setDamage();
  EXPECT_NEAR(2, slime->getDamage(), 5);
  EXPECT_FALSE(slime->getDamage() < 2 ||
               slime->getDamage() > 7);
  delete slime;

  Enemy *faceHugger = new Enemy("Face Hugger", 20, 4);
  faceHugger->setDamage();
  EXPECT_NEAR(2, faceHugger->getDamage(), 4);
  EXPECT_FALSE(faceHugger->getDamage() < 2 ||
               faceHugger->getDamage() > 6);
  delete faceHugger;

  Enemy *moblin = new Enemy("Moblin", 17, 7);
  moblin->setDamage();
  EXPECT_NEAR(3, moblin->getDamage(), 7);
  EXPECT_FALSE(moblin->getDamage() < 3 ||
               moblin->getDamage() > 10);
  delete moblin;

  Enemy *creeper = new Enemy("Creeper", 25, 60);
  creeper->setDamage();
  EXPECT_NEAR(30, creeper->getDamage(), 60);
  EXPECT_FALSE(creeper->getDamage() < 30 ||
               creeper->getDamage() > 90);
  delete creeper;

  Enemy *monstro = new Enemy("Monstro", 30, 9);
  monstro->setDamage();
  EXPECT_NEAR(4, monstro->getDamage(), 9);
  EXPECT_FALSE(monstro->getDamage() < 4 ||
               monstro->getDamage() > 13);
  delete monstro;

  Enemy *bigS = new Enemy("Big Ass Spider", 35, 16);
  bigS->setDamage();
  EXPECT_NEAR(8, bigS->getDamage(), 16);
  EXPECT_FALSE(bigS->getDamage() < 8 ||
               bigS->getDamage() > 24);
  delete bigS;

  Enemy *sk = new Enemy("Skelington", 38, 18);
  sk->setDamage();
  EXPECT_NEAR(9, sk->getDamage(), 18);
  EXPECT_FALSE(sk->getDamage() < 9 ||
               sk->getDamage() > 27);
  delete sk;

  Enemy *demon = new Enemy("Demon", 41, 17);
  demon->setDamage();
  EXPECT_NEAR(8, demon->getDamage(), 17);
  EXPECT_FALSE(demon->getDamage() < 8 ||
               demon->getDamage() > 25);
  delete demon;

  Enemy *chef = new Enemy("Chef", 49, 22);
  chef->setDamage();
  EXPECT_NEAR(11, chef->getDamage(), 22);
  EXPECT_FALSE(chef->getDamage() < 11 ||
               chef->getDamage() > 33);
  delete chef;

  Enemy *Mbp = new Enemy("Man Bear Pig", 58, 22);
  Mbp->setDamage();
  EXPECT_NEAR(11, Mbp->getDamage(), 22);
  EXPECT_FALSE(Mbp->getDamage() < 11 ||
               Mbp->getDamage() > 33);
  delete Mbp;

  Enemy *Wal = new Enemy("Waluigi", 54, 24);
  Wal->setDamage();
  EXPECT_NEAR(12, Wal->getDamage(), 24);
  EXPECT_FALSE(Wal->getDamage() < 12 ||
               Wal->getDamage() > 36);
  delete Wal;

  Enemy *BigD = new Enemy("Big Daddy", 62, 25);
  BigD->setDamage();
  EXPECT_NEAR(12, BigD->getDamage(), 25);
  EXPECT_FALSE(BigD->getDamage() < 12 ||
               BigD->getDamage() > 37);
  delete BigD;

  Enemy *sans = new Enemy("Sans", 60, 25);
  sans->setDamage();
  EXPECT_NEAR(12, sans->getDamage(), 25);
  EXPECT_FALSE(sans->getDamage() < 12 ||
               sans->getDamage() > 37);
  delete sans;

  Enemy *Pyd = new Enemy("Pyramid Head", 69, 28);
  Pyd->setDamage();
  EXPECT_NEAR(14, Pyd->getDamage(), 28);
  EXPECT_FALSE(Pyd->getDamage() < 14 ||
               Pyd->getDamage() > 42);
  delete Pyd;

  Enemy *gg = new Enemy("General Grievous", 80, 30);
  gg->setDamage();
  EXPECT_NEAR(15, gg->getDamage(), 30);
  EXPECT_FALSE(gg->getDamage() < 15 ||
               gg->getDamage() > 45);
  delete gg;
  Enemy *mew = new Enemy("MewTwo", 81, 33);
  mew->setDamage();
  EXPECT_NEAR(16, mew->getDamage(), 33);
  EXPECT_FALSE(mew->getDamage() < 16 ||
               mew->getDamage() > 49);
  delete mew;

  Enemy *Big = new Enemy ("Literally The Biggest Dragon Ever", 88, 35);
  Big->setDamage();
  EXPECT_NEAR(17, Big->getDamage(), 35);
  EXPECT_FALSE(Big->getDamage() < 17 ||
               Big->getDamage() > 52);
  delete Big;
}
