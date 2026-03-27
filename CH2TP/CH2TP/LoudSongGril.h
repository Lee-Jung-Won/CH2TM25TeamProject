#pragma once

#include "Monster.h"

#include <string>
#include <random>

class LoudSongGril : public Monster
{
public:
	LoudSongGril();

	void StartText() override;
	void DeadText() override;

private:
	void setstats();
};

