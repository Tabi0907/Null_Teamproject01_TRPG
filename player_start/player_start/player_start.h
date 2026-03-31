#pragma once
#include <iostream>
#include <string>

class Character
{
public:
    std::string Name;
    int Hp = 200;           // 현재 체력
    int MaxHP = 200;        // 최대 체력 
    int Level = 1;
    int Attack = 30;        // 공격력
    int Exp = 0;
    int Gold = 0;           // 골드

    void print();           // 상태창 출력
    void DoLevelUp();       // 레벨업 
    void LevelUpCheck();    // 경험치 확인
};