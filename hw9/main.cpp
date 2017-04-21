// Programmer: Anna Case                         Date: 3/19/2017
// File: definitions.h                           Class: CS1570
// Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: function definitions header

#include "tailor.h"
#include "town.h"

int main()
{
  srand(time(NULL));
  void print (int townsize, int x_loc, int y_loc, town env);
  //Town declarations
  const int NUM_OBJ = 6;
  int treex[6] = {1,1,2,3,4,4};
  int treey[6] = {2,5,5,2,1,3};
  char obj = TREE;
  int townsize = 10;
  int x_loc, y_loc;
  town env;
  //Player declarations
  const int WANDER = 12;
  string naming = "Milhouse";
  char P = 'M';
  int start_x = 2;
  int start_y = 3;
  tailor player;
  
  env.constructor(townsize); //Builds Town
  for (int o=0;o<NUM_OBJ;o++) //Sets town's environment
  {
	x_loc = treex[o];
	y_loc = treey[o];
    env.setTown(x_loc,y_loc,obj);
  }
  
  player.constructor(naming, P); //Builds a player
  player.place_me(start_x,start_y,env); //Place tailor
  print(townsize, x_loc, y_loc, env);
  for (int a=0;a<WANDER;a++) //walks 12 times
  {
    player.rand_walk(env);
	print(townsize, x_loc, y_loc, env);
  }
  return 0;
}

//Pre: town set
//Post: prints town
void print (int townsize, int x_loc, int y_loc, town env)
{
  for (int x=0;x<=townsize;x++)
  {
	x_loc = x;
	for (int y=0;y<=townsize;y++)
	{
	  y_loc = y;
	  cout << env.getTown(x_loc, y_loc);
	}
	cout << endl;
  }
}