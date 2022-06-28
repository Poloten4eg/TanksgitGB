#include "TankPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
ATankPawn::ATankPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	RootComponent = BodyMesh;

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh -> SetupAttachment(BodyMesh);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BodyMesh);
    SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	
}
void ATankPawn::MoveForward(float Value)
{
	TargetForwardAxisValue = Value;
}

void ATankPawn::MoveRight(float Value)
{
	TargetRightAxisValue = Value;
}

void ATankPawn::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
	
    FVector CurrentLocation = GetActorLocation();
    FVector ForwardVector = GetActorForwardVector();
	FVector RightVector = GetActorRightVector();
    FVector MovePosition = CurrentLocation + ForwardVector * MoveSpeed * TargetForwardAxisValue + (RightVector * MoveSpeed * TargetRightAxisValue);
    SetActorLocation(MovePosition, true);
	
}
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();
    SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, 0.0f));
}