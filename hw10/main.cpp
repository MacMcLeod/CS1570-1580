/*
Programmers: Anna Case | Ben Politte
Student Ids: 16181344  | 12533493
Date: 5/3/2017
Class: CS1570 C
Instructor: Dileep Mardham
Description: main file hw 10
*/

#include "heading.h"
int main()
{
  srand(time(NULL));
  TownClass town;
  BullyClass rudedude[NUMBULLIES];
  TailorClass player;
  PhantomClass ghost[NUMPHANTOMS];
  
  //objects
  town env;
  bully rudedudes[NUMBULLIES];
  tailor player;
  phantom ghosts[NUMPHANTOMS];
  //constructors
  env.ProceduralGenerator(); //Builds town (walls, house)
  player.tailor_con ();  //Builds a player
  ghost.pants_con(env);
  rudedudes[0].read_file(); //only needs to be performed once
  for (b=0;b>NUMBULLIES;b++)
  {
    rudedudes[b].bully_con();
  }
  //initial placement
  player.place_me(env); //Place tailor
  //play loop
  while (step < 1000 && player.health != 0 && player.pants != 0)
  {
    player.rand_walk(env);
	player.turn();
	ghost.chase(player, env)
    for (b=0;b>NUMBULLIES;b++)
    {
      rudedudes[b].patrol(env);
    }
	env.printTown();
  }
  return 0;
}
