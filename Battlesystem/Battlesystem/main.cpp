int main() {
    // 각 매니저 객체 생성
    LogManager logMng;
    UnitManager unitMng;
    BattleManager battleMng;

    // 튜터님이 시킨 '정상 작동 순서' 로그 확인
    cout << "--- System Booting ---" << endl;
    logMng.Init();    // 1번 로그 출력
    unitMng.Init();   // 2번 로그 출력
    battleMng.Init(); // 3번 로그 출력 (질문자님 파트)
    cout << "--- Booting Complete ---" << endl;

    return 0;
}