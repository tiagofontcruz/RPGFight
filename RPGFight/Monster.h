#pragma once

#include<string>

class Monster
{
public:
	std::string description;
	int LEVEL; //counter
	int STR; //strength
	int DEX; //dexterity
	int HP; //Hit Points
	int AC; //Armour Class, a measurement of how hard we are to hit or how much damage mitigation we do

	Monster(); //constructor, called automatically when we create a Player object
	void Print(); //method to //displays the monster information
};

//this is a standalone function that fills out a player's data
void CreateMonster(Monster& theMonster);


