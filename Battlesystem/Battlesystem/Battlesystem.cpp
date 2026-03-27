void startAutoBattle(Player& player, Monster& monster) {
    cout << "\n>>> [System] 0x" << &monster << " 주소에서 예외 객체 발견!" << endl;
    cout << ">>> [Type] class " << monster.name << " (Size: " << monster.hp << " bytes)" << endl;
    Sleep(1000);

    while (player.isAlive() && monster.isAlive()) {
        // 1. 플레이어 턴
        if (rand() % 100 < 15) {
            cout << "\n[Event] 가비지 컬렉터 실행! 메모리(HP)를 최적화합니다." << endl;
            player.useItem();
        }
        else {
            cout << "\n[Execute] player->attack(&monster);" << endl;
            monster.takeDamage(player.atk);
            cout << ">> Result: monster.hp = " << monster.hp << ";" << endl;
        }

        if (!monster.isAlive()) break;
        Sleep(700);

        // 2. 몬스터 턴
        cout << "\n[Execute] monster->send_packet(&player);" << endl;
        player.takeDamage(monster.atk);
        cout << ">> Result: player.hp = " << player.hp << ";" << endl;

        Sleep(700);
        cout << "------------------------------------------" << endl;
    }

    if (player.isAlive()) {
        processVictory(player);
    }
    else {
        cout << "\n[Fatal Error] Main Thread Terminated (Player HP: 0)" << endl;
    }
}

void processVictory(Player& p) {
    cout << "\n✨ [Success] 객체 해제 성공 (Free Memory: +50 EXP)" << endl;
    // ... 골드 및 아이템 로직 ...
    if ((rand() % 100) < 30) {
        cout << ">> [System] 새로운 객체 포인터(Item)를 인벤토리에 push_back 완료!" << endl;
    }
}