#pragma once
#include <string>

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

	Danso* SLDANSO;
	Danso* SSDANSO;
	Danso* SGDANSO;
	Danso* SPDANSO;
	Danso* SDDANSO;

public:
	Shop();
	~Shop();
	void printshoplist();
	void buy(int num, Character& chr);
};

