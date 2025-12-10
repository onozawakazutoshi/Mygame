#pragma once
#include "KamataEngine.h"
#include "Map.h"
#include "Enemy.h"
#include "input/Input.h"
#include "Guardian.h"

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
	Guardian* guardian_ = new Guardian();
	Input* input = Input::GetInstance();
	float ne = -80.0f;
};
