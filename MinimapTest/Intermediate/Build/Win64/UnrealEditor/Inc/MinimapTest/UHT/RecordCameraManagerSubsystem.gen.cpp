// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MinimapTest/RecordCameraManagerSubsystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRecordCameraManagerSubsystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	MINIMAPTEST_API UClass* Z_Construct_UClass_URecordCameraManagerSubsystem();
	MINIMAPTEST_API UClass* Z_Construct_UClass_URecordCameraManagerSubsystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MinimapTest();
// End Cross Module References
	void URecordCameraManagerSubsystem::StaticRegisterNativesURecordCameraManagerSubsystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URecordCameraManagerSubsystem);
	UClass* Z_Construct_UClass_URecordCameraManagerSubsystem_NoRegister()
	{
		return URecordCameraManagerSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_URecordCameraManagerSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URecordCameraManagerSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_MinimapTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URecordCameraManagerSubsystem_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecordCameraManagerSubsystem_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "RecordCameraManagerSubsystem.h" },
		{ "ModuleRelativePath", "RecordCameraManagerSubsystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URecordCameraManagerSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URecordCameraManagerSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URecordCameraManagerSubsystem_Statics::ClassParams = {
		&URecordCameraManagerSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URecordCameraManagerSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_URecordCameraManagerSubsystem_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_URecordCameraManagerSubsystem()
	{
		if (!Z_Registration_Info_UClass_URecordCameraManagerSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URecordCameraManagerSubsystem.OuterSingleton, Z_Construct_UClass_URecordCameraManagerSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URecordCameraManagerSubsystem.OuterSingleton;
	}
	template<> MINIMAPTEST_API UClass* StaticClass<URecordCameraManagerSubsystem>()
	{
		return URecordCameraManagerSubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URecordCameraManagerSubsystem);
	URecordCameraManagerSubsystem::~URecordCameraManagerSubsystem() {}
	struct Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_RecordCameraManagerSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_RecordCameraManagerSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URecordCameraManagerSubsystem, URecordCameraManagerSubsystem::StaticClass, TEXT("URecordCameraManagerSubsystem"), &Z_Registration_Info_UClass_URecordCameraManagerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URecordCameraManagerSubsystem), 587267893U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_RecordCameraManagerSubsystem_h_2797662037(TEXT("/Script/MinimapTest"),
		Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_RecordCameraManagerSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_RecordCameraManagerSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
