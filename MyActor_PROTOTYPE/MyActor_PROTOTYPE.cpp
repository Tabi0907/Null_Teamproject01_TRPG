#include "MyActor_PROTOTYPE.h"
#include <iostream>

void MyActor_PROTOTYPE::BeginPlay() {
    ShowMyLog("반가워요! 로그 시스템이 온라인 상태입니다.");
}

void MyActor_PROTOTYPE::ShowMyLog(std::string Message) {
    std::cout << ">> [LOG] " << Message << std::endl;
    SavedLogs.push_back(Message);
}