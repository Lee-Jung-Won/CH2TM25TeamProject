#include "StreetDealer.h"
#include <iostream>

using namespace std;

StreetDealer::StreetDealer()
    : Monster("[Lv6]Drunken Ojisang", 0, 0, 140, 600) // 기본 EXP 10, 골드 10
{
    level = 6;      // 레벨 1 고정
    setStats();     // 체력·공격력 랜덤 설정
}

void StreetDealer::setStats()
{
    random_device rd;
    mt19937 gen(rd()); // 랜덤함수 엔진

    uniform_int_distribution<> hpDist(level * 165, level * 200);
    uniform_int_distribution<> atkDist(level * 11, level * 12);    // 공격력 5 ~ 7

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void StreetDealer::StartText()
{
    cout << "\033[31m[Lv6]StreetDealer: Buy it. Only Cash\033[0m" << endl;
}

void StreetDealer::DeadText()
{
    cout << "\033[31m[Lv6]StreetDealer is DEAD!\033[0m" << endl;
}