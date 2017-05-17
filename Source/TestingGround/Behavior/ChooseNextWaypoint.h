// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUND_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	
	
public:
  virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


protected:
  
  // Expose Index in the Behavior Tree.
  UPROPERTY(EditAnywhere, Category = "BlackBoard")
  struct FBlackboardKeySelector Index;

private:
  void GetPatrolPoints();
};
