#include "SmokingGuy.h"
#include <iostream>

SmokingGuy::SmokingGuy()
	: Monster("Smoking Guy", 0, 0, 50, 50)
{
	level = 4;
	setstats();
}

void SmokingGuy::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 40, level * 50);
	uniform_int_distribution<> atkDist(level * 8, level * 10);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void SmokingGuy::StartText()
{
	cout << "\033[31mSmoking Guy: dambe chumba?\033[0m" << endl;
}

void SmokingGuy::DeadText()
{
	cout << "\033[31mSmoking Guy is DEAD!\033[0m" << endl;
}