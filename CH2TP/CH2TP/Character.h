#pragma once
#include <string>
#include <vector>
#include "HealthPotion.h"
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
    int maxExp;
    int gold;

    //-------------
    vector<Item*> inventory;
public:

    // put name to initialize

    void addhpinventory(Item* it);
    void useitem(int index);
    //--------------get
    // 
    //--------------set

    Character(const string& characterName, bool showMessage = true);

    virtual string getName() const;
    virtual int getAttack() const;
    virtual void takeDamage(const Character& attacker);

    int getHealth() const;

    void ShowStatus() const;

    int getLevel() const;

    void GainExp(int inExp);

    void GainGold(int inGold);

    void LevelUp();

    virtual ~Character() {}
};