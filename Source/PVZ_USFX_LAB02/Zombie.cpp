// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie.h"
#include "PVZ_USFX_LAB02GameModeBase.h"
#include <Kismet/GameplayStatics.h>
#include "Plant.h"

// Sets default values
AZombie::AZombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshZombie = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Zombie Mesh"));
	RootComponent = MeshZombie;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMesh01(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	MeshZombie->SetStaticMesh(ZombieMesh01.Object);


	energia = 1000;
	Velocidad = 100.00f;
	Fuerza = 10;
	//InitialLifeSpan = 5; //Para que el actor se destruya

	LocalizacionObjetivo = FVector(-550.0f, -850.0f, 20.0f); // Cambia la ubicación objetivo según tus necesidades

}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TiempoTranscurrido += DeltaTime;

	TArray<AActor*> Plantas; // array donde se guardan todos los actores de la clase APlant

	// aqui se llena el array con todos los actores de la clase APlant
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlant::StaticClass(), Plantas);
	bool TienePlantaAlFrente = false;

	// recorrer el array Plantas y comparar la posicion x de cada planta con la posicion x del zombie
	for (int32 i = 0; i < Plantas.Num(); i++)
	{
		// comparar la posicion x de la Planta con la del zombie
		if (Plantas[i]->GetActorLocation().X == this->GetActorLocation().X) {
			// si la posicion x de la planta es igual a la del zombie, entonces la planta es el objetivo
			LocalizacionObjetivo = Plantas[i]->GetActorLocation();
			// calcula la direccion y distancia al objetivo
			Direccion = (LocalizacionObjetivo - this->GetActorLocation()).GetSafeNormal();
			// calcula la distancia al objetivo
			DistanciaAlObjetivo = FVector::Dist(LocalizacionObjetivo, this->GetActorLocation());
			TienePlantaAlFrente = true;
		}
		
	}
	if (!TienePlantaAlFrente) {
		// si la posicion x de la planta no es igual a la del zombie, entonces el objetivo es la casa del jugador
		LocalizacionObjetivo = FVector(this->GetActorLocation().X, -850.0f, this->GetActorLocation().Z);
		// calcula la direccion y distancia al objetivo
		Direccion = (LocalizacionObjetivo - this->GetActorLocation()).GetSafeNormal();
		// calcula la distancia al objetivo
		DistanciaAlObjetivo = FVector::Dist(LocalizacionObjetivo, this->GetActorLocation());
	}

	// Mueve el Zombie si puede moverse y no está oculto
	if (bCanMove && !this->IsHidden()) {
	// Calcula el desplazamiento en este frame
	float DeltaMove = Velocidad * GetWorld()->DeltaTimeSeconds;

		if (DeltaMove > DistanciaAlObjetivo)
		{
			// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
			this->SetActorLocation(LocalizacionObjetivo);
		}
		else
		{
			// Mueve el objeto en la dirección calculada
			this->AddActorWorldOffset(Direccion * DeltaMove);

			// cambiar velocidad cada 1 segundo
			if (TiempoTranscurrido >= 1.0f) {
				VelocidadRandom(50, 200);
				TiempoTranscurrido = 0.0f;
			}
		}
	}
}

void AZombie::Attack()
{
	//ataque de zombie
}

void AZombie::morir()
{
	//Destroy();			//El actor se destruye
	//this->Destroy();		//El actor también se destruye
	//SetActorHiddenInGame(true);	//El actor sólo se oculta
}

void AZombie::VelocidadRandom(float V1, float V2)
{
		Velocidad = +FMath::FRandRange(V1, V2);
}