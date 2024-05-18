// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()

public:
	AAuraEffectActor();

protected:
	virtual void BeginPlay() override;

	// 应用效果到目标
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass) const;

	// 即时游戏效果
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="应用效果")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	// 持续游戏效果
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="应用效果")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
};
