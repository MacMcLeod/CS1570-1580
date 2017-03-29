// Programmer: Anna Case                         Date: 3/8/2017
// File: lab8.cpp                                Class: CS1580
//Instructor: Rushiraj
// Student Id: 16181344                          Section: E
// Description: main function, calls functions

#include "definitions.h"
//Defines array and size (-1 for use in for statements)
int numbers[6];
int size = 6;

int main() 
{
  greetings();
  getInput(numbers, size);
  cout << "The initial array is " << endl;
  print(numbers, size); //prints initial array
  sort(numbers, size);
  cout << "The sorted array is " << endl;
  print(numbers, size); //prints sorted array
  signoff();
  return 0;
}
