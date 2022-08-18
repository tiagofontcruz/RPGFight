#pragma once

#include<string>

enum class JobEnum { BARBARIAN, BARD, CLERIC, DRUID, FIGHTER, MONK, PALADIN, RANGER, ROGUE, SORCERER, WARLOCK, WIZARD };
enum RaceEnum { DWARF, ELF, HALFLING, HUMAN, DRAGONBORN, GNOME, HALFELF, HALFORC, TIEFLING };

class Player
{
public:
	std::string name;
	int STR; //strength
	int CON; //constitution
	int DEX; //dexterity
	int INT; //intelligence
	int WIS; //Wisdom
	int CHA; //Charisma	
	int HP; //Hit Points
	int AC; //Armour Class

	JobEnum job;
	RaceEnum race;

	Player(); //constructor, called automatically when we create a Player object
	void Print(); //method to display the character "sheet", or data
	int GetInitiativeModifier(); //return our DEX-based modifier
};

//this is a standalone function that fills out a player's data
void CreateCharacter(Player& thePlayer);


