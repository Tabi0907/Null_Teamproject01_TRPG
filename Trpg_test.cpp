#include <iostream>
#include <ctime>
#include "player_start.h"
#include "monster.h"
#include "item.h"
#include "MyActor_PROTOTYPE.h"
#include "Battlemanager.h"
#include <windows.h>
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    MyActor_PROTOTYPE logger;
    BattleManager bm;

    logger.BeginPlay();
    bm.Init();

    Character player;
    while (true) {
        cout << "프로토콜 이름 입력 (공백 불가): ";

        if (cin.peek() == '\n') cin.ignore();

        getline(cin, player.Name);

        // 이름이 비어있거나, 공백(Space)으로만 채워져 있는지 검사
        if (player.Name.empty() || player.Name.find_first_not_of(' ') == string::npos) {
         
            cout << "[ERROR] 프로토콜 이름은 비워둘 수 없습니다. 다시 입력하세요.\n" << endl;
            
        }
        else {
            break; // 올바른 이름이 입력되면 반복문 탈출
        }
    }

    // 체크리스트: 1~6번 스테이지 순차 진행 또는 랜덤 난입 루프
    for (int i = 0; i < 6; i++)
    {
        if (player.Hp <= 0) break;

        Monster monster;
        int randomType = rand() % 6;
        monster.initMonster(randomType, player.Level);

        cout << "\n" << string(40, '=') << endl;
        cout << "  STAGE " << i + 1 << " : [" << monster.name << "] 난입!" << endl;
        cout << string(40, '=') << endl;

        // 1. 전투 시작
        bm.startAutoBattle(player, monster);

        // 2. 패배 시 게임 오버
        if (player.Hp <= 0) {
            cout << "\n[GAME OVER] 시스템 무결성이 0%가 되었습니다..." << endl;
            break;
        }

        // 3. 승리 보상 처리
        cout << "\n>>> STAGE " << i + 1 << " 정화 완료! 보상을 획득합니다." << endl;

        player.Exp += 50;                  // 경험치 50 (체크리스트)
        int goldDrop = 10 + (rand() % 11); // 골드 10~20 (체크리스트)
        player.Gold += goldDrop;

        cout << "[REWARD] EXP +50 | GOLD +" << goldDrop << "G" << endl;

        // 30% 확률로 추가 아이템 획득 (선택 사항 - 기획서 내용 반영)
        if (rand() % 100 < 30) {
            int itemType = rand() % 2;
            cout << "[BONUS] 몬스터 데이터에서 유용한 아이템을 추출했습니다!" << endl;
            UseItem(itemType, player);
        }

        player.LevelUpCheck(); // 레벨업 확인
        player.print();        // 현재 상태 출력

        // 4. 다음 행동 선택
        if (i < 5) { // 마지막 스테이지가 아닐 때만 물어봄
            int choice;
            cout << "\n[NEXT PROTOCOL] 1.상점(준비중)  2.즉시 다음 스테이지  3.로그아웃 : ";
            cin >> choice;

            if (choice == 1) {
                cout << "\n" << string(40, '-') << endl;
                cout << " [SYSTEM_NOTICE] 상점 모듈 'SHOP.EXE'가 아직 최적화되지 않았습니다." << endl;
                cout << " 현재 보유 골드: " << player.Gold << "G를 안전하게 보관합니다." << endl;
                cout << " 다음 업데이트를 기다려주세요! (아무 키나 눌러 전투 복귀)" << endl;
                cout << string(40, '-') << endl;

                // 잠시 멈췄다가 다음 스테이지로 넘어가게 함
                system("pause");
            }
            else if (choice == 3) {
                cout << "진행 상황을 저장하고 로그아웃합니다..." << endl;
                return 0;
            }
        }
    }

    if (player.Hp > 0)
    {
        cout << "\n" << string(60, '*') << endl;
        cout << " [!] 경고: 표준 위협 제거 완료. 하지만 코어에서 이상 신호가 발생합니다." << endl;
        cout << " [!] 시스템이 강제로 'WHILE' 루프 영역에 진입합니다..." << endl;
        cout << string(60, '*') << endl;

        Sleep(2000); // 긴장감 조성을 위한 대기

        // ⭐ 여기서 보스전 함수를 호출해야 합니다!
        bm.startBossBattle(player);
    }

    // 보스전까지 승리했을 때 최종 엔딩 출력
    if (player.Hp > 0)
    {
        cout << "\n" << string(60, '=') << endl;
        cout << "[FINAL] 축하합니다! 최종 위협까지 제거하여 시스템이 완벽히 복구되었습니다!" << endl;
        cout << string(60, '=') << endl;
    }

    system("pause"); // 결과 확인을 위해 창 고정
    return 0;
}