#pragma once
#include <string>
#include <vector>
#include "HealthPotion.h"
#include <iostream>
using namespace std;

class Character 
{
private:

    std::string name;
protected:   
    string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int exp;
    const int EXP_PER_LEVEL = 100;

    //-------------
    vector<Item*> inventory;
public:

    // put name to initialize
    Character(std::string characterName);
   
    void addhpinventory(Item* it);
    void useitem(int index);
    //--------------get
    // 
    //--------------set
    // 
    // 
    // show stat

    Character(const string& characterName);

    virtual string getName() const;
    virtual int getAttack() const;
    virtual void takeDamage(const Character& attacker);

    int getHealth() const;

    void ShowStatus() const;
};