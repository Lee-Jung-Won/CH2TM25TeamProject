#include "JejusLover.h"
#include <iostream>

using namespace std;

JejusLover::JejusLover()
    : Monster("Jejus Lover", 0, 0, 10, 10) // 기본 EXP 10, 골드 10
{
    level = 1;      // 레벨 1 고정
    setStats();     // 체력·공격력 랜덤 설정
}

void JejusLover::setStats()
{
    random_device rd;
    mt19937 gen(rd()); // 랜덤함수 엔진

    uniform_int_distribution<> hpDist(level * 30, level * 35);  // 체력 30 ~ 35
    uniform_int_distribution<> atkDist(level * 5, level * 7);   // 공격력 5 ~ 7

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void JejusLover::StartText()
{
    cout << "\033[31mJejusLover: Jejus Christ Amen-.\033[0m" << endl;
}

void JejusLover::DeadText()
{
    cout << "\033[31mJejusLover is DEAD!\033[0m" << endl;
}