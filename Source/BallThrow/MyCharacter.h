// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"


UCLASS()
class BALLTHROW_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	class AActor* GetActorInHandRef() const;
	void ClearBallInHandRef();
	bool GetBallInHandBool();

private:
	UPROPERTY(EditDefaultsOnly, Category = "References")
		TSubclassOf<class ABallCollectorCharacter> BallCollectorClass;
	UPROPERTY(EditDefaultsOnly, Category = "References")
		TSubclassOf<class ABallCollectorController> BallCollectorControllerClass;

	AActor* ActorInHandRef;
	AActor* NearestActor;

	class UBallCounterWidget* BallCounterWidget;

	FVector BallCollectorSpawnLocation = FVector(0, 0, 180);

	bool BallInHandBool = false;

	float InteractionDistance = 150.0f;

	float ThrowSpeed = 800.0f;
	float ThrowZOffset = 800.0f;

	void SpawnNewBallCollector();
	void NearestActorHandling();
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Interact();
	void ThrowBall();

};