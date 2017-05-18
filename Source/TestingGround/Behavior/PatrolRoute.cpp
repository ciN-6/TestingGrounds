// Copywrite, ciN 2017

#include "TestingGround.h"
#include "PatrolRoute.h"



AActor* UPatrolRoute::GetPatrolPoint(int32 InIndex) const {

  if (FMath::IsWithin(InIndex, 0, PatrolPoints.Num())) {
    return PatrolPoints[InIndex];
  }
  return nullptr;
}

int32 UPatrolRoute::GetPatrolPointLength() {
  return PatrolPoints.Num();
}
