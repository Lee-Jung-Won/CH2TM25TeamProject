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

void Shop::printshoplist()
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
	cout << "PlayerMoney : ";
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
		if (chr.getGold() >= 0)//
		{
			// 인벤토리에서 중복 찾기 후 중복이면 addinven후 delete
			//                 찾기 후 단일이면 addinven후 temp로 new할당 매개변수 대입
			for (auto& i : *(chr.getinventory()))
			{
				if (i->getName() == SNHP->getName()) //same name
				{
					i->setstore(i->getstore() + 1);
					return;
				}
			}
			//같은거 못찾았다
			HealthPotion* temp = new HealthPotion(1, "Noraml");
			chr.addhpinventory(temp);

			return;
		}
		cout << "Not enough Money" << endl;
		return;
	}
}
