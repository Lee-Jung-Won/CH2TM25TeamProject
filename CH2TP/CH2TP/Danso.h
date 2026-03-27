#pragma once
#include "Item.h"

using namespace std;

class Danso : public Item
{
private:
	Tn totalname;
	int dmg;
public:			// plastic danso 30dmg
	Danso(string r = "Plastic", int setdmg = 30, string n = "Danso")
	{
		totalname.name = n;
		totalname.rank = r;
		dmg = setdmg;
			if (r == "Silver")
			{
				dmg = 50;
			}
			else if (r == "Gold")
			{
				dmg = 70;
			}
			else if (r == "Platinum")
			{
				dmg = 90;
			}
			else if (r == "Diamond")
			{
				dmg = 120;
			}
	}
	const Tn& getName() const override;
	int getstore() override;
	void setstore(int newnum);
	void use(Character* chr);

};

