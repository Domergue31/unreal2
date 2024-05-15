// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MinimapTest/StreamingSourceManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStreamingSourceManager() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	MINIMAPTEST_API UClass* Z_Construct_UClass_ACustomWorldSettings_NoRegister();
	MINIMAPTEST_API UClass* Z_Construct_UClass_ARecordCamera_NoRegister();
	MINIMAPTEST_API UClass* Z_Construct_UClass_AStreamingSourceManager();
	MINIMAPTEST_API UClass* Z_Construct_UClass_AStreamingSourceManager_NoRegister();
	MINIMAPTEST_API UClass* Z_Construct_UClass_UStreamingSourceComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MinimapTest();
// End Cross Module References
	void AStreamingSourceManager::StaticRegisterNativesAStreamingSourceManager()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AStreamingSourceManager);
	UClass* Z_Construct_UClass_AStreamingSourceManager_NoRegister()
	{
		return AStreamingSourceManager::StaticClass();
	}
	struct Z_Construct_UClass_AStreamingSourceManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_allStreamingSources_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_allStreamingSources_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_allStreamingSources;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_miniMapCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_miniMapCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldSettings_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_worldSettings;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AStreamingSourceManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MinimapTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStreamingSourceManager_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStreamingSourceManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "StreamingSourceManager.h" },
		{ "ModuleRelativePath", "StreamingSourceManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_allStreamingSources_Inner = { "allStreamingSources", nullptr, (EPropertyFlags)0x00000000000a0008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStreamingSourceComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_allStreamingSources_MetaData[] = {
		{ "Category", "StreamingSourceManager" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "StreamingSourceManager.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_allStreamingSources = { "allStreamingSources", nullptr, (EPropertyFlags)0x0040008000020009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStreamingSourceManager, allStreamingSources), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_allStreamingSources_MetaData), Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_allStreamingSources_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_miniMapCamera_MetaData[] = {
		{ "Category", "StreamingSourceManager" },
		{ "ModuleRelativePath", "StreamingSourceManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_miniMapCamera = { "miniMapCamera", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStreamingSourceManager, miniMapCamera), Z_Construct_UClass_ARecordCamera_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_miniMapCamera_MetaData), Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_miniMapCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_worldSettings_MetaData[] = {
		{ "Category", "StreamingSourceManager" },
		{ "ModuleRelativePath", "StreamingSourceManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_worldSettings = { "worldSettings", nullptr, (EPropertyFlags)0x0044000000020001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStreamingSourceManager, worldSettings), Z_Construct_UClass_ACustomWorldSettings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_worldSettings_MetaData), Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_worldSettings_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AStreamingSourceManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_allStreamingSources_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_allStreamingSources,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_miniMapCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStreamingSourceManager_Statics::NewProp_worldSettings,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AStreamingSourceManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStreamingSourceManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AStreamingSourceManager_Statics::ClassParams = {
		&AStreamingSourceManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AStreamingSourceManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AStreamingSourceManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStreamingSourceManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AStreamingSourceManager_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStreamingSourceManager_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AStreamingSourceManager()
	{
		if (!Z_Registration_Info_UClass_AStreamingSourceManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AStreamingSourceManager.OuterSingleton, Z_Construct_UClass_AStreamingSourceManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AStreamingSourceManager.OuterSingleton;
	}
	template<> MINIMAPTEST_API UClass* StaticClass<AStreamingSourceManager>()
	{
		return AStreamingSourceManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStreamingSourceManager);
	AStreamingSourceManager::~AStreamingSourceManager() {}
	struct Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AStreamingSourceManager, AStreamingSourceManager::StaticClass, TEXT("AStreamingSourceManager"), &Z_Registration_Info_UClass_AStreamingSourceManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AStreamingSourceManager), 3830781931U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceManager_h_928588419(TEXT("/Script/MinimapTest"),
		Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
