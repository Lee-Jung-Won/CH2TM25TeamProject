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
        valuecompare = chr->getHealth() + 100 - chr->getmaxHealth();
        if (valuecompare > 0)
        {
            chr->setHealth(chr->getHealth() + 100 - valuecompare);
            return;
        }
        chr->setHealth(chr->getHealth() + 100);
        return;
    }
    else if(totalname.rank == "Rare")
    {
        int valuecompare = 0;
        valuecompare = chr->getHealth() + 50 - chr->getmaxHealth();
        if (valuecompare > 0)
        {
            chr->setHealth(chr->getHealth() + 50 - valuecompare);
            return;
        }
        chr->setHealth(chr->getHealth() + 50);
        return;
    }
    else if (totalname.rank == "Normal")
    {
        int valuecompare = 0;
        valuecompare = chr->getHealth() + 30 - chr->getmaxHealth();
        if (valuecompare > 0)
        {
            chr->setHealth(chr->getHealth() + 30 - valuecompare);
            return;
        }
        chr->setHealth(chr->getHealth() + 30);
        return;
    }
}

int HealthPotion::getprice()
{
    return price;
}
