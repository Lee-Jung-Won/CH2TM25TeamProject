#include "AngryHomeless.h"
#include <iostream>

using namespace std;

AngryHomeless::AngryHomeless()
	: Monster("[LV2]AngryHomeless", 0, 0, 60, 150)
{
	level = 2;
	setstats();
}

void AngryHomeless::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 125, level * 175);
	uniform_int_distribution<> atkDist(level * 12.5, level * 17.5);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void AngryHomeless::StartText()
{
	cout << "\033[31m[LV2]AngryHomeless: 1000won please....\033[0m" << endl;
}

void AngryHomeless::DeadText()
{
	cout << "\033[31m[LV2]AngryHomeless is DEAD!\033[0m" << endl;
}