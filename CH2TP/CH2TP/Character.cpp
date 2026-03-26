#include "Character.h"
#include <iostream>
#include <algorithm>
using namespace std;

Character::Character(const string& characterName, bool showMessage) 
{
    name = characterName;
    level = 1;
    maxHealth = 200;
    health = 200;
    attack = 30;
    exp = 0;
    maxExp = 100;
    instance = this;
    gold = 0;

    if (showMessage) 
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

void Character::setattack(int dmgval)
{
    attack = dmgval;
}

int Character::getHealth() const 
{
    return health; 
}


void Character::setHealth(int newhp)
{
    health = newhp;
}
int Character::getLevel() const
{
    return level;
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
    cout << "EXP:    " << exp << " / " << maxExp << endl;
    cout << "GOLD:   " << gold << " G" << endl;
    cout << "============================\n" << endl;

    //add inventory list print
    int cntt = 0;
    for (auto& i : inventory)
    {
        cntt++;
        cout << cntt << ". " << i->getName().rank << "- " << i->getName().name
            << "... " << i->getstore() << endl;
    }
}

Character* Character::getInstance()
{
    return instance;
}

void Character::addhpinventory(Item* it)
{
    for (auto& i : inventory)
    {
        if (i->getName() == it->getName())
        {
            i->setstore(i->getstore() + it->getstore());
            return;
        }
    }
    inventory.push_back(it);

    //sort.....
    sort(inventory.begin(), inventory.end(),
        [](Item* a, Item* b)
        {
            return a->getName() < b->getName();
        }
        );
    //store0 >> delete func

}

void Character::addweaponinventory(Item* it)
{
    if (inventory2.size() == 0)
    {
        it->use(instance);
        inventory2.emplace_back(it);
    }
    // 같은 이름이 있다면 > 등급을 따지고 높으면 해당주소칸 값 덮어쓰기
    for (auto& i : inventory2)
    {
        if (i->getName().name == it->getName().name)
        {
            if (GetRankPriority(i->getName().rank) < GetRankPriority(it->getName().rank))
            {
                i = it;
                i->use(instance);
                return;
            }
        }
    }
}

void Character::useitem(int index)
{
    // inventory of index = in-index
    // character* need... > usefunc need Character*....
    // >inventory[index]->use(character*) >> result : eachclass use-overriding...
    if ((index < 1) || (index > inventory.size()))
    {
        return; // wrong index
    }
    inventory[index - 1]->use(instance);

}

void Character::GainExp(int inExp)//using word inExp for monster's drop exp
{
    exp += inExp;

    cout << "+ " << inExp << " EXP" << endl;

    while (exp >= maxExp)
    {
        exp -= maxExp;

        LevelUp();
        
    }
}

void Character::GainGold(int inGold)
{
    gold += inGold;

    cout << "+ " << inGold << " GOLD" << endl;

}

void Character::LevelUp()
{


    level++;

    maxHealth += 50;

    maxExp += 50;

    health = maxHealth;

    attack += 20;

    cout << "CurrentLevel is " << level << endl;
    
    cout << "For Next Level, You need " << maxExp << "EXP" << endl;


}