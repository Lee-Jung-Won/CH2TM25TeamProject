#pragma once

#include "Monster.h"

#include <string>
#include <random>

class LoudSongGirl : public Monster
{
public:
	LoudSongGirl();

	void StartText() override;
	void DeadText() override;

private:
	void setstats();
};

