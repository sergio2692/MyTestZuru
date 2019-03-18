// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"


AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomMesh = CreateDefaultSubobject<UProceduralMeshComponent>("CustomMesh");
	SetRootComponent(CustomMesh);
	CustomMesh->bUseAsyncCooking = true;

	handle1 = CreateDefaultSubobject<UProceduralMeshComponent>("handle1");
	handle2 = CreateDefaultSubobject<UProceduralMeshComponent>("handle2");
	handle3 = CreateDefaultSubobject<UProceduralMeshComponent>("handle3");
	handle4 = CreateDefaultSubobject<UProceduralMeshComponent>("handle4");

	piede1 = CreateDefaultSubobject<UProceduralMeshComponent>("piede1");
	piede2 = CreateDefaultSubobject<UProceduralMeshComponent>("piede2");
	piede3 = CreateDefaultSubobject<UProceduralMeshComponent>("piede3");
	piede4 = CreateDefaultSubobject<UProceduralMeshComponent>("piede4");

}



// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();


	GenerateCubeMesh(CustomMesh,8,200, VertTable);
	
	GenerateCubeMesh(handle1, 10, 10, VertHandle1);
	GenerateCubeMesh(handle2, 10, 10, VertHandle2);
	GenerateCubeMesh(handle3, 10, 10, VertHandle3);

	GenerateCubeMesh(handle4, 10, 10, VertHandle4);

	GenerateCubeMesh(piede1, 70,10, Vertpiede1);
	GenerateCubeMesh(piede2, 70, 10, Vertpiede2);
	GenerateCubeMesh(piede3, 70, 10, Vertpiede3);
	GenerateCubeMesh(piede4, 70, 10, Vertpiede4);

	CustomMesh->SetWorldLocation(FVector(0, 0, 0));

	handle1->SetWorldLocation(VertTable[1] - FVector(5, 5, 0));
	
	handle2->SetWorldLocation(VertTable[3] - FVector(5, 5, 0));
	handle3->SetWorldLocation(VertTable[5] - FVector(5, 5, 0));
	handle4->SetWorldLocation(VertTable[6] - FVector(5, 5, 0));



	piede1->SetWorldLocation(FVector(VertTable[1].X, VertTable[1].Y, VertTable[1].Z -75));
	piede2->SetWorldLocation(FVector(VertTable[3].X, VertTable[3].Y - 10, VertTable[3].Z - 75));
	piede3->SetWorldLocation(FVector(VertTable[5].X-10, VertTable[5].Y , VertTable[5].Z - 75));
	piede4->SetWorldLocation(FVector(VertTable[6].X-10, VertTable[6].Y -10, VertTable[6].Z - 75));

	for (int i = 0;i < ChairSpawned.Num(); i++) {
		ChairSpawned[i]->Destroy();
	}
	ChairSpawned.Empty();


	//0 left | 4 right | 2 front left | 6 front right
	RefreshChair(VertTable[0].X, VertTable[4].X, VertTable[0].Y-25, VertTable[0].Z-50, TypeCost::tipoY,180.0f);
	RefreshChair(VertTable[2].X, VertTable[6].X, VertTable[2].Y+25, VertTable[0].Z-50, TypeCost::tipoY,0.0f);

	RefreshChair(VertTable[4].Y, VertTable[6].Y, VertTable[4].X+25, VertTable[0].Z-50, TypeCost::tipoX,270.0f);
	RefreshChair(VertTable[0].Y, VertTable[2].Y, VertTable[2].X-25, VertTable[0].Z-50, TypeCost::tipoX,90.0f);
}

void AMyActor::AddTriangle(TArray<int32>& Triangles,int32 V1, int32 V2, int32 V3)
{
	Triangles.Add(V1);
	Triangles.Add(V2);
	Triangles.Add(V3);
}

