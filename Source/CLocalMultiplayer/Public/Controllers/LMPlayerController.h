// Nghia Lam - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LMPlayerController.generated.h"

class ALMBaseCharacter;

UCLASS()
class CLOCALMULTIPLAYER_API ALMPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ALMPlayerController();

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	TObjectPtr<ALMBaseCharacter> PlayerCharacter;
};
