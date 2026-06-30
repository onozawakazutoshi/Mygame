#include"KamataEngine.h"
#include "3d/Model.h"
#include"WorldTransformEx.h"
#include "Map.h"
#pragma once

using namespace KamataEngine;
class Courseefect {
public:
	void Initialize(Map* map_);
	void positionInitialize(Vector2 pos,int i);
	void Update();
	void Draw(Camera& camera);

private:
	Vector2 position_[1000];
	Model* model_ = nullptr;
	WorldTransformEx worldTransform_;
	Map* Map_;
};
