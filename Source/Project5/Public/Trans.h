// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trans.generated.h"

UCLASS()
class PROJECT5_API ATrans : public AActor
{
	GENERATED_BODY()
	
private:
	FVector start;
	int32 evCnt;
	float totDist;

public:	
	// Sets default values for this actor's properties
	ATrans();
	void move();
	int32 step();
	void createEvent();
	float distance(FVector first, FVector second);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
