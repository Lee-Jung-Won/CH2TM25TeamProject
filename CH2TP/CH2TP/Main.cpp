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


    // 생성된 캐릭터의 상태를 언제든지 확인할 수 있게 출력
    player.ShowStatus();

    DrunkenOjisang monster;

    BattleSystem::Battle(player, monster);

    return 0;
}