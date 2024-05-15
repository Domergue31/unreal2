// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MinimapTest/MinimapTestGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMinimapTestGameMode() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	MINIMAPTEST_API UClass* Z_Construct_UClass_AMinimapTestGameMode();
	MINIMAPTEST_API UClass* Z_Construct_UClass_AMinimapTestGameMode_NoRegister();
	MINIMAPTEST_API UClass* Z_Construct_UClass_AStreamingSourceManager_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MinimapTest();
// End Cross Module References
	void AMinimapTestGameMode::StaticRegisterNativesAMinimapTestGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMinimapTestGameMode);
	UClass* Z_Construct_UClass_AMinimapTestGameMode_NoRegister()
	{
		return AMinimapTestGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AMinimapTestGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_streamingManagerRef_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_streamingManagerRef;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_streamingManager_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_streamingManager;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMinimapTestGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MinimapTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMinimapTestGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMinimapTestGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MinimapTestGameMode.h" },
		{ "ModuleRelativePath", "MinimapTestGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMinimapTestGameMode_Statics::NewProp_streamingManagerRef_MetaData[] = {
		{ "Category", "MinimapTestGameMode" },
		{ "ModuleRelativePath", "MinimapTestGameMode.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMinimapTestGameMode_Statics::NewProp_streamingManagerRef = { "streamingManagerRef", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMinimapTestGameMode, streamingManagerRef), Z_Construct_UClass_UClass, Z_Construct_UClass_AStreamingSourceManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMinimapTestGameMode_Statics::NewProp_streamingManagerRef_MetaData), Z_Construct_UClass_AMinimapTestGameMode_Statics::NewProp_streamingManagerRef_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMinimapTestGameMode_Statics::NewProp_streamingManager_MetaData[] = {
		{ "Category", "MinimapTestGameMode" },
		{ "ModuleRelativePath", "MinimapTestGameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AMinimapTestGameMode_Statics::NewProp_streamingManager = { "streamingManager", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMinimapTestGameMode, streamingManager), Z_Construct_UClass_AStreamingSourceManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMinimapTestGameMode_Statics::NewProp_streamingManager_MetaData), Z_Construct_UClass_AMinimapTestGameMode_Statics::NewProp_streamingManager_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMinimapTestGameMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMinimapTestGameMode_Statics::NewProp_streamingManagerRef,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMinimapTestGameMode_Statics::NewProp_streamingManager,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMinimapTestGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMinimapTestGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMinimapTestGameMode_Statics::ClassParams = {
		&AMinimapTestGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMinimapTestGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMinimapTestGameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMinimapTestGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AMinimapTestGameMode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMinimapTestGameMode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AMinimapTestGameMode()
	{
		if (!Z_Registration_Info_UClass_AMinimapTestGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMinimapTestGameMode.OuterSingleton, Z_Construct_UClass_AMinimapTestGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMinimapTestGameMode.OuterSingleton;
	}
	template<> MINIMAPTEST_API UClass* StaticClass<AMinimapTestGameMode>()
	{
		return AMinimapTestGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMinimapTestGameMode);
	AMinimapTestGameMode::~AMinimapTestGameMode() {}
	struct Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_MinimapTestGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_MinimapTestGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMinimapTestGameMode, AMinimapTestGameMode::StaticClass, TEXT("AMinimapTestGameMode"), &Z_Registration_Info_UClass_AMinimapTestGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMinimapTestGameMode), 3788539488U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_MinimapTestGameMode_h_931619014(TEXT("/Script/MinimapTest"),
		Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_MinimapTestGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_MinimapTestGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
