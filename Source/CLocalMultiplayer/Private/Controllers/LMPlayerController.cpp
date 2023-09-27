// Nghia Lam - MIT License.

#include "Controllers/LMPlayerController.h"

#include "Characters/LMBaseCharacter.h"
#include "Characters/LMCharacterInput.h"
#include "Utilities/LMLog.h"

ALMPlayerController::ALMPlayerController()
{
}

void ALMPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	PlayerCharacter = Cast<ALMBaseCharacter>(GetCharacter());
	if (PlayerCharacter)
	{
		PlayerCharacter->GetCharacterInputComponent()->InitializeInputComponent(InputComponent);
	}
	else
	{
		LMLOG_WARNING("[ALMPlayerController] This controller is not attached to a ALMBaseCharacter")
	}
}
