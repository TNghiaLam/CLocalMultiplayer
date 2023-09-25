// Nghia Lam - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMBaseCharacter.generated.h"

UCLASS()
class CLOCALMULTIPLAYER_API ALMBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ALMBaseCharacter();

	UFUNCTION(BlueprintCallable, Category = "Character Actions")
	void MoveCharacter(const FVector2D& MovementVector);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
