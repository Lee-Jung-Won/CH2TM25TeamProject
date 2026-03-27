#include <iostream>
#include "Character.h"
#include "DrunkenOjisang.h"
#include "BattleSystem.h"

using namespace std;

int main() {
    int choice;
    string playerName;
    cout << "Enter your character's name: ";
    getline(cin, playerName);

    Character player(playerName);
    // hp( many, "string" ) ====== weapon("string")
    HealthPotion hp(3); // start potion - Normal = +30 Rare = +50 Epic = +100
    Danso weapon; // "Plastic" , "Silver" , "Gold" , "Platinum" , Diamond"
    player.addhpinventory(&hp); // start potion input
    player.addweaponinventory(&weapon); // start weapon input

    player.ShowStatus();

    player.addhpinventory(&hp);
    DrunkenOjisang monster;

    while (true)
    {
        cout << "\033[33m\n========<Game Menu>========\n\t1.Battle\n\t2.Store\n\t0.Exit\033[0m\nSelect a number: ";
        cin >> choice;
        if (choice == 0) break;
        switch (choice)
        {
        case 1: BattleSystem::StartBattle(player); break;

        case 2: cout << "Store"; break;
        }
    }


    return 0;
}