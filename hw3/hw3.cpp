// Programmer: Anna Case                         Date: 2/10/2017
// File: hw3.cpp                                 Class: CS1570
// Instructor : Mardham
// Student Id: 16181344                          Section: C
// Description: GLASS-O-MATIC tells the user (Milhouse) their glasses prescription
#include <string>
#include <iostream>
using namespace std;
int main()
{

  short cornea;
  short start;
  short x1;
  short x2;
  short x;
  short line_number;
  char letter_one;
  string name;
  string next_letters, letter4, last_letters;

  cout << "Hello, what is your name?" << endl; //Gets name
  cin >> name;

  do //Gets eye measurement
  {
    cout << name << ", what is the measurement of your right eye cornea in millimeters?";
    cin >> cornea;
  } while (!(cornea >= 0 or cornea <= 20 ));
  //Sets first letter
  if (cornea < 6)
  {
    letter_one = 'P';
    start = 1;
  }
  else if (cornea < 11)
  {
    letter_one = 'B';
    start = 2;
  }
  else
  {
    letter_one = 'C';
	start = 3;
  }
  //Finds x
  x1 = ( start * 7919 + 104729) % 101  +  150;
  x2 = (x1  * 7919 + 104729) % 101  +  150;
  x = ( x1 + x2 )/2;
  //Determines next letters
  if (150 <= x && x <= 200)
  {
    next_letters = "iN";
  } else if (200 <= x && x <= 250)
  {
    next_letters = "Li";
  }
  //Gets mistake line number and computes Letter 4, sometimes 5
  cout << name << ", what line did you make your first mistake on?" << endl;
  cin >> line_number;
  if (line_number == 1) {
    letter4 = "N";
  } else if (line_number == 2) {
    letter4 = "Ke";
  } else {
    letter4 = "P";
  }
  //determines last letters
  if (( 'P' == letter_one || letter_one == 'B') && line_number == 1) {
    last_letters = "d";
  }
  else if (letter_one == 'C' && line_number == 1)
  {
    last_letters = "ky";
  }
  else if (next_letters == "iN" && line_number > 2)
  {
    last_letters = "h";
  }
  else
  {
    last_letters = "ye";
  }
  //outputs prescription
  cout << "Your prescription is: " << letter_one << next_letters << letter4 << last_letters << endl;
  return 0;
}
