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
    //chr hpget, hpset func need
    // hpgetter + each rank have diffenrent value(switch) * 50(exemple)
    // set upline value
    if (totalname.rank == "Epic")
    {
        chr->setHealth(chr->getHealth() + 100);
    }
    else if(totalname.rank == "Rare")
    {
        chr->setHealth(chr->getHealth() + 50);
    }
    else if (totalname.rank == "Normal")
    {
        chr->setHealth(chr->getHealth() + 30);
    }
}
