/*
Programmers: Anna Case | Ben Politte
Student Ids: 16181344  | 12533493
Date: 5/3/2017
Class: CS1570 C
Instructor: Dileep Mardham
Description: moving creatures definitions header
*/

#pragma once
#include "heading.h"
#include "town.h"
const int DIR = 4;
const short DIST = 1;
//Tailor
const int STARTPANTS = 30;
const int STARTHEALTH = 100;
const int MAXM = 40;
const int MINM = 20;
const int HP = 100;
//Pants
const int START = -1;
const int CHASE = 25;
//Bullies
const int INCR = 10;
const int MAXP = 50;
const int MINP = 30;
const short PROB = 80;
//Player attributes
int step = 0;
string naming = "Milhouse";
char P = 'M';

class TailorClass
{
  private:
    string name; 
    char symbol;
    int money;
    bool alive;
    short health;
    short pants;
	int dir;
    point coord;
  public:
    friend class TownClass;
    TailorClass(char letter)
    {
      symbol = letter;
      name = naming;
      alive = true;
      health = HP;
      pants = STARTPANTS;
      money = rand()%MAXM+MINM;
    }
	void randWalk(TownClass& env);
    char checkDir(int dir);
	void turn();
    bool jumpFence(TownClass& env);
};
//============================================================================//
class PhantomClass
{
  private:
    point coord;
  public: 
    void phantom_con(TownClass& env);
    void place_pants(TownClass& env);
    void chase(TailorClass player, TownClass& env);
    void kill(TailorClass& player);
};
//============================================================================//
class BullyClass
{
  private:
    std::string Bname;
	short punch_power;
	short prob_punch;
///	std::vector<std::string> names_in_file;
    std::string names;
	int namelist;
//	std::vector<std::string> insults_in_file;
    std::string insults;
	int insultlist;
	point coord;
  public:
    void read_files();
    void bully_con();
	void punch(TailorClass & player);
	void patrol(TownClass & env);
};
//============================================================================//
