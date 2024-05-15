// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MinimapTest/MiniMapCamera.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMiniMapCamera() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACameraActor();
	MINIMAPTEST_API UClass* Z_Construct_UClass_AMiniMapCamera();
	MINIMAPTEST_API UClass* Z_Construct_UClass_AMiniMapCamera_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MinimapTest();
// End Cross Module References
	void AMiniMapCamera::StaticRegisterNativesAMiniMapCamera()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMiniMapCamera);
	UClass* Z_Construct_UClass_AMiniMapCamera_NoRegister()
	{
		return AMiniMapCamera::StaticClass();
	}
	struct Z_Construct_UClass_AMiniMapCamera_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMiniMapCamera_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACameraActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MinimapTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMiniMapCamera_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMiniMapCamera_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Input Rendering" },
		{ "IncludePath", "MiniMapCamera.h" },
		{ "ModuleRelativePath", "MiniMapCamera.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMiniMapCamera_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMiniMapCamera>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMiniMapCamera_Statics::ClassParams = {
		&AMiniMapCamera::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMiniMapCamera_Statics::Class_MetaDataParams), Z_Construct_UClass_AMiniMapCamera_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AMiniMapCamera()
	{
		if (!Z_Registration_Info_UClass_AMiniMapCamera.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMiniMapCamera.OuterSingleton, Z_Construct_UClass_AMiniMapCamera_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMiniMapCamera.OuterSingleton;
	}
	template<> MINIMAPTEST_API UClass* StaticClass<AMiniMapCamera>()
	{
		return AMiniMapCamera::StaticClass();
	}
	AMiniMapCamera::AMiniMapCamera(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMiniMapCamera);
	AMiniMapCamera::~AMiniMapCamera() {}
	struct Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_MiniMapCamera_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_MiniMapCamera_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMiniMapCamera, AMiniMapCamera::StaticClass, TEXT("AMiniMapCamera"), &Z_Registration_Info_UClass_AMiniMapCamera, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMiniMapCamera), 2434509950U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_MiniMapCamera_h_3798947875(TEXT("/Script/MinimapTest"),
		Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_MiniMapCamera_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_MiniMapCamera_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
