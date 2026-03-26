// LevelUp.cpp

#include "LevelUp.h"
#include <iostream>

void LevelUp::DoLevelUp()
{
	// 최대 레벨 제한 
	if (Level >= 10)
	{
		std::cout << "[SYSTEM_LOG] Error: Maximum Stability(10) Reached. 추가 복구 불가 . \n";
		return;
	}

	// 레벨 증가
	Level++;

	// 스탯
	MaxHP += (Level * 20);
	AttackPower += (Level * 5);

	CurrentHP = MaxHP;

	// 커진 최대치만큼 현재 체력 복구 로그 출력
	std::cout << "\n[SYSTEM_LOG] System Recovery in Progress...\n";
	std::cout << "[SYSTEM_LOG] 존재 안정도(Level) 상승: " << Level << "\n";
	std::cout << "[SYSTEM_LOG] 시스템 무결성(MaxHP): " << MaxHP << ", 데이터 처리량(ATK): " << AttackPower << "로 업데이트 완료.\n";
	std::cout << "[SYSTEM_LOG] Patch executed (Success!): 파일 손상률 0%로 복구됨. (현재 체력: " << CurrentHP << ")\n\n";
}
