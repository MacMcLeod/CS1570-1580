// Programmer: Anna Case
// File: definitions.h                         Class: CS1580
//Date: 3/15/2017
// Description: function definitions header
#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
struct student
{
  int id;
  int grade;
};

const int STU_NUM = 7;
int minGrade(student s[]);
int maxGrade(student s[]);
float avgGrade(student s[]);
void print(int grade_min, int grade_max, float grade_avg);

#endif // DEFINITIONS_H_INCLUDED
