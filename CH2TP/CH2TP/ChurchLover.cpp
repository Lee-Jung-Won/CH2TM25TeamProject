#include "ChurchLover.h"
#include <iostream>

using namespace std;

ChurchLover::ChurchLover()
    : Monster("[Lv5]Church Lover", 0, 0, 120, 400) // 기본 EXP 10, 골드 10
{
    level = 5;      // 레벨 1 고정
    setStats();     // 체력·공격력 랜덤 설정
}

void ChurchLover::setStats()
{
    random_device rd;
    mt19937 gen(rd()); // 랜덤함수 엔진

    uniform_int_distribution<> hpDist(level * 150, level * 200);  // 체력 30 ~ 35
    uniform_int_distribution<> atkDist(level * 11, level * 13);   // 공격력 5 ~ 7

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void ChurchLover::StartText()
{
    cout << "\033[31m[Lv5]ChurchLover: Go Church. Go Heaven.\033[0m" << endl;
}

void ChurchLover::DeadText()
{
    cout << "\033[31m[Lv5]ChurchLover is DEAD!\033[0m" << endl;
}