// Programmer: Anna Case                         Date: 3/19/2017
// File: tailor.h                           	 Class: CS1570
// Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: function definitions header

#ifndef TAILOR_H_INCLUDED
#define TAILOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "town.h"

using namespace std;
//Variables
const int DIR = 4;
const int LEFT = 0;
const int RIGHT =1;
const int UP = 2;
const int DOWN = 3;
const int INIT_X = 2;
const int INIT_Y = 3;
class tailor 
{
  private:
    std::string name; 
    char T; //player
    double money;
    bool alive;
	int in_x;
	int in_y;
  public:
    friend class town;
    void constructor (string naming, char P);
	void place_me(int start_x, int start_y, town env);
    void rand_walk(town env);
};

#endif // TAILOR_H_INCLUDED
