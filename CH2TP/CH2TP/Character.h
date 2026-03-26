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
<<<<<<< HEAD
    Character* instance;
=======
    int gold;
>>>>>>> monster

    //-------------
    vector<Item*> inventory; // supply
    vector<Item*> inventory2; // weapon
public:

    // put name to initialize
    Character* getInstance();
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
    void setHealth(int newhp);

    void ShowStatus() const;

    int getLevel() const;

    void GainExp(int inExp);

    void GainGold(int inGold);

    void LevelUp();

    virtual ~Character() {}
};