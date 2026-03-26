// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor_PROTOTYPE.generated.h"

UCLASS()
class MYPROJECT_API AMyActor_PROTOTYPE : public AActor
{
    GENERATED_BODY()

public:
    // 1. 처음 시작할 때 준비하는 곳
    AMyActor_PROTOTYPE();

protected:
    // 2. 게임 시작 버튼 누르면 딱 한 번 실행되는 곳
    virtual void BeginPlay() override;

public:
    // 3. 게임 도중 계속 실행되는 곳 (지금은 비워둘게요!)
    virtual void Tick(float DeltaTime) override;

    // --- [여기서부터 내가 만든 구간!] ---
    // 다른 팀원들이 "로그 찍어줘!"라고 부탁할 때 쓸 함수예요.
    // Message: 보여줄 글자 / Color: 글자 색상
    void ShowMyLog(FString Message, FColor Color);

private:
    // 나중에 로그를 모아서 보고 싶을 때를 대비해 저장해두는 목록이에요.
    TArray<FString> SavedLogs;
};
