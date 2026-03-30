#pragma once
#include <string>
#include <vector>
class Item;
class HealthPotion;
class Danso;
class Character;
class ExpPotion;

using namespace std;
class Shop
{
private:
	string name;
	int buget;

	HealthPotion* SNHP;
	HealthPotion* SRHP;
	HealthPotion* SEHP;
	ExpPotion* SNEXP;
	ExpPotion* SREXP;
	ExpPotion* SEEXP;

	std::vector<Item*> shopsobiinven;
	//Danso* SLDANSO;
	//Danso* SSDANSO;
	//Danso* SGDANSO;
	//Danso* SPDANSO;
	//Danso* SDDANSO;

public:
	Shop();
	~Shop();
	int openshop(Character& who);
	void buy(int num, Character& chr);
};

