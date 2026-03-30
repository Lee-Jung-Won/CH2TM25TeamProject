#include "DansoGrandma.h"
#include <iostream>

DansoGrandma::DansoGrandma()
	:Monster("Danso Grandma", 0, 0, 200, 135)
{
	level =9;
	setstats();
}

void DansoGrandma::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 30, level * 40);
	uniform_int_distribution<> atkDist(level * 5, level * 10);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void DansoGrandma::StartText()
{
	cout << "\033[31mDanso Grandma: Who-A-U Who-A-U Sit Down Darling..❤ ❤\033[0m" << endl;
}

void DansoGrandma::DeadText()
{
	cout << "\033[31mDanso Grandma is DEAD!\033[0m" << endl;
}