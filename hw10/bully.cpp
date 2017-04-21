// Programmer: Anna Case                         Date: 3/19/2017
// File: bully.cpp	                             Class: CS1570
// Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: bully class

//Pre: a number of bullies have been declared
//Post: their values are initialized
void constructor()
{
  ifstream in;
  in ("bullies.dat");
  in.open();
  //#####assign their name member variable
  punch_power = rand() % MAXP + MINP;
  prob_punch = PROB;
  in.close();
  return;
}

//Pre: the tailor has encountered a bully
//Post: he is punched or insulted
void punch(tailor& player)
{
  if (rand() % 100 <= prob_punch)
  {
	money = money/(punch_power/100);
	player.health -= INCR;
	//####RaNDOMLY KICK PLAYER
	player.place_me();
  }
  else
  {
	string temp;
	ifstream in;
    in ("message.dat");
    in.open();
	//#####get message
	cout << << endl;
	in.close();
  }
  return;
}