#include "GiantBackpacker.h"
#include <iostream>

GiantBackpacker::GiantBackpacker()
	: Monster("GiantBack packer", 0, 0, 45, 35)
{
	level = 3;
	setstats();
}

void GiantBackpacker::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 30, level * 40);
	uniform_int_distribution<> atkDist(level * 5, level * 10);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void GiantBackpacker::StartText()
{
	cout << "\033[31mGiantBack packer: jamsiman jinagalgeyo~\033[0m" << endl;
}

void GiantBackpacker::DeadText()
{
	cout << "\033[31mGiantBack packer is DEAD!\033[0m" << endl;
}