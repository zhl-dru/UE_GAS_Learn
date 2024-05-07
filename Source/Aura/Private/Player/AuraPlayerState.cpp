// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

AAuraPlayerState::AAuraPlayerState()
{
	// 设置服务器尝试更新客户端的频率为100次/秒
	NetUpdateFrequency = 100.f;
}
