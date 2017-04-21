// Programmer: Anna Case                         Date: 3/19/2017
// File: bully.h                           	 	 Class: CS1570
// Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: defines bully class

#ifndef BULLY_H_INCLUDED
#define BULLY_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
const int INCR = 10;
const int MAXP = 50;
const int MINP = 30;
const short PROB = 80;
class bully 
{
  private:
    string name;
	short punch_power;
	short prob_punch;
  public:
    void constructor();
	void punch(tailor);
};

#endif //BULLY_H_INCLUDED
