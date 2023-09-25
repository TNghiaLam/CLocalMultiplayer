// Nghia Lam - MIT License.

#include "Characters/LMBaseCharacter.h"

ALMBaseCharacter::ALMBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALMBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ALMBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALMBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ALMBaseCharacter::MoveCharacter(const FVector2D& MovementVector)
{
	AddMovementInput(GetActorRightVector(), MovementVector.X);
	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
}
