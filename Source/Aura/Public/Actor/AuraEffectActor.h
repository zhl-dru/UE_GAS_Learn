// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "AuraEffectActor.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;

// 应用效果的策略
UENUM(BlueprintType)
enum class EEffectApplicationPolicy
{
	ApplyOnOverlap, // 碰撞时
	ApplyOnEndOverlap, // 结束碰撞时
	DoNotApply
};

// 去除效果的策略
UENUM(BlueprintType)
enum class EEffectRemovalPolicy
{
	RemovalOnEndOverlap, // 结束碰撞时
	DoNotRemoval
};

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
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="应用效果")
	bool bDestoryOnEffectRemoval = false;

	// 即时游戏效果
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="应用效果")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	// 应用即时游戏效果的策略
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="应用效果")
	EEffectApplicationPolicy InstantEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	// 持续游戏效果
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="应用效果")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	// 应用持续游戏效果的策略
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="应用效果")
	EEffectApplicationPolicy DurationEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	// 无限游戏效果
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="应用效果")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

	// 应用无限游戏效果的策略
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="应用效果")
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	// 删除无限游戏效果的策略
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="应用效果")
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::RemovalOnEndOverlap;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;
};
