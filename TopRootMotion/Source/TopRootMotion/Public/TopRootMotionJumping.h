#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "TopRootMotionJumping.generated.h"

UCLASS(DisplayName = "Top Root Motion Jumping")
class UTopRootMotionJumping : public UAnimNotifyState
{
	GENERATED_BODY()

public:

	UPROPERTY(EditInstanceOnly)
		float RootMotionHeightScale = 1.f;
	UPROPERTY(EditInstanceOnly, meta = (ToolTip = "Should Set StartTime at the begin of notify (second)"))
		float StartTime = 0.f;
	UPROPERTY(EditInstanceOnly, meta = (ToolTip = "Reduce velocity at the notify end"))
		float EndNotifyReduceVelocityRatio = 0.1f;

	UPROPERTY()
		ACharacter* Character;

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) final;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime) final;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	virtual FString GetNotifyName_Implementation() const { return FString("Root Motion Control Height"); }

#if WITH_EDITOR
	virtual FLinearColor GetEditorColor() override { return FLinearColor::White; }
#endif

private:
	UAnimSequence* AnimSequence;
	float CurrentDuration;
	float CharacterLocationZ;

	FTransform ExtractRootTrackTransform(float AnimTime) const;
};
