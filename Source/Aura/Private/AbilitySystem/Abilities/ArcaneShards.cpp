// Copyright JQX Software


#include "AbilitySystem/Abilities/ArcaneShards.h"

FString UArcaneShards::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			"<Title>ARCANE SHARDS</>\n"
			"<Small>Level: </><Level>%d</>\n"
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			"<Default>Summon shards of arcane energy,"
			" causing radial arcane damage of "
			"</><Damage>%d</><Default> at the shard origin.</>"),
							   Level,
							   ManaCost,
							   Cooldown,
							   ScaledDamage);
	}
	return FString::Printf(TEXT(
		"<Title>ARCANE SHARDS</>\n"
		"<Small>Level: </><Level>%d</>\n"
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
		"<Default>Summons %d shards of arcane energy,"
		" causing radial arcane damage of "
		"</><Damage>%d</><Default> at the shard origins.</>"),
						   Level,
						   ManaCost,
						   Cooldown,
						   FMath::Min(Level, MaxNumShards),
						   ScaledDamage);
}

FString UArcaneShards::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
		"<Title>NEXT LEVEL</>\n"
		"<Small>Level: </><Level>%d</>\n"
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
		"<Default>Summons %d shards of arcane energy,"
		" causing radial arcane damage of "
		"</><Damage>%d</><Default> at the shard origins.</>"),
						   Level,
						   ManaCost,
						   Cooldown,
						   FMath::Min(Level, MaxNumShards),
						   ScaledDamage);
}