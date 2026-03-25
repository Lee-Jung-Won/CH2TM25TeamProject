#include "Character.h"
#include <iostream>

using namespace std;

// 넘어온 이름으로 캐릭터 초기 스탯 설정
Character::Character(string characterName) {
    name = characterName;   // 캐릭터 이름
    level = 1;              // 레벨
    maxHealth = 200;        // 최대 체력
    health = 200;           // 체력
    attack = 30;            // 공격력
    exp = 0;                // 경험치

    cout << "Welcome, " << name << "! Your adventure begins." << endl;
}

// 상태 출력 함수
void Character::ShowStatus() const {
    cout << "\n=== ===" << endl;
    cout << "Name:   " << name << endl;
    cout << "Level:  " << level << endl;
    cout << "Health: " << health << " / " << maxHealth << endl;
    cout << "Attack: " << attack << endl;
    cout << "EXP:    " << exp << " / " << EXP_PER_LEVEL << endl;
    cout << "============================\n" << endl;
}