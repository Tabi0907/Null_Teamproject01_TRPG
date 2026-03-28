#include "BattleManager.h"
#include "Player.h"  // 팀원 파일과 연결
#include "Monster.h"

using namespace std;

// 1. 튜터님 요청: 초기화 확인용 로그
void BattleManager::Init() {
    cout << ">> [System] BattleManager: Initializing Combat Modules..." << endl;
}

// 2. 기존 startAutoBattle의 몸통 전체를 여기로 복사
void BattleManager::startAutoBattle(Player& player, Monster& monster) {
    // 0x 주소 출력부터 while 루프까지 싹 다 여기로 이사 옵니다.
    cout << "\n>>> [System] 0x" << &monster << " 주소에서 예외 객체 발견!" << endl;
    // ... (기존 코드 내용) ...
}

// 3. 기존 processVictory의 몸통 이사
void BattleManager::processVictory(Player& p) {
    cout << "\n✨ [Success] 객체 해제 성공..." << endl;
    // ... (기존 코드 내용) ...
}