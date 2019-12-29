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

	//���N�G�X�g
	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	void MyHttpCall(int you);

	//���N�G�X�g2(rank��M)
	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	void MyHttpCall2();
	//���N�G�X�g2(rank���M)
	UFUNCTION(BlueprintCallable, Category = "AMyHttpActor")
	void MyHttpCall3();
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


	FHttpModule* Http;									//http�N���X

	bool request_frag;									//���N�G�X�g���t���O
	int32 computer;										//����̎�
	FUser_i player;

	FUser_i use_rank[5];

	UPROPERTY(EditAnywhere, Category = "MyHttpActor")
	FString computer_s;									//����̎�(string)
	UPROPERTY(EditAnywhere, Category = "MyHttpActor")
	FString mes;										//���s

};

