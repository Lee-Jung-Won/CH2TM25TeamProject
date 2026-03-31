#include "LoudSongGirl.h"
#include <iostream>

LoudSongGirl::LoudSongGirl()
	: Monster("[Lv4]LoudSong Girl", 0, 0, 100, 300)
{
	level = 4;
	setstats();
}

void LoudSongGirl::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 150, level * 200);
	uniform_int_distribution<> atkDist(level * 12, level * 13);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void LoudSongGirl::StartText()
{
	cout << "\033[31m[Lv4]LoudSong Girl: AAAAAAAAAAAAAAAAAAAA!!!!!!!\033[0m" << endl;
}

void LoudSongGirl::DeadText()
{
	cout << "\033[31m[Lv4]LoudSong Girl is DEAD!\033[0m" << endl;
}