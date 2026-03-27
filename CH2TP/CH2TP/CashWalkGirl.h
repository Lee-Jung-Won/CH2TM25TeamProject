#pragma once
#include "Monster.h"
#include <string>
#include <random>


class CashWalkGirl : public Monster
{
public:
    CashWalkGirl();

    void StartText() override;
    void DeadText() override;

private:
    void setStats();
};