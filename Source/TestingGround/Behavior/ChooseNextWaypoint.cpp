// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGround.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "ChooseNextWaypoint.h"




EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

  UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
  int32 Index = Blackboard->GetValueAsInt(this->Index.SelectedKeyName);
  
  UE_LOG(LogTemp, Warning, TEXT("Index : %i"), Index);

  return EBTNodeResult::Succeeded;

}

void UChooseNextWaypoint::GetPatrolPoints() {
  
}