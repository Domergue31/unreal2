// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RicochetArrow/RicochetLauncherSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRicochetLauncherSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EObjectTypeQuery();
	RICOCHETARROW_API UClass* Z_Construct_UClass_ARicochetArrowActor_NoRegister();
	RICOCHETARROW_API UClass* Z_Construct_UClass_URicochetLauncherSettings();
	RICOCHETARROW_API UClass* Z_Construct_UClass_URicochetLauncherSettings_NoRegister();
	UPackage* Z_Construct_UPackage__Script_RicochetArrow();
// End Cross Module References
	void URicochetLauncherSettings::StaticRegisterNativesURicochetLauncherSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URicochetLauncherSettings);
	UClass* Z_Construct_UClass_URicochetLauncherSettings_NoRegister()
	{
		return URicochetLauncherSettings::StaticClass();
	}
	struct Z_Construct_UClass_URicochetLauncherSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ricochetArrowRef_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ricochetArrowRef;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hitNumber_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_hitNumber;
		static const UECodeGen_Private::FBytePropertyParams NewProp_objectsType_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_objectsType_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_objectsType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_range_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_range;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URicochetLauncherSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_RicochetArrow,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URicochetLauncherSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "RicochetLauncherSettings.h" },
		{ "ModuleRelativePath", "RicochetLauncherSettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_ricochetArrowRef_MetaData[] = {
		{ "Category", "Shoot" },
		{ "ModuleRelativePath", "RicochetLauncherSettings.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_ricochetArrowRef = { "ricochetArrowRef", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URicochetLauncherSettings, ricochetArrowRef), Z_Construct_UClass_UClass, Z_Construct_UClass_ARicochetArrowActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_ricochetArrowRef_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_ricochetArrowRef_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_hitNumber_MetaData[] = {
		{ "Category", "Shoot" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "RicochetLauncherSettings.h" },
		{ "UIMin", "1" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_hitNumber = { "hitNumber", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URicochetLauncherSettings, hitNumber), METADATA_PARAMS(Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_hitNumber_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_hitNumber_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_objectsType_Inner = { "objectsType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UEnum_Engine_EObjectTypeQuery, METADATA_PARAMS(nullptr, 0) }; // 3629342158
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_objectsType_MetaData[] = {
		{ "Category", "Shoot" },
		{ "ModuleRelativePath", "RicochetLauncherSettings.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_objectsType = { "objectsType", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URicochetLauncherSettings, objectsType), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_objectsType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_objectsType_MetaData)) }; // 3629342158
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_range_MetaData[] = {
		{ "Category", "Shoot" },
		{ "ClampMin", "100" },
		{ "ModuleRelativePath", "RicochetLauncherSettings.h" },
		{ "UIMin", "100" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_range = { "range", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URicochetLauncherSettings, range), METADATA_PARAMS(Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_range_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_range_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URicochetLauncherSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_ricochetArrowRef,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_hitNumber,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_objectsType_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_objectsType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URicochetLauncherSettings_Statics::NewProp_range,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URicochetLauncherSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URicochetLauncherSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URicochetLauncherSettings_Statics::ClassParams = {
		&URicochetLauncherSettings::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_URicochetLauncherSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_URicochetLauncherSettings_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_URicochetLauncherSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URicochetLauncherSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URicochetLauncherSettings()
	{
		if (!Z_Registration_Info_UClass_URicochetLauncherSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URicochetLauncherSettings.OuterSingleton, Z_Construct_UClass_URicochetLauncherSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URicochetLauncherSettings.OuterSingleton;
	}
	template<> RICOCHETARROW_API UClass* StaticClass<URicochetLauncherSettings>()
	{
		return URicochetLauncherSettings::StaticClass();
	}
	URicochetLauncherSettings::URicochetLauncherSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URicochetLauncherSettings);
	URicochetLauncherSettings::~URicochetLauncherSettings() {}
	struct Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetLauncherSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetLauncherSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URicochetLauncherSettings, URicochetLauncherSettings::StaticClass, TEXT("URicochetLauncherSettings"), &Z_Registration_Info_UClass_URicochetLauncherSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URicochetLauncherSettings), 4072596831U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetLauncherSettings_h_4175803413(TEXT("/Script/RicochetArrow"),
		Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetLauncherSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetLauncherSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
