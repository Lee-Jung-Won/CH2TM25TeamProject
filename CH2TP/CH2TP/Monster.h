#pragma once
#include "Character.h"

class Monster : public Character 
{
public:
    Monster(const string& monsterName, int hp, int atk);

    virtual void StartText() = 0;
    virtual void DeadText() = 0;
};