#include "ExpPotion.h"
#include "Character.h"
#include "Danso.h"

using namespace std;

int ExpPotion::getstore()
{
    return ExpRestore;
}

void ExpPotion::setstore(int newnum)
{
    ExpRestore = newnum;
}

const Tn& ExpPotion::getName() const
{
    return totalname;
}

void ExpPotion::use(Character* chr)
{
    if (ExpRestore <= 0)
    {
        return;
    }
    ExpRestore--;
    
    if (totalname.rank == "Epic")
    {
        chr->GainExp(30);
    }

    else if (totalname.rank == "Rare")
    {
        chr->GainExp(20);
    }

    else if (totalname.rank == "Normal")
    {
        chr->GainExp(10);
    }

}

int ExpPotion::getprice()
{
    return price;
}