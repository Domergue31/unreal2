// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MinimapTest/StreamingSourceManagerSubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStreamingSourceManagerSubsystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UTickableWorldSubsystem();
	MINIMAPTEST_API UClass* Z_Construct_UClass_ACustomWorldSettings_NoRegister();
	MINIMAPTEST_API UClass* Z_Construct_UClass_ARecordCamera_NoRegister();
	MINIMAPTEST_API UClass* Z_Construct_UClass_UStreamingSourceComponent_NoRegister();
	MINIMAPTEST_API UClass* Z_Construct_UClass_UStreamingSourceManagerSubsystem();
	MINIMAPTEST_API UClass* Z_Construct_UClass_UStreamingSourceManagerSubsystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MinimapTest();
// End Cross Module References
	void UStreamingSourceManagerSubsystem::StaticRegisterNativesUStreamingSourceManagerSubsystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStreamingSourceManagerSubsystem);
	UClass* Z_Construct_UClass_UStreamingSourceManagerSubsystem_NoRegister()
	{
		return UStreamingSourceManagerSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics
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
	UObject* (*const Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UTickableWorldSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_MinimapTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "StreamingSourceManagerSubsystem.h" },
		{ "ModuleRelativePath", "StreamingSourceManagerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_allStreamingSources_Inner = { "allStreamingSources", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStreamingSourceComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_allStreamingSources_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "StreamingSourceManagerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_allStreamingSources = { "allStreamingSources", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStreamingSourceManagerSubsystem, allStreamingSources), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_allStreamingSources_MetaData), Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_allStreamingSources_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_miniMapCamera_MetaData[] = {
		{ "ModuleRelativePath", "StreamingSourceManagerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_miniMapCamera = { "miniMapCamera", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStreamingSourceManagerSubsystem, miniMapCamera), Z_Construct_UClass_ARecordCamera_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_miniMapCamera_MetaData), Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_miniMapCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_worldSettings_MetaData[] = {
		{ "ModuleRelativePath", "StreamingSourceManagerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_worldSettings = { "worldSettings", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStreamingSourceManagerSubsystem, worldSettings), Z_Construct_UClass_ACustomWorldSettings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_worldSettings_MetaData), Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_worldSettings_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_allStreamingSources_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_allStreamingSources,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_miniMapCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::NewProp_worldSettings,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStreamingSourceManagerSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::ClassParams = {
		&UStreamingSourceManagerSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UStreamingSourceManagerSubsystem()
	{
		if (!Z_Registration_Info_UClass_UStreamingSourceManagerSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStreamingSourceManagerSubsystem.OuterSingleton, Z_Construct_UClass_UStreamingSourceManagerSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UStreamingSourceManagerSubsystem.OuterSingleton;
	}
	template<> MINIMAPTEST_API UClass* StaticClass<UStreamingSourceManagerSubsystem>()
	{
		return UStreamingSourceManagerSubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UStreamingSourceManagerSubsystem);
	UStreamingSourceManagerSubsystem::~UStreamingSourceManagerSubsystem() {}
	struct Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceManagerSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceManagerSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UStreamingSourceManagerSubsystem, UStreamingSourceManagerSubsystem::StaticClass, TEXT("UStreamingSourceManagerSubsystem"), &Z_Registration_Info_UClass_UStreamingSourceManagerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStreamingSourceManagerSubsystem), 3455937264U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceManagerSubsystem_h_3368108580(TEXT("/Script/MinimapTest"),
		Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceManagerSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceManagerSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
