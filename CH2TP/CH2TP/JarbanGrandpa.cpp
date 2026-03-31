#include "JarbanGrandpa.h"
#include <iostream>

using namespace std;

JarbanGranpa::JarbanGranpa()
    : Monster("[Lv8]Jarban Granpa", 0, 0, 180, 1200) // 기본 EXP 10, 골드 10
{
    level = 8;      // 레벨 1 고정
    setStats();     // 체력·공격력 랜덤 설정
}

void JarbanGranpa::setStats()
{
    random_device rd;
    mt19937 gen(rd()); // 랜덤함수 엔진

    uniform_int_distribution<> hpDist(level * 175, level * 213);  // 체력 30 ~ 35
    uniform_int_distribution<> atkDist(level * 10, level * 11.3);    // 공격력 5 ~ 7

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void JarbanGranpa::StartText()
{
    cout << "\033[31m[Lv8]Jarban Granpa: Demasia, forever\033[0m" << endl;
}

void JarbanGranpa::DeadText()
{
    cout << "\033[31m[Lv8]Jarban Granpa is DEAD!\033[0m" << endl;
}