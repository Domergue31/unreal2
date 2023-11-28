// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RicochetArrow/RicochetArrowGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRicochetArrowGameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	RICOCHETARROW_API UClass* Z_Construct_UClass_ARicochetArrowGameModeBase();
	RICOCHETARROW_API UClass* Z_Construct_UClass_ARicochetArrowGameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_RicochetArrow();
// End Cross Module References
	void ARicochetArrowGameModeBase::StaticRegisterNativesARicochetArrowGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARicochetArrowGameModeBase);
	UClass* Z_Construct_UClass_ARicochetArrowGameModeBase_NoRegister()
	{
		return ARicochetArrowGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ARicochetArrowGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARicochetArrowGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_RicochetArrow,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARicochetArrowGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "RicochetArrowGameModeBase.h" },
		{ "ModuleRelativePath", "RicochetArrowGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARicochetArrowGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARicochetArrowGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ARicochetArrowGameModeBase_Statics::ClassParams = {
		&ARicochetArrowGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ARicochetArrowGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARicochetArrowGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARicochetArrowGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ARicochetArrowGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARicochetArrowGameModeBase.OuterSingleton, Z_Construct_UClass_ARicochetArrowGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ARicochetArrowGameModeBase.OuterSingleton;
	}
	template<> RICOCHETARROW_API UClass* StaticClass<ARicochetArrowGameModeBase>()
	{
		return ARicochetArrowGameModeBase::StaticClass();
	}
	ARicochetArrowGameModeBase::ARicochetArrowGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARicochetArrowGameModeBase);
	ARicochetArrowGameModeBase::~ARicochetArrowGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetArrowGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetArrowGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ARicochetArrowGameModeBase, ARicochetArrowGameModeBase::StaticClass, TEXT("ARicochetArrowGameModeBase"), &Z_Registration_Info_UClass_ARicochetArrowGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARicochetArrowGameModeBase), 2505956353U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetArrowGameModeBase_h_664622223(TEXT("/Script/RicochetArrow"),
		Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetArrowGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetArrowGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
