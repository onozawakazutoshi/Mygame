#include <KamataEngine.h>

#pragma once
class SceneState {
public:
	virtual ~SceneState() = default;

	virtual void Update() = 0;
	virtual void Draw(ID3D12GraphicsCommandList* commandList) = 0;
};
