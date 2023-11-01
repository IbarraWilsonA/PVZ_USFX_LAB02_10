// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorZombies.h"

// Sets default values
AGeneradorZombies::AGeneradorZombies()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
// Called when the game starts or when spawned
void AGeneradorZombies::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGeneradorZombies::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AZombie* AGeneradorZombies::OrdenarZombies(FString Tipo, FVector _spawnPosition)
{
	//Crea el zombie y muestra su nombre en pantalla
	AZombie* Zombie = ArmarZombies(Tipo, _spawnPosition);

	Zombie->Attack();


	//Returns the created potion
	return Zombie;
}
