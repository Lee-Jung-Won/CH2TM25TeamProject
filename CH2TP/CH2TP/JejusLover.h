#pragma once
#include "Monster.h"
#include <string>
#include <random>


class JejusLover : public Monster
{
public:
    JejusLover();

    void StartText() override;
    void DeadText() override;

private:
    void setStats();
};