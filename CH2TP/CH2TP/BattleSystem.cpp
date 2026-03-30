#include "BattleSystem.h"
#include <iostream>
#include <random>

using namespace std;

void BattleSystem::StartBattle(Character& player)
{
	vector<Monster*> monsters;

	if (player.getLevel() >= 1 && player.getLevel() < 10)
	{
		monsters.push_back(new DrunkenOjisang());
		monsters.push_back(new DrunkenWoman());
	}

	if (player.getLevel() >= 2 && player.getLevel() < 10)
	{
		monsters.push_back(new DeepsleepMan());
		monsters.push_back(new AngryHomeless());
	}

	if (player.getLevel() >= 3 && player.getLevel() < 10)
	{
		monsters.push_back(new GiantBackpacker());
		monsters.push_back(new Deepkisscouple());
	}	

	if (player.getLevel() >= 4 && player.getLevel() < 10)
	{
		monsters.push_back(new SmokingGuy());
		monsters.push_back(new LoudSongGril());
	}

	if (player.getLevel() >= 5 && player.getLevel() < 10)
	{
		monsters.push_back(new ChurchLover());
		monsters.push_back(new JejusLover());
	}

	if (player.getLevel() >= 6 && player.getLevel() < 10)
	{
		monsters.push_back(new CashWalkGirl());
		monsters.push_back(new StreetDealer());
	}

	if (player.getLevel() >= 7 && player.getLevel() < 10)
	{
		monsters.push_back(new BidulgiMaster());
		monsters.push_back(new TiredBusinessMan());
	}

	if (player.getLevel() >= 8 && player.getLevel() < 10)
	{
		monsters.push_back(new ScreenDoorBreaker());
		monsters.push_back(new JarbanGranpa());
	}

	if (player.getLevel() >= 9 && player.getLevel() < 10)
	{
		monsters.push_back(new HandleExerciser());
		monsters.push_back(new DansoGrandma());
	}

	if (player.getLevel() >= 10)
	{
		monsters.push_back(new AirportDodook());
	}

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, monsters.size() - 1);

	Monster* enemy = monsters[dist(gen)];

	cout << "\033[31m\n!!!EnemySpawne!!!\033[0m\n" << endl;
	
	if (player.getLevel() == 10)//보스 등장 컷씬
	{
		cout << R"(                      
████████████████████████████████████████▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓
███████████████▓▓▓▓▓████████████████████▓▓▓▓▓▓▓▓▓▓▒▒▒▒░░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
███▓███████████▓▓▓▓▓████▓█████████▓██▓▓█████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████████▓███▓▓▓▓▓██████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
██████▓████████▓▓▓▓▓██████████▓███▓███████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓█████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
██████▓██████████████▓▓▓▓▓▓█████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░░░░░░░░░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓█████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
█████████████████████▓▓▓▓▓▓█▓██████▓█▓▓▓▓███▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒░░░░░░░░░░░░░▒▓▓▓▓▓▓▓▓▓▓▓█████████████████▓▓███████████
█████████████████████████████████▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░░▒▒▒▒▒░░░░░░░░░░░░░░▒▒▒▒▒▒▓▓▓▓▓▓▓████████▓███████████████████
████▓█████████▓▓▓▓████████▓██████████▓▓▓▓▓▓▓▓▓▒▓▓▒░░    ░▒▒▒▒░░░░░░░░░░░░░░░▒▒▒▒░▒▒▓▓▓▓▓▓▓▓▓▓███▓▓████████████████▓█
█▓███████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░       ░▒▒▒▒░░░░░░░░░░░░░░░▒▒▒▒░ ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███████████
██████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░         ░▒▒▒▒░░░░░░░░░░░░░░░▒▒▒▒░   ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░           ░▒▒▒▒░            ░░▒▒▒▒     ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░▒▒░              ░░░░░     ░       ░░░░        ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
▓▓▓▓▓▓▓▓▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░▒▒               ░░░░░░░░░░░░░░░░░░              ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
▓▓▓▓▓▓▓▓▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░░           ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░          ▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░░         ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░        ░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░        ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░       ░▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▓▓▓▓
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░        ░░░░░░░░░░░    ░░░░░░░░░░     ░░░░░░░░░░░       ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▒▒▒▒       ░░░░       ░░░░░░    ░░░  ░░░░   ░░  ░░░░░░░       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓
▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒░       ░░░░░░░    ░░ ░░░░        ░░░ ░░    ░░ ░░░░░░      ░▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▓
▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▒░       ░░░░░░░░░░░░░░░░░░   ░░░   ░░░░░░░░░░░░░░░░░░░      ░▒▒░▒▒▒▒▒▒▒▒▓▓▓▓▓▒▒▒▓▓▓
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▒▒▒▒      ░░░░░░░░░░░░░░░░░░   ░░░░░░  ░░░░░░░░░░░░░░░░░░      ░▒▒░░▒▒▒▒▒▒▓▓▓▒▒▒▓▓▓▓▓▓
░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░   ░░░░░░░░░░░░░░░░░░░   ░░░░░░░░ ░░░░░░░░░░░░░░░░░░░░   ░▒▒▒▒▒▒▒▒▒▓▓▓▒▒▓▓▓▓▓▓▓▓▓
▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▓▒▒▒▒▒▒▒▒▒░ ░░ ░░░░░░░░░░░░░░     ░░░░░░░░░░   ░░░░░░░░░░░░░░░░   ░░░▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░   ░▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓
▓▓▓▓▓▓▓█▓▓▓████████▓▓▓▓▓▒▓▓▓▓▓▓▓▓▒▒░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▓▓▓▓▓
▓▓██▓███████████████▓▓▓▓▓▓▓▓███▓▓▓▒░░▒▒░░░░░░░░░░░░░░ ░░░     ░░░░     ░░░░░░░░░░░░░░░░░░░ ░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓
▓▓█▓████▓██████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
▓▓███████████████▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓
▓▓██████▓████████▓█▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▒░ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▓▒▓▓▓▓▓▓▓▓▓▓░░▒░░▒░▒▓▓▓▓▓
▓▓██████████████████▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▒░░░░░░░░░░░░░░░░░░░░░          ░░░░░░░░░░░░░░░░░░░░ ░▓▓▓▓▓▓▓▓▓▓▓▓▒░░░░░░░▒▓▓▓▓▓
▓▓█████████████████▓▓▓▓▓▒▓▓▓▓▓▓▒▓▓▓▓▒▓▒▒░░░░░░░░░░░░░░░               ░░░░░░░░░░░░░░░░░░▒▓▓▒▒▒▓▓▓▓▒▒▓▓▒░░░░░░░▒▓▒▓▓▓
▓▓████████▓████████▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░░░░░░░░░░░░░░░░              ░░░░░░░░░░░░░░░▒▓▓▓▓▓▒▓▓▓▓▓▒▓▓▓▒░░░▒░░░▒▓▓▓▓▓
▓▓█████████████████▓▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▒  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓▒▒▒▒▒▓▓▓▓▓▓▓▓▒░░░░░░░▒▓▓▓▓▓
▓▓██████████████████▓▓▓▓▒▓▓▓▓▓▓▓▓▓▓▒     ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ░▒▒░░░▒▒▒▒▓▓▒▓▓▓▒░░░░░░░▒▓▓▓▓▓
▓▓█████████████████▓█▓▓▓▒▓▓▓▓▓▓▓▓▓░        ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░       ░▒▒▒▓▓▓▓▓▓▓▓▓▒░░░░░░░▒▓▓▓▓▓
▓▓██████████████████▓▓▓▓▒▓▓▓▓▓▓▓▒            ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░          ▒▒▓▒░░▒▒▓▓▓▓░░░░░░░░▒▒▒▒▒▒
▓▓██████████████████▓▓▓▓▒▓▓▓▓▓▓░            ░  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░            ░▓▓▓▓▓▓▓▓▓▓▓▒▓▓▓▓▒░░▒▒▒▒▒▒
▓▓███▓███▓██████████▓▓▓▓▒▓▓▓▓▓░             ░    ░░░░░░░░░░░░░░░░░░░░░░░░░  ░░             ░▒▓▓▓▓▓▓▓▓▒▒▓▒▒▒░░░▒▒▒▒▒▒
▓▓█████▓█████████▓▓▓▓▓▓▓▒▓▓▓░                         ░░░░░░░░ ░░░░░░░                       ░▒▓▓▓▓▓▓▒░  ░░░░░▒▒▒▒▒▒
▓▓█████████████▓▓▓▓▓▓▓▓▒▒░░░                 ░░                         ░░░                    ░▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░░░░░                      ░░░         ░░░░░░░░░░░░░░░░░   ░                  ▒▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒
▓▓▓▓▓▓▒░░░░░░░  ░░░  ░                         ░░░░        ░░░░░░░░░░   ░░   ░                      ░░▒▒▒▒▒▓▒▒▒▒▒▒▒▒
▒▓▒▒░░                                          ░░░░░             ░        ░░░                          ░▒▒▒▒▒▒▒▒▒▒▒
▒░                  ░                             ░░░░░  ░         ░   ░  ░░░                             ░░▒▒▒▒▒▒▒▒
                                                ░  ░░░░░░ ░░░░      ░░░ ░░░░  ░░                             ░▒▓▓▓▓▓
                                                 ░░░ ░░░░░░░░░░░    ░░ ░░░░ ░░░                                ▒▓▓▓▓
                     ░                             ░░░░░░░░░░░░░░░░░░ ░░░  ░░░                                  ░▓▓▓
                     ░                              ░░░░░░░░░░░░░░░░░░    ░░░                                    ░▓▓
                     ░                                ░░░░░░░░░░░░░░░░   ░░░                                      ▒▓

		)";

		cout << "\n";
	}
	enemy->StartText();
	cout << "Monster HP: " << enemy->getHealth() << ", Attack: " << enemy->getAttack() << endl;

	cout << "\033[33m\n=== Battle Start! ===\033[0m\n";

	int i = 1;
	bool A = true;
	int choice;
	int Potionchoice;
	Logger logger;

	while (A)
	{
		cout << "\033[33m\n========<What are you doing?>========\n\t1.ATTACK\n\t2.ITEM\n\t3.Stats\n\t4.Run\033[0m\nSelect a number: ";
		cin >> choice;

		switch (choice)
		{
		case 1: // ATTACK
			system("cls");
			cout << "\033[32m\n=== PLAYER TURN ===\033[0m\n" << endl; // player turn
			enemy->takeDamage(player);
			logger.addLog(LogType::Attack, "\033[32m" + player.getName() + " attacks " + enemy->getName() + "!\033[0m");
			logger.addLog(LogType::Damage, "\033[32m" + enemy->getName() + " takes " + std::to_string(player.getAttack()) + " damage\033[0m");
			logger.addLog(LogType::Damage, "\033[31m" + enemy->getName() + "'s remaining HP: " + std::to_string(enemy->getHealth()) + "\033[0m");

			if (enemy->getHealth() <= 0) // enemy die
			{
				enemy->DeadText();

				cout << "\033[33m\n=== REWARD!! ===\033[0m\n";

				int inExp = enemy->getRewardExp();
				int inGold = enemy->getRewardGold();

				player.GainExp(inExp);
				player.GainGold(inGold);

				if (player.getLevel() >= 10)
				{
					system("cls");
					cout << "\033[34mPeace has finally come to Line 1...\033[0m" << endl;
					cout << "\033[33m" << R"(
 _____   ___  ___  ___ _____   _____  _      _____   ___  ______  _  _  _ 
|  __ \ / _ \ |  \/  ||  ___| /  __ \| |    |  ___| / _ \ | ___ \| || || |
| |  \// /_\ \| .  . || |__   | /  \/| |    | |__  / /_\ \| |_/ /| || || |
| | __ |  _  || |\/| ||  __|  | |    | |    |  __| |  _  ||    / | || || |
| |_\ \| | | || |  | || |___  | \__/\| |____| |___ | | | || |\ \ |_||_||_|
 \____/\_| |_/\_|  |_/\____/   \____/\_____/\____/ \_| |_/\_| \_|(_)(_)(_)
					)" << "\033[0m" << endl;
					cout << "Press Enter to exit..." << endl;
					cin.get();

					for (Monster* m : monsters) // 메모리 릭 방지
					{
						delete m;
					}
					monsters.clear();

					exit(0);
				}

				for (Monster* m : monsters) // 메모리 릭 방지
				{
					delete m;
				}
				monsters.clear();

				player.ShowStatus();

				A = false;
				break;
			}

			cout << "\033[31m\n=== ENEMY TRUN ===\033[0m\n" << endl; // enemy turn
			player.takeDamage(*enemy);
			enemy->BattleText();
			logger.addLog(LogType::Attack, "\033[31m" + enemy->getName() + " attacks " + player.getName() + "!\033[0m");
			logger.addLog(LogType::Damage, "\033[31m" + player.getName() + " takes " + std::to_string(enemy->getAttack()) + " damage\033[0m");
			logger.addLog(LogType::Damage, "\033[32m" + player.getName() + "'s remaining HP: " + std::to_string(player.getHealth()) + "\033[0m");

			cout << "\033[33m\n=== " << i << " Turn End ===\033[0m\n";
			++i;

			if (player.getHealth() <= 0) // player die
			{
				cout << player.getName() << " is Dead..." << endl;
				cout << "\033[31m" << R"(
 _____   ___  ___  ___ _____   _____  _   _  _____ ______          
|  __ \ / _ \ |  \/  ||  ___| |  _  || | | ||  ___|| ___ \         
| |  \// /_\ \| .  . || |__   | | | || | | || |__  | |_/ /         
| | __ |  _  || |\/| ||  __|  | | | || | | ||  __| |    /          
| |_\ \| | | || |  | || |___  \ \_/ /\ \_/ /| |___ | |\ \  _  _  _ 
 \____/\_| |_/\_|  |_/\____/   \___/  \___/ \____/ \_| \_|(_)(_)(_)
                                                                   
                                                                   
				)" << "\033[0m" << endl;
				cout << "Press Enter to exit..." << endl;
				cin.get();

				exit(0); // program exit
			}
			break;

		case 2:	//ITEM
			system("cls");
			player.ShowStatus();

			if (player.getInventorySize() <= 0)
			{
				cout << "\033[33mThere are no potions available...\033[0m" << endl;
				break;
			}
			cout << "Press Enter to exit..." << endl;

			cin.get();

			cout << "\033[33mPlease select the potion number to use.: \033[0m" << endl;
			cin >> Potionchoice;

			switch (Potionchoice)
			{
			case 1:
				if (player.getInventorySize() >= 1 && player.getInventoryItem(1) != nullptr)
				{
					cout << "\033[32m\n=== PLAYER TURN ===\033[0m\n" << endl;
					cout << "\033[33mUse a potion.\033[0m" << endl;
					player.useitem(1);
					player.ShowStatus();

					cout << "\033[31m\n=== ENEMY TRUN ===\033[0m\n" << endl; // enemy turn
					player.takeDamage(*enemy);
					logger.addLog(LogType::Attack, "\033[31m" + enemy->getName() + " attacks " + player.getName() + "!\033[0m");
					logger.addLog(LogType::Damage, "\033[31m" + player.getName() + " takes " + std::to_string(enemy->getAttack()) + " damage\033[0m");
					logger.addLog(LogType::Damage, "\033[32m" + player.getName() + "'s remaining HP: " + std::to_string(player.getHealth()) + "\033[0m");

					cout << "\033[33m\n=== " << i << " Turn End ===\033[0m\n";
					++i;
				}
				else
				{
					cout << "\033[32m\n=== PLAYER TURN ===\033[0m\n" << endl;
					cout << "\033[33mThere are no potions!\033[0m" << endl;

					cout << "\033[31m\n=== ENEMY TRUN ===\033[0m\n" << endl; // enemy turn
					player.takeDamage(*enemy);
					logger.addLog(LogType::Attack, "\033[31m" + enemy->getName() + " attacks " + player.getName() + "!\033[0m");
					logger.addLog(LogType::Damage, "\033[31m" + player.getName() + " takes " + std::to_string(enemy->getAttack()) + " damage\033[0m");
					logger.addLog(LogType::Damage, "\033[32m" + player.getName() + "'s remaining HP: " + std::to_string(player.getHealth()) + "\033[0m");

					cout << "\033[33m\n=== " << i << " Turn End ===\033[0m\n";
					++i;
				}
				break;

			case 2:
				if (player.getInventorySize() >= 1 && player.getInventoryItem(1) != nullptr)
				{
					cout << "\033[32m\n=== PLAYER TURN ===\033[0m\n" << endl;
					cout << "\033[33mUse a potion.\033[0m" << endl;
					player.useitem(2);
					player.ShowStatus();

					cout << "\033[31m\n=== ENEMY TRUN ===\033[0m\n" << endl; // enemy turn
					player.takeDamage(*enemy);
					logger.addLog(LogType::Attack, "\033[31m" + enemy->getName() + " attacks " + player.getName() + "!\033[0m");
					logger.addLog(LogType::Damage, "\033[31m" + player.getName() + " takes " + std::to_string(enemy->getAttack()) + " damage\033[0m");
					logger.addLog(LogType::Damage, "\033[32m" + player.getName() + "'s remaining HP: " + std::to_string(player.getHealth()) + "\033[0m");

					cout << "\033[33m\n=== " << i << " Turn End ===\033[0m\n";
					++i;
				}
				else
				{
					cout << "\033[32m\n=== PLAYER TURN ===\033[0m\n" << endl;
					cout << "\033[33mThere are no potions!\033[0m" << endl;

					cout << "\033[31m\n=== ENEMY TRUN ===\033[0m\n" << endl; // enemy turn
					player.takeDamage(*enemy);
					logger.addLog(LogType::Attack, "\033[31m" + enemy->getName() + " attacks " + player.getName() + "!\033[0m");
					logger.addLog(LogType::Damage, "\033[31m" + player.getName() + " takes " + std::to_string(enemy->getAttack()) + " damage\033[0m");
					logger.addLog(LogType::Damage, "\033[32m" + player.getName() + "'s remaining HP: " + std::to_string(player.getHealth()) + "\033[0m");

					cout << "\033[33m\n=== " << i << " Turn End ===\033[0m\n";
					++i;
				}
				break;

			case 3:
				if (player.getInventorySize() >= 1 && player.getInventoryItem(1) != nullptr)
				{
					cout << "\033[32m\n=== PLAYER TURN ===\033[0m\n" << endl;
					cout << "\033[33mUse a potion.\033[0m" << endl;
					player.useitem(3);
					player.ShowStatus();

					cout << "\033[31m\n=== ENEMY TRUN ===\033[0m\n" << endl; // enemy turn
					player.takeDamage(*enemy);
					logger.addLog(LogType::Attack, "\033[31m" + enemy->getName() + " attacks " + player.getName() + "!\033[0m");
					logger.addLog(LogType::Damage, "\033[31m" + player.getName() + " takes " + std::to_string(enemy->getAttack()) + " damage\033[0m");
					logger.addLog(LogType::Damage, "\033[32m" + player.getName() + "'s remaining HP: " + std::to_string(player.getHealth()) + "\033[0m");

					cout << "\033[33m\n=== " << i << " Turn End ===\033[0m\n";
					++i;
				}
				else
				{
					cout << "\033[32m\n=== PLAYER TURN ===\033[0m\n" << endl;
					cout << "\033[33mThere are no potions!\033[0m" << endl;

					cout << "\033[31m\n=== ENEMY TRUN ===\033[0m\n" << endl; // enemy turn
					player.takeDamage(*enemy);
					logger.addLog(LogType::Attack, "\033[31m" + enemy->getName() + " attacks " + player.getName() + "!\033[0m");
					logger.addLog(LogType::Damage, "\033[31m" + player.getName() + " takes " + std::to_string(enemy->getAttack()) + " damage\033[0m");
					logger.addLog(LogType::Damage, "\033[32m" + player.getName() + "'s remaining HP: " + std::to_string(player.getHealth()) + "\033[0m");

					cout << "\033[33m\n=== " << i << " Turn End ===\033[0m\n";
					++i;
				}
				break;
			}
			break;

		case 3:
			system("cls");
			player.ShowStatus();
			break;

		case 4: // RUN
			system("cls");
			cout << "You ran away in a hurry...." << endl;
			A = false;
			break;

		}
	}
}