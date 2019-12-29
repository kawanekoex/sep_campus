// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "janken1225/Private/MyJanken.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyJanken() {}
// Cross Module References
	JANKEN1225_API UScriptStruct* Z_Construct_UScriptStruct_FUser_i();
	UPackage* Z_Construct_UPackage__Script_janken1225();
	JANKEN1225_API UClass* Z_Construct_UClass_AMyJanken_NoRegister();
	JANKEN1225_API UClass* Z_Construct_UClass_AMyJanken();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	JANKEN1225_API UFunction* Z_Construct_UFunction_AMyJanken_Get_combo();
	JANKEN1225_API UFunction* Z_Construct_UFunction_AMyJanken_Get_computer_s();
	JANKEN1225_API UFunction* Z_Construct_UFunction_AMyJanken_Get_mes();
	JANKEN1225_API UFunction* Z_Construct_UFunction_AMyJanken_Get_use_rank();
	JANKEN1225_API UFunction* Z_Construct_UFunction_AMyJanken_MyHttpCall();
	JANKEN1225_API UFunction* Z_Construct_UFunction_AMyJanken_MyHttpCall2();
	JANKEN1225_API UFunction* Z_Construct_UFunction_AMyJanken_MyHttpCall3();
	JANKEN1225_API UFunction* Z_Construct_UFunction_AMyJanken_Set_name();
