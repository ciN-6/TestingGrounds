// Copywrite, ciN 2017

#include "TestingGround.h"
#include "Gun.h"
#include "Animation/AnimInstance.h"
#include "BallProjectile.h"

// Sets default values
AGun::AGun()
{
  Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
  Gun->bCastDynamicShadow = false;
  Gun->CastShadow = false;
  Gun->SetupAttachment(RootComponent);

  MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
  MuzzleLocation->SetupAttachment(Gun);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
  
}

void AGun::OnFire()
{

  if (ProjectileClass != NULL)
  {
    UWorld* const World = GetWorld();
    if (World != NULL)
    {
      const FRotator SpawnRotation = MuzzleLocation->GetComponentRotation();      
      const FVector SpawnLocation = MuzzleLocation->GetComponentLocation();
      FActorSpawnParameters ActorSpawnParams;
      ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
      World->SpawnActor<ABallProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
    }
  }

  // try and play the sound if specified
  if (FireSound != NULL){    
    UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
  }

  // try and play a firing animation if specified
  if (FireAnimation != NULL){
    if (AnimInstance != NULL){
      AnimInstance->Montage_Play(FireAnimation, 1.f);
    }
  }
}




// Called every frame
void AGun::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}

