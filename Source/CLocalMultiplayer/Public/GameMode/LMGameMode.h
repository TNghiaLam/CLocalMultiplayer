﻿// Nghia Lam - MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LMGameMode.generated.h"

class ALMBaseCharacter;

UCLASS()
class CLOCALMULTIPLAYER_API ALMGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Characters")
	TSubclassOf<ALMBaseCharacter> CharacterClass;
	
	UPROPERTY(EditAnywhere, Category="Camera")
	TSubclassOf<AActor> MainCameraClass;
	
	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<AActor> MainCameraRef;

private:
	void FindMainCameraRef();
	void SpawnPlayers();
};
