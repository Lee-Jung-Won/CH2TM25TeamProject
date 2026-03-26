#pragma once
#include "Character.h"
#include "Monster.h"
#include <iostream>

class BattleSystem 
{
public:
    static void Battle(Character& player, Monster& monster);
};