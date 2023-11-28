// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RicochetArrow/RicochetGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRicochetGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	RICOCHETARROW_API UClass* Z_Construct_UClass_ARicochetGameMode();
	RICOCHETARROW_API UClass* Z_Construct_UClass_ARicochetGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_RicochetArrow();
// End Cross Module References
	void ARicochetGameMode::StaticRegisterNativesARicochetGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARicochetGameMode);
	UClass* Z_Construct_UClass_ARicochetGameMode_NoRegister()
	{
		return ARicochetGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ARicochetGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARicochetGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_RicochetArrow,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARicochetGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "RicochetGameMode.h" },
		{ "ModuleRelativePath", "RicochetGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARicochetGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARicochetGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ARicochetGameMode_Statics::ClassParams = {
		&ARicochetGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ARicochetGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARicochetGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARicochetGameMode()
	{
		if (!Z_Registration_Info_UClass_ARicochetGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARicochetGameMode.OuterSingleton, Z_Construct_UClass_ARicochetGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ARicochetGameMode.OuterSingleton;
	}
	template<> RICOCHETARROW_API UClass* StaticClass<ARicochetGameMode>()
	{
		return ARicochetGameMode::StaticClass();
	}
	ARicochetGameMode::ARicochetGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARicochetGameMode);
	ARicochetGameMode::~ARicochetGameMode() {}
	struct Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ARicochetGameMode, ARicochetGameMode::StaticClass, TEXT("ARicochetGameMode"), &Z_Registration_Info_UClass_ARicochetGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARicochetGameMode), 1518984142U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetGameMode_h_1963381293(TEXT("/Script/RicochetArrow"),
		Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
