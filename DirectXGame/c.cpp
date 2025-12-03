#include "c.h"
void c::Initialize() {
	uint32_t tex = TextureManager::Load("white1x1.png");

	title_ = Sprite::Create(tex, {640.0f, 360.0f}, {0, 0, 0, 1}, {0.5f, 0.5f}, false, false);
	title_->SetSize({1280, 720});

	tex = TextureManager::Load("Sprit/C.png");

	C = Sprite::Create(tex, {240.0f, 360.0f}, {1, 1, 1, 0}, {0.5f, 0.5f}, false, false);
	C->SetSize({200, 200});

	tex = TextureManager::Load("Sprit/L.png");

	L = Sprite::Create(tex, {440.0f, 360.0f}, {1, 1, 1, 0}, {0.5f, 0.5f}, false, false);
	L->SetSize({200, 200});

	tex = TextureManager::Load("Sprit/E.png");

	E = Sprite::Create(tex, {640.0f, 360.0f}, {1, 1, 1, 0}, {0.5f, 0.5f}, false, false);
	E->SetSize({200, 200});

	tex = TextureManager::Load("Sprit/A.png");

	A = Sprite::Create(tex, {840.0f, 360.0f}, {1, 1, 1, 0}, {0.5f, 0.5f}, false, false);
	A->SetSize({200, 200});

	tex = TextureManager::Load("Sprit/R.png");

	R = Sprite::Create(tex, {1040.0f, 360.0f}, {1, 1, 1, 0}, {0.5f, 0.5f}, false, false);
	R->SetSize({200, 200});

	input_ = Input::GetInstance();
}

void c::Update() {
	switch (titlemode_) {
	case 0:

		if (alpha_ < 1.0f) {
			alpha_ += 0.01f;
		}
		C->SetColor({1, 1, 1, alpha_});
		L->SetColor({1, 1, 1, alpha_});
		E->SetColor({1, 1, 1, alpha_});
		A->SetColor({1, 1, 1, alpha_});
		R->SetColor({1, 1, 1, alpha_});
		if (alpha_ >= 1.0f) {
			titlemode_ = 1;
		}

		break;
	case 1:
		if (input_->GetMousePosition().x >= 140 && input_->GetMousePosition().x <= 340 && input_->GetMousePosition().y >= 260 && input_->GetMousePosition().y <= 460) {
			C->SetColor({1, 0, 0, alpha_});
		} else {
			C->SetColor({1, 1, 1, alpha_});
		}
		if (input_->GetMousePosition().x >= 340 && input_->GetMousePosition().x <= 540 && input_->GetMousePosition().y >= 260 && input_->GetMousePosition().y <= 460) {
			L->SetColor({1, 0, 0, alpha_});
		} else {
			L->SetColor({1, 1, 1, alpha_});
		}
		if (input_->GetMousePosition().x >= 540 && input_->GetMousePosition().x <= 740 && input_->GetMousePosition().y >= 260 && input_->GetMousePosition().y <= 460) {
			E->SetColor({1, 0, 0, alpha_});
		} else {
			E->SetColor({1, 1, 1, alpha_});
		}

		if (input_->IsTriggerMouse(0)) {
			if (input_->GetMousePosition().x >= 140 && input_->GetMousePosition().x <= 340 && input_->GetMousePosition().y >= 260 && input_->GetMousePosition().y <= 460) {
				titlemode_ = 2;
			}
			if (input_->GetMousePosition().x >= 340 && input_->GetMousePosition().x <= 540 && input_->GetMousePosition().y >= 260 && input_->GetMousePosition().y <= 460) {
				titlemode_ = 3;
			}
			if (input_->GetMousePosition().x >= 540 && input_->GetMousePosition().x <= 740 && input_->GetMousePosition().y >= 260 && input_->GetMousePosition().y <= 460) {
				titlemode_ = 4;
			} else {
				gemeChange_ = true;
			}
		}
		break;

	case 2:
		if (alpha_ > 0.0f) {
			alpha_ -= 0.01f;
		}
		C->SetColor({1, 1, 1, alpha_});
		L->SetColor({1, 1, 1, alpha_});
		E->SetColor({1, 1, 1, alpha_});
		A->SetColor({1, 1, 1, alpha_});
		R->SetColor({1, 1, 1, alpha_});
		if (alpha_ <= 0.0f) {
			if (sleeptime_ == 0) {
				titlemode_ = 0;
				sleeptime_ = 60;
			} else {
				sleeptime_--;
			}
		}
		break;

	case 3:

		Acc();
		L->SetPosition(bipos_);
		if (bipos_.y >= 1000) {
			bipos_.y = -400.0f;
			bioverflage_ = true;
		}
		if (bipos_.y >= 360 && bioverflage_) {
			bipos_.y = 360.0f;
			L->SetPosition(bipos_);
			vel.y = 0.0f;
			titlemode_ = 1;
			bioverflage_ = false;
		}
		break;

	case 4:

		Acc();
		L->SetPosition(bipos_);
		if (bipos_.y >= 1000) {
			bipos_.y = -400.0f;
			bioverflage_ = true;
		}
		if (bipos_.y >= 360 && bioverflage_) {
			bipos_.y = 360.0f;
			L->SetPosition(bipos_);
			vel.y = 0.0f;
			titlemode_ = 1;
			bioverflage_ = false;
		}
		break;
	}
}
void c::Acc() {

	float dt = 0.3f; // 1フレーム = 16ms

	// 1フレーム分の更新（単純オイラー）
	vel.x += acc.x * dt;
	vel.y += acc.y * dt;
	bipos_.x += vel.x * dt;
	bipos_.y += vel.y * dt;

	std::cout << "pos = (" << bipos_.x << ", " << bipos_.y << ")\n";
	std::cout << "vel = (" << vel.x << ", " << vel.y << ")\n";
}

void c::Draw(ID3D12GraphicsCommandList* commandList) {
	Sprite::PreDraw(commandList);
	title_->Draw();
	C->Draw();
	L->Draw();
	E->Draw();
	A->Draw();
	R->Draw();
	Sprite::PostDraw();
}
