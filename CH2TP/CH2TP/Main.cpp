#include <iostream>
#include "Character.h"
#include "DrunkenOjisang.h"
#include "BattleSystem.h"

using namespace std;

int main() {
    string playerName;
    cout << "Enter your character's name: ";
    getline(cin, playerName);

    Character player(playerName);
    player.ShowStatus();

    HealthPotion hp(3);
    HealthPotion hp1(3, "B");
    player.addhpinventory(&hp);
    player.addhpinventory(&hp);
    player.addhpinventory(&hp);
    player.addhpinventory(&hp1);


    
    player.ShowStatus();

    DrunkenOjisang monster;

    BattleSystem::Battle(player, monster);

    return 0;
}