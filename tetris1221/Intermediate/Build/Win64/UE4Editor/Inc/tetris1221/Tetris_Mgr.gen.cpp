// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "tetris1221/Private/Tetris_Mgr.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTetris_Mgr() {}
// Cross Module References
	TETRIS1221_API UClass* Z_Construct_UClass_ATetris_Mgr_NoRegister();
	TETRIS1221_API UClass* Z_Construct_UClass_ATetris_Mgr();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_tetris1221();
	TETRIS1221_API UFunction* Z_Construct_UFunction_ATetris_Mgr_getscore();
	TETRIS1221_API UClass* Z_Construct_UClass_AStageMgr_NoRegister();
// End Cross Module References
	void ATetris_Mgr::StaticRegisterNativesATetris_Mgr()
	{
		UClass* Class = ATetris_Mgr::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "getscore", &ATetris_Mgr::execgetscore },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATetris_Mgr_getscore_Statics
	{
		struct Tetris_Mgr_eventgetscore_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ATetris_Mgr_getscore_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Tetris_Mgr_eventgetscore_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATetris_Mgr_getscore_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATetris_Mgr_getscore_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATetris_Mgr_getscore_Statics::Function_MetaDataParams[] = {
		{ "Category", "Tetris" },
		{ "ModuleRelativePath", "Private/Tetris_Mgr.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATetris_Mgr_getscore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATetris_Mgr, nullptr, "getscore", nullptr, nullptr, sizeof(Tetris_Mgr_eventgetscore_Parms), Z_Construct_UFunction_ATetris_Mgr_getscore_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATetris_Mgr_getscore_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATetris_Mgr_getscore_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATetris_Mgr_getscore_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATetris_Mgr_getscore()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATetris_Mgr_getscore_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATetris_Mgr_NoRegister()
	{
		return ATetris_Mgr::StaticClass();
	}
	struct Z_Construct_UClass_ATetris_Mgr_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_stage_obj_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_stage_obj;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATetris_Mgr_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_tetris1221,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATetris_Mgr_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATetris_Mgr_getscore, "getscore" }, // 485250927
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATetris_Mgr_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Tetris_Mgr.h" },
		{ "ModuleRelativePath", "Private/Tetris_Mgr.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATetris_Mgr_Statics::NewProp_stage_obj_MetaData[] = {
		{ "Category", "Tetris" },
		{ "ModuleRelativePath", "Private/Tetris_Mgr.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATetris_Mgr_Statics::NewProp_stage_obj = { "stage_obj", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATetris_Mgr, stage_obj), Z_Construct_UClass_AStageMgr_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATetris_Mgr_Statics::NewProp_stage_obj_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATetris_Mgr_Statics::NewProp_stage_obj_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATetris_Mgr_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATetris_Mgr_Statics::NewProp_stage_obj,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATetris_Mgr_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATetris_Mgr>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATetris_Mgr_Statics::ClassParams = {
		&ATetris_Mgr::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATetris_Mgr_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_ATetris_Mgr_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_ATetris_Mgr_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATetris_Mgr_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATetris_Mgr()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATetris_Mgr_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATetris_Mgr, 299153179);
	template<> TETRIS1221_API UClass* StaticClass<ATetris_Mgr>()
	{
		return ATetris_Mgr::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATetris_Mgr(Z_Construct_UClass_ATetris_Mgr, &ATetris_Mgr::StaticClass, TEXT("/Script/tetris1221"), TEXT("ATetris_Mgr"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATetris_Mgr);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
