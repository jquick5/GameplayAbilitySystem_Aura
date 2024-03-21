// Copyright JQX Software

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraProjectileSpell.h"
#include "AuraFireBolt.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraFireBolt : public UAuraProjectileSpell
{
	GENERATED_BODY()

public:
	virtual FString GetDescription(int32 Level) override;
	virtual FString GetNextLevelDescription(int32 Level) override;

	UFUNCTION(BlueprintCallable)
	void SpawnProjectiles(const FVector& ProjectileTargetLocation, const FGameplayTag& SocketTag, AActor* HomingTarget,
	                      bool bOverridePitch = false, float PitchOverride = 0.f);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Firebolt")
	float ProjectileSpread = 90.f;

	UPROPERTY(EditDefaultsOnly, Category="Firebolt")
	int32 MaxNumProjectiles = 5;

	UPROPERTY(EditDefaultsOnly, Category="Firebolt")
	float HomingAccelerationMin = 1600.f;

	UPROPERTY(EditDefaultsOnly, Category="Firebolt")
	float HomingAccelerationMax = 3200.f;

	UPROPERTY(EditDefaultsOnly, Category="Firebolt")
	bool bLaunchHomingProjectiles = true;
};
