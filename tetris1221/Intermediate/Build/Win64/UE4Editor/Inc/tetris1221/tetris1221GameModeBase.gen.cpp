// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "tetris1221/tetris1221GameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodetetris1221GameModeBase() {}
// Cross Module References
	TETRIS1221_API UClass* Z_Construct_UClass_Atetris1221GameModeBase_NoRegister();
	TETRIS1221_API UClass* Z_Construct_UClass_Atetris1221GameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_tetris1221();
// End Cross Module References
	void Atetris1221GameModeBase::StaticRegisterNativesAtetris1221GameModeBase()
	{
	}
	UClass* Z_Construct_UClass_Atetris1221GameModeBase_NoRegister()
	{
		return Atetris1221GameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_Atetris1221GameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Atetris1221GameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_tetris1221,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Atetris1221GameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "tetris1221GameModeBase.h" },
		{ "ModuleRelativePath", "tetris1221GameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_Atetris1221GameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Atetris1221GameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Atetris1221GameModeBase_Statics::ClassParams = {
		&Atetris1221GameModeBase::StaticClass,
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
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_Atetris1221GameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_Atetris1221GameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Atetris1221GameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Atetris1221GameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Atetris1221GameModeBase, 2700476450);
	template<> TETRIS1221_API UClass* StaticClass<Atetris1221GameModeBase>()
	{
		return Atetris1221GameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_Atetris1221GameModeBase(Z_Construct_UClass_Atetris1221GameModeBase, &Atetris1221GameModeBase::StaticClass, TEXT("/Script/tetris1221"), TEXT("Atetris1221GameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Atetris1221GameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
