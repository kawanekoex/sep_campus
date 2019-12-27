// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"Tetris_Mgr.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
	int32& getscore() {
		return mgr->getscore();
	}

	UPROPERTY(EditAnywhere, Category = "Tetris")
	ATetris_Mgr* mgr;
	
	UPROPERTY(EditAnywhere, Category = "Tetris")
	int test;
};
