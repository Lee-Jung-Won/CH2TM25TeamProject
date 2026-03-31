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

	SNHP = new HealthPotion(100, "Normal");
	SRHP = new HealthPotion(100, "Rare");
	SEHP = new HealthPotion(100, "Epic");
	SNEXP = new ExpPotion(50, "Normal");
	SREXP = new ExpPotion(40, "Rare");
	SEEXP = new ExpPotion(30, "Epic");
	shopsobiinven.push_back(SNHP);
	shopsobiinven.push_back(SRHP);
	shopsobiinven.push_back(SEHP);
	shopsobiinven.push_back(SNEXP);
	shopsobiinven.push_back(SREXP);
	shopsobiinven.push_back(SEEXP);


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
	if (SNEXP != nullptr)
	{
		delete SNEXP;
		SNEXP = nullptr;
	}
	if (SREXP != nullptr)
	{
		delete SREXP;
		SREXP = nullptr;
	}
	if (SEEXP != nullptr)
	{
		delete SEEXP;
		SEEXP = nullptr;
	}
}

int Shop::openshop(Character& who)
{
	system("cls");
	cout << endl;
	cout << "\033[36m" << R"(
               __      __       .__                               
              /  \    /  \ ____ |  |   ____  ____   _____   ____  
              \   \/\/   // __ \|  | _/ ___\/  _ \ /     \_/ __ \ 
               \        /\  ___/|  |_\  \__(  <_> )  Y Y  \  ___/ 
                \__/\  /  \___  >____/\___  >____/|__|_|  /\___  >
                     \/       \/          \/            \/     \/ 
                         _________.__                             
                        /   _____/|  |__   ____ ______            
                        \_____  \ |  |  \ /  _ \\____ \           
                        /        \|   Y  (  <_> )  |_> >          
                       /_______  /|___|  /\____/|   __/           
                               \/      \/       |__|      
)" << "\033[0m" << endl;
	cout << "<<<<<<<<<<<<< 1. Potion Store            0.Out           2. Weapon Store >>>>>>>>>>>>>>" << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;
	cout << "MoneyYouHave : " << who.getGold() << "G" << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;
	who.printinventory();
	cout << "Choose number you want to go... : ";
	cin >> chosenum;
	system("CLS");
	if (chosenum == 1)
	{
		system("cls");
		cout << "---------------------------------------------------------------------------------------";
		cout << "\033[37m" << R"(
                     __  .__                            __                        
      ______   _____/  |_|__| ____   ____       _______/  |_  ___________   ____  
      \____ \ /  _ \   __\  |/  _ \ /    \     /  ___/\   __\/  _ \_  __ \_/ __ \ 
      |  |_> >  <_> )  | |  (  <_> )   |  \    \___ \  |  | (  <_> )  | \/\  ___/ 
      |   __/ \____/|__| |__|\____/|___|  /   /____  > |__|  \____/|__|    \___  >
      |__|                              \/         \/                          \/ 
		)" << "\033[0m" << endl;
		cout << "=======================================================================================" << endl;
		cout << "=============================------------------------------============================" << endl;
		cout << "==========            1. HP-Potion(Normal) ::  " << shopsobiinven[0]->getprice() << "G...(+100HP)  (" << shopsobiinven[0]->getstore() << ")          ==========" << endl;
		cout << "=======================================================================================" << endl;
		cout << "==========            2. HP-Potion( Rare ) ::  " << shopsobiinven[1]->getprice() << "G...(+150HP)  (" << shopsobiinven[1]->getstore() << ")          ==========" << endl;
		cout << "=======================================================================================" << endl;
		cout << "==========            3. HP-Potion( Epic ) :: " << shopsobiinven[2]->getprice() << "G...(+200HP)  (" << shopsobiinven[2]->getstore() << ")          ==========" << endl;
		cout << "=======================================================================================" << endl;
		cout << "==========            4.EXP-Potion(Normal) ::  " << shopsobiinven[3]->getprice() << "G...(+30EXP)  ( " << shopsobiinven[3]->getstore() << ")          ==========" << endl;
		cout << "=======================================================================================" << endl;
		cout << "==========            5.EXP-Potion( Rare ) ::  " << shopsobiinven[4]->getprice() << "G...(+50EXP)  ( " << shopsobiinven[4]->getstore() << ")          ==========" << endl;
		cout << "=======================================================================================" << endl;
		cout << "==========            6.EXP-Potion( Epic ) ::  " << shopsobiinven[5]->getprice() << "G...(+100EXP) ( " << shopsobiinven[5]->getstore() << ")          ==========" << endl;
		cout << "=======================================================================================" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "MoneyYouHave : " << who.getGold() << "G" << "                                                           0. Back" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		who.printinventory();
	}
	else if (chosenum == 2)
	{
		system("cls");
		cout << "---------------------------------------------------------------------------------------";
		cout << "\033[37m" << R"(                             __                        
  __  _  __ ____ _____  ______   ____   ____       _______/  |_  ___________   ____  
  \ \/ \/ // __ \\__  \ \____ \ /  _ \ /    \     /  ___/\   __\/  _ \_  __ \_/ __ \ 
   \     /\  ___/ / __ \|  |_> >  <_> )   |  \    \___ \  |  | (  <_> )  | \/\  ___/ 
    \/\_/  \___  >____  /   __/ \____/|___|  /   /____  > |__|  \____/|__|    \___  >
               \/     \/|__|               \/         \/                          \/ )" << "\033[0m" << endl << endl;
		cout << "=============================------------------------------============================" << endl;
		cout << "========================= <<  Danso_               Store  >> ==========================" << endl;
		cout << "=============================------------------------------============================" << endl;
		cout << "=======                   1. Plastic Danso ::  150G (+30dmg)                    =======" << endl;
		cout << "=======================================================================================" << endl;
		cout << "=======                   2. Silver  Danso ::  300G (+60dmg)                    =======" << endl;
		cout << "=======================================================================================" << endl;
		cout << "=======                   3. Gold    Danso ::  500G (+120dmg)                   =======" << endl;
		cout << "=======================================================================================" << endl;
		cout << "=======                   4. Platinu Danso ::  750G (+200dmg)                   =======" << endl;
		cout << "=======================================================================================" << endl;
		cout << "=======                   5. Diamond Danso :: 1000G (+300dmg)                   =======" << endl;
		cout << "=======================================================================================" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "MoneyYouHave : " << who.getGold() << "G" << "                                                           0. Back" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		who.printinventory();
	}
	else
	{
		system("cls");
		cout << "---------------------------------------------------------------------------------------";
		cout << endl;
		cout << "\033[36m" << R"(
                ___________       ____  ___       .___        ___________
                \    _____/       \   \/  /       |   |       \__    ___/
                 |    __)_         \     /        |   |         |    |   
                 |        \        /     \        |   |         |    |   
                /_______  /       /___/\  \       |___|         |____|   
                        \/              \_/                              
)" << "\033[0m" << endl;
		cout << "---------------------------------------------------------------------------------------";
		cout << endl;
		who.printinventory();
		chosenum = 0;

	}
	
	return chosenum;
}

