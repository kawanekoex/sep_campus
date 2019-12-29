// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "tetris1221/Private/StageMgr.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStageMgr() {}
// Cross Module References
	TETRIS1221_API UClass* Z_Construct_UClass_AStageMgr_NoRegister();
	TETRIS1221_API UClass* Z_Construct_UClass_AStageMgr();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_tetris1221();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	void AStageMgr::StaticRegisterNativesAStageMgr()
	{
	}
	UClass* Z_Construct_UClass_AStageMgr_NoRegister()
	{
		return AStageMgr::StaticClass();
	}
	struct Z_Construct_UClass_AStageMgr_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_draw_obj_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_draw_obj;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AStageMgr_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_tetris1221,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStageMgr_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "StageMgr.h" },
		{ "ModuleRelativePath", "Private/StageMgr.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStageMgr_Statics::NewProp_draw_obj_MetaData[] = {
		{ "Category", "Tetris" },
		{ "ModuleRelativePath", "Private/StageMgr.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AStageMgr_Statics::NewProp_draw_obj = { "draw_obj", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AStageMgr, draw_obj), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AStageMgr_Statics::NewProp_draw_obj_MetaData, ARRAY_COUNT(Z_Construct_UClass_AStageMgr_Statics::NewProp_draw_obj_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AStageMgr_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStageMgr_Statics::NewProp_draw_obj,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AStageMgr_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStageMgr>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AStageMgr_Statics::ClassParams = {
		&AStageMgr::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AStageMgr_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_AStageMgr_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AStageMgr_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AStageMgr_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AStageMgr()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AStageMgr_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AStageMgr, 1614857000);
	template<> TETRIS1221_API UClass* StaticClass<AStageMgr>()
	{
		return AStageMgr::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStageMgr(Z_Construct_UClass_AStageMgr, &AStageMgr::StaticClass, TEXT("/Script/tetris1221"), TEXT("AStageMgr"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStageMgr);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
