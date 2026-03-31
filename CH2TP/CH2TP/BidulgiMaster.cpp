#include "BidulgiMaster.h"
#include <iostream>

using namespace std;

BidulgiMaster::BidulgiMaster()
    : Monster("[Lv7]BidulgiMaster", 0, 0, 160, 800) 
{
    level = 7;      
    setStats();     
}

void BidulgiMaster::setStats()
{
    random_device rd;
    mt19937 gen(rd()); 

    uniform_int_distribution<> hpDist(level * 171, level * 200); 
    uniform_int_distribution<> atkDist(level * 10, level * 11.5);   

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void BidulgiMaster::StartText()
{
    cout << "\033[31m[Lv7]Bidulgi Master: 99,,9,,999,,9999,,,\033[0m" << endl;
}

void BidulgiMaster::DeadText()
{
    cout << "\033[31m[Lv7]Bidulgi Master is DEAD!\033[0m" << endl;
}