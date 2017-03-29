//Programmer: Anna Case
//File lab5.cpp					Class: CS1580
//Date: 2/19/2017
//Description: Switch Case Casino
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
  //initialize variables
  int choice;
  int pcard;
  int pcard2;
  int card1;
  int card2;
  int number;
  int number2;
  string response;
  //Asks the user what to play
  cout << "Would you like to 1. Play Blackjack 2. Play High or Low or 3. Leave The Casino?" << endl;
  cin >> choice;
  //Seed RNG
  srand(time(NULL));
  while (choice != 3)
  {
    switch (choice)
    {
      //Play Blackjack
      case 1:
        cout << "Pick 2 values between 1-10 as your cards." << endl;
        cin >> pcard >> pcard2;
        card1 = rand() % 10 + 1;
        card2 = rand() % 10 + 1;
        cout << "The dealer's cards are " << card1 << " and " << card2 << endl;
        if ((pcard + pcard2) > (card1 + card2))
        {
          cout << "You win!" << endl;
          cout << "Would you like to 1. Play Blackjack 2. Play High or Low or 3. Leave The Casino?" << endl;
          cin >> choice;
          break;
        }
        else
        {
          cout << "You lost!" << endl;
          cout << "Would you like to 1. Play Blackjack 2. Play High or Low or 3. Leave The Casino?" << endl;
          cin >> choice;
          break;
        }
      //Play High or Low
      case 2:
        number = rand() % 100 + 1;
        number2 = rand() % 100 + 1;
        cout << "The number is " << number << endl;
        cout << "Will the new number be 'higher' or 'lower'?" << endl;
        cin >> response;
        cout << "The second number is " << number2 <<endl;
        if ((response == "higher" && number2>number) || (response == "lower" && number2<number))
        {
          cout << "You win!" << endl;
          cout << "Would you like to 1. Play Blackjack 2. Play High or Low or 3. Leave The Casino?" << endl;
          cin >> choice;
          break;
        }
        else
        {
          cout << "You lost!" << endl;
          cout << "Would you like to 1. Play Blackjack 2. Play High or Low or 3. Leave The Casino?" << endl;
          cin >> choice;
          break;
        }
      //Leave the Casino
      //Unused, while loop ends
      default:
        cout << "Goodbye!" << endl;
        break;
    }
  }
return 0;
}
