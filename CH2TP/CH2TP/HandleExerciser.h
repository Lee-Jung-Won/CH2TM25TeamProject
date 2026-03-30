#pragma once

#include "Monster.h"

#include <string>
#include <random>

class HandleExerciser : public Monster
{
public:
	HandleExerciser();

	void StartText() override;
	void DeadText() override;

private:
	void setstats();
};

