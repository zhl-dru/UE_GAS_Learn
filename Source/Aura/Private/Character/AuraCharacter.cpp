// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	// 获取角色运动组件
	// 旋转玩家朝向加速方向为 true
	GetCharacterMovement()->bOrientRotationToMovement = true;
	// 设置水平旋转速度为400度/秒
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	// 限制角色移动在一个平面上
	GetCharacterMovement()->bConstrainToPlane = true;
	// 指定角色在开始移动时立即贴合到所在平面上
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// 设置角色旋转不受控制器方向的影响
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}
