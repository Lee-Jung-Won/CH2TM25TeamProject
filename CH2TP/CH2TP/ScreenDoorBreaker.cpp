#include "ScreenDoorBreaker.h"
#include <iostream>

using namespace std;

ScreenDoorBreaker::ScreenDoorBreaker()
    : Monster("Drunken Ojisang", 0, 0, 150, 115) // 기본 EXP 10, 골드 10
{
    level = 8;      // 레벨 1 고정
    setStats();     // 체력·공격력 랜덤 설정
}

void ScreenDoorBreaker::setStats()
{
    random_device rd;
    mt19937 gen(rd()); // 랜덤함수 엔진

    uniform_int_distribution<> hpDist(level * 30, level * 35);  // 체력 30 ~ 35
    uniform_int_distribution<> atkDist(level * 5, level * 7);   // 공격력 5 ~ 7

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void ScreenDoorBreaker::StartText()
{
    cout << "\033[31mScreenDoorBreaker: 'Wajangchangchang'\033[0m" << endl;
}

void ScreenDoorBreaker::DeadText()
{
    cout << "\033[31mScreenDoorBreaker is DEAD!\033[0m" << endl;
}