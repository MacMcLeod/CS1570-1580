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
void TownClass::proceduralGenerator()
{
  point p;
  int j=0;
  int tries = 0;
  string word;
  bool success;
  GenerateWalls();
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
          convertToTile(graph[k][j],p);
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
char TownClass::checkGrid(point p)
{
  return grid[p.x][p.y].letter; 
}
//============================================================================//
bool TownClass::replaceSymbol(point p, char symbol)
{
  grid[p.x][p.y].letter=symbol;
  return true;
}
//============================================================================//
void TownClass::GenerateFence()
{
  short dir1=0;
  short dir2=2;
  bool end1=true;
  bool place=false;
  int tries=0;
  point p1;
  //Starts the fence
  while(end1)
  {
    tries++;
    srand(tries+time(NULL));
    p1.x=rand()%(TOWNSIZE-2)+1;
    p1.y=rand()%(TOWNSIZE-2)+1;
    end1=(grid[p1.x][p1.y].letter!=EMPTY);
  }
  //Continues the fence
  dir1=rand()%4;
  dir2=(dir1+2)%4;
  while(!end1)
  {
    tries++;
    cin.get();
    printTown();
    srand(time(NULL)+tries);
    place=false;
    switch(dir1)
    {
      case UP:
        if(grid[p1.x][p1.y-1].letter==WALL
        ||grid[p1.x][p1.y-1].letter==STRAIGHTFENCE
        ||grid[p1.x][p1.y-1].letter==CORNERFENCE)
          end1=true;
        else if(grid[p1.x][p1.y-1].letter==EMPTY)
        {
          p1.y--;
          place=true;  
        }
        else
        {
          dir1=((2*rand()%2)+1+dir1)%4;
        }
        break;
      case DOWN:
        if(grid[p1.x][p1.y+1].letter==WALL||grid[p1.x][p1.y+1].letter==STRAIGHTFENCE)
          end1=true;
        else if(grid[p1.x][p1.y+1].letter==EMPTY)
        {
          p1.y++;
          place=true;
        }
        else
        {
          dir1=((2*rand()%2)+1+dir1)%4;
        }
        break;
      case RIGHT:
        if(grid[p1.x+1][p1.y].letter==WALL||grid[p1.x+1][p1.y].letter==STRAIGHTFENCE)
          end1=true;
        else if(grid[p1.x+1][p1.y].letter==EMPTY)
        {
          p1.x++;
          place=true;
        }
        else
        {
          dir1=((2*rand()%2)+1+dir1)%4;
        }
        break;
      case LEFT:
        if(grid[p1.x-1][p1.y].letter==WALL||grid[p1.x-1][p1.y].letter==STRAIGHTFENCE)
          end1=true;
        else if(grid[p1.x-1][p1.y].letter==EMPTY)
        {
          p1.x--;
          place=true;
        }
        else
        {
          dir1=((2*rand()%2)+1+dir1)%4;
        }
      break;
    }
    if(place&&(rand()%100>=GATEPROB))
      grid[p1.x][p1.y].letter=STRAIGHTFENCE;
    if((rand()%100)<=TURNPROB)
    {
      dir1=((2*rand()%2)+1+dir1)%4;
      grid[p1.x][p1.y].letter=CORNERFENCE;
    }
  }
  return;
}
//============================================================================//
