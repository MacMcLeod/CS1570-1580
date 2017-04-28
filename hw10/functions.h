#pragma once
#include "town.h"
void wait(int seconds);
bool place(char symbol,point & coord,point newLocation,TownClass & env);
bool move(short dist, short dir, point & location, TownClass & env);

