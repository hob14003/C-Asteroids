/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#define CLOSE_ENOUGH 15


#include <vector>
#include "ship.h"
#include "rocks.h"
#include "velocity.h"

#include "bullet.h"
#include <iostream>
using namespace std;


/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br);
   ~Game();
   
   
   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);
   Rock* createRock();
   
   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();
   
   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);
   void drawRocks();
   
   //int getNumBRock() { return numBRock; }
   //void subtractNumBRock(int numBRock) { this->numBRock -= numBRock; }
   float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2)const;

private:
   /*********************************************
    * Function: justLanded
    * Description: Returns true if the lander has
    *  just successfully landed.
    *********************************************/
   //bool justLanded() const;
   
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   vector<Rock*> rock; // make more like bird relationship
   //vector<int*> count;
   Ship ship;
   //Rock* rock;
   //int numBRock;
   int score;
   
   std::vector<Bullet> bullets;
   

  //BigRock * bigRock1;
   
   
   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   bool isOnScreen(const Point & point);
   void advanceBullets();
   void advanceRock();
   void advanceShip();
   //BigRock* createRocks();
   
   void handleCollisions();
   void cleanUpZombies();
   
  
   
};

#endif /* GAME_H */


