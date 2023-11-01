// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"

#include "Plant.h"
#include "Zombie.h"

// Sets default values
AProyectil::AProyectil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	// Create mesh component for the projectile sphere
	MeshBala = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Proyectilmesh0"));
	MeshBala->SetStaticMesh(ProjectileMeshAsset.Object);
	MeshBala->SetupAttachment(RootComponent);
	MeshBala->BodyInstance.SetCollisionProfileName("Proyectil");
	MeshBala->OnComponentHit.AddDynamic(this, &AProyectil::OnHit);		// set up a notification for when this component hits something
	RootComponent = MeshBala;

	MeshBala->SetRelativeScale3D(FVector(0.3f, 0.3f, 0.3f));

	// Use a ProjectileMovementComponent to govern this projectile's movement
	MovimientoProyectil = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	MovimientoProyectil->UpdatedComponent = MeshBala;
	MovimientoProyectil->InitialSpeed = 3000.0f;
	MovimientoProyectil->MaxSpeed = 3000.0f;
	MovimientoProyectil->bRotationFollowsVelocity = true;
	MovimientoProyectil->bShouldBounce = false;
	MovimientoProyectil->ProjectileGravityScale = 0.f; // No gravity


	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AProyectil::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProyectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProyectil::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	Zombie = Cast<AZombie>(OtherActor);

	if (OtherActor == Zombie) {
		Zombie->energia -= 10;
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje %i"), Zombie->energia));
		if (Zombie->energia <= 0) {
			Zombie->Destroy();
		};
	}

	//APlant* Plant = Cast<APlant>(OtherActor);
	//if (OtherActor->ActorHasTag("Plant")) {
	//	Plant->energia -= 10;
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje %i"), Plant->energia));
	//	if (Plant->energia <= 0) {
	//		Plant->Destroy();
	//	};
	//}


	Destroy();
}

