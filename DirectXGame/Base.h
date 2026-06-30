
#pragma once
#include<stdio.h>
#include<math/Vector2.h>
#include"KamataEngine.h"
#include "3d/Model.h"
#include"WorldTransformEx.h"
#include "Courseefect.h"
class Map;
struct roadData {
	int ispos[2];
	int backpos[2];
	int score;
	bool alive = true;
};

class  Base{

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

	int recordcount;

	roadData posrecord[1000];

	float run;

	Map* Map_;

	int roadMaxcount;

	int count;

	int startpos[2];

	bool NotRoad;

	int backrecordcount;

	int NotRoadcount;

	int HP;
	KamataEngine::Vector2 postooo{};
	KamataEngine::Vector2 sizze{20.0f, 20.0f};
	int maxRecursionDepth; // 再帰の最大深さ
	int currentRecursionDepth;

	Sprite* enemySprite;

	Model* model_ ;

	WorldTransformEx worldTransform_;

	Courseefect* courseefect_;

public:
	virtual void Initialize(Map* map_) = 0;
	virtual void Updete() = 0;
	virtual void Road(int count) = 0;
	virtual void Drow(ID3D12GraphicsCommandList* commandList, Camera& camera) = 0;

	virtual bool GetNotRoad() { return NotRoad; }

	virtual int getValue(int row, int col) const {
		if (row >= 0 && row < Y && col >= 0 && col < X) {
			return m[row][col];
		}
		return -1; // 範囲外のときのエラー処理
	}

	roadData GetPosition() const {
		if (recordcount > 0) {
			return posrecord[recordcount - 1]; // 最新の座標データ
		}
		return {}; // 初期化された `roadData` を返す
	}

	static int saiki_num;

	virtual void Resount(Map* map_);
	virtual bool SetNotRoad(bool Not) { return NotRoad = Not; }

	virtual int GetHP() { return HP; }
	virtual int SetHP(int h) { return HP = h; }
};
