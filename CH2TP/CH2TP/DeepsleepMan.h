#pragma once

#include "Monster.h"

#include <string>
#include <random>

class DeepsleepMan : public Monster
{
public:
	DeepsleepMan();

	void StartText() override;
	void DeadText() override;

private:
	void setstats();
};


