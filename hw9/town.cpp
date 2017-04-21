// Programmer: Anna Case                         Date: 3/19/2017
// File: town.cpp	                             Class: CS1570
// Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: town class

#include "town.h"

//Pre: user enters town size
//Post: size of town is set, cleared, and build
void town::constructor (int townsize)
{
  if (townsize<25 && townsize > 4)
  {
	X_size = townsize;
    Y_size = townsize;
  }
  else
  {
	X_size = MAX;
	Y_size = MAX;
  }
  clear();
  build();
  return;
}

//Pre: town size is set
//Post: all characters in array are set
void town::clear () //clears all characters of the town
{
  for (int x=0;x<=X_size;x++)
  {
	for (int y=0;y<=Y_size;y++)
	{
	  area[x][y] = ' ';
	}
  }
  return;
}

//Pre: town size is set
//Post: exterior characters of town are set to walls
void town::build ()
{
  for (int x=0;x<X_size;x++)
  {
    area[x][0] = WALL;
	area[x][Y_size] = WALL;
  }
  for (int y=1;y<Y_size;y++)
  {
    area[0][y] = WALL;
	area[X_size-1][y] = WALL;
  }
  return;
}

//Pre: An environment variable has been declared
//Post: Is added to town array
void town::set_location (int in_x, int in_y, char T)
{
  cout << in_x << endl << in_y << endl << T << endl;
  area[in_x][in_y] = T;
  return;
}
//Pre: An environment variable has been declared
//Post: Is added to town array
void town::setTown (int x_loc, int y_loc, char obj)
{
  area[x_loc][y_loc] = obj;
  return;
}

//Pre: town is fully changed
//Post: town is returned
char town::getTown (int x_loc, int y_loc)
{
  return area[x_loc][y_loc];
}

