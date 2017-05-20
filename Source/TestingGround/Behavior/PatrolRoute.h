// Copywrite, ciN 2017

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"

/*
  Contains the route points and helper to get the points.
*/
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

  UPROPERTY(EditAnywhere, Category = "Patrol")
  TArray<AActor*> PatrolPoints;

	
};
