#pragma once
#include <string>
#include <vector>
#include "HealthPotion.h"
#include "Danso.h"
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
    Character* instance;
    int gold;

    //-------------
    vector<Item*> inventory; // supply
    vector<Item*> inventory2; // weapon
public:

    // put name to initialize
    Character* getInstance();
    vector<Item*>* getinventory();
    void addhpinventory(Item* it);
    void addweaponinventory(Item* it);
    void useitem(int index);
    //--------------get
    // 
    //--------------set

    Character(const string& characterName, bool showMessage = true);

    virtual string getName() const;
    virtual int getAttack() const;
    void setattack(int dmgval);
    virtual void takeDamage(const Character& attacker);

    int getHealth() const;
    void setHealth(int newhp);

    int getmaxHealth();

    void ShowStatus() const;

    int getLevel() const;

    void GainExp(int inExp);

    void GainGold(int inGold);
    int getGold();

    void LevelUp();

    virtual ~Character() {}
};