// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"

UCLASS()
class UNREAL_WEEKDAY_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

private :
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent*	SpringArm;
	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent*		Camera;

private:
	class UMaterialInstanceDynamic* BodyMaterial;
	class UMaterialInstanceDynamic* LogoMaterial;

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private :
	void OnMoveForward(float Axis);
	void OnMoveRight(float Axis);
	void OnHorizontalLook(float Axis);
	void OnVerticalLook(float Axis);
	void OnRunning();
	void OffRunning();

public:
	UFUNCTION(BlueprintCallable)
		void ChangeColor(FLinearColor InColor);
};
