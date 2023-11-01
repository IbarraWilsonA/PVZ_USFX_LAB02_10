// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieCono.h"

AZombieCono::AZombieCono()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	MeshZombie->SetStaticMesh(ZombieMesh.Object);
}

void AZombieCono::BeginPlay()
{
	Super::BeginPlay();
	energia = 150;
	Velocidad = 150.00f;
	Fuerza = 15;
}


void AZombieCono::Attack()
{
	//atacar a la planta
}
