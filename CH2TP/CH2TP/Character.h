#pragma once
#include <string>
#include <vector>
#include "HealthPotion.h"
using namespace std;

class Character
{
private:

    std::string name;
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
    void ShowStatus() const;
};

