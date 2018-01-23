#include "ship.h"
#include <iostream>
using namespace std;
// Put your ship methods here

void Ship :: draw()
{
  drawShip(point, getRotation(), thrust);
}

void Ship :: moveLeft()
{
   rotation += ROTATE_AMOUNT;
}


void Ship :: moveRight()
{
   rotation -= ROTATE_AMOUNT;
}

void Ship :: applyThrust()
{
  //if(canThrust())
   // {
     //cout << "entered applyThrust\n";
      velocity.setDx(velocity.getDx() + THRUST_AMOUNT * (cos(M_PI / 180.0 * (-rotation + 270))));
      velocity.setDy(velocity.getDy() + THRUST_AMOUNT * (-sin(M_PI / 180.0 * (-rotation +270))));
     // setFuel(fuel - 3);
  //  }
}


