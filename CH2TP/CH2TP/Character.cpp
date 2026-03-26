#include "Character.h"

Character::Character(const string& characterName) 
{
    name = characterName;
    level = 1;
    maxHealth = 200;
    health = 200;
    attack = 30;
    exp = 0;

    cout << "Welcome, " << name << "! Your adventure begins." << endl;
}

string Character::getName() const 
{
    return name;
}

int Character::getAttack() const
{
    return attack;
}

int Character::getHealth() const 
{
    return health; 
}

void Character::takeDamage(const Character& attacker)
{
    int damage = attacker.getAttack();
    health -= damage;
    if (health < 0) health = 0;

    cout << name << " takes " << damage << " damage from "
        << attacker.getName() << "! Remaining HP: " << health << endl;
}

void Character::ShowStatus() const 
{
    cout << "\n=== ===\n";
    cout << "Name:   " << name << endl;
    cout << "Level:  " << level << endl;
    cout << "Health: " << health << " / " << maxHealth << endl;
    cout << "Attack: " << attack << endl;
    cout << "EXP:    " << exp << " / " << EXP_PER_LEVEL << endl;
    cout << "============================\n" << endl;
}

