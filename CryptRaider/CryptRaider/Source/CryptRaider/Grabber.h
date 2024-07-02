// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"
#include ""

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Grab")
	void Grab();

	UFUNCTION(BlueprintCallable, Category = "Grab")
	void Release();

private:
	float Reach = 100.f;

	UPROPERTY(EditAnywhere)
	UInputAction *GrabAction;
		
	UPROPERTY(EditAnywhere)
	UPhysicsHandleComponenet *PhysicsHandle;

	void FindPhysicsHandle();
	void SetupInputComponent();
	FHitResult GetFirstPhysicsBodyInReach() const;

};
