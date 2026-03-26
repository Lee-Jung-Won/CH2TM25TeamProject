#pragma once
#include <string>
#include <iostream>
using namespace std;

class Character 
{
protected:   
    string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int exp;
    const int EXP_PER_LEVEL = 100;

public:
    Character(const string& characterName);

    virtual string getName() const;
    virtual int getAttack() const;
    virtual void takeDamage(const Character& attacker);

    int getHealth() const;
    void ShowStatus() const;
};