#include "SmokingGuy.h"
#include <iostream>

SmokingGuy::SmokingGuy()
	: Monster("[Lv4]Smoking Guy", 0, 0, 100, 300)
{
	level = 4;
	setstats();
}

void SmokingGuy::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 150, level * 200);
	uniform_int_distribution<> atkDist(level * 12, level * 13);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void SmokingGuy::StartText()
{
	cout << "\033[31m[Lv4]Smoking Guy: dambe chumba?\033[0m" << endl;
}

void SmokingGuy::DeadText()
{
	cout << "\033[31m[Lv4]Smoking Guy is DEAD!\033[0m" << endl;
}