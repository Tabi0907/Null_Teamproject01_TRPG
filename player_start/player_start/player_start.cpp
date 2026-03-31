#include "player_start.h"
#include <iostream>

using namespace std;

void Character::print()
{
    cout << "------------------------------------------" << endl;
    cout << "[NAME] " << Name << " (Lv." << Level << ")" << endl;
    cout << "[HP] " << Hp << " / " << MaxHP << " | [ATK] " << Attack << endl;
    cout << "[EXP] " << Exp << " / 100" << endl;
    // --- [추가] 골드 출력 부분 ---
    cout << "[RESOURCE] " << Gold << "G (Credit)" << endl;
    cout << "------------------------------------------" << endl;
}

void Character::DoLevelUp()
{
    if (Level >= 10) {
        cout << "[SYSTEM_LOG] Error: Maximum Stability(10) Reached.\n";
        return;
    }

    Level++;
    Exp -= 100; // 0으로 초기화 대신 차감방식(남은 경험치 보존)을 추천하지만, 기존처럼 0으로 하셔도 무방합니다.
    MaxHP += (Level * 20);
    Attack += (Level * 5);
    Hp = MaxHP; // 풀회복

    cout << "\n[SYSTEM_LOG] System Recovery in Progress..." << endl;
    cout << "[SYSTEM_LOG] 존재 안정도(Level) 상승: " << Level << endl;
    cout << "[SYSTEM_LOG] 시스템 무결성(MaxHP): " << MaxHP << ", 데이터 처리량(ATK): " << Attack << " 업데이트 완료." << endl;
    cout << "[SYSTEM_LOG] Patch executed (Success!): 파일 손상률 0% 복구됨.\n" << endl;
}

void Character::LevelUpCheck()
{
    // 체크리스트: 100 이상 획득 시 레벨업
    if (Exp >= 100) DoLevelUp();
}