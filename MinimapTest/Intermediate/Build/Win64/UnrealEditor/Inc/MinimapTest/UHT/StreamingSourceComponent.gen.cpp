// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MinimapTest/StreamingSourceComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStreamingSourceComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	MINIMAPTEST_API UClass* Z_Construct_UClass_UStreamingSourceComponent();
	MINIMAPTEST_API UClass* Z_Construct_UClass_UStreamingSourceComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MinimapTest();
// End Cross Module References
	void UStreamingSourceComponent::StaticRegisterNativesUStreamingSourceComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStreamingSourceComponent);
	UClass* Z_Construct_UClass_UStreamingSourceComponent_NoRegister()
	{
		return UStreamingSourceComponent::StaticClass();
	}
	struct Z_Construct_UClass_UStreamingSourceComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_enableStreamingSource_MetaData[];
#endif
		static void NewProp_enableStreamingSource_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_enableStreamingSource;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_id_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_id;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UStreamingSourceComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_MinimapTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStreamingSourceComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "StreamingSourceComponent.h" },
		{ "ModuleRelativePath", "StreamingSourceComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_enableStreamingSource_MetaData[] = {
		{ "Category", "StreamingSourceComponent" },
		{ "ModuleRelativePath", "StreamingSourceComponent.h" },
	};
#endif
	void Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_enableStreamingSource_SetBit(void* Obj)
	{
		((UStreamingSourceComponent*)Obj)->enableStreamingSource = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_enableStreamingSource = { "enableStreamingSource", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UStreamingSourceComponent), &Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_enableStreamingSource_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_enableStreamingSource_MetaData), Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_enableStreamingSource_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_id_MetaData[] = {
		{ "Category", "StreamingSourceComponent" },
		{ "ModuleRelativePath", "StreamingSourceComponent.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UStreamingSourceComponent, id), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_id_MetaData), Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_id_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UStreamingSourceComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_enableStreamingSource,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStreamingSourceComponent_Statics::NewProp_id,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UStreamingSourceComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStreamingSourceComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UStreamingSourceComponent_Statics::ClassParams = {
		&UStreamingSourceComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UStreamingSourceComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UStreamingSourceComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStreamingSourceComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UStreamingSourceComponent()
	{
		if (!Z_Registration_Info_UClass_UStreamingSourceComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStreamingSourceComponent.OuterSingleton, Z_Construct_UClass_UStreamingSourceComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UStreamingSourceComponent.OuterSingleton;
	}
	template<> MINIMAPTEST_API UClass* StaticClass<UStreamingSourceComponent>()
	{
		return UStreamingSourceComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UStreamingSourceComponent);
	UStreamingSourceComponent::~UStreamingSourceComponent() {}
	struct Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UStreamingSourceComponent, UStreamingSourceComponent::StaticClass, TEXT("UStreamingSourceComponent"), &Z_Registration_Info_UClass_UStreamingSourceComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStreamingSourceComponent), 558877289U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceComponent_h_170503912(TEXT("/Script/MinimapTest"),
		Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_StreamingSourceComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
