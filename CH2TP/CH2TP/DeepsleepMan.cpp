#include "DeepsleepMan.h"
#include <iostream>

using namespace std;

DeepsleepMan::DeepsleepMan()
	: Monster("Deepsleep Man", 0, 0, 30, 25)
{
	level = 2;
	setstats();
}

void DeepsleepMan::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 30, level * 40);
	uniform_int_distribution<> atkDist(level * 5, level * 8);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void DeepsleepMan::StartText()
{
	cout << "\033[31mDeepsleep Man: Zzz....Zz....\033[0m" << endl;
}

void DeepsleepMan::DeadText()
{
	cout << "\033[31mDeepsleep Man is DEAD!\033[0m" << endl;
}