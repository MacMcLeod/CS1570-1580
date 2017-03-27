// Programmer: Anna Case                         Date: 2/3/2017
// File: hw2.cpp                                 Class: CS1570
// Instructor : Mardham
// Student Id: 16181344                          Section: C
// Description: Milhouse's Allergy Pill Calculator
#include <iostream>
using namespace std;
int main()
{
  short classes;
  float milk;
  short gaming_hours;
  bool tattoo;
  float poison;
  int pills;
  //Asks for user input
  cout << "Hi Millhouse! How many classes did you have yesterday?" << endl;
  cin >> classes;
  cout << "Rough! How many cups of soymilk did you drink?" << endl;
  cin >> milk;
  cout << "And how many hours did you spend video gaming?" << endl;
  cin >> gaming_hours;
  cout << "And did you apply a fake tattoo? 1 for yes, 0 for no" << endl;
  cin >> tattoo;
  //Function determines whether a tattoo poisoning value should be added
  if (tattoo == true)
  {
    poison = 3.5;
  } else {
    poison = 0;
  }
  //determines amount of pills to take
  pills =(classes/static_cast<float>(gaming_hours)) + (milk * 1.9) + poison;
  //Outputs pills to take
  cout << "You should take " << pills << " pills. Bye!" << endl;
  return 0;
}
