#include "CExplosion.h"
#include "Global.h"
#include "Particles/ParticleSystemComponent.h"

ACExplosion::ACExplosion()
{
	CHelpers::CreateComponent<UParticleSystemComponent>
		(this, &Particle, "Particle");
	UParticleSystem* particle;
	CHelpers::GetAsset<UParticleSystem>(&particle, "ParticleSystem'/Game/Effects/P_Cube_Mesh_Test.P_Cube_Mesh_Test'");
	Particle->SetTemplate(particle);
	Particle->bAutoActivate = false;
}

void ACExplosion::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACExplosion::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	Particle->ResetParticles();
	Particle->SetActive(true);

	FVector start = GetActorLocation();
	FVector end = FVector(start.X, start.Y, start.Z+10);

	TArray<TEnumAsByte<EObjectTypeQuery>> queries;
	queries.Add(EObjectTypeQuery::ObjectTypeQuery4); // 프로젝트 세팅 -> 콜리전 -> PhysicsBody를 뜻함
	
	TArray<AActor*> ignoreActors;
	TArray<FHitResult> hitResults;
	if (UKismetSystemLibrary::SphereTraceMultiForObjects
	(GetWorld(), start, end, 200, queries, false, ignoreActors,
		EDrawDebugTrace::ForOneFrame, hitResults, true))
	{
		for (const FHitResult& hitResult : hitResults)
		{
			UStaticMeshComponent* meshComponent = Cast<UStaticMeshComponent>
				(hitResult.GetActor()->GetRootComponent());
			if (!!meshComponent)
			{
				meshComponent->AddRadialImpulse(GetActorLocation(), 1000, 
												meshComponent->GetMass() * 1000.0f,
												ERadialImpulseFalloff::RIF_Linear);
			}
		}
	}
}
