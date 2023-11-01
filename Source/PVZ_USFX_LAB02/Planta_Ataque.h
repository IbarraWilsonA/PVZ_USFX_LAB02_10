// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plant.h"
#include "Planta_Ataque.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API APlanta_Ataque : public APlant
{
	GENERATED_BODY()
	

public:
	// Sets default values for this actor's properties
	APlanta_Ataque();

	void AtaquePlanta();

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:

	FTimerHandle ManejoTiempo;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Si tiene permitido disparar
	uint32 bCanFire : 1;

protected:

	void FireShot(FVector FireDirection);
	//void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;
	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	void ShotTimerExpired();

	float TiempoTranscurrido;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	int CantidadDisparos;
	int contador;

};
