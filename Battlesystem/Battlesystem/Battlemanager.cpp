#include "Battlemanager.h"
#include "item.h"
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

// 색상 제어 함수
void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 1. 초기화 함수
void BattleManager::Init() {
    cout << "[SYSTEM_LOG] 전투 매니저 준비 완료. (자동 전투 모드 활성화)" << endl;
    Sleep(1000);
}

// 2. 일반 전투 함수 (자동 전투)
void BattleManager::startAutoBattle(Character& player, Monster& monster) {
    cout << "\n" << string(45, '-') << endl;
    Sleep(500);
    cout << "[격리 구역 진입] " << player.Name << " VS " << monster.name << endl;
    Sleep(800);

    int turnCount = 1;

    while (player.Hp > 0 && monster.hp > 0) {
        cout << "\n[TURN " << turnCount << "]" << endl;
        Sleep(600);

        int actionChance = rand() % 100;

        if (actionChance < 30) {
            int itemChoice = (player.Hp < (player.MaxHP * 0.5)) ? ((rand() % 100 < 80) ? 0 : 1) : (rand() % 2);
            SetColor(9);
            if (player.Hp < (player.MaxHP * 0.5))
                cout << ">> [AI_LOG] 무결성 저하 감지. 회복 패치 우선 순위 상향." << endl;
            else
                cout << ">> [AI_LOG] 시스템 안정적. 무작위 리소스 최적화 실행." << endl;
            SetColor(7);
            Sleep(400);
            UseItem(itemChoice, player);
            Sleep(800);
        }
        else {
            int finalDamage = player.Attack;
            bool isCritical = (rand() % 100 < 15);
            if (isCritical) {
                finalDamage *= 2;
                SetColor(9);
                cout << ">> [CRITICAL] 치명적 결함 발견! " << player.Name << "의 회심의 일격!" << endl;
                SetColor(7);
                Sleep(600);
            }
            monster.hp -= finalDamage;
            if (monster.hp < 0) monster.hp = 0;
            SetColor(9);
            cout << ">> " << player.Name << "의 공격! [" << finalDamage << "] 데미지." << endl;
            SetColor(7);
            Sleep(500);
            cout << ">> [SYSTEM] " << monster.name << " 잔여 HP: " << monster.hp << endl;
            Sleep(500);
        }

        if (monster.hp <= 0) break;

        SetColor(12);
        cout << "<< " << monster.name << "의 역공격! [" << monster.attack << "] 데미지 유입." << endl;
        SetColor(7);
        player.Hp -= monster.attack;
        if (player.Hp < 0) player.Hp = 0;
        Sleep(500);
        cout << "<< " << player.Name << " 남은 HP: " << player.Hp << endl;
        Sleep(800);
        turnCount++;
    }

    cout << "\n" << string(45, '-') << endl;
    Sleep(1000);
    if (player.Hp > 0) cout << "[RESULT] " << monster.name << " 개체 정화 성공!" << endl;
    else cout << "[RESULT] " << player.Name << " 시스템 셧다운..." << endl;
    Sleep(500);
    cout << string(45, '-') << endl;
}

// 3. 최종 보스전 함수 (자동 마무리 연출 적용)
void BattleManager::startBossBattle(Character& player) {
    cout << "\n" << string(60, '=') << endl;
    Sleep(1000);
    cout << " [SYSTEM] 치명적 오류: 코어 데이터가 무한 루프에 빠졌습니다!" << endl;
    Sleep(800);
    cout << " [WARNING] 'WHILE' 개체가 모든 공격을 무효화하고 있습니다." << endl;
    Sleep(1500);

    Monster boss;
    boss.name = "WHILE (The Infinite)";
    boss.hp = 700;
    boss.attack = 40;

    bool isLoopBroken = false;
    int loopCount = 0;

    while (player.Hp > 0 && boss.hp > 0) {
        string cmd;
        if (!isLoopBroken) {
            SetColor(12);
            cout << "\n[WHILE]: \"나는 영원히 반복된다...\"" << endl;
            Sleep(600);
            cout << "[WHILE]: \"너는 이 루프를 절대로 벗어날 수 없다.\"" << endl;
            SetColor(7);
            Sleep(600);

            if (loopCount >= 2) {
                SetColor(14); // 노란색 힌트
                cout << "\n(알림: 시스템의 논리 흐름이 끝없이 순환하고 있습니다.)" << endl;
                cout << "(알림: 이 비정상적인 루프를 '부수어야' 할 것 같습니다...)" << endl;
                SetColor(7);
                Sleep(800);
            }
        }

        cout << "\n[명령 입력(attack / item)]: ";
        cin >> cmd;

        // [핵심] break 입력 시 자동 마무리 연출
        if (cmd == "break") {
            if (!isLoopBroken) {
                isLoopBroken = true;
                cout << "\n" << string(55, '!') << endl;
                cout << ">> [CRITICAL] 시스템 강제 중단점(Break Point) 발견!" << endl;
                cout << ">> [SYSTEM] 보스의 무적 루프가 해제되었습니다." << endl;
                cout << ">> [SYSTEM] 남은 데이터를 일괄 소거(Execute)합니다." << endl;
                cout << string(55, '!') << endl;
                Sleep(1500);

                // --- 초고속 자동 공격 연출 ---
                SetColor(11); // 밝은 하늘색
                while (boss.hp > 0) {
                    int rushDamage = player.Attack + (rand() % 50) + 100; // 보스니까 더 세게!
                    boss.hp -= rushDamage;
                    if (boss.hp < 0) boss.hp = 0;

                    cout << ">> [EXECUTE] 데이터 파괴 중... -" << rushDamage << " (남은 HP: " << boss.hp << ")" << endl;
                    Sleep(150); // 0.15초 간격으로 타다닥!
                }
                SetColor(7);
                break; // 자동 공격이 끝나면 루프 탈출
            }
        }
        else if (cmd == "attack") {
            if (!isLoopBroken) {
                cout << ">> " << player.Name << "의 공격! 하지만 보스가 데이터를 즉시 복구합니다." << endl;
                Sleep(500);
                cout << ">> [WHILE HP]: " << boss.hp << " / " << boss.hp << " (회복됨)" << endl;
            }
            else {
                // break를 안 쓰고 그냥 때릴 경우 (혹시나 해서 남겨둠)
                boss.hp -= player.Attack;
                cout << ">> " << player.Name << "의 공격! [" << player.Attack << "] 데미지." << endl;
                Sleep(500);
            }
        }
        else if (cmd == "item") {
            int idx;
            cout << "사용할 아이템(0:회복, 1:공격업): "; cin >> idx;
            UseItem(idx, player);
            Sleep(800);
        }

        if (boss.hp <= 0) break;

        // 보스 반격
        Sleep(700);
        SetColor(12);
        cout << "\n<< " << boss.name << "의 데이터 과부하 공격!" << endl;
        SetColor(7);
        Sleep(500);
        player.Hp -= boss.attack;
        if (player.Hp < 0) player.Hp = 0;
        cout << "<< [" << boss.attack << "] 데미지 유입. 시스템 무결성 저하." << endl;
        Sleep(500);
        cout << "<< " << player.Name << " 현재 HP: " << player.Hp << endl;
        Sleep(800);

        loopCount++;
    }

    if (player.Hp > 0) {
        Sleep(1000);
        cout << "\n" << string(60, '*') << endl;
        cout << " [SUCCESS] 'WHILE' 루프 정화 성공!" << endl;
        Sleep(800);
        cout << " [LOG] 모든 시스템이 정상화되었습니다. 게임 클리어!" << endl;
        cout << string(60, '*') << endl;
    }
}