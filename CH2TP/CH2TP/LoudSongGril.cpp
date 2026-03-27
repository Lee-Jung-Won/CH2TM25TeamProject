#include "LoudSongGril.h"
#include <iostream>

LoudSongGril::LoudSongGril()
	: Monster("LoudSong Gril", 0, 0, 50, 50)
{
	level = 4;
	setstats();
}

void LoudSongGril::setstats()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> hpDist(level * 40, level * 50);
	uniform_int_distribution<> atkDist(level * 8, level * 10);

	health = hpDist(gen);
	maxHealth = health;
	attack = atkDist(gen);
}

void LoudSongGril::StartText()
{
	cout << "\033[31mLoudSong Gril: AAAAAAAAAAAAAAAAAAAA!!!!!!!\033[0m" << endl;
}

void LoudSongGril::DeadText()
{
	cout << "\033[31mLoudSong Gril is DEAD!\033[0m" << endl;
}