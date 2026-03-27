#pragma once

#include "CoreMinimal.h"

// [아이템 기능]
// 이 함수는 아이템을 사용하면 효과를 바로 적용합니다.
// ItemType 값에 따라 다른 아이템이 실행됩니다.
// 0 : Recovery Patch → 체력 +50
// 1 : Overclock.exe → 공격력 +10 (이번 전투만 적용)
// Hp는 플레이어 체력, TempAttack은 전투 중 임시 공격력입니다.
void UseItem(int ItemType, int& Hp, int& TempAttack);