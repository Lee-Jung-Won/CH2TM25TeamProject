#pragma once
#include "Monster.h"
#include <string>
#include <random>

class ScreenDoorBreaker : public Monster
{
public:
    ScreenDoorBreaker();

    void StartText() override;
    void DeadText() override;

private:
    void setStats();
};
