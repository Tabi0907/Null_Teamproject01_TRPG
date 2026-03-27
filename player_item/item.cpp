#include <iostream>
#include "Item.h"

using namespace std;

// [아이템 기능 구현]
// ItemType 값에 따라 아이템 효과를 적용합니다.
// 0 : Recovery Patch → 체력 +50
// 1 : Overclock.exe → 공격력 +10 (이번 전투만 적용)
void UseItem(int ItemType, int& Hp, int& TempAttack)
{
    // Recovery Patch (체력 회복)
    if (ItemType == 0)
    {
        Hp += 50;
        cout << "Recovery Patch 적용 → 시스템 복구 +50\n";
    }
    // Overclock.exe (공격력 증가)
    else if (ItemType == 1)
    {
        TempAttack += 10;
        cout << "Overclock 실행 → 공격력 +10 (이번 전투)\n";
    }
}