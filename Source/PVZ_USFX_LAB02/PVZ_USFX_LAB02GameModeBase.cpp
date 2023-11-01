// Copyright Epic Games, Inc. All Rights Reserved.


#include "PVZ_USFX_LAB02GameModeBase.h"
#include "Spawns.h"
#include "Jugador.h"
#include "Zombie.h"
#include "Plant.h"
#include "Sol.h"
#include "Planta_Ataque.h"
#include "GeneradorZombies.h"
#include "GeneradorZombiesTierra.h"
#include "TimerManager.h"

APVZ_USFX_LAB02GameModeBase::APVZ_USFX_LAB02GameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	DefaultPawnClass = AJugador::StaticClass();//Definiendo el Pawn

	SpawnLocationZombie = FVector(-550.0f, 850.0f, 20.0f);

	TiempoTranscurrido = 0.0f;


}

void APVZ_USFX_LAB02GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UWorld* const World = GetWorld();

	ASpawns* Spawn1 = GetWorld()->SpawnActor<ASpawns>(ASpawns::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);


	//Aparición de los soles
	//ASol* Sol1 = GetWorld()->SpawnActor<ASol>(ASol::StaticClass(), FVector(-20.0f, -220.0f, 20.0f), FRotator::ZeroRotator);


	// Genera 5 zombies
	//for (int i = 0; i < 5; i++) {
	//	// Define una posición temporal para el zombie en X
	//	SpawnLocationZombie.X += 200;
	//	// Aparicion de los zombies


	//	NuevoZombie = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

	//	NuevoZombie->Velocidad = FMath::FRandRange(50, 100);
	//	//NuevoZombie->Velocidad = 0.02f;

	//	ArrayZombies.Add(NuevoZombie);

	//}

	// generar zombies cono
	AGeneradorZombies* GeneradorZombies = GetWorld()->SpawnActor<AGeneradorZombiesTierra>(AGeneradorZombiesTierra::StaticClass());

	FTransform SpawnLocation;
	SpawnLocation.SetLocation(FVector(-1500.0f, 1200.0f, 200.0f));
	float initialPositionX = -550.0f;
	float initialPositionY = 850.0f;
	int ColumnaZombies = 1;
	for (int32 i = 0; i < NumberZombiesCono; ++i)
	{
		AZombie* NewZombieCono = GeneradorZombies->OrdenarZombies("ZombieCono", FVector(initialPositionX + ColumnaZombies * 200.0f, initialPositionY , 20.0f));

		if (NewZombieCono)
		{
			NewZombieCono->SetSpawnAfter(FMath::RandRange(1, 10));
			NewZombieCono->SetActorHiddenInGame(true);
			NewZombieCono->SetActorEnableCollision(true);     // Habilita las colisiones si es necesario
			NewZombieCono->SetCanMove(false);
			ArrayZombies.Add(NewZombieCono);
		}
		if (ColumnaZombies == 5)
		{
			ColumnaZombies = 0;
		}

			ColumnaZombies++;
	}


				//Aumentando la velocidad con el metodo aumentovelocidad cada 1 segundo
//	World->GetTimerManager().SetTimer(Temporizador, this, &APVZ_USFX_LAB02GameModeBase::aumentovelocidad, 1, true);



	//Definiendo la posición de las plantas
	SpawnLocationPlant = FVector(-550.0f, -850.0f, 20.0f);
	SpawnLocationPlantTemp = SpawnLocationPlant;

	// Genera 5 plantas
	for (int i = 0; i < 5; i++)
	{
		//Define una posicion temporal para la planta en X
		SpawnLocationPlantTemp.X += 200;
		for (int j = 0; j < 2; j++)
		{

			// Define una posición temporal para la planta en Y
			SpawnLocationPlantTemp.Y += 180;

			// Genera un nombre para la planta
			FString NombrePlanta = FString::Printf(TEXT("Planta%d"), i * 2 + j + 1);
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Purple, FString::Printf(TEXT("Energía de %d"), i * 2 + j + 1));

			// Crea una nueva instancia de APlant en el mundo
			//APlanta_Ataque* NuevaPlanta = GetWorld()->SpawnActor<APlanta_Ataque>(APlanta_Ataque::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);
			APlant* NuevaPlanta = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);

					 //Asigna un valor aleatorio a la energía de la planta
			NuevaPlanta->energia = FMath::FRandRange(0.0, 10.0);

					// Muestra un mensaje en la consola
			//UE_LOG(LogTemp, Warning, TEXT("Energía de %s: %i"), *NombrePlanta, NuevaPlanta->energia);

					// Muestra un mensaje en la pantalla
//			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Purple, FString::Printf(TEXT("Energía de %s: %i"), *NombrePlanta, NuevaPlanta->energia));

					// Agrega la planta al contenedor de plantas
			MapPlantas.Add(NombrePlanta, NuevaPlanta);

			// Coloca al actor (planta) en una posición diferente
			//NuevaPlanta->SetActorLocation(FVector(i * 100, 0, 0));

		}
		// Define una posición temporal para la planta en Y

		SpawnLocationPlantTemp.Y = SpawnLocationPlant.Y;
	}
	
// **** BORRAR UNA PLANTA DEL MUNDO PARA VER SI EL ZOMBIE SE MUEVE HACIA LA SIGUIENTE PLANTA ****

	FString ClaveABuscar = FString::Printf(TEXT("Planta10")); // La primera clave que deseas buscar
	FString ClaveABuscar2 = FString::Printf(TEXT("Planta9")); // La segunda clave que deseas buscar

	TArray<APlant*> PlantasAEliminar;

	for (TMap<FString, APlant*>::TIterator It(MapPlantas); It; ++It)
	{
		if (It.Key() == ClaveABuscar || It.Key() == ClaveABuscar2)
		{
			PlantasAEliminar.Add(It.Value());
		}
	}

	for (APlant* Planta : PlantasAEliminar)
	{
		Planta->Destroy();
	}
}

void APVZ_USFX_LAB02GameModeBase::Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);

	for (AZombie* ActualZombie : ArrayZombies)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SpawnAfter: %f"), ActualZombie->GetSpawnAfter()));

		if (ActualZombie && ActualZombie->SpawnAfter <= 0)
		{
			ActualZombie->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));      // Establece la escala de spawn deseada
			ActualZombie->SetActorHiddenInGame(false);      // Haz que el actor sea visible
			ActualZombie->SetActorEnableCollision(true);     // Habilita las colisiones si es necesario
			ActualZombie->SetCanMove(true);     // Habilita las colisiones si es necesario
			NumberZombiesSpawned += 1;

			ArrayZombies.Remove(ActualZombie);
		}
		else
		{
			ActualZombie->SetSpawnAfter(ActualZombie->GetSpawnAfter() - DeltaTime);
		}
	}

}
/*void APVZ_USFX_LAB02GameModeBase::aumentovelocidad()
{
	for (int i = 0; i < ArrayZombies.Num(); i++)
	{
		ArrayZombies[i]->Velocidad = +FMath::FRandRange(50, 100);

	}*/
