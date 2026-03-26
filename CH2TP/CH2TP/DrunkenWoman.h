#pragma once
#include "Monster.h"
#include <string>
#include <random>

class DrunkenWoman : public Monster
{
public:
    DrunkenWoman();

    void StartText() override;
    void DeadText() override;

private:
    void setStats();
};