#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

int main() {
    string playerName;

    // 생성할 캐릭터의 이름을 입력
    cout << "Enter your character's name: ";
    getline(cin, playerName); 

    // 입력받은 이름으로 캐릭터 객체를 생성
    Character myCharacter(playerName);

    // 생성된 캐릭터의 상태를 언제든지 확인할 수 있게 출력
    myCharacter.ShowStatus();

    return 0;
}