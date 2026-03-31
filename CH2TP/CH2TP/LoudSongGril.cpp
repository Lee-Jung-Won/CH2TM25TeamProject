#include "LoudSongGril.h"
#include <iostream>

LoudSongGril::LoudSongGril()
	: Monster("[Lv4]LoudSong Gril", 0, 0, 100, 300)
{
	level = 4;
	setstats();
}

void LoudSongGril::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 150, level * 200);
	uniform_int_distribution<> atkDist(level * 12, level * 13);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void LoudSongGril::StartText()
{
	cout << "\033[31m[Lv4]LoudSong Gril: AAAAAAAAAAAAAAAAAAAA!!!!!!!\033[0m" << endl;
}

void LoudSongGril::DeadText()
{
	cout << "\033[31m[Lv4]LoudSong Gril is DEAD!\033[0m" << endl;
}