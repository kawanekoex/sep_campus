// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "tetris1221/Private/Mesh_Block.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMesh_Block() {}
// Cross Module References
	TETRIS1221_API UClass* Z_Construct_UClass_AMesh_Block_NoRegister();
	TETRIS1221_API UClass* Z_Construct_UClass_AMesh_Block();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	UPackage* Z_Construct_UPackage__Script_tetris1221();
// End Cross Module References
	void AMesh_Block::StaticRegisterNativesAMesh_Block()
	{
	}
	UClass* Z_Construct_UClass_AMesh_Block_NoRegister()
	{
		return AMesh_Block::StaticClass();
	}
	struct Z_Construct_UClass_AMesh_Block_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMesh_Block_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStaticMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_tetris1221,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMesh_Block_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "Mesh_Block.h" },
		{ "ModuleRelativePath", "Private/Mesh_Block.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMesh_Block_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMesh_Block>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMesh_Block_Statics::ClassParams = {
		&AMesh_Block::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMesh_Block_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMesh_Block_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMesh_Block()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMesh_Block_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMesh_Block, 1110184221);
	template<> TETRIS1221_API UClass* StaticClass<AMesh_Block>()
	{
		return AMesh_Block::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMesh_Block(Z_Construct_UClass_AMesh_Block, &AMesh_Block::StaticClass, TEXT("/Script/tetris1221"), TEXT("AMesh_Block"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMesh_Block);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
