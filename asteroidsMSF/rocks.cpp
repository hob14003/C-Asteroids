#include "rocks.h"
#include <iostream>
using namespace std;
// Put your Rock methods here

float Rock :: getRadius()
{
  
}

float Rock :: makeXRandomDirection()
{
  pixXSpeed = (random(0, 100) / 100.0 * pixelSpeed);
  if(random(0, 100) >= 50)
  {
    return pixXSpeed;
  }
  else
  {
    return pixXSpeed * -1;
  } 
   // return (rand(100, 0) / 100 * pixelSpeed * -1);
}

float Rock :: makeYRandomDirection()
{
  pixYSpeed = (pixelSpeed - pixXSpeed);
  if(random(0, 100) >= 50)
  {
    return pixYSpeed;
  }
  else
  {
    return pixYSpeed * -1;
  } 
   // return (rand(100, 0) / 100 * pixelSpeed * -1);
}

void Rock :: draw()
{
  //cout << "Rock draw entered\n";
  //drawLargeAsteroid(point, rotation);
}

float BigRock :: getRadius()
{
  return 16;
}

void BigRock :: draw()
{
 // cout << "BigRock draw entered\n";
  //drawLargeAsteroid(point, random(-1, 1));
  setRotation(getRotation() + 2);
  drawLargeAsteroid(point, getRotation());
}

void MediumRock :: draw()
{
  setRotation(getRotation() + 2);
  drawMediumAsteroid(point, getRotation());
}

float MediumRock :: getRadius()
{
  return 10;
}

void SmallRock :: draw()
{
    setRotation(getRotation() + 2);
    drawSmallAsteroid(point, getRotation());
}

float SmallRock :: getRadius()
{
  return 5;
}