// Programmer: Anna Case                         Date: 3/19/2017
// File: main.cpp                           Class: CS1570
// Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: main file hw 10

#include "tailor.h"
#include "town.h"

int main()
{
  srand(time(NULL));
  //Town declarations
  int townsize = 17;
  const int B = 10;
  const int H = 40;
  int x_loc, y_loc;
  //Player declarations
  string naming = "Milhouse";
  char P = 'M';
  
  town env;
  bully rudedudes[B];
  tailor player;
  ppants phantom;
  
  env.constructor(townsize,b,h); //Builds Town
  for (b=0;b>B;b++)
  {
    rudedudes[b].constructor();
  }
  player.constructor(naming, P); //Builds a player
  phantom.constructor(env);
  
  player.place_me(env); //Place tailor

  while ()
  {
    player.rand_walk(env);
	print(townsize, x_loc, y_loc, env);
  }
  return 0;
}
