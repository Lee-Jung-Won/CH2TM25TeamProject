#pragma once
#include "Item.h"

using namespace std;

class Danso : public Item
{
private:
	Tn totalname;
	int durable;
public:			// plastic danso 30dmg
	Danso(int setdurable = 30, string r = "Plastic", string n = "Danso")
	{
		totalname.name = n;
		totalname.rank = r;
		durable = setdurable;
	}
	const Tn& getName() const override;
	int getstore() override;
	void setstore(int newnum);
	void use(Character* chr);

};

