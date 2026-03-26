#pragma once
#include "Monster.h"
#include <string>
#include <random>

class DrunkenOjisang : public Monster 
{
private:
    int level;

public:
    DrunkenOjisang();

    void takeDamage(const Character& attacker) override;
    void StartText() override;
    void DeadText() override;
    void setStat();
};