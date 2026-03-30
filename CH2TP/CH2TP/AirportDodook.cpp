#include "AirportDodook.h"
#include <iostream>

using namespace std;

AirportDodook::AirportDodook()
	: Monster("AirportDodook", 2000, 100, 0, 0)
{
	level = 10;
	
}

void AirportDodook::setstats()
{
	if (health <= maxHealth * 0.2f)//체력 20
	{
		attack = 200;
	}
	else if (health <= maxHealth * 0.5f)//체력 50
	{
		attack = 150;
	}
	else
	{
		attack = 100;//default
	}
}

void AirportDodook::StartText()
{
	cout << "\033[31mAirport Dodook: Wath TEREVI? Watch TEREVI? \033[0m" << endl;
}

void AirportDodook::BattleText()
{
	if (health <= maxHealth * 0.2f)
	{
		cout << "\033[31mAirport Dodook: Tlqkf!! Don't Blame Me! Tlqkf! Tlqkf!!\033[0m" << endl;
	}
	else if (health <= maxHealth * 0.5f)
	{
		cout << "\033[31mAirport Dodook: Very Ugly! You Look Like a Shit!!\033[0m" << endl;
	}
	else if (health <= maxHealth * 0.8f)
	{
		cout << "\033[31mAirport Dodook: You Know Inflation?? You Know IMF?? \033[0m" << endl;
	}
	else
	{
		cout << "\033[31mAirport Dodook: Watch NEWS? Watch NEWS?\033[0m" << endl;
	}
}

void AirportDodook::DeadText()
{
	cout << "\033[31mAirportDodook is DEAD!\033[0m" << endl;
}