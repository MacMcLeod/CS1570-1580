// Programmer: Anna Case                         Date: 3/19/2017
// File: definitions.h                           Class: CS1570
//Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: function definitions header

#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int INVENTORY = 100;
const int NUM_COLORS = 7;
const int MIN_WAIST = 20;
const int MAX_WAIST = 40;
const int MIN_INSEAM = 14;
const int MAX_INSEAM = 45;
const int SIZES = MAX_WAIST - MIN_WAIST + 1;
const string colors[NUM_COLORS] = {"black", "blue", "red", "rainbow", "checkered", "electric green", "polka dot"};
struct pants //100 pants
{
  int waist;
  int inseam;
  int color;
  bool availability;
};

struct pants_of_size //21 pant sizes
{
  int waist;
  short colors_in_size[NUM_COLORS];
};
//Functions
void initialize (pants p[]);
void sortInventory(pants p[], pants_of_size s[]);
void printInventory (pants p[]);
void getWaist(int &pref_waist);
void whichColor(int &pref_color);
void printColor (int pref_waist, pants_of_size s[]);
void printInseam (int pref_waist, int pref_color, pants p[]);
void whatInseam(int pref_waist, int pref_color, pants p[], int &pref_inseam);
void price(int pref_inseam, int pref_waist);
void moreCustomers(bool &more_cust);
#endif // DEFINITIONS_H_INCLUDED
