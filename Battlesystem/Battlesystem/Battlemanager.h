#pragma once
#ifndef BATTLE_MANAGER_H
#define BATTLE_MANAGER_H

#include <iostream>
#include <windows.h>

class Player; // 전방 선언 (팀원의 Player 클래스가 있다고 가정)
class Monster;

class BattleManager {
public:
    // 튜터님이 말씀하신 초기화 함수 (새로 추가)
    void Init();

    // 기존에 만드신 함수 이름(선언)만 가져옵니다.
    void startAutoBattle(Player& player, Monster& monster);

private:
    // 내부에서만 쓰는 함수 이름
    void processVictory(Player& p);
};

#endif