#include "heading.h"
#include "functions.h"
//#include "creatures.h"
//============================================================================//
//Pre: something needs to move
//Post: a point is moved in a direction (char is not updated)
bool move (short dir, short dist, point & location, TownClass & env)
{
  switch(dir)
  {
    case UP:
      location.y-=dist;
      if(EMPTY==env.checkGrid(location))
        return true;
      else
        location.y+=dist;
        return false;
      break;
    case DOWN:
      location.y+=dist;
      if(EMPTY==env.checkGrid(location))
        return true;
      else
        location.y-=dist;
        return false;
      break;
    case LEFT:
      location.x-=dist;
      if(EMPTY==env.checkGrid(location))
        return true;
      else
        location.x+=dist;
        return false;
      break;
    case RIGHT:
      location.x+=dist;
      if(EMPTY==env.checkGrid(location))
        return true;
      else
        location.x-=dist;
        return false;
      break;
  }
  return false;
}
//============================================================================//
//Pre: someone needs to move
//Post: moves a point & char to a new location
bool place(char symbol,point & coord,point newLocation,TownClass & env)
{
  if(EMPTY==env.checkGrid(newLocation))
  {
    env.replaceSymbol(coord,EMPTY);
    env.replaceSymbol(newLocation,symbol);
    coord=newLocation;
    return true;
  }
  else
    return false;
}
//============================================================================//
//Pre: need to wait
//Post: waited
void wait(int seconds)
{
  int x = 0;
  x=time(NULL);
  while(time(NULL)<seconds+x){}
  return;
}
//============================================================================//
//Pre: Creature tries to walk in all directions (rand first)
//Post: Creature has been successful unless blocked
bool walkingDir (int dir, TownClass& env, point& location)
{
  bool success=false;
  for (int a=0;a<DIR;a++)
  {
  
    if (!success)
      success=move((dir+a)%DIR,DIST,location,env);
  }
  return success;
}