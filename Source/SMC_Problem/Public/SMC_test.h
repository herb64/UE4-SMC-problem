// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "SMC_test.generated.h"

/**
 * A test static mesh component made blueprint spawnable to demonstrate
 * the loss of static mesh on recompilation 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SMC_PROBLEM_API USMC_test : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// As a workaround implement constructor and set mesh manually
	USMC_test();

	// A testing value for uproperty setting - mesh disappears also, it
	// not changing property to private at all, as discussed in
	// https://issues.unrealengine.com/issue/UE-63298
	// Change the default value to see, if it propagates into the editor
	UPROPERTY(EditAnywhere)
	float myVariable = 5000.0f;
};