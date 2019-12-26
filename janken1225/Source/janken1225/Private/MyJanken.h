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

	//リクエスト
	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	void MyHttpCall(int you);
	// HTTP通信を行ってレスポンスが返ってきた際のイベント処理
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	FString& Get_computer_s() {
		return computer_s;
	}

	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	FString& Get_mes() {
		return mes;
	}

	FHttpModule* Http;									//httpクラス

	bool request_frag;									//リクエスト中フラグ
	int32 computer;										//相手の手

	UPROPERTY(EditAnywhere, Category = "MyHttpActor")
	FString computer_s;									//相手の手(string)
	UPROPERTY(EditAnywhere, Category = "MyHttpActor")
	FString mes;										//勝敗

};
