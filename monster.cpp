#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
using namespace std;

// ========================
// 몬스터 클래스
// ========================
class Monster {
public:
    string name;
    int hp;
    int attack;

    // 몬스터 스탯 설정 함수
    void setStats(string n, int level, int hpMin, int hpMax, int atkMin, int atkMax) {
        name   = n;
        hp     = (level * hpMin) + rand() % (level * (hpMax - hpMin) + 1);
        attack = (level * atkMin) + rand() % (level * (atkMax - atkMin) + 1);
    }

    // 몬스터 정보 출력 함수
    void printInfo() {
        cout << "  이름: "   << name   << endl;
        cout << "  체력: "   << hp     << endl;
        cout << "  공격력: " << attack << endl;
        cout << endl;
    }
};

// ========================
// 메인 함수
// ========================
int main() {
    // 랜덤 시드 설정
    srand(time(0));

    // Null의 레벨 입력
    int level;
    cout << "Null의 레벨을 입력하세요: ";
    cin >> level;

    // 몬스터 6마리 객체 생성
    Monster monsters[6];

    // 각 몬스터 스탯 설정 (이름, 레벨, 체력Min, 체력Max, 공격Min, 공격Max)
    monsters[0].setStats("Bug",       level, 10, 15, 3,  5 );
    monsters[1].setStats("Leak",      level, 15, 22, 5,  8 );
    monsters[2].setStats("Deadlock",  level, 20, 30, 8,  12);
    monsters[3].setStats("Overflow",  level, 27, 40, 12, 17);
    monsters[4].setStats("Segfault",  level, 35, 52, 17, 23);
    monsters[5].setStats("Undefined", level, 45, 65, 23, 30);

    // 몬스터 정보 출력
    cout << "\n===== 몬스터 정보 =====" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "[몬스터 " << i + 1 << "]" << endl;
        monsters[i].printInfo();
    }

    return 0;
}
