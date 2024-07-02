// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "MyCharacter.generated.h"

UCLASS()
class CRYPTRAIDER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void Grab();

private:
	UPROPERTY(EditAnywhere, Category = "Grab")
	float GrabRange;

	UPROPERTY(EditAnywhere, Category = "Grab")
	float GrabRadius;

	UPROPERTY(EditAnywhere, Category = "Grab")
	UPhysicsHandleComponent *PhysicsHandle;
};
