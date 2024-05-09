// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"

AAuraPlayerState::AAuraPlayerState()
{
	// 创建GAS组件
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	// 启用GAS网络复制
	AbilitySystemComponent->SetIsReplicated(true);
	// 设置玩家的网络复制模式为混合
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// 创建GAS属性集
	AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");

	// 设置服务器尝试更新客户端的频率为100次/秒
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
