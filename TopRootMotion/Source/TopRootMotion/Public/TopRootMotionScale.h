#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "TopRootMotionScale.generated.h"

UCLASS(DisplayName = "Top Root Motion Scale")
class UTopRootMotionScale : public UAnimNotifyState
{
	GENERATED_BODY()

public:

	UPROPERTY(EditInstanceOnly)
		float RootMotionScale = 1.f;

	UPROPERTY()
		ACharacter* Character;

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	virtual FString GetNotifyName_Implementation() const { return FString("RootMotionScale"); }
	virtual FLinearColor GetEditorColor() override;
};
