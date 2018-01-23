/*************************************************************
 * File: velocity.cpp
 * Author: Harlen Hobbs
 *
 * Description: 
 *************************************************************/

#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

/******************************************
 * LANDER
 *
 ******************************************/

float Velocity :: getDx()
{
  return x;
}

float Velocity :: getDy()
{
  return y;
}

void Velocity :: setDx(float x)
{
    this->x = x;

}

void Velocity :: setDy(float y)
{
   this->y = y;

}
