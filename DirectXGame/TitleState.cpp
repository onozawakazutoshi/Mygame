#include "TitleState.h"
#include "GameState.h"
#include "SceneManager.h"

TitleState::TitleState(SceneManager* manager) {
	manager_ = manager;

	title_.Initialize();
}

void TitleState::Update() {
	title_.Update();

	if (title_.IsGameChange()) {

		manager_->ChangeState(new GameState(manager_));
	}
}

void TitleState::Draw(ID3D12GraphicsCommandList* commandList) { title_.Draw(commandList); }