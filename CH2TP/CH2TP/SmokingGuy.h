#pragma once

#include "Monster.h"

#include <string>
#include <random>

class SmokingGuy : public Monster
{
public:
	SmokingGuy();

	void StartText() override;
	void DeadText() override;

private:
	void setstats();
};

