// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CryptRaider/MyCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyCharacter() {}

// Begin Cross Module References
CRYPTRAIDER_API UClass* Z_Construct_UClass_AMyCharacter();
CRYPTRAIDER_API UClass* Z_Construct_UClass_AMyCharacter_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UPhysicsHandleComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_CryptRaider();
// End Cross Module References

// Begin Class AMyCharacter Function Grab
struct Z_Construct_UFunction_AMyCharacter_Grab_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called to bind functionality to input\n" },
#endif
		{ "ModuleRelativePath", "MyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called to bind functionality to input" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_Grab_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "Grab", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_Grab_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyCharacter_Grab_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyCharacter_Grab()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyCharacter_Grab_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyCharacter::execGrab)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Grab();
	P_NATIVE_END;
}
// End Class AMyCharacter Function Grab

// Begin Class AMyCharacter
void AMyCharacter::StaticRegisterNativesAMyCharacter()
{
	UClass* Class = AMyCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Grab", &AMyCharacter::execGrab },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyCharacter);
UClass* Z_Construct_UClass_AMyCharacter_NoRegister()
{
	return AMyCharacter::StaticClass();
}
struct Z_Construct_UClass_AMyCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyCharacter.h" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrabRange_MetaData[] = {
		{ "Category", "Grab" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrabRadius_MetaData[] = {
		{ "Category", "Grab" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PhysicsHandle_MetaData[] = {
		{ "Category", "Grab" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GrabRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GrabRadius;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicsHandle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyCharacter_Grab, "Grab" }, // 3529092770
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_GrabRange = { "GrabRange", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyCharacter, GrabRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrabRange_MetaData), NewProp_GrabRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_GrabRadius = { "GrabRadius", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyCharacter, GrabRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrabRadius_MetaData), NewProp_GrabRadius_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_PhysicsHandle = { "PhysicsHandle", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyCharacter, PhysicsHandle), Z_Construct_UClass_UPhysicsHandleComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PhysicsHandle_MetaData), NewProp_PhysicsHandle_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_GrabRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_GrabRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_PhysicsHandle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMyCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_CryptRaider,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyCharacter_Statics::ClassParams = {
	&AMyCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMyCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyCharacter()
{
	if (!Z_Registration_Info_UClass_AMyCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyCharacter.OuterSingleton, Z_Construct_UClass_AMyCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyCharacter.OuterSingleton;
}
template<> CRYPTRAIDER_API UClass* StaticClass<AMyCharacter>()
{
	return AMyCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyCharacter);
AMyCharacter::~AMyCharacter() {}
// End Class AMyCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_jih10_MyPlace_Unreal_Udemy_CryptRaider_CryptRaider_Source_CryptRaider_MyCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyCharacter, AMyCharacter::StaticClass, TEXT("AMyCharacter"), &Z_Registration_Info_UClass_AMyCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyCharacter), 2034658644U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_jih10_MyPlace_Unreal_Udemy_CryptRaider_CryptRaider_Source_CryptRaider_MyCharacter_h_3437207779(TEXT("/Script/CryptRaider"),
	Z_CompiledInDeferFile_FID_Users_jih10_MyPlace_Unreal_Udemy_CryptRaider_CryptRaider_Source_CryptRaider_MyCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_jih10_MyPlace_Unreal_Udemy_CryptRaider_CryptRaider_Source_CryptRaider_MyCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
