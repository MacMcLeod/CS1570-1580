// Programmer: Anna Case                         Date: 3/19/2017
// File: phantompants.cpp	                             Class: CS1570
// Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: bully class

//Pre: 
//Post:
void constructor(town& env)
{
  env.set_location(START,START,P);
}
//Pre:
//Post:
void place_me(town& env)
{
it will give the pants location a random spot in town that is empty and it will place a 'P' in the town in that location.
  rand_x, rand_y;
  env.set_location(rand_x,rand_y,P);
  return;
}
//Pre:
//Post:
void chase(tailor& player)
{
  if (rand&100<=CHASE)
  {
    phantom.place_me();
  }
  return;
}
//Pre: Tailor has been killed by phantom pants
//Post: Tailor's attributes are set to dead 
void kill(tailor& player)
{
  player.alive = 0;
  player.health = 0;
  return;
}
