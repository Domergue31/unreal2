// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RicochetArrow/RicochetArrowActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRicochetArrowActor() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	RICOCHETARROW_API UClass* Z_Construct_UClass_AArrow();
	RICOCHETARROW_API UClass* Z_Construct_UClass_ARicochetArrowActor();
	RICOCHETARROW_API UClass* Z_Construct_UClass_ARicochetArrowActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_RicochetArrow();
// End Cross Module References
	void ARicochetArrowActor::StaticRegisterNativesARicochetArrowActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARicochetArrowActor);
	UClass* Z_Construct_UClass_ARicochetArrowActor_NoRegister()
	{
		return ARicochetArrowActor::StaticClass();
	}
	struct Z_Construct_UClass_ARicochetArrowActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_path_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_path_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_path;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARicochetArrowActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AArrow,
		(UObject* (*)())Z_Construct_UPackage__Script_RicochetArrow,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARicochetArrowActor_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "RicochetArrowActor.h" },
		{ "ModuleRelativePath", "RicochetArrowActor.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ARicochetArrowActor_Statics::NewProp_path_Inner = { "path", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARicochetArrowActor_Statics::NewProp_path_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "RicochetArrowActor.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ARicochetArrowActor_Statics::NewProp_path = { "path", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ARicochetArrowActor, path), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ARicochetArrowActor_Statics::NewProp_path_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARicochetArrowActor_Statics::NewProp_path_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARicochetArrowActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARicochetArrowActor_Statics::NewProp_path_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARicochetArrowActor_Statics::NewProp_path,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARicochetArrowActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARicochetArrowActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ARicochetArrowActor_Statics::ClassParams = {
		&ARicochetArrowActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ARicochetArrowActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ARicochetArrowActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ARicochetArrowActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARicochetArrowActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARicochetArrowActor()
	{
		if (!Z_Registration_Info_UClass_ARicochetArrowActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARicochetArrowActor.OuterSingleton, Z_Construct_UClass_ARicochetArrowActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ARicochetArrowActor.OuterSingleton;
	}
	template<> RICOCHETARROW_API UClass* StaticClass<ARicochetArrowActor>()
	{
		return ARicochetArrowActor::StaticClass();
	}
	ARicochetArrowActor::ARicochetArrowActor() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARicochetArrowActor);
	ARicochetArrowActor::~ARicochetArrowActor() {}
	struct Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetArrowActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetArrowActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ARicochetArrowActor, ARicochetArrowActor::StaticClass, TEXT("ARicochetArrowActor"), &Z_Registration_Info_UClass_ARicochetArrowActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARicochetArrowActor), 586585588U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetArrowActor_h_1094376427(TEXT("/Script/RicochetArrow"),
		Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetArrowActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_RicochetArrow_Source_RicochetArrow_RicochetArrowActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
