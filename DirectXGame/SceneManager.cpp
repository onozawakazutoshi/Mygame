#include "SceneManager.h"
#include "TitleState.h"

SceneManager::SceneManager() { state_ = new TitleState(this); }

SceneManager::~SceneManager() { delete state_; }

void SceneManager::Update() { state_->Update(); }

void SceneManager::Draw(ID3D12GraphicsCommandList* commandList) { state_->Draw(commandList); }

void SceneManager::ChangeState(SceneState* state) {
	delete state_;

	state_ = state;
}
