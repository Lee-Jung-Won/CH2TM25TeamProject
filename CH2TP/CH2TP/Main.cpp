#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

int main() {
    string playerName;

    // ������ ĳ������ �̸��� �Է�
    cout << "Enter your character's name: ";
    getline(cin, playerName); 

    // �Է¹��� �̸����� ĳ���� ��ü�� ����
    Character myCharacter(playerName);

    // ������ ĳ������ ���¸� �������� Ȯ���� �� �ְ� ���
    myCharacter.ShowStatus();

    return 0;
}