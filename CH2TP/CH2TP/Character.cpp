#include "Character.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

Character::Character(const string& characterName, bool showMessage) 
{
    name = characterName;
    level = 1;
    maxHealth = 2000;
    health = 200;
    attack = 30;
    exp = 0;
    maxExp = 100;
    instance = this;
    gold = 5000;

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
int Character::getmaxHealth()
{
    return maxHealth;
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
        << attacker.getName() << "! Enemy Remaining HP: " << health << endl;
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
    cout << "============================\n";

    //add inventory list print
    int cntt = 0;
    cout << "----------==========********* INVENTORY *********=========----------" << endl;
    if (inventory.size() > 0)
    {
        for (auto& i : inventory)
        {
            cntt++;
            cout << cntt << ". [" << left << setw(6) << i->getName().rank << "]- " << i->getName().name
                << "... " << i->getstore() << "\t";
            if (cntt % 2 == 0)
            {
                cout << endl;
            }
        }
    }
    else
    {
        cout << "\t\t\t POTION NOTHING HAVE" << endl;
    }
    cout << endl << endl;
    cntt = 0;
    if (inventory2.size() > 0)
    {
        for (auto& i : inventory2)
        {
            cntt++;
            Danso* j = dynamic_cast<Danso*>(i);
            cout << cntt << ". [" << left << setw(6) << j->getName().rank << "]- " << j->getName().name
                << "... [+" << j->getstore() << "Dmg] [+" << j->getupgrade() << "]\t";
            if (cntt % 2 == 0)
            {
                cout << endl;
            }
        }
    }
    else
    {
        cout << "\t\t\t WEAPON NOTHING HAVE" << endl;
    }
    cout << endl;
    cout << "----------==========********* --------- *********=========----------" << endl;
}

void Character::makepotion(Item* getpotion)
{
    //HealthPotion* temp1 = new HealthPotion(getpotion);
    //instance->addhpinventory(temp1);

    for (auto& i : inventory)
    {
        if (i->getName() == getpotion->getName()) //same name
        {
            i->setstore(i->getstore() + getpotion->getstore());
            delete getpotion;
            return;
        }
    }
    //diffent name
    inventory.push_back(getpotion);

    //sort.....
    sort(inventory.begin(), inventory.end(),
        [](Item* a, Item* b)
        {
            return a->getName() < b->getName();
        }
    );

}

void Character::makeweapon(Danso& getweapon)
{
    Danso* temp1 = new Danso(getweapon);

    if (inventory2.size() == 0)
    {
        temp1->use(instance);
        inventory2.emplace_back(temp1);
        return;
    }

    for (auto& i : inventory2)
    {
        if (i->getName().name == temp1->getName().name)
        {
            if (GetRankPriority(i->getName().rank) == GetRankPriority(temp1->getName().rank))
            {
                Danso* temp2 = dynamic_cast<Danso*>(i);
                attack -= temp2->getstore();
                cout << "YOUR WEAPON *ENCHANTED* [" << temp2->getupgrade() << "][+" << temp2->getstore() << "DMG]";
                temp2->setupgrade(temp2->getupgrade() + 1);
                temp2->setstore(temp2->getstore() + 10); // upgrade
                cout << " --->>> [" << temp2->getupgrade() << "][+" << temp2->getstore() << "DMG]";
                temp2->use(instance);
                delete temp1;
                temp1 = nullptr;
            }
            else if (GetRankPriority(i->getName().rank) < GetRankPriority(temp1->getName().rank))
            {
                attack -= i->getstore();
                delete i;
                i = temp1;
                i->use(instance);
                return;
            }
        }
    }
}

Character* Character::getInstance()
{
    return instance;
}

vector<Item*>* Character::getinventory()
{
    return &inventory;
}

vector<Item*>* Character::getwpinventory()
{
    return &inventory2;
}

void Character::addhpinventory(Item* it)
{
    //for (auto& i : inventory)
    //{
    //    if (i->getName() == it->getName()) //same name
    //    {
    //        i->setstore(i->getstore() + it->getstore());
    //        delete it;
    //        return;
    //    }
    //}
    ////diffent name
    //inventory.push_back(it);

    ////sort.....
    //sort(inventory.begin(), inventory.end(),
    //    [](Item* a, Item* b)
    //    {
    //        return a->getName() < b->getName();
    //    }
    //    );
    ////store0 >> delete func

}

void Character::addweaponinventory(Item* it)
{
    //if (inventory2.size() == 0)
    //{
    //    it->use(instance);
    //    inventory2.emplace_back(it);
    //    return;
    //}
    //
    //for (auto& i : inventory2)
    //{
    //    if (i->getName().name == it->getName().name)
    //    {
    //        if (GetRankPriority(i->getName().rank) < GetRankPriority(it->getName().rank))
    //        {
    //            attack -= i->getstore();
    //            delete i;
    //            i = it;
    //            i->use(instance);
    //            return;
    //        }
    //    }
    //}
}

void Character::useitem(int index)
{
    // inventory1 potion use
    if ((index < 1) || (index > inventory.size()))
    {
        return; // wrong index nonfunc
    }
    inventory[index - 1]->use(instance);

    if (inventory[index - 1]->getstore() <= 0)
    {
        delete inventory[index - 1];
        inventory[index - 1] = nullptr;
        auto it = inventory.begin();
        inventory.erase(it + (index - 1));

    }
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

int Character::getGold()
{
    return gold;
}

void Character::setGold(int newGold)
{
    gold = newGold;
}

void Character::LevelUp()
{
    cout << "\033[33m" << R"(
  -----------------------------------------------------------------------------------------
 ก่                                                                                       ก่
 ก่      .____     _______________   _______________.____       ____ _____________  __|__ ก่
 ก่      |    |    \_   _____/\   \ /   /\_   _____/|    |     |    |   \______   \   |   ก่
 ก่      |    |     |    __)_  \   Y   /  |    __)_ |    |     |    |   /|     ___/       ก่
 ก่      |    |___  |        \  \     /   |        \|    |___  |    |  / |    |           ก่
 ก่      |_______ \/_______  /   \___/   /_______  /|_______ \ |______/  |____|           ก่
 ก่              \/        \/                    \/         \/                            ก่
 ก่                                                                                       ก่
  -----------------------------------------------------------------------------------------
    )" << "\033[0m";

    level++;

    maxHealth += 50;

    maxExp += 50;

    health = maxHealth;

    attack += 20;

    cout << "CurrentLevel is " << level << endl;
    
    cout << "For Next Level, You need " << maxExp << "EXP" << endl;


}