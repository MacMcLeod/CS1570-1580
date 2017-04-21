// Programmer: Anna Case                         Date:  4/5/2017
// File: main.cpp                                Class: CS1580
//Instructor: Rushiraj
// Student Id: 16181344                          Section: E
// Description: main function, calls functions

#include "definitions.h"
int main()
{
  char word[10];
  int incount = 0;
  int outcount = 0;
  ofstream outfile;
  outfile.open("Output.dat");
  ifstream infile;
  infile.open("Input.dat");
  //handles errors
  if (!infile.is_open())
  {
    cout << "Input file not opened." << endl;
  }
  if (!outfile.is_open())//Create Output
  {
    cout << "Output file not opened." << endl;
  }
  //Gets word
  while (infile >> word)
  {
    incount++;
    //Runs Conditions Functions
    bool length = isLong(word);
    bool vowel = checkVowels(word);
    //Makes output
    if (length && vowel) //If bool functions true
    {
      outfile << word << endl;
      outcount++;
    }
  }
  //Prints summary
  outfile << "Summary : " << endl << "Input words: " << incount << endl;
  outfile << "Output words: " << outcount << endl;
  infile.close();
  outfile.close();
  return 0;
}
