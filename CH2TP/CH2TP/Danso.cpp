#include "Danso.h"
#include "Character.h"

const Tn& Danso::getName() const
{
	return totalname;
}

int Danso::getstore()
{
	return durable;
}

void Danso::setstore(int newnum)
{
	durable = newnum;
}

void Danso::use(Character* chr)
{
	chr->setattack(chr->getAttack() + GetRankPriority(totalname.rank) * 20);

}