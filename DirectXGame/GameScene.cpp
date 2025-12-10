#include "GameScene.h"


void GameScene::Initialize() {
	map_->Initialize();
	enemy_->Initialize(map_);
	camera_.Initialize();
	guardian_->Initialize(map_);
	camera_.translation_ = Vector3{640, 358, ne};
	input_ = Input::GetInstance();	
}

void GameScene::Update() { 
	map_->Update();
	enemy_->Updete();
	guardian_->Update();
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
	if (input_->IsPressMouse(1)&&ne < -70.0f) {
		ne += 0.1f;
	} else if (ne == -70.0f) {
		
	} else if (ne >= -80.0f) {
		ne -= 0.2f;
	}
	camera_.translation_ = Vector3{640, 358, ne};
	camera_.rotation_ = Vector3{W,R,0};
	camera_.UpdateMatrix();

	guardian_->Mousclicked();
}

void GameScene::Draw(ID3D12GraphicsCommandList* commandList) {
	
	guardian_->Draw(commandList, camera_);
	enemy_->Drow(commandList, camera_); 
	map_->Draw(commandList,camera_);
	
	
}
