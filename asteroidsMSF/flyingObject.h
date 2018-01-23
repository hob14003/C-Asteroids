#ifndef FLYINGOBJECTS_H
#define FLYINGOBJECTS_H

//#define BULLET_SPEED 10.0
//float angle = 60.0;

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"

#include <cmath>

class FlyingObject
{
   protected:
    bool alive;
    Velocity velocity;
    Point point;
    
  public:
    Point getPoint() const;
    Velocity getVelocity() const;
    bool isAlive();
    void setPoint(Point point);
    void setPoint(Point point, float xWing);
    void setVelocity(Velocity velocity);
    void kill();
    void advance();
   // void draw(); 
  

};

#endif