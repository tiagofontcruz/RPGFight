#include <string>
#include <random>
#include <iostream>
#include "DieRoller.h"
#include "Monster.h"
#include "Player.h"
#include "Fight.h"
#include <windows.h>

int damage;
bool alive = true;

Fight::Fight() {

}

bool Fight(Player& P, Monster& M) {

	DieRoller droller;
	
	if (P.HP > 0)
	{
		alive = true;
	}

	if (P.job == JobEnum::CLERIC || P.job == JobEnum::SORCERER || P.job == JobEnum::WARLOCK || P.job == JobEnum::WIZARD)
	{
		//ONLY MAGICAL ATTACK
		do {			
			//player attack first
			if (P.WIS > M.DEX) {
				if (droller.RollDN(P.WIS) >= droller.RollDN(M.DEX))
				{
					//player's critical damage
					damage = (P.INT + droller.RollDN(6)) * 10 - (M.AC / 2);
					M.HP -= damage;
					std::cout << P.name << " attacks " << M.description << " and hits for " << damage << " critical damage!" << std::endl;
				}
				else
				{
					//player's normal damage
					damage = (P.INT + droller.RollDN(6)) * 4 - (M.AC / 2);
					M.HP -= damage;
					std::cout << P.name << " attacks " << M.description << " and hits for " << damage << " damage!" << std::endl;

				}
				//if monster died, there is no monster's attack
				if (M.HP > 0) {				
					if (droller.RollDN(M.DEX) >= droller.RollDN(P.DEX))
					{
						//monster's critical damage
						damage = (M.STR + droller.RollDN(6)) * 8 - (P.AC / 2);
						P.HP -= damage;
						std::cout << M.description << " attacks " << P.name << " and hits for " << damage << " critical damage!" << std::endl;
					}
					else
					{
						//monster's normal damage
						damage = (M.STR + droller.RollDN(6)) * 3 - (P.AC / 2);
						P.HP -= damage;
						std::cout << M.description << " attacks " << P.name << " and hits for " << damage << " damage!" << std::endl;
					}
				}
			}
			else
			{
				//monster attack first
				if (droller.RollDN(M.DEX) >= droller.RollDN(P.DEX))
				{
					//monster's critical damage
					damage = (M.STR + droller.RollDN(6)) * 8 - (P.AC / 2);
					P.HP -= damage;
					std::cout << M.description << " attacks " << P.name << " and hits for " << damage << " critical damage!" << std::endl;
				}
				else
				{
					//monster's normal damage
					damage = (M.STR + droller.RollDN(6)) * 3 - (P.AC / 2);
					P.HP -= damage;
					std::cout << M.description << " attacks " << P.name << " and hits for " << damage << " damage!" << std::endl;
				}
				//if player died, there is no player's attack
				if (P.HP <= 0) {
					alive = false;
				}
				else
				{
					if (droller.RollDN(P.WIS) >= droller.RollDN(M.DEX))
					{
						//player's critical damage
						damage = (P.INT * droller.RollDN(6)) * 10 - (M.AC / 2);
						M.HP -= damage;
						std::cout << P.name << " attacks " << M.description << " and hits for " << damage << " critical damage!" << std::endl;
					}
					else
					{
						//player's normal damage
						damage = (P.INT * droller.RollDN(6)) * 4 - (M.AC / 2);
						M.HP -= damage;
						std::cout << P.name << " attacks " << M.description << " and hits for " << damage << " damage!" << std::endl;
					}
				}
			}
			Sleep(1000);
		} while (M.HP >=0);
	}
	else
	{
		//ONLY PHYSICAL ATTACK
		do {
			//player attack first
			if (P.DEX > M.DEX) {
				if (droller.RollDN(P.DEX) >= droller.RollDN(M.DEX))
				{
					//player's critical damage
					damage = (P.STR + droller.RollDN(6)) * 5 - (M.AC / 2);
					M.HP -= damage;
					std::cout << P.name << " attacks " << M.description << " and hits for " << damage << " critical damage!" << std::endl;
				}
				else
				{
					//player's normal damage
					damage = (P.STR + droller.RollDN(6)) * 2 - (M.AC / 2);
					M.HP -= damage;
					std::cout << P.name << " attacks " << M.description << " and hits for " << damage << " damage!" << std::endl;

				}
				//if monster died, there is no monster's attack
				if (M.HP > 0) {					
					if (droller.RollDN(M.DEX) >= droller.RollDN(P.DEX))
					{
						//monster's critical damage
						damage = (M.STR + droller.RollDN(6)) * 8 - (P.AC / 2);
						P.HP -= damage;
						std::cout << M.description << " attacks " << P.name << " and hits for " << damage << " critical damage!" << std::endl;
					}
					else
					{
						//monster's normal damage
						damage = (M.STR + droller.RollDN(6)) * 3 - (P.AC / 2);
						P.HP -= damage;
						std::cout << M.description << " attacks " << P.name << " and hits for " << damage << " damage!" << std::endl;
					}
				}
			}
			else
			{
				//monster attack first
				if (droller.RollDN(M.DEX) >= droller.RollDN(P.DEX))
				{
					//monster's critical damage
					damage = (M.STR + droller.RollDN(6)) * 8 - (P.AC / 2);
					P.HP -= damage;
					std::cout << M.description << " attacks " << P.name << " and hits for " << damage << " critical damage!" << std::endl;
				}
				else
				{
					//monster's normal damage
					damage = (M.STR + droller.RollDN(6)) * 3 - (P.AC / 2);
					P.HP -= damage;
					std::cout << M.description << " attacks " << P.name << " and hits for " << damage << " damage!" << std::endl;
				}
				//if player died, there is no player's attack
				if (P.HP <= 0) {
					alive = false;
				}
				else
				{
					if (droller.RollDN(P.DEX) >= droller.RollDN(M.DEX))
					{
						//player's critical damage
						damage = (P.STR * droller.RollDN(6)) * 5 - (M.AC / 2);
						M.HP -= damage;
						std::cout << P.name << " attacks " << M.description << " and hits for " << damage << " critical damage!" << std::endl;
					}
					else
					{
						//player's normal damage
						damage = (P.STR * droller.RollDN(6)) * 2 - (M.AC / 2);
						M.HP -= damage;
						std::cout << P.name << " attacks " << M.description << " and hits for " << damage << " damage!" << std::endl;
					}
				}
			}
			Sleep(1000);
		} while (M.HP >= 0);
	}
	if (P.HP > 0)
	{
		std::cout << "" << std::endl;
		std::cout << "*******************************************************************************" << std::endl;
		std::cout << P.name << " has " << P.HP << " HP remaining!" << std::endl;
		std::cout << P.name << " has increased 1 point for each attribute!" << std::endl;
		std::cout << "STR: " << (P.STR += 1) << "  CON: " << (P.CON += 1) << "  DEX: " << (P.DEX) << " NO CHANGES" << std::endl;
		std::cout << "INT: " << (P.INT += 1) << "  CHA: " << (P.CHA += 1) << "  WIS: " << (P.WIS) << " NO CHANGES" << std::endl;
		std::cout << "*******************************************************************************" << std::endl;
	}
	else
	{
		alive = false;
	}
	return alive;
}