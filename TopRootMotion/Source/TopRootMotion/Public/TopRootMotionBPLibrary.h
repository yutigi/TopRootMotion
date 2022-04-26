#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "TopRootMotionBPLibrary.generated.h"

class ACharacter;

UCLASS()
class UTopRootMotionBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Root Motion Scale", Keywords = "TopRootMotion root motion scale"), Category = "TopRootMotion")
		static void SetRootMotionScale(ACharacter* Character, const float RootMotionScale);
};
