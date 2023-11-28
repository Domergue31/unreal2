// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MainPlayer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RICOCHETARROW_MainPlayer_generated_h
#error "MainPlayer.generated.h already included, missing '#pragma once' in MainPlayer.h"
#endif
#define RICOCHETARROW_MainPlayer_generated_h

#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_14_DELEGATE \
static void FOnMove_DelegateWrapper(const FMulticastScriptDelegate& OnMove, float _axis);


#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_SPARSE_DATA
#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_RPC_WRAPPERS
#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_ACCESSORS
#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMainPlayer(); \
	friend struct Z_Construct_UClass_AMainPlayer_Statics; \
public: \
	DECLARE_CLASS(AMainPlayer, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RicochetArrow"), NO_API) \
	DECLARE_SERIALIZER(AMainPlayer)


#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAMainPlayer(); \
	friend struct Z_Construct_UClass_AMainPlayer_Statics; \
public: \
	DECLARE_CLASS(AMainPlayer, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RicochetArrow"), NO_API) \
	DECLARE_SERIALIZER(AMainPlayer)


#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMainPlayer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMainPlayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainPlayer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainPlayer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainPlayer(AMainPlayer&&); \
	NO_API AMainPlayer(const AMainPlayer&); \
public: \
	NO_API virtual ~AMainPlayer();


#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainPlayer(AMainPlayer&&); \
	NO_API AMainPlayer(const AMainPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainPlayer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMainPlayer) \
	NO_API virtual ~AMainPlayer();


#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_10_PROLOG
#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_SPARSE_DATA \
	FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_RPC_WRAPPERS \
	FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_ACCESSORS \
	FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_INCLASS \
	FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_SPARSE_DATA \
	FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_ACCESSORS \
	FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_INCLASS_NO_PURE_DECLS \
	FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RICOCHETARROW_API UClass* StaticClass<class AMainPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_RicochetArrow_Source_RicochetArrow_MainPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
