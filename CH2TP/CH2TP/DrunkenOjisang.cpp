#include "DrunkenOjisang.h"
#include <iostream>

using namespace std;

DrunkenOjisang::DrunkenOjisang() : Monster("DrunkenOjisang", 0, 0) 
{
    level = 1;
    setStat();
}

void DrunkenOjisang::takeDamage(const Character& attacker) 
{
    int damage = attacker.getAttack();
    health -= damage;
    if (health < 0) health = 0;

    cout << name << " takes " << damage << " damage from "
        << attacker.getName() << "! Remaining HP: " << health << endl;
}

void DrunkenOjisang::StartText() 
{
    cout << "\033[31m" << "soju the gatgowa!!" << "\033[0m" << endl;
}

void DrunkenOjisang::DeadText() 
{
    cout << name << " DEAD" << endl << "\033[31m" << "deri yogi..." << "\033[0m" << endl;
}

void DrunkenOjisang::setStat() 
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> healthDist(level * 30, level * 35);
    uniform_int_distribution<> attackDist(level * 5, level * 7);

    health = healthDist(gen);
    attack = attackDist(gen);
}