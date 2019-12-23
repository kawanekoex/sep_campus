// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Public/Def.h"
#include "Mesh_Block.generated.h"

/**
 * 
 */
UCLASS()
class AMesh_Block : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMesh_Block();

	void set();

	FVector2Int index;
	FColor c;
};
