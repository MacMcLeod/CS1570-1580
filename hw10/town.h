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
    friend class TailorClass;
    bool replaceSymbol(point p, char letter);
    char checkGrid(point p);
    void proceduralGenerator();
    void printTown();
    friend ostream& operator<<(ostream& out, TownClass & town);
    void graphicalPrintTown();
    void GenerateWalls();
    void GenerateFence();
  private:
    bool checkFenceAdj(short dir, const point p);
    bool moveTarget(short dir, point & p);
    location grid[MAX][MAX];
    bool GenerateHouse(point p);
};
