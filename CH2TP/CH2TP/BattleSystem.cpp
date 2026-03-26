#include "BattleSystem.h"
#include <iostream>
using namespace std;

void BattleSystem::Battle(Character& player, Monster& monster) 
{
    monster.StartText();
    cout << "A wild " << monster.getName() << " appears!" << endl;
    cout << "Monster HP: " << monster.getHealth()
        << ", Attack: " << monster.getAttack() << endl;

    cout << "\n--- Battle Start ---\n";

    while (player.getHealth() > 0 && monster.getHealth() > 0) 
    {  
        cout << "\033[32m" << "===PLAYER TURN===" << "\033[0m" << endl;
        cout << player.getName() << " attacks " << monster.getName() << "!" << endl;
        monster.takeDamage(player);

        if (monster.getHealth() <= 0) 
        {
            monster.DeadText();
            break;
        }

        cout << "\033[33m" << "===ENEMY TURN===" << "\033[0m" << endl;
        cout << monster.getName() << " attacks " << player.getName() << "!" << endl;
        player.takeDamage(monster);

        if (player.getHealth() <= 0) {
            cout << player.getName() << " has been defeated!" << endl;
            break;
        }

        cout << "\n--- Turn End ---\n";
        player.ShowStatus();
        cout << monster.getName() << " HP: " << monster.getHealth() << endl;
    }

    cout << "\n--- Battle End ---\n";
    player.ShowStatus();
    cout << monster.getName() << " HP: " << monster.getHealth() << endl;
}