// Fill out your copyright notice in the Description page of Project Settings.


#include "CSpawnActor.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"

//MaterialInstanceConstant'/Game/Materials/MaterialMesh_Inst.MaterialMesh_Inst'

// Sets default values
ACSpawnActor::ACSpawnActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Meshes/Mesh_Cube.Mesh_Cube'");
	Mesh->SetStaticMesh(mesh);

}

// Called when the game starts or when spawned
void ACSpawnActor::BeginPlay()
{
	Super::BeginPlay();

	UMaterialInstanceConstant* material;
	CHelpers::GetAssetDynamic< UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/Materials/MaterialMesh_Inst.MaterialMesh_Inst'");

	Material = UMaterialInstanceDynamic::Create(material, this);
	Mesh->SetMaterial(0, Material);

	UKismetSystemLibrary::K2_SetTimer(this, "ChangeColor", 1.0f, true);
	
}

void ACSpawnActor::ChangeColor()
{
	FLinearColor color;
	color.R = UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f);
	color.G = UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f);
	color.B = UKismetMathLibrary::RandomFloatInRange(0.0f, 1.0f);
	color.A = 1.0f;
	Material->SetVectorParameterValue("Color", color);
}
