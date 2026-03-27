#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
using namespace std;

int main() {
    // 랜덤 시드 설정 (매번 다른 값이 나오게)
    srand(time(0));

    // Null의 레벨 입력
    int level;
    cout << "Null의 레벨을 입력하세요: ";
    cin >> level;

    // 몬스터 이름 배열 (약 → 강 순)
    string monsterName[6] = { "Bug", "Leak", "Deadlock", "Overflow", "Segfault", "Undefined" };

    // 등급별 배율 (몬스터마다 조금씩 강해짐)
    int hpMin[6]  = { 10, 15, 20, 27, 35, 45 };
    int hpMax[6]  = { 15, 22, 30, 40, 52, 65 };
    int atkMin[6] = {  3,  5,  8, 12, 17, 23 };
    int atkMax[6] = {  5,  8, 12, 17, 23, 30 };

    cout << "\n===== 몬스터 정보 =====" << endl;

    for (int i = 0; i < 6; i++) {
        // 체력: 레벨 × 배율 범위 내 랜덤
        int hp     = (level * hpMin[i])  + rand() % (level * (hpMax[i] - hpMin[i]) + 1);

        // 공격력: 레벨 × 배율 범위 내 랜덤
        int attack = (level * atkMin[i]) + rand() % (level * (atkMax[i] - atkMin[i]) + 1);

        cout << "[몬스터 " << i + 1 << "] " << monsterName[i] << endl;
        cout << "  체력: "   << hp     << endl;
        cout << "  공격력: " << attack << endl;
        cout << endl;
    }

    return 0;
}
