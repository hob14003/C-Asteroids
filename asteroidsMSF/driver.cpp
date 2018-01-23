/*****************************************************
 * File: Driver.cpp
 * Author: Br. Burton
 *
 * Description: This file contains the main function
 *  that starts the game and the callback function
 *  that specifies what methods of the game class are
 *  called each time through the game loop.
 ******************************************************/
#include "game.h"
#include "uiInteract.h"
#include <iostream>
using namespace std;
/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void *p)
{
   ////cout << 4 << endl;
   Game *pGame = (Game *)p;
   ////cout << 5 << endl;
   pGame->advance();
   ////cout << 6 << endl;
   pGame->handleInput(*pUI);
   //cout << 7 << endl;
   pGame->draw(*pUI);
   //cout << 8 << endl;
}


/*********************************
 * Main is pretty sparse.  Just initialize
 * the game and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{

   Point topLeft(-200, 200);
   Point bottomRight(200, -200);
   ////cout << 1 << endl;
   Interface ui(argc, argv, "Asteroids", topLeft, bottomRight);
   ////cout << 2 << endl;
   Game game(topLeft, bottomRight);
   ////cout << 3 << endl;
   ui.run(callBack, &game);
   ////cout << 9 << endl;
   return 0;
}
