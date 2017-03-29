// Programmer: Anna Case
// File: definitions.cpp                                Class: CS1580
//Date: 3/8/2017
// Description: defines all functions

#include "definitions.h"

void greetings()
{ //runs at start
  cout << "Hello world!" << endl;
  return;
}
void getInput(int numbers[], int size)
{ //sets array of numbers
  srand(time(NULL));	// only seed ONE time
  for (int i = 0; i <= size; i++)
  {
    numbers[i] = rand() % 100 + 1;
  }
  return;
}
void sort (int numbers[], int size)
{ // sorts
  std::sort(numbers, numbers+(size+1));
  return;
}
void print (int numbers[], int size)
{ //lists array
  for (int i = 0; i <= size; i++)
  {
    cout << numbers[i] << endl;
  }
  return;
}
void signoff()
{ // runs at end
  cout << "Goodbye!" << endl;
  return;
}
