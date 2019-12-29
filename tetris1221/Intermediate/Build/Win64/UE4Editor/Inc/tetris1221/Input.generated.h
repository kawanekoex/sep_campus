// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TETRIS1221_Input_generated_h
#error "Input.generated.h already included, missing '#pragma once' in Input.h"
#endif
#define TETRIS1221_Input_generated_h

#define tetris1221_Source_tetris1221_Private_Input_h_14_RPC_WRAPPERS
#define tetris1221_Source_tetris1221_Private_Input_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define tetris1221_Source_tetris1221_Private_Input_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAInput(); \
	friend struct Z_Construct_UClass_AInput_Statics; \
public: \
	DECLARE_CLASS(AInput, APawn, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/tetris1221"), NO_API) \
	DECLARE_SERIALIZER(AInput)


#define tetris1221_Source_tetris1221_Private_Input_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAInput(); \
	friend struct Z_Construct_UClass_AInput_Statics; \
public: \
	DECLARE_CLASS(AInput, APawn, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/tetris1221"), NO_API) \
	DECLARE_SERIALIZER(AInput)


#define tetris1221_Source_tetris1221_Private_Input_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AInput(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AInput) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInput); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInput); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AInput(AInput&&); \
	NO_API AInput(const AInput&); \
public:


#define tetris1221_Source_tetris1221_Private_Input_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AInput(AInput&&); \
	NO_API AInput(const AInput&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInput); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInput); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AInput)


#define tetris1221_Source_tetris1221_Private_Input_h_14_PRIVATE_PROPERTY_OFFSET
#define tetris1221_Source_tetris1221_Private_Input_h_11_PROLOG
#define tetris1221_Source_tetris1221_Private_Input_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tetris1221_Source_tetris1221_Private_Input_h_14_PRIVATE_PROPERTY_OFFSET \
	tetris1221_Source_tetris1221_Private_Input_h_14_RPC_WRAPPERS \
	tetris1221_Source_tetris1221_Private_Input_h_14_INCLASS \
	tetris1221_Source_tetris1221_Private_Input_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define tetris1221_Source_tetris1221_Private_Input_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	tetris1221_Source_tetris1221_Private_Input_h_14_PRIVATE_PROPERTY_OFFSET \
	tetris1221_Source_tetris1221_Private_Input_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	tetris1221_Source_tetris1221_Private_Input_h_14_INCLASS_NO_PURE_DECLS \
	tetris1221_Source_tetris1221_Private_Input_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TETRIS1221_API UClass* StaticClass<class AInput>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID tetris1221_Source_tetris1221_Private_Input_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
