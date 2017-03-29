// Programmer: Anna Case
// File: lab02.cpp                           Class: CS1580
//Date: 1/25/2017
// Description: Calculate gravitational force between two bodies

#include <iostream>
using namespace std;
int main()
{
  //declarations
  const float GRAV = 6.674;
  float mass1;
  float mass2;
  float distance;
  float force;
  //get variables
  cout << "what is your mass in kg?" << endl;
  cin >> mass1;
  cout << "what is your friend's mass in kg?" << endl;
  cin >> mass2;
  cout << "what is the distance between you in meters?" << endl;
  cin >> distance;
  //calculate and output force
  force = mass1 * mass2 * GRAV / (distance * distance);
  cout << "The exact force is " << force << " newtons." << endl;
  cout << "Which is about " << static_cast<int>(force) << " newtons." << endl;
  return 0;
}
