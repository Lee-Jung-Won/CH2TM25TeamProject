#include "CashWalkGirl.h"
#include <iostream>

using namespace std;

CashWalkGirl::CashWalkGirl()
    : Monster("[Lv6]CashWalkGirl", 0, 0, 140, 600) 
{
    level = 6;     
    setStats();    
}

void CashWalkGirl::setStats()
{
    random_device rd;
    mt19937 gen(rd()); 

    uniform_int_distribution<> hpDist(level * 165, level * 200);  
    uniform_int_distribution<> atkDist(level * 11, level * 12);   

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void CashWalkGirl::StartText()
{
    cout << "\033[31m[Lv6]CashWalk Girl: Dumchit, Dumchit\033[0m" << endl;
}

void CashWalkGirl::DeadText()
{
    cout << "\033[31m[Lv6]CashWalk Girl is DEAD!\033[0m" << endl;
}