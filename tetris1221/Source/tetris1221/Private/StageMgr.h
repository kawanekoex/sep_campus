// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Public//Def.h"
#include "StageMgr.generated.h"

UCLASS()
class AStageMgr : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStageMgr();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float aaa;

	UPROPERTY(EditAnywhere, Category = "Tetris")
	UClass* draw_obj;

	Block block_draw[STAGE_MAX_Y][STAGE_MAX_X];
	Block block_draw_check[STAGE_MAX_Y][STAGE_MAX_X];
};
