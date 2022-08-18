#pragma once

#include "Monster.h"
#include "Player.h"

class Fight
{
public:
	Fight(); //constructor, called automatically when we create a Fight object
};

bool Fight(Player& P, Monster& M);