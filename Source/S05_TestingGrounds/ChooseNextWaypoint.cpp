// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "TP_ThirdPerson/PatrollingCharacter.h" //TODO remove coupling
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//TODO protect against empty patrol routes 
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	//get patrol points 
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingCharacter = Cast<APatrollingCharacter>(ControlledPawn);
	auto PatrolPoints = PatrollingCharacter->PatrolPointsCPP;

	//Set Next Waypoint 
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cycle index
	auto NextIndex = (Index + 1) % PatrolPoints.Num(); 
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex); 

	return EBTNodeResult::Succeeded; 
}


