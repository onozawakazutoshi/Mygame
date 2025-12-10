#pragma once
#include "KamataEngine.h"
#include <3D/Model.h>
#include "WorldTransformEx.h"

using namespace KamataEngine;

struct MapDate {
	Vector2 position;
	int type;
};

class Map {
public:
	void Initialize();
	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList, Camera& camera);

	Vector2 Getmappos(int x, int y) { return map_[x][y].position; };
	int GetMachineType(int x, int y) { return map_[x][y].type; }
	int GetMapheight() { return height_; }
	int GetMapwidth() { return width_; }

	Vector2 GetMapSize() { return mapSize; }

private:
	static const int width_ = 10;
	static const int height_ = 10;
	MapDate map_[width_][height_] = {0};

	Sprite* mapSprite[width_][height_];
	Sprite* redSprite = nullptr;

	Vector2 mapSize = {5.0f, 5.0f};

	int maptype[width_][height_] = {
	    {0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
	    {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 5, 0, 0, 0, 0, 0},
	    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	Model* model_[width_][height_];

	WorldTransformEx worldTransform_[width_][height_];

	ObjectColor objectColorW_;

	ObjectColor objectColorB_;

	ObjectColor objectColorR_;

	int time_ = 0;	

	bool damegeFlag_ = false;

};