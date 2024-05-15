// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MinimapTest/RecordCamera.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRecordCamera() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
	MINIMAPTEST_API UClass* Z_Construct_UClass_ARecordCamera();
	MINIMAPTEST_API UClass* Z_Construct_UClass_ARecordCamera_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MinimapTest();
// End Cross Module References
	void ARecordCamera::StaticRegisterNativesARecordCamera()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARecordCamera);
	UClass* Z_Construct_UClass_ARecordCamera_NoRegister()
	{
		return ARecordCamera::StaticClass();
	}
	struct Z_Construct_UClass_ARecordCamera_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_captureComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_captureComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isLerp_MetaData[];
#endif
		static void NewProp_isLerp_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isLerp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_canMove_MetaData[];
#endif
		static void NewProp_canMove_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_canMove;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_speed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_destination_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_destination;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARecordCamera_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MinimapTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCamera_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCamera_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "RecordCamera.h" },
		{ "ModuleRelativePath", "RecordCamera.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCamera_Statics::NewProp_captureComponent_MetaData[] = {
		{ "Category", "RecordCamera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "RecordCamera.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ARecordCamera_Statics::NewProp_captureComponent = { "captureComponent", nullptr, (EPropertyFlags)0x0044000000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARecordCamera, captureComponent), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCamera_Statics::NewProp_captureComponent_MetaData), Z_Construct_UClass_ARecordCamera_Statics::NewProp_captureComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCamera_Statics::NewProp_name_MetaData[] = {
		{ "Category", "RecordCamera" },
		{ "ModuleRelativePath", "RecordCamera.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ARecordCamera_Statics::NewProp_name = { "name", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARecordCamera, name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCamera_Statics::NewProp_name_MetaData), Z_Construct_UClass_ARecordCamera_Statics::NewProp_name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCamera_Statics::NewProp_isLerp_MetaData[] = {
		{ "Category", "RecordCamera" },
		{ "ModuleRelativePath", "RecordCamera.h" },
	};
#endif
	void Z_Construct_UClass_ARecordCamera_Statics::NewProp_isLerp_SetBit(void* Obj)
	{
		((ARecordCamera*)Obj)->isLerp = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ARecordCamera_Statics::NewProp_isLerp = { "isLerp", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ARecordCamera), &Z_Construct_UClass_ARecordCamera_Statics::NewProp_isLerp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCamera_Statics::NewProp_isLerp_MetaData), Z_Construct_UClass_ARecordCamera_Statics::NewProp_isLerp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCamera_Statics::NewProp_canMove_MetaData[] = {
		{ "Category", "RecordCamera" },
		{ "ModuleRelativePath", "RecordCamera.h" },
	};
#endif
	void Z_Construct_UClass_ARecordCamera_Statics::NewProp_canMove_SetBit(void* Obj)
	{
		((ARecordCamera*)Obj)->canMove = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ARecordCamera_Statics::NewProp_canMove = { "canMove", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ARecordCamera), &Z_Construct_UClass_ARecordCamera_Statics::NewProp_canMove_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCamera_Statics::NewProp_canMove_MetaData), Z_Construct_UClass_ARecordCamera_Statics::NewProp_canMove_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCamera_Statics::NewProp_speed_MetaData[] = {
		{ "Category", "RecordCamera" },
		{ "ModuleRelativePath", "RecordCamera.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARecordCamera_Statics::NewProp_speed = { "speed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARecordCamera, speed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCamera_Statics::NewProp_speed_MetaData), Z_Construct_UClass_ARecordCamera_Statics::NewProp_speed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCamera_Statics::NewProp_destination_MetaData[] = {
		{ "Category", "RecordCamera" },
		{ "ModuleRelativePath", "RecordCamera.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ARecordCamera_Statics::NewProp_destination = { "destination", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARecordCamera, destination), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCamera_Statics::NewProp_destination_MetaData), Z_Construct_UClass_ARecordCamera_Statics::NewProp_destination_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARecordCamera_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCamera_Statics::NewProp_captureComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCamera_Statics::NewProp_name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCamera_Statics::NewProp_isLerp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCamera_Statics::NewProp_canMove,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCamera_Statics::NewProp_speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCamera_Statics::NewProp_destination,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARecordCamera_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARecordCamera>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ARecordCamera_Statics::ClassParams = {
		&ARecordCamera::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ARecordCamera_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCamera_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCamera_Statics::Class_MetaDataParams), Z_Construct_UClass_ARecordCamera_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCamera_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ARecordCamera()
	{
		if (!Z_Registration_Info_UClass_ARecordCamera.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARecordCamera.OuterSingleton, Z_Construct_UClass_ARecordCamera_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ARecordCamera.OuterSingleton;
	}
	template<> MINIMAPTEST_API UClass* StaticClass<ARecordCamera>()
	{
		return ARecordCamera::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARecordCamera);
	ARecordCamera::~ARecordCamera() {}
	struct Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_RecordCamera_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_RecordCamera_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ARecordCamera, ARecordCamera::StaticClass, TEXT("ARecordCamera"), &Z_Registration_Info_UClass_ARecordCamera, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARecordCamera), 682078476U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_RecordCamera_h_586366197(TEXT("/Script/MinimapTest"),
		Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_RecordCamera_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_RecordCamera_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
