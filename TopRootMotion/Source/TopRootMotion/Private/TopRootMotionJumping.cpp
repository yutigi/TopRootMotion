#include "TopRootMotionJumping.h"

#include "Animation/AnimSequence.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

void UTopRootMotionJumping::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	CurrentDuration = StartTime;
	Character = Cast<ACharacter>(MeshComp->GetOwner());
	if (!Character)
		return;
	AnimSequence = Cast<UAnimSequence>(Animation);
	if (!AnimSequence)
		return;
	CharacterLocationZ = Character->GetActorLocation().Z;
}

void UTopRootMotionJumping::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime);
	CurrentDuration += FrameDeltaTime;
	if (!Character || !AnimSequence)
		return;
	FTransform CurrentRootMotionExtractData = ExtractRootTrackTransform(CurrentDuration);
	const float StandingDownwardForceScale = Character->GetCharacterMovement()->StandingDownwardForceScale;
	const float RootMotionZAxis = CurrentRootMotionExtractData.GetLocation().Z;
	const FVector CalculateGravity = FVector(0.0f, 0.0f, RootMotionZAxis);
	const FVector CurrentActorLocation = Character->GetActorLocation();
	Character->SetActorLocation(FVector(CurrentActorLocation.X,
		CurrentActorLocation.Y,
		CharacterLocationZ + RootMotionZAxis * RootMotionHeightScale),
		true, nullptr, ETeleportType::ResetPhysics);
}

void UTopRootMotionJumping::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	if (!Character || !AnimSequence)
		return;
	CharacterLocationZ = 0;
	Character->GetCharacterMovement()->Velocity = EndNotifyReduceVelocityRatio * Character->GetCharacterMovement()->Velocity;
}

FTransform UTopRootMotionJumping::ExtractRootTrackTransform(float AnimTime) const
{
	FTransform RootTransform;
	AnimSequence->GetBoneTransform(RootTransform, 0, AnimTime, true);
	return RootTransform;
}