#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CustomWidget.h"
#include "RevisionGameInstance.generated.h"


UENUM()
enum class EGameState
{
	None,
	Menu,
	Game,
	Pause
};


UCLASS()
class REVISIONPROJECT_API URevisionGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		EGameState gameState = EGameState::None;


public:
	FORCEINLINE EGameState GetGameState() const { return gameState; }
	FORCEINLINE void SetGameState(EGameState _state) {
		gameState = _state;
		SwitchUI();
	}


	void SwitchUI();


	template<typename T>
	static void InitCustomWidget(TSubclassOf<UCustomWidget> _ref, UCustomWidget& _widget)
	{
		if (!_ref) return;
		_widget = CreateWidget<T>(GetWorld(), _ref);
		if (_widget)
			_widget.InitEvents();
	}
};
