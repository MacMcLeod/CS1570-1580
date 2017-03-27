// Programmer: Anna Case                         Date: 3/19/2017
// File: hw7.cpp                                 Class: CS1570
//Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: Milhouse's Pants Store

#include "definitions.h"
int main()
{
  srand(time(NULL)); //seeds RNG
  //Declarations
  pants p[INVENTORY];
  pants_of_size s[SIZES];
  int pref_waist;
  int pref_color;
  int pref_inseam;
  bool more_cust;
  //Initializes inventory
  initialize(p);
  sortInventory(p,s);
  printInventory(p);
  do
  { //Gets customer input
    getWaist(pref_waist);
	printColor(pref_waist,s);
	whichColor(pref_color);
	if (pref_color >= 0)
	{
	  printInseam(pref_waist,pref_color,p);
	  whatInseam(pref_waist, pref_color,p,pref_inseam);
	  price(pref_inseam, pref_waist);
	}
	moreCustomers(more_cust);
	sortInventory(p,s);
  } while (more_cust == 1);
  return 0;
}
