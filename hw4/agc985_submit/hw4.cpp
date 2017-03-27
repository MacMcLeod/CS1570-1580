// Programmer: Anna Case                         Date: 2/19/2017
// File: hw4.cpp                                Class: CS1570
// Student Id: 16181344                          Section: C
// Description:

#include <iostream>
using namespace std;
int main() {
  int choice;
  //case 1 variables
  int x_exponential;
  double computed_exponential = 1;
  const double MATH_E = 2.71828;
  //case 2 variables
  float x_sine;
  float numerator = 1;
  int sin_precision;
  double term;
  int denominator = 1;
  double computed_sine = 0;
  //case 3 variables
  int third_choice;
  int x_root;
  float square_root;
  float cubed_root;

  cout << "OPTIONS: \n 1. Exponential of X \n 2. Sine of X \n 3. Roots of X \n 4. Quit (and run away)" << endl;
  cin >> choice;
  if ((choice < 1) || (choice > 4)) {
    cout << "Invalid choice! Your options are: /n 1. Exponential of X /n 2. Sine of X /n 3. Roots of X /n 4. Quit (and run away)" << endl;
    cin >> choice;
  } else {
  }
  while (choice != 900) {
  switch (choice) {
    case 1: //Computes Exponential of X
      cout << "Enter a value of x" << endl;
      cin >> x_exponential;
      while ((x_exponential < 0)  || (x_exponential > 7)) {
        cout << "Invalid choice! Enter a number from 0 to 7" << endl;
        cin >> x_exponential;
      }
      for(int k = 1; k <= x_exponential; k++)
        computed_exponential *= MATH_E;
      cout << "The answer is "<< computed_exponential << endl;
      cout << "OPTIONS: \n 1. Exponential of X \n 2. Sine of X \n 3. Roots of X \n 4. Quit (and run away)" << endl;
      cin >> choice;
      break;
    case 2: //Computes Sine of X
      cout << "Enter a value of x" << endl;
      cin >> x_sine;
      if (0 > x_sine) {
        do {
          cout << "Invalid choice! Enter a number 0 or higher" << endl;
          cin >> x_sine;
        } while (0 > x_sine);
      } else {
      }
      cout << "Enter a degree of precision from 1 to 5" << endl;
      cin >> sin_precision;
      if ((sin_precision < 1) || (sin_precision > 5)) {
        do {
          cout << "Invalid precision. Enter a value from 1 to 5" << endl;
          cin >> sin_precision;
        } while ((sin_precision < 1) || (sin_precision > 5));
      } else {
      }
      numerator = x_sine;
      denominator = 1;
      for(int s = 1; s <= sin_precision; s++) {
        //Gets numerator and denominator
        for (int d=1; d<=2*s-1; d++) {
          denominator *= d;
        }
        for (int n=1; n < 2*sin_precision-1; n++) {
          numerator *= x_sine;
        }
        //divides two parts of term
        term = numerator / denominator;
        //If an even term, subtracts the value
        if ((s % 2) == 0) {
          term = 0 - term;
        } else {
        }
        computed_sine += term;
      }
      cout << "The value is " << computed_sine << endl;
      cout << "OPTIONS: \n 1. Exponential of X \n 2. Sine of X \n 3. Roots of X \n 4. Quit (and run away)" << endl;
      cin >> choice;
      break;
    case 3: //Computes Roots of X
      cout << "ROOTS: \n 1. Enter X \n 2. Square Root \n 3. Cubed Root" << endl;
      cin >> third_choice;
      if (third_choice != 1) {
        cout << "Please choose '1' to enter X first." << endl;
        cin >> third_choice;
      } else {
      }
      while (third_choice != 400) {
        //Handles Menu Choices
        switch (third_choice) {
          case 1: //Receives X
            cout << "Enter X" << endl;
            cin >> x_root;
            cout << "Would you like to find 2. Square Root or 3. Cubed Root?" << endl;
            cin >> third_choice;
            break;
          case 2: //Finds Square Root
            square_root = x_root;
            for (int i=1; i<=6; i++) {
              square_root = (square_root + (x_root/square_root)) / 2;
            }
            cout << "The square root is approximately " << square_root << endl;
            third_choice = 400;
            break;
          case 3: //Finds Cubed Root
            cubed_root = x_root;
            for (int i=1; i<=10; i++) {
              cubed_root = ((2 * cubed_root) + (x_root/(cubed_root * cubed_root))) / 3;
            }
            cout << "The cubed root is approximately " << cubed_root << endl;
            third_choice = 400;
            break;
          default:
            cout << "Invalid Choice!" << endl;
            third_choice = 400;
            break;
        }
      }
      cout << "OPTIONS: \n 1. Exponential of X \n 2. Sine of X \n 3. Roots of X \n 4. Quit (and run away)" << endl;
      cin >> choice;
      break;
    default:
      cout << "Goodbye!" << endl;
      choice = 900;
    }
  }
  return 0;

}
