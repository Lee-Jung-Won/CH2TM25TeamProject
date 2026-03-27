#pragma once

#include "Monster.h"

#include <string>
#include <random>

class GiantBackpacker : public Monster
{
public:
	GiantBackpacker();

	void StartText() override;
	void DeadText() override;

private:
	void setstats();
};

