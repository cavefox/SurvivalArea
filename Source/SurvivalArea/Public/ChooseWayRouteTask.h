// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseWayRouteTask.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALAREA_API UChooseWayRouteTask : public UBTTaskNode
{
	GENERATED_BODY()
	
	
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;
	
	UPROPERTY(EditAnywhere, category="Blackboard")
		FBlackboardKeySelector	IndexSelected;

	UPROPERTY(EditAnywhere, category = "Blackboard")
		FBlackboardKeySelector	SelectedObject;
};
