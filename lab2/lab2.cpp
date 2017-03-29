// Programmer: Anna Case
// File: lab02.cpp                               Class: CS1580
//Date: 1/25/2017
// Description: Correcting errors in the .cpp file provided for the second lab.
//including the I/O stream library
#include <iostream>
using namespace std;
int main()
{
  int multiplicand;
  // a within formula c = a * b
  int multiplier;
  // b within formula c = a * b
  int product;
  // c within formula c = a * b
  // display brief welcome message
  cout << "I can do multiply for great good!" << endl;
  // read multiplicand from keyboard
  cout << "Enter the multiplicand: ";
  cin >> multiplicand;
  // read multiplier from keyboard
  cout << "Enter the multiplier: ";
  cin >> multiplier;
  // perform multiplication as * operator
  product = multiplicand * multiplier;
  // display the result
  cout << multiplicand << " * " << multiplier << " = " << product << endl;
  return 0;
}
