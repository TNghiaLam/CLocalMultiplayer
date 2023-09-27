// Nghia Lam - MIT License

#include "Characters/LMCharacterInput.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PlayerMappableInputConfig.h"
#include "Characters/LMBaseCharacter.h"

ULMCharacterInput::ULMCharacterInput()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void ULMCharacterInput::BeginPlay()
{
	Super::BeginPlay();
}

void ULMCharacterInput::InitializeInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	if (!PlayerCharacter)
	{
		PlayerCharacter = CastChecked<ALMBaseCharacter>(GetOwner());
	}

	const APlayerController* PC = PlayerCharacter->GetController<APlayerController>();
	check(PC);

	const ULocalPlayer* LP = PC->GetLocalPlayer();
	check(LP);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	
	// Register any default input configs
	for (const FMappableConfig& InputConfig : DefaultInputConfigs)
	{
		if (InputConfig.bShouldActivateAutomatically)
		{
			FModifyContextOptions Options = {};
			Options.bIgnoreAllPressedKeysUntilRelease = false;
			
			Subsystem->AddPlayerMappableConfig(InputConfig.Config.LoadSynchronous(), Options);
		}
	}

	// Bind Actions
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &ULMCharacterInput::RequestMove);
}

void ULMCharacterInput::RequestMove(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	if (PlayerCharacter)
	{
		PlayerCharacter->MoveCharacter(MovementVector);
	}
}
