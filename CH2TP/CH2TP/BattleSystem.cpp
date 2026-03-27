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
	}

	if (player.getLevel() >= 1 && player.getLevel() < 10)
	{
		monsters.push_back(new DrunkenWoman());
	}

	if (player.getLevel() >= 2 && player.getLevel() < 10)
	{
		monsters.push_back(new DeepsleepMan());
	}

	if (player.getLevel() >= 2 && player.getLevel() < 10)
	{
		monsters.push_back(new AngryHomeless());
	}

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, monsters.size() - 1);

	Monster* enemy = monsters[dist(gen)];

	cout << "\033[31m\n!!!EnemySpawne!!!\033[0m\n" << endl;
	enemy->StartText();
	cout << "Monster HP: " << enemy->getHealth() << ", Attack: " << enemy->getAttack() << endl;

	cout << "\033[33m\n=== Battle Start! ===\033[0m\n";
	
	int i = 1;

	while (player.getHealth() > 0 && enemy->getHealth() > 0)
	{	
		cout << "Press Enter to proceed with the turn..." << endl; 
		cin.get();

		cout << "\033[32m\n=== PLAYER TURN ===\033[0m\n" << endl; // player turn
		cout << player.getName() << " Attack! " << enemy->getName() << endl;
		enemy->takeDamage(player);

		// player.ShowStatus();

		if (enemy->getHealth() <= 0) // enemy die
		{
			enemy->DeadText();

			cout << "\033[33m\n=== REWARD!! ===\033[0m\n";

			int inExp = enemy->getRewardExp();
			int inGold = enemy->getRewardGold();

			player.GainExp(inExp);
			player.GainGold(inGold);

			player.ShowStatus();

			cout << "Press Enter to exit..." << endl;
			cin.get();

			break;
		}

		cout << "\033[31m\n=== ENEMY TRUN ===\033[0m\n" << endl; // enemy turn
		cout << enemy->getName() << " Attack! " << player.getName() << endl;
		player.takeDamage(*enemy);

		cout << "\033[33m\n=== " << i << " Turn End ===\033[0m\n";
		++i;

		if (player.getHealth() <= 0) // player die
		{
			cout << player.getName() << "is Dead..." << endl;
			cout << "\033[31m\n=== GAME OVER ===\033[0m\n" << endl;
			cout << "Press Enter to exit..." << endl;
			cin.get();

			exit(0); // program exit
		}
	}	
}
