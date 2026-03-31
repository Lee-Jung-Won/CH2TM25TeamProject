#include "DrunkenOjisang.h"
#include <iostream>

using namespace std;

DrunkenOjisang::DrunkenOjisang()
    : Monster("[LV1]Drunken Ojisang", 0, 0, 40, 100) // 기본 EXP 10, 골드 10
{
    level = 1;      // 레벨 1 고정
    setStats();     // 체력·공격력 랜덤 설정
}

void DrunkenOjisang::setStats()
{
    random_device rd;
    mt19937 gen(rd()); // 랜덤함수 엔진

    uniform_int_distribution<> hpDist(level * 150, level * 250);  // 체력 30 ~ 35
    uniform_int_distribution<> atkDist(level * 15, level * 25);   // 공격력 5 ~ 7

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void DrunkenOjisang::StartText()
{
    cout << "\033[31m[LV1]Drunken Ojisang: Soju the gatgowa!!\033[0m" << endl;
}

void DrunkenOjisang::DeadText()
{
    cout << "\033[31m[LV1]Drunken Ojisang is DEAD!\033[0m" << endl;
}