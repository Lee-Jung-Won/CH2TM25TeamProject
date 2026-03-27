#include "BidulgiMaster.h"
#include <iostream>

using namespace std;

BidulgiMaster::BidulgiMaster()
    : Monster("BidulgiMaster", 0, 0, 130, 100) 
{
    level = 7;      
    setStats();     
}

void BidulgiMaster::setStats()
{
    random_device rd;
    mt19937 gen(rd()); 

    uniform_int_distribution<> hpDist(level * 30, level * 35); 
    uniform_int_distribution<> atkDist(level * 5, level * 7);   

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void BidulgiMaster::StartText()
{
    cout << "\033[31mBidulgi Master: 99,,9,,999,,9999,,,\033[0m" << endl;
}

void BidulgiMaster::DeadText()
{
    cout << "\033[31mBidulgi Master is DEAD!\033[0m" << endl;
}