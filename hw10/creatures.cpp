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
//Pre: player called to see out
//Post: player attributes given
ostream& operator<<(ostream& stream, TailorClass player)
{
  stream <<player.name<<"'s Stats:"
         <<" Health: "<<player.health
         <<" Money: "<<player.money
         <<" Inventory: "<<player.pants
         <<" Location: "<<player.coord.x<<","<<player.coord.y;
  return stream;
}

//Pre: Game started
//Post: A pair of phantom pants are placed out of range
void TailorClass::randWalk (TownClass& env)  
{
  bool success=false;
  env.replaceSymbol(coord, EMPTY);
   while(!success)
  {
    int toDir = rand()%DIR;
    switch(toDir)
    {
    case LEFT:
      success=walkingDir(toDir,env,coord);
      break;
    case RIGHT:
      success=walkingDir(toDir,env,coord);
      break;
    case UP:
      success=walkingDir(toDir,env,coord);
      break;
    case DOWN:
      success=walkingDir(toDir,env,coord);
      break;
    }
    if (!success)
    {
      success = true;
      cout << "Player cannot move" << endl;
    }
  }
  env.replaceSymbol(coord,P);  //places tailor
  return;
}

//Pre: tailor needs to move (inital or punch)
//Post: tailor placed in empty place
void TailorClass::moved (TownClass & env)
{
  do
  {
    newLoc.x = (rand()%TOWNSIZE);
    newLoc.y = (rand()%TOWNSIZE);
  } while (!place(P,coord,newLoc,env));
}

//Pre: a fence and a bully are next to the player
//Post: Milhouse will (maybe) jump the fence if it is clear
bool TailorClass::jumpFence (TownClass& env)
{
  const short JUMPCHANCE = 40;
  bool success = false;
  env.replaceSymbol(coord,EMPTY);
  for (int f=0;f<DIR;f++)
  {
    if (checkDir(f,env)==FENCE && rand()%100>=JUMPCHANCE)
    {
      success=move(f,DIST+1,coord,env);
      if (success) //else is something on the otherside of the fence
        env.replaceSymbol(coord,P);
    }
  }
  return success;
}

//Pre: Player has moved
//Post: Acts accordingly. House becomes a home if sold
void TailorClass::turn (TownClass& env)
{
  const int SALE = 10;
  const int SALECHANCE = 70;
  const int SOLD = 1;
  for (int i=0;i<DIR;i++)
  {
    char inDir = checkDir(i,env);
    if (inDir==HOUSE)
    {
      object.x = coord.x;
      object.y = coord.y;
      switch(i)
      {
        case UP:
          object.y++;
        case DOWN:
          object.y--;
        case LEFT:
          object.x--;
        case RIGHT:
          object.x++;
      }
      if (!env.grid[object.x][object.y].thrown&&rand()%100<=SALECHANCE&&pants>0)
      {
        money += SALE;
        pants -= SOLD;
        env.grid[object.x][object.y].thrown=true;
        env.grid[object.x][object.y].letter=HOME;
      }
    }
  }
  env.grid[coord.x][coord.y].letter=P;
  return;
}

//Pre: Player has moved
//Post: Player returns character in a direction
char TailorClass::checkDir(int dir, TownClass env)
{
  object.x = coord.x;
  object.y = coord.y;
  switch(dir)
    {
    case DOWN:
      object.y--;
      break;
  case RIGHT:
      object.x++;
    break;
  case UP:
      object.y++;
      break;
    case LEFT:
      object.x--;
      break;
    }
  return env.checkGrid(object);
}

//Pre: another turn in game
//Post: returns alive status
bool TailorClass::isAlive()
{
  if (alive)
    return true;
  else
    return false;
}

//Pre: another turn in game
//Post: returns inventory status
bool TailorClass::hasInventory()
{
  if (pants>0)
    return true;
  else
    return false;
}
//============================================================================//
//Pre: A pair of pants have been dropped
//Post: A phantom seeks Milhouse
void PhantomClass::place_pants(TownClass & env, TailorClass & player)
{
  coord.x = player.coord.x;
  coord.y = player.coord.y;
  env.replaceSymbol(coord,PANTS);
  player.moved(env);
  existing = true;
  player.pants--;
  return;
}

