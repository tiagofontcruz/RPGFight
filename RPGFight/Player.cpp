#include "Player.h"
#include "DieRoller.h"
#include<random>
#include<iostream>
#include <windows.h>

Player::Player() {
	//initialize variables
	STR = CON = DEX = INT = WIS = CHA = AC = 0;
	HP = 100;
	name = "WhoKnows";
}

void Player::Print()
{
	system("cls");
	std::cout << "Name: " << name << std::endl;
	std::cout << "Race: ";

	//prints the name of the race the player has chosen
	switch (race)
	{
	case DWARF:
		std::cout << "Dwarf" << std::endl;
		break;
	case ELF:
		std::cout << "Elf" << std::endl;
		break;
	case HALFLING:
		std::cout << "Halfing" << std::endl;
		break;
	case HUMAN:
		std::cout << "Human" << std::endl;
		break;
	case DRAGONBORN:
		std::cout << "Dragonborn" << std::endl;
		break;
	case GNOME:
		std::cout << "Gnome" << std::endl;
		break;
	case HALFELF:
		std::cout << "Half Elf" << std::endl;
		break;
	case HALFORC:
		std::cout << "Half Orc" << std::endl;
		break;
	case TIEFLING:
		std::cout << "Tiefling" << std::endl;
		break;
	default:
		std::cout << "Uknown race" << std::endl;
	}

	std::cout << "Class: ";

	//prints the name of the class the player has chosen
	switch (job)
	{
	case JobEnum::BARBARIAN:
		std::cout << "Barbarian" << std::endl;
		break;
	case JobEnum::BARD:
		std::cout << "Bard" << std::endl;
		break;
	case JobEnum::CLERIC:
		std::cout << "Cleric" << std::endl;
		break;
	case JobEnum::DRUID:
		std::cout << "Druid" << std::endl;
		break;
	case JobEnum::FIGHTER:
		std::cout << "Fighter" << std::endl;
		break;
	case JobEnum::MONK:
		std::cout << "Monk" << std::endl;
		break;
	case JobEnum::PALADIN:
		std::cout << "Paladin" << std::endl;
		break;
	case JobEnum::RANGER:
		std::cout << "Ranger" << std::endl;
		break;
	case JobEnum::ROGUE:
		std::cout << "Rogue" << std::endl;
		break;
	case JobEnum::SORCERER:
		std::cout << "Sorcerer" << std::endl;
		break;
	case JobEnum::WARLOCK:
		std::cout << "Warlock" << std::endl;
		break;
	case JobEnum::WIZARD:
		std::cout << "Wizard" << std::endl;
		break;
	default:
		std::cout << "Uknown character class" << std::endl;
	}

	std::cout << "" << std::endl;

	//prints the values of each attribute
	std::cout << "***************************************" << std::endl;
	std::cout << "STR: " << STR << std::endl;
	std::cout << "CON: " << CON << std::endl;
	std::cout << "DEX: " << DEX << std::endl;
	std::cout << "INT: " << INT << std::endl;
	std::cout << "WIS: " << WIS << std::endl;
	std::cout << "CHA: " << CHA << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Your Iniciative Modifier: " << GetInitiativeModifier() << std::endl;
	std::cout << "Your Armour Class point are: " << AC << std::endl;
	std::cout << "Your Hit Point are: " << HP << std::endl;
	std::cout << "" << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "GET READY FOR BATTLE !!!!" << std::endl;
	system("pause");
}

