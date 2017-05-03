#pragma once
//Libraries:
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

//General Constants:
const short TOWNSIZE = 17;
const short MAX = 25;
const short NUMBULLIES = 10;
const int BARR = 4;
const short NUMHOUSES = 40;
const short NUMPHANTOMS = 3;
//Direction Denoters
const short DOWN = 0;
const short RIGHT = 1;
const short UP = 2;
const short LEFT = 3;
const int DIR = 4;
const short DIST = 1;
//Map Generation Constants
const short HOUSESPACING = 2;
const short PROBTURN = 40; //About 50% to 30% seems to work good
const short PROBGATE = 25; //Percentage od straight fence sections
                           //that are left unplaced to form gateways
//must be either 1 or 2, otherwise generator will fail!

//Map Symbols:
const char BULLY = 'B';
const char HOUSE = 'h';
const char HOME = 'H';
const char WALL = 'W';
const char TREE = 'T';
const char PANTS = 'P';
const char EMPTY = ' ';
const char FENCE = 'o';
const char GATE = EMPTY;
const char CORNER = FENCE;
//Structures:
struct location
{
  char letter;
  bool thrown;
};
struct point
{
  short x, y;
};
