#pragma once
//Libraries:
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

//Constants:
const short TOWNSIZE = 17;
const short MAX = 25;
const short NUMBULLIES = 10;
const short NUMHOUSES = 40;
const short NUMPHANTOMS = 3;

//Direction Denoters
const int DOWN = 0;
const short RIGHT = 1;
const short UP = 2;
const int LEFT = 3;

//Map Generation Constants
const short HOUSESPACING = 2;
const short TURNPROB = 25;
const short GATEPROB = 20;
//must be either 1 or 2, otherwise generator will fail!

//Map Symbols:
const char BULLY = 'B';
const char HOUSE = 'H';
const char WALL = 'W';
const char TREE = 'T';
const char PANTS = 'P';
const char EMPTY = ' ';
const char STRAIGHTFENCE = '.';
const char CORNERFENCE = '+';

//Structures:
struct location
{
  char letter;
  bool thrown=0;
};
struct point
{
  short x, y;
};
