// Programmer: Anna Case                         Date: 3/10/2017
// File: calculations.cpp                        Class: CS1570
// Instructor : Mardham
// Student Id: 16181344                          Section: C
// Description: contains functions for all calculations

#include "calculations.h"
int x_input;
float x_sine;
double computed_exponential = 1;
int sin_precision;
double term;
double computed_sine = 0;
float root;
int nth_root;
int comp_fact = 1;
float exp_num;
float exp_root = 1;
float hcos;

void factorial()
{ //Function to find factorial
  do {
    cout << "Enter a value from 0 to 10" << endl;
    cin >> x_input;
  } while ((x_input <0) || (x_input > 10));
  exchange(x_input);
  for (int i = x_input; i>1; i--)
  {
    comp_fact *= i;
  }
  cout << "The factorial is " << comp_fact << endl;
}
void exponential()
{ //Function to find exponential
  do {
    cout << "Enter a number from 0 to 7" << endl;
    cin >> x_input;
  } while ((x_input < 0)  || (x_input > 7));
  exchange(x_input);
  exp(exp_num);
  computed_exponential = exp_num;
  cout << "The answer is "<< computed_exponential << endl;
  return;
}
void sine ()
{ //Function to find sine of x
  do {
    cout << "Enter a number 0 or higher" << endl;
    cin >> x_input;
  } while (0 > x_input);
  exchange(x_input);
  do {
    cout << "Enter a precision value from 1 to 5" << endl;
    cin >> sin_precision;
  } while ((sin_precision < 1) || (sin_precision > 5));
  //computes sine
  computed_sine = x_input;
  term = x_input;
  for(int i = 1; i < sin_precision; i++) {
    term *= -1 * (x_input/(2*i))*(x_input/(2*i+1));
    computed_sine += term;
  }
  cout << "The value is " << computed_sine << endl;
}
void roots()
{ //Function to find roots
  cout << "Enter a value to find the root of" << endl;
  cin >> x_input;
  exchange(x_input);
  do { //Checks for valid input
    cout << "Would you like to find square root (n = 2), cube root (n = 3), fourth root (n = 4), or fifth root (n = 5)" << endl;
    cin >> nth_root;
  } while ((nth_root < 2)  || (nth_root > 5));
  root = x_input;
  for (int i=1; i<=10; i++)
  { //Calculation
    root = (((nth_root - 1) * root) + (x_input/exp_root)) / nth_root;
    exp_root = 1;
    for (int k=1;k<=(nth_root-1);k++)
    {
      exp_root *= root;
    }
  }
  cout << "The root is approximately " << root << endl;
}
void hcosine()
{ //Function to find hyperbolic cosine
  cout << "Enter a value of x" << endl;
  cin >> x_input;
  exp(exp_num);
  hcos = (exp_num+(1/exp_num))/2;
  cout << "The hyperbolic cosine is " << hcos << endl;
  return;
}
void exp (float &exp_num)
{ //Calculates e to the x
  exp_num = 1;
  for (int k = 1; k <= x_input; k++)
  {
    exp_num *= MATH_E;
  }
  return;
}
void exchange (int &x_input)
{ //exchanges x value if necessary
  if ((rand()%100) <= 34)	// 35% of the time
    //FIND RAND X
    x_input = (rand() % 7) + 3;
    cout << "I like the number " << x_input << " better!" << endl;
}
