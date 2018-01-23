/*************************************************************
 * File: velocity.h
 * Author: Harlen Hobbs
 *
 * Description: 
 *************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
//#include "ground.h"
//#include "lander.h"



/*****************************************
 * VELOCITY
 * 
 *****************************************/
class Velocity
{
private:
  float x;
  float y;
public:
  Velocity()
    {
      x = 0;
      y = 0;
    }
  Velocity(float x, float y)
    {
      this->x = x;
      this->y = y;
    }
  float getDx();
  float getDy();
  void setDx(float x);
  void setDy(float y);
};

#endif 
