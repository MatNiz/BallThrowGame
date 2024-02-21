// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"


UCLASS()
class THIRDPERSONGAME_API ABall : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Properties")
		class UStaticMeshComponent* BallMesh;

	//void DisablePhysicAndCollision();
	void Throw(AActor* Actor, float ThrowSpeed, float ThrowZOffset);
	void PickUp(AActor* Actor);
	void ToggleNiagara();

private:
	bool IsPickedUp = false;
	bool IsNiagaraOn = false;


	class UNiagaraComponent* BallNiagaraComponent;
	
};
