// Nghia Lam - MIT License

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "UObject/SoftObjectPtr.h"
#include "Components/ActorComponent.h"
#include "LMCharacterInput.generated.h"

struct FInputActionValue;

class ALMBaseCharacter;
class UInputAction;
class UPlayerMappableInputConfig;

USTRUCT()
struct FMappableConfig
{
	GENERATED_BODY()
	
	FMappableConfig() = default;
	
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UPlayerMappableInputConfig> Config;

	/**
	 * The type of config that this is. Useful for filtering out configs by the current input device
	 * for things like the settings screen, or if you only want to apply this config when a certain
	 * input type is being used.
	 */
	UPROPERTY(EditAnywhere)
	ECommonInputType Type = ECommonInputType::Count;

	/**
	 * If true, then this input config will be activated when it's associated Game Feature is activated.
	 * This is normally the desirable behavior
	 */
	UPROPERTY(EditAnywhere)
	bool bShouldActivateAutomatically = true;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CLOCALMULTIPLAYER_API ULMCharacterInput : public UActorComponent
{
	GENERATED_BODY()

public:
	ULMCharacterInput();

	void InitializeInputComponent(UInputComponent* PlayerInputComponent);
	void RequestMove(const FInputActionValue& Value);
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "ULMCharacterInput")
	TArray<FMappableConfig> DefaultInputConfigs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ULMCharacterInput|Actions")
	UInputAction* MoveInputAction;
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Player")
	TObjectPtr<ALMBaseCharacter> PlayerCharacter;
};
