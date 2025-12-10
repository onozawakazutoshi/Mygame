#pragma once
#include<stdio.h>
#include<math/Vector2.h>
#include"KamataEngine.h"
#include "3d/Model.h"
#include"WorldTransformEx.h"
#include "Courseefect.h"

using namespace KamataEngine;

class Map;
struct roadData {
	int ispos[2];
	int backpos[2];
	int score;
	bool alive = true;
};

class Enemy
{


private:
	static const int X = 10;
	static const int Y = 10;

	int m[Y][X];
	
	bool goflag = false;
	roadData record[1000];
	roadData ima;
	int copy[Y][X];

	int ispos[2];

	int golepos[2];
	
	int recordcount=0;

	roadData posrecord[1000];

	float run = 0;

	Map* Map_;
	
	int roadMaxcount;

	int count = 0;

	int startpos[2];

	bool NotRoad;

	int backrecordcount = 0;

	int NotRoadcount = 0;



	int HP = 1;
	KamataEngine::Vector2 postooo{};
	KamataEngine::Vector2 sizze{20.0f,20.0f};
	int maxRecursionDepth = 100; // 再帰の最大深さ
	int currentRecursionDepth = 0;

	Sprite* enemySprite = nullptr;

	Model* model_ = nullptr;

	WorldTransformEx worldTransform_;

	Courseefect* courseefect_ = nullptr;

	ObjectColor objectColor_;

	Input* input_ = nullptr;

public:
	void Initialize(Map* map_);
	void Updete();
	void Road(int count);
	void Drow(ID3D12GraphicsCommandList* commandList, Camera& camera);

	bool GetNotRoad() {
		return NotRoad;
	}

	int getValue(int row, int col) const {
		if (row >= 0 && row < Y && col >= 0 && col < X) {
			return m[row][col];
		}
		return -1; // 範囲外のときのエラー処理
	}

	roadData GetPosition() const {
		if (recordcount > 0) {
			return posrecord[recordcount - 1];  // 最新の座標データ
		}
		return {};  // 初期化された `roadData` を返す
	}

	static int saiki_num;

	void Resount(Map* map_);
	bool SetNotRoad(bool Not) { return NotRoad = Not; }

	int GetHP() { return HP; }
	int SetHP(int h) { return HP = h; }
};
