// Fill out your copyright notice in the Description page of Project Settings.
//로그학인을 맡고 한번 만들어봤는데 아무라도 많이 빈공간이 있는것 같지만 여기까지가 저의 최선입니다.


#include "MyActor_PROTOTYPE.h"

// 처음에 이 액터가 만들어질 때 설정
AMyActor_PROTOTYPE::AMyActor_PROTOTYPE()
{
    // 매 순간 검사하는 기능(Tick)을 켜둘게요.
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// 게임 시작!
// Called when the game starts or when spawned
void AMyActor_PROTOTYPE::BeginPlay()
{
    Super::BeginPlay();

    // 시작하자마자 "로그 준비 완료"라고 화면에 띄워볼게요.
    ShowMyLog(TEXT("반가워요! 로그 시스템이 켜졌습니다."), FColor::Yellow);
}

// 매 프레임마다 하는 일
void AMyActor_PROTOTYPE::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}


// [핵심 기능] 팀원들이 부탁하면 화면에 글자를 그려주는 함수
void AMyActor_PROTOTYPE::ShowMyLog(FString Message, FColor Color)
{
    // GEngine이 있을 때만(화면이 보일 때만) 실행해요.
    if (GEngine)
    {
        // 화면에 글자를 띄워줍니다! (5초 동안 유지)
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, Color, Message);
    }

    // 나중에 확인하기 위해 내 보관함에도 저장해둬요.
    SavedLogs.Add(Message);

    // 개발자 창(Output Log)에도 기록을 남겨요.
    UE_LOG(LogTemp, Warning, TEXT("로그 기록: %s"), *Message);
}