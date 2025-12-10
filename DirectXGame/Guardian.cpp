#include "Guardian.h"

void Guardian::Initialize(Map* map_) {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			m[i][j] = NULL;
		}
	}
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			m[i][j] = map_->GetMachineType(i, j);
		}
	}
	Map_ = map_;
	goflag = false;

	NotRoad = false;

	copy[Y][X] = 0;

	ispos[0] = 0;
	ispos[1] = 0;

	golepos[0] = 0;
	golepos[1] = 0;

	recordcount = 0;

	run = 0;
	currentRecursionDepth = 0;
	roadMaxcount = 0;
	count = 0;

	backrecordcount = -1;

	NotRoadcount = 0;
	HP = 1;
	for (int i = 0; i < 1000; i++) {
		record[i].backpos[0] = NULL;
		record[i].backpos[1] = NULL;
		record[i].ispos[0] = -1;
		record[i].ispos[1] = -1;
		record[i].score = NULL;
		posrecord[i].backpos[0] = NULL;
		posrecord[i].backpos[1] = NULL;
		posrecord[i].ispos[0] = -1;
		posrecord[i].ispos[1] = -1;
		posrecord[i].score = NULL;
	}
	uint32_t tex = TextureManager::Load("white1x1.png");

	enemySprite = Sprite::Create(tex, {postooo.x, postooo.y}, {1, 0, 0, 0.3f}, {0.5f, 0.5f}, false, false);
	enemySprite->SetSize({30, 30});
	worldTransform_.Initialize();
	model_ = Model::CreateFromOBJ("cube");
	input_ = Input::GetInstance();

	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			copy[i][j] = m[i][j];
		}
	}
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			// スターとととゴールの位置を取得
			if (m[i][j] == 2) {
				startpos[0] = 0;
				startpos[1] = 0;
			}
			if (m[i][j] == 5) {
				startpos[0] = i + 1;
				startpos[1] = j;
				golepos[0] = i+1;
				golepos[1] = j;
			}
		}
	}
}

void Guardian::Update() {
	if (togoal) {

		if (HP == 1) {
			ispos[0] = startpos[0];
			ispos[1] = startpos[1];
			record[0].ispos[0] = ispos[0];
			record[0].ispos[1] = ispos[1];
			record[0].alive = true;
			// if (posrecord == nullptr) {
			Road(count);
		}
		for (int i = 0; i < 1000; i++) {
			courseefect_->positionInitialize(Vector2((float)posrecord[i].ispos[0], (float)posrecord[i].ispos[1]), i);
		}
		// 経路上の現在の位置情報を取得して postooo に反映
		postooo.x = (float)Map_->Getmappos(posrecord[roadMaxcount - (int)run].ispos[0], posrecord[roadMaxcount - (int)run].ispos[1]).x + Map_->GetMapSize().x / 2;
		postooo.y = (float)Map_->Getmappos(posrecord[roadMaxcount - (int)run].ispos[0], posrecord[roadMaxcount - (int)run].ispos[1]).y + Map_->GetMapSize().y / 2;

		enemySprite->SetPosition(postooo);
		saiki_num = 0;
		worldTransform_.translation_ = Vector3{postooo.x - 2.5f, postooo.y - 2.5f, -3};
		worldTransform_.scale_ = Vector3{2.0f, 2.0f, 2.0f};
		worldTransform_.UpdateMatrix();

		if (run < roadMaxcount + 0.9) {
			
			run += 0.03f;
		} else {
			run = 0;
			startpos[0] = golepos[0];
			startpos[1] = golepos[1];
			
		}
	}
}

void Guardian::Draw(ID3D12GraphicsCommandList* commandList, Camera& camera) {
	Model::PreDraw(commandList);
	// courseefect_->Draw(camera);
	//model_->Draw(worldTransform_, camera);
	camera;
	Model::PostDraw();
	Sprite::PreDraw(commandList);
	if (input_->IsPressMouse(0)) {
		enemySprite->SetPosition(input_->GetMousePosition());
		enemySprite->SetRotation(rotation);
		enemySprite->Draw();

		rotation += 0.1f;
	}
	Sprite::PostDraw();


}

