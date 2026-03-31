#include "Deepkisscouple.h"
#include <iostream>

Deepkisscouple::Deepkisscouple()
	:Monster("[Lv3]Deepkiss couple", 0, 0, 80, 200)
{
	level = 3;
	setstats();
}

void Deepkisscouple::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 115, level * 150);
	uniform_int_distribution<> atkDist(level * 12.5, level * 15);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void Deepkisscouple::StartText()
{
	cout << "\033[31m[Lv3]Deepkiss couple: ...❤ ❤\033[0m" << endl;
}

void Deepkisscouple::DeadText()
{
	cout << "\033[31m[Lv3]Deepkiss couple is DEAD!\033[0m" << endl;
}