// Copywrite, ciN 2017

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUND_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	

  // returns a Patrol point.
  AActor* GetPatrolPoint(int32 InIndex) const;

  int32 GetPatrolPointLength();
  
protected:




  /******************************
  * Methods                     *
  ******************************/


public:	

private:
  /******************************
  * Properties                  *
  ******************************/

  UPROPERTY(EditInstanceOnly, Category = "Patrol")
  TArray<AActor*> PatrolPoints;

	
};
