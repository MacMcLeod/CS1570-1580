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
const int STARTP = 30;
const int MAXM = 40;
const int MINM = 20;

class tailor 
{
  private:
    std::string name; 
    char T; //player
    double money;
    bool alive;
	short health;
	short pants;
	int in_x;
	int in_y;
  public:
    friend class town;
    void constructor (string naming, char P);
	void place_me(town env);
    void rand_walk(town env);
};

#endif // TAILOR_H_INCLUDED
