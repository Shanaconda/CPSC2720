/**
* @author Shannon Abeda
* @date 2020-01-24
*/

/**
* This class implements a Computer User of derived
* from the base class Player
*/

#ifndef PLAYERAI_H
#define PLAYERAI_H
#include <string>
#include <Player.h>
#include <vector>


class PlayerAi : public Player {
 public:
  /**
  *Default constructor
  *
  */
  PlayerAi();

  /**
  *Virtual Deconstructor
  *
  */
  virtual ~PlayerAi();

  /**
  *Constructor passes
  *string parameter
  */

  PlayerAi(std::string n);

  /**
  *Method takes in pointers of Player and Computer objects
  *and a SetOfCards. Computer will play a turn
  *
  */
  void computerPlay(Player* p1, PlayerAi* p2, SetOfCards* d);


  /**
  *Method takes in pointers of Player and Computer objects
  *and a SetOfCards. Computer2 will play a turn
  *
  */
  void computerPlayII(Player* p1, PlayerAi*p3, SetOfCards* d);

 private:
};

#endif // PLAYERAI_H
