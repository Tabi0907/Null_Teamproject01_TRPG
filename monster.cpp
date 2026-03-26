#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
using namespace std;

int main() {
    // 랜덤 시드 설정 (매번 다른 값이 나오게)
    srand(time(0));

    // 캐릭터_Null의 레벨 입력
    int level;
    cout << "Null의 레벨을 입력하세요: ";
    cin >> level;

    // 몬스터 이름 배열
    string monsterName[5] = { "Bug", "Leak", "Deadlock", "Overflow", "Segfault" };

    cout << "\n===== 몬스터 정보 =====" << endl;

    for (int i = 0; i < 5; i++) {
        // 체력: (레벨 × 20) ~ (레벨 × 30)
        int minHp  = level * 20;
        int maxHp  = level * 30;
        int hp     = minHp + rand() % (maxHp - minHp + 1);

        // 공격력: (레벨 × 5) ~ (레벨 × 10)
        int minAtk = level * 5;
        int maxAtk = level * 10;
        int attack = minAtk + rand() % (maxAtk - minAtk + 1);

        cout << "[몬스터 " << i + 1 << "] " << monsterName[i] << endl;
        cout << "  체력: "   << hp     << endl;
        cout << "  공격력: " << attack << endl;
        cout << endl;
    }

    return 0;
}
