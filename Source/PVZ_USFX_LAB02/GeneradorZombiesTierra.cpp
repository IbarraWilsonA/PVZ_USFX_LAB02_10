// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorZombiesTierra.h"
#include "ZombieComun.h"
#include "ZombieCono.h"
AZombie* AGeneradorZombiesTierra::ArmarZombies(FString ZombiesSKU, FVector _spawnPosition)
{
	//Selecciona el tipo de zombie a crear basado en su ZombiesSKU (string)
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	if (ZombiesSKU.Equals("ZombieComun")) {
		return GetWorld()->SpawnActor<AZombieComun>(AZombieComun::StaticClass(), SpawnLocation);
	}
	else if (ZombiesSKU.Equals("ZombieCono")) {
		return GetWorld()->SpawnActor<AZombieCono>(AZombieCono::StaticClass(), SpawnLocation);
	}
	else if (ZombiesSKU.Equals("TierraGigante")) {

		//Añadir otro zombie si se desea
		return 	nullptr;
	}
	else return nullptr; //Returna null si el valor no es valido
}
