// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGround.h"
#include "AIController.h"
#include "Behavior/PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "ChooseNextWaypoint.h"




EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

  UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
  int32 CurrentIndex = Blackboard->GetValueAsInt(this->Index.SelectedKeyName);  
 // APatrollingGuard* Guard = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());

  UPatrolRoute* RouteComponent = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolRoute>();

  if (!RouteComponent) { 
    return EBTNodeResult::Failed;}

  AActor* NextPoint = RouteComponent->GetPatrolPoint(CurrentIndex);

  if (!NextPoint) {
    return EBTNodeResult::Failed; }

  Blackboard->SetValueAsObject(this->Waypoint.SelectedKeyName, NextPoint);
  
  CurrentIndex = (CurrentIndex + 1) % (RouteComponent->GetPatrolPointLength());
  Blackboard->SetValueAsInt(this->Index.SelectedKeyName, CurrentIndex);

  return EBTNodeResult::Succeeded;
}

