#include "GameState.h"

GameState::GameState(SceneManager* manager) {
	manager_ = manager;

	gameScene_.Initialize();
}

void GameState::Update() { gameScene_.Update(); }

void GameState::Draw(ID3D12GraphicsCommandList* commandList) { gameScene_.Draw(commandList); }
