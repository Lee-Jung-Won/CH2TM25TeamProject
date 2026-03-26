#include "HealthPotion.h"
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
}