void AMyActor::RefreshChair(float start, float end ,float costante, float z, TypeCost::tipi type,float rot)
{
	

	auto numbOfCHair = floor((end - start) / 80);

	auto posChair = (end - start) / numbOfCHair;

	FVector location = FVector(0, 0, 0);

	//FString startE = FString::SanitizeFloat(start);
	//FString EndE = FString::SanitizeFloat(costante);

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("X ")+ startE);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Y ") + EndE);

	
	for (int i = 1;i < numbOfCHair; i++) {
		if (type == TypeCost::tipoX) {
			location = FVector(costante,start + (posChair * i), z);
		}
		else if (type == TypeCost::tipoY) {
			location = FVector(start + (posChair * i), costante, z);
		}
		FTransform transford = GetActorTransform();
		
		FVector WorldVector = FVector(0, 0, 0);


		FRotator Rotation(0.0f, rot, 0.0f);
		FActorSpawnParameters SpawnInfo;
		
		FVector worldLoc = GetTransform().TransformPosition(location);
		

		AActor* gen = GetWorld()->SpawnActor<AActor>(chair, worldLoc, Rotation, SpawnInfo);
		
		gen->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepWorld, true));

		ChairSpawned.Add(gen);
	}
	

}

void AMyActor::GenerateCubeMesh(UProceduralMeshComponent* proceduralmesh, int32 h, int32 w, TArray<FVector>& Vertices)
{
	//6 sides on cube, 4 verts each (corners)

	//These are relative locations to the placed Actor in the world
	Vertices.Add(FVector(0, 0, 0)); //lower left - 0
	Vertices.Add(FVector(0, 0, h)); //upper left - 1
	Vertices.Add(FVector(0, w, 0)); //lower right - 2 
	Vertices.Add(FVector(0, w, h)); //upper right - 3

	Vertices.Add(FVector(w, 0, 0)); //lower front left - 4
	Vertices.Add(FVector(w, 0, h)); //upper front left - 5

	Vertices.Add(FVector(w, w, h)); //upper front right - 6
	Vertices.Add(FVector(w, w, 0)); //lower front right - 7
	
	TArray<FVector2D> uvs;
	uvs.Add(FVector2D(0.0f, 0.0f));
	uvs.Add(FVector2D(0.0f, 0.0f));
	uvs.Add(FVector2D(0.0f, 1.0f));
	uvs.Add(FVector2D(0.0f, 1.0f));
	uvs.Add(FVector2D(1.0f, 0.0f));
	uvs.Add(FVector2D(1.0f, 0.0f));
	uvs.Add(FVector2D(1.0f, 1.0f));
	uvs.Add(FVector2D(1.0f, 1.0f));

	TArray<int32> Triangles;

	
	//Back face of cube
	AddTriangle(Triangles,0, 2, 3);
	AddTriangle(Triangles,3, 1, 0);

	//Left face of cube
	AddTriangle(Triangles,0, 1, 4);
	AddTriangle(Triangles,4, 1, 5);

	//Front face of cube
	AddTriangle(Triangles,4, 5, 7);
	AddTriangle(Triangles,7, 5, 6);

	//Right face of cube
	AddTriangle(Triangles,7, 6, 3);
	AddTriangle(Triangles,3, 2, 7);

	//Top face
	AddTriangle(Triangles,1, 3, 5);
	AddTriangle(Triangles,6, 5, 3);

	//bottom face
	AddTriangle(Triangles,2, 0, 4);
	AddTriangle(Triangles,4, 7, 2);

	TArray<FColor> vertexColors;
	/**
	VertexColors.Add(FLinearColor(0.f, 0.f, 1.f));
	VertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
	VertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
	VertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
	VertexColors.Add(FLinearColor(0.5f, 1.f, 0.5f));
	VertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
	VertexColors.Add(FLinearColor(1.f, 1.f, 0.f));
	VertexColors.Add(FLinearColor(0.f, 1.f, 1.f));
	*/

	vertexColors.Init(FColor(0.0f, 0.0f, 0.0f, 1.0f), 3);

	proceduralmesh->CreateMeshSection(0, Vertices, Triangles,TArray<FVector>(),uvs,vertexColors,TArray<FProcMeshTangent>(),true);
}

