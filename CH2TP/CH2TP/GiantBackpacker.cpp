#include "GiantBackpacker.h"
#include <iostream>

GiantBackpacker::GiantBackpacker()
	: Monster("[Lv3]GiantBack packer", 0, 0, 80, 200)
{
	level = 3;
	setstats();
}

void GiantBackpacker::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 115, level * 150);
	uniform_int_distribution<> atkDist(level * 12.5, level * 15);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void GiantBackpacker::StartText()
{
	cout << "\033[31m[Lv3]GiantBack packer: jamsiman jinagalgeyo~\033[0m" << endl;
}

void GiantBackpacker::DeadText()
{
	cout << "\033[31m[Lv3]GiantBack packer is DEAD!\033[0m" << endl;
}