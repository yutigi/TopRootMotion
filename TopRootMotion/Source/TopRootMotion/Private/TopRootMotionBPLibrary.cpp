#include "TopRootMotionBPLibrary.h"
#include "TopRootMotion.h"
#include "GameFramework/Character.h"

UTopRootMotionBPLibrary::UTopRootMotionBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UTopRootMotionBPLibrary::SetRootMotionScale(ACharacter* Character, const float RootMotionScale)
{
	Character->SetAnimRootMotionTranslationScale(RootMotionScale);
}

