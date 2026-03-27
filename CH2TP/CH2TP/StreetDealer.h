#pragma once
#include "Monster.h"
#include <string>
#include <random>

class StreetDealer : public Monster
{
public:
    StreetDealer();

    void StartText() override;
    void DeadText() override;

private:
    void setStats();
};