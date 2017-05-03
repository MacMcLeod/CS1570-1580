#pragma once
#include "creatures.h"
#include "heading.h"
#include "town.h"
void wait(int seconds);
bool place(char symbol,point & coord,point newLocation,TownClass & env);
bool move(short dist, short dir, point & location, TownClass & env);
bool walkingDir (int dir, TownClass& env, point& location);

