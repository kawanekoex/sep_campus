// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include<vector>
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"

#define STAGE_MAX_Y 20		//ステージ縦幅
#define STAGE_MAX_X 10		//ステージ横幅
#define BLOCK_MAX_Y 5		//ブロック最大縦幅
#define BLOCK_MAX_X 5		//ブロック最大横幅
#define BLOCK_TYPE 7		//ブロックの種類最大数
#define MOVE_TIME_MAX 7		//有余
#define RAND_NUM_MAX_SIZE 30
#define BLOCK_SIZE 100.f

/**
 * 
 */
class TETRIS1221_API Def
{
public:
	Def();
	~Def();
};

struct FVector2Int {
	int32 x, y;

	FVector2Int(int32 x = 0, int32 y = 0) : x(x), y(y) {}

	FVector2Int operator + (FVector2Int a) {
		FVector2Int b;
		b.x = this->x + a.x;
		b.y = this->y + a.y;
		return b;
	}
	FVector2Int operator - (FVector2Int a) {
		FVector2Int b;
		b.x = this->x - a.x;
		b.y = this->y - a.y;
		return b;
	}
	FVector2Int operator * (FVector2Int a) {
		FVector2Int b;
		b.x = this->x * a.x;
		b.y = this->y * a.y;
		return b;
	}
	FVector2Int operator / (FVector2Int a) {
		FVector2Int b;
		b.x = this->x / a.x;
		b.y = this->y / a.y;
		return b;
	}
	void operator += (FVector2Int a) {
		this->x += a.x;
		this->y += a.y;
	}
	void operator -= (FVector2Int a) {
		this->x -= a.x;
		this->y -= a.y;
	}
	void operator *= (FVector2Int a) {
		this->x *= a.x;
		this->y *= a.y;
	}
	void operator /= (FVector2Int a) {
		this->x /= a.x;
		this->y /= a.y;
	}
};

struct MoveBlock
{
	FVector2Int v;
	FVector2Int pos;
	int32 id;
	FColor co;
	float move_time;
	float wait_time;
	bool block_date[BLOCK_MAX_Y][BLOCK_MAX_X];
	std::vector<FVector2Int> block_pos;
};

struct Block
{
	FColor co;
	//bool block_date[BLOCK_MAX_Y][BLOCK_MAX_X];
	bool draw_frag = false;
	int32 id = 0;
	AActor* obj;

	void operator = (Block a) {
		this->co = a.co;
		this->draw_frag = a.draw_frag;
		this->id = a.id;
		this->obj = a.obj;
	}
};
struct NextBlock
{
	FColor co;
	bool block_date[BLOCK_MAX_Y][BLOCK_MAX_X];
};

enum ETETRIS_STEP
{
	NO,
	SPWAN,
	MOVE
};

enum EACT
{
	NO_ACT,
	RIGHT,
	LEFT,
	DOWN,
	RIGHT_ROLL,
	LEFT_ROLL,
	HOLD
};