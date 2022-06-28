// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"

class UStaticMeshComponent;
class UCameraComponent;
class USpringArmComponent;


UCLASS()

class TANKSGITGB_API ATankPawn : public APawn
{
	GENERATED_BODY()
	
public:
	ATankPawn();
	void MoveForward (float Value);
	void MoveRight (float Value);
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite,Category="Components")
	UStaticMeshComponent* BodyMesh;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite,Category="Components")
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite,Category="Components")
	USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite,Category="Components")
	UCameraComponent* Camera;
	
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite,Category="Movement")
	float TargetAxisValue= 0.0f;;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Speed")
	float MoveSpeed = 100.0f;
	
    UPROPERTY()
	class ATankPlayerController* TankPlayerController;
	
private:
	float TargetForwardAxisValue = 0.0f;
	float TargetRightAxisValue = 0.0f;
};
