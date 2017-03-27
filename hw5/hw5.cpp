// Programmer: Anna Case                         Date: 2/22/2017
// File: lab6.cpp                           Class: CS1580
// Instructor : Rushiraj
// Student Id: 16181344                              Section: E
// Description: Stock Investment Lab
#include <iostream>
using namespace std;
int main() {
  //declarations
  bool cont = true;
  void greet();
  string name;
  void signoff(string name);
  int waistMeasurement();
  int waist;
  int legLength();
  int leg;
  float highTolerance();
  float tolerance;
  float inseamCalculation(int waist);
  float inseam;
  void highwater(int leg, float tolerance, float inseam);
  bool acceptableHW;
  float actualTolerance;
  void output (bool highwater);
  //Call functions
  greet ();
  while (cont == true)
  {
    waistMeasurement();
    legLength();
    highTolerance();
    highwater(leg, tolerance, inseam);
    output (highwater);
    cout << "Would you like to (1) enter measurements again or (0) quit" << endl;
    cin >> cont;
  }
  signoff(name);
  return 0;
}

void greet ()
{ //prints greeting
  cout << "Hello! What is your name?" << endl;
  cin >> name;
  cout << "Nice to help you, " << name << endl;
  return;
}
int waistMeasurement ()
{
  cout << "Please enter your waist measurement" << endl;
  cin >> waist;
  while (waist <= 0)
  {
    cout << "The value must be positive." << endl;
    cin >> waist;
  }
  return waist;
}
int legLength ()
{
  cout << "Please enter your leg length" << endl;
  cin >> leg;
  while (leg <= 0)
  {
    cout << "The value must be positive." << endl;
    cin >> leg;
  }
  return leg;
}
float highTolerance ()
{
  cout << "Please enter your high-water tolerance." << endl;
  cin >> tolerance;
  while (tolerance <= 0)
  {
    cout << "The value must be positive." << endl;
    cin >> tolerance;
  }
  return tolerance;
}
float inseamCalculation(int waist)
{
  const short WIRATIO = 0.9;
  inseam = waist * WIRATIO;
  return inseam;
}
void highwater (int leg, float tolerance, float inseam)
{
  actualTolerance = leg - inseam;
  if (actualTolerance >= tolerance)
  {
	acceptableHW = true;
  }
  else
  {
	acceptableHW = false;
  }
}
void output (bool acceptableHW)
{
  if (acceptableHW == true)
  {
    cout << "Great pair of high-waters!" << endl;
  }
  else
  {
    cout << "These pants are NOT high-water enough for you" << endl;
  }
}
void signoff(string name)
{
  cout << "Goodbye " << name << endl;
}
