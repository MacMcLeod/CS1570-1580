// Programmer: Anna Case                         Date: 3/19/2017
// File: definitions.cpp                         Class: CS1570
//Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: function definitions

#include "definitions.h"

//Pre: Empty structures
//Post: Randomly generates inventory of 100 pants
void initialize(pants p[])
{
  for (int i=0;i<INVENTORY;i++)
  {
	p[i].waist = rand()%((MAX_WAIST - MIN_WAIST) + 1) + MIN_WAIST; 
	p[i].inseam = rand()%((MAX_INSEAM - MIN_INSEAM) + 1) + MIN_INSEAM; 
	p[i].color = rand()%((NUM_COLORS) - 1); 
	p[i].availability = 1; //Inventory initially full
  }
  return;
}

//Pre: Inventory has been created
//Post: second structure (pants of size) has been populated
void sortInventory(pants p[], pants_of_size s[])
{
  int g;
  for (g=0; g < SIZES; g++)
  {
    for (int h=0; h<NUM_COLORS;h++)
	{
	  s[g].colors_in_size[h] = 0;
	}
  }
  for (int k =0; k <(INVENTORY);k++)
  {
	if (p[k].availability == 1) {
      s[p[k].waist - MIN_WAIST].waist =  p[k].waist; 
      s[p[k].waist - MIN_WAIST].colors_in_size[p[k].color] += 1;
    }
  }
  return;
}

//Pre: Inventory has been created
//Post: Inventory has been printed
void printInventory(pants p[])
{
  for (int i=0;i<SIZES;i++)
  {
	for (int q=0;q<INVENTORY;q++)
	{
	  if (p[q].waist == (i+MIN_WAIST))
	  {
	    cout << "Waist: " << p[q].waist << " Inseam: " << p[q].inseam << " Color: " << colors[p[q].color] << endl;
	  }
    }
  }
  return;
}

//Pre: Program has outputted inventory
//Post: User has entered waist size
void getWaist(int &pref_waist)
{
  cout << "What is your waist measurement?" << endl;
  cin >> pref_waist; 
}

//Pre: User has entered waist size
//Post: Program has outputted available colors
void printColor(int pref_waist, pants_of_size s[])
{
  short temp;
  cout << "Here are the colors of pants with your waist: " << endl;
  for (int i=0;i<NUM_COLORS;i++)
  {
	if (s[pref_waist - MIN_WAIST].colors_in_size[i] != 0)
	{
	  temp = s[pref_waist - MIN_WAIST].colors_in_size[i];
	  cout << temp << " of "<< colors[i] << " are available in your size." << endl;
	} else {
	  cout << colors[i] << " is not available in your size." << endl;
	}
  }
  return;
}

//Pre: Program has outputted list of available colors
//Post: User has entered preferred color
void whichColor (int &pref_color) {
  cout << "Type the number corresponding to the color you would like. If you do not like your choices, enter -1." << endl;
  cout << "0.black, 1.blue, 2.red, 3.rainbow, 4.checkered, 5.electric green, 6.polka dot" << endl;
  cin >> pref_color;
  return;
}

//Pre: user has entered preferred waist and color
//Post: program has outputted available inseams
void printInseam(int pref_waist, int pref_color, pants p[])
{
  cout << "Here are the inseams of the pants with your waist and color: " << endl;
  for (int i=0;i<(INVENTORY);i++)
  {
	if ((p[i].waist == pref_waist)&&(p[i].color == pref_color)&&(p[i].availability==1))
	{
	  cout << "Inseam: " << p[i].inseam <<endl;
	}
  }
  return;
}

//Pre: list of available inseams has been outputted
//Post: user has entered inseam and availability in inventory struct is updated
void whatInseam(int pref_waist, int pref_color, pants p[], int &pref_inseam)
{
  cout << "What inseam would you like to buy?" << endl;
  cin >> pref_inseam;
  for (int i=0;i<(INVENTORY);i++)
  {
	if ((p[i].waist == pref_waist)&&(p[i].color == pref_color)&&(p[i].inseam == pref_inseam))
	{
	  p[i].availability = 0;
	}
  }
  return;
}

//Pre: user has entered inseam value
//Post: program outputs appropriate price
void price (int pref_inseam, int pref_waist) {
  int highwater = 0;
  if (pref_inseam < (0.9 * pref_waist + 2))
  {
    highwater = 40;
  }
  cout << "The price is " << (pref_waist  +  pref_inseam + highwater) << endl;

}

//Pre: while loop (main) is unupdated
//Post: while loop (main) continues if more, ends if not 
void moreCustomers (bool &more_cust)
{
  cout << "Is there another customer? 1 for yes, 0 for no" << endl;
  cin >> more_cust;
  return;
}
