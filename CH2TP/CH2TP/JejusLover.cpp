#include "JejusLover.h"
#include <iostream>

using namespace std;

JejusLover::JejusLover()
    : Monster("[Lv5]Jejus Lover", 0, 0, 120, 400) // 기본 EXP 10, 골드 10
{
    level = 5;      // 레벨 1 고정
    setStats();     // 체력·공격력 랜덤 설정
}

void JejusLover::setStats()
{
    random_device rd;
    mt19937 gen(rd()); // 랜덤함수 엔진

    uniform_int_distribution<> hpDist(level * 200, level * 300);  // 체력 30 ~ 35
    uniform_int_distribution<> atkDist(level * 11, level * 13);   // 공격력 5 ~ 7

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void JejusLover::StartText()
{
    cout << "\033[31m[Lv5]JejusLover: Jejus Christ AAAAAmen-.\033[0m" << endl;
}

void JejusLover::DeadText()
{
    cout << "\033[31m[Lv5]JejusLover is DEAD!\033[0m" << endl;
}