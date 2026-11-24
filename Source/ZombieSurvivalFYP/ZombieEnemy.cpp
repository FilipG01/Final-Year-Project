// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieEnemy.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"

void AZombieEnemy::FindPlayer()
{
	TargetPlayer = UGameplayStatics::GetPlayerPawn(
		GetWorld(), 0
	);
}

void AZombieEnemy::ChasePlayer()
{
	if (!IsValid(TargetPlayer))
	{
		FindPlayer();

		if (!IsValid(TargetPlayer))
		{
			return;
		}
	}

	AAIController* AIController =
		Cast<AAIController>(GetController());

	if (AIController == nullptr)
	{
		return;
	}

	AIController->MoveToActor(
		TargetPlayer,
		AcceptanceRadius
	);
}

// Sets default values
AZombieEnemy::AZombieEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AZombieEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;

	FindPlayer();

	ChasePlayer();

	GetWorldTimerManager().SetTimer(
		BehaviourTimerHandle,
		this,
		&AZombieEnemy::ChasePlayer,
		BehaviourUpdateInterval,
		true
	);
}

// Called every frame
void AZombieEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZombieEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

