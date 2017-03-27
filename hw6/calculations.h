// Programmer: Anna Case                         Date: 3/10/2017
// File: calculations.h                        Class: CS1570
// Student Id: 16181344                          Section: C
// Description: header file for declarations
#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//TODO: rewrite to avoid use of global variables
extern int x_input; //used in all calculations
//Factorial
void factorial();
extern int comp_fact;
//Exponential
void exponential();
extern double computed_exponential;
const double MATH_E = 2.71828;
void exp (float &exp_num);
extern float exp_num;
//Sine variables
void sine();
extern float x_sine;
extern int sin_precision;
extern double term;
extern double computed_sine;
//Roots
void roots();
extern float root;
extern float exp_root;
extern int nth_root;
//Hyperbolic Cosine
void hcosine();
extern float hcos;
//Exchange X
void exchange(int &x_input);

#endif
