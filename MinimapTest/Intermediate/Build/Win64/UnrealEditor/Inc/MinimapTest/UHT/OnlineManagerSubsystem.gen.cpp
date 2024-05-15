// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MinimapTest/OnlineManagerSubsystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOnlineManagerSubsystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	MINIMAPTEST_API UClass* Z_Construct_UClass_UOnlineManagerSubsystem();
	MINIMAPTEST_API UClass* Z_Construct_UClass_UOnlineManagerSubsystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MinimapTest();
// End Cross Module References
	DEFINE_FUNCTION(UOnlineManagerSubsystem::execFindServer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FindServer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlineManagerSubsystem::execCreateServer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateServer();
		P_NATIVE_END;
	}
	void UOnlineManagerSubsystem::StaticRegisterNativesUOnlineManagerSubsystem()
	{
		UClass* Class = UOnlineManagerSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateServer", &UOnlineManagerSubsystem::execCreateServer },
			{ "FindServer", &UOnlineManagerSubsystem::execFindServer },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlineManagerSubsystem_CreateServer_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlineManagerSubsystem_CreateServer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "OnlineManagerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlineManagerSubsystem_CreateServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlineManagerSubsystem, nullptr, "CreateServer", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlineManagerSubsystem_CreateServer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlineManagerSubsystem_CreateServer_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UOnlineManagerSubsystem_CreateServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlineManagerSubsystem_CreateServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlineManagerSubsystem_FindServer_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlineManagerSubsystem_FindServer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "OnlineManagerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlineManagerSubsystem_FindServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlineManagerSubsystem, nullptr, "FindServer", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlineManagerSubsystem_FindServer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlineManagerSubsystem_FindServer_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UOnlineManagerSubsystem_FindServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlineManagerSubsystem_FindServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlineManagerSubsystem);
	UClass* Z_Construct_UClass_UOnlineManagerSubsystem_NoRegister()
	{
		return UOnlineManagerSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UOnlineManagerSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sessionName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_sessionName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_serverName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_serverName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ipAddress_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ipAddress;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlineManagerSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_MinimapTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineManagerSubsystem_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlineManagerSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlineManagerSubsystem_CreateServer, "CreateServer" }, // 1897402280
		{ &Z_Construct_UFunction_UOnlineManagerSubsystem_FindServer, "FindServer" }, // 2219003305
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineManagerSubsystem_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlineManagerSubsystem_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "OnlineManagerSubsystem.h" },
		{ "ModuleRelativePath", "OnlineManagerSubsystem.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_sessionName_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "OnlineManagerSubsystem" },
		{ "ModuleRelativePath", "OnlineManagerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_sessionName = { "sessionName", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOnlineManagerSubsystem, sessionName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_sessionName_MetaData), Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_sessionName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_serverName_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "OnlineManagerSubsystem" },
		{ "ModuleRelativePath", "OnlineManagerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_serverName = { "serverName", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOnlineManagerSubsystem, serverName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_serverName_MetaData), Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_serverName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_ipAddress_MetaData[] = {
		{ "AllowPrivateAccess", "" },
		{ "Category", "OnlineManagerSubsystem" },
		{ "ModuleRelativePath", "OnlineManagerSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_ipAddress = { "ipAddress", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOnlineManagerSubsystem, ipAddress), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_ipAddress_MetaData), Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_ipAddress_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOnlineManagerSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_sessionName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_serverName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlineManagerSubsystem_Statics::NewProp_ipAddress,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlineManagerSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlineManagerSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlineManagerSubsystem_Statics::ClassParams = {
		&UOnlineManagerSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UOnlineManagerSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineManagerSubsystem_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineManagerSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlineManagerSubsystem_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineManagerSubsystem_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UOnlineManagerSubsystem()
	{
		if (!Z_Registration_Info_UClass_UOnlineManagerSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlineManagerSubsystem.OuterSingleton, Z_Construct_UClass_UOnlineManagerSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlineManagerSubsystem.OuterSingleton;
	}
	template<> MINIMAPTEST_API UClass* StaticClass<UOnlineManagerSubsystem>()
	{
		return UOnlineManagerSubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlineManagerSubsystem);
	UOnlineManagerSubsystem::~UOnlineManagerSubsystem() {}
	struct Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_OnlineManagerSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_OnlineManagerSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlineManagerSubsystem, UOnlineManagerSubsystem::StaticClass, TEXT("UOnlineManagerSubsystem"), &Z_Registration_Info_UClass_UOnlineManagerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlineManagerSubsystem), 156825426U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_OnlineManagerSubsystem_h_3173238339(TEXT("/Script/MinimapTest"),
		Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_OnlineManagerSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_unreal2_MinimapTest_Source_MinimapTest_OnlineManagerSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
