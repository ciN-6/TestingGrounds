// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGround.h"
#include "BP_NPC_AI.h"




void ABP_NPC_AI::BeginPlay() {
  Super::BeginPlay();
  UE_LOG(LogTemp, Warning, TEXT("AI Controller!"));
}