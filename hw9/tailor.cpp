// Programmer: Anna Case                         Date: 3/19/2017
// File: tailor.cpp                              Class: CS1570
// Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: tailor class
#include "town.h"
#include "tailor.h"
//Pre: User enters tailor values
//Post: Private variables initialized
void tailor::constructor (string naming, char P)
{
  money = 0.00; //starts broke
  alive = 1; //starts alive
  name = naming;
  T = P;
  return;
}

//Pre: Size of town is set
//Post: Tailor is placed nearest to the middle of the town
void tailor::place_me (int start_x, int start_y, town& env)
{
  static int starting = 0;
  do
  {
    if (start_x>0 || start_y>0)
    {
      in_x = start_x;
      in_y = start_y; 
    }
	starting++;
  } while (starting = 0);
  env.set_location(in_x, in_y, T);
  return;
}

//Pre: Tailor is in a spot
//Post: Tailor walks to random adjacent spot
void tailor::rand_walk (town& env)  
{
  int temp_x = in_x;
  int temp_y = in_y;  
  T = ' ';
  //env.set_location(in_x,in_y,T); //clears old locations
  T = 'M';
  bool occupied = true;
  const int DIR = 4;
  static int bump=0;
  while (occupied)
  {
	switch(rand() % DIR)
	{
      case LEFT:    
	    in_x--;
	    break;
	  case RIGHT:  
	    in_x++;
	    break;
	  case UP: 
	    in_y--;
	    break;
	  case DOWN:  
        in_y++;
	    break;
	}
	bump++;
	if (env.getTown(in_x, in_y)==' ')
	{
	  occupied = false;
	}
	else
	{
	  in_x = temp_x;
	  in_y = temp_y;
	}
  }
  bump--;
  env.set_location(in_x,in_y,T);
  return;
}