#include "HealthPotion.h"
#include "Character.h"
#include "Danso.h"

using namespace std;

int HealthPotion::getstore()
{
    return healthRestore;
}

void HealthPotion::setstore(int newnum)
{
    healthRestore = newnum;
}

const Tn& HealthPotion::getName() const
{
    return totalname;
}

void HealthPotion::use(Character* chr)
{
    if (healthRestore <= 0)
    {
        return;
    }
    healthRestore--;

    if (totalname.rank == "Epic")
    {
        int valuecompare = 0;
        valuecompare = chr->getHealth() + 200 - chr->getmaxHealth();
        if (valuecompare > 0)
        {
            cout << "[ +" << 200 - valuecompare << "HP ] - [ FULL HP ]" << endl;
            chr->setHealth(chr->getHealth() + 200 - valuecompare);
            return;
        }
        cout << "[ + 200HP ]" << endl;
        chr->setHealth(chr->getHealth() + 200);
        return;
    }
    else if(totalname.rank == "Rare")
    {
        int valuecompare = 0;
        valuecompare = chr->getHealth() + 150 - chr->getmaxHealth();
        if (valuecompare > 0)
        {
            cout << "[ +" << 150 - valuecompare << "HP ] - [ FULL HP ]" << endl;
            chr->setHealth(chr->getHealth() + 150 - valuecompare);
            return;
        }
        cout << "[ + 150HP ]" << endl;
        chr->setHealth(chr->getHealth() + 150);
        return;
    }
    else if (totalname.rank == "Normal")
    {
        int valuecompare = 0;
        valuecompare = chr->getHealth() + 100 - chr->getmaxHealth();
        if (valuecompare > 0)
        {
            cout << "[ +" << 100 - valuecompare << "HP ] - [ FULL HP ]" << endl;
            chr->setHealth(chr->getHealth() + 100 - valuecompare);
            return;
        }
        cout << "[ + 100HP ]" << endl;
        chr->setHealth(chr->getHealth() + 100);
        return;
    }
}

int HealthPotion::getprice()
{
    return price;
}
