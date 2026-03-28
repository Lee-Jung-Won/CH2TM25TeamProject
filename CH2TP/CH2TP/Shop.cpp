#include "Shop.h"
#include <iostream>
#include "Character.h"

Shop::Shop()
{
	name = "SHOP";
	buget = 0;

	SNHP = new HealthPotion(1, "Normal");
	SRHP = new HealthPotion(1, "Rare");
	SEHP = new HealthPotion(1, "Epic");

	SLDANSO = new Danso("Plastic");
	SSDANSO = new Danso("Silver");
	SGDANSO = new Danso("Gold");
	SPDANSO = new Danso("Platinum");
	SDDANSO = new Danso("Diamond");

}

Shop::~Shop()
{

}

void Shop::openshop(Character& who)
{
	cout << "================---" << name << "---================" << endl;
	cout << "-     " << "1. Normal-HP potion:  50G" << endl;
	cout << "-     " << "2. Rare  -HP potion: 100G" << endl;
	cout << "-     " << "3. Epic  -HP potion: 150G" << endl;
	cout << "==================================" << endl;
	cout << "-     " << "4. Plastic -Danso:  100G" << endl;
	cout << "-     " << "5. Silver  -Danso:  200G" << endl;
	cout << "-     " << "6. Gold    -Danso:  300G" << endl;
	cout << "-     " << "7. Platinum-Danso:  400G" << endl;
	cout << "-     " << "8. Diamond -Danso:  500G" << endl;
	cout << "==================================" << endl;
	cout << "MoneyYouHave : " << who.getGold() << "G" << endl;
}

void Shop::buy(int num, Character& chr)
{
	// 주소 addinventory하고 매개변수에 다시 new할당
	// 이러면 객체하나로 커버치는게 가능하지싶은데 문제가 중복아이템이 있어서
	// 값만 넘겨주는 상황에서 매개변수에 다시 new할당하면 메모리닉남
	// 같은게 있나없나 확인하고 있으면 넘기고 delete
	// 없으면 addinventory

	if (num == 1)
	{
		if (chr.getGold() >= 50)//
		{
			// 인벤토리에서 중복 찾기 후 중복이면 addinven후 delete
			//                 찾기 후 단일이면 addinven후 temp로 new할당 매개변수 대입
			for (auto& i : *(chr.getinventory()))
			{
				if (i->getName() == SNHP->getName()) //same name
				{
					i->setstore(i->getstore() + 1);
					// --money
					chr.setGold(chr.getGold() - 50);
					return;
				}
			}
			//같은거 못찾았다
			HealthPotion* temp = new HealthPotion(1, "Normal");
			chr.addhpinventory(temp);
			chr.setGold(chr.getGold() - 50);
			return;
		}
		cout << "Not enough Money" << endl;
		return;
	}
	else if (num == 2)
	{
		if (chr.getGold() >= 100)//
		{
			// 인벤토리에서 중복 찾기 후 중복이면 addinven후 delete
			//                 찾기 후 단일이면 addinven후 temp로 new할당 매개변수 대입
			for (auto& i : *(chr.getinventory()))
			{
				if (i->getName() == SRHP->getName()) //same name
				{
					i->setstore(i->getstore() + 1);
					// --money
					chr.setGold(chr.getGold() - 100);
					return;
				}
			}
			//같은거 못찾았다
			HealthPotion* temp = new HealthPotion(1, "Rare");
			chr.addhpinventory(temp);
			chr.setGold(chr.getGold() - 100);
			return;
		}
		cout << "Not enough Money" << endl;
		return;
	}
	else if (num == 3)
	{
		if (chr.getGold() >= 150)//
		{
			// 인벤토리에서 중복 찾기 후 중복이면 addinven후 delete
			//                 찾기 후 단일이면 addinven후 temp로 new할당 매개변수 대입
			for (auto& i : *(chr.getinventory()))
			{
				if (i->getName() == SEHP->getName()) //same name
				{
					i->setstore(i->getstore() + 1);
					// --money
					chr.setGold(chr.getGold() - 150);
					return;
				}
			}
			//같은거 못찾았다
			HealthPotion* temp = new HealthPotion(1, "Epic");
			chr.addhpinventory(temp);
			chr.setGold(chr.getGold() - 150);
			return;
		}
		cout << "Not enough Money" << endl;
		return;
	}
	else if (num == 4)
	{
		if (chr.getGold() >= 100)//
		{
			// --money
			chr.setGold(chr.getGold() - 100);
			Danso* temp = new Danso("Plastic");
			chr.addweaponinventory(temp);
			return;
		}
		cout << "Not enough Money" << endl;
		return;
	}
	else if (num == 5)
	{
		if (chr.getGold() >= 200)//
		{
			// --money
			chr.setGold(chr.getGold() - 200);
			Danso* temp = new Danso("Silver");
			chr.addweaponinventory(temp);
			return;
		}
		cout << "Not enough Money" << endl;
		return;
	}
	else if (num == 6)
	{
		if (chr.getGold() >= 300)//
		{
			// --money
			chr.setGold(chr.getGold() - 300);
			Danso* temp = new Danso("Gold");
			chr.addweaponinventory(temp);
			return;
		}
		cout << "Not enough Money" << endl;
		return;
	}
	else if (num == 7)
	{
		if (chr.getGold() >= 400)//
		{
			// --money
			chr.setGold(chr.getGold() - 400);
			Danso* temp = new Danso("Platinum");
			chr.addweaponinventory(temp);
			return;
		}
		cout << "Not enough Money" << endl;
		return;
	}
	else if (num == 8)
	{
		if (chr.getGold() >= 500)//
		{
			// --money
			chr.setGold(chr.getGold() - 500);
			Danso* temp = new Danso("Diamond");
			chr.addweaponinventory(temp);
			return;
		}
		cout << "Not enough Money" << endl;
		return;
	}
	else
	{
		cout << "Wrong Number" << endl;
		return;
	}
}
