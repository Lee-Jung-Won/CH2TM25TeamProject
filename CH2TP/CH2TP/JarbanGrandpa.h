#pragma once
#include "Monster.h"
#include <string>
#include <random>

class JarbanGranpa : public Monster
{
public:
    JarbanGranpa();

    void StartText() override;
    void DeadText() override;

private:
    void setStats();
};