//Pre: used for moving phantoms
//Post: returns if the phantom pants have been created
bool PhantomClass::exists()
{
  if (existing)
    return true;
  else
    return false;
}
////////////////////////////////////////////////////////////////////////////////
void PhantomClass::chase(TailorClass& player, TownClass& env)
{
  bool killedThisRound=false;
  //Kills if player walks next to pants
  if((coord.x+DIST==player.coord.x && coord.y == player.coord.y)||
     (coord.x-DIST==player.coord.x && coord.y == player.coord.y)||
     (coord.y+DIST==player.coord.y && coord.x == player.coord.x)||
     (coord.y-DIST==player.coord.y && coord.x == player.coord.x))
  {
    kill(player);
    killedThisRound=true;
  }
  //Pants attempt to move toward the player
  else if (rand()%100<=PROBCHASE)
  {
    bool success = 0;
    int deltaX;
    int deltaY;
    env.replaceSymbol(coord, EMPTY);
    deltaX=coord.x-player.coord.x;//The x direction dist to the player
    deltaY=coord.y-player.coord.y;//The y direction dist to the player
    int toDir;//some direction
      
    //Pants attempt to move closer to the player along the longer distance
    if(abs(deltaX)>=abs(deltaY))
    {
      toDir=RIGHT;
      if(deltaX>0)
        toDir=LEFT;
    }
    else
    {
      toDir=DOWN;
      if(deltaY>0)
        toDir=UP;
    }
    switch(toDir)
    {
     case LEFT:
      success=move(toDir,DIST,coord,env);
      break;
     case RIGHT:
      success=move(toDir,DIST,coord,env);
      break;
     case UP:
      success=move(toDir,DIST,coord,env);
      break;
     case DOWN:
      success=move(toDir,DIST,coord,env);
      break;
    }    
    //If the pants didn't move before, pants attempt to move now along
    //the shorter distance
    if (!success)
    {
      if(abs(deltaX)<=abs(deltaY))
      {
        toDir=RIGHT;
        if(deltaX>0)
          toDir=LEFT;
      }
      else
      {
        toDir=DOWN;
        if(deltaY>0)
         toDir=UP;
      }
      switch(toDir)
      {
       case LEFT:
        success=move(toDir,DIST,coord,env);
        break;
       case RIGHT:
        success=move(toDir,DIST,coord,env);
        break;
       case UP:
        success=move(toDir,DIST,coord,env);
        break;
       case DOWN:
        success=move(toDir,DIST,coord,env);
        break;
      }
    }
  }
  env.replaceSymbol(coord,PANTS);
  if(((coord.x+DIST==player.coord.x && coord.y == player.coord.y)||
      (coord.x-DIST==player.coord.x && coord.y == player.coord.y)||
      (coord.y+DIST==player.coord.y && coord.x == player.coord.x)||
      (coord.y-DIST==player.coord.y && coord.x == player.coord.x))&&
      (!killedThisRound))
    kill(player);
  return;
}

//Pre: Tailor has been killed by phantom pants
//Post: Tailor's attributes are set to dead 
void PhantomClass::kill(TailorClass & player)
{
  player.alive = false;
  player.health=0;
  cout<<"Phantom Pants killed "<<player.name<<"!\n";
  return;
}

//===========================================================================//
//Constructor
BullyClass::BullyClass()
{
  //Gets from file
  srand(time(NULL));
  ifstream in;
  in.open("bullies.dat");
  while(getline(in, names))
    names_in_file.push_back(names);
  namelist = names_in_file.size();
  in.close();
  in.clear();
  in.open("message.dat");
  while(getline(in, insults))
    insults_in_file.push_back(insults);
  insultlist = insults_in_file.size();
  in.close();
  //attributes
  coord.x = -1;
  coord.y = -1;
  punch_power = rand()%(MAXP-MINP) + MINP;
  Bname = names_in_file[rand()%namelist];
}

//Pre: a number of bullies have been declared
//Post: their values are initialized
void BullyClass::placement(TownClass& env)
{
  do
  {
    newLoc.x = rand()%TOWNSIZE;
    newLoc.y = rand()%TOWNSIZE;
  } while (!place(BULLY,coord,newLoc,env));
  return;
}

//Pre: the tailor has encountered a bully
//Post: he is punched or insulted
void BullyClass::punch(TailorClass& player, TownClass& env, PhantomClass ghosts[])
{
  static short punchesThrown = 0;
  bool away = false;
  if (rand()%100<=40)
  {
    away = player.jumpFence(env);
  }
  if(away)
  cout<<player.name<<" escaped the bully!\n";
  if (away==false && rand()%100 <= PROB)
  {
    player.money *= (1-punch_power/100.0);
    player.health -= INCR;
    if (player.health==0)
    {
      player.alive = false;
      cout<<"A bully killed "<<player.name<<"!!\n";
    }
    else
    {
      cout<<"A bully punched "<<player.name<<"!\n";
    }
    if(punchesThrown<NUMPHANTOMS)
      ghosts[punchesThrown].place_pants(env,player);
    punchesThrown++;
  }
  else
  {
    string insult = insults_in_file[rand()%insultlist];
    cout << insult << endl;
  }
  return;
}

//Pre: another 'turn' has begun
//Post: the bully walks within his territory, may catch player
void BullyClass::patrol (TailorClass& player, TownClass& env, int& punchCount, PhantomClass ghosts[])
{
  if (((coord.x+DIST==player.coord.x && coord.y == player.coord.y)||
      (coord.x-DIST==player.coord.x && coord.y == player.coord.y)||
      (coord.y+DIST==player.coord.y && coord.x == player.coord.x)||
      (coord.y-DIST==player.coord.y && coord.x == player.coord.x))&&
      (punchCount==0))
  {
    punch(player,env,ghosts);
    punchCount++;
  }
  bool success=false;
  env.replaceSymbol(coord, EMPTY);
  while(!success)
  {
    int toDir = rand()%DIR;
    switch(toDir)
    {
    case LEFT:
      success=walkingDir(toDir,env,coord);
      break;
    case RIGHT:
      success=walkingDir(toDir,env,coord);
      break;
    case UP:
      success=walkingDir(toDir,env,coord);
      break;
    case DOWN:
      success=walkingDir(toDir,env,coord);
      break;
    }
    if (!success)
    {
      success = true;
    }
  }
  env.replaceSymbol(coord,BULLY);
  if(((coord.x+DIST==player.coord.x && coord.y == player.coord.y)||
      (coord.x-DIST==player.coord.x && coord.y == player.coord.y)||
      (coord.y+DIST==player.coord.y && coord.x == player.coord.x)||
      (coord.y-DIST==player.coord.y && coord.x == player.coord.x))&&
      (punchCount==0))
  {
    punch(player,env,ghosts);
    punchCount++;
  }
  return;
}
//===========================================================================//
