// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Http.h"
#include "MyJanken.generated.h"

UCLASS()
class AMyJanken : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyJanken();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//���N�G�X�g
	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	void MyHttpCall(int you);
	// HTTP�ʐM���s���ă��X�|���X���Ԃ��Ă����ۂ̃C�x���g����
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	FString& Get_computer_s() {
		return computer_s;
	}

	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	FString& Get_mes() {
		return mes;
	}

	FHttpModule* Http;									//http�N���X

	bool request_frag;									//���N�G�X�g���t���O
	int32 computer;										//����̎�

	UPROPERTY(EditAnywhere, Category = "MyHttpActor")
	FString computer_s;									//����̎�(string)
	UPROPERTY(EditAnywhere, Category = "MyHttpActor")
	FString mes;										//���s

};
