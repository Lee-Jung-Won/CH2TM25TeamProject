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

    DrunkenOjisang monster;

    BattleSystem::Battle(player, monster);

    return 0;
}