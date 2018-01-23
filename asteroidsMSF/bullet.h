#ifndef bullet_h
#define bullet_h

//#define BULLET_SPEED 5
#define BULLET_LIFE 40



// Put your Bullet class here

#include "velocity.h"
#include "point.h"
#include "ship.h"
//#include "game.h"
#include "uiDraw.h"
#include "flyingObject.h"
//#include <iostream>

class Bullet : public FlyingObject
{
  private:
    FlyingObject bullet;
    //Ship ship;
    //bool alive;
    //Velocity velocity;
    //Point point;
    int count;
    
  public:
    Bullet()
    {
     // point.setX(0); //ship.getDx()??
     // point.setY(0);//ship.getY()??
      velocity.setDx(10);
      velocity.setDy(10);
      alive = true;
      count = 0;
    }
    int getCount();
    void draw();
    void fire(Point point, float angle, Velocity bulletVelocity); 
};


#endif /* bullet_h */
