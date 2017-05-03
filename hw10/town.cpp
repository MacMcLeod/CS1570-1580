/*
Programmers: Anna Case | Ben Politte
Student Ids: 16181344  | 12533493
Date: 3/19/2017
Class: CS1570 D
Instructor: Dileep Mardham
Purpose: Functions for creating and refreshing the town objects
*/
//#include "heading.h"
#include "town.h"
#include "creatures.h"
#include "functions.h"
//============================================================================//
//Pre: town created
//Post: houses & fences generated
void TownClass::proceduralGenerator()
{
  point p;
  int tries = 0;
  string word;
  bool success;
  GenerateWalls();
//  GenerateFence();
  for(int i=0; i<NUMHOUSES;i=i)//Places number of houses equal to NUMHOUSES
  {
    tries++;
    srand(tries+time(NULL));
    p.x=rand()%(TOWNSIZE-2)+1;
    p.y=rand()%(TOWNSIZE-2)+1;
    success=GenerateHouse(p);
    if(success)
      i++;
    if(true&&success&&i<NUMHOUSES)
    {
      success=false;
      switch (rand()%4)
      {
        case 0:
        p.x+=HOUSESPACING;
        success=GenerateHouse(p);
	p.x-=HOUSESPACING;
	if(!success)
	{
	  p.y+=HOUSESPACING;
	  success=GenerateHouse(p);
	  p.y-=HOUSESPACING;
	  if(!success)
	  {
	    p.x-=HOUSESPACING;
	    success=GenerateHouse(p);
            p.x+=HOUSESPACING;
            if(!success)
            {
              p.y-=HOUSESPACING;
	      success=GenerateHouse(p);
	      p.y+=HOUSESPACING;
	    }
	  }
	}
       break;
	case 1:
	p.y+=HOUSESPACING;
	success=GenerateHouse(p);
	p.y-=HOUSESPACING;
	if(!success)
	{
	  p.x-=HOUSESPACING;
	  success=GenerateHouse(p);
	  p.x+=HOUSESPACING;
	  if(!success)
	  {
	    p.y-=HOUSESPACING;
            success=GenerateHouse(p);
            p.y+=HOUSESPACING;
            if(!success)
            {
              p.x+=HOUSESPACING;
              success=GenerateHouse(p);
	      p.x-=HOUSESPACING;
	    }
	  }
	}
       break;
	case 2:
	p.x-=HOUSESPACING;
	success=GenerateHouse(p);
	p.x+=HOUSESPACING;
	if(!success)
	{
	  p.y-=HOUSESPACING;
	  success=GenerateHouse(p);
	  p.y+=HOUSESPACING;
	  if(!success)
	  {
	    p.x+=HOUSESPACING;
	    success=GenerateHouse(p);
	    p.x-=HOUSESPACING;
	    if(!success)
	    {
              p.y+=HOUSESPACING;
              success=GenerateHouse(p);
	      p.y-=HOUSESPACING;
	    }
	  }
	}
	break;
	case 3:
	p.y-=HOUSESPACING;
	success=GenerateHouse(p);
	p.y+=HOUSESPACING;
	if(!success)
	{
	  p.x+=HOUSESPACING;
	  success=GenerateHouse(p);
	  p.x-=HOUSESPACING;
	  if(!success)
	  {
	    p.y+=HOUSESPACING;
            success=GenerateHouse(p);
	    p.y-=HOUSESPACING;
	    if(!success)
	    {
	      p.x-=HOUSESPACING;
	      success=GenerateHouse(p);
	      p.x+=HOUSESPACING;
	    }
	  }
	}
      }
      if(success)
      i++;
    }
  }
  GenerateFence();
  return;
}
//============================================================================//
//Pre: Walls placed
//Post: Houses generated
bool TownClass::GenerateHouse(point p)
{
  if((grid[p.x][p.y].letter==' ')&&
    ((grid[p.x+1][p.y].letter!=HOUSE
    &&grid[p.x-1][p.y].letter!=HOUSE
    &&grid[p.x][p.y+1].letter!=HOUSE
    &&grid[p.x][p.y-1].letter!=HOUSE
    &&grid[p.x+1][p.y+1].letter!=HOUSE
    &&grid[p.x-1][p.y+1].letter!=HOUSE
    &&grid[p.x+1][p.y-1].letter!=HOUSE
    &&grid[p.x-1][p.y-1].letter!=HOUSE
    &&HOUSESPACING==2)||(HOUSESPACING==1)))
  {
	grid[p.x][p.y].letter=HOUSE;
	return true;
  }
  else
    return false;
}
//============================================================================//
//Pre: town grid created
//Post: walls placed
void TownClass::GenerateWalls()
{
  for(int j=0; j<TOWNSIZE-1; j++)
  {
    for(int i=1; i<TOWNSIZE-1; i++)
    grid[j][i].letter=EMPTY;
    grid[j][0].letter=WALL;
    grid[0][j].letter=WALL;
    grid[j][TOWNSIZE-1].letter=WALL;
    grid[TOWNSIZE-1][j].letter=WALL;
  }
  grid[TOWNSIZE-1][TOWNSIZE-1].letter=WALL;
  return;
}
//============================================================================//
//Pre: turn complete
//Post: outputs changes on screen
ostream& operator<<(ostream& out, TownClass & town)
{
  for(int j=0; j<TOWNSIZE; j++)
  {
        for(int k=0; k<TOWNSIZE; k++)
        {
          out<<town.grid[k][j].letter<<EMPTY;
        }
        out<<endl;
  }
  return out;
}
void TownClass::printTown()
{
  for(int j=0; j<TOWNSIZE; j++)
  {
	for(int k=0; k<TOWNSIZE; k++)
	{
	  cout<<grid[k][j].letter<<EMPTY;
	}
	cout<<endl;
  }
  return;
}
//============================================================================//
/*void TownClass::graphicalPrintTown()
{
  point p;
  tile graph[MAX][MAX];
  //This set of loops translates the contents of grid[][] array to tiles and
  //fills the graph[][] array.
  for(int p.y=0; p.y<TOWNSIZE; p.y++)
  {
        for(int p.k=0; p.x<TOWNSIZE; p.x++)
        {
          convertToTile(graph[k][j],grid[p.x][p.y].letter);
        }
        cout<<endl;
  }
  //This set then prints the contents of graph[][] line by line.
  for(int j=0; j<TOWNSIZE; j++)
  {
    for(int b=0; b<TILEY; b++)
    {
      for(int k=0; k<TOWNSIZE; k++)
      {
        for(int a=0; a<TILEX; a++)
        {
          cout<<graph[k][j].block[a][b];
        }
      }
      cout<<endl;
    }
  }   
  return;
}*/
//============================================================================//
//Pre: need a char value on grid
//Post: value is returned
char TownClass::checkGrid(point p)
{
  return grid[p.x][p.y].letter; 
}
//============================================================================//
//Pre: need to update grid
//Post: one char is changed
bool TownClass::replaceSymbol(point p, char symbol)
{
  grid[p.x][p.y].letter=symbol;
  return true;
}
//============================================================================//
//Pre: Houses have been placed
//Post: Fence generates
void TownClass::GenerateFence()
{
  const short TURNREQ=-2;
  short canTurn1 = 1;
  short canTurn2 = 1;
  int tries = 0;
  short dir1,dir2;
  point p1,p2;
  bool end1=true;
  bool end2=false;
  while(end1)
  {
    tries++;
    srand(time(NULL)+tries);
    p1.x=rand()%(TOWNSIZE-4)+2;
    p1.y=rand()%(TOWNSIZE-4)+2;
    end1=(grid[p1.x][p1.y].letter!=EMPTY);
  }
  grid[p1.x][p1.y].letter=FENCE;
  p2.x=p1.x;
  p2.y=p1.y;
  dir1=rand()%4;
  dir2=(dir1+2)%4;
  end1=checkFenceAdj(dir1, p1);
  end2=checkFenceAdj(dir2, p2);
  while(end1==false||end2==false)
  {
    tries++;
    srand(time(NULL)+tries);
    if(!moveTarget(dir1,p1)&&!end1)
    {
      dir1=(2*(rand()%2)+1+dir1)%4;
      if(canTurn1<1)
        end1=true;
      else if(!moveTarget(dir1,p1))
      {
        dir1=(dir1+2)%4;
        moveTarget(dir1,p1);
      }
      canTurn1=TURNREQ;
    }
    if(!moveTarget(dir2,p2)&&!end2)
    {
      dir2=(2*(rand()%2)+1+dir2)%4;
      if(canTurn2<1)
        end2=true;
      else if(!moveTarget(dir2,p2))
      {
        dir2=(dir2+2)%4;
        moveTarget(dir2,p2);
      }
      canTurn2=TURNREQ;
    }
    if(!end1)
    {
      if(canTurn1>TURNREQ&&rand()%100<PROBGATE)
        grid[p1.x][p1.y].letter=GATE;
      else
        grid[p1.x][p1.y].letter=FENCE;
      end1=checkFenceAdj(dir1, p1);
      canTurn1++;
    }
    if(!end2)
    {
      if(rand()%100<PROBGATE)
        grid[p2.x][p2.y].letter=GATE;
      else
        grid[p2.x][p2.y].letter=FENCE;
      end2=checkFenceAdj(dir2, p2);
      canTurn2++;
    }
    if(rand()%100<PROBTURN&&canTurn1>0)
    {
      dir1=(2*(rand()%2)+1+dir1)%4;
      grid[p1.x][p1.y].letter=CORNER;
      canTurn1=TURNREQ;
    }

    if(rand()%100<PROBTURN&&canTurn2>0)
    {
      dir2=(2*(rand()%2)+1+dir2)%4;
      grid[p2.x][p2.y].letter=CORNER;
      canTurn2=TURNREQ;
    }   
  }
  grid[p1.x][p1.y].letter=FENCE;
  grid[p2.x][p2.y].letter=FENCE;
  return;
}
//============================================================================//
//Pre: Fence being placed
//Post: Checks nearby for fence
bool TownClass::checkFenceAdj(short dir,const point p)
{
  switch(dir)
  {
    case LEFT:
    if((grid[p.x-1][p.y].letter==WALL||grid[p.x-1][p.y].letter==FENCE
    ||grid[p.x][p.y+1].letter==WALL||grid[p.x][p.y+1].letter==FENCE
    ||grid[p.x][p.y-1].letter==WALL||grid[p.x][p.y-1].letter==FENCE)
    ||(grid[p.x-1][p.y].letter!=EMPTY&&grid[p.x][p.y+1].letter!=EMPTY
       &&grid[p.x][p.y-1].letter!=EMPTY))
      return true;
    else
      return false;
    break;
    case RIGHT:
    if((grid[p.x+1][p.y].letter==WALL||grid[p.x+1][p.y].letter==FENCE
    ||grid[p.x][p.y+1].letter==WALL||grid[p.x][p.y+1].letter==FENCE
    ||grid[p.x][p.y-1].letter==WALL||grid[p.x][p.y-1].letter==FENCE)
    ||(grid[p.x+1][p.y].letter!=EMPTY&&grid[p.x][p.y+1].letter!=EMPTY
       &&grid[p.x][p.y-1].letter!=EMPTY))
      return true;
    else
      return false;
    break;
    case UP:
    if((grid[p.x-1][p.y].letter==WALL||grid[p.x-1][p.y].letter==FENCE
    ||grid[p.x+1][p.y].letter==WALL||grid[p.x+1][p.y].letter==FENCE
    ||grid[p.x][p.y-1].letter==WALL||grid[p.x][p.y-1].letter==FENCE)
    ||(grid[p.x-1][p.y].letter!=EMPTY&&grid[p.x+1][p.y].letter!=EMPTY
       &&grid[p.x][p.y-1].letter!=EMPTY))
      return true;
    else
      return false;
    break;
    case DOWN:
    if((grid[p.x-1][p.y].letter==WALL||grid[p.x-1][p.y].letter==FENCE
    ||grid[p.x+1][p.y].letter==WALL||grid[p.x+1][p.y].letter==FENCE
    ||grid[p.x][p.y+1].letter==WALL||grid[p.x][p.y+1].letter==FENCE)
    ||(grid[p.x-1][p.y].letter!=EMPTY&&grid[p.x+1][p.y].letter!=EMPTY
       &&grid[p.x][p.y+1].letter!=EMPTY))
      return true;
    else
      return false;
    break;
  }
  return false;
}
//
//Pre: Town being generated
//Post: Used in town generation
bool TownClass::moveTarget(short dir, point & p)
{
  switch(dir)
  {
    case UP:
    if(grid[p.x][p.y-1].letter==EMPTY)
      p.y--;
    else
      return false;
    break;
    case DOWN:
    if(grid[p.x][p.y+1].letter==EMPTY)
      p.y++;
    else
      return false;
    break;
    case RIGHT:
    if(grid[p.x+1][p.y].letter==EMPTY)
      p.x++;
    else
      return false;
    break;
    case LEFT:
    if(grid[p.x-1][p.y].letter==EMPTY)
      p.x--;
    else
      return false;
    break;
  }
  return true;
}
