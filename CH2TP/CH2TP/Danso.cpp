#include "Danso.h"
#include "Character.h"

const Tn& Danso::getName() const
{
	return totalname;
}

int Danso::getstore()
{
	return dmg;
}

void Danso::setstore(int newnum)
{
	dmg = newnum;
}

void Danso::use(Character* chr)
{
	chr->setattack(chr->getAttack() + dmg);
}

int Danso::getprice()
{
	return price;
}

int Danso::getupgrade()
{
	return upgrade;
}

void Danso::setupgrade(int newupgrade)
{
	upgrade = newupgrade;
}
