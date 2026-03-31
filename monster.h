#pragma once
#include <iostream>
#include <string>

class Monster {
public:
    std::string name;
    int hp;
    int attack;
    void initMonster(int type, int level);

    void printInfo();
};