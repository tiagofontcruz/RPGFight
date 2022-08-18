#include<iostream>
#include "Fight.h" //this includes player.h and monster.h 
#include <windows.h>

void main()
{
	Player thePlayer;
	CreateCharacter(thePlayer);
	thePlayer.Print();

	Monster theMonster;

	do
	{
		CreateMonster(theMonster);
		theMonster.Print();

		if (Fight(thePlayer, theMonster))
		{
			std::cout << "You defeat the " << theMonster.description << "!" << std::endl;
			Sleep(6000);
			system("cls");
		}
	} while (thePlayer.HP > 0);

	std::cout << "The " << theMonster.description << " defeated you!" << std::endl;
	std::cout << "YOU DIED!" << std::endl;
	Sleep(6000);
	system("cls");
}