// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawns.h"
#include "Zombie.h"
#include "Plant.h"
// Sets default values
ASpawns::ASpawns()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawns::BeginPlay()
{
	Super::BeginPlay();
	
	/*AZombie* Zombie1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), FVector(400.0, 200.0, 100.0), FRotator::ZeroRotator);
	APlant* Planta1 = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), FVector(-100.0, 200.0, 100.0), FRotator::ZeroRotator);*/

}

// Called every frame
void ASpawns::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

