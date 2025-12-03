#include "Courseefect.h"

void Courseefect::Initialize(Map* map_) { 

	model_ = Model::CreateFromOBJ("cube");
	Map_ = map_;
}
void Courseefect::positionInitialize(Vector2 pos, int i) {
	position_[i] = pos;
}

void Courseefect::Update() {
	
}

void Courseefect::Draw(Camera& camera) {
	for (int i = 0; i < 1000; i++) {
		worldTransform_.translation_ = Vector3{ position_[i].x * Map_->GetMapSize().x + 640 - Map_->GetMapwidth() * Map_->GetMapSize().x / 2,
			position_[i].y * Map_->GetMapSize().y + 360 - Map_->GetMapheight() * Map_->GetMapSize().y / 2,
		    -2};
		worldTransform_.UpdateMatrix();
		model_->Draw(worldTransform_, camera);
	}
}
