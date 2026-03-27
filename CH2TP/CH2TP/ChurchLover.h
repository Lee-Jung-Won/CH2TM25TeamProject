#pragma once
#include "Monster.h"
#include <string>
#include <random>

class ChurchLover : public Monster
{
public:
	ChurchLover();

	void StartText() override;
	void DeadText() override;

private:
	void setStats();
};