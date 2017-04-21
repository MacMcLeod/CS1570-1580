// Programmer: Anna Case                         Date: 3/22/2017
// File: definitions.cpp                         Class: CS1580
//Section: E
// Description: function definitions

#include "definitions.h"
//Pre-Condition: asks for name
//Post-Condition: returns name
void getInput(char name[])
{
  cout << "Please input your name." << endl;
  cin.getline(name, MAX); //get full name (Spaces)
  return;
}
//Pre-Condition: takes user name
//Post-Condition: encrypts user name
void encrypt(char name[], char enc_name[])
{
  int length = strlen(name);
  for (int i=0; i<=length;i++)
  {
	if (isalpha(name[i]))
	{
	  enc_name[i] = name[i] + 3; 
	}
  }
  return;
}
//Pre-Condition: both arrays are set
//Post-Condition: both arrays are shown
void showOutput(char name[], char enc_name[])
{
  cout << "Your name is: " << name << endl;
  cout << "Your cryptic message is: " << enc_name << endl; 
}
