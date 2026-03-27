#pragma once

#include "Monster.h"

#include <string>
#include <random>

class Deepkisscouple : public Monster
{
public:
	Deepkisscouple();

	void StartText() override;
	void DeadText() override;

private:
	void setstats();
};

