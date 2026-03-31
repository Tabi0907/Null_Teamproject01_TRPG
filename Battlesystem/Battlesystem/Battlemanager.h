#pragma once
#include "player_start.h" // Character
#include "monster.h"      // Monster

class BattleManager {
public:
    void Init();
    void startAutoBattle(Character& player, Monster& monster);
    void startBossBattle(Character& player);

private:
    void processVictory(Character& p);
};