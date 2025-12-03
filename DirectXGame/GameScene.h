#pragma once
#include "KamataEngine.h"
#include "Map.h"
#include "Enemy.h"
#include "input/Input.h"

using namespace KamataEngine;

class GameScene {
public:
	
	void Initialize();
	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);

private:
	Map* map_ = new Map();
	Enemy* enemy_ = new Enemy();
	Camera camera_;
	float R = 0.0f;
	float W = 0.0f;
	Input* input_ = nullptr;
};
