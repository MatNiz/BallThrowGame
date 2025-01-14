// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chest.generated.h"

UCLASS()
class BALLTHROW_API AChest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void ChestInteracton();
	bool GetIsChestOpen();

private:
	UPROPERTY(EditDefaultsOnly, Category = "References")
		TSubclassOf<class ABall> BallClass;
	UPROPERTY(EditDefaultsOnly, Category = "Properties")
		class UStaticMeshComponent* ChestMesh;
	UPROPERTY(EditDefaultsOnly, Category = "Properties")
		USceneComponent* SpawnLocationComponent; 
	UPROPERTY(EditDefaultsOnly, Category = "Properties")
		class UStaticMesh* ChestClosedMesh;
	UPROPERTY(EditDefaultsOnly, Category = "Properties")
		class UStaticMesh* ChestOpenMesh;

	UMaterialInstanceDynamic* DynamicMaterialInstance;
	UMaterialInterface* OriginalMaterial;

	FVector SpawnOffset = FVector(50, 0, 50);

	bool IsChestOpen;


	void SpawnBall();

};
