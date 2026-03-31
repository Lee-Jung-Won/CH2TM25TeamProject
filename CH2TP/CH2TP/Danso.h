#pragma once
#include "Item.h"

using namespace std;

class Danso : public Item
{
private:
	Tn totalname;
	int dmg;
	int price;
	int upgrade;
public:			// plastic danso 30dmg
	Danso(string r = "Plastic", int setdmg = 30, string n = "Danso")
	{
		totalname.name = n;
		totalname.rank = r;
		dmg = setdmg;
		price = 150;
		upgrade = 0;
			if (r == "Silver")
			{
				dmg = 60;
				price = 300;
			}
			else if (r == "Gold")
			{
				dmg = 120;
				price = 500;
			}
			else if (r == "Platinum")
			{
				dmg = 200;
				price = 750;
			}
			else if (r == "Diamond")
			{
				dmg = 300;
				price = 1000;
			}
	}
	const Tn& getName() const override;
	int getstore() override;
	void setstore(int newnum);
	void use(Character* chr);
	int getprice() override;
	int getupgrade();
	void setupgrade(int newupgrade);
};

