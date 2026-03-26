#include "Character.h"
#include <iostream>
#include <algorithm>

using namespace std;

// 넘어온 이름으로 캐릭터 초기 스탯 설정
Character::Character(string characterName) {
    name = characterName;   // 캐릭터 이름
    level = 1;              // 레벨
    maxHealth = 200;        // 최대 체력
    health = 200;           // 체력
    attack = 30;            // 공격력
    exp = 0;                // 경험치

    cout << "Welcome, " << name << "! Your adventure begins." << endl;
}

// print func
void Character::ShowStatus() const {
    cout << "\n=== ===" << endl;
    cout << "Name:   " << name << endl;
    cout << "Level:  " << level << endl;
    cout << "Health: " << health << " / " << maxHealth << endl;
    cout << "Attack: " << attack << endl;
    cout << "EXP:    " << exp << " / " << EXP_PER_LEVEL << endl;
    cout << "============================\n" << endl;
    //add inventory list print
    for (auto& i : inventory)
    {
        cout << i->getName().rank << "- " << i->getName().name
            << "... " << i->getstore() << endl;
    }
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
}

void Character::useitem(int index)
{
    // inventory of index = in-index
    // character* need... > usefunc need Character*....
    // >inventory[index]->use(character*) >> result : eachclass use-overriding...
}
