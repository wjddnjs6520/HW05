#include "Trans.h"
#include "Engine/Engine.h"

// Sets default values
ATrans::ATrans()
{
    PrimaryActorTick.bCanEverTick = true; // ƽ�� ����Ѵٸ� �ʿ�
}

void ATrans::move()
{
    //�̺�Ʈ �Լ� ����
    createEvent();

    //���� ��ǥ ����
    FVector temp = start;

    //���� ��ǥ �̵�
    start.X = step();
    start.Y = step();

    //���� ��ǥ ���� �Ÿ� ����� ���� ����
    float currentds = distance(temp, start);

    //��ü �̵��Ÿ��� �߰�.
    totDist += currentds;

    //�α� Ȯ���� ���� ������ int32�� �����ؼ� ���
    UE_LOG(LogTemp, Warning, TEXT("x: %d y: %d"), (int32)start.X, (int32)start.Y);

    //���� ��ǥ ���� �̵� �Ÿ� ���
    UE_LOG(LogTemp, Warning, TEXT("cuurent distance: %f"), currentds);
}

int32 ATrans::step()
{
    int32 RandomValue = FMath::RandRange(0, 1); // 0�̳� 1

    return RandomValue;
}

void ATrans::createEvent()
{
    int32 EventRandomValue = FMath::RandRange(1, 100); // 1~100 ������ ��

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

    // ƽ �� ������ �۾�
}
