#include "TopRootMotionScale.h"
#include "GameFramework/Character.h"
#include "TopRootMotionBPLibrary.h"

void UTopRootMotionScale::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	Character = Cast<ACharacter>(MeshComp->GetOwner());
	if (Character)
		UTopRootMotionBPLibrary::SetRootMotionScale(Character, RootMotionScale);
}

void UTopRootMotionScale::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);

	if (Character)
		UTopRootMotionBPLibrary::SetRootMotionScale(Character, 1.f);
}

FLinearColor UTopRootMotionScale::GetEditorColor()
{
	Super::GetEditorColor();
	return FLinearColor::Green;
}
