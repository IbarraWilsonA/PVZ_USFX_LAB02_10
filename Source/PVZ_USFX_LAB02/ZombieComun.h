// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Zombie.h"
#include "ZombieComun.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API AZombieComun : public AZombie
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:

	virtual void Attack() override;

};
