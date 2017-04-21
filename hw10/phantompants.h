// Programmer: Anna Case                         Date: 3/19/2017
// File: phantompants.h                           	 	 Class: CS1570
// Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: defines bully class

#ifndef PHANTOMPANTS_H_INCLUDED
#define PHANTOMPANTS_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
const char PANTS = 'P';
const int START = -1;
const int CHASE = 25;
class ppants 
{
  private:
 
  public:
    void constructor(town& env);
	void place_me(town& env);
	void chase(tailor& player);
	void kill(tailor& player);
};

#endif //PHANTOMPANTS_H_INCLUDED
