// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseWayRouteTask.h"
#include "behaviortree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRouteComponent.h"


EBTNodeResult::Type UChooseWayRouteTask::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UPatrolRouteComponent *PatrolRouteComp = OwnerComp.GetAIOwner()->GetPawn() ->FindComponentByClass<UPatrolRouteComponent>();
	if (!ensure(PatrolRouteComp)) {
		return EBTNodeResult::Failed;
	}

	if (PatrolRouteComp->GetPatrolPoints().Num() == 0) {
		return EBTNodeResult::Failed;
	}

	// 1
	int index = OwnerComp.GetBlackboardComponent()->GetValueAsInt(IndexSelected.SelectedKeyName);
	AActor* point = PatrolRouteComp->GetPatrolPoints()[index];
	if (!ensure(point)) {
		return EBTNodeResult::Failed;
	}

	// 2
	OwnerComp.GetBlackboardComponent()->SetValueAsObject(SelectedObject.SelectedKeyName, point);


	// 3
	index++;
	index = index % PatrolRouteComp->GetPatrolPoints().Num();
	OwnerComp.GetBlackboardComponent()->SetValueAsInt(IndexSelected.SelectedKeyName, index);

	return EBTNodeResult::Succeeded;
}