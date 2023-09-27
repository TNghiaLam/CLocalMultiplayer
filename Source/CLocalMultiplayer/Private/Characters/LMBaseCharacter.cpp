// Nghia Lam - MIT License.

#include "Characters/LMBaseCharacter.h"

#include "Characters/LMCharacterInput.h"
#include "Characters/LMCharacterMovement.h"

ALMBaseCharacter::ALMBaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<ULMCharacterMovement>(CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = false;
	bUseControllerRotationYaw = false;
	
	// Setup components
	LMInputComponent = CreateDefaultSubobject<ULMCharacterInput>(TEXT("Character Input"));
	LMMovementComponent = CastChecked<ULMCharacterMovement>(GetCharacterMovement());
}

void ALMBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ALMBaseCharacter::MoveCharacter(const FVector2D& MovementVector)
{
	AddMovementInput(GetActorRightVector(), MovementVector.X);
	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
}
