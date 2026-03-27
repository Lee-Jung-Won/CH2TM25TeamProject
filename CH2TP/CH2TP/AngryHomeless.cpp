#include "AngryHomeless.h"
#include <iostream>

using namespace std;

AngryHomeless::AngryHomeless()
	: Monster("Deepsleep Man", 0, 0, 30, 25)
{
	level = 2;
	setstats();
}

void AngryHomeless::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 30, level * 40);
	uniform_int_distribution<> atkDist(level * 5, level * 8);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void AngryHomeless::StartText()
{
	cout << "\033[31mAngryHomeless: 1000won please....\033[0m" << endl;
}

void AngryHomeless::DeadText()
{
	cout << "\033[31mAngryHomeless is DEAD!\033[0m" << endl;
}