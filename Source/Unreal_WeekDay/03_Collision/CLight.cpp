#include "CLight.h"
#include "Global.h"
#include "CTrigger.h"
#include "Components/TextRenderComponent.h"
#include "Components/PointLightComponent.h"

ACLight::ACLight()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	CHelpers::CreateComponent<UPointLightComponent>(this, &Light, "Light", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 90, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	Light->Intensity = 1e+4f;
	// ���� �ݰ�
	Light->AttenuationRadius = 200;
	Light->LightColor = FColor(255, 128, 5);
}

void ACLight::BeginPlay()
{
	Super::BeginPlay();
	Light->SetVisibility(false);

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
										  ACTrigger::StaticClass(), actors);
	CheckFalse(actors.Num() > 0);
	ACTrigger* trigger = Cast<ACTrigger>(actors[0]);
	trigger->OnBoxLightBeginOverlap.BindUFunction(this, "OnLight");	
	trigger->OnBoxLightEndOverlap.BindUFunction(this, "OffLight");	
}

void ACLight::OnLight()
{
	Light->SetVisibility(true);

}
void ACLight::OffLight()
{
	Light->SetVisibility(false);
}


