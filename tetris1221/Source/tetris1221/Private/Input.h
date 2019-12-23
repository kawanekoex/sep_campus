// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Public//Def.h"
#include"Tetris_Mgr.h"
#include "Input.generated.h"

UCLASS()
class AInput : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AInput();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Tetris")
	ATetris_Mgr* tetris_mgr;

	//std::vector<EACT> act;
	void down();
	void right();
	void left();
	void right_roll();
	void left_roll();
	void hold();
};
