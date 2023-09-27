// Nghia Lam - MIT License.

#include "GameMode/LMGameMode.h"

#include "EngineUtils.h"
#include "Characters/LMBaseCharacter.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "Utilities/LMLog.h"

void ALMGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Spawn players based on player start locations.
	int PlayerIndex = 0;

	const UWorld* CurrentWorld = GetWorld();
	
	UClass* ActorClass = APlayerStart::StaticClass();
	for (TActorIterator<AActor> It(CurrentWorld, ActorClass); It; ++It)
	{
		// Get Player Controller
		APlayerController* PC = UGameplayStatics::GetPlayerController(CurrentWorld, PlayerIndex);
		if (PC == nullptr)
		{
			PC = UGameplayStatics::CreatePlayer(CurrentWorld, PlayerIndex, true);
		}
		
		const AActor* Start = *It;
		const FVector& Location = Start->GetActorLocation();
		const FRotator& Rotation = Start->GetActorRotation();
		
		APawn* SpawnedCharacter = GetWorld()->SpawnActor<ALMBaseCharacter>(CharacterClass, Location, Rotation);
		PC->Possess(SpawnedCharacter);

		++PlayerIndex;
	}
}
