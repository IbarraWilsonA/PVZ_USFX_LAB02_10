// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plant.h"
#include "Girasol.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API AGirasol : public APlant
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AGirasol();

	FTimerHandle SpawnSolesTimer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame

	void SpawnSoles();

	virtual void Tick(float DeltaTime) override;
};