// End Cross Module References
class UScriptStruct* FUser_i::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern JANKEN1225_API uint32 Get_Z_Construct_UScriptStruct_FUser_i_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FUser_i, Z_Construct_UPackage__Script_janken1225(), TEXT("User_i"), sizeof(FUser_i), Get_Z_Construct_UScriptStruct_FUser_i_Hash());
	}
	return Singleton;
}
template<> JANKEN1225_API UScriptStruct* StaticStruct<FUser_i>()
{
	return FUser_i::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FUser_i(FUser_i::StaticStruct, TEXT("/Script/janken1225"), TEXT("User_i"), false, nullptr, nullptr);
static struct FScriptStruct_janken1225_StaticRegisterNativesFUser_i
{
	FScriptStruct_janken1225_StaticRegisterNativesFUser_i()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("User_i")),new UScriptStruct::TCppStructOps<FUser_i>);
	}
} ScriptStruct_janken1225_StaticRegisterNativesFUser_i;
	struct Z_Construct_UScriptStruct_FUser_i_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_name_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_combo_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_combo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUser_i_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FUser_i_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FUser_i>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUser_i_Statics::NewProp_name_MetaData[] = {
		{ "Category", "User_i" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FUser_i_Statics::NewProp_name = { "name", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FUser_i, name), METADATA_PARAMS(Z_Construct_UScriptStruct_FUser_i_Statics::NewProp_name_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FUser_i_Statics::NewProp_name_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUser_i_Statics::NewProp_combo_MetaData[] = {
		{ "Category", "User_i" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FUser_i_Statics::NewProp_combo = { "combo", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FUser_i, combo), METADATA_PARAMS(Z_Construct_UScriptStruct_FUser_i_Statics::NewProp_combo_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FUser_i_Statics::NewProp_combo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FUser_i_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUser_i_Statics::NewProp_name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUser_i_Statics::NewProp_combo,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FUser_i_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_janken1225,
		nullptr,
		&NewStructOps,
		"User_i",
		sizeof(FUser_i),
		alignof(FUser_i),
		Z_Construct_UScriptStruct_FUser_i_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FUser_i_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FUser_i_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FUser_i_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FUser_i()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FUser_i_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_janken1225();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("User_i"), sizeof(FUser_i), Get_Z_Construct_UScriptStruct_FUser_i_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FUser_i_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FUser_i_Hash() { return 1756918785U; }
	void AMyJanken::StaticRegisterNativesAMyJanken()
	{
		UClass* Class = AMyJanken::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Get_combo", &AMyJanken::execGet_combo },
			{ "Get_computer_s", &AMyJanken::execGet_computer_s },
			{ "Get_mes", &AMyJanken::execGet_mes },
			{ "Get_use_rank", &AMyJanken::execGet_use_rank },
			{ "MyHttpCall", &AMyJanken::execMyHttpCall },
			{ "MyHttpCall2", &AMyJanken::execMyHttpCall2 },
			{ "MyHttpCall3", &AMyJanken::execMyHttpCall3 },
			{ "Set_name", &AMyJanken::execSet_name },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyJanken_Get_combo_Statics
	{
		struct MyJanken_eventGet_combo_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMyJanken_Get_combo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyJanken_eventGet_combo_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyJanken_Get_combo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyJanken_Get_combo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyJanken_Get_combo_Statics::Function_MetaDataParams[] = {
		{ "Category", "AMyHttpActor" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyJanken_Get_combo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyJanken, nullptr, "Get_combo", nullptr, nullptr, sizeof(MyJanken_eventGet_combo_Parms), Z_Construct_UFunction_AMyJanken_Get_combo_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_Get_combo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyJanken_Get_combo_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_Get_combo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyJanken_Get_combo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyJanken_Get_combo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyJanken_Get_computer_s_Statics
	{
		struct MyJanken_eventGet_computer_s_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyJanken_Get_computer_s_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyJanken_eventGet_computer_s_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyJanken_Get_computer_s_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyJanken_Get_computer_s_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyJanken_Get_computer_s_Statics::Function_MetaDataParams[] = {
		{ "Category", "AMyHttpActor" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyJanken_Get_computer_s_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyJanken, nullptr, "Get_computer_s", nullptr, nullptr, sizeof(MyJanken_eventGet_computer_s_Parms), Z_Construct_UFunction_AMyJanken_Get_computer_s_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_Get_computer_s_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyJanken_Get_computer_s_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_Get_computer_s_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyJanken_Get_computer_s()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyJanken_Get_computer_s_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyJanken_Get_mes_Statics
	{
		struct MyJanken_eventGet_mes_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyJanken_Get_mes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyJanken_eventGet_mes_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyJanken_Get_mes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyJanken_Get_mes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyJanken_Get_mes_Statics::Function_MetaDataParams[] = {
		{ "Category", "AMyHttpActor" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyJanken_Get_mes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyJanken, nullptr, "Get_mes", nullptr, nullptr, sizeof(MyJanken_eventGet_mes_Parms), Z_Construct_UFunction_AMyJanken_Get_mes_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_Get_mes_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyJanken_Get_mes_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_Get_mes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyJanken_Get_mes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyJanken_Get_mes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics
	{
		struct MyJanken_eventGet_use_rank_Parms
		{
			int32 i;
			FUser_i ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_i;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyJanken_eventGet_use_rank_Parms, ReturnValue), Z_Construct_UScriptStruct_FUser_i, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::NewProp_i = { "i", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyJanken_eventGet_use_rank_Parms, i), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::NewProp_i,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::Function_MetaDataParams[] = {
		{ "Category", "AMyHttpActor" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyJanken, nullptr, "Get_use_rank", nullptr, nullptr, sizeof(MyJanken_eventGet_use_rank_Parms), Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyJanken_Get_use_rank()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyJanken_Get_use_rank_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyJanken_MyHttpCall_Statics
	{
		struct MyJanken_eventMyHttpCall_Parms
		{
			int32 you;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_you;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AMyJanken_MyHttpCall_Statics::NewProp_you = { "you", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyJanken_eventMyHttpCall_Parms, you), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyJanken_MyHttpCall_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyJanken_MyHttpCall_Statics::NewProp_you,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyJanken_MyHttpCall_Statics::Function_MetaDataParams[] = {
		{ "Category", "AMyHttpActor" },
		{ "Comment", "//???N?G?X?g\n" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
		{ "ToolTip", "???N?G?X?g" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyJanken_MyHttpCall_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyJanken, nullptr, "MyHttpCall", nullptr, nullptr, sizeof(MyJanken_eventMyHttpCall_Parms), Z_Construct_UFunction_AMyJanken_MyHttpCall_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_MyHttpCall_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyJanken_MyHttpCall_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_MyHttpCall_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyJanken_MyHttpCall()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyJanken_MyHttpCall_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyJanken_MyHttpCall2_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyJanken_MyHttpCall2_Statics::Function_MetaDataParams[] = {
		{ "Category", "AMyHttpActor" },
		{ "Comment", "//???N?G?X?g2(rank???M)\n" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
		{ "ToolTip", "???N?G?X?g2(rank???M)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyJanken_MyHttpCall2_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyJanken, nullptr, "MyHttpCall2", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyJanken_MyHttpCall2_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_MyHttpCall2_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyJanken_MyHttpCall2()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyJanken_MyHttpCall2_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyJanken_MyHttpCall3_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyJanken_MyHttpCall3_Statics::Function_MetaDataParams[] = {
		{ "Category", "AMyHttpActor" },
		{ "Comment", "//???N?G?X?g2(rank???M)\n" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
		{ "ToolTip", "???N?G?X?g2(rank???M)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyJanken_MyHttpCall3_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyJanken, nullptr, "MyHttpCall3", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyJanken_MyHttpCall3_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_MyHttpCall3_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyJanken_MyHttpCall3()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyJanken_MyHttpCall3_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyJanken_Set_name_Statics
	{
		struct MyJanken_eventSet_name_Parms
		{
			FString s;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_s;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyJanken_Set_name_Statics::NewProp_s = { "s", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyJanken_eventSet_name_Parms, s), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyJanken_Set_name_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyJanken_Set_name_Statics::NewProp_s,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyJanken_Set_name_Statics::Function_MetaDataParams[] = {
		{ "Category", "AMyHttpActor" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyJanken_Set_name_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyJanken, nullptr, "Set_name", nullptr, nullptr, sizeof(MyJanken_eventSet_name_Parms), Z_Construct_UFunction_AMyJanken_Set_name_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_Set_name_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyJanken_Set_name_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMyJanken_Set_name_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyJanken_Set_name()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyJanken_Set_name_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMyJanken_NoRegister()
	{
		return AMyJanken::StaticClass();
	}
	struct Z_Construct_UClass_AMyJanken_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mes_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_mes;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_computer_s_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_computer_s;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyJanken_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_janken1225,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyJanken_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyJanken_Get_combo, "Get_combo" }, // 407981818
		{ &Z_Construct_UFunction_AMyJanken_Get_computer_s, "Get_computer_s" }, // 3018415529
		{ &Z_Construct_UFunction_AMyJanken_Get_mes, "Get_mes" }, // 769581636
		{ &Z_Construct_UFunction_AMyJanken_Get_use_rank, "Get_use_rank" }, // 341030290
		{ &Z_Construct_UFunction_AMyJanken_MyHttpCall, "MyHttpCall" }, // 7459921
		{ &Z_Construct_UFunction_AMyJanken_MyHttpCall2, "MyHttpCall2" }, // 1704557453
		{ &Z_Construct_UFunction_AMyJanken_MyHttpCall3, "MyHttpCall3" }, // 908984692
		{ &Z_Construct_UFunction_AMyJanken_Set_name, "Set_name" }, // 2137058946
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyJanken_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyJanken.h" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyJanken_Statics::NewProp_mes_MetaData[] = {
		{ "Category", "MyHttpActor" },
		{ "Comment", "//?????\xcc\x8e?(string)\n" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
		{ "ToolTip", "?????\xcc\x8e?(string)" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMyJanken_Statics::NewProp_mes = { "mes", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyJanken, mes), METADATA_PARAMS(Z_Construct_UClass_AMyJanken_Statics::NewProp_mes_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMyJanken_Statics::NewProp_mes_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyJanken_Statics::NewProp_computer_s_MetaData[] = {
		{ "Category", "MyHttpActor" },
		{ "ModuleRelativePath", "Private/MyJanken.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMyJanken_Statics::NewProp_computer_s = { "computer_s", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyJanken, computer_s), METADATA_PARAMS(Z_Construct_UClass_AMyJanken_Statics::NewProp_computer_s_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMyJanken_Statics::NewProp_computer_s_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyJanken_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyJanken_Statics::NewProp_mes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyJanken_Statics::NewProp_computer_s,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyJanken_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyJanken>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyJanken_Statics::ClassParams = {
		&AMyJanken::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMyJanken_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMyJanken_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMyJanken_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMyJanken_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyJanken()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyJanken_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyJanken, 3579307424);
	template<> JANKEN1225_API UClass* StaticClass<AMyJanken>()
	{
		return AMyJanken::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyJanken(Z_Construct_UClass_AMyJanken, &AMyJanken::StaticClass, TEXT("/Script/janken1225"), TEXT("AMyJanken"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyJanken);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
