#include "bullet.h"


// Put your bullet methods here
#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
//#include <iostream>
#include <cmath>

#define BULLET_SPEED 5.0

int Bullet :: getCount()
{
  return count;
}

void Bullet :: draw()
{
  drawDot(point);
  count++;
}

void Bullet :: fire(Point point, float angle, Velocity bulletVelocity) 
{
  velocity.setDx(bulletVelocity.getDx() + BULLET_SPEED * (-cos(M_PI / 180.0 * (-angle + 90)))); 
  velocity.setDy(bulletVelocity.getDy() + BULLET_SPEED * (sin(M_PI / 180.0 * (-angle + 90)))); 
}