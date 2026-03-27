#pragma once
#include "Item.h"

using namespace std;

class Danso : public Item
{
private:
	Tn totalname;
	int dmg;
	int price;
public:			// plastic danso 30dmg
	Danso(string r = "Plastic", int setdmg = 30, string n = "Danso")
	{
		totalname.name = n;
		totalname.rank = r;
		dmg = setdmg;
		price = 100;
			if (r == "Silver")
			{
				dmg = 50;
				price = 200;
			}
			else if (r == "Gold")
			{
				dmg = 70;
				price = 300;
			}
			else if (r == "Platinum")
			{
				dmg = 90;
				price = 400;
			}
			else if (r == "Diamond")
			{
				dmg = 120;
				price = 500;
			}
	}
	const Tn& getName() const override;
	int getstore() override;
	void setstore(int newnum);
	void use(Character* chr);
	int getprice() override;
};