void Guardian::Resount(Map* map_) {
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			m[i][j] = NULL;
		}
	}
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			m[i][j] = map_->GetMachineType(i, j);
		}
	}
	Map_ = map_;
	goflag = false;

	NotRoad = false;

	copy[Y][X] = 0;

	ispos[0] = 0;
	ispos[1] = 0;

	golepos[0] = 0;
	golepos[1] = 0;

	recordcount = 0;

	run = 0;

	roadMaxcount = 0;
	count = 0;

	backrecordcount = -1;

	NotRoadcount = 0;

	for (int i = 0; i < 1000; i++) {
		record[i].backpos[0] = NULL;
		record[i].backpos[1] = NULL;
		record[i].ispos[0] = NULL;
		record[i].ispos[1] = NULL;
		record[i].score = NULL;
		posrecord[i].backpos[0] = NULL;
		posrecord[i].backpos[1] = NULL;
		posrecord[i].ispos[0] = NULL;
		posrecord[i].ispos[1] = NULL;
		posrecord[i].score = NULL;
	}
}

void Guardian::Mousclicked() { 
	//if (input_->GetMousePosition().x)

}

int Guardian::saiki_num = 0;
void Guardian::Road(int Count) {

	saiki_num++;
	if (!NotRoad) {
		if (copy[record[1].ispos[0]][record[1].ispos[1]] != 5) {
			/// 行けるかどうかの判定+スコアつけ
			if (ispos[0] - 1 >= 0 && copy[ispos[0] - 1][ispos[1]] != 1) {
				recordcount++;
				record[recordcount].ispos[0] = ispos[0] - 1;
				record[recordcount].ispos[1] = ispos[1];
				record[recordcount].backpos[0] = ispos[0];
				record[recordcount].backpos[1] = ispos[1];
				record[recordcount].score = (int)(sqrt((golepos[0] - record[recordcount].ispos[0] - 1) * (golepos[0] - record[recordcount].ispos[0] - 1)) +
				                                  (int)sqrt((golepos[1] - record[recordcount].ispos[1]) * (golepos[1] - record[recordcount].ispos[1]))) +
				                            (int)(sqrt((startpos[0] - record[recordcount].ispos[0] - 1) * (startpos[0] - record[recordcount].ispos[0] - 1)) +
				                                  (int)sqrt((startpos[1] - record[recordcount].ispos[1]) * (startpos[1] - record[recordcount].ispos[1]))) +
				                            Count;
				record[recordcount].alive = false;
			}
			if (ispos[0] + 1 < Map_->GetMapheight() && copy[ispos[0] + 1][ispos[1]] != 1) {
				recordcount++;
				record[recordcount].ispos[0] = ispos[0] + 1;
				record[recordcount].ispos[1] = ispos[1];
				record[recordcount].backpos[0] = ispos[0];
				record[recordcount].backpos[1] = ispos[1];
				record[recordcount].score = (int)sqrt((golepos[0] - record[recordcount].ispos[0] + 1) * (golepos[0] - record[recordcount].ispos[0]) + 1) +
				                            (int)sqrt((golepos[1] - record[recordcount].ispos[1]) * (golepos[1] - record[recordcount].ispos[1])) +
				                            (int)sqrt((startpos[0] - record[recordcount].ispos[0] + 1) * (startpos[0] - record[recordcount].ispos[0]) + 1) +
				                            (int)sqrt((startpos[1] - record[recordcount].ispos[1]) * (startpos[1] - record[recordcount].ispos[1])) + Count;
				record[recordcount].alive = false;
			}
			if (ispos[1] - 1 >= 0 && copy[ispos[0]][ispos[1] - 1] != 1) {
				recordcount++;
				if (ispos[1] - 1 == 0) {
				}
				record[recordcount].ispos[0] = ispos[0];
				record[recordcount].ispos[1] = ispos[1] - 1;
				record[recordcount].backpos[0] = ispos[0];
				record[recordcount].backpos[1] = ispos[1];
				record[recordcount].score = (int)sqrt((golepos[0] - record[recordcount].ispos[0]) * (golepos[0] - record[recordcount].ispos[0])) +
				                            (int)sqrt((golepos[1] - record[recordcount].ispos[1] - 1) * (golepos[1] - record[recordcount].ispos[1] - 1)) +
				                            (int)sqrt((startpos[0] - record[recordcount].ispos[0]) * (startpos[0] - record[recordcount].ispos[0])) +
				                            (int)sqrt((startpos[1] - record[recordcount].ispos[1] - 1) * (startpos[1] - record[recordcount].ispos[1] - 1)) + Count;
				record[recordcount].alive = false;
			}
			if (ispos[1] + 1 < Map_->GetMapwidth() && copy[ispos[0]][ispos[1] + 1] != 1) {
				recordcount++;
				record[recordcount].ispos[0] = ispos[0];
				record[recordcount].ispos[1] = ispos[1] + 1;
				record[recordcount].backpos[0] = ispos[0];
				record[recordcount].backpos[1] = ispos[1];
				record[recordcount].score = (int)sqrt((golepos[0] - record[recordcount].ispos[0]) * (golepos[0] - record[recordcount].ispos[0])) +
				                            (int)sqrt((golepos[1] - record[recordcount].ispos[1] + 1) * (golepos[1] - record[recordcount].ispos[1] + 1)) +
				                            (int)sqrt((startpos[0] - record[recordcount].ispos[0]) * (startpos[0] - record[recordcount].ispos[0])) +
				                            (int)sqrt((startpos[1] - record[recordcount].ispos[1] + 1) * (startpos[1] - record[recordcount].ispos[1] + 1)) + Count;

				record[recordcount].alive = false;
			}
			copy[ispos[0]][ispos[1]] = 1;

			for (int i = recordcount; i > 0; i--) {
				if (copy[record[i].ispos[0]][record[i].ispos[1]] == 1) {
					record[i].score += 100;
					record[1].alive = true;
				}
			}

			for (int i = 1; i < recordcount + 1; i++) {
				for (int j = 1; j < recordcount; j++) {
					if (record[i].score < record[j].score) {
						roadData2 a = record[i];
						record[i] = record[j];
						record[j] = a;
					}
				}
			}

			ispos[0] = record[1].ispos[0];
			ispos[1] = record[1].ispos[1];

			Count = recordcount;
			// recordcount--;
			for (int i = 0;; i++) {
				if (!record[i].alive) {
					break;
				}
				if (i > recordcount) {
					NotRoad = true;
					break;
				}
			}

			backrecordcount = recordcount;

			Road(Count);
		}
		if (!NotRoad) {
			for (int j = 0; j < recordcount + 1; j++) {
				if (ispos[0] == record[j].ispos[0] && ispos[1] == record[j].ispos[1]) {
					posrecord[0] = record[j];
				}
			}
			for (int i = 0;;) {
				/*if (i>= 1000) {
				    break;
				}*/
				if (m[posrecord[i].ispos[0]][posrecord[i].ispos[1]] == 2) {
					roadMaxcount = i;
					NotRoad = true;
					break;
				} else {
					for (int j = 0; j < recordcount + 1; j++) {
						if (posrecord[i].backpos[0] == record[j].ispos[0] && posrecord[i].backpos[1] == record[j].ispos[1]) {
							i++;
							posrecord[i] = record[j];
							break;
						}
						if (m[posrecord[i].ispos[0]][posrecord[i].ispos[1]] == 2) {
							break;
						}
					}
				}
			}
		}
	}
}