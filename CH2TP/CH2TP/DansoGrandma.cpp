#include "DansoGrandma.h"
#include <iostream>

DansoGrandma::DansoGrandma()
	:Monster("[Lv9]Danso Grandma", 0, 0, 200, 135)
{
	level =9;
	setstats();
}

void DansoGrandma::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 189, level * 211);
	uniform_int_distribution<> atkDist(level * 9.4, level * 11);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void DansoGrandma::StartText()
{
	cout << "\033[31m[Lv9]Danso Grandma: Who-A-U Who-A-U Sit Down Darling..❤ ❤\033[0m" << endl;
}

void DansoGrandma::DeadText()
{
	cout << "\033[31m[Lv9]Danso Grandma is DEAD!\033[0m" << endl;
}