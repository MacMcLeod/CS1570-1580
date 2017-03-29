// Programmer: Anna Case
// File: lab4.cpp                           Class: CS1580
//Date: 2/8/2017
// Description: Stock Investment Lab
#include <iostream>
using namespace std;
int main()
{
  const float X_MULT = 1.15;
  const float Y_MULT = 0.81;
  const float Z_MULT = 2.5;
  //init value for do
  char again = 'y';
  do
  {
    int choice;
    int investment;
    float gain;
    //gets values
    cout << "Hello, would you like to invest in #1: stock x, #2: stock y, or #3: stock z?" << endl;
    cin >> choice;
    cout << "Lovely! How much would you like to invest?" << endl;
    cin >> investment;
    //determines capital gain
    if (choice == 1) {
      gain = investment * X_MULT;
    } else if (choice == 2) {
      gain = investment * Y_MULT;
    } else {
      gain = investment * Z_MULT;
    }
    //prints capital gain
    cout << "$"<< gain << " is your projected capital value." << endl;
    cout << "Would you like to invest in another stock? y/n" << endl;
    cin >> again;
  } while (again == 'y');
  return 0;
}
