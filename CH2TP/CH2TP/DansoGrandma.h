#pragma once

#include "Monster.h"

#include <string>
#include <random>

class DansoGrandma : public Monster
{
public:
	DansoGrandma();

	void StartText() override;
	void DeadText() override;

private:
	void setstats();
};

