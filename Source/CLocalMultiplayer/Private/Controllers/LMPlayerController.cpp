// Nghia Lam - MIT License.

#include "Controllers/LMPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/LMBaseCharacter.h"

ALMPlayerController::ALMPlayerController()
{
}

void ALMPlayerController::RequestMove(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	if (PlayerCharacter)
	{
		PlayerCharacter->MoveCharacter(MovementVector);
	}
}

void ALMPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// bShowMouseCursor = false;
	PlayerCharacter = CastChecked<ALMBaseCharacter>(GetCharacter());
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(DefaultInputMapping, 0);
	}
}

void ALMPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	check(InputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &ALMPlayerController::RequestMove);
	}
}
