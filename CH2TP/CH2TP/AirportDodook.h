#pragma once

#include "Monster.h"

#include <string>
#include <random>

class AirportDodook : public Monster
{
public:
	AirportDodook();

	void StartText() override;
	void BattleText();
	void DeadText() override;

private:
	void setstats();
};


