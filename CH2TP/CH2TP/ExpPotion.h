#pragma once
#include "Item.h"

class ExpPotion: public Item
{
private:
	Tn totalname;
	int ExpRestore;
	int price;
public:
	ExpPotion(int cnt, string r = "Normal", string n = "EXP")
	{
		totalname.name = n;
		totalname.rank = r;
		ExpRestore = cnt;
		price = 20;
		if (r == "Rare")
		{
			price = 40;
		}
		else if (r == "Epic")
		{
			price = 60;
		}
	}
	const Tn& getName() const override;
	void use(Character* chr) override;
	int getstore() override;
	void setstore(int newnum) override;
	int getprice() override;
};

