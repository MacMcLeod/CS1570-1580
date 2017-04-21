// Programmer: Anna Case                         Date:  4/12/2017
// File: lab12.cpp                                Class: CS1580
//Instructor: Rushiraj
// Student Id: 16181344                          Section: E
// Description: main function, calls functions

#include "student.h"
int main()
{
  int n;
  string S;
  Student s1;
  ofstream out;
  out.open("STUDENT.dat");
  cout << "What is your name?" << endl;
  cin >> S;
  s1.setName(S);
  do
  {
    cout << "What is your grade?" << endl;
    cin >> n;
  } while (n>90 || 0>n);
  s1.setGrade(n);
  s1.increment();
  out << "Student's name: " << s1.getName() << endl;
  out << "Student's incremented grade: " << s1.getGrade() << endl;

  out.close();
  return 0;
}
