#include <KamataEngine.h>
#pragma once

#include "SceneState.h"

class SceneManager {
public:
	SceneManager();
	~SceneManager();

	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);

	void ChangeState(SceneState* state);

private:
	SceneState* state_;
};
