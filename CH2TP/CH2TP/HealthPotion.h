#pragma once
#include "Item.h"

using namespace std;

class HealthPotion: public Item
{
private:
	Tn totalname;
	int healthRestore;
public:
	HealthPotion(int cnt, string r = "C", string n = "HP")
	{
		totalname.name = n;
		totalname.rank = r;
		healthRestore = cnt;
	}
	const Tn& getName() const override;

	int getstore() override;
	void setstore(int newnum);

	void use(Character* chr);

};

