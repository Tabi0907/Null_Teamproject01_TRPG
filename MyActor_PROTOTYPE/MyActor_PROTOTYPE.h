#pragma once
#include <string>
#include <vector>

class MyActor_PROTOTYPE
{
public:
    void BeginPlay();
    void ShowMyLog(std::string Message);
private:
    std::vector<std::string> SavedLogs;
};