// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Http.h"
#include "MyJanken.generated.h"

USTRUCT(BlueprintType)
struct FUser_i {
	GENERATED_USTRUCT_BODY();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User_i")
	int32 combo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "User_i")
	FString name;
};

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

	//リクエスト2(rank受信)
	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	void MyHttpCall2();
	//リクエスト2(rank送信)
	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	void MyHttpCall3();
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

	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	int32& Get_combo() {
		return player.combo;
	}

	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	FUser_i& Get_use_rank(int32 i) {
		return use_rank[i];
	}

	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	void Set_name(FString s) {
		player.name = s;
	}


	FHttpModule* Http;									//httpクラス

	bool request_frag;									//リクエスト中フラグ
	int32 computer;										//相手の手
	FUser_i player;

	FUser_i use_rank[5];

	UPROPERTY(EditAnywhere, Category = "MyHttpActor")
	FString computer_s;									//相手の手(string)
	UPROPERTY(EditAnywhere, Category = "MyHttpActor")
	FString mes;										//勝敗

};

