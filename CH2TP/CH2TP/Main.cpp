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
    while (true)
    {
        cin >> choice;
        if (choice == 0) break;
        switch (choice)
        {
        case 1: BattleSystem::Battle(player, monster); break;

        case 2: cout << "상점"; break;
        }
    }

    return 0;
}