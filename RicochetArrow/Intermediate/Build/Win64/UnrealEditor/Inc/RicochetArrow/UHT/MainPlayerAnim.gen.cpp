// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RicochetArrow/MainPlayerAnim.h"
#include "../../Source/Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainPlayerAnim() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	RICOCHETARROW_API UClass* Z_Construct_UClass_UMainPlayerAnim();
	RICOCHETARROW_API UClass* Z_Construct_UClass_UMainPlayerAnim_NoRegister();
	UPackage* Z_Construct_UPackage__Script_RicochetArrow();
// End Cross Module References
	DEFINE_FUNCTION(UMainPlayerAnim::execSetSpeed)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param__speed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSpeed(Z_Param__speed);
		P_NATIVE_END;
	}
	void UMainPlayerAnim::StaticRegisterNativesUMainPlayerAnim()
	{
		UClass* Class = UMainPlayerAnim::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetSpeed", &UMainPlayerAnim::execSetSpeed },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics
	{
		struct MainPlayerAnim_eventSetSpeed_Parms
		{
			float _speed;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp__speed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics::NewProp__speed = { "_speed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MainPlayerAnim_eventSetSpeed_Parms, _speed), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics::NewProp__speed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainPlayerAnim.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMainPlayerAnim, nullptr, "SetSpeed", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics::MainPlayerAnim_eventSetSpeed_Parms), Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMainPlayerAnim_SetSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMainPlayerAnim_SetSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMainPlayerAnim);
	UClass* Z_Construct_UClass_UMainPlayerAnim_NoRegister()
	{
		return UMainPlayerAnim::StaticClass();
	}
	struct Z_Construct_UClass_UMainPlayerAnim_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_speed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMainPlayerAnim_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_RicochetArrow,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMainPlayerAnim_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMainPlayerAnim_SetSpeed, "SetSpeed" }, // 1366513574
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMainPlayerAnim_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "MainPlayerAnim.h" },
		{ "ModuleRelativePath", "MainPlayerAnim.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMainPlayerAnim_Statics::NewProp_speed_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "MainPlayerAnim" },
		{ "ModuleRelativePath", "MainPlayerAnim.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMainPlayerAnim_Statics::NewProp_speed = { "speed", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMainPlayerAnim, speed), METADATA_PARAMS(Z_Construct_UClass_UMainPlayerAnim_Statics::NewProp_speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMainPlayerAnim_Statics::NewProp_speed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMainPlayerAnim_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMainPlayerAnim_Statics::NewProp_speed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMainPlayerAnim_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMainPlayerAnim>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMainPlayerAnim_Statics::ClassParams = {
		&UMainPlayerAnim::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMainPlayerAnim_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMainPlayerAnim_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UMainPlayerAnim_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMainPlayerAnim_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMainPlayerAnim()
	{
		if (!Z_Registration_Info_UClass_UMainPlayerAnim.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMainPlayerAnim.OuterSingleton, Z_Construct_UClass_UMainPlayerAnim_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMainPlayerAnim.OuterSingleton;
	}
	template<> RICOCHETARROW_API UClass* StaticClass<UMainPlayerAnim>()
	{
		return UMainPlayerAnim::StaticClass();
	}
	UMainPlayerAnim::UMainPlayerAnim(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMainPlayerAnim);
	UMainPlayerAnim::~UMainPlayerAnim() {}
	struct Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_MainPlayerAnim_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_MainPlayerAnim_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMainPlayerAnim, UMainPlayerAnim::StaticClass, TEXT("UMainPlayerAnim"), &Z_Registration_Info_UClass_UMainPlayerAnim, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMainPlayerAnim), 757339096U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_MainPlayerAnim_h_477082516(TEXT("/Script/RicochetArrow"),
		Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_MainPlayerAnim_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_MainPlayerAnim_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
