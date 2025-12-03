#include "GameScene.h"


void GameScene::Initialize() {
	map_->Initialize();
	enemy_->Initialize(map_);
	camera_.Initialize();
}

void GameScene::Update() { 
	map_->Update();
	enemy_->Updete();
	if (Input::GetInstance()->PushKey(DIK_A)) {
		R += 0.05f;
	}
	if (Input::GetInstance()->PushKey(DIK_D)) {
		R -= 0.05f;
	}
	if (Input::GetInstance()->PushKey(DIK_W)) {
		W += 0.05f;
	}
	if (Input::GetInstance()->PushKey(DIK_S)) {
		W -= 0.05f;
	}
	camera_.translation_ = Vector3{640, 358, -80};
	camera_.rotation_ = Vector3{W,R,0};
	camera_.UpdateMatrix();
}

void GameScene::Draw(ID3D12GraphicsCommandList* commandList) { 
	map_->Draw(commandList,camera_);
	
	enemy_->Drow(commandList, camera_);
}
