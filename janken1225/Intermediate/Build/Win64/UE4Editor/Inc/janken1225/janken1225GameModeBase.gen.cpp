// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "janken1225/janken1225GameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodejanken1225GameModeBase() {}
// Cross Module References
	JANKEN1225_API UClass* Z_Construct_UClass_Ajanken1225GameModeBase_NoRegister();
	JANKEN1225_API UClass* Z_Construct_UClass_Ajanken1225GameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_janken1225();
// End Cross Module References
	void Ajanken1225GameModeBase::StaticRegisterNativesAjanken1225GameModeBase()
	{
	}
	UClass* Z_Construct_UClass_Ajanken1225GameModeBase_NoRegister()
	{
		return Ajanken1225GameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_Ajanken1225GameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Ajanken1225GameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_janken1225,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Ajanken1225GameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "janken1225GameModeBase.h" },
		{ "ModuleRelativePath", "janken1225GameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_Ajanken1225GameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Ajanken1225GameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Ajanken1225GameModeBase_Statics::ClassParams = {
		&Ajanken1225GameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_Ajanken1225GameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_Ajanken1225GameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Ajanken1225GameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Ajanken1225GameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Ajanken1225GameModeBase, 2822961014);
	template<> JANKEN1225_API UClass* StaticClass<Ajanken1225GameModeBase>()
	{
		return Ajanken1225GameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_Ajanken1225GameModeBase(Z_Construct_UClass_Ajanken1225GameModeBase, &Ajanken1225GameModeBase::StaticClass, TEXT("/Script/janken1225"), TEXT("Ajanken1225GameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Ajanken1225GameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
