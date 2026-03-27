#include <iostream>
#include "Character.h"
#include "Shop.h"
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
    HealthPotion* NHP = new HealthPotion(3, "Normal"); // start potion - Normal = +30 Rare = +50 Epic = +100
    //HealthPotion* RHP = new HealthPotion(3, "Rare");
    //HealthPotion* EHP = new HealthPotion(3, "Epic");
    Danso LDanso("Plastic");// "Plastic30"
    Danso SDanso("Silver"); // "Silver50"
    Danso GDanso("Gold");   // "Gold70"
    Danso PDanso("Platinum");//"Platinum90"
    Danso DDanso("Diamond"); //"Diamond120"
    Shop sshhoopp;
    player.addhpinventory(NHP); // start potion input
    player.addweaponinventory(&LDanso); // start weapon input
    player.ShowStatus();
    sshhoopp.buy(1, player);
    player.ShowStatus();
    player.useitem(1);
    player.useitem(1);
    player.useitem(1);
    player.useitem(1);
    player.ShowStatus();
    sshhoopp.buy(1, player);
    player.ShowStatus();
    sshhoopp.buy(1, player);
    player.ShowStatus();
    player.addhpinventory(NHP);
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