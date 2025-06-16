#include "Trans.h"
#include "Engine/Engine.h"

// Sets default values
ATrans::ATrans()
{
    PrimaryActorTick.bCanEverTick = true; // 틱을 사용한다면 필요
}

void ATrans::move()
{
    //이벤트 함수 실행
    createEvent();

    //현재 좌표 복사
    FVector temp = start;

    //다음 좌표 이동
    start.X = step();
    start.Y = step();

    //현재 좌표 기준 거리 출력을 위해 선언
    float currentds = distance(temp, start);

    //전체 이동거리에 추가.
    totDist += currentds;

    //로그 확인을 위해 더블을 int32로 변경해서 출력
    UE_LOG(LogTemp, Warning, TEXT("x: %d y: %d"), (int32)start.X, (int32)start.Y);

    //현재 좌표 기준 이동 거리 출력
    UE_LOG(LogTemp, Warning, TEXT("cuurent distance: %f"), currentds);
}

int32 ATrans::step()
{
    int32 RandomValue = FMath::RandRange(0, 1); // 0이나 1

    return RandomValue;
}

void ATrans::createEvent()
{
    int32 EventRandomValue = FMath::RandRange(1, 100); // 1~100 사이의 값

    if (EventRandomValue >= 50) {
        UE_LOG(LogTemp, Log, TEXT("Event Yes"));
        evCnt++;
    }
    else {
        UE_LOG(LogTemp, Log, TEXT("Event No"));
    }
}

float ATrans::distance(FVector first, FVector second)
{
    float distancsx = (first.X - second.X) * (first.X - second.X);
    float distancsy = (first.Y - second.Y) * (first.Y - second.Y);
    return FMath::Sqrt(distancsx + distancsy);
}

// Called when the game starts or when spawned
void ATrans::BeginPlay()
{
    Super::BeginPlay();
    //start point
    start = FVector(0, 0, 0);

    for (int i = 0; i < 10; i++) {
        move();
    }

    UE_LOG(LogTemp, Log, TEXT("Totle Event Count: %d Total Distance: %f"), evCnt, totDist);
}

// Called every frame
void ATrans::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 틱 시 수행할 작업
}
