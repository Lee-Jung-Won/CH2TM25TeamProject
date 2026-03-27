#pragma once
#include "Monster.h"
#include <string>
#include <random>

class TiredBusinessMan : public Monster
{
public:
    TiredBusinessMan();

    void StartText() override;
    void DeadText() override;

private:
    void setStats();
};