// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrollingCharacter.h"


// Sets default values
APatrollingCharacter::APatrollingCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APatrollingCharacter::BeginPlay()
{
	Super::BeginPlay();
	}

// Called every frame
void APatrollingCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APatrollingCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

