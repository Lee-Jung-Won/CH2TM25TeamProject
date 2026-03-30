#include "HandleExerciser.h"
#include <iostream>

HandleExerciser::HandleExerciser()
	: Monster("Handle Exerciser", 0, 0, 170, 130)
{
	level = 9;
	setstats();
}

void HandleExerciser::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 30, level * 40);
	uniform_int_distribution<> atkDist(level * 5, level * 10);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void HandleExerciser::StartText()
{
	cout << "\033[31mHandle Exerciser: Endless Supanova Tornado Splash-! ! !\033[0m" << endl;
}

void HandleExerciser::DeadText()
{
	cout << "\033[31mHandle Exerciser is DEAD!\033[0m" << endl;
}