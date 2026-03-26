#include "Monster.h"

Monster::Monster(const std::string& monsterName, int hp, int atk)
    : Character(monsterName)  
{
    health = hp;
    maxHealth = hp;
    attack = atk;
}