#pragma once
#include <string>

class Character
{
private:
    std::string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int exp;
    const int EXP_PER_LEVEL = 100;

public:
    // 이름을 받아서 캐릭터를 생성하는 생성자
    Character(std::string characterName);

    // 캐릭터 상태를 보여주는 함수
    void ShowStatus() const;
};

