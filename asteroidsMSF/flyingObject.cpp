#include "bullet.h"
#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
#include <iostream>
    
    
Point FlyingObject :: getPoint() const
{
  return point;
}

Velocity FlyingObject :: getVelocity() const
{
  return velocity;
}

bool FlyingObject :: isAlive()
{
  return alive; //alive
}

void FlyingObject :: setPoint(Point point)
{
  this->point = point;
}

void FlyingObject :: setPoint(Point point, float xWing)
{
  this->point.setX(point.getX() + xWing);
  this->point.setY(point.getY());
}

void FlyingObject :: setVelocity(Velocity velocity)
{
  this->velocity = velocity;
}

void FlyingObject :: kill()
{
   alive = false;
}

void FlyingObject :: advance()
{
  //if(x > -200 && x < 200)
  // this->x = x;
  if (point.getX() > 200)
    point.setX(-200);
  if (point.getY() > 200)
    point.setY(-200);
  if (point.getX() < -200)
    point.setX(200);
  if (point.getY() < -200)
    point.setY(200);

  point.setX(point.getX() + velocity.getDx());
  point.setY(point.getY() + velocity.getDy());
}

