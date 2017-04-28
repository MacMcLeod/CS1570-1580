// Programmer: Anna Case                         Date: 3/19/2017
// File: town.h                           		 Class: CS1570
// Instructor: Mardham
// Student Id: 16181344                          Section: C
// Description: town class

#pragma once
#include "heading.h"
//Classes
class TownClass
{
  public:
    bool replaceSymbol(point p, char letter);
    char checkGrid(point p);
    //////////////////////////////
    void proceduralGenerator();
    void printTown();
    void graphicalPrintTown();
    void GenerateWalls();
    void GenerateFence();
  private:
    location grid[MAX][MAX];
    bool GenerateHouse(point p);
};
