// Nghia Lam - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "LMPlayerController.generated.h"

class ALMBaseCharacter;

UCLASS()
class CLOCALMULTIPLAYER_API ALMPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ALMPlayerController();
	
	void RequestMove(const FInputActionValue& Value);
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LMPlayerController|Input")
	UInputMappingContext* DefaultInputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LMPlayerController|Input")
	UInputAction* MoveInputAction;
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Player")
	TObjectPtr<ALMBaseCharacter> PlayerCharacter;
};
