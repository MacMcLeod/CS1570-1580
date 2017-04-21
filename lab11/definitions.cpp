// Programmer: Anna Case                         Date:  4/5/2017
// File: definitions.cpp                                Class: CS1580
//Instructor: Rushiraj
// Student Id: 16181344                          Section: E
// Description: main function, calls functions

#include "definitions.h"

bool isLong(char word[])
{
  if (strlen(word) >= 5)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool checkVowels(char word[])
{
  int count = 0;
  int len = strlen(word);
  char vowels[VOWELS] = {'a','e','i','o','u'};
  for (int i=0;i <=len; i++)
  {
    for (int v=0;v<VOWELS;v++)
    {
      if (strchr(word, vowels[v]))
      {
        count++;
      }
    }
  }
  if (count >= 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}
