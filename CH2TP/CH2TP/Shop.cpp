#include "Shop.h"
#include <iostream>
#include "Character.h"
#include <Windows.h>
#include <iomanip>
static int chosenum = 0;
Shop::Shop()
{
	name = "SHOP";
	buget = 0;

	SNHP = new HealthPotion(10, "Normal");
	SRHP = new HealthPotion(10, "Rare");
	SEHP = new HealthPotion(10, "Epic");

	shopsobiinven.push_back(SNHP);
	shopsobiinven.push_back(SRHP);
	shopsobiinven.push_back(SEHP);
	//SLDANSO = new Danso("Plastic");
	//SSDANSO = new Danso("Silver");
	//SGDANSO = new Danso("Gold");
	//SPDANSO = new Danso("Platinum");
	//SDDANSO = new Danso("Diamond");

}

Shop::~Shop()
{
	if (SNHP != nullptr)
	{
		delete SNHP;
		SNHP = nullptr;
	}
	if (SRHP != nullptr)
	{
		delete SRHP;
		SRHP = nullptr;
	}
	if (SEHP != nullptr)
	{
		delete SEHP;
		SEHP = nullptr;
	}
}

int Shop::openshop(Character& who)
{
	cout << endl;
	cout << "=======================================================================================" << endl;
	cout << "=======================================================================================" << endl;
	cout << "================      =========   ======   =======       ========            ==========" << endl;
	cout << "=============   ======   ======   ======   =====   =====   ======   ======   ==========" << endl;
	cout << "=============   ======   ======   ======   =====   =====   =====   =======   ==========" << endl;
	cout << "=============   =======  =====   ======   =====   =====   ======   ======   ===========" << endl;
	cout << "===============    ===========   ======   =====   =====   =====   ======   ============" << endl;
	cout << "===================   ========            ====   =====   ======          ==============" << endl;
	cout << "=====================   ======   ======   ====   =====   =====   ======================" << endl;
	cout << "=============  ======   =====   ======   ====   =====   ======   ======================" << endl;
	cout << "============   ======   =====   ======   ====   =====   =====   =======================" << endl;
	cout << "============   ====   ======   ======   =====   ====   ======   =======================" << endl;
	cout << "===============      =======   ======   ======        ======   ========================" << endl;
	cout << "=======================================================================================" << endl;
	cout << "=======================================================================================" << endl;
	cout << "<<<<<<<<<<<<< 1. Potion Store            3.Out           2. Weapon Store >>>>>>>>>>>>>>" << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;
		//cout << "-     " << "1. Normal-HP potion:  50G" << endl;
	//cout << "-     " << "2. Rare  -HP potion: 100G" << endl;
	//cout << "-     " << "3. Epic  -HP potion: 150G" << endl;
	//cout << "==================================" << endl;
	//cout << "-     " << "4. Plastic -Danso:  100G" << endl;
	//cout << "-     " << "5. Silver  -Danso:  200G" << endl;
	//cout << "-     " << "6. Gold    -Danso:  300G" << endl;
	//cout << "-     " << "7. Platinum-Danso:  400G" << endl;
	//cout << "-     " << "8. Diamond -Danso:  500G" << endl;
	//cout << "==================================" << endl;
	cout << "MoneyYouHave : " << who.getGold() << "G" << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;

	cout << "Choose number you want to go... : ";
	cin >> chosenum;
	system("CLS");
	if (chosenum == 1)
	{
		cout << "=======================================================================================" << endl;
		cout << "===========================------------------------------==============================" << endl;
		cout << "======================== <<  Potion               Store  >> ===========================" << endl;
		cout << "=============================------------------------------============================" << endl;
		cout << "==========                1. HP-Potion(Normal) ::  " << shopsobiinven[0]->getprice() << "G...(" << shopsobiinven[0]->getstore() << ")                ==========" << endl;
		cout << "=======================================================================================" << endl;
		cout << "==========                2. HP-Potion( Rare ) :: " << shopsobiinven[1]->getprice() << "G...(" << shopsobiinven[1]->getstore() << ")                ==========" << endl;
		cout << "=======================================================================================" << endl;
		cout << "==========                3. HP-Potion( Epic ) :: " << shopsobiinven[2]->getprice() << "G...(" << shopsobiinven[2]->getstore() << ")                ==========" << endl;
		cout << "=======================================================================================" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "MoneyYouHave : " << who.getGold() << "G" << "                                                           0. Back" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;

	}
	else if (chosenum == 2)
	{
		cout << "=======================================================================================" << endl;
		cout << "=============================------------------------------============================" << endl;
		cout << "========================== <<  Danso_               Store  >> =========================" << endl;
		cout << "=============================------------------------------============================" << endl;
		cout << "=======                    1. Plastic Danso :: 100G (+30dmg)                    =======" << endl;
		cout << "=======================================================================================" << endl;
		cout << "=======                    2. Silver  Danso :: 200G (+60dmg)                    =======" << endl;
		cout << "=======================================================================================" << endl;
		cout << "=======                    3. Gold    Danso :: 300G (+120dmg)                   =======" << endl;
		cout << "=======================================================================================" << endl;
		cout << "=======                    4. Platinu Danso :: 400G (+200dmg)                   =======" << endl;
		cout << "=======================================================================================" << endl;
		cout << "=======                    5. Diamond Danso :: 500G (+300dmg)                   =======" << endl;
		cout << "=======================================================================================" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "MoneyYouHave : " << who.getGold() << "G" << "                                                           0. Back" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;

	}
	else
	{
		cout << "=======================================================================================" << endl;
		cout << "=========================   =======   =======   =======   =============================" << endl;
		cout << "========================= E ======= X ======= I ======= T =============================" << endl;
		cout << "=========================   =======   =======   =======   =============================" << endl;
		cout << "=======================================================================================" << endl;
		cout << endl;
		chosenum = 3;

		int cntt = 0;
		cout << "----------==========********* INVENTORY *********=========----------" << endl;
		for (auto& i : *(who.getinventory()))
		{
			cntt++;
			cout << cntt << ". [" << left << setw(6) << i->getName().rank << "]- " << i->getName().name
				<< "... " << i->getstore() << "\t";
			if (cntt % 2 == 0)
			{
				cout << endl;
			}
		}
		cout << endl;
		cout << "----------==========********* --------- *********=========----------" << endl;

	}
	return chosenum;
}

