#include "DeepsleepMan.h"
#include <iostream>

using namespace std;

DeepsleepMan::DeepsleepMan()
	: Monster("[LV2]Deepsleep Man", 0, 0, 60, 150)
{
	level = 2;
	setstats();
}

void DeepsleepMan::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 125, level * 175);
	uniform_int_distribution<> atkDist(level * 12.5, level * 17.5);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void DeepsleepMan::StartText()
{
	cout << "\033[31m[LV2]Deepsleep Man: Zzz....Zz....\033[0m" << endl;
}

void DeepsleepMan::DeadText()
{
	cout << "\033[31m[LV2]Deepsleep Man is DEAD!\033[0m" << endl;
}