void AMyActor::UpdateMesh(UProceduralMeshComponent* handle, int32 x, int32 y)
{

	if (handle == handle1) {

		VertTable[0].X = x;
		VertTable[0].Y = y;
		VertTable[1].X = x;
		VertTable[1].Y = y;


		VertTable[2].X = x;

		VertTable[3].X = x;

		VertTable[4].Y = y;

		VertTable[5].Y = y;




	}
	if (handle == handle2) {

		VertTable[2].X = x;
		VertTable[2].Y = y;
		VertTable[3].X = x;
		VertTable[3].Y = y;

		
		VertTable[0].X = x;

		VertTable[1].X = x;

		VertTable[6].Y = y;

		VertTable[7].Y = y;

	}
	if (handle == handle3) {

		VertTable[4].X = x;
		VertTable[4].Y = y;
		VertTable[5].X = x;
		VertTable[5].Y = y;


		VertTable[6].X = x;

		VertTable[7].X = x;

		VertTable[0].Y = y;

		VertTable[1].Y = y;


	}
	if (handle == handle4) {

		VertTable[6].X = x;
		VertTable[6].Y = y;

		VertTable[7].X = x;
		VertTable[7].Y = y;


		VertTable[4].X = x;

		VertTable[5].X = x;

		VertTable[2].Y = y;

		VertTable[3].Y = y;

	}
	
	handle1->SetWorldLocation(VertTable[1] - FVector(5, 5, 0));
	handle2->SetWorldLocation(VertTable[3] - FVector(5, 5, 0));
	handle3->SetWorldLocation(VertTable[5] - FVector(5, 5, 0));
	handle4->SetWorldLocation(VertTable[6] - FVector(5, 5, 0));

	piede1->SetWorldLocation(FVector(VertTable[1].X, VertTable[1].Y, VertTable[1].Z - 75));
	piede2->SetWorldLocation(FVector(VertTable[3].X, VertTable[3].Y - 10, VertTable[3].Z - 75));
	piede3->SetWorldLocation(FVector(VertTable[5].X - 10, VertTable[5].Y, VertTable[5].Z - 75));
	piede4->SetWorldLocation(FVector(VertTable[6].X - 10, VertTable[6].Y - 10, VertTable[6].Z - 75));

	CustomMesh->UpdateMeshSection(0, VertTable, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>());
	CustomMesh->SetWorldLocation(FVector(0, 0, 0));

	for (int i = 0;i < ChairSpawned.Num(); i++) {
		ChairSpawned[i]->Destroy();
	}
	ChairSpawned.Empty();

	
	//FString startE = FString::SanitizeFloat(VertTable[0].X);
	//FString startEY = FString::SanitizeFloat(VertTable[0].Y);
	//FString EndE = FString::SanitizeFloat(VertTable[4].X);

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("vert X ") + startE);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("vert Y ") + startEY);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("vert end ") + EndE);


	RefreshChair(VertTable[0].X, VertTable[4].X, VertTable[0].Y - 25, VertTable[0].Z - 50, TypeCost::tipoY, 180.0f);
	RefreshChair(VertTable[2].X, VertTable[6].X, VertTable[2].Y + 25, VertTable[0].Z - 50, TypeCost::tipoY, 0.0f);

	RefreshChair(VertTable[4].Y, VertTable[6].Y, VertTable[4].X + 25, VertTable[0].Z - 50, TypeCost::tipoX, 270.0f);
	RefreshChair(VertTable[0].Y, VertTable[2].Y, VertTable[2].X - 25, VertTable[0].Z - 50, TypeCost::tipoX, 90.0f);
	
}