void Shop::buy(int num, Character& chr)
{
	// 주소 addinventory하고 매개변수에 다시 new할당
	// 이러면 객체하나로 커버치는게 가능하지싶은데 문제가 중복아이템이 있어서
	// 값만 넘겨주는 상황에서 매개변수에 다시 new할당하면 메모리닉남
	// 같은게 있나없나 확인하고 있으면 넘기고 delete
	// 없으면 addinventory
	switch (chosenum)
	{
	case 1: // potionstore
	{
			int many = 1;
			cout << "How Many you Want :: ";
			cin >> many;
			if (num == 1)
			{

				// 몇개를 사시겠습니까? 변수....> 1자리에 변수넣으면되고...
				HealthPotion prehp(many, "Normal");
				if (chr.getGold() >= (prehp.getprice() * many))
				{
					chr.makepotion(prehp);
					chr.setGold(chr.getGold() - many * prehp.getprice());
					shopsobiinven[0]->setstore(shopsobiinven[0]->getstore() - many);
				}
				else
				{
					cout << "Not Enough Money" << endl;
				}
				break;
			}
			else if (num == 2)
			{
				// 몇개를 사시겠습니까? 변수....> 1자리에 변수넣으면되고...
				HealthPotion prehp(many, "Rare");
				if (chr.getGold() >= (prehp.getprice() * many))
				{
					chr.makepotion(prehp);
					chr.setGold(chr.getGold() - many * prehp.getprice());
					shopsobiinven[1]->setstore(shopsobiinven[1]->getstore() - many);
				}
				else
				{
					cout << "Not Enough Money" << endl;
				}
				break;
			}
			else if (num == 3)
			{
				// 몇개를 사시겠습니까? 변수....> 1자리에 변수넣으면되고...
				HealthPotion prehp(many, "Epic");
				if (chr.getGold() >= (prehp.getprice() * many))
				{
					chr.makepotion(prehp);
					chr.setGold(chr.getGold() - many * prehp.getprice());
					shopsobiinven[2]->setstore(shopsobiinven[2]->getstore() - many);
				}
				else
				{
					cout << "Not Enough Money" << endl;
				}
				break;
			}
			else
			{
				cout << "Wrong Number" << endl;
			}
	}
	case 2: // dansostore
		if (num == 1)
		{
			Danso prewp("Plastic");
			if (chr.getGold() >= prewp.getprice())
			{
				chr.makeweapon(prewp);
				chr.setGold(chr.getGold() - prewp.getprice());
			}
			else
			{
				cout << "Not Enough Money" << endl;
			}
		}
		else if (num == 2)
		{
			Danso prewp("Silver");
			if (chr.getGold() >= prewp.getprice())
			{
				chr.makeweapon(prewp);
				chr.setGold(chr.getGold() - prewp.getprice());
			}
			else
			{
				cout << "Not Enough Money" << endl;
			}
		}
		else if (num == 3)
		{
			Danso prewp("Gold");
			if (chr.getGold() >= prewp.getprice())
			{
				chr.makeweapon(prewp);
				chr.setGold(chr.getGold() - prewp.getprice());
			}
			else
			{
				cout << "Not Enough Money" << endl;
			}
		}
		else if (num == 4)
		{
			Danso prewp("Platinum");
			if (chr.getGold() >= prewp.getprice())
			{
				chr.makeweapon(prewp);
				chr.setGold(chr.getGold() - prewp.getprice());
			}
			else
			{
				cout << "Not Enough Money" << endl;
			}
		}
		else if (num == 5)
		{
			Danso prewp("Diamond");
			if (chr.getGold() >= prewp.getprice())
			{
				chr.makeweapon(prewp);
				chr.setGold(chr.getGold() - prewp.getprice());
			}
			else
			{
				cout << "Not Enough Money" << endl;
			}
		}
		else
		{
			cout << "Wrong Number" << endl;
		}
		break;
	default:

		break;
	}
	//if (num == 1)
	//{


	//	//if (chr.getGold() >= 50)//
	//	//{
	//	//	// 인벤토리에서 중복 찾기 후 중복이면 addinven후 delete
	//	//	//                 찾기 후 단일이면 addinven후 temp로 new할당 매개변수 대입
	//	//	for (auto& i : *(chr.getinventory()))
	//	//	{
	//	//		if (i->getName() == SNHP->getName()) //same name
	//	//		{
	//	//			i->setstore(i->getstore() + 1);
	//	//			// --money
	//	//			chr.setGold(chr.getGold() - 50);
	//	//			return;
	//	//		}
	//	//	}
	//	//	//같은거 못찾았다
	//	//	HealthPotion* temp = new HealthPotion(1, "Normal");
	//	//	chr.addhpinventory(temp);
	//	//	chr.setGold(chr.getGold() - 50);
	//	//	return;
	//	//}
	//	//cout << "Not enough Money" << endl;
	//	//return;
	//}
	//else if (num == 2)
	//{
	//	if (chr.getGold() >= 100)//
	//	{
	//		// 인벤토리에서 중복 찾기 후 중복이면 addinven후 delete
	//		//                 찾기 후 단일이면 addinven후 temp로 new할당 매개변수 대입
	//		for (auto& i : *(chr.getinventory()))
	//		{
	//			if (i->getName() == SRHP->getName()) //same name
	//			{
	//				i->setstore(i->getstore() + 1);
	//				// --money
	//				chr.setGold(chr.getGold() - 100);
	//				return;
	//			}
	//		}
	//		//같은거 못찾았다
	//		HealthPotion* temp = new HealthPotion(1, "Rare");
	//		chr.addhpinventory(temp);
	//		chr.setGold(chr.getGold() - 100);
	//		return;
	//	}
	//	cout << "Not enough Money" << endl;
	//	return;
	//}
	//else if (num == 3)
	//{
	//	if (chr.getGold() >= 150)//
	//	{
	//		// 인벤토리에서 중복 찾기 후 중복이면 addinven후 delete
	//		//                 찾기 후 단일이면 addinven후 temp로 new할당 매개변수 대입
	//		for (auto& i : *(chr.getinventory()))
	//		{
	//			if (i->getName() == SEHP->getName()) //same name
	//			{
	//				i->setstore(i->getstore() + 1);
	//				// --money
	//				chr.setGold(chr.getGold() - 150);
	//				return;
	//			}
	//		}
	//		//같은거 못찾았다
	//		HealthPotion* temp = new HealthPotion(1, "Epic");
	//		chr.addhpinventory(temp);
	//		chr.setGold(chr.getGold() - 150);
	//		return;
	//	}
	//	cout << "Not enough Money" << endl;
	//	return;
	//}
	 
	 

//	if (num == 4)
//	{
//		if (chr.getGold() >= 100)//
//		{
//			// --money
//			chr.setGold(chr.getGold() - 100);
//			Danso* temp = new Danso("Plastic");
//			chr.addweaponinventory(temp);
//			return;
//		}
//		cout << "Not enough Money" << endl;
//		return;
//	}
//	else if (num == 5)
//	{
//		if (chr.getGold() >= 200)//
//		{
//			// --money
//			chr.setGold(chr.getGold() - 200);
//			Danso* temp = new Danso("Silver");
//			chr.addweaponinventory(temp);
//			return;
//		}
//		cout << "Not enough Money" << endl;
//		return;
//	}
//	else if (num == 6)
//	{
//		if (chr.getGold() >= 300)//
//		{
//			// --money
//			chr.setGold(chr.getGold() - 300);
//			Danso* temp = new Danso("Gold");
//			chr.addweaponinventory(temp);
//			return;
//		}
//		cout << "Not enough Money" << endl;
//		return;
//	}
//	else if (num == 7)
//	{
//		if (chr.getGold() >= 400)//
//		{
//			// --money
//			chr.setGold(chr.getGold() - 400);
//			Danso* temp = new Danso("Platinum");
//			chr.addweaponinventory(temp);
//			return;
//		}
//		cout << "Not enough Money" << endl;
//		return;
//	}
//	else if (num == 8)
//	{
//		if (chr.getGold() >= 500)//
//		{
//			// --money
//			chr.setGold(chr.getGold() - 500);
//			Danso* temp = new Danso("Diamond");
//			chr.addweaponinventory(temp);
//			return;
//		}
//		cout << "Not enough Money" << endl;
//		return;
//	}
//	else
//	{
//		cout << "Wrong Number" << endl;
//		return;
//	}
}