//method that creates the character
void CreateCharacter(Player& thePlayer)
{
	DieRoller droller; //creates the type object DieRoller

	//random player's race	
	int raceChoice = droller.RollDN(9);

	switch (raceChoice)
	{
	case 1:
		thePlayer.race = DWARF;
		break;
	case 2:
		thePlayer.race = ELF;
		break;
	case 3:
		thePlayer.race = HALFLING;
		break;
	case 4:
		thePlayer.race = HUMAN;
		break;
	case 5:
		thePlayer.race = DRAGONBORN;
		break;
	case 6:
		thePlayer.race = GNOME;
		break;
	case 7:
		thePlayer.race = HALFELF;
		break;
	case 8:
		thePlayer.race = HALFORC;
		break;
	case 9:
		thePlayer.race = TIEFLING;
		break;
	default:
		std::cout << "That was an invalid choice! You are now a human." << std::endl;
		thePlayer.race = HUMAN;
	}

	//Random player's class	
	int classChoice = droller.RollDN(12);

	switch (classChoice)
	{
	case 1:
		thePlayer.job = JobEnum::BARBARIAN;
		thePlayer.AC = 16 + thePlayer.CON / 2; //add Armour Class point
		break;
	case 2:
		thePlayer.job = JobEnum::BARD;
		thePlayer.AC += 12 + thePlayer.DEX / 2; //add Armour Class point
		break;
	case 3:
		thePlayer.job = JobEnum::CLERIC;
		thePlayer.AC += 10 + thePlayer.DEX / 2; //add Armour Class point
		break;
	case 4:
		thePlayer.job = JobEnum::DRUID;
		thePlayer.AC = 18 + thePlayer.CON / 2; //add Armour Class pointv
		break;
	case 5:
		thePlayer.job = JobEnum::FIGHTER;
		thePlayer.AC = 16 + thePlayer.CON / 2; //add Armour Class point
		break;
	case 6:
		thePlayer.job = JobEnum::MONK;
		thePlayer.AC += 12 + thePlayer.DEX / 2; //add Armour Class point
		break;
	case 7:
		thePlayer.job = JobEnum::PALADIN;
		thePlayer.AC = 16 + thePlayer.CON / 2; //add Armour Class point
		break;
	case 8:
		thePlayer.job = JobEnum::RANGER;
		thePlayer.AC = 12 + thePlayer.CON / 2; //add Armour Class point
		break;
	case 9:
		thePlayer.job = JobEnum::ROGUE;
		thePlayer.AC = 12 + thePlayer.CON / 2; //add Armour Class point
		break;
	case 10:
		thePlayer.job = JobEnum::SORCERER;
		thePlayer.AC += 10 + thePlayer.DEX / 2; //add Armour Class point
		break;
	case 11:
		thePlayer.job = JobEnum::WARLOCK;
		thePlayer.AC += 10 + thePlayer.DEX / 2; //add Armour Class point
		break;
	case 12:
		thePlayer.job = JobEnum::WIZARD;
		thePlayer.AC += 10 + thePlayer.DEX / 2; //add Armour Class point
		break;
	default:
		std::cout << "That was an invalid choice! You are now a bard." << std::endl;
		thePlayer.job = JobEnum::BARD;
		thePlayer.AC += 12 + thePlayer.DEX / 2;
	}

	std::cout << "Please enter a name for your character: ";
	std::cin >> thePlayer.name;

	int op;
	//roll the dices
	do
	{
		std::cout << "Please enter number 3 for roll 3D6 or 4 for roll 4D6: ";
		std::cin >> op;

		if (op == 3)
		{
			thePlayer.STR = droller.RollDN(6) + droller.RollDN(6) + droller.RollDN(6);
			thePlayer.CON = droller.RollDN(6) + droller.RollDN(6) + droller.RollDN(6);
			thePlayer.DEX = droller.RollDN(6) + droller.RollDN(6) + droller.RollDN(6);
			thePlayer.INT = droller.RollDN(6) + droller.RollDN(6) + droller.RollDN(6);
			thePlayer.WIS = droller.RollDN(6) + droller.RollDN(6) + droller.RollDN(6);
			thePlayer.CHA = droller.RollDN(6) + droller.RollDN(6) + droller.RollDN(6);
		}

		if (op == 4) {
			thePlayer.STR = droller.Roll4D6DropLowest();
			thePlayer.CON = droller.Roll4D6DropLowest();
			thePlayer.DEX = droller.Roll4D6DropLowest();
			thePlayer.INT = droller.Roll4D6DropLowest();
			thePlayer.WIS = droller.Roll4D6DropLowest();
			thePlayer.CHA = droller.Roll4D6DropLowest();
		}

		thePlayer.HP = thePlayer.HP * thePlayer.CON;

	} while (op != 3 && op != 4);

	int abilityScore = 0;

	//gives the player a race Ability Score (modifier)
	switch (thePlayer.race)
	{
	case DWARF:
		abilityScore = 2;
		thePlayer.CON += abilityScore;
		break;
	case ELF:
		abilityScore = 1;
		thePlayer.INT += abilityScore;
		break;
	case HALFLING:
		abilityScore = 2;
		thePlayer.DEX += abilityScore;
		break;
	case HUMAN:
		abilityScore = 1;
		thePlayer.STR += abilityScore;
		thePlayer.CON += abilityScore;
		thePlayer.DEX += abilityScore;
		thePlayer.INT += abilityScore;
		thePlayer.WIS += abilityScore;
		thePlayer.CHA += abilityScore;
		break;
	case DRAGONBORN:
		abilityScore = 2;
		thePlayer.STR += abilityScore;
		thePlayer.CHA += abilityScore - 1;
		break;
	case GNOME:
		abilityScore = 2;
		thePlayer.INT += abilityScore;
		break;
	case HALFELF:
		abilityScore = 2;
		thePlayer.CHA += abilityScore;
		thePlayer.DEX += abilityScore - 1;
		thePlayer.INT += abilityScore - 1;
		break;
	case HALFORC:
		abilityScore = 2;
		thePlayer.STR += abilityScore;
		thePlayer.CON += abilityScore - 1;
		break;
	case TIEFLING:
		abilityScore = 2;
		thePlayer.CHA += abilityScore;
		thePlayer.INT += abilityScore - 1;
		break;
	default:
		std::cout << "Uknown race" << std::endl;
	}
}

