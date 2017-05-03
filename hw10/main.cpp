/*
Programmers: Anna Case | Ben Politte
Student Ids: 16181344  | 12533493
Date: 5/3/2017
Class: CS1570 C
Instructor: Dileep Mardham
Description: main file hw 10
*/

#include "heading.h"
#include "town.h"
#include "creatures.h"

int main()
{
  srand(time(NULL));
  TownClass env;
  BullyClass bullies[BARR];
  BullyClass rudedudes[NUMBULLIES];
  TailorClass player;
  PhantomClass ghosts[NUMPHANTOMS];
  int step = 0;
  bool last = false;
  //constructors
  env.proceduralGenerator(); //Builds town (walls, house)
  for (int b=0;b<NUMBULLIES;b++)
  {
    rudedudes[b]=bullies[rand()%BARR];
    rudedudes[b].placement(env);
  }
  //Place tailor
  player.moved(env); //places tailor
  while (!last) //loop 
  {
    player.randWalk(env);
    player.turn(env);
    step++; //increments step/turn
    int punchCount=0;
    for (int q=0;q<NUMBULLIES;q++) //moves bullies
    {
      rudedudes[q].patrol(player,env,punchCount,ghosts);
    }
    for (int h=0;h<NUMPHANTOMS;h++) //moves phantoms
    {
      if (ghosts[h].exists())
      {
        ghosts[h].chase(player, env);
      }
    }
    if (!player.isAlive())
      last = true;
    else if (!player.hasInventory()) //determines if last term
    {
      last = true;
      cout<<player.getName()<<" has run out of pants!"<<endl;
    } 
    else
    {
      if (step==1000)
      {
        last = true;
        cout <<player.getName()<<"'s feet are tired!" << endl;
      }
    }
    if (step<=35|| last) //print town conditions
    {
      cout<<env;
      cout << "Turn " << step << " : " << player << endl;
    }
  }
  return 0;
}
