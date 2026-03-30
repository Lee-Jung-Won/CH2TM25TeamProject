#pragma once
#include "Character.h"

using namespace std;

class Monster : public Character
{
protected:
    int rewardExp;   // Monster Dead EXP
    int rewardGold;  // Monster Dead Gold

public:
    Monster(const string& monsterName, int hp, int atk, int exp, int gold);

    virtual void StartText() = 0;
    
    virtual void DeadText() = 0;


    int getRewardExp() const;
    int getRewardGold() const;

    bool canAppear(int playerLevel) const;

    virtual void BattleText() {}

    virtual ~Monster() {}
};