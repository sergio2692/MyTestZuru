// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProceduralChair.h"


// Sets default values
AMyProceduralChair::AMyProceduralChair()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomMesh = CreateDefaultSubobject<UProceduralMeshComponent>("CustomMesh");
	SetRootComponent(CustomMesh);
	CustomMesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned
void AMyProceduralChair::BeginPlay()
{
	Super::BeginPlay();

	TArray<FVector> Vertices;

	Vertices.Add(FVector(-21.1786, 0, 22.9004));
	Vertices.Add(FVector(-21.1786, 0.0000, 12.8700));
	Vertices.Add(FVector(-12.1414,0.0000,12.8700));
	Vertices.Add(FVector(-12.1414,0.0000,22.9004));
	Vertices.Add(FVector(-21.1786,41.0521,22.9004));
	Vertices.Add(FVector(-12.1414,41.0521,22.9004));
	Vertices.Add(FVector(-12.1414,41.0521,12.8700));
	Vertices.Add(FVector(-21.1786,41.0521,12.8700));
	Vertices.Add(FVector(-20.9548,0.0000,-23.5098));
	Vertices.Add(FVector(-20.9548,0.0000,-33.5402));
	Vertices.Add(FVector(-11.9176,0.0000,-33.5402));
	Vertices.Add(FVector(-11.9176,0.0000,-23.5098));
	Vertices.Add(FVector(-20.9548,41.0521,-23.5098));
	Vertices.Add(FVector(-11.9176,41.0521,-23.5098));
	Vertices.Add(FVector(-11.9176,41.0521,-33.5402));
	Vertices.Add(FVector(-20.9548,41.0521,-33.5402));
	Vertices.Add(FVector(20.4074,0.0000,-23.2210));
	Vertices.Add(FVector(20.4074,0.0000,-33.2514));
	Vertices.Add(FVector(29.4446,0.0000,-33.2514));
	Vertices.Add(FVector(29.4446,0.0000,-23.2210));
	Vertices.Add(FVector(20.4074,41.0521,-23.2210));
	Vertices.Add(FVector(29.4446,41.0521,-23.2210));
	Vertices.Add(FVector(29.4446,41.0521,-33.2514));
	Vertices.Add(FVector(20.4074,41.0521,-33.2514));
	Vertices.Add(FVector(20.1938,47.4724,23.7569));
	Vertices.Add(FVector(20.1938,47.4724,13.7265));
	Vertices.Add(FVector(29.2310,47.4724,13.7265));
	Vertices.Add(FVector(29.2310,47.4724,23.7569));
	Vertices.Add(FVector(20.1938,88.5245,23.7569));
	Vertices.Add(FVector(29.2310,88.5245,23.7569));
	Vertices.Add(FVector(29.2310,88.5245,13.7265));
	Vertices.Add(FVector(20.1938,88.5245,13.7265));
	Vertices.Add(FVector(-25.0964,41.6536,23.8247));
	Vertices.Add(FVector(-25.0964,41.6536,-35.6895));
	Vertices.Add(FVector(33.6026,41.6536,-35.6895));
	Vertices.Add(FVector(33.6026,41.6536,23.8247));
	Vertices.Add(FVector(-25.0964,47.3605,23.8247));
	Vertices.Add(FVector(33.6026,47.3605,23.8247));
	Vertices.Add(FVector(33.6026,47.3605,-35.6895));
	Vertices.Add(FVector(-25.0964,47.3605,-35.6895));
	Vertices.Add(FVector(20.1938,0.0000,22.4246));
	Vertices.Add(FVector(20.1938,0.0000,12.3942));
	Vertices.Add(FVector(29.2310,0.0000,12.3942));
	Vertices.Add(FVector(29.2310,0.0000,22.4246));
	Vertices.Add(FVector(20.1938,41.0521,22.4246));
	Vertices.Add(FVector(29.2310,41.0521,22.4246));
	Vertices.Add(FVector(29.2310,41.0521,12.3942));
	Vertices.Add(FVector(20.1938,41.0521,12.3942));
	Vertices.Add(FVector(-21.2704,47.4724,23.7569));
	Vertices.Add(FVector(-21.2704,47.4724,13.7265));
	Vertices.Add(FVector(-12.2332,47.4724,13.7265));
	Vertices.Add(FVector(-12.2332,47.4724,23.7569));
	Vertices.Add(FVector(-21.2704,88.5245,23.7569));
	Vertices.Add(FVector(-12.2332,88.5245,23.7569));
	Vertices.Add(FVector(-12.2332,88.5245,13.7265));
	Vertices.Add(FVector(-21.2704,88.5245,13.7265));
	Vertices.Add(FVector(33.5267,89.2714,13.3313));
	Vertices.Add(FVector(33.5267,95.7935,13.3313));
	Vertices.Add(FVector(33.5267,95.7935,23.1145));
	Vertices.Add(FVector(33.5267,89.2714,23.1145));
	Vertices.Add(FVector(-25.1723,89.2714,13.3313));
	Vertices.Add(FVector(-25.1723,89.2714,23.1145));
	Vertices.Add(FVector(-25.1723,95.7935,23.1145));
	Vertices.Add(FVector(-25.1723,95.7935,13.3313));
	Vertices.Add(FVector(33.5267,65.1296,13.3313));
	Vertices.Add(FVector(33.5267,71.6517,13.3313));
	Vertices.Add(FVector(33.5267,71.6517,23.1145));
	Vertices.Add(FVector(33.5267,65.1296,23.1145));
	Vertices.Add(FVector(-25.1723,65.1296,13.3313));
	Vertices.Add(FVector(-25.1723,65.1296,23.1145));
	Vertices.Add(FVector(-25.1723,71.6517,23.1145));
	Vertices.Add(FVector(-25.1723,71.6517,13.3313));

	TArray<int32> Triangles;
	Triangles.Add(2);	Triangles.Add(1);	Triangles.Add(0);
	Triangles.Add(0);	Triangles.Add(3);	Triangles.Add(2);
	Triangles.Add(6);	Triangles.Add(5);	Triangles.Add(4);
	Triangles.Add(4);	Triangles.Add(7);	Triangles.Add(6);
	Triangles.Add(5);	Triangles.Add(3);	Triangles.Add(0);
	Triangles.Add(0);	Triangles.Add(4);	Triangles.Add(5);
	Triangles.Add(6);	Triangles.Add(2);	Triangles.Add(3);
	Triangles.Add(3);	Triangles.Add(5);	Triangles.Add(6);
	Triangles.Add(7);	Triangles.Add(1);	Triangles.Add(2);
	Triangles.Add(2);	Triangles.Add(6);	Triangles.Add(7);
	Triangles.Add(4);	Triangles.Add(0);	Triangles.Add(1);
	Triangles.Add(1);	Triangles.Add(7);	Triangles.Add(4);
	Triangles.Add(10);	Triangles.Add(9);	Triangles.Add(8);
	Triangles.Add(8);	Triangles.Add(11);	Triangles.Add(10);
	Triangles.Add(14);	Triangles.Add(13);	Triangles.Add(12);
	Triangles.Add(12);	Triangles.Add(15);	Triangles.Add(14);
	Triangles.Add(13);	Triangles.Add(11);	Triangles.Add(8);
	Triangles.Add(8);	Triangles.Add(12);	Triangles.Add(13);
	Triangles.Add(14);	Triangles.Add(10);	Triangles.Add(11);
	Triangles.Add(11);	Triangles.Add(13);	Triangles.Add(14);
	Triangles.Add(15);	Triangles.Add(9);	Triangles.Add(10);
	Triangles.Add(10);	Triangles.Add(14);	Triangles.Add(15);
	Triangles.Add(12);	Triangles.Add(8);	Triangles.Add(9);
	Triangles.Add(9);	Triangles.Add(15);	Triangles.Add(12);
	Triangles.Add(18);	Triangles.Add(17);	Triangles.Add(16);
	Triangles.Add(16);	Triangles.Add(19);	Triangles.Add(18);
	Triangles.Add(22);	Triangles.Add(21);	Triangles.Add(20);
	Triangles.Add(20);	Triangles.Add(23);	Triangles.Add(22);
	Triangles.Add(21);	Triangles.Add(19);	Triangles.Add(16);
	Triangles.Add(16);	Triangles.Add(20);	Triangles.Add(21);
	Triangles.Add(22);	Triangles.Add(18);	Triangles.Add(19);
	Triangles.Add(19);	Triangles.Add(21);	Triangles.Add(22);
	Triangles.Add(23);	Triangles.Add(17);	Triangles.Add(18);
	Triangles.Add(18);	Triangles.Add(22);	Triangles.Add(23);
	Triangles.Add(20);	Triangles.Add(16);	Triangles.Add(17);
	Triangles.Add(17);	Triangles.Add(23);	Triangles.Add(20);
	Triangles.Add(26);	Triangles.Add(25);	Triangles.Add(24);
	Triangles.Add(24);	Triangles.Add(27);	Triangles.Add(26);
	Triangles.Add(30);	Triangles.Add(29);	Triangles.Add(28);
	Triangles.Add(28);	Triangles.Add(31);	Triangles.Add(30);
	Triangles.Add(29);	Triangles.Add(27);	Triangles.Add(24);
	Triangles.Add(24);	Triangles.Add(28);	Triangles.Add(29);
	Triangles.Add(30);	Triangles.Add(26);	Triangles.Add(27);
	Triangles.Add(27);	Triangles.Add(29);	Triangles.Add(30);
	Triangles.Add(31);	Triangles.Add(25);	Triangles.Add(26);
	Triangles.Add(26);	Triangles.Add(30);	Triangles.Add(31);
	Triangles.Add(28);	Triangles.Add(24);	Triangles.Add(25);
	Triangles.Add(25);	Triangles.Add(31);	Triangles.Add(28);
	Triangles.Add(34);	Triangles.Add(33);	Triangles.Add(32);
	Triangles.Add(32);	Triangles.Add(35);	Triangles.Add(34);
	Triangles.Add(38);	Triangles.Add(37);	Triangles.Add(36);
	Triangles.Add(36);	Triangles.Add(39);	Triangles.Add(38);
	Triangles.Add(37);	Triangles.Add(35);	Triangles.Add(32);
	Triangles.Add(32);	Triangles.Add(36);	Triangles.Add(37);
	Triangles.Add(38);	Triangles.Add(34);	Triangles.Add(35);
	Triangles.Add(35);	Triangles.Add(37);	Triangles.Add(38);
	Triangles.Add(39);	Triangles.Add(33);	Triangles.Add(34);
	Triangles.Add(34);	Triangles.Add(38);	Triangles.Add(39);
	Triangles.Add(36);	Triangles.Add(32);	Triangles.Add(33);
	Triangles.Add(33);	Triangles.Add(39);	Triangles.Add(36);
	Triangles.Add(34);	Triangles.Add(33);	Triangles.Add(32);
	Triangles.Add(32);	Triangles.Add(35);	Triangles.Add(34);
	Triangles.Add(38);	Triangles.Add(37);	Triangles.Add(36);
	Triangles.Add(36);	Triangles.Add(39);	Triangles.Add(38);
	Triangles.Add(37);	Triangles.Add(35);	Triangles.Add(32);
	Triangles.Add(32);	Triangles.Add(36);	Triangles.Add(37);
	Triangles.Add(38);	Triangles.Add(34);	Triangles.Add(35);
	Triangles.Add(35);	Triangles.Add(37);	Triangles.Add(38);
	Triangles.Add(39);	Triangles.Add(33);	Triangles.Add(34);
	Triangles.Add(34);	Triangles.Add(38);	Triangles.Add(39);
	Triangles.Add(36);	Triangles.Add(32);	Triangles.Add(33);
	Triangles.Add(33);	Triangles.Add(39);	Triangles.Add(36);
	Triangles.Add(42);	Triangles.Add(41);	Triangles.Add(40);
	Triangles.Add(40);	Triangles.Add(43);	Triangles.Add(42);
	Triangles.Add(46);	Triangles.Add(45);	Triangles.Add(44);
	Triangles.Add(44);	Triangles.Add(47);	Triangles.Add(46);
	Triangles.Add(45);	Triangles.Add(43);	Triangles.Add(40);
	Triangles.Add(40);	Triangles.Add(44);	Triangles.Add(45);
	Triangles.Add(46);	Triangles.Add(42);	Triangles.Add(43);
	Triangles.Add(43);	Triangles.Add(45);	Triangles.Add(46);
	Triangles.Add(47);	Triangles.Add(41);	Triangles.Add(42);
	Triangles.Add(42);	Triangles.Add(46);	Triangles.Add(47);
	Triangles.Add(44);	Triangles.Add(40);	Triangles.Add(41);
	Triangles.Add(41);	Triangles.Add(47);	Triangles.Add(44);
	Triangles.Add(50);	Triangles.Add(49);	Triangles.Add(48);
	Triangles.Add(48);	Triangles.Add(51);	Triangles.Add(50);
	Triangles.Add(54);	Triangles.Add(53);	Triangles.Add(52);
	Triangles.Add(52);	Triangles.Add(55);	Triangles.Add(54);
	Triangles.Add(53);	Triangles.Add(51);	Triangles.Add(48);
	Triangles.Add(48);	Triangles.Add(52);	Triangles.Add(53);
	Triangles.Add(54);	Triangles.Add(50);	Triangles.Add(51);
	Triangles.Add(51);	Triangles.Add(53);	Triangles.Add(54);
	Triangles.Add(55);	Triangles.Add(49);	Triangles.Add(50);
	Triangles.Add(50);	Triangles.Add(54);	Triangles.Add(55);
	Triangles.Add(52);	Triangles.Add(48);	Triangles.Add(49);
	Triangles.Add(49);	Triangles.Add(55);	Triangles.Add(52);
	Triangles.Add(58);	Triangles.Add(57);	Triangles.Add(56);
	Triangles.Add(56);	Triangles.Add(59);	Triangles.Add(58);
	Triangles.Add(62);	Triangles.Add(61);	Triangles.Add(60);
	Triangles.Add(60);	Triangles.Add(63);	Triangles.Add(62);
	Triangles.Add(61);	Triangles.Add(59);	Triangles.Add(56);
	Triangles.Add(56);	Triangles.Add(60);	Triangles.Add(61);
	Triangles.Add(62);	Triangles.Add(58);	Triangles.Add(59);
	Triangles.Add(59);	Triangles.Add(61);	Triangles.Add(62);
	Triangles.Add(63);	Triangles.Add(57);	Triangles.Add(58);
	Triangles.Add(58);	Triangles.Add(62);	Triangles.Add(63);
	Triangles.Add(60);	Triangles.Add(56);	Triangles.Add(57);
	Triangles.Add(57);	Triangles.Add(63);	Triangles.Add(60);
	Triangles.Add(66);	Triangles.Add(65);	Triangles.Add(64);
	Triangles.Add(64);	Triangles.Add(67);	Triangles.Add(66);
	Triangles.Add(70);	Triangles.Add(69);	Triangles.Add(68);
	Triangles.Add(68);	Triangles.Add(71);	Triangles.Add(70);
	Triangles.Add(69);	Triangles.Add(67);	Triangles.Add(64);
	Triangles.Add(64);	Triangles.Add(68);	Triangles.Add(69);
	Triangles.Add(70);	Triangles.Add(66);	Triangles.Add(67);
	Triangles.Add(67);	Triangles.Add(69);	Triangles.Add(70);
	Triangles.Add(71);	Triangles.Add(65);	Triangles.Add(66);
	Triangles.Add(66);	Triangles.Add(70);	Triangles.Add(71);
	Triangles.Add(68);	Triangles.Add(64);	Triangles.Add(65);
	Triangles.Add(65);	Triangles.Add(71);	Triangles.Add(68);



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

	TArray<FVector2D> uvs;
	uvs.Add(FVector2D(0.1841, 0.2217));
	uvs.Add(FVector2D(0.0155, 0.2217));
	uvs.Add(FVector2D(0.0155, 0.0679));
	uvs.Add(FVector2D(0.1841, 0.0679));
	uvs.Add(FVector2D(0.1841, 0.2217));
	uvs.Add(FVector2D(0.1841, 0.0679));
	uvs.Add(FVector2D(0.0155, 0.0679));
	uvs.Add(FVector2D(0.0155, 0.2217));
	uvs.Add(FVector2D(0.9639, 0.2255));
	uvs.Add(FVector2D(0.7953, 0.2255));
	uvs.Add(FVector2D(0.7953, 0.0718));
	uvs.Add(FVector2D(0.9639, 0.0718));
	uvs.Add(FVector2D(0.9639, 0.2255));
	uvs.Add(FVector2D(0.9639, 0.0718));
	uvs.Add(FVector2D(0.7953, 0.0718));
	uvs.Add(FVector2D(0.7953, 0.2255));
	uvs.Add(FVector2D(0.9590, 0.9293));
	uvs.Add(FVector2D(0.7905, 0.9293));
	uvs.Add(FVector2D(0.7905, 0.7755));
	uvs.Add(FVector2D(0.9590, 0.7755));
	uvs.Add(FVector2D(0.9590, 0.9293));
	uvs.Add(FVector2D(0.9590, 0.7755));
	uvs.Add(FVector2D(0.7905, 0.7755));
	uvs.Add(FVector2D(0.7905, 0.9293));
	uvs.Add(FVector2D(0.1697, 0.9256));
	uvs.Add(FVector2D(0.0011, 0.9256));
	uvs.Add(FVector2D(0.0011, 0.7719));
	uvs.Add(FVector2D(0.1697, 0.7719));
	uvs.Add(FVector2D(0.1697, 0.9256));
	uvs.Add(FVector2D(0.1697, 0.7719));
	uvs.Add(FVector2D(0.0011, 0.7719));
	uvs.Add(FVector2D(0.0011, 0.9256));
	uvs.Add(FVector2D(1.0000, 1.0000));
	uvs.Add(FVector2D(0.0000, 1.0000));
	uvs.Add(FVector2D(0.0000, 0.0013));
	uvs.Add(FVector2D(1.0000, 0.0013));
	uvs.Add(FVector2D(1.0000, 1.0000));
	uvs.Add(FVector2D(1.0000, 0.0013));
	uvs.Add(FVector2D(0.0000, 0.0013));
	uvs.Add(FVector2D(0.0000, 1.0000));
	uvs.Add(FVector2D(0.1921, 0.9256));
	uvs.Add(FVector2D(0.0235, 0.9256));
	uvs.Add(FVector2D(0.0235, 0.7719));
	uvs.Add(FVector2D(0.1921, 0.7719));
	uvs.Add(FVector2D(0.1921, 0.9256));
	uvs.Add(FVector2D(0.1921, 0.7719));
	uvs.Add(FVector2D(0.0235, 0.7719));
	uvs.Add(FVector2D(0.0235, 0.9256));
	uvs.Add(FVector2D(0.1697, 0.2201));
	uvs.Add(FVector2D(0.0011, 0.2201));
	uvs.Add(FVector2D(0.0011, 0.0664));
	uvs.Add(FVector2D(0.1697, 0.0664));
	uvs.Add(FVector2D(0.1697, 0.2201));
	uvs.Add(FVector2D(0.1697, 0.0664));
	uvs.Add(FVector2D(0.0011, 0.0664));
	uvs.Add(FVector2D(0.0011, 0.2201));
	uvs.Add(FVector2D(0.0119, 0.9987));
	uvs.Add(FVector2D(0.0119, 0.9987));
	uvs.Add(FVector2D(0.1763, 0.9987));
	uvs.Add(FVector2D(0.1763, 0.9987));
	uvs.Add(FVector2D(0.0119, 0.0000));
	uvs.Add(FVector2D(0.1763, 0.0000));
	uvs.Add(FVector2D(0.1763, 0.0000));
	uvs.Add(FVector2D(0.0119, 0.0000));
	uvs.Add(FVector2D(0.0119, 0.9987));
	uvs.Add(FVector2D(0.0119, 0.9987));
	uvs.Add(FVector2D(0.1763, 0.9987));
	uvs.Add(FVector2D(0.1763, 0.9987));
	uvs.Add(FVector2D(0.0119, 0.0000));
	uvs.Add(FVector2D(0.1763, 0.0000));
	uvs.Add(FVector2D(0.1763, 0.0000));
	uvs.Add(FVector2D(0.0119, 0.0000));







	vertexColors.Init(FColor(0.0f, 0.0f, 0.0f, 1.0f), 3);

	CustomMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), uvs, vertexColors, TArray<FProcMeshTangent>(), true);
	//CustomMesh->SetWorldRotation(FRotator(0.0f,180.0f,270.0f));
}

// Called every frame
void AMyProceduralChair::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

