// LevelUp.h

#pragma once

class LevelUp
{
public:
	// 초기 스탯
	int Level = 1;
	int MaxHP = 200;
	int CurrentHP = 200;
	int AttackPower = 30;

	// 레벨업
	void DoLevelUp();
};
