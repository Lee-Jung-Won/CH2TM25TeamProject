#include "Character.h"
#include <iostream>

using namespace std;

// �Ѿ�� �̸����� ĳ���� �ʱ� ���� ����
Character::Character(string characterName) {
    name = characterName;   // ĳ���� �̸�
    level = 1;              // ����
    maxHealth = 200;        // �ִ� ü��
    health = 200;           // ü��
    attack = 30;            // ���ݷ�
    exp = 0;                // ����ġ
    MaxExp = 100;

    cout << "Welcome, " << name << "! Your adventure begins." << endl;
}

// ���� ��� �Լ�
void Character::ShowStatus() const {
    cout << "\n=== ===" << endl;
    cout << "Name:   " << name << endl;
    cout << "Level:  " << level << endl;
    cout << "Health: " << health << " / " << maxHealth << endl;
    cout << "Attack: " << attack << endl;
    cout << "EXP:    " << exp << " / " << EXP_PER_LEVEL << endl;
    cout << "============================\n" << endl;
}

void GainExp() {
    
    
}


void Character::Levelup() {

}