#include <iostream>
#include "Character.h"
#include "Shop.h"
#include "DrunkenOjisang.h"
#include "BattleSystem.h"
#include "Logger.h"

using namespace std;

int main() {
    int choice;
    string playerName;
    cout << "\033[34m" << R"(
  ________                          _________ __                 __   
 /  _____/_____    _____   ____    /   _____//  |______ ________/  |_ 
/   \  ___\__  \  /     \_/ __ \   \_____  \\   __\__  \\_  __ \   __\
\    \_\  \/ __ \|  Y Y  \  ___/   /        \|  |  / __ \|  | \/|  |  
 \______  (____  /__|_|  /\___  > /_______  /|__| (____  /__|   |__|  
        \/     \/      \/     \/          \/           \/             
)" << "\033[0m" << endl;
    cout << "Enter your character's name: ";
    getline(cin, playerName);

    Character player(playerName);
    Shop sshhoopp;

    player.ShowStatus();

    DrunkenOjisang monster;

    while (true)
    {
        cout << "\033[33m\n========<Game Menu>========\n\t1.Battle\n\t2.Store\n\t0.Exit\033[0m\nSelect a number: ";
        cin >> choice;
        if (choice == 0) break;
        switch (choice)
        {
        case 1: BattleSystem::StartBattle(player); break;

        case 2:
            int cnum = 0;
            int out = 0;
            do
            {
                out = sshhoopp.openshop(player);
                if (out == 3)
                {
                    break;
                }
                cout << "Choose num :";
                cin >> cnum;
                if (cnum == 0)
                {
                    system("CLS");
                    continue;
                }
                sshhoopp.buy(cnum, player);
                //player.ShowStatus();
            } while (1);
            break;
        }
    }


    return 0;
}