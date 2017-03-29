// Programmer: Anna Case
// File: definitions.cpp                         Class: CS1580
//Date: 3/15/2017
// Description: function definitions

#include "definitions.h"

int minGrade(student s[])
{
  int min = s[0].grade;
  for (int w = 1; w < STU_NUM; w++)
  {
    if (s[w].grade < min)
    {
      min = s[w].grade;
    }
  }
  return min;
}

int maxGrade (student s[])
{
  int max = s[0].grade;
  for (int q = 1; q < STU_NUM; q++)
  {
    if (s[q].grade > max)
    {
      max = s[q].grade;
    }
  }
  return max;
}

float avgGrade (student s[])
{
  float sum = 0;
  for (int k=0; k<STU_NUM; k++)
  {
    sum += s[k].grade;
  }
  return (sum / STU_NUM);
}

void print (int grade_min, int grade_max, float grade_avg)
{
  cout << "The minimum grade is " << grade_min << endl;
  cout << "The maximum grade is " << grade_max << endl;
  cout << "The average grade is " << grade_avg << endl;
  return;
}

