// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FUser_i;
#ifdef JANKEN1225_MyJanken_generated_h
#error "MyJanken.generated.h already included, missing '#pragma once' in MyJanken.h"
#endif
#define JANKEN1225_MyJanken_generated_h

#define janken1225_Source_janken1225_Private_MyJanken_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FUser_i_Statics; \
	JANKEN1225_API static class UScriptStruct* StaticStruct();


template<> JANKEN1225_API UScriptStruct* StaticStruct<struct FUser_i>();

#define janken1225_Source_janken1225_Private_MyJanken_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSet_name) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Set_name(Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGet_use_rank) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_i); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FUser_i*)Z_Param__Result=P_THIS->Get_use_rank(Z_Param_i); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGet_combo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->Get_combo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGet_mes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->Get_mes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGet_computer_s) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->Get_computer_s(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMyHttpCall3) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MyHttpCall3(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMyHttpCall2) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MyHttpCall2(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMyHttpCall) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_you); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MyHttpCall(Z_Param_you); \
		P_NATIVE_END; \
	}


#define janken1225_Source_janken1225_Private_MyJanken_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSet_name) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_s); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Set_name(Z_Param_s); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGet_use_rank) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_i); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FUser_i*)Z_Param__Result=P_THIS->Get_use_rank(Z_Param_i); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGet_combo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->Get_combo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGet_mes) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->Get_mes(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGet_computer_s) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->Get_computer_s(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMyHttpCall3) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MyHttpCall3(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMyHttpCall2) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MyHttpCall2(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMyHttpCall) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_you); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MyHttpCall(Z_Param_you); \
		P_NATIVE_END; \
	}


#define janken1225_Source_janken1225_Private_MyJanken_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyJanken(); \
	friend struct Z_Construct_UClass_AMyJanken_Statics; \
public: \
	DECLARE_CLASS(AMyJanken, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/janken1225"), NO_API) \
	DECLARE_SERIALIZER(AMyJanken)


#define janken1225_Source_janken1225_Private_MyJanken_h_22_INCLASS \
private: \
	static void StaticRegisterNativesAMyJanken(); \
	friend struct Z_Construct_UClass_AMyJanken_Statics; \
public: \
	DECLARE_CLASS(AMyJanken, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/janken1225"), NO_API) \
	DECLARE_SERIALIZER(AMyJanken)


#define janken1225_Source_janken1225_Private_MyJanken_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyJanken(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyJanken) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyJanken); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyJanken); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyJanken(AMyJanken&&); \
	NO_API AMyJanken(const AMyJanken&); \
public:


#define janken1225_Source_janken1225_Private_MyJanken_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyJanken(AMyJanken&&); \
	NO_API AMyJanken(const AMyJanken&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyJanken); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyJanken); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyJanken)


#define janken1225_Source_janken1225_Private_MyJanken_h_22_PRIVATE_PROPERTY_OFFSET
#define janken1225_Source_janken1225_Private_MyJanken_h_19_PROLOG
#define janken1225_Source_janken1225_Private_MyJanken_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	janken1225_Source_janken1225_Private_MyJanken_h_22_PRIVATE_PROPERTY_OFFSET \
	janken1225_Source_janken1225_Private_MyJanken_h_22_RPC_WRAPPERS \
	janken1225_Source_janken1225_Private_MyJanken_h_22_INCLASS \
	janken1225_Source_janken1225_Private_MyJanken_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define janken1225_Source_janken1225_Private_MyJanken_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	janken1225_Source_janken1225_Private_MyJanken_h_22_PRIVATE_PROPERTY_OFFSET \
	janken1225_Source_janken1225_Private_MyJanken_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	janken1225_Source_janken1225_Private_MyJanken_h_22_INCLASS_NO_PURE_DECLS \
	janken1225_Source_janken1225_Private_MyJanken_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> JANKEN1225_API UClass* StaticClass<class AMyJanken>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID janken1225_Source_janken1225_Private_MyJanken_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
