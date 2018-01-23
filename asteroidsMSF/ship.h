#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "uiDraw.h"
#include "velocity.h"
#include "flyingObject.h"
#include "point.h"

// Put your Ship class here
class Ship : public FlyingObject
{
private:
  int rotation;
  bool thrust;
  //float pixelSpeed;
  //float pixXSpeed;
  //float pixYSpeed;
  bool alive;
  //float angle; //should perform the same function as rotation
  
public:
  Ship()
  {
    thrust = false;
    alive = true;
    point.setX(0);
    point.setY(0);
    velocity.setDx(0);
    velocity.setDy(0);
    rotation = 0;
  }
  
  void moveLeft();
  void moveRight();
  void applyThrust();
  //float getAngle() const { return angle; }
  Point getPoint() const { return point; }
  //virtual ~Rock() { }
  void setAlive(bool alive) { this->alive = alive; }
  void setRotation(int rotation) { this->rotation = rotation; }
  int getRotation() { return rotation; } 
 //void advanceShip();
//  virtual void draw() = 0;// { }
  int hit() { }
  void draw();
  //float makeXRandomDirection();
  //float makeYRandomDirection();
};

#endif /* ship_h */
