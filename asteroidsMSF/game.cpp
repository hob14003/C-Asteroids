/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rocks.h"
#include "ship.h"
#include <vector>
#include <iostream>
#include <cmath>

#define OFF_SCREEN_BORDER_AMOUNT 5

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

#define FILE_PATH "imperial_march.wav"
//#include <SDL2/SDL.h>



/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceRock();
   advanceShip();
   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br)
{

  for(int i = 0; i < 5; i++)
   {
   Rock * bRock = new BigRock();
   rock.push_back(bRock);
   }
   score = 0; //perhaps used for milestone
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // TODO: Check to see if there is currently a bird allocated 
   //       and if so, delete it.

  //if (bird != NULL || !bird->())
//  {

 // delete bird;
 // bird = NULL;
//  }
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
         
         if (bullets[i].getCount() == 40)
         {    
            // the bullet has left the screen
            bullets[i].kill();
         }
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE Rock
 *
 * 1. If there is no Rock, create one with some probability
 * 2. If there is a Rock, and it's alive, advance it
 * 3. Check if the Rock has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceRock()
{
  
     for (vector <Rock*> :: iterator it = rock.begin(); it != rock.end(); it++)
     {
       Rock * rock = *it;
      
       /*if (rock == NULL)
       {
         rock = createRock();
       }
       else
       {*/
         if (rock->isAlive())
         {
           rock->advance();
         }
       //}
    }
}

void Game :: advanceShip()
{
  if (ship.isAlive())
  {
    ship.advance();
  }
}

/**************************************************************************
 * GAME :: CREATE ROCK
 * Create a Rock according to the rules of the game.
 **************************************************************************/
/*Rock* Game :: createRock()
{
  switch ((int)rock[i]->getRadius())
  {
    case 16:
     mRock = new MediumRock(rock[i]->getVelocity(), rock[i]->getPoint(), -1);
     rock.push_back(mRock);
     mRock = new MediumRock(rock[i]->getVelocity(), rock[i]->getPoint(), 1);
     rock.push_back(mRock);
     mRock = new SmallRock(rock[i]->getVelocity(), rock[i]->getPoint(), 2);
     rock.push_back(mRock);
     break;
    case 10:
     sRock = new SmallRock(rock[i]->getVelocity(), rock[i]->getPoint(), -3);
     rock.push_back(sRock);
     sRock = new SmallRock(rock[i]->getVelocity(), rock[i]->getPoint(), 3);
     rock.push_back(sRock);
     break;
    case 5:
     break;
    default:
     cout << "Error in handleCollisions switch case\n";
     break;
    } 


  // Rock* newRock = NULL; 
  // newRock = new BigRock();
 
 //  return newRock;
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
 // Rock* newRock1 = NULL;
 // Rock* newRock2 = NULL;

 Rock * mRock;
 Rock * sRock;
 
   for (int i = 0; i < rock.size(); i++)
   {
     for (int j = 0; j < bullets.size(); j++)
     {
        if (bullets[j].isAlive() && rock[i]->isAlive())
        {

          if (getClosestDistance(*rock[i], bullets[j]) < rock[i]->getRadius())
          {
          
           switch ((int)rock[i]->getRadius())
           {
             case 16:
               mRock = new MediumRock(rock[i]->getVelocity(), rock[i]->getPoint(), -1);
               rock.push_back(mRock);
               mRock = new MediumRock(rock[i]->getVelocity(), rock[i]->getPoint(), 1);
               rock.push_back(mRock);
               mRock = new SmallRock(rock[i]->getVelocity(), rock[i]->getPoint(), 2);
               rock.push_back(mRock);
               break;
             case 10:
               sRock = new SmallRock(rock[i]->getVelocity(), rock[i]->getPoint(), -3);
               rock.push_back(sRock);
               sRock = new SmallRock(rock[i]->getVelocity(), rock[i]->getPoint(), 3);
               rock.push_back(sRock);
               break;
             case 5:
               break;
             default:
               cout << "Error in handleCollisions switch case\n";
               break;
            } 
            
            rock[i]->kill();
            bullets[j].kill();
          } 
       }   
     }
     if (ship.isAlive() && rock[i]->isAlive())
     {
       if (getClosestDistance(*rock[i], ship) < rock[i]->getRadius())
       {
         switch ((int)rock[i]->getRadius())
           {
             case 16:
               mRock = new MediumRock(rock[i]->getVelocity(), rock[i]->getPoint(), -1);
               rock.push_back(mRock);
               mRock = new MediumRock(rock[i]->getVelocity(), rock[i]->getPoint(), 1);
               rock.push_back(mRock);
               mRock = new SmallRock(rock[i]->getVelocity(), rock[i]->getPoint(), 2);
               rock.push_back(mRock);
               break;
             case 10:
               sRock = new SmallRock(rock[i]->getVelocity(), rock[i]->getPoint(), -3);
               rock.push_back(sRock);
               sRock = new SmallRock(rock[i]->getVelocity(), rock[i]->getPoint(), 3);
               rock.push_back(sRock);
               break;
             case 5:
               break;
             default:
               cout << "Error in handleCollisions switch case " << rock[i]->getRadius() << endl;
               break;
            } 
            
            rock[i]->kill();
            ship.kill();
       }
       
     }
  }
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game :: cleanUpZombies()
{
  vector<Rock*>::iterator rockIt = rock.begin();
   while (rockIt != rock.end())
   {
     Rock* pRock = *rockIt;
      if (pRock != NULL && !pRock->isAlive())
     {
       delete pRock;
       pRock = NULL;
       rockIt = rock.erase(rockIt);
     }
     else
      rockIt++;
   }
   int count = 0;
   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;
      
      if (!bullet.isAlive() || bullet.getCount() >= 40)
      {
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
    count++;
   }
   
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      ship.moveLeft();
   }
   
   if (ui.isRight())
   {
      ship.moveRight();
   }
   
   if (ui.isUp())
   {
     ship.applyThrust();
   }
   
   // Check for "Spacebar
   if (ui.isSpace() /*&& ammo > 0*/)
   {
      Bullet newBullet1;
      Bullet newBullet2;
      newBullet1.setPoint(ship.getPoint(), 6);
      newBullet2.setPoint(ship.getPoint(), -6);
      newBullet1.fire(ship.getPoint(), ship.getRotation(), ship.getVelocity());
      newBullet2.fire(ship.getPoint(), ship.getRotation(), ship.getVelocity());
      bullets.push_back(newBullet1);
      bullets.push_back(newBullet2);
      /*Bullet newBullet;
      newBullet.setPoint(ship.getPoint());
      newBullet.fire(ship.getPoint(), ship.getRotation(), ship.getVelocity());
      
      bullets.push_back(newBullet);*/
  //    ammo--;
   } 
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
  for (vector <Rock*> :: iterator it = rock.begin(); it != rock.end(); it++)
  {
    Rock * rock = *it;
    if (rock->isAlive()) 
    { 
      rock->draw();
    }

  }
  if (ship.isAlive())
  {
    ship.draw();
  } 
  // draw the bullets, if they are alive
  for (int i = 0; i < bullets.size(); i++)
  {
    if (bullets[i].isAlive())
    {
      bullets[i].draw();
    }
  }
   
   // Put the score on the screen
   //Point scoreLocation;
   //scoreLocation.setX(topLeft.getX() + 5);
   //scoreLocation.setY(topLeft.getY() - 5);
   //drawNumber(scoreLocation, score);
   
   //Point ammoLocation;
   //ammoLocation.setX(bottomRight.getX() - 20);
   //ammoLocation.setY(topLeft.getY() - 5);
   //drawNumber(ammoLocation, ammo);
   
   //Point ammoTextLocation;
   //ammoTextLocation.setX(bottomRight.getX() - 75);
   //ammoTextLocation.setY(topLeft.getY() - 15);
   //drawText(ammoTextLocation, "AMMO:"); 
}



// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   //
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}


