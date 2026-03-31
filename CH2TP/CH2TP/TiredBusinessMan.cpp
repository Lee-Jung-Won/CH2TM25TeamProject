#include "TiredBusinessMan.h"
#include <iostream>

using namespace std;

TiredBusinessMan::TiredBusinessMan()
    : Monster("[Lv7]TiredBusinessMan", 0, 0, 160, 800) // 기본 EXP 10, 골드 10
{
    level = 7;      // 레벨 1 고정
    setStats();     // 체력·공격력 랜덤 설정
}

void TiredBusinessMan::setStats()
{
    random_device rd;
    mt19937 gen(rd()); // 랜덤함수 엔진

    uniform_int_distribution<> hpDist(level * 571, level * 714);
    uniform_int_distribution<> atkDist(level * 10, level * 11.5);   // 공격력 5 ~ 7

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void TiredBusinessMan::StartText()
{
    cout << "\033[31m[Lv7]Tired BusinessMan: Kill me,,\033[0m" << endl;
}

void TiredBusinessMan::DeadText()
{
    cout << "\033[31m[Lv7]Tired BusinessMan is DEAD!\033[0m" << endl;
}