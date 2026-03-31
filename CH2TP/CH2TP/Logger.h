#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

enum class LogType { Attack, Damage, EXP, Gold, Kill };

class Logger
{
private:
    std::vector<std::string> eventLogs;         // 전체 이벤트 기록을 저장하는 리스트
    std::map<std::string, int> monsterKills;    // 어떤 몬스터를 몇 마리 잡았는지 저장

public:
    // [ ] 공격, 피해, 아이템 사용, 골드 획득 등 중요한 이벤트를 콘솔에 나열
    void addLog(LogType type, std::string message) {
        std::string prefix;

        // 로그 타입에 따른 머리말 설정
        switch (type) {
        case LogType::Attack: prefix = "[ATTACK] "; break;
        case LogType::Damage: prefix = "[DAMAGE] "; break;
        case LogType::EXP:   prefix = "[EXP]   "; break;
        case LogType::Gold:   prefix = "[GOLD]   "; break;
        case LogType::Kill:   prefix = "[KILL]   "; break;
        }

        std::string fullLog = prefix + message;

        // 벡터에 로그 저장 
        eventLogs.push_back(fullLog);

        // 콘솔에 실시간 출력
        std::cout << fullLog << std::endl;
    }

    // 몬스터 처치를 기록하고 통계에 합산하는 전용 함수
    void recordKill(std::string monsterName) {
        // 해당 이름의 몬스터 카운트를 1 증가
        monsterKills[monsterName]++;

        // 처치 로그 추가
        addLog(LogType::Kill, "Defeated " + monsterName + "!");
    }

    // 몬스터를 얼마나 잡았는지 한눈에 확인 가능하도록 출력
    void showSummary() {
        std::cout << "\n================ BATTLE SUMMARY ================" << std::endl;

        if (monsterKills.empty()) {
            std::cout << "No monsters defeated yet." << std::endl;
        }
        else {
            // map을 순회하며 몬스터 이름과 처치 수 출력
            for (const auto& pair : monsterKills) {
                std::cout << " - " << std::left << std::setw(15) << pair.first
                    << ": " << pair.second << " unit(s)" << std::endl;
            }
        }

        std::cout << "===============================================\n" << std::endl;
    }
};