void Shop::buy(int num, Character& chr)
{
	switch (chosenum)
	{
	case 1: // potionstore
	{

			if (num == 1)
			{
				int many = 1;
				cout << "How Many you Want :: ";
				cin >> many;
				if (many > 0 && many <= SNHP->getstore())
				{
					// ��� ��ðڽ��ϱ�? ����....> 1�ڸ��� ����������ǰ�...
					HealthPotion* prehp = new HealthPotion(many, "Normal");
					if (SNHP->getstore() > 0)
					{
						if (chr.getGold() >= (prehp->getprice() * many))
						{
							chr.setGold(chr.getGold() - many * prehp->getprice());
							shopsobiinven[0]->setstore(shopsobiinven[0]->getstore() - many);
							chr.makepotion(prehp);
						}
						else
						{
							cout << "Not Enough Money" << endl;
						}
					}
					else
					{
						cout << "\t[ Normal ] HP Potion is [ SLOD OUT ]";
					}
				}
				else
				{
					cout << "Input ~Wrond Number~ : 1 ~ " << SNHP->getstore() << endl;
				}
				break;
			}
			else if (num == 2)
			{
				int many = 1;
				cout << "How Many you Want :: ";
				cin >> many;
				if (many > 0 && many <= SRHP->getstore())
				{
					// ��� ��ðڽ��ϱ�? ����....> 1�ڸ��� ����������ǰ�...
					HealthPotion* prehp = new HealthPotion(many, "Rare");
					if (SRHP->getstore() > 0)
					{
						if (chr.getGold() >= (prehp->getprice() * many))
						{
							chr.setGold(chr.getGold() - many * prehp->getprice());
							shopsobiinven[1]->setstore(shopsobiinven[1]->getstore() - many);
							chr.makepotion(prehp);
						}
						else
						{
							cout << "Not Enough Money" << endl;
						}
					}
					else
					{
						cout << "\t[ Rare ] HP Potion is [ SLOD OUT ]";
					}
				}
				else
				{
					cout << "Input ~Wrond Number~ : 1 ~ " << SRHP->getstore() << endl;
				}
				break;
			}
			else if (num == 3)
			{
				int many = 1;
				cout << "How Many you Want :: ";
				cin >> many;
				if (many > 0 && many <= SEHP->getstore())
				{
					// ��� ��ðڽ��ϱ�? ����....> 1�ڸ��� ����������ǰ�...
					HealthPotion* prehp = new HealthPotion(many, "Epic");
					if (SEHP->getstore() > 0)
					{
						if (chr.getGold() >= (prehp->getprice() * many))
						{
							
							chr.setGold(chr.getGold() - many * prehp->getprice());
							shopsobiinven[2]->setstore(shopsobiinven[2]->getstore() - many);
							chr.makepotion(prehp);
						}
						else
						{
							cout << "Not Enough Money" << endl;
						}
					}
					else
					{
						cout << "\t[ Epic ] HP Potion is [ SLOD OUT ]";
					}
				}
				else
				{
					cout << "Input ~Wrond Number~ : 1 ~ " << SEHP->getstore() << endl;
				}
				break;
			}
			else if (num == 4)
			{
				int many = 1;
				cout << "How Many you Want :: ";
				cin >> many;
				if (many > 0 && many <= SNEXP->getstore())
				{
					// ��� ��ðڽ��ϱ�? ����....> 1�ڸ��� ����������ǰ�...
					ExpPotion* prehp = new ExpPotion(many, "Normal");
					if (SNEXP->getstore() > 0)
					{
						if (chr.getGold() >= (prehp->getprice() * many))
						{
							
							chr.setGold(chr.getGold() - many * prehp->getprice());
							shopsobiinven[num - 1]->setstore(shopsobiinven[num - 1]->getstore() - many);
							chr.makepotion(prehp);
						}
						else
						{
							cout << "Not Enough Money" << endl;
						}
					}
					else
					{
						cout << "\t[ Normal ] EXP Potion is [ SLOD OUT ]";
					}
				}
				else
				{
					cout << "Input ~Wrond Number~ : 1 ~ " << SNEXP->getstore() << endl;
				}
				break;
			}
			else if (num == 5)
			{
				int many = 1;
				cout << "How Many you Want :: ";
				cin >> many;
				if (many > 0 && many <= SREXP->getstore())
				{
					// ��� ��ðڽ��ϱ�? ����....> 1�ڸ��� ����������ǰ�...
					ExpPotion* prehp = new ExpPotion(many, "Rare");
					if (SREXP->getstore() > 0)
					{
						if (chr.getGold() >= (prehp->getprice() * many))
						{
							
							chr.setGold(chr.getGold() - many * prehp->getprice());
							shopsobiinven[num - 1]->setstore(shopsobiinven[num - 1]->getstore() - many);
							chr.makepotion(prehp);
						}
						else
						{
							cout << "Not Enough Money" << endl;
						}
					}
					else
					{
						cout << "\t[ Rare ] EXP Potion is [ SLOD OUT ]";
					}
				}
				else
				{
					cout << "Input ~Wrond Number~ : 1 ~ " << SREXP->getstore() << endl;
				}
				break;
			}
			else if (num == 6)
			{
				int many = 1;
				cout << "How Many you Want :: ";
				cin >> many;
				if (many > 0 && many <= SEEXP->getstore())
				{
					// ��� ��ðڽ��ϱ�? ����....> 1�ڸ��� ����������ǰ�...
					ExpPotion* prehp = new ExpPotion(many, "Epic");
					if (SEEXP->getstore() > 0)
					{
						if (chr.getGold() >= (prehp->getprice() * many))
						{
							
							chr.setGold(chr.getGold() - many * prehp->getprice());
							shopsobiinven[num - 1]->setstore(shopsobiinven[num - 1]->getstore() - many);
							chr.makepotion(prehp);
						}
						else
						{
							cout << "Not Enough Money" << endl;
						}
					}
					else
					{
						cout << "\t[ Epic ] EXP Potion is [ SLOD OUT ]";
					}
				}
				else
				{
					cout << "Input ~Wrond Number~ : 1 ~ " << SEEXP->getstore() << endl;
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
			if (chr.getwpinventory()->size() == 0)
			{
				if (chr.getGold() >= prewp.getprice())
				{
					
					chr.setGold(chr.getGold() - prewp.getprice());
					chr.makeweapon(&prewp);
				}
				else
				{
					cout << "Not Enough Money" << endl;
				}
			}
			else
			{
				if (GetRankPriority(chr.getwpinventory()->at(0)->getName().rank) > GetRankPriority(prewp.getName().rank))
				{
					cout << "You Can't Change Your WEAPON to LOWER RANK WEAPON" << endl;
				}
				else
				{
					if (chr.getGold() >= prewp.getprice())
					{
						
						chr.setGold(chr.getGold() - prewp.getprice());
						chr.makeweapon(&prewp);
					}
					else
					{
						cout << "Not Enough Money" << endl;
					}
				}
			}
		}
		else if (num == 2)
		{
			Danso prewp("Silver");
			if (chr.getwpinventory()->size() == 0)
			{
				if (chr.getGold() >= prewp.getprice())
				{
					
					chr.setGold(chr.getGold() - prewp.getprice());
					chr.makeweapon(&prewp);
				}
				else
				{
					cout << "Not Enough Money" << endl;
				}
			}
			else
			{
				if (GetRankPriority(chr.getwpinventory()->at(0)->getName().rank) > GetRankPriority(prewp.getName().rank))
				{
					cout << "You Can't Change Your WEAPON to LOWER RANK WEAPON" << endl;
				}
				else
				{
					if (chr.getGold() >= prewp.getprice())
					{
						
						chr.setGold(chr.getGold() - prewp.getprice());
						chr.makeweapon(&prewp);
					}
					else
					{
						cout << "Not Enough Money" << endl;
					}
				}
			}
		}
		else if (num == 3)
		{
			Danso prewp("Gold");
			if (chr.getwpinventory()->size() == 0)
			{
				if (chr.getGold() >= prewp.getprice())
				{
					
					chr.setGold(chr.getGold() - prewp.getprice());
					chr.makeweapon(&prewp);
				}
				else
				{
					cout << "Not Enough Money" << endl;
				}
			}
			else
			{
				if (GetRankPriority(chr.getwpinventory()->at(0)->getName().rank) > GetRankPriority(prewp.getName().rank))
				{
					cout << "You Can't Change Your WEAPON to LOWER RANK WEAPON" << endl;
				}
				else
				{
					if (chr.getGold() >= prewp.getprice())
					{
						
						chr.setGold(chr.getGold() - prewp.getprice());
						chr.makeweapon(&prewp);
					}
					else
					{
						cout << "Not Enough Money" << endl;
					}
				}
			}
		}
		else if (num == 4)
		{
			Danso prewp("Platinum");
			if (chr.getwpinventory()->size() == 0)
			{
				if (chr.getGold() >= prewp.getprice())
				{
					
					chr.setGold(chr.getGold() - prewp.getprice());
					chr.makeweapon(&prewp);
				}
				else
				{
					cout << "Not Enough Money" << endl;
				}
			}
			else
			{
				if (GetRankPriority(chr.getwpinventory()->at(0)->getName().rank) > GetRankPriority(prewp.getName().rank))
				{
					cout << "You Can't Change Your WEAPON to LOWER RANK WEAPON" << endl;
				}
				else
				{
					if (chr.getGold() >= prewp.getprice())
					{
						
						chr.setGold(chr.getGold() - prewp.getprice());
						chr.makeweapon(&prewp);
					}
					else
					{
						cout << "Not Enough Money" << endl;
					}
				}
			}
		}
		else if (num == 5)
		{
			Danso prewp("Diamond");
			if (chr.getwpinventory()->size() == 0)
			{
				if (chr.getGold() >= prewp.getprice())
				{
					
					chr.setGold(chr.getGold() - prewp.getprice());
					chr.makeweapon(&prewp);
				}
				else
				{
					cout << "Not Enough Money" << endl;
				}
			}
			else
			{
				if (GetRankPriority(chr.getwpinventory()->at(0)->getName().rank) > GetRankPriority(prewp.getName().rank))
				{
					cout << "You Can't Change Your WEAPON to LOWER RANK WEAPON" << endl;
				}
				else
				{
					if (chr.getGold() >= prewp.getprice())
					{
						
						chr.setGold(chr.getGold() - prewp.getprice());
						chr.makeweapon(&prewp);
					}
					else
					{
						cout << "Not Enough Money" << endl;
					}
				}
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

}
