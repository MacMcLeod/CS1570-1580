// Programmer: Anna Case                         Date: 3/22/2017
// File: lab10.cpp                               Class: CS1580
//Section: E
// Description: NTCA encrypter

#include "definitions.h"

int main()
{
  //Declarations
  char name[MAX];
  char enc_name[MAX];
  bool cont = 1;
  do
  {
    getInput(name);
    encrypt(name, enc_name);
    showOutput(name, enc_name);
	//Clear string
    cout << "Would you like to continue? 0/1" << endl;
    cin >> cont;
  } while (cont == 1);
  return 0;
}


