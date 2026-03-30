#pragma once
#include "Item.h"

using namespace std;

class HealthPotion: public Item
{
private:
	Tn totalname;
	int healthRestore;
	int price;
public:
	HealthPotion(int cnt, string r = "Normal", string n = "HP")
	{
		totalname.name = n;
		totalname.rank = r;
		healthRestore = cnt;
		price = 50;
		if (r == "Rare")
		{
			price = 100;
		}
		else if (r == "Epic")
		{
			price = 150;
		}
	}
	const Tn& getName() const override;

	int getstore() override;
	void setstore(int newnum);
	void use(Character* chr);
	int getprice() override;
};

