// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GameFramework/PlayerController.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandle"));
	GrabRange = 200.f;
	GrabRadius = 10.f;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PhysicsHandle && PhysicsHandle->GrabbedComponent)
	{
		FVector TargetLocation;
		FHitResult Hit;
		GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECC_Visibility, false, Hit);
		TargetLocation = Hit.Location;
		PhysicsHandle->SetTargetLocation(TargetLocation);
	}

}

void AMyCharacter::Grab()
{
    if (PhysicsHandle->GrabbedComponent)
    {
        PhysicsHandle->ReleaseComponent();
    }
    else
    {
        FHitResult Hit;
        FVector StartLocation = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();
        FVector EndLocation = StartLocation + (GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetActorForwardVector() * GrabRange);

        FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);

        if (GetWorld()->SweepSingleByChannel(Hit, StartLocation, EndLocation, FQuat::Identity, ECC_PhysicsBody, Sphere))
        {
            if (UPrimitiveComponent *ComponentToGrab = Hit.GetComponent())
            {
                PhysicsHandle->GrabComponentAtLocation(ComponentToGrab, NAME_None, Hit.Location);
            }
        }
    }
}

