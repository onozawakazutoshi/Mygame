#pragma once

#include "GameScene.h"
#include "SceneState.h"

class SceneManager;

class GameState : public SceneState {
public:
	GameState(SceneManager* manager);

	void Update() override;
	void Draw(ID3D12GraphicsCommandList* commandList) override;

private:
	SceneManager* manager_;

	GameScene gameScene_;
};