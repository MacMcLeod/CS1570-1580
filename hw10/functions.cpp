#include "heading.h"
#include "functions.h"
//#include "creatures.h"
//============================================================================//
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
}
//============================================================================//
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
void wait(int seconds)
{
  int x = 0;
  x=time(NULL);
  while(time(NULL)<seconds+x){}
  return;
}
