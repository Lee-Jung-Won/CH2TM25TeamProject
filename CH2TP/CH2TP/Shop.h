#pragma once
#include <string>
#include <vector>
class Item;
class HealthPotion;
class Danso;
class Character;

using namespace std;
class Shop
{
private:
	string name;
	int buget;

	HealthPotion* SNHP;
	HealthPotion* SRHP;
	HealthPotion* SEHP;
	
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

