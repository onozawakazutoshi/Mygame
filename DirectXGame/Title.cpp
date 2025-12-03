#include "Title.h"
void Title::Initialize() { 
	uint32_t tex = TextureManager::Load("white1x1.png");

	title_ = Sprite::Create(tex, {640.0f, 360.0f}, {0, 0, 0, 1}, {0.5f, 0.5f}, false, false); 
	title_->SetSize({1280, 720});

	 tex = TextureManager::Load("Sprit/ra.png");

	ra = Sprite::Create(tex, {240.0f, 360.0f}, {1, 1, 1, 0}, {0.5f, 0.5f}, false, false);
	ra->SetSize({200, 200});
	
	 tex = TextureManager::Load("Sprit/bi.png");

	bi = Sprite::Create(tex, {440.0f, 360.0f}, {1, 1, 1, 0}, {0.5f, 0.5f}, false, false);
	bi->SetSize({200, 200});

	 tex = TextureManager::Load("Sprit/de.png");

	de = Sprite::Create(tex, {640.0f, 360.0f}, {1, 1, 1, 0}, {0.5f, 0.5f}, false, false);
	de->SetSize({200, 200});

	 tex = TextureManager::Load("Sprit/nn.png");

	nn = Sprite::Create(tex, {840.0f, 360.0f}, {1, 1, 1, 0}, {0.5f, 0.5f}, false, false);
	nn->SetSize({200, 200});

	 tex = TextureManager::Load("Sprit/su.png");

	su = Sprite::Create(tex, {1040.0f, 360.0f}, {1, 1, 1, 0}, {0.5f, 0.5f}, false, false);
	su->SetSize({200, 200});

	input_ = Input::GetInstance();

}

void Title::Update() {
	switch (titlemode_) {
	case 0:

		if (alpha_ < 1.0f) {
			alpha_ += 0.01f;
		}
		ra->SetColor({1, 1, 1, alpha_});
		bi->SetColor({1, 1, 1, alpha_});
		de->SetColor({1, 1, 1, alpha_});
		nn->SetColor({1, 1, 1, alpha_});
		su->SetColor({1, 1, 1, alpha_});
		if (alpha_ >= 1.0f) {
			titlemode_ = 1;
		}

		break;
	case 1:
		if (input_->GetMousePosition().x >= 140 && input_->GetMousePosition().x <= 340 && input_->GetMousePosition().y >= 260 && input_->GetMousePosition().y <= 460) {
			ra->SetColor({1, 0, 0, alpha_});
		} else {
			ra->SetColor({1, 1, 1, alpha_});
		}
		if (input_->GetMousePosition().x >= 340 && input_->GetMousePosition().x <= 540 && input_->GetMousePosition().y >= 260 && input_->GetMousePosition().y <= 460) {
			bi->SetColor({1, 0, 0, alpha_});
		} else {
			bi->SetColor({1, 1, 1, alpha_});
		}
		if (input_->GetMousePosition().x >= 540 && input_->GetMousePosition().x <= 740 && input_->GetMousePosition().y >= 260 && input_->GetMousePosition().y <= 460) {
			de->SetColor({1, 0, 0, alpha_});
		} else {
			de->SetColor({1, 1, 1, alpha_});
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
		ra->SetColor({1, 1, 1, alpha_});
		bi->SetColor({1, 1, 1, alpha_});
		de->SetColor({1, 1, 1, alpha_});
		nn->SetColor({1, 1, 1, alpha_});
		su->SetColor({1, 1, 1, alpha_});
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
		bi->SetPosition(bipos_);
		if (bipos_.y >= 1000) {
			bipos_.y = -400.0f;
			bioverflage_ = true;
		}
		if (bipos_.y >= 360 && bioverflage_) {
			bipos_.y = 360.0f;
			bi->SetPosition(bipos_);
			vel.y = 0.0f;
			titlemode_ = 1;
			bioverflage_ = false;
		}
		break;

	case 4:

		Acc();
		bi->SetPosition(bipos_);
		if (bipos_.y >= 1000) {
			bipos_.y = -400.0f;
			bioverflage_ = true;
		}
		if (bipos_.y >= 360 && bioverflage_) {
			bipos_.y = 360.0f;
			bi->SetPosition(bipos_);
			vel.y = 0.0f;
			titlemode_ = 1;
			bioverflage_ = false;
		}
		break;
	}
}
void Title::Acc() {

	float dt = 0.3f;    // 1フレーム = 16ms

	// 1フレーム分の更新（単純オイラー）
	vel.x += acc.x * dt;
	vel.y += acc.y * dt;
	bipos_.x += vel.x * dt;
	bipos_.y += vel.y * dt;

	std::cout << "pos = (" << bipos_.x << ", " << bipos_.y << ")\n";
	std::cout << "vel = (" << vel.x << ", " << vel.y << ")\n";
}


void Title::Draw(ID3D12GraphicsCommandList* commandList) {
	Sprite::PreDraw(commandList);
	title_->Draw();
	ra->Draw();
	bi->Draw();
	de->Draw();
	nn->Draw();
	su->Draw();
	Sprite::PostDraw();
}
 