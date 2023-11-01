// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Zombie.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API AZombie : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZombie();

	UPROPERTY(EditAnywhere) // para ver y editar desde el unreal
	float Velocidad;

	UPROPERTY(VisibleAnywhere) // para ver desde el unreal
	int energia;

	UPROPERTY(VisibleAnywhere) // para ver desde el unreal
	int Fuerza;

	FVector LocalizacionObjetivo;
	FVector Direccion;
	float DistanciaAlObjetivo;

	bool bCanMove = false;
	float SpawnAfter = 0.0f;

	float TiempoTranscurrido;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshZombie;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Attack();

	void morir();

	void VelocidadRandom(float V1, float V2);

	FORCEINLINE void SetSpawnAfter(float _SpawnAfter) { SpawnAfter = _SpawnAfter; }
	FORCEINLINE float GetSpawnAfter() { return SpawnAfter; }
	FORCEINLINE void SetCanMove(bool _bCanMove) { bCanMove = _bCanMove; }
};
