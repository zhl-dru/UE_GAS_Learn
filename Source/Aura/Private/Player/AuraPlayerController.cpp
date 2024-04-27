// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	// 开启网络复制
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 断言输入配置
	check(AuraContext);
	// 获取本地玩家输入子系统的指针
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());
	// 断言输入子系统
	check(Subsystem);
	// 将配置添加到子系统
	Subsystem->AddMappingContext(AuraContext, 0);

	// 显示鼠标
	bShowMouseCursor = true;
	// 鼠标光标为默认
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	// 视口鼠标不锁定
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	// 捕捉时不隐藏
	InputModeData.SetHideCursorDuringCapture(false);
	// 设置输入模式
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// 获取增强输入组件的指针
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	// 绑定输入触发时执行的事件
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	// 获取输入轴向量
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	// 获取角色的旋转
	const FRotator Rotation = GetControlRotation();
	// 得到角色的方向
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	// 向前的向量
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	// 向右的向量
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// 对角色应用移动
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
