// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Zombie.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeneradorZombies.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API AGeneradorZombies : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneradorZombies();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Crea un zombie y lo devuelve. es una funciona virtual pura así que no necesita implementacion
	virtual AZombie* ArmarZombies(FString ZombiesSKU, FVector _spawnPosition)PURE_VIRTUAL(AGeneradorZombies::ArmarZombies, return nullptr;);

	//Ordena, arma y devuelve un zombie
	AZombie* OrdenarZombies(FString Tipo, FVector _spawnPosition);
};
