// Copywrite, ciN 2017

#pragma once

#include "GameFramework/Actor.h"
#include "Gun.generated.h"


UCLASS()
class TESTINGGROUND_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

  //Gun mesh
  UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
  class USkeletalMeshComponent* Gun;

  //Location on gun mesh where projectiles should spawn. 
  UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
  class USceneComponent* MuzzleLocation;

  /** Gun muzzle's offset from the characters location */
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
  FVector GunOffset;

  /** Sound to play each time we fire */
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
  class USoundBase* FireSound;

  /** AnimMontage to play each time we fire */
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
  class UAnimMontage* FireAnimation;

  // Projectile class to spawn 
  UPROPERTY(EditDefaultsOnly, Category = Projectile)
  TSubclassOf<class ABallProjectile> ProjectileClass;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
  class UAnimInstance* AnimInstance;

  // Firing Method.
  UFUNCTION(BlueprintCallable, Category = "Input")
  void OnFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
};
