// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TETRIS1221_Tetris_Mgr_generated_h
#error "Tetris_Mgr.generated.h already included, missing '#pragma once' in Tetris_Mgr.h"
#endif
#define TETRIS1221_Tetris_Mgr_generated_h

#define tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execgetscore) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->getscore(); \
		P_NATIVE_END; \
	}


#define tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execgetscore) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->getscore(); \
		P_NATIVE_END; \
	}


#define tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATetris_Mgr(); \
	friend struct Z_Construct_UClass_ATetris_Mgr_Statics; \
public: \
	DECLARE_CLASS(ATetris_Mgr, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/tetris1221"), NO_API) \
	DECLARE_SERIALIZER(ATetris_Mgr)


#define tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_INCLASS \
private: \
	static void StaticRegisterNativesATetris_Mgr(); \
	friend struct Z_Construct_UClass_ATetris_Mgr_Statics; \
public: \
	DECLARE_CLASS(ATetris_Mgr, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/tetris1221"), NO_API) \
	DECLARE_SERIALIZER(ATetris_Mgr)


#define tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATetris_Mgr(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATetris_Mgr) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATetris_Mgr); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATetris_Mgr); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATetris_Mgr(ATetris_Mgr&&); \
	NO_API ATetris_Mgr(const ATetris_Mgr&); \
public:


#define tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATetris_Mgr(ATetris_Mgr&&); \
	NO_API ATetris_Mgr(const ATetris_Mgr&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATetris_Mgr); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATetris_Mgr); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATetris_Mgr)


#define tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__stage_obj() { return STRUCT_OFFSET(ATetris_Mgr, stage_obj); }


#define tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_11_PROLOG
#define tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_PRIVATE_PROPERTY_OFFSET \
	tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_RPC_WRAPPERS \
	tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_INCLASS \
	tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_PRIVATE_PROPERTY_OFFSET \
	tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_INCLASS_NO_PURE_DECLS \
	tetris1221_Source_tetris1221_Private_Tetris_Mgr_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TETRIS1221_API UClass* StaticClass<class ATetris_Mgr>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID tetris1221_Source_tetris1221_Private_Tetris_Mgr_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
