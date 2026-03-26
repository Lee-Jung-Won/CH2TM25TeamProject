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
    int MaxExp;
    const int EXP_PER_LEVEL = 100;

public:
    // �̸��� �޾Ƽ� ĳ���͸� �����ϴ� ������
    Character(std::string characterName);

    // ĳ���� ���¸� �����ִ� �Լ�
    void ShowStatus() const;
    
    void GainExp();

    void Levelup() const;

};

