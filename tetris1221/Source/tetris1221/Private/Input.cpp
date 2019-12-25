// Fill out your copyright notice in the Description page of Project Settings.


#include "Input.h"
#include"Components/InputComponent.h"

// Sets default values
AInput::AInput()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AInput::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInput::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//tetris_mgr->act = act;
}

// Called to bind functionality to input
void AInput::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UE_LOG(LogTemp, Warning, TEXT("input"));
	PlayerInputComponent->BindAction("DOWN", IE_Repeat, this, &AInput::down);
	PlayerInputComponent->BindAction("RIGHT", IE_Pressed, this, &AInput::right);
	PlayerInputComponent->BindAction("LEFT", IE_Pressed, this, &AInput::left);
	PlayerInputComponent->BindAction("RIGHT_ROLL", IE_Pressed, this, &AInput::right_roll);
	PlayerInputComponent->BindAction("LEFT_ROLL", IE_Pressed, this, &AInput::left_roll);
	PlayerInputComponent->BindAction("HOLD", IE_Pressed, this, &AInput::hold);
}

void AInput::down() {
	tetris_mgr->act.push_back(EACT::DOWN);
	
}
void AInput::right() {
	tetris_mgr->act.push_back(EACT::RIGHT);
}
void AInput::left() {
	tetris_mgr->act.push_back(EACT::LEFT);
}
void AInput::right_roll() {
	tetris_mgr->act.push_back(EACT::RIGHT_ROLL);
}
void AInput::left_roll() {
	tetris_mgr->act.push_back(EACT::LEFT_ROLL);
}
void AInput::hold() {
	tetris_mgr->act.push_back(EACT::HOLD);
}
