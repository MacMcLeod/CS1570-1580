// Programmer: Anna Case
// File: lab7.cpp                           	 Class: CS1580
//Date: 3/1/2017
// Description:
#include <iostream>
using namespace std;
//declarations
int iplaceholder;
float fplaceholder;
//Swap functions
void swap (int &num1, int &num2, int placeholder);
void swap (float &num1, float &num2, float placeholder);
int main()
{
  //Functions
  void greet();
  void getInput (int &num1, int &num2);
  void getInput (float &num1, float &num2);
  void print (int num1, int num2);
  void print (float num1, float num2);
  void signoff();
  //Input
  int int1;
  int int2;
  float float1;
  float float2;
  greet();
  //Gets Integer
  getInput(int1, int2);
  cout << "Before swapping, " << endl;
  //Initial Value
  print(int1, int2);
  cout << "After swapping, " << endl;
  swap(int1, int2);
  //Final Value
  print(int1, int2);
  //Asks for floats
  getInput(float1, float2);
  cout << "Before swapping, " << endl;
  //Initial Value
  print(float1, float2);
  swap(float1, float2);
  cout << "After swapping, " << endl;
  //Final Value
  print(float1, float2);
  signoff ();
  return 0;
}

void greet()
{
  cout << "Hello!" << endl;
}
//Gets two values
void getInput (int &int1, int &int2)
{
  cout << "Enter two integers/floats" << endl;
  cin >> int1 >> int2;
}
void getInput (float &float1, float &float2)
{
  cout << "Enter two integers/floats" << endl;
  cin >> float1 >> float2;
}
void swap (int &int1, int &int2)
{
  int1 = iplaceholder;
  int1 = int2;
  int2 = iplaceholder;
}
void swap (float &float1, float &float2)
{
  float1 = fplaceholder;
  float1 = float2;
  float2 = fplaceholder;
}
//Prints the values
void print (int int1, int int2)
{
  cout << int1 << " and " << int2 << endl;
}
void print (float float1, float float2)
{
  cout << float1 << " and " << float2 << endl;
}
void signoff ()
{
  cout << "Goodbye! " << endl;
}


