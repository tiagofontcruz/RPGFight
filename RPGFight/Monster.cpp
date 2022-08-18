#include "Monster.h"
#include "DieRoller.h"
#include<random>
#include<iostream>

Monster::Monster() {
	//initialize variables
	LEVEL = 0;
	description = "WhoKnows";
}

void Monster::Print()
{
	std::cout << "" << std::endl;
	std::cout << "A " << description << "appears!" << std::endl;
	std::cout << "" << std::endl;
	//prints the values of each attribute
	std::cout << "STR: " << STR << std::endl;
	std::cout << "DEX: " << DEX << std::endl;	
	std::cout << "" << std::endl;		
	std::cout << "The monster Armour Class point are: " << AC << std::endl;
	std::cout << "The monster Hit Point are: " << HP << std::endl;
	std::cout << "" << std::endl;
	std::cout << "***************************************" << std::endl;
}

//method that creates the monster
void CreateMonster(Monster& theMonster)
{
	DieRoller droller; //creates the type object DieRoller
	
	//initialize variables for each time that the function is called
	int monsterType = droller.RollDN(3);
	theMonster.STR = theMonster.DEX = theMonster.AC = 1;
	theMonster.HP = 200;

	if (theMonster.LEVEL <= 5)
	{
		theMonster.STR = droller.RollDN(6) + droller.RollDN(2); //add strengh
		theMonster.HP = theMonster.HP + droller.RollDN(10); //add Hit Points
		theMonster.DEX = droller.RollDN(6) + droller.RollDN(2); //add dexterity
		theMonster.AC = 6 + theMonster.DEX / 2; //add Armour Class point
		switch (monsterType)
		{
		case 1:
			theMonster.description = "Tiny beast";			
			break;
		case 2:
			theMonster.description = "Small humanoid";
			break;
		case 3:
			theMonster.description = "Small fey";
			break;
		default:
			std::cout << "That was an invalid number!" << std::endl;
		}
	}else if (theMonster.LEVEL <= 15)
		{
		theMonster.STR = droller.RollDN(9) + droller.RollDN(3); //add strengh
		theMonster.HP = theMonster.HP * 3 + droller.RollDN(10); //add Hit Points
		theMonster.DEX = droller.RollDN(9) + droller.RollDN(3); //add dexterity
		theMonster.AC = 8 + theMonster.DEX / 2; //add Armour Class point
		switch (monsterType)
		{
		case 1:
			theMonster.description = "Medium beast";
			break;
		case 2:
			theMonster.description = "Medium Undead";
			break;
		case 3:
			theMonster.description = "Medium dragon";
			break;
		default:
			std::cout << "That was an invalid number!" << std::endl;
		}
	}else if (theMonster.LEVEL >= 16)
		{
		theMonster.STR = droller.RollDN(14) + droller.RollDN(4); //add strengh
		theMonster.HP = theMonster.HP * 5 + droller.RollDN(10); //add Hit Points
		theMonster.DEX = droller.RollDN(14) + droller.RollDN(4); //add dexterity
		theMonster.AC = 10 + theMonster.DEX / 2; //add Armour Class point
		switch (monsterType)
		{
		case 1:
			theMonster.description = "Large beast";			
			break;
		case 2:
			theMonster.description = "Large monstrosity";
			break;
		case 3:
			theMonster.description = "Large dragon";
			break;
		default:
			std::cout << "That was an invalid number!" << std::endl;
		}
	}
	theMonster.LEVEL++;
}
