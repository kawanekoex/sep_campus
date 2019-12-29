// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "tetris1221/Private/Input.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInput() {}
// Cross Module References
	TETRIS1221_API UClass* Z_Construct_UClass_AInput_NoRegister();
	TETRIS1221_API UClass* Z_Construct_UClass_AInput();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_tetris1221();
	TETRIS1221_API UClass* Z_Construct_UClass_ATetris_Mgr_NoRegister();
// End Cross Module References
	void AInput::StaticRegisterNativesAInput()
	{
	}
	UClass* Z_Construct_UClass_AInput_NoRegister()
	{
		return AInput::StaticClass();
	}
	struct Z_Construct_UClass_AInput_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_tetris_mgr_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_tetris_mgr;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInput_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_tetris1221,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInput_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Input.h" },
		{ "ModuleRelativePath", "Private/Input.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInput_Statics::NewProp_tetris_mgr_MetaData[] = {
		{ "Category", "Tetris" },
		{ "ModuleRelativePath", "Private/Input.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInput_Statics::NewProp_tetris_mgr = { "tetris_mgr", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AInput, tetris_mgr), Z_Construct_UClass_ATetris_Mgr_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AInput_Statics::NewProp_tetris_mgr_MetaData, ARRAY_COUNT(Z_Construct_UClass_AInput_Statics::NewProp_tetris_mgr_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AInput_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInput_Statics::NewProp_tetris_mgr,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInput_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInput>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AInput_Statics::ClassParams = {
		&AInput::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AInput_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_AInput_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AInput_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AInput_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AInput()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AInput_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AInput, 3118984681);
	template<> TETRIS1221_API UClass* StaticClass<AInput>()
	{
		return AInput::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AInput(Z_Construct_UClass_AInput, &AInput::StaticClass, TEXT("/Script/tetris1221"), TEXT("AInput"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInput);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
