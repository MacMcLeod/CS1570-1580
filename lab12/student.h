// Programmer: Anna Case                         Date: 4/5/2017
// File: definitions.h                           Class: CS1580
// Instructor: Rushiraj
// Student Id: 16181344                          Section: E
// Description: function definitions header

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int INCR = 7;
//Student with name and grade
class Student
{
  private:
  int grade;
  string name;

  public:
  string getName();
  void setName(string S);
  int getGrade();
  void setGrade(int n);
  void increment();
};
#endif // STUDENT_H_INCLUDED
