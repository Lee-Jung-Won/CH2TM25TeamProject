#include "DrunkenWoman.h"
#include <iostream>

using namespace std;

DrunkenWoman::DrunkenWoman()
    : Monster("Drunken Woman", 0, 0, 12, 12) // 기본 EXP 12, 골드 12
{ 
    level = 1;  // 레벨 1 고정
    setStats(); // 체력과 공격력을 랜덤으로 설정
}

void DrunkenWoman::setStats()
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> hpDist(level * 30, level * 40);  // 체력 30 ~ 40 사이
    uniform_int_distribution<> atkDist(level * 5, level * 8);   // 공격력 5 ~ 8 사이

    health = hpDist(gen);
    maxHealth = health;
    attack = atkDist(gen);
}

void DrunkenWoman::StartText()
{
    cout << "\033[31mDrunken Woman: jagiya yogi odiya?\033[0m" << endl;
}

void DrunkenWoman::DeadText()
{
    cout << "\033[31mDrunken Woman is DEAD!\033[0m" << endl;
}