// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Engine.h"
#include "TimerManager.h"
#include "MyActor.generated.h"


UCLASS()
class TABLEANDCHAIR_API AMyActor : public AActor
{
	GENERATED_BODY()
	
		

public:
	// Sets default values for this actor's properties
	AMyActor();

protected:
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UProceduralMeshComponent* CustomMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UProceduralMeshComponent* handle1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UProceduralMeshComponent* handle2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UProceduralMeshComponent* handle3;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UProceduralMeshComponent* handle4;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UProceduralMeshComponent* piede1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UProceduralMeshComponent* piede2;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UProceduralMeshComponent* piede3;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UProceduralMeshComponent* piede4;

	UPROPERTY(EditInstanceOnly, Category = "Chair Class")
		TSubclassOf<AActor> chair;
	
	TArray<FVector> VertTable;

	TArray<FVector> VertHandle1;
	TArray<FVector> VertHandle2;
	TArray<FVector> VertHandle3;
	TArray<FVector> VertHandle4;

	TArray<FVector> Vertpiede1;
	TArray<FVector> Vertpiede2;
	TArray<FVector> Vertpiede3;
	TArray<FVector> Vertpiede4;

	TArray<AActor*> ChairSpawned;
	/* Creates a triangle that connects the given vertices */
	void AddTriangle(TArray<int32>& Triangles,int32 V1, int32 V2, int32 V3);

	struct TypeCost
	{
		enum tipi
		{
			tipoX,tipoY
		};
	};

	void RefreshChair(float start, float end, float costante, float z, TypeCost::tipi type,float rot);

	void GenerateCubeMesh(UProceduralMeshComponent* proceduralmesh, int32 h, int32 w, TArray<FVector>& Vertices);



	UFUNCTION(BlueprintCallable)
	void UpdateMesh(UProceduralMeshComponent * handle, int32 x, int32 y);


public:

	// Called every frame
	
};
