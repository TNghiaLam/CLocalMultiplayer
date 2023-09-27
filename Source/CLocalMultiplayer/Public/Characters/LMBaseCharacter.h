// Nghia Lam - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMBaseCharacter.generated.h"

class ULMCharacterInput;
class ULMCharacterMovement;

UCLASS()
class CLOCALMULTIPLAYER_API ALMBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ALMBaseCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "LMCharacter|Actions")
	void MoveCharacter(const FVector2D& MovementVector);
	
	UFUNCTION(BlueprintCallable, Category = "LMCharacter|Component")
	ULMCharacterMovement* GetCharacterMovementComponent() const { return LMMovementComponent; }

	UFUNCTION(BlueprintCallable, Category = "LMCharacter|Component")
	ULMCharacterInput* GetCharacterInputComponent() const { return LMInputComponent; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LMCharacter|Component")
	TObjectPtr<ULMCharacterMovement> LMMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LMCharacter|Component")
	TObjectPtr<ULMCharacterInput> LMInputComponent;
};
