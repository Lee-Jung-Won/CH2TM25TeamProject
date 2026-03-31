#include "HandleExerciser.h"
#include <iostream>

HandleExerciser::HandleExerciser()
	: Monster("[Lv9]Handle Exerciser", 0, 0, 200, 1500)
{

	level = 9;
	setstats();
}

void HandleExerciser::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 889, level * 1238);
	uniform_int_distribution<> atkDist(level * 9.4, level * 11);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void HandleExerciser::StartText()
{
	cout << "\033[31m[Lv9]Handle Exerciser: Endless Supanova Tornado Splash-! ! !\033[0m" << endl;
}

void HandleExerciser::DeadText()
{
	cout << "\033[31m[Lv9]Handle Exerciser is DEAD!\033[0m" << endl;
}