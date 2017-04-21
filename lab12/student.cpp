// Programmer: Anna Case                         Date:  4/12/2017
// File: .cpp                                Class: CS1580
//Instructor: Rushiraj
// Student Id: 16181344                          Section: E
// Description: main function, calls functions
#include "student.h"
//Pre: S is input
//Post: sets name to S
void Student::setName(string S)
{
  name = S;
}
//Pre: n is input
//Post: sets grade to n
void Student::setGrade(int n)
{
  grade = n;
}
//Pre: N/A
//Post: returns name
string Student::getName()
{
  return name;
}
//Pre: N/A
//Post: returns grade
int Student::getGrade()
{
  return grade;
}
//Pre: initial grade
//Post: grade is incremented
void Student::increment()
{
  grade += INCR;
}
