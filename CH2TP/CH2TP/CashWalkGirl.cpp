#include "CashWalkGirl.h"
#include <iostream>

using namespace std;

CashWalkGirl::CashWalkGirl()
    : Monster("CashWalkGirl", 0, 0, 110, 85) 
{
    level = 6;     
    setStats();    
}

void CashWalkGirl::setStats()
{
    random_device rd;
    mt19937 gen(rd()); 

    uniform_int_distribution<> hpDist(level * 30, level * 35);  
    uniform_int_distribution<> atkDist(level * 5, level * 7);   

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void CashWalkGirl::StartText()
{
    cout << "\033[31mCashWalk Girl: Dumchit, Dumchit\033[0m" << endl;
}

void CashWalkGirl::DeadText()
{
    cout << "\033[31mCashWalk Girl is DEAD!\033[0m" << endl;
}