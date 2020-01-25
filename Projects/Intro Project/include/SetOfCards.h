#ifndef SETOFCARDS_H
#define SETOFCARDS_H

#include <Card.h>
#include <vector>

class SetOfCards : public Card {
 public:
  SetOfCards();
  virtual ~SetOfCards();
  void newDeck();
  Card draw();
  int getSizeDeck(); //testing function

 protected:

 private:
  std::vector<Card> Deck;
};

#endif // SETOFCARDS_H
