/*
Programmers: Anna Case | Ben Politte
Student Ids: 16181344  | 12533493
Date: 5/3/2017
Class: CS1570 C
Instructor: Dileep Mardham
Description: moving creatures functions
*/
#include "creatures.h"
//============================================================================//
//Pre: Game started
//Post: A pair of phantom pants are placed out of range
void TailorClass::randWalk (TownClass & env)  
{
  bool success=false;
  env.replaceSymbol(coord, EMPTY);
  while(!success)
  {
    switch(rand()%DIR);
    {
    case LEFT:
      success=move(LEFT,DIST,coord,env);
      break;
    case RIGHT:
      success=move(RIGHT,DIST,coord,env);
      break;
    case UP:
      success=move(UP,DIST,coord,env);
      break;
    case DOWN:
      success=move(DOWN,DIST,coord,env);
      break;
    }
  }
  env.replaceSymbol(coord,P); //places tailor
  return;
}

//Pre: Player has moved
//Post: Acts accordingly
bool TailorClass::turn ()
{
  const int SALE = 10;
  const int SOLD = 1;
  for (int i=0;i<DIR;i++)
  {
	char inDir = checkDir(i);
	if (inDir == BULLY)
	{
	  rudedudes[rand%NUMBULLIES+1].punch(player);
	}
	else if (inDir==HOUSE && thrown==0)
	{
	  money += SALE;
	  pants -= SOLD;
	  //######thrown of house = 1
	}
  }
  return;
}

//Pre: a fence and a bully are next to the player
//Post: Milhouse will (maybe) jump the fence if it is clear
bool TailorClass::jumpFence (TownClass & env)
{
  const short JUMPCHANCE = 40;
  bool success = false;
  if (fence && rand%100>=JUMPCHANCE)
  {
	success=move(TOFENCE,DIST+1,coord,env);
	if (success) //else something on otherside of fence
	  env.replaceSymbol(coord,P);
  }
  return success;
}

//Pre: Player has moved
//Post: Player returns character in a direction
char TailorClass::checkDir(int dir)
{
  point around = coord;
  switch(rand()%DIR);
    {
    case DOWN:
      around.y -=DIST;
      break;
	case RIGHT:
      around.x +=DIST;
	  break;
	case UP:
      around.y +=DIST;
      break;
    case LEFT:
      around.x -=DIST;
      break;
    }
  return env.checkgrid(around);
}
//============================================================================//
/*//Pre: Game started
//Post: A pair of phantom pants are placed out of range
void PhantomClass::pants_con(TownClass & env)
{
  env.
  return;
}*/

//Pre: A pair of pants have been dropped
//Post: A phantom seeks Milhouse
void PhantomClass::place_pants(TownClass & env)
{
  while (grid != EMPTY)
  {
	coord.x = rand() % (TOWNSIZE + 1);
    coord.y = % (TOWNSIZE + 1);
  }
  //####place(PANTS, point & coord, point newLocation, TownClass & env)
  return;
}

//Pre: The tailor has moved
//Post: There is a 25% chance the phantom(s) have moved
void PhantomClass::chase(TailorClass player, TownClass& env)
{
  if (((coord.x+DIST)||(coord.x-DIST)==player.coord.x))&&((coord.y-DIST)||(coord.y-DIST)==player.coord.y)))
    kill(player);
  else
  {
	place (&coord.x, &coord.y)
	if (rand%100<=CHASE)
      //#######placePhantom(at_x, at_y);
  }
  return;
}

//Pre: Tailor has been killed by phantom pants
//Post: Tailor's attributes are set to dead 
void PhantomClass::kill(TailorClass& player)
{
  player.alive = 0;
  player.health = 0;
  return;
}

//===========================================================================//

//Pre: files are created, bullies are not initialized
//Post: a list of names and insults are made
void BullyClass::read_file()
{
  //Names
  ifstream in;
  in ("bullies.dat");
  in.open();
  while( std::getline(in, names))
    names_in_file.push_back(names);
  namelist = names_in_file.size();
  in.close();
  //Messages
  ifstream in;
  in ("message.dat");
  in.open();
  while(std::getline(in, insults))
    insults_in_file.push_back(insults);
  insultlist = insults_in_file.size();
  in.close();
  return;
}

//Pre: a number of bullies have been declared
//Post: their values are initialized
BullyClass::BullyClass()
{
  Bname = names_in_file[rand & namelist];
  punch_power = rand() % MAXP + MINP;
  in.close();
}

//Pre: the tailor has encountered a bully
//Post: he is punched or insulted
void BullyClass::punch(TailorClass & player)
{
  bool away = 0;
  if (rand()%100 <= 40)
  {
    away = player.jumpFence(env);
  }
  if (away=0)
  {
    if (rand() % 100 <= prob_punch)
    {
	  money = money/(punch_power/100);
	  player.health -= INCR;
	  //####RANDOMLY KICK PLAYER
	  player.place_me();
	  ghost.place_pants(env);
    }
    else
    {
	  std::string insult = insults_in_file[rand & insultlist];
	  cout << insult << endl;
    }
  }
  return;
}

//Pre: another 'turn' has begun
//Post: the bully walks within his territory
void BullyClass::patrol(TownClass & env)
{
  //#######env.placeBully(x,y);
  return;
}
//===========================================================================//
