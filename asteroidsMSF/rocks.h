#ifndef ROCKS_H
#define ROCKS_H

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "uiDraw.h"
#include "velocity.h"
#include "flyingObject.h"

// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock

 
class Rock : public FlyingObject
{
protected:
  int rotation;
  float pixelSpeed;
  float pixXSpeed;
  float pixYSpeed;
  
public:
  virtual ~Rock() { }
  void setAlive(bool alive) { this->alive = alive; }
  void setRotation(int rotation) { this->rotation = rotation; }
  int getRotation() { return rotation; } 
 // void advance();
//  virtual void draw() = 0;// { }
  virtual float getRadius();
  virtual int hit() { }
  virtual void draw();
  float makeXRandomDirection();
  float makeYRandomDirection();
};



class BigRock : public Rock
{
private:
  int numBRock;
  
public:
  BigRock()
  {
    alive = true;
    pixelSpeed = 1;
    point.setX(random(-200, 200));
    point.setY(random(-200, 200));
    velocity.setDx(makeXRandomDirection());
    velocity.setDy(makeYRandomDirection());
    //velocity.setDx(random(-1, 1));
    //velocity.setDy(random(-1, 1));
    //velocity.setDx(1);
    //velocity.setDy(1);
    rotation = (random(0, 360));
    //numBRock = 5;
    //set rotation
  }
 // numBRock = 6;
  
  //void substractNumBRock(int numBRock) { this->numBRock -= numBRock; }
  //int getNumBRock() { return numBRock; }
  
  void draw(); //need to make sure it knows which draw...
  float getRadius();
 // void setRotation() { rotation = 2; }
};

class MediumRock : public Rock
{
private:
 
public:
  MediumRock(Velocity velo, Point pt, float dVelocity)
  {
    alive = true;
    point.setX(pt.getX());
    point.setY(pt.getY());
    velocity.setDx(velo.getDx());
    velocity.setDy(velo.getDy() + dVelocity);
    rotation = 5;

    //set rotation
  }
  void draw();
  float getRadius();
 // void draw(const Point & center, int rotation); //need to make sure it knows which draw...
 // void setRotation() { rotation = 2; }

};

class SmallRock : public Rock
{
private:
 
public:
  SmallRock(Velocity velo, Point pt, float dVelocity)
  {
    alive = true;
    point.setX(pt.getX());
    point.setY(pt.getY() + dVelocity);
    velocity.setDx(velo.getDx() + dVelocity);
    velocity.setDy(velo.getDy());
    rotation = 10;
    //set rotation
  }
 void draw();
 float getRadius();
 // void draw(const Point & center, int rotation); //need to make sure it knows which draw...
 // void setRotation() { rotation = 2; }

};



#endif /* rocks_h */
