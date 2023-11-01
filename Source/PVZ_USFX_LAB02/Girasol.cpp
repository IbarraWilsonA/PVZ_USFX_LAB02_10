// Fill out your copyright notice in the Description page of Project Settings.


#include "Girasol.h"
#include "Sol.h"
AGirasol::AGirasol()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshGirasol(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));
	MeshPlanta->SetStaticMesh(MeshGirasol.Object);
	MeshPlanta->SetRelativeScale3D(FVector(3.0f, 1.0f, 3.0f));
	energia = 150;
}

void AGirasol::BeginPlay()
{
	Super::BeginPlay();

	UWorld* const World = GetWorld();
	int rand = FMath::RandRange(3, 6);
	World->GetTimerManager().SetTimer(SpawnSolesTimer, this, &AGirasol::SpawnSoles, rand, true);
}

void AGirasol::SpawnSoles()
{
		UWorld* const World = GetWorld();
		World->SpawnActor<ASol>(GetActorLocation() + FVector(0.0f, 0.0f, 100.0f), FRotator::ZeroRotator);
}

void AGirasol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