//return our DEX-based initiative modifier
int Player::GetInitiativeModifier()
{
	int modifier = 0;

	if (DEX == 1)
	{
		modifier = -5;
		DEX += modifier;
	}
	if (DEX == 1 || DEX == 2)
	{
		modifier = -4;
		DEX += modifier;
	}
	if (DEX == 4 || DEX == 5)
	{
		modifier = -3;
		DEX += modifier;
	}
	if (DEX == 6 || DEX == 7)
	{
		modifier = -2;
		DEX += modifier;
	}
	if (DEX == 8 || DEX == 9)
	{
		modifier = -1;
		DEX += modifier;
	}
	if (DEX == 10 || DEX == 11)
	{
		modifier = 0;
		DEX += modifier;
	}
	if (DEX == 12 || DEX == 13)
	{
		modifier = 1;
		DEX += modifier;
	}
	if (DEX == 14 || DEX == 15)
	{
		modifier = 2;
		DEX += modifier;
	}
	if (DEX == 16 || DEX == 17)
	{
		modifier = 3;
		DEX += modifier;
	}
	if (DEX == 18 || DEX == 19)
	{
		modifier = 4;
		DEX += modifier;
	}
	if (DEX == 20 || DEX == 21)
	{
		modifier = 5;
		DEX += modifier;
	}
	if (DEX == 22 || DEX == 23)
	{
		modifier = 6;
		DEX += modifier;
	}
	if (DEX == 24 || DEX == 25)
	{
		modifier = 7;
		DEX += modifier;
	}
	if (DEX == 26 || DEX == 27)
	{
		modifier = 8;
		DEX += modifier;
	}
	if (DEX == 28 || DEX == 29)
	{
		modifier = 9;
		DEX += modifier;
	}
	if (DEX == 30)
	{
		modifier = 10;
		DEX += modifier;
	}
	return modifier;
}


