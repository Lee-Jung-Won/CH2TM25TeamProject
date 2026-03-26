#include "Monster.h"
#include "Character.h"

using namespace std;

Monster::Monster(const string& monsterName, int hp, int atk, int exp, int gold)
    : Character(monsterName, false)  
{
    health = hp;
    maxHealth = hp;
    attack = atk;

    rewardExp = exp;
    rewardGold = gold;
}

int Monster::getRewardExp() const
{
    return rewardExp;
}

int Monster::getRewardGold() const
{
    return rewardGold;
}

bool Monster::canAppear(int playerLevel) const
{
    return level <= playerLevel;
}