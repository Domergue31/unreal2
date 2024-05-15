// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MinimapTest/CustomWorldSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomWorldSettings() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AWorldSettings();
	ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
	MINIMAPTEST_API UClass* Z_Construct_UClass_ACustomWorldSettings();
	MINIMAPTEST_API UClass* Z_Construct_UClass_ACustomWorldSettings_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MinimapTest();
// End Cross Module References
	void ACustomWorldSettings::StaticRegisterNativesACustomWorldSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACustomWorldSettings);
	UClass* Z_Construct_UClass_ACustomWorldSettings_NoRegister()
	{
		return ACustomWorldSettings::StaticClass();
	}
	struct Z_Construct_UClass_ACustomWorldSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_baseHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_baseHeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_depthScale_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_depthScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_temp_currentWeather_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_temp_currentWeather;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_subLevels_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_subLevels_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_subLevels_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_subLevels;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACustomWorldSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AWorldSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_MinimapTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACustomWorldSettings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACustomWorldSettings_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Actor Advanced Display Events Object Attachment Info Input Blueprint Layers Tags Replication Input Movement Collision Transformation HLOD DataLayers" },
		{ "IncludePath", "CustomWorldSettings.h" },
		{ "ModuleRelativePath", "CustomWorldSettings.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_baseHeight_MetaData[] = {
		{ "Category", "StreamingManagerSubsystem" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "CustomWorldSettings.h" },
		{ "UMin", "0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_baseHeight = { "baseHeight", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACustomWorldSettings, baseHeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_baseHeight_MetaData), Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_baseHeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_depthScale_MetaData[] = {
		{ "Category", "StreamingManagerSubsystem" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "CustomWorldSettings.h" },
		{ "UMin", "0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_depthScale = { "depthScale", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACustomWorldSettings, depthScale), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_depthScale_MetaData), Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_depthScale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_temp_currentWeather_MetaData[] = {
		{ "Category", "SubLevelsData" },
		{ "ModuleRelativePath", "CustomWorldSettings.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_temp_currentWeather = { "temp_currentWeather", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACustomWorldSettings, temp_currentWeather), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_temp_currentWeather_MetaData), Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_temp_currentWeather_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_subLevels_ValueProp = { "subLevels", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_subLevels_Key_KeyProp = { "subLevels_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_subLevels_MetaData[] = {
		{ "Category", "SubLevelsData" },
		{ "ModuleRelativePath", "CustomWorldSettings.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_subLevels = { "subLevels", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACustomWorldSettings, subLevels), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_subLevels_MetaData), Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_subLevels_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACustomWorldSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_baseHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_depthScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_temp_currentWeather,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_subLevels_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_subLevels_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACustomWorldSettings_Statics::NewProp_subLevels,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACustomWorldSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACustomWorldSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACustomWorldSettings_Statics::ClassParams = {
		&ACustomWorldSettings::StaticClass,
		"game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACustomWorldSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACustomWorldSettings_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACustomWorldSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_ACustomWorldSettings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACustomWorldSettings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ACustomWorldSettings()
	{
		if (!Z_Registration_Info_UClass_ACustomWorldSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACustomWorldSettings.OuterSingleton, Z_Construct_UClass_ACustomWorldSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACustomWorldSettings.OuterSingleton;
	}
	template<> MINIMAPTEST_API UClass* StaticClass<ACustomWorldSettings>()
	{
		return ACustomWorldSettings::StaticClass();
	}
	ACustomWorldSettings::ACustomWorldSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACustomWorldSettings);
	ACustomWorldSettings::~ACustomWorldSettings() {}
	struct Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_CustomWorldSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_CustomWorldSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACustomWorldSettings, ACustomWorldSettings::StaticClass, TEXT("ACustomWorldSettings"), &Z_Registration_Info_UClass_ACustomWorldSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACustomWorldSettings), 2481670560U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_CustomWorldSettings_h_3052416889(TEXT("/Script/MinimapTest"),
		Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_CustomWorldSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_CustomWorldSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
