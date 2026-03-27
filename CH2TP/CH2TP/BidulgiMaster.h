#pragma once
#include "Monster.h"
#include <string>
#include <random>

class BidulgiMaster : public Monster
{
public:
    BidulgiMaster();

    void StartText() override;
    void DeadText() override;

private:
    void setStats();
};