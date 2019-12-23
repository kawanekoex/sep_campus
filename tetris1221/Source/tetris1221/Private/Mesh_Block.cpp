// Fill out your copyright notice in the Description page of Project Settings.


#include "Mesh_Block.h"
#include"components/StaticMeshComponent.h"
#include"components/MeshComponent.h"
#include"ConstructorHelpers.h"
#include"Engine/StaticMesh.h"

AMesh_Block::AMesh_Block() {
	ConstructorHelpers::FObjectFinder<UStaticMesh> staticMeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	UStaticMeshComponent* mesh = GetStaticMeshComponent();
	UStaticMesh* a = staticMeshAsset.Object;

	SetMobility(EComponentMobility::Type::Movable);
	mesh->SetStaticMesh(a);
}

void AMesh_Block::set() {
	

	
}