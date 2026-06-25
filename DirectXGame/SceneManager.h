#include <KamataEngine.h>
#include "SceneState.h"

#pragma once
class SceneManager {
	public:
	void Update() { state_->Update(); }

	void Draw(ID3D12GraphicsCommandList* cmd) { state_->Draw(cmd); }

	void ChangeState(SceneState* state) {
		delete state_;
		state_ = state;
	}

	private:
	SceneState* state_;
};
