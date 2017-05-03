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
#include "functions.h"
//Tailor
const int STARTPANTS = 30;
const int MAXM = 40;
const int MINM = 20;
const int HP = 100;
//Pants
const int START = -1;
const int PROBCHASE = 25;
//Bullies
const int INCR = 10;
const int MAXP = 50;
const int MINP = 30;
const short PROB = 80;

class TailorClass
{
  private:
    string name; 
    char P;
    int money;
    bool alive;
    short health;
    short pants;
    int dir;
    point coord;
    point newLoc;
    point object; //house and checkdir object
  public:
    string getName()
    {
      return name;
    }
    friend class TownClass;
    friend class PhantomClass;
    friend class BullyClass;
    TailorClass()
    {
      health = HP;
      alive = true;
      money = rand()%MAXM+MINM;
      pants = STARTPANTS;
      coord.x = -1;
      coord.y = -1;
      P = 'M';
      name = "Milhouse";
    }
    friend ostream& operator<<(ostream& stream, TailorClass player);
    void randWalk(TownClass& env);
    void moved(TownClass& env);
    bool jumpFence(TownClass& env);
    char checkDir(int dir, TownClass env);
    void turn(TownClass& env);
    bool isAlive();
    bool hasInventory();
};
//============================================================================//
class PhantomClass ///constructed in town
{
  private:
    point coord;
    point newLoc;
    bool existing;
  public: 
    PhantomClass()
    {
      coord.x = -1;
      coord.y = -1;
      existing = false;
    }
    bool exists();
    void place_pants(TownClass& env, TailorClass& player);
    void chase(TailorClass& player, TownClass& env);
    void kill(TailorClass& player);
};
//============================================================================//
class BullyClass
{
  private:
    string Bname;
    short punch_power;
    short prob_punch;
    vector<string> names_in_file;
    string names;
    int namelist;
    vector<string> insults_in_file;
    string insults;
    int insultlist;
    point coord;
    point newLoc;
  public:
    BullyClass();
    void placement(TownClass& env);
    void punch(TailorClass& player, TownClass& env, PhantomClass ghosts[]);
    void patrol(TailorClass& player, TownClass& env, int& punchCount, PhantomClass ghosts[]);
};
//============================================================================//
