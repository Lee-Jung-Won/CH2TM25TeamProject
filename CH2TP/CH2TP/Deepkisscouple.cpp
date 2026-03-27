#include "Deepkisscouple.h"
#include <iostream>

Deepkisscouple::Deepkisscouple()
	:Monster("Deepkiss couple", 0, 0, 45, 35)
{
	level = 3;
	setstats();
}

void Deepkisscouple::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 30, level * 40);
	uniform_int_distribution<> atkDist(level * 5, level * 10);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void Deepkisscouple::StartText()
{
	cout << "\033[31mDeepkiss couple: ...❤ ❤\033[0m" << endl;
}

void Deepkisscouple::DeadText()
{
	cout << "\033[31mDeepkiss couple is DEAD!\033[0m" << endl;
}