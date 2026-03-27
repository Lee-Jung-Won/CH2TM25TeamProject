#pragma once

#include "Monster.h"

#include <string>
#include <random>

class AngryHomeless : public Monster
{
public:
	AngryHomeless();

	void StartText() override;
	void DeadText() override;

private:
	void setstats();
};


