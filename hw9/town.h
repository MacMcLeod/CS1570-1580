// Programmer: Anna Case                         Date: 3/19/2017
// File: town.h                           		 Class: CS1570
// Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: town class

#ifndef TOWN_H_INCLUDED
#define TOWN_H_INCLUDED
#include <iostream>
#include <cstring>

using namespace std;
//Variables
const short MAX = 25;
const short MIN = 4;
const char WALL = 'W';
const char TREE = 'T';
const char EMPTY = ' ';
class town
{
  private:
    int X_size;
    int Y_size;
    char area[MAX][MAX];
  public:
    friend class tailor;
    void constructor (int townsize);
    void clear ();
    void build ();
    void set_location (int in_x, int in_y, char T);
    void setTown (int x_loc, int y_loc, char obj);
    char getTown (int x_loc, int y_loc);
};
#endif // TOWN_H_INCLUDED
