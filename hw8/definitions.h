// Programmer: Anna Case                         Date: 3/19/2017
// File: definitions.h                           Class: CS1570
// Section: C
// Description: function definitions header

#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;
//Constants
const int WORDS = 5;
const int MAXINWORD = 20;
//Function Definitions
void parse (char word[],int length);
void runOn (char sentence[]);
void swap (char sentence[]);
void wordSwap (char word[]);
void stammer (char word[]);
#endif // DEFINITIONS_H_INCLUDED
