#include "Monster.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Monster::initMonster(int type, int level) {
    string names[] = { "Bug", "Leak", "Deadlock", "Overflow", "Segfault", "Undefined" };
    int hpMin[] = { 10, 15, 20, 27, 35, 45 };
    int hpMax[] = { 15, 22, 30, 40, 52, 65 };
    int atkMin[] = { 3,  5,  8,  12, 17, 23 };
    int atkMax[] = { 5,  8,  12, 17, 23, 30 };

    if (type >= 0 && type < 6) {
        name = names[type];
        hp = (level * hpMin[type]) + rand() % (level * (hpMax[type] - hpMin[type]) + 1);
        attack = (level * atkMin[type]) + rand() % (level * (atkMax[type] - atkMin[type]) + 1);
    }
}

void Monster::printInfo() {
    cout << "[" << name << "] HP: " << hp << " | ATK: " << attack << endl;
}