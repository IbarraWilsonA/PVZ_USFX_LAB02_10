// Fill out your copyright notice in the Description page of Project Settings.


#include "Planta_Ataque.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

#include "Proyectil.h"

#include "TimerManager.h"
#include <cmath>

APlanta_Ataque::APlanta_Ataque()
{
	PrimaryActorTick.bCanEverTick = true;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantAtaqueMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantAtaqueMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));


	MeshPlanta->SetStaticMesh(PlantAtaqueMesh.Object);

	MeshPlanta->SetRelativeScale3D(FVector(0.5f, 0.5f, 1.5f));



	bCanFire = true;

	GunOffset = FVector(40.f, 40.f, 10.f);

	FireRate = 0.5f;

	energia = 200;

	CantidadDisparos = 1;
	contador = 1;
}

void APlanta_Ataque::AtaquePlanta()
{
	FireShot(FVector(0.0f, 1.0f, 0.0f));

}

void APlanta_Ataque::BeginPlay()
{

	UWorld* const World = GetWorld();

	GetWorldTimerManager().SetTimer(ManejoTiempo, this, &APlanta_Ataque::AtaquePlanta, FireRate, true, 0.1f);

}

void APlanta_Ataque::Tick(float DeltaTime)
{

}

void APlanta_Ataque::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AProyectil>(SpawnLocation, FireRotation); //*******************

			}

			//bCanFire = false;
			//World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &APlanta_Ataque::ShotTimerExpired, FireRate);

		}
	}
}

void APlanta_Ataque::ShotTimerExpired()
{
	bCanFire = true;

}
