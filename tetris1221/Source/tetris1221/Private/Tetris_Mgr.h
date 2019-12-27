// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"Public/Def.h"
#include"StageMgr.h"
#include "Tetris_Mgr.generated.h"

UCLASS()
class ATetris_Mgr : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATetris_Mgr();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Tetris")
	int& getscore() {
		return score;
	}


	Block block_stage[STAGE_MAX_Y + BLOCK_MAX_Y][STAGE_MAX_X];
	int32 score;
	int32 draw_score;
	unsigned short rand_num[RAND_NUM_MAX_SIZE];
	int32 rand_num_index;
	NextBlock n_block[7];
	std::vector<EACT> act;
private:
	Block block_draw[2][STAGE_MAX_Y][STAGE_MAX_X];
	MoveBlock m_block;
	bool gane_over;
	int32 next[5];
	int32 hold;
	float game_time;



	UPROPERTY(EditAnywhere, Category = "Tetris")
	AStageMgr* stage_obj;


	void wait_block(float DeltaTime);
	void spawn_block();
	void block_hold();
	void act_interface(float DeltaTime);
	bool wall_judg_block();
	void kaitenn(bool right_f);
	void tumeru(int d_y);
	void Load();
}; 
