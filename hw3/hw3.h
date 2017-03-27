// Programmer: Anna Case                         Date: 2/**/2017 
// File: hw03.cpp                           Class: CS1570 
// Instructor : ***
// Student Id: 16181344                              Section: 
// Description: 
#include <string>
#include <iostream> 
using namespace std;
int main() { 
	string name;
	short cornea;
	char letter1;
	str next_letters, letter4, last_letters;
	short start;
	short x1,x2,x;
	short line_number;
	
    cout << "Hello, what is your name?" << endl;
	cin >> name;
	
	do {
		cout << ”What is the measurement of your right eye cornea in millimeters?“;
		cin >> cornea;

	} while (!(cornea >= 0 or input <= 20 ));
	
	if (cornea < 6) {
		letter1 = "P";
		start = 1;
	else if (cornea < 11) 
		letter1 = "B";
		start = 2;
	else	
		letter1 = "C";
		start = 3;
	}
	//change formulas
	x1 = ( start * 7919 + 104729) mod 101  +  150;
	x2 = (x1  * 7919 + 104729) mod 101  +  150;
	x = average ( x1 , x2 );
	
	cout << name << ", what line did you make your first mistake on?" << endl;
	cin >> line_number;
	if (line_number == 1) {
		letter4 = "N";
	} else if (line_number == 2) {
		letter4 = "Ke";
	} else {
		letter4 = "P";
	}
	
	if (letter1 = "P" || letter1 == "B" && line_number = 1) {
			last_letters = "d";
	} else if (letter1 == "C" && line_number = 1)   {
		last_letters = "ky";
	} else if (next_letters == "iN" && line_number > 2)  {
		last_letters = "h";
	} else {
		last_letters = "ye";
	} 
	
	cout << "Your prescription is: " << letter1 << next_letters << letter4 << last_letters << endl;
return 0; 
}