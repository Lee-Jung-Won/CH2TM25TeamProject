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
    Logger log;
    cout << "\033[34m" << R"(
  ________                          _________ __                 __   
 /  _____/_____    _____   ____    /   _____//  |______ ________/  |_ 
/   \  ___\__  \  /     \_/ __ \   \_____  \\   __\__  \\_  __ \   __\
\    \_\  \/ __ \|  Y Y  \  ___/   /        \|  |  / __ \|  | \/|  |  
 \______  (____  /__|_|  /\___  > /_______  /|__| (____  /__|   |__|  
        \/     \/      \/     \/          \/           \/             
)" << "\033[0m" << endl;
    
    while (1)
    {
        cout << "Enter your character's name: ";
        getline(cin, playerName);

        if (playerName.empty())
        {
            cout << "Re enter your Name." << endl;
        }
        else
        {
            break;
        }
    }
    
    
    
    system("cls");

    Character player(playerName);
    Shop sshhoopp;

    player.ShowStatus();

    DrunkenOjisang monster;
    while (true)
    {
        cout << "\033[33m\n========<Game Menu>========\n\t1.Battle\n\t2.Store\n\t0.Exit\033[0m\nSelect a number: ";
        cin >> choice;
        if (choice == 0) {
            system("cls");
            cout << "\033[34m" << R"(
'||''''| '||\   ||` '||'''|. 
 ||   .   ||\\  ||   ||   || 
 ||'''|   || \\ ||   ||   || 
 ||       ||  \\||   ||   || 
.||....| .||   \||. .||...|'            
)" << "\033[0m" << endl;

            log.showSummary();
            break;
        }
        switch (choice)
        {
        case 1: system("cls"); BattleSystem::StartBattle(player, log); break;

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
                cout << "Choose [NUM] you want to BUY : ";
                cin >> cnum;
                if (cnum == 0)
                {
                    continue;
                }
                sshhoopp.buy(cnum, player);
            } while (1);
            break;
        }
    }


    return 0;
}