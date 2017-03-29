// Programmer: Anna Case
// File: lab6.cpp                           Class: CS1580
//Date: 2/22/2017
// Description: Stock Investment Lab
#include <iostream>
using namespace std;
const float PI = 3.14159;
float radius;
float area;
int main() {
  //declarations
  void greet();
  float readRadius();
  float findArea(float radius);
  void printResult (float radius, float area);
  void signoff();
  //Call functions
  greet ();
  readRadius();
  findArea(radius);
  printResult(radius,area);
  signoff();
  return 0;
}

void greet ()
{ //prints greeting
  cout << "Welcome to area calculation!" << endl;
  return;
}
float readRadius ()
{ //reads appropriate radius
 cout << "Please enter a positive radius." << endl;
 cin >> radius;
  if (radius <= 0)
  {
    do
    {
      cout << "The value must be positive." << endl;
      cin >> radius;
    } while (radius <= 0);
  }
  return radius;
}

float findArea (float radius)
{ //calculates area
  area = PI * radius * radius;
  return area;
}

void printResult (float radius, float area)
{ //prints results
  cout << "The radius of " << radius << " gives an area of "
  << area << endl;
  return;
}

void signoff()
{ //signsoff
  cout << "Have a good day!" << endl;
  return;
}
