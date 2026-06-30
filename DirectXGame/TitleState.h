#pragma once

#include "SceneState.h"
#include "Title.h"

class SceneManager;

class TitleState : public SceneState {
public:
	TitleState(SceneManager* manager);

	void Update() override;
	void Draw(ID3D12GraphicsCommandList* commandList) override;

private:
	SceneManager* manager_;

	Title title_;
};