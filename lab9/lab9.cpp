// Programmer: Anna Case
// File: lab9.cpp                                Class: CS1580
//Date: 3/15/2017
// Description: main function, calls functions

#include "definitions.h"
//Defines array and size (-1 for use in for statements)
int main()
{
  //Declarations
  student s[STU_NUM];
  int grade_min;
  int grade_max;
  float grade_avg;
  //User input of students
  for (int i=0; i<STU_NUM; i++)
  {
    cout << "Input the student's ID #" << endl;
    cin >> s[i].id;
    cout << "Input the student's grade" << endl;
    cin >> s[i].grade;
  }
  //Calculations
  grade_min = minGrade(s);
  grade_max = maxGrade(s);
  grade_avg = avgGrade(s);
  //Print results
  print (grade_min, grade_max, grade_avg);
  return 0;
}


