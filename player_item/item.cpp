#include "item.h"
#include <iostream>
#include <windows.h> 

using namespace std;

void UseItem(int ItemType, Character& player) {
    if (ItemType == 0) { // Recovery Patch
        int preHp = player.Hp; // 1. 회복 전 체력을 미리 저장 (예: 188)

        player.Hp += 50; // 2. 일단 50을 더함 (188 + 50 = 238)

        // 3. 최대 체력(200)까지만 허용
        if (player.Hp > player.MaxHP) {
            player.Hp = player.MaxHP; // (238 -> 200으로 고정)
        }

        // 4. [실제 회복량 = 현재 체력 - 이전 체력] (200 - 188 = 12)
        int actualHeal = player.Hp - preHp;

        if (actualHeal > 0) {
            cout << ">> [ITEM] Recovery Patch 사용 -> HP " << actualHeal << " 복구! ";
            cout << "(현재: " << player.Hp << "/" << player.MaxHP << ")" << endl;
        }
        else {
            cout << ">> [ITEM] Recovery Patch 사용 -> 이미 시스템이 최적 상태입니다. (HP 변동 없음)" << endl;
        }

        Sleep(800); // 아까 말씀드린 '한 줄씩' 연출을 위한 대기
    }
    else if (ItemType == 1) { // Overclock
        player.Attack += 10;
        std::cout << "[ITEM] Overclock.exe 실행 -> 공격력 10 상승!\n";
    }
